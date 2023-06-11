/* -*- buffer-read-only: t -*-
   !!!!!!!   DO NOT EDIT THIS FILE   !!!!!!!
   This file is built by regen_perly.pl from perly.y.
   Any changes made here will be lost!
 */

#define PERL_BISON_VERSION  30006

/* A Bison parser, made by GNU Bison 3.6.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    GRAMPROG = 258,                /* GRAMPROG  */
    GRAMEXPR = 259,                /* GRAMEXPR  */
    GRAMBLOCK = 260,               /* GRAMBLOCK  */
    GRAMBARESTMT = 261,            /* GRAMBARESTMT  */
    GRAMFULLSTMT = 262,            /* GRAMFULLSTMT  */
    GRAMSTMTSEQ = 263,             /* GRAMSTMTSEQ  */
    GRAMSUBSIGNATURE = 264,        /* GRAMSUBSIGNATURE  */
    PERLY_AMPERSAND = 265,         /* PERLY_AMPERSAND  */
    PERLY_BRACE_OPEN = 266,        /* PERLY_BRACE_OPEN  */
    PERLY_BRACE_CLOSE = 267,       /* PERLY_BRACE_CLOSE  */
    PERLY_BRACKET_OPEN = 268,      /* PERLY_BRACKET_OPEN  */
    PERLY_BRACKET_CLOSE = 269,     /* PERLY_BRACKET_CLOSE  */
    PERLY_COMMA = 270,             /* PERLY_COMMA  */
    PERLY_DOLLAR = 271,            /* PERLY_DOLLAR  */
    PERLY_DOT = 272,               /* PERLY_DOT  */
    PERLY_EQUAL_SIGN = 273,        /* PERLY_EQUAL_SIGN  */
    PERLY_MINUS = 274,             /* PERLY_MINUS  */
    PERLY_PERCENT_SIGN = 275,      /* PERLY_PERCENT_SIGN  */
    PERLY_PLUS = 276,              /* PERLY_PLUS  */
    PERLY_SEMICOLON = 277,         /* PERLY_SEMICOLON  */
    PERLY_SLASH = 278,             /* PERLY_SLASH  */
    PERLY_SNAIL = 279,             /* PERLY_SNAIL  */
    PERLY_STAR = 280,              /* PERLY_STAR  */
    BAREWORD = 281,                /* BAREWORD  */
    METHOD = 282,                  /* METHOD  */
    FUNCMETH = 283,                /* FUNCMETH  */
    THING = 284,                   /* THING  */
    PMFUNC = 285,                  /* PMFUNC  */
    PRIVATEREF = 286,              /* PRIVATEREF  */
    QWLIST = 287,                  /* QWLIST  */
    FUNC0OP = 288,                 /* FUNC0OP  */
    FUNC0SUB = 289,                /* FUNC0SUB  */
    UNIOPSUB = 290,                /* UNIOPSUB  */
    LSTOPSUB = 291,                /* LSTOPSUB  */
    PLUGEXPR = 292,                /* PLUGEXPR  */
    PLUGSTMT = 293,                /* PLUGSTMT  */
    LABEL = 294,                   /* LABEL  */
    FORMAT = 295,                  /* FORMAT  */
    SUB = 296,                     /* SUB  */
    SIGSUB = 297,                  /* SIGSUB  */
    ANONSUB = 298,                 /* ANONSUB  */
    ANON_SIGSUB = 299,             /* ANON_SIGSUB  */
    PACKAGE = 300,                 /* PACKAGE  */
    USE = 301,                     /* USE  */
    WHILE = 302,                   /* WHILE  */
    UNTIL = 303,                   /* UNTIL  */
    IF = 304,                      /* IF  */
    UNLESS = 305,                  /* UNLESS  */
    ELSE = 306,                    /* ELSE  */
    ELSIF = 307,                   /* ELSIF  */
    CONTINUE = 308,                /* CONTINUE  */
    FOR = 309,                     /* FOR  */
    GIVEN = 310,                   /* GIVEN  */
    WHEN = 311,                    /* WHEN  */
    DEFAULT = 312,                 /* DEFAULT  */
    TRY = 313,                     /* TRY  */
    CATCH = 314,                   /* CATCH  */
    FINALLY = 315,                 /* FINALLY  */
    LOOPEX = 316,                  /* LOOPEX  */
    DOTDOT = 317,                  /* DOTDOT  */
    YADAYADA = 318,                /* YADAYADA  */
    FUNC0 = 319,                   /* FUNC0  */
    FUNC1 = 320,                   /* FUNC1  */
    FUNC = 321,                    /* FUNC  */
    UNIOP = 322,                   /* UNIOP  */
    LSTOP = 323,                   /* LSTOP  */
    MULOP = 324,                   /* MULOP  */
    ADDOP = 325,                   /* ADDOP  */
    DOLSHARP = 326,                /* DOLSHARP  */
    DO = 327,                      /* DO  */
    HASHBRACK = 328,               /* HASHBRACK  */
    NOAMP = 329,                   /* NOAMP  */
    LOCAL = 330,                   /* LOCAL  */
    MY = 331,                      /* MY  */
    REQUIRE = 332,                 /* REQUIRE  */
    COLONATTR = 333,               /* COLONATTR  */
    FORMLBRACK = 334,              /* FORMLBRACK  */
    FORMRBRACK = 335,              /* FORMRBRACK  */
    SUBLEXSTART = 336,             /* SUBLEXSTART  */
    SUBLEXEND = 337,               /* SUBLEXEND  */
    DEFER = 338,                   /* DEFER  */
    PREC_LOW = 339,                /* PREC_LOW  */
    OROP = 340,                    /* OROP  */
    ANDOP = 341,                   /* ANDOP  */
    NOTOP = 342,                   /* NOTOP  */
    ASSIGNOP = 343,                /* ASSIGNOP  */
    PERLY_QUESTION_MARK = 344,     /* PERLY_QUESTION_MARK  */
    PERLY_COLON = 345,             /* PERLY_COLON  */
    OROR = 346,                    /* OROR  */
    DORDOR = 347,                  /* DORDOR  */
    ANDAND = 348,                  /* ANDAND  */
    BITOROP = 349,                 /* BITOROP  */
    BITANDOP = 350,                /* BITANDOP  */
    CHEQOP = 351,                  /* CHEQOP  */
    NCEQOP = 352,                  /* NCEQOP  */
    CHRELOP = 353,                 /* CHRELOP  */
    NCRELOP = 354,                 /* NCRELOP  */
    SHIFTOP = 355,                 /* SHIFTOP  */
    MATCHOP = 356,                 /* MATCHOP  */
    PERLY_EXCLAMATION_MARK = 357,  /* PERLY_EXCLAMATION_MARK  */
    PERLY_TILDE = 358,             /* PERLY_TILDE  */
    UMINUS = 359,                  /* UMINUS  */
    REFGEN = 360,                  /* REFGEN  */
    POWOP = 361,                   /* POWOP  */
    PREINC = 362,                  /* PREINC  */
    PREDEC = 363,                  /* PREDEC  */
    POSTINC = 364,                 /* POSTINC  */
    POSTDEC = 365,                 /* POSTDEC  */
    POSTJOIN = 366,                /* POSTJOIN  */
    ARROW = 367,                   /* ARROW  */
    PERLY_PAREN_CLOSE = 368,       /* PERLY_PAREN_CLOSE  */
    PERLY_PAREN_OPEN = 369         /* PERLY_PAREN_OPEN  */
  };
  typedef enum yytokentype yytoken_kind_t;
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
 * 0caf1eb1cc4750131dc71e3a22ead383ed9a123dec61ccd23408ff13441fafde perly.y
 * acf1cbfd2545faeaaa58b1cf0cf9d7f98b5be0752eb7a54528ef904a9e2e1ca7 regen_perly.pl
 * ex: set ro: */
