#include "perly-5.35.1.h"
enum token_type {
    TOKENTYPE_NONE,
    TOKENTYPE_IVAL,
    TOKENTYPE_OPNUM, /* pl_yylval.ival contains an opcode number */
    TOKENTYPE_PVAL,
    TOKENTYPE_OPVAL
};

static struct debug_tokens {
    const int token;
    enum token_type type;
    const char *name;
} const debug_tokens[] =
{
    { ADDOP,		TOKENTYPE_OPNUM,	"ADDOP" },
    { ANDAND,		TOKENTYPE_NONE,		"ANDAND" },
    { ANDOP,		TOKENTYPE_NONE,		"ANDOP" },
    { ANONSUB,		TOKENTYPE_IVAL,		"ANONSUB" },
    { ANON_SIGSUB,	TOKENTYPE_IVAL,		"ANON_SIGSUB" },
    { ARROW,		TOKENTYPE_NONE,		"ARROW" },
    { ASSIGNOP,		TOKENTYPE_OPNUM,	"ASSIGNOP" },
    { BITANDOP,		TOKENTYPE_OPNUM,	"BITANDOP" },
    { BITOROP,		TOKENTYPE_OPNUM,	"BITOROP" },
    { CATCH,		TOKENTYPE_IVAL,		"CATCH" },
    { CHEQOP,		TOKENTYPE_OPNUM,	"CHEQOP" },
    { CHRELOP,		TOKENTYPE_OPNUM,	"CHRELOP" },
    { COLONATTR,	TOKENTYPE_NONE,		"COLONATTR" },
    { CONTINUE,		TOKENTYPE_NONE,		"CONTINUE" },
    { DEFAULT,		TOKENTYPE_NONE,		"DEFAULT" },
    { DO,		TOKENTYPE_NONE,		"DO" },
    { DOLSHARP,		TOKENTYPE_NONE,		"DOLSHARP" },
    { DORDOR,		TOKENTYPE_NONE,		"DORDOR" },
    { DOTDOT,		TOKENTYPE_IVAL,		"DOTDOT" },
    { ELSE,		TOKENTYPE_NONE,		"ELSE" },
    { ELSIF,		TOKENTYPE_IVAL,		"ELSIF" },
    { FOR,		TOKENTYPE_IVAL,		"FOR" },
    { FORMAT,		TOKENTYPE_NONE,		"FORMAT" },
    { FORMLBRACK,	TOKENTYPE_NONE,		"FORMLBRACK" },
    { FORMRBRACK,	TOKENTYPE_NONE,		"FORMRBRACK" },
    { FUNC,		TOKENTYPE_OPNUM,	"FUNC" },
    { FUNC0,		TOKENTYPE_OPNUM,	"FUNC0" },
    { FUNC0OP,		TOKENTYPE_OPVAL,	"FUNC0OP" },
    { FUNC0SUB,		TOKENTYPE_OPVAL,	"FUNC0SUB" },
    { FUNC1,		TOKENTYPE_OPNUM,	"FUNC1" },
    { FUNCMETH,		TOKENTYPE_OPVAL,	"FUNCMETH" },
    { GIVEN,		TOKENTYPE_IVAL,		"GIVEN" },
    { HASHBRACK,	TOKENTYPE_NONE,		"HASHBRACK" },
    { IF,		TOKENTYPE_IVAL,		"IF" },
    { LABEL,		TOKENTYPE_OPVAL,	"LABEL" },
    { LOCAL,		TOKENTYPE_IVAL,		"LOCAL" },
    { LOOPEX,		TOKENTYPE_OPNUM,	"LOOPEX" },
    { LSTOP,		TOKENTYPE_OPNUM,	"LSTOP" },
    { LSTOPSUB,		TOKENTYPE_OPVAL,	"LSTOPSUB" },
    { MATCHOP,		TOKENTYPE_OPNUM,	"MATCHOP" },
    { METHOD,		TOKENTYPE_OPVAL,	"METHOD" },
    { MULOP,		TOKENTYPE_OPNUM,	"MULOP" },
    { MY,		TOKENTYPE_IVAL,		"MY" },
    { NCEQOP,		TOKENTYPE_OPNUM,	"NCEQOP" },
    { NCRELOP,		TOKENTYPE_OPNUM,	"NCRELOP" },
    { NOAMP,		TOKENTYPE_NONE,		"NOAMP" },
    { NOTOP,		TOKENTYPE_NONE,		"NOTOP" },
    { OROP,		TOKENTYPE_IVAL,		"OROP" },
    { OROR,		TOKENTYPE_NONE,		"OROR" },
    { PACKAGE,		TOKENTYPE_NONE,		"PACKAGE" },
    { PERLY_AMPERSAND, TOKENTYPE_IVAL, "PERLY_AMPERSAND" },
    { PERLY_BRACE_CLOSE, TOKENTYPE_IVAL, "PERLY_BRACE_CLOSE" },
    { PERLY_BRACE_OPEN, TOKENTYPE_IVAL, "PERLY_BRACE_OPEN" },
    { PERLY_BRACKET_CLOSE, TOKENTYPE_IVAL, "PERLY_BRACKET_CLOSE" },
    { PERLY_BRACKET_OPEN, TOKENTYPE_IVAL, "PERLY_BRACKET_OPEN" },
    { PERLY_COLON, TOKENTYPE_IVAL, "PERLY_COLON" },
    { PERLY_COMMA, TOKENTYPE_IVAL, "PERLY_COMMA" },
    { PERLY_DOT, TOKENTYPE_IVAL, "PERLY_DOT" },
    { PERLY_EQUAL_SIGN, TOKENTYPE_IVAL, "PERLY_EQUAL_SIGN" },
    { PERLY_EXCLAMATION_MARK, TOKENTYPE_IVAL, "PERLY_EXCLAMATION_MARK" },
    { PERLY_MINUS, TOKENTYPE_IVAL, "PERLY_MINUS" },
    { PERLY_PAREN_OPEN, TOKENTYPE_IVAL, "PERLY_PAREN_OPEN" },
    { PERLY_PERCENT_SIGN, TOKENTYPE_IVAL, "PERLY_PERCENT_SIGN" },
    { PERLY_PLUS, TOKENTYPE_IVAL, "PERLY_PLUS" },
    { PERLY_QUESTION_MARK, TOKENTYPE_IVAL, "PERLY_QUESTION_MARK" },
    { PERLY_SEMICOLON, TOKENTYPE_IVAL, "PERLY_SEMICOLON" },
    { PERLY_SLASH, TOKENTYPE_IVAL, "PERLY_SLASH" },
    { PERLY_SNAIL, TOKENTYPE_IVAL, "PERLY_SNAIL" },
    { PERLY_STAR, TOKENTYPE_IVAL, "PERLY_STAR" },
    { PERLY_TILDE, TOKENTYPE_IVAL, "PERLY_TILDE" },
    { PLUGEXPR,		TOKENTYPE_OPVAL,	"PLUGEXPR" },
    { PLUGSTMT,		TOKENTYPE_OPVAL,	"PLUGSTMT" },
    { PMFUNC,		TOKENTYPE_OPVAL,	"PMFUNC" },
    { POSTJOIN,		TOKENTYPE_NONE,		"POSTJOIN" },
    { POSTDEC,		TOKENTYPE_NONE,		"POSTDEC" },
    { POSTINC,		TOKENTYPE_NONE,		"POSTINC" },
    { POWOP,		TOKENTYPE_OPNUM,	"POWOP" },
    { PREDEC,		TOKENTYPE_NONE,		"PREDEC" },
    { PREINC,		TOKENTYPE_NONE,		"PREINC" },
    { PRIVATEREF,	TOKENTYPE_OPVAL,	"PRIVATEREF" },
    { QWLIST,		TOKENTYPE_OPVAL,	"QWLIST" },
    { REFGEN,		TOKENTYPE_NONE,		"REFGEN" },
    { REQUIRE,		TOKENTYPE_NONE,		"REQUIRE" },
    { SHIFTOP,		TOKENTYPE_OPNUM,	"SHIFTOP" },
    { SIGSUB,		TOKENTYPE_NONE,		"SIGSUB" },
    { SUB,		TOKENTYPE_NONE,		"SUB" },
    { SUBLEXEND,	TOKENTYPE_NONE,		"SUBLEXEND" },
    { SUBLEXSTART,	TOKENTYPE_NONE,		"SUBLEXSTART" },
    { THING,		TOKENTYPE_OPVAL,	"THING" },
    { TRY,		TOKENTYPE_IVAL,		"TRY" },
    { UMINUS,		TOKENTYPE_NONE,		"UMINUS" },
    { UNIOP,		TOKENTYPE_OPNUM,	"UNIOP" },
    { UNIOPSUB,		TOKENTYPE_OPVAL,	"UNIOPSUB" },
    { UNLESS,		TOKENTYPE_IVAL,		"UNLESS" },
    { UNTIL,		TOKENTYPE_IVAL,		"UNTIL" },
    { USE,		TOKENTYPE_IVAL,		"USE" },
    { WHEN,		TOKENTYPE_IVAL,		"WHEN" },
    { WHILE,		TOKENTYPE_IVAL,		"WHILE" },
    { BAREWORD,		TOKENTYPE_OPVAL,	"BAREWORD" },
    { YADAYADA,		TOKENTYPE_IVAL,		"YADAYADA" },
    /* added by Perl::Lexer */
    { GRAMPROG, TOKENTYPE_OPNUM, "GRAMPROG" },
    { GRAMEXPR, TOKENTYPE_OPNUM, "GRAMEXPR" },
    { GRAMBLOCK, TOKENTYPE_OPNUM, "GRAMBLOCK" },
    { GRAMBARESTMT, TOKENTYPE_OPNUM, "GRAMBARESTMT" },
    { GRAMFULLSTMT, TOKENTYPE_OPNUM, "GRAMFULLSTMT" },
    { GRAMSTMTSEQ, TOKENTYPE_OPNUM, "GRAMSTMTSEQ" },
    { GRAMSUBSIGNATURE, TOKENTYPE_OPNUM, "GRAMSUBSIGNATURE" },
    { PERLY_AMPERSAND, TOKENTYPE_OPNUM, "PERLY_AMPERSAND" },
    { PERLY_BRACE_OPEN, TOKENTYPE_OPNUM, "PERLY_BRACE_OPEN" },
    { PERLY_BRACE_CLOSE, TOKENTYPE_OPNUM, "PERLY_BRACE_CLOSE" },
    { PERLY_BRACKET_OPEN, TOKENTYPE_OPNUM, "PERLY_BRACKET_OPEN" },
    { PERLY_BRACKET_CLOSE, TOKENTYPE_OPNUM, "PERLY_BRACKET_CLOSE" },
    { PERLY_COMMA, TOKENTYPE_OPNUM, "PERLY_COMMA" },
    { PERLY_DOLLAR, TOKENTYPE_OPNUM, "PERLY_DOLLAR" },
    { PERLY_DOT, TOKENTYPE_OPNUM, "PERLY_DOT" },
    { PERLY_EQUAL_SIGN, TOKENTYPE_OPNUM, "PERLY_EQUAL_SIGN" },
    { PERLY_MINUS, TOKENTYPE_OPNUM, "PERLY_MINUS" },
    { PERLY_PERCENT_SIGN, TOKENTYPE_OPNUM, "PERLY_PERCENT_SIGN" },
    { PERLY_PLUS, TOKENTYPE_OPNUM, "PERLY_PLUS" },
    { PERLY_SEMICOLON, TOKENTYPE_OPNUM, "PERLY_SEMICOLON" },
    { PERLY_SLASH, TOKENTYPE_OPNUM, "PERLY_SLASH" },
    { PERLY_SNAIL, TOKENTYPE_OPNUM, "PERLY_SNAIL" },
    { PERLY_STAR, TOKENTYPE_OPNUM, "PERLY_STAR" },
    { PREC_LOW, TOKENTYPE_OPNUM, "PREC_LOW" },
    { PERLY_QUESTION_MARK, TOKENTYPE_OPNUM, "PERLY_QUESTION_MARK" },
    { PERLY_COLON, TOKENTYPE_OPNUM, "PERLY_COLON" },
    { PERLY_EXCLAMATION_MARK, TOKENTYPE_OPNUM, "PERLY_EXCLAMATION_MARK" },
    { PERLY_TILDE, TOKENTYPE_OPNUM, "PERLY_TILDE" },
    { PERLY_PAREN_CLOSE, TOKENTYPE_OPNUM, "PERLY_PAREN_CLOSE" },
    { PERLY_PAREN_OPEN, TOKENTYPE_OPNUM, "PERLY_PAREN_OPEN" },
    { 0,		TOKENTYPE_NONE,		NULL }
};

