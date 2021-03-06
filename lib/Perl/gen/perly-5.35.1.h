/* -*- buffer-read-only: t -*-
   !!!!!!!   DO NOT EDIT THIS FILE   !!!!!!!
   This file is built by regen_perly.pl from perly.y.
   Any changes made here will be lost!
 */

#define PERL_BISON_VERSION  30003

/* A Bison parser, made by GNU Bison 3.3.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    GRAMPROG = 258,
    GRAMEXPR = 259,
    GRAMBLOCK = 260,
    GRAMBARESTMT = 261,
    GRAMFULLSTMT = 262,
    GRAMSTMTSEQ = 263,
    GRAMSUBSIGNATURE = 264,
    PERLY_AMPERSAND = 265,
    PERLY_BRACE_OPEN = 266,
    PERLY_BRACE_CLOSE = 267,
    PERLY_BRACKET_OPEN = 268,
    PERLY_BRACKET_CLOSE = 269,
    PERLY_COMMA = 270,
    PERLY_DOLLAR = 271,
    PERLY_DOT = 272,
    PERLY_EQUAL_SIGN = 273,
    PERLY_MINUS = 274,
    PERLY_PERCENT_SIGN = 275,
    PERLY_PLUS = 276,
    PERLY_SEMICOLON = 277,
    PERLY_SLASH = 278,
    PERLY_SNAIL = 279,
    PERLY_STAR = 280,
    BAREWORD = 281,
    METHOD = 282,
    FUNCMETH = 283,
    THING = 284,
    PMFUNC = 285,
    PRIVATEREF = 286,
    QWLIST = 287,
    FUNC0OP = 288,
    FUNC0SUB = 289,
    UNIOPSUB = 290,
    LSTOPSUB = 291,
    PLUGEXPR = 292,
    PLUGSTMT = 293,
    LABEL = 294,
    FORMAT = 295,
    SUB = 296,
    SIGSUB = 297,
    ANONSUB = 298,
    ANON_SIGSUB = 299,
    PACKAGE = 300,
    USE = 301,
    WHILE = 302,
    UNTIL = 303,
    IF = 304,
    UNLESS = 305,
    ELSE = 306,
    ELSIF = 307,
    CONTINUE = 308,
    FOR = 309,
    GIVEN = 310,
    WHEN = 311,
    DEFAULT = 312,
    TRY = 313,
    CATCH = 314,
    LOOPEX = 315,
    DOTDOT = 316,
    YADAYADA = 317,
    FUNC0 = 318,
    FUNC1 = 319,
    FUNC = 320,
    UNIOP = 321,
    LSTOP = 322,
    MULOP = 323,
    ADDOP = 324,
    DOLSHARP = 325,
    DO = 326,
    HASHBRACK = 327,
    NOAMP = 328,
    LOCAL = 329,
    MY = 330,
    REQUIRE = 331,
    COLONATTR = 332,
    FORMLBRACK = 333,
    FORMRBRACK = 334,
    SUBLEXSTART = 335,
    SUBLEXEND = 336,
    PREC_LOW = 337,
    OROP = 338,
    ANDOP = 339,
    NOTOP = 340,
    ASSIGNOP = 341,
    PERLY_QUESTION_MARK = 342,
    PERLY_COLON = 343,
    OROR = 344,
    DORDOR = 345,
    ANDAND = 346,
    BITOROP = 347,
    BITANDOP = 348,
    CHEQOP = 349,
    NCEQOP = 350,
    CHRELOP = 351,
    NCRELOP = 352,
    SHIFTOP = 353,
    MATCHOP = 354,
    PERLY_EXCLAMATION_MARK = 355,
    PERLY_TILDE = 356,
    UMINUS = 357,
    REFGEN = 358,
    POWOP = 359,
    PREINC = 360,
    PREDEC = 361,
    POSTINC = 362,
    POSTDEC = 363,
    POSTJOIN = 364,
    ARROW = 365,
    PERLY_PAREN_CLOSE = 366,
    PERLY_PAREN_OPEN = 367
  };
#endif

/* Value type.  */
static bool
S_is_opval_token(int type) {
    switch (type) {
    case BAREWORD:
    case FUNC0OP:
    case FUNC0SUB:
    case FUNCMETH:
    case LABEL:
    case LSTOPSUB:
    case METHOD:
    case PLUGEXPR:
    case PLUGSTMT:
    case PMFUNC:
    case PRIVATEREF:
    case QWLIST:
    case THING:
    case UNIOPSUB:
        return 1;
    }
    return 0;
}
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{

    I32	ival; /* __DEFAULT__ (marker for regen_perly.pl;
                                must always be 1st union member) */
    char *pval;
    OP *opval;
    GV *gvval;

};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (void);


/* Generated from:
 * 427b422b0ce1154d834dc461973a3254729575694f98ab600032f67ccab7b9e5 perly.y
 * acf1cbfd2545faeaaa58b1cf0cf9d7f98b5be0752eb7a54528ef904a9e2e1ca7 regen_perly.pl
 * ex: set ro: */
