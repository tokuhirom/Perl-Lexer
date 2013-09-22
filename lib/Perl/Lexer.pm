package Perl::Lexer;
use 5.018001;
use strict;
use warnings;

our $VERSION = "0.01";

use parent qw(Exporter);

our @EXPORT = qw(
    TOKENTYPE_NONE
    TOKENTYPE_IVAL
    TOKENTYPE_OPNUM
    TOKENTYPE_PVAL
    TOKENTYPE_OPVAL
);

use XSLoader;
XSLoader::load(__PACKAGE__, $VERSION);

sub new {
    my $class = shift;
    bless {}, $class;
}

package Perl::Lexer::Token;

sub inspect {
    my $self = shift;
    my $ret = '<Token: ';
    $ret .= $self->name . ' ' . lc($self->type_str);
    if (UNIVERSAL::isa($self->yylval, 'B::SVOP')) {
        $ret .= ' ' . $self->yylval_svop;
    } else {
        $ret .= ' ' . $self->yylval;
    }
    $ret .= '>';
    return $ret;
}

sub name {
    my $self = shift;
    _name($self->[0]);
}

sub type {
    my $self = shift;
    _type($self->[0]);
}

sub type_str {
    my $type = shift->type;
    +{
        Perl::Lexer::TOKENTYPE_NONE()  => 'NONE',
        Perl::Lexer::TOKENTYPE_IVAL()  => 'IVAL',
        Perl::Lexer::TOKENTYPE_OPNUM() => 'OPNUM',
        Perl::Lexer::TOKENTYPE_PVAL()  => 'PVAL',
        Perl::Lexer::TOKENTYPE_OPVAL() => 'OPVAL',
    }->{$type};
}

sub yylval {
    my $self = shift;
    return $self->[1];
}

sub yylval_svop {
    my $self = shift;
    Carp::croak("It's not SVOP") unless UNIVERSAL::isa($self->[1], 'B::SVOP');
    return _yylval_svop($self->[1]);
}

1;
__END__

=encoding utf-8

=head1 NAME

Perl::Lexer - Use Perl5 lexer as a library.

=head1 SYNOPSIS

    use v5.18.0;
    use Perl::Lexer;

    my $lexer = Perl::Lexer->new();
    my @tokens = @{$lexer->scan_string('1+2')};
    for (@tokens) {
        say $_->inspect;
    }

Output is:

    <Token: THING opval 1>
    <Token: ADDOP opnum 63>
    <Token: THING opval 2>

=head1 DESCRIPTION

B<THIS LIBRARY IS WRITTEN FOR RESEARCHING PERL5 LEXER API. THIS MODULE USES PERL5 INTERNAL API. DO NOT USE THIS.>

Perl::Lexer is a really hacky library for using Perl5 lexer as a library.

=head1 LICENSE

Copyright (C) Tokuhiro Matsuno.

This library is free software; you can redistribute it and/or modify
it under the same terms as Perl itself.

=head1 AUTHOR

Tokuhiro Matsuno E<lt>tokuhirom@gmail.comE<gt>

=cut

