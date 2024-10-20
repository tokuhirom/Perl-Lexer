#include "perly-5.39.9.h"
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
    { ADDOP, TOKENTYPE_OPNUM, "ADDOP" },
    { ANDAND, TOKENTYPE_NONE, "ANDAND" },
    { ANDOP, TOKENTYPE_NONE, "ANDOP" },
    { ARROW, TOKENTYPE_NONE, "ARROW" },
    { ASSIGNOP, TOKENTYPE_OPNUM, "ASSIGNOP" },
    { BITANDOP, TOKENTYPE_OPNUM, "BITANDOP" },
    { BITOROP, TOKENTYPE_OPNUM, "BITOROP" },
    { CHEQOP, TOKENTYPE_OPNUM, "CHEQOP" },
    { CHRELOP, TOKENTYPE_OPNUM, "CHRELOP" },
    { COLONATTR, TOKENTYPE_NONE, "COLONATTR" },
    { DOLSHARP, TOKENTYPE_NONE, "DOLSHARP" },
    { DORDOR, TOKENTYPE_NONE, "DORDOR" },
    { DOTDOT, TOKENTYPE_IVAL, "DOTDOT" },
    { FORMLBRACK, TOKENTYPE_NONE, "FORMLBRACK" },
    { FORMRBRACK, TOKENTYPE_NONE, "FORMRBRACK" },
    { FUNC, TOKENTYPE_OPNUM, "FUNC" },
    { FUNC0, TOKENTYPE_OPNUM, "FUNC0" },
    { FUNC0OP, TOKENTYPE_OPVAL, "FUNC0OP" },
    { FUNC0SUB, TOKENTYPE_OPVAL, "FUNC0SUB" },
    { FUNC1, TOKENTYPE_OPNUM, "FUNC1" },
    { HASHBRACK, TOKENTYPE_NONE, "HASHBRACK" },
    { KW_CATCH, TOKENTYPE_IVAL, "KW_CATCH" },
    { KW_CLASS, TOKENTYPE_IVAL, "KW_CLASS" },
    { KW_CONTINUE, TOKENTYPE_IVAL, "KW_CONTINUE" },
    { KW_DEFAULT, TOKENTYPE_IVAL, "KW_DEFAULT" },
    { KW_DO, TOKENTYPE_IVAL, "KW_DO" },
    { KW_ELSE, TOKENTYPE_IVAL, "KW_ELSE" },
    { KW_ELSIF, TOKENTYPE_IVAL, "KW_ELSIF" },
    { KW_FIELD, TOKENTYPE_IVAL, "KW_FIELD" },
    { KW_GIVEN, TOKENTYPE_IVAL, "KW_GIVEN" },
    { KW_FOR, TOKENTYPE_IVAL, "KW_FOR" },
    { KW_FORMAT, TOKENTYPE_IVAL, "KW_FORMAT" },
    { KW_IF, TOKENTYPE_IVAL, "KW_IF" },
    { KW_LOCAL, TOKENTYPE_IVAL, "KW_LOCAL" },
    { KW_METHOD_anon, TOKENTYPE_IVAL, "KW_METHOD_anon" },
    { KW_METHOD_named, TOKENTYPE_IVAL, "KW_METHOD_named" },
    { KW_MY, TOKENTYPE_IVAL, "KW_MY" },
    { KW_PACKAGE, TOKENTYPE_IVAL, "KW_PACKAGE" },
    { KW_REQUIRE, TOKENTYPE_IVAL, "KW_REQUIRE" },
    { KW_SUB_anon, TOKENTYPE_IVAL, "KW_SUB_anon" },
    { KW_SUB_anon_sig, TOKENTYPE_IVAL, "KW_SUB_anon_sig" },
    { KW_SUB_named, TOKENTYPE_IVAL, "KW_SUB_named" },
    { KW_SUB_named_sig, TOKENTYPE_IVAL, "KW_SUB_named_sig" },
    { KW_TRY, TOKENTYPE_IVAL, "KW_TRY" },
    { KW_USE_or_NO, TOKENTYPE_IVAL, "KW_USE_or_NO" },
    { KW_UNLESS, TOKENTYPE_IVAL, "KW_UNLESS" },
    { KW_UNTIL, TOKENTYPE_IVAL, "KW_UNTIL" },
    { KW_WHEN, TOKENTYPE_IVAL, "KW_WHEN" },
    { KW_WHILE, TOKENTYPE_IVAL, "KW_WHILE" },
    { LABEL, TOKENTYPE_OPVAL, "LABEL" },
    { LOOPEX, TOKENTYPE_OPNUM, "LOOPEX" },
    { LSTOP, TOKENTYPE_OPNUM, "LSTOP" },
    { LSTOPSUB, TOKENTYPE_OPVAL, "LSTOPSUB" },
    { MATCHOP, TOKENTYPE_OPNUM, "MATCHOP" },
    { METHCALL, TOKENTYPE_OPVAL, "METHCALL" },
    { METHCALL0, TOKENTYPE_OPVAL, "METHCALL0" },
    { MULOP, TOKENTYPE_OPNUM, "MULOP" },
    { NCEQOP, TOKENTYPE_OPNUM, "NCEQOP" },
    { NCRELOP, TOKENTYPE_OPNUM, "NCRELOP" },
    { NOAMP, TOKENTYPE_NONE, "NOAMP" },
    { NOTOP, TOKENTYPE_NONE, "NOTOP" },
    { OROP, TOKENTYPE_IVAL, "OROP" },
    { OROR, TOKENTYPE_IVAL, "OROR" },
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
    { PLUGEXPR, TOKENTYPE_OPVAL, "PLUGEXPR" },
    { PLUGSTMT, TOKENTYPE_OPVAL, "PLUGSTMT" },
    { PLUGIN_ADD_OP, TOKENTYPE_PVAL, "PLUGIN_ADD_OP" },
    { PLUGIN_ASSIGN_OP, TOKENTYPE_PVAL, "PLUGIN_ASSIGN_OP" },
    { PLUGIN_HIGH_OP, TOKENTYPE_PVAL, "PLUGIN_HIGH_OP" },
    { PLUGIN_LOGICAL_AND_OP, TOKENTYPE_PVAL, "PLUGIN_LOGICAL_AND_OP" },
    { PLUGIN_LOGICAL_OR_OP, TOKENTYPE_PVAL, "PLUGIN_LOGICAL_OR_OP" },
    { PLUGIN_LOGICAL_AND_LOW_OP, TOKENTYPE_PVAL, "PLUGIN_LOGICAL_AND_LOW_OP" },
    { PLUGIN_LOGICAL_OR_LOW_OP, TOKENTYPE_PVAL, "PLUGIN_LOGICAL_OR_LOW_OP" },
    { PLUGIN_LOW_OP, TOKENTYPE_PVAL, "PLUGIN_LOW_OP" },
    { PLUGIN_MUL_OP, TOKENTYPE_PVAL, "PLUGIN_MUL_OP" },
    { PLUGIN_POW_OP, TOKENTYPE_PVAL, "PLUGIN_POW_OP" },
    { PLUGIN_REL_OP, TOKENTYPE_PVAL, "PLUGIN_REL_OP" },
    { PMFUNC, TOKENTYPE_OPVAL, "PMFUNC" },
    { POSTJOIN, TOKENTYPE_NONE, "POSTJOIN" },
    { POSTDEC, TOKENTYPE_NONE, "POSTDEC" },
    { POSTINC, TOKENTYPE_NONE, "POSTINC" },
    { POWOP, TOKENTYPE_OPNUM, "POWOP" },
    { PREDEC, TOKENTYPE_NONE, "PREDEC" },
    { PREINC, TOKENTYPE_NONE, "PREINC" },
    { PRIVATEREF, TOKENTYPE_OPVAL, "PRIVATEREF" },
    { QWLIST, TOKENTYPE_OPVAL, "QWLIST" },
    { REFGEN, TOKENTYPE_NONE, "REFGEN" },
    { SHIFTOP, TOKENTYPE_OPNUM, "SHIFTOP" },
    { SUBLEXEND, TOKENTYPE_NONE, "SUBLEXEND" },
    { SUBLEXSTART, TOKENTYPE_NONE, "SUBLEXSTART" },
    { THING, TOKENTYPE_OPVAL, "THING" },
    { UMINUS, TOKENTYPE_NONE, "UMINUS" },
    { UNIOP, TOKENTYPE_OPNUM, "UNIOP" },
    { UNIOPSUB, TOKENTYPE_OPVAL, "UNIOPSUB" },
    { BAREWORD, TOKENTYPE_OPVAL, "BAREWORD" },
    { YADAYADA, TOKENTYPE_IVAL, "YADAYADA" },
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
    { KW_FORMAT, TOKENTYPE_OPNUM, "KW_FORMAT" },
    { KW_PACKAGE, TOKENTYPE_OPNUM, "KW_PACKAGE" },
    { KW_CLASS, TOKENTYPE_OPNUM, "KW_CLASS" },
    { KW_LOCAL, TOKENTYPE_OPNUM, "KW_LOCAL" },
    { KW_MY, TOKENTYPE_OPNUM, "KW_MY" },
    { KW_FIELD, TOKENTYPE_OPNUM, "KW_FIELD" },
    { KW_IF, TOKENTYPE_OPNUM, "KW_IF" },
    { KW_ELSE, TOKENTYPE_OPNUM, "KW_ELSE" },
    { KW_ELSIF, TOKENTYPE_OPNUM, "KW_ELSIF" },
    { KW_UNLESS, TOKENTYPE_OPNUM, "KW_UNLESS" },
    { KW_FOR, TOKENTYPE_OPNUM, "KW_FOR" },
    { KW_UNTIL, TOKENTYPE_OPNUM, "KW_UNTIL" },
    { KW_WHILE, TOKENTYPE_OPNUM, "KW_WHILE" },
    { KW_CONTINUE, TOKENTYPE_OPNUM, "KW_CONTINUE" },
    { KW_GIVEN, TOKENTYPE_OPNUM, "KW_GIVEN" },
    { KW_WHEN, TOKENTYPE_OPNUM, "KW_WHEN" },
    { KW_DEFAULT, TOKENTYPE_OPNUM, "KW_DEFAULT" },
    { KW_TRY, TOKENTYPE_OPNUM, "KW_TRY" },
    { KW_CATCH, TOKENTYPE_OPNUM, "KW_CATCH" },
    { KW_FINALLY, TOKENTYPE_OPNUM, "KW_FINALLY" },
    { KW_DEFER, TOKENTYPE_OPNUM, "KW_DEFER" },
    { KW_REQUIRE, TOKENTYPE_OPNUM, "KW_REQUIRE" },
    { KW_DO, TOKENTYPE_OPNUM, "KW_DO" },
    { BAREWORD, TOKENTYPE_OPNUM, "BAREWORD" },
    { METHCALL0, TOKENTYPE_OPNUM, "METHCALL0" },
    { METHCALL, TOKENTYPE_OPNUM, "METHCALL" },
    { THING, TOKENTYPE_OPNUM, "THING" },
    { PMFUNC, TOKENTYPE_OPNUM, "PMFUNC" },
    { PRIVATEREF, TOKENTYPE_OPNUM, "PRIVATEREF" },
    { QWLIST, TOKENTYPE_OPNUM, "QWLIST" },
    { FUNC0OP, TOKENTYPE_OPNUM, "FUNC0OP" },
    { FUNC0SUB, TOKENTYPE_OPNUM, "FUNC0SUB" },
    { UNIOPSUB, TOKENTYPE_OPNUM, "UNIOPSUB" },
    { LSTOPSUB, TOKENTYPE_OPNUM, "LSTOPSUB" },
    { PLUGEXPR, TOKENTYPE_OPNUM, "PLUGEXPR" },
    { PLUGSTMT, TOKENTYPE_OPNUM, "PLUGSTMT" },
    { LABEL, TOKENTYPE_OPNUM, "LABEL" },
    { LOOPEX, TOKENTYPE_OPNUM, "LOOPEX" },
    { DOTDOT, TOKENTYPE_OPNUM, "DOTDOT" },
    { YADAYADA, TOKENTYPE_OPNUM, "YADAYADA" },
    { FUNC0, TOKENTYPE_OPNUM, "FUNC0" },
    { FUNC1, TOKENTYPE_OPNUM, "FUNC1" },
    { FUNC, TOKENTYPE_OPNUM, "FUNC" },
    { UNIOP, TOKENTYPE_OPNUM, "UNIOP" },
    { LSTOP, TOKENTYPE_OPNUM, "LSTOP" },
    { POWOP, TOKENTYPE_OPNUM, "POWOP" },
    { MULOP, TOKENTYPE_OPNUM, "MULOP" },
    { ADDOP, TOKENTYPE_OPNUM, "ADDOP" },
    { DOLSHARP, TOKENTYPE_OPNUM, "DOLSHARP" },
    { HASHBRACK, TOKENTYPE_OPNUM, "HASHBRACK" },
    { NOAMP, TOKENTYPE_OPNUM, "NOAMP" },
    { COLONATTR, TOKENTYPE_OPNUM, "COLONATTR" },
    { FORMLBRACK, TOKENTYPE_OPNUM, "FORMLBRACK" },
    { FORMRBRACK, TOKENTYPE_OPNUM, "FORMRBRACK" },
    { SUBLEXSTART, TOKENTYPE_OPNUM, "SUBLEXSTART" },
    { SUBLEXEND, TOKENTYPE_OPNUM, "SUBLEXEND" },
    { PHASER, TOKENTYPE_OPNUM, "PHASER" },
    { PREC_LOW, TOKENTYPE_OPNUM, "PREC_LOW" },
    { PLUGIN_LOW_OP, TOKENTYPE_OPNUM, "PLUGIN_LOW_OP" },
    { OROP, TOKENTYPE_OPNUM, "OROP" },
    { PLUGIN_LOGICAL_OR_LOW_OP, TOKENTYPE_OPNUM, "PLUGIN_LOGICAL_OR_LOW_OP" },
    { ANDOP, TOKENTYPE_OPNUM, "ANDOP" },
    { PLUGIN_LOGICAL_AND_LOW_OP, TOKENTYPE_OPNUM, "PLUGIN_LOGICAL_AND_LOW_OP" },
    { NOTOP, TOKENTYPE_OPNUM, "NOTOP" },
    { ASSIGNOP, TOKENTYPE_OPNUM, "ASSIGNOP" },
    { PLUGIN_ASSIGN_OP, TOKENTYPE_OPNUM, "PLUGIN_ASSIGN_OP" },
    { PERLY_QUESTION_MARK, TOKENTYPE_OPNUM, "PERLY_QUESTION_MARK" },
    { PERLY_COLON, TOKENTYPE_OPNUM, "PERLY_COLON" },
    { OROR, TOKENTYPE_OPNUM, "OROR" },
    { DORDOR, TOKENTYPE_OPNUM, "DORDOR" },
    { PLUGIN_LOGICAL_OR_OP, TOKENTYPE_OPNUM, "PLUGIN_LOGICAL_OR_OP" },
    { ANDAND, TOKENTYPE_OPNUM, "ANDAND" },
    { PLUGIN_LOGICAL_AND_OP, TOKENTYPE_OPNUM, "PLUGIN_LOGICAL_AND_OP" },
    { BITOROP, TOKENTYPE_OPNUM, "BITOROP" },
    { BITANDOP, TOKENTYPE_OPNUM, "BITANDOP" },
    { CHEQOP, TOKENTYPE_OPNUM, "CHEQOP" },
    { NCEQOP, TOKENTYPE_OPNUM, "NCEQOP" },
    { CHRELOP, TOKENTYPE_OPNUM, "CHRELOP" },
    { NCRELOP, TOKENTYPE_OPNUM, "NCRELOP" },
    { PLUGIN_REL_OP, TOKENTYPE_OPNUM, "PLUGIN_REL_OP" },
    { SHIFTOP, TOKENTYPE_OPNUM, "SHIFTOP" },
    { PLUGIN_ADD_OP, TOKENTYPE_OPNUM, "PLUGIN_ADD_OP" },
    { PLUGIN_MUL_OP, TOKENTYPE_OPNUM, "PLUGIN_MUL_OP" },
    { MATCHOP, TOKENTYPE_OPNUM, "MATCHOP" },
    { PERLY_EXCLAMATION_MARK, TOKENTYPE_OPNUM, "PERLY_EXCLAMATION_MARK" },
    { PERLY_TILDE, TOKENTYPE_OPNUM, "PERLY_TILDE" },
    { UMINUS, TOKENTYPE_OPNUM, "UMINUS" },
    { REFGEN, TOKENTYPE_OPNUM, "REFGEN" },
    { PLUGIN_POW_OP, TOKENTYPE_OPNUM, "PLUGIN_POW_OP" },
    { PREINC, TOKENTYPE_OPNUM, "PREINC" },
    { PREDEC, TOKENTYPE_OPNUM, "PREDEC" },
    { POSTINC, TOKENTYPE_OPNUM, "POSTINC" },
    { POSTDEC, TOKENTYPE_OPNUM, "POSTDEC" },
    { POSTJOIN, TOKENTYPE_OPNUM, "POSTJOIN" },
    { PLUGIN_HIGH_OP, TOKENTYPE_OPNUM, "PLUGIN_HIGH_OP" },
    { ARROW, TOKENTYPE_OPNUM, "ARROW" },
    { PERLY_PAREN_CLOSE, TOKENTYPE_OPNUM, "PERLY_PAREN_CLOSE" },
    { PERLY_PAREN_OPEN, TOKENTYPE_OPNUM, "PERLY_PAREN_OPEN" },
    { 0,		TOKENTYPE_NONE,		NULL }
};

