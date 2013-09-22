#!/usr/bin/env perl
use v5.18.0;
use Perl::Lexer;

my $src = join '', <>;

my $lexer = Perl::Lexer->new();
my @tokens = @{$lexer->scan_string($src)};
for (@tokens) {
    say $_->inspect;
}
