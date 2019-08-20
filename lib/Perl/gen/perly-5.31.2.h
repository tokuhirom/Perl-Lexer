/* -*- buffer-read-only: t -*-
   !!!!!!!   DO NOT EDIT THIS FILE   !!!!!!!
   This file is built by regen_perly.pl from perly.y.
   Any changes made here will be lost!
 */

#define PERL_BISON_VERSION  30004

/* A Bison parser, made by GNU Bison 3.4.1.  */

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
    BAREWORD = 264,
    METHOD = 265,
    FUNCMETH = 266,
    THING = 267,
    PMFUNC = 268,
    PRIVATEREF = 269,
    QWLIST = 270,
    FUNC0OP = 271,
    FUNC0SUB = 272,
    UNIOPSUB = 273,
    LSTOPSUB = 274,
    PLUGEXPR = 275,
    PLUGSTMT = 276,
    LABEL = 277,
    FORMAT = 278,
    SUB = 279,
    SIGSUB = 280,
    ANONSUB = 281,
    ANON_SIGSUB = 282,
    PACKAGE = 283,
    USE = 284,
    WHILE = 285,
    UNTIL = 286,
    IF = 287,
    UNLESS = 288,
    ELSE = 289,
    ELSIF = 290,
    CONTINUE = 291,
    FOR = 292,
    GIVEN = 293,
    WHEN = 294,
    DEFAULT = 295,
    LOOPEX = 296,
    DOTDOT = 297,
    YADAYADA = 298,
    FUNC0 = 299,
    FUNC1 = 300,
    FUNC = 301,
    UNIOP = 302,
    LSTOP = 303,
    RELOP = 304,
    EQOP = 305,
    MULOP = 306,
    ADDOP = 307,
    DOLSHARP = 308,
    DO = 309,
    HASHBRACK = 310,
    NOAMP = 311,
    LOCAL = 312,
    MY = 313,
    REQUIRE = 314,
    COLONATTR = 315,
    FORMLBRACK = 316,
    FORMRBRACK = 317,
    SUBLEXSTART = 318,
    SUBLEXEND = 319,
    PREC_LOW = 320,
    OROP = 321,
    DOROP = 322,
    ANDOP = 323,
    NOTOP = 324,
    ASSIGNOP = 325,
    OROR = 326,
    DORDOR = 327,
    ANDAND = 328,
    BITOROP = 329,
    BITANDOP = 330,
    SHIFTOP = 331,
    MATCHOP = 332,
    UMINUS = 333,
    REFGEN = 334,
    POWOP = 335,
    PREINC = 336,
    PREDEC = 337,
    POSTINC = 338,
    POSTDEC = 339,
    POSTJOIN = 340,
    ARROW = 341
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
 * 41d458c12a47d69d8ab1315970582b2055ecea77bfc8a582b557e9b3df1c290a perly.y
 * 0947213b55d0ed11693554bea04987e886cf285f5c14cf9075fa1e7acc3f4061 regen_perly.pl
 * ex: set ro: */
