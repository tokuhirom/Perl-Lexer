#!/usr/bin/env perl
use strict;
use warnings;
use FindBin;
use HTTP::Tiny;
use Archive::Tar;
use version;

# XXX: 5.8.8 and 5.8.9 also have debug_tokens.
my $min_version = '5.010000';

my $ua = HTTP::Tiny->new;

my @perl_versions;
{
    my $res = $ua->get("http://www.cpan.org/src/5.0/");
    die "Can't get perl versions" unless $res->{success};
    @perl_versions = $res->{content} =~ m!href="perl-(5\.\d+\.\d+).tar.gz"!g;
}

my $src_dir = "$FindBin::Bin/src";
my $dst_dir = "$FindBin::Bin/../lib/Perl/gen";

mkdir $src_dir unless -d $src_dir;
mkdir $dst_dir unless -d $dst_dir;

open my $map, '>', "$dst_dir/token_info_map.h";

my %seen;
for my $version (sort @perl_versions) {
    next if version->parse($version) < version->parse($min_version);
    next if $seen{$version}++;
    say "downloading $version...";
    my $file = "$src_dir/perl-$version.tar.gz";
    my $res = $ua->mirror("http://www.cpan.org/src/5.0/perl-$version.tar.gz", $file);
    unless ($res->{success}) {
        warn "Can't download $version";
        next;
    }
    my $tar = Archive::Tar->new($file, 1);

    for my $name (qw/perly.h toke.c/) {
        (my $vname = $name) =~ s/\./-$version./;
        unlink "$src_dir/$vname" if -f "$src_dir/$vname";
        $tar->extract_file("perl-$version/$name", "$src_dir/$vname");
    }

    {
        my $src = "$src_dir/perly-$version.h";
        my $dst = "$dst_dir/perly-$version.h";
        open my $in, '<', $src;
        open my $out, '>', $dst;
        while(<$in>) {
            next if /PERL_CORE|PERL_IN_TOKE_C/;
            print $out $_;
        }
        close $in;
        close $out;
    }

    {
        my $src = "$src_dir/toke-$version.c";
        my $dst = "$dst_dir/token_info-$version.h";
        open my $in, '<', $src;
        open my $out, '>', $dst;
        say $out qq{#include "perly-$version.h"};
        my $flag;
        while(<$in>) {
            if (/^(?:enum token_type|static struct debug_token)/) {
                $flag = 1;
            }
            if ($flag) {
                print $out $_;
                $flag = 0 if /^\s*$/;
            }
        }
    }

    my ($revision, $major, $minor) = split /\./, $version;
    my $if = keys %seen > 1 ? "elif" : "if";

    print $map <<"MAP";
#$if PERL_VERSION == $major && PERL_SUBVERSION == $minor
#include "token_info-$version.h"
MAP
}

print $map "#endif\n";
