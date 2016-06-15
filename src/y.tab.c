#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140101

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "pascal.y"
	#include <stdio.h>
	#include <ctype.h>
	#include <stdlib.h>
	#include "util.h"
	#include "globals.h"
	#define YYSTYPE TreeNode*

	int totalLine;
	TreeNode * root;
	int hasError;
#line 30 "y.tab.c"

#ifndef YYSTYPE
typedef int YYSTYPE;
#endif

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define AND 257
#define ARRAY 258
#define ASSIGN 259
#define BEGINN 260
#define CASE 261
#define CHAR 262
#define COLON 263
#define COMMA 264
#define CONST 265
#define DIV 266
#define DO 267
#define DOT 268
#define DOTDOT 269
#define DOWNTO 270
#define ELSE 271
#define END 272
#define EQUAL 273
#define FOR 274
#define FUNCTION 275
#define GE 276
#define GOTO 277
#define GT 278
#define ID 279
#define IF 280
#define INTEGER 281
#define LB 282
#define LE 283
#define LP 284
#define LT 285
#define MINUS 286
#define MOD 287
#define MUL 288
#define NOT 289
#define OF 290
#define OR 291
#define PLUS 292
#define PROCEDURE 293
#define PROGRAM 294
#define RB 295
#define READ 296
#define REAL 297
#define RECORD 298
#define REPEAT 299
#define RP 300
#define SEMI 301
#define STRING 302
#define SYS_CON 303
#define SYS_FUNCT 304
#define SYS_PROC 305
#define SYS_TYPE 306
#define THEN 307
#define TO 308
#define TYPE 309
#define UNEQUAL 310
#define UNTIL 311
#define VAR 312
#define WHILE 313
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,    0,    1,    1,    1,    2,    5,    3,    6,
    7,    7,   11,   11,   12,   12,   12,   12,   12,    8,
    8,   13,   13,   14,   15,   15,   15,   16,   16,   16,
   16,   16,   16,   16,   17,   18,   20,   20,   21,   19,
   19,    9,    9,   22,   22,   23,   10,   10,   10,   10,
   10,   24,   26,   25,   28,   27,   27,   29,   29,   30,
   30,   31,   32,    4,   33,   34,   34,   34,   35,   35,
   36,   36,   36,   36,   36,   36,   36,   36,   36,   36,
   37,   37,   37,   38,   38,   38,   38,   38,   39,   49,
   49,   40,   41,   42,   50,   50,   43,   51,   51,   52,
   52,   44,   47,   47,   45,   45,   45,   45,   45,   45,
   45,   53,   53,   53,   53,   54,   54,   54,   54,   54,
   48,   48,   48,   48,   48,   48,   48,   48,   48,   48,
   46,   46,
};
static const short yylen[] = {                            2,
    3,    3,    1,    3,    3,    3,    2,    2,    5,    0,
    2,    0,    5,    4,    1,    1,    1,    1,    1,    2,
    0,    2,    1,    4,    1,    1,    1,    1,    1,    3,
    3,    4,    5,    3,    6,    3,    2,    1,    4,    3,
    1,    2,    0,    2,    1,    4,    2,    2,    1,    1,
    0,    4,    5,    4,    3,    3,    0,    3,    1,    3,
    3,    2,    1,    1,    3,    3,    0,    3,    3,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    3,    6,    5,    1,    4,    1,    4,    4,    5,    2,
    0,    4,    4,    8,    1,    1,    5,    2,    1,    4,
    4,    2,    3,    1,    3,    3,    3,    3,    3,    3,
    1,    3,    3,    3,    1,    3,    3,    3,    3,    1,
    1,    4,    1,    4,    1,    3,    2,    2,    4,    3,
    3,    1,
};
static const short yydefred[] = {                         0,
    3,    0,    0,   10,    0,    0,    0,    0,    0,    5,
    6,    4,    2,    1,   67,    7,   64,    0,    0,    0,
    0,    0,    0,    0,   80,    0,   65,    0,    0,    0,
    0,    0,    0,   67,    0,    0,   73,    0,   70,   71,
   72,   74,   75,   76,   77,   78,   79,    0,    0,    0,
    0,   23,    0,    0,   17,    0,   15,    0,    0,    0,
   16,   18,   19,    0,  125,    0,  120,    0,    0,    0,
  102,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   68,   66,    0,    0,    0,   22,   41,    0,    0,
   45,    0,    0,    0,   49,   50,    0,    0,    0,    0,
    0,    0,  128,  127,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   69,    0,    0,    0,
    0,    0,   14,    0,    0,    0,    0,    0,    0,   28,
    0,    0,   25,   26,   27,    0,    0,   44,    0,    0,
   47,   48,   10,   10,  130,    0,    0,  126,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   99,    0,    0,
    0,    0,  119,  117,  118,  116,    0,    0,    0,    0,
   85,    0,   88,    0,    0,   87,   93,   13,    0,    0,
    0,    0,    0,    0,   38,    0,   24,    0,   40,    0,
    0,   55,    0,    0,    0,  129,  122,  124,    0,    0,
   97,   98,   96,   95,    0,    0,    0,    0,    0,   89,
    0,    0,   34,   30,    0,    0,   36,   37,   31,   46,
    0,    0,    0,   59,    0,    0,    0,    8,   52,   54,
    0,    0,    0,    0,   90,    0,    0,   32,    0,    0,
   56,    0,    0,    0,   53,  101,  100,    0,    0,   33,
   39,   58,   60,   61,   94,   35,
};
static const short yydgoto[] = {                          3,
    4,    7,  203,   16,  204,    9,   19,   24,   54,   94,
   22,   65,   51,   52,  142,  143,  144,  145,   89,  194,
  195,   90,   91,   95,   96,   97,  201,   98,  233,  234,
  235,  236,   37,   20,   38,   39,   40,   41,   42,   43,
   44,   45,   46,   47,  124,  125,  131,   67,  220,  215,
  167,  168,   68,   69,
};
static const short yysindex[] = {                      -223,
    0, -232,    0,    0, -275, -250, -241, -228, -213,    0,
    0,    0,    0,    0,    0,    0,    0, -235, -267, -154,
 -199, -195, -136, -217,    0,  541,    0, -133, -173,  -20,
  541,  -94, -112,    0, -109,  541,    0, -237,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  579,  -86,  -83,
 -136,    0,  -99, -258,    0,  -58,    0,  541,  541,  541,
    0,    0,    0, -100,    0,  179,    0,  -89,  -93,  -67,
    0,  541,  -79,  541,  541,  221,  -42,  541,  -98,  541,
  507,    0,    0,  -81,  579, -169,    0,    0, -182,  -99,
    0,  -56,  -49, -258,    0,    0,  -80,  -70,  -46,  541,
  541,  144,    0,    0,  541,  541,  541,  541,  541,  541,
  561,  541,  541,  541,  541,  541,  541,  541,  541,  541,
  344,  -47,  260,  344, -246,  -52,    0,  -66,  541,  344,
 -239,  -52,    0,  -65,  -37,  -26,  -99,  579,  -99,    0,
  -23,  -51,    0,    0,    0, -169,  -30,    0,  -33,  -33,
    0,    0,    0,    0,    0,  302, -160,    0, -153,  -89,
  -89,  -89,  -89,  -89,  -11,   -8,  552,    0,  -89,  -93,
  -93,  -93,    0,    0,    0,    0,  102,  541,   -3,  541,
    0,   -6,    0,  344,  541,    0,    0,    0,   -2,  -12,
 -151,    1, -142, -236,    0,  579,    0,  -27,    0, -221,
   13,    0, -228,  -18,  -15,    0,    0,    0,  -52,  -52,
    0,    0,    0,    0,  541,  344,  541,  344,  -52,    0,
  344,  -14,    0,    0,  570, -169,    0,    0,    0,    0,
  -99,   27,  -84,    0,   33,   35,   -2,    0,    0,    0,
    6,    7,  524,  344,    0,    9,  579,    0,   10,   27,
    0, -221,   -2,   -2,    0,    0,    0,  -52, -169,    0,
    0,    0,    0,    0,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0, -252,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -244,    0,
    0, -247,    0, -108,    0,    0,    0,    0,    0, -242,
    0,    0,    0,    0, -226,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -220,    0,    0,   54,    0,    2,    0,    0,    0,    0,
    0,    0,    0,   49,    0,    0,    0,  259,   91,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -105,
    0,    0,    0,   57,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -171,    0,    0, -132,    0,    0,    0,    0,    0, -129,
    0,    0,    0,    0,    0, -135,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   55,   20,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  301,
  343,  385,  427,  469,    0,    0,    0,    0,  511,  133,
  175,  217,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -234,    0, -170,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -162,    0, -126,    0,    0,
 -114,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   60,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -157,    0,    0,    0,    0,    0,   61,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,  322,  125,  176,    0,    0,    0,    0,    0,
    0,  -48,    0,  278, -143, -184,    0,    0, -128,    0,
  137,    0,  243,  244,  248,    0,  193,    0,    0,   93,
    0,    0,   -7,  312, -122,  271,    0,    0,    0,    0,
    0,    0,    0,    0,  -24,   52,    0,  -39,    0,    0,
    0,  184,  777,  127,
};
#define YYTABLESIZE 889
static const short yytable[] = {                         84,
   17,   66,  198,  182,  222,   11,   76,   12,  191,  187,
  193,   81,   11,   84,   13,   21,   92,  180,   82,  103,
  104,   91,   12,    5,  185,   10,   14,   11,   84,   86,
   21,   15,    1,  102,   93,  227,  134,  141,  128,   20,
   12,   23,   88,   21,   86,   11,    6,  121,   21,  123,
   12,   18,  255,  181,   20,  130,   12,   88,   84,   12,
  186,   11,  166,   83,   11,  193,   91,   21,  263,  264,
    2,  232,   20,   48,   86,  156,  173,  174,  175,  176,
  146,  147,  249,   49,   81,   92,  241,  242,  135,  192,
  231,   20,   55,   83,   53,  177,  245,  141,   82,   81,
   92,   25,  250,  180,  184,   15,   26,   71,   83,  136,
  180,   57,  147,   82,  137,  266,  138,   27,  166,   28,
  226,  147,   29,  232,   30,   31,   32,   61,  139,   81,
   92,  132,   62,   63,  104,  265,  140,  131,   83,  207,
  141,   33,   50,   82,   34,   70,  208,  229,  224,  103,
   35,   43,  157,  216,   42,  218,  159,   25,   36,   29,
  221,   15,   26,  116,   29,   29,   43,  132,   77,   42,
  104,   78,  117,  131,   80,   28,  248,  141,   29,   88,
   30,   31,   32,  105,   43,  103,   85,   42,  141,   86,
  243,  120,  244,  118,  119,   17,  113,   33,  260,  122,
   34,  114,  115,   25,  141,  141,   35,   15,   26,   99,
  141,  178,  129,   25,   36,  251,  252,   15,   26,  133,
  153,   28,  149,  100,   29,  101,   30,   31,   32,  150,
  154,   28,  155,  183,   29,  188,   30,   31,   72,  170,
  171,  172,  190,   33,  189,  196,   34,   73,  199,  197,
  200,  209,   35,   33,  210,  217,   34,  121,  121,   55,
   36,   74,   35,   75,  219,  121,  223,  121,  121,  225,
   36,  121,  121,  230,  121,  237,  136,  121,   57,  121,
  246,  137,  239,  138,  121,  240,  121,  121,  121,  121,
  147,  121,  121,  121,   61,  253,  121,  254,  259,   62,
   63,  121,  121,  140,  123,  123,  256,  257,  121,  121,
  261,  121,  123,   51,  123,  123,    9,   57,  123,  123,
   57,  123,   63,   62,  123,    8,  123,  238,   87,  205,
  228,  123,  148,  123,  123,  123,  123,  151,  123,  123,
  123,  152,  202,  123,  262,   79,  115,  127,  123,  123,
  212,    0,    0,    0,  115,  123,  123,  115,  123,    0,
  115,  115,    0,  115,    0,    0,  115,    0,  115,    0,
    0,  213,    0,  115,  106,  115,  115,  107,    0,  108,
  115,  115,  115,    0,  109,  115,  110,    0,  113,    0,
  115,  115,    0,    0,    0,    0,  113,  115,  115,  113,
  115,    0,  113,  113,    0,  113,    0,    0,  113,  214,
  113,  112,    0,    0,    0,  113,  106,  113,  113,  107,
    0,  108,  113,  113,  113,    0,  109,  113,  110,    0,
  114,    0,  113,  113,    0,    0,    0,    0,  114,  113,
  113,  114,  113,  158,  114,  114,    0,  114,    0,    0,
  114,  106,  114,  112,  107,    0,  108,  114,    0,  114,
  114,  109,    0,  110,  114,  114,  114,    0,  111,  114,
    0,    0,  112,    0,  114,  114,    0,    0,    0,    0,
  112,  114,  114,  112,  114,    0,  112,  112,  112,  112,
    0,    0,  112,  106,  112,    0,  107,    0,  108,  112,
    0,  112,  112,  109,    0,  110,  112,  112,  112,    0,
    0,  112,    0,    0,  111,    0,  112,  112,    0,    0,
    0,    0,  111,  112,  112,  111,  112,  126,  111,  111,
  112,  111,  106,    0,  111,  107,  111,  108,    0,    0,
    0,  111,  109,  111,  110,    0,    0,    0,  111,    0,
    0,    0,    0,  111,  179,    0,  109,    0,  111,  111,
    0,    0,    0,    0,  109,  111,  111,  109,  111,  112,
  109,  109,    0,  109,  106,    0,  109,  107,  109,  108,
    0,    0,    0,  109,  109,  109,  110,    0,    0,    0,
  109,    0,    0,    0,    0,  109,  206,    0,  105,    0,
  109,  109,    0,    0,    0,    0,  105,  109,  109,  105,
  109,  112,  105,  105,    0,  105,  106,    0,  105,  107,
  105,  108,    0,    0,    0,  105,  109,  105,  110,    0,
    0,    0,  105,    0,    0,    0,    0,  105,    0,    0,
  106,    0,  105,  105,    0,    0,    0,    0,  106,  105,
  105,  106,  105,  112,  106,  106,    0,  106,    0,    0,
  106,    0,  106,    0,    0,    0,    0,  106,    0,  106,
    0,    0,    0,    0,  106,    0,    0,    0,    0,  106,
    0,    0,  107,    0,  106,  106,    0,    0,    0,    0,
  107,  106,  106,  107,  106,    0,  107,  107,    0,  107,
    0,    0,  107,    0,  107,    0,    0,    0,    0,  107,
    0,  107,    0,    0,    0,    0,  107,    0,    0,    0,
    0,  107,    0,    0,  108,    0,  107,  107,    0,    0,
    0,    0,  108,  107,  107,  108,  107,    0,  108,  108,
    0,  108,    0,    0,  108,    0,  108,    0,    0,    0,
    0,  108,    0,  108,    0,    0,    0,    0,  108,    0,
    0,    0,    0,  108,    0,    0,  110,    0,  108,  108,
    0,    0,    0,  132,  110,  108,  108,  110,  108,  106,
  110,  110,  107,  110,  108,    0,  110,    0,  110,  109,
  258,  110,    0,  110,    0,  110,  106,    0,    0,  107,
  110,  108,   55,    0,    0,  110,  109,    0,  110,    0,
  110,  110,    0,   55,    0,    0,  112,  110,  110,   56,
  110,   57,   55,  211,   58,    0,   59,    0,    0,   60,
  165,   55,   57,  112,    0,    0,    0,   61,    0,  165,
   55,   57,   62,   63,   64,    0,    0,    0,   61,    0,
   57,    0,    0,   62,   63,  247,    0,   61,    0,   57,
    0,    0,   62,   63,    0,    0,   61,    0,    0,    0,
    0,   62,   63,    0,    0,   61,    0,    0,    0,    0,
   62,   63,  160,  161,  162,  163,  164,    0,  169,
};
static const short yycheck[] = {                         48,
    8,   26,  146,  126,  189,  256,   31,  260,  137,  132,
  139,   36,  260,  256,  256,  260,  275,  264,  256,   59,
   60,  256,  275,  256,  264,  301,  268,  275,  271,  256,
  275,  260,  256,   58,  293,  272,   85,   86,   78,  260,
  293,  309,  279,  279,  271,  293,  279,   72,  293,   74,
  301,  265,  237,  300,  275,   80,  309,  279,  301,  312,
  300,  309,  111,  301,  312,  194,  301,  312,  253,  254,
  294,  200,  293,  273,  301,  100,  116,  117,  118,  119,
  263,  264,  226,  279,  256,  256,  209,  210,  258,  138,
  312,  312,  262,  256,  312,  120,  219,  146,  256,  271,
  271,  256,  231,  264,  129,  260,  261,  281,  271,  279,
  264,  281,  264,  271,  284,  259,  286,  272,  167,  274,
  263,  264,  277,  252,  279,  280,  281,  297,  298,  301,
  301,  264,  302,  303,  264,  258,  306,  264,  301,  300,
  189,  296,  279,  301,  299,  279,  300,  196,  300,  264,
  305,  260,  101,  178,  260,  180,  105,  256,  313,  295,
  185,  260,  261,  257,  300,  301,  275,  300,  263,  275,
  300,  284,  266,  300,  284,  274,  225,  226,  277,  279,
  279,  280,  281,  284,  293,  300,  273,  293,  237,  273,
  215,  259,  217,  287,  288,  203,  286,  296,  247,  279,
  299,  291,  292,  256,  253,  254,  305,  260,  261,  268,
  259,  259,  311,  256,  313,  300,  301,  260,  261,  301,
  301,  274,  279,  282,  277,  284,  279,  280,  281,  279,
  301,  274,  279,  300,  277,  301,  279,  280,  259,  113,
  114,  115,  269,  296,  282,  269,  299,  268,  279,  301,
  284,  263,  305,  296,  263,  259,  299,  256,  257,  262,
  313,  282,  305,  284,  271,  264,  279,  266,  267,  269,
  313,  270,  271,  301,  273,  263,  279,  276,  281,  278,
  295,  284,  301,  286,  283,  301,  285,  286,  287,  288,
  264,  290,  291,  292,  297,  263,  295,  263,  290,  302,
  303,  300,  301,  306,  256,  257,  301,  301,  307,  308,
  301,  310,  264,  260,  266,  267,  260,  263,  270,  271,
  301,  273,  263,  263,  276,    4,  278,  203,   51,  154,
  194,  283,   90,  285,  286,  287,  288,   94,  290,  291,
  292,   94,  150,  295,  252,   34,  256,   77,  300,  301,
  167,   -1,   -1,   -1,  264,  307,  308,  267,  310,   -1,
  270,  271,   -1,  273,   -1,   -1,  276,   -1,  278,   -1,
   -1,  270,   -1,  283,  273,  285,  286,  276,   -1,  278,
  290,  291,  292,   -1,  283,  295,  285,   -1,  256,   -1,
  300,  301,   -1,   -1,   -1,   -1,  264,  307,  308,  267,
  310,   -1,  270,  271,   -1,  273,   -1,   -1,  276,  308,
  278,  310,   -1,   -1,   -1,  283,  273,  285,  286,  276,
   -1,  278,  290,  291,  292,   -1,  283,  295,  285,   -1,
  256,   -1,  300,  301,   -1,   -1,   -1,   -1,  264,  307,
  308,  267,  310,  300,  270,  271,   -1,  273,   -1,   -1,
  276,  273,  278,  310,  276,   -1,  278,  283,   -1,  285,
  286,  283,   -1,  285,  290,  291,  292,   -1,  290,  295,
   -1,   -1,  256,   -1,  300,  301,   -1,   -1,   -1,   -1,
  264,  307,  308,  267,  310,   -1,  270,  271,  310,  273,
   -1,   -1,  276,  273,  278,   -1,  276,   -1,  278,  283,
   -1,  285,  286,  283,   -1,  285,  290,  291,  292,   -1,
   -1,  295,   -1,   -1,  256,   -1,  300,  301,   -1,   -1,
   -1,   -1,  264,  307,  308,  267,  310,  307,  270,  271,
  310,  273,  273,   -1,  276,  276,  278,  278,   -1,   -1,
   -1,  283,  283,  285,  285,   -1,   -1,   -1,  290,   -1,
   -1,   -1,   -1,  295,  295,   -1,  256,   -1,  300,  301,
   -1,   -1,   -1,   -1,  264,  307,  308,  267,  310,  310,
  270,  271,   -1,  273,  273,   -1,  276,  276,  278,  278,
   -1,   -1,   -1,  283,  283,  285,  285,   -1,   -1,   -1,
  290,   -1,   -1,   -1,   -1,  295,  295,   -1,  256,   -1,
  300,  301,   -1,   -1,   -1,   -1,  264,  307,  308,  267,
  310,  310,  270,  271,   -1,  273,  273,   -1,  276,  276,
  278,  278,   -1,   -1,   -1,  283,  283,  285,  285,   -1,
   -1,   -1,  290,   -1,   -1,   -1,   -1,  295,   -1,   -1,
  256,   -1,  300,  301,   -1,   -1,   -1,   -1,  264,  307,
  308,  267,  310,  310,  270,  271,   -1,  273,   -1,   -1,
  276,   -1,  278,   -1,   -1,   -1,   -1,  283,   -1,  285,
   -1,   -1,   -1,   -1,  290,   -1,   -1,   -1,   -1,  295,
   -1,   -1,  256,   -1,  300,  301,   -1,   -1,   -1,   -1,
  264,  307,  308,  267,  310,   -1,  270,  271,   -1,  273,
   -1,   -1,  276,   -1,  278,   -1,   -1,   -1,   -1,  283,
   -1,  285,   -1,   -1,   -1,   -1,  290,   -1,   -1,   -1,
   -1,  295,   -1,   -1,  256,   -1,  300,  301,   -1,   -1,
   -1,   -1,  264,  307,  308,  267,  310,   -1,  270,  271,
   -1,  273,   -1,   -1,  276,   -1,  278,   -1,   -1,   -1,
   -1,  283,   -1,  285,   -1,   -1,   -1,   -1,  290,   -1,
   -1,   -1,   -1,  295,   -1,   -1,  256,   -1,  300,  301,
   -1,   -1,   -1,  267,  264,  307,  308,  267,  310,  273,
  270,  271,  276,  273,  278,   -1,  276,   -1,  278,  283,
  267,  285,   -1,  283,   -1,  285,  273,   -1,   -1,  276,
  290,  278,  262,   -1,   -1,  295,  283,   -1,  285,   -1,
  300,  301,   -1,  262,   -1,   -1,  310,  307,  308,  279,
  310,  281,  262,  272,  284,   -1,  286,   -1,   -1,  289,
  279,  262,  281,  310,   -1,   -1,   -1,  297,   -1,  279,
  262,  281,  302,  303,  304,   -1,   -1,   -1,  297,   -1,
  281,   -1,   -1,  302,  303,  286,   -1,  297,   -1,  281,
   -1,   -1,  302,  303,   -1,   -1,  297,   -1,   -1,   -1,
   -1,  302,  303,   -1,   -1,  297,   -1,   -1,   -1,   -1,
  302,  303,  106,  107,  108,  109,  110,   -1,  112,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 313
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? (YYMAXTOKEN + 1) : (a))
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"AND","ARRAY","ASSIGN","BEGINN",
"CASE","CHAR","COLON","COMMA","CONST","DIV","DO","DOT","DOTDOT","DOWNTO","ELSE",
"END","EQUAL","FOR","FUNCTION","GE","GOTO","GT","ID","IF","INTEGER","LB","LE",
"LP","LT","MINUS","MOD","MUL","NOT","OF","OR","PLUS","PROCEDURE","PROGRAM","RB",
"READ","REAL","RECORD","REPEAT","RP","SEMI","STRING","SYS_CON","SYS_FUNCT",
"SYS_PROC","SYS_TYPE","THEN","TO","TYPE","UNEQUAL","UNTIL","VAR","WHILE",
"illegal-symbol",
};
static const char *yyrule[] = {
"$accept : program",
"program : program_head routine DOT",
"program : program_head routine error",
"program : error",
"program_head : PROGRAM ID SEMI",
"program_head : PROGRAM error SEMI",
"program_head : PROGRAM ID error",
"routine : routine_head routine_body",
"sub_routine : routine_head routine_body",
"routine_head : label_part const_part type_part var_part routine_part",
"label_part :",
"const_part : CONST const_expr_list",
"const_part :",
"const_expr_list : const_expr_list ID EQUAL const_value SEMI",
"const_expr_list : ID EQUAL const_value SEMI",
"const_value : INTEGER",
"const_value : REAL",
"const_value : CHAR",
"const_value : STRING",
"const_value : SYS_CON",
"type_part : TYPE type_decl_list",
"type_part :",
"type_decl_list : type_decl_list type_definition",
"type_decl_list : type_definition",
"type_definition : ID EQUAL type_decl SEMI",
"type_decl : simple_type_decl",
"type_decl : array_type_decl",
"type_decl : record_type_decl",
"simple_type_decl : SYS_TYPE",
"simple_type_decl : ID",
"simple_type_decl : LP name_list RP",
"simple_type_decl : const_value DOTDOT const_value",
"simple_type_decl : MINUS const_value DOTDOT const_value",
"simple_type_decl : MINUS const_value DOTDOT MINUS const_value",
"simple_type_decl : ID DOTDOT ID",
"array_type_decl : ARRAY LB simple_type_decl RB OF type_decl",
"record_type_decl : RECORD field_decl_list END",
"field_decl_list : field_decl_list field_decl",
"field_decl_list : field_decl",
"field_decl : name_list COLON type_decl SEMI",
"name_list : name_list COMMA ID",
"name_list : ID",
"var_part : VAR var_decl_list",
"var_part :",
"var_decl_list : var_decl_list var_decl",
"var_decl_list : var_decl",
"var_decl : name_list COLON type_decl SEMI",
"routine_part : routine_part function_decl",
"routine_part : routine_part procedure_decl",
"routine_part : function_decl",
"routine_part : procedure_decl",
"routine_part :",
"function_decl : function_head SEMI sub_routine SEMI",
"function_head : FUNCTION ID parameters COLON simple_type_decl",
"procedure_decl : procedure_head SEMI sub_routine SEMI",
"procedure_head : PROCEDURE ID parameters",
"parameters : LP para_decl_list RP",
"parameters :",
"para_decl_list : para_decl_list SEMI para_type_list",
"para_decl_list : para_type_list",
"para_type_list : var_para_list COLON simple_type_decl",
"para_type_list : val_para_list COLON simple_type_decl",
"var_para_list : VAR name_list",
"val_para_list : name_list",
"routine_body : compound_stmt",
"compound_stmt : BEGINN stmt_list END",
"stmt_list : stmt_list stmt SEMI",
"stmt_list :",
"stmt_list : stmt_list stmt error",
"stmt : INTEGER COLON non_label_stmt",
"stmt : non_label_stmt",
"non_label_stmt : assign_stmt",
"non_label_stmt : proc_stmt",
"non_label_stmt : compound_stmt",
"non_label_stmt : if_stmt",
"non_label_stmt : repeat_stmt",
"non_label_stmt : while_stmt",
"non_label_stmt : for_stmt",
"non_label_stmt : case_stmt",
"non_label_stmt : goto_stmt",
"non_label_stmt : error",
"assign_stmt : ID ASSIGN expression",
"assign_stmt : ID LB expression RB ASSIGN expression",
"assign_stmt : ID DOT ID ASSIGN expression",
"proc_stmt : ID",
"proc_stmt : ID LP args_list RP",
"proc_stmt : SYS_PROC",
"proc_stmt : SYS_PROC LP expression_list RP",
"proc_stmt : READ LP factor RP",
"if_stmt : IF expression THEN stmt else_clause",
"else_clause : ELSE stmt",
"else_clause :",
"repeat_stmt : REPEAT stmt_list UNTIL expression",
"while_stmt : WHILE expression DO stmt",
"for_stmt : FOR ID ASSIGN expression direction expression DO stmt",
"direction : TO",
"direction : DOWNTO",
"case_stmt : CASE expression OF case_expr_list END",
"case_expr_list : case_expr_list case_expr",
"case_expr_list : case_expr",
"case_expr : const_value COLON stmt SEMI",
"case_expr : ID COLON stmt SEMI",
"goto_stmt : GOTO INTEGER",
"expression_list : expression_list COMMA expression",
"expression_list : expression",
"expression : expression GE expr",
"expression : expression GT expr",
"expression : expression LE expr",
"expression : expression LT expr",
"expression : expression EQUAL expr",
"expression : expression UNEQUAL expr",
"expression : expr",
"expr : expr PLUS term",
"expr : expr MINUS term",
"expr : expr OR term",
"expr : term",
"term : term MUL factor",
"term : term DIV factor",
"term : term MOD factor",
"term : term AND factor",
"term : factor",
"factor : ID",
"factor : ID LP args_list RP",
"factor : SYS_FUNCT",
"factor : SYS_FUNCT LP args_list RP",
"factor : const_value",
"factor : LP expression RP",
"factor : NOT factor",
"factor : MINUS factor",
"factor : ID LB expression RB",
"factor : ID DOT ID",
"args_list : args_list COMMA expression",
"args_list : expression",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 1003 "pascal.y"
int yyerror(char *a){
	hasError = 1;
	return 0;
}


int printError(char *a){
	fprintf(stderr, "line %d: %s\n", lineno, a);
}

#line 647 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 74 "pascal.y"
	{
			yyval = newTreeNode(N_PROGRAM);
			appendChild(yyval, yystack.l_mark[-2]); 
			appendChild(yyval, yystack.l_mark[-1]); 

			/*          N_PROGRAM	
			 *			/		\
			 *			N_ID  	N_ROUTINE					
			 */

			if (!hasError) hasError = 0;
			root = yyval;
			totalLine = lineno;
		}
break;
case 2:
#line 88 "pascal.y"
	{
			printError("missing the <DOT> of the end of program");
		}
break;
case 3:
#line 91 "pascal.y"
	{
			printError("syntax error");		
		}
break;
case 4:
#line 95 "pascal.y"
	{
				yyval = yystack.l_mark[-1];
				}
break;
case 5:
#line 98 "pascal.y"
	{
			 	printError("missing <RPOGRAM NAME>");
			 }
break;
case 6:
#line 101 "pascal.y"
	{
			 	printError("missing <SEMI>");
			 }
break;
case 7:
#line 105 "pascal.y"
	{
			yyval = newTreeNode(N_ROUTINE);
			appendChild(yyval, yystack.l_mark[-1]);
			appendChild(yyval, yystack.l_mark[0]);
			/*          	N_ROUTINE	
			 *			/				\
			 *			N_ROUTINE_HEAD  	N_STMT_LIST					
			 */

		}
break;
case 8:
#line 117 "pascal.y"
	{
				yyval = newTreeNode(N_ROUTINE);
				appendChild(yyval, yystack.l_mark[-1]);
				appendChild(yyval, yystack.l_mark[0]);		
			/*          	N_ROUTINE	  //the same as N_ROUTINE
			 *			/				\
			 *			N_ROUTINE_HEAD  	N_STMT_LIST					
			 */

			}
break;
case 9:
#line 129 "pascal.y"
	{
				 yyval = newTreeNode(N_ROUTINE_HEAD);
				 appendChild(yyval, yystack.l_mark[-4]);
				 appendChild(yyval, yystack.l_mark[-3]);			
				 appendChild(yyval, yystack.l_mark[-2]);			
				 appendChild(yyval, yystack.l_mark[-1]);			
				 appendChild(yyval, yystack.l_mark[0]);

				/*          								N_ROUTINE_HEAD	  
				 *			/				|				|	        |                 |           	\
				 *			N_LABEL_PART   N_CONST_PART  N_TYPE_PART  N_VAR_PART  N_ROUTINE_PART N_ROUTINE_PART					
				 */
			 }
break;
case 10:
#line 144 "pascal.y"
	{
		   		yyval = newTreeNode(N_LABEL_PART);
           }
break;
case 11:
#line 149 "pascal.y"
	{
			   yyval = yystack.l_mark[0];
		   }
break;
case 12:
#line 152 "pascal.y"
	{
           		yyval = newTreeNode(N_CONST_PART);  /*an N_CONST_PART with empty child*/
		   }
break;
case 13:
#line 157 "pascal.y"
	{ 
					 yyval = yystack.l_mark[-4];  					/*eliminate left recursion*/
					 TreeNode* exp = newTreeNode(N_CONST_PART_EXP);
					 appendChild(exp, yystack.l_mark[-3]);
					 appendChild(exp, yystack.l_mark[-1]);
					 appendChild(yyval, exp);
				/*          					    N_CONST_PART	  
				 *			/				      |				   |           	\
				 *			N_CONST_PART_EXP   N_CONST_PART_EXP  ......  N_CONST_PART_EXP					
				 */
				}
break;
case 14:
#line 168 "pascal.y"
	{
					 yyval = newTreeNode(N_CONST_PART); 
					 TreeNode* exp = newTreeNode(N_CONST_PART_EXP);
					 appendChild(exp, yystack.l_mark[-3]);
					 appendChild(exp, yystack.l_mark[-1]);
					 appendChild(yyval, exp);

				/*          				N_CONST_PART_EXP	  
				 *							/	     	\
				 *			               N_ID       (N_INTEGER|N_REAL|N_CHAR|N_STRING|N_SYS_CON)					
				 */
				}
break;
case 15:
#line 182 "pascal.y"
	{
				 yyval = yystack.l_mark[0];
			}
break;
case 16:
#line 185 "pascal.y"
	{
				yyval = yystack.l_mark[0];
			}
break;
case 17:
#line 188 "pascal.y"
	{
				 yyval = yystack.l_mark[0];
			}
break;
case 18:
#line 191 "pascal.y"
	{
				 yyval = yystack.l_mark[0];
			}
break;
case 19:
#line 194 "pascal.y"
	{
				 yyval = yystack.l_mark[0];
			}
break;
case 20:
#line 199 "pascal.y"
	{
				 yyval = yystack.l_mark[0];			
		  }
break;
case 21:
#line 202 "pascal.y"
	{	 
				 yyval = newTreeNode(N_TYPE_PART);	 /*an N_TYPE_PART with empty child*/
		  }
break;
case 22:
#line 207 "pascal.y"
	{
	 		     	yyval = yystack.l_mark[-1];   /*eliminate left recursion*/
				 	appendChild(yyval, yystack.l_mark[0]);			
		  	   }
break;
case 23:
#line 211 "pascal.y"
	{
					 yyval = newTreeNode(N_TYPE_PART);
					 appendChild(yyval, yystack.l_mark[0]);

				/*          					    N_TYPE_PART	  
				 *			/				      |				   |           	\
				 *			N_TYPE_DEFINITION   N_TYPE_DEFINITION  ......  N_TYPE_DEFINITION					
				 */		
				}
break;
case 24:
#line 222 "pascal.y"
	{
	 			 yyval = newTreeNode(N_TYPE_DEFINITION);
				 appendChild(yyval, yystack.l_mark[-3]);	
				 appendChild(yyval, yystack.l_mark[-1]);
				/*          				N_TYPE_DEFINITION	  
				 *							/	     	\
				 *			               N_ID      (N_SIMPLE_TYPE_DECL|N_ARRAY_TYPE_DECL|N_RECORD_TYPE_DECL)					
				 */		
		        }
break;
case 25:
#line 233 "pascal.y"
	{
	 			yyval = yystack.l_mark[0];	
		  }
break;
case 26:
#line 236 "pascal.y"
	{
				 yyval = yystack.l_mark[0];				
		  }
break;
case 27:
#line 239 "pascal.y"
	{
				 yyval = yystack.l_mark[0];	
		  }
break;
case 28:
#line 244 "pascal.y"
	{
				 	yyval = newTreeNode(N_SIMPLE_TYPE_DECL);
				 	appendChild(yyval, yystack.l_mark[0]);
				/*          N_SIMPLE_TYPE_DECL	  
				 *					|	     	
				 *			    N_SYS_TYPE   					
				 */	
				 }
break;
case 29:
#line 252 "pascal.y"
	{
					yyval = newTreeNode(N_SIMPLE_TYPE_DECL);
				 	appendChild(yyval, yystack.l_mark[0]);					
				/*          N_SIMPLE_TYPE_DECL	  
				 *					|	     	
				 *			       N_ID   					
				 */	
				 }
break;
case 30:
#line 260 "pascal.y"
	{
					yyval = newTreeNode(N_SIMPLE_TYPE_DECL);
					appendChild(yyval, yystack.l_mark[-1]);
				/*          N_SIMPLE_TYPE_DECL	  
				 *					|	     	
				 *			    N_NAME_LIST   					
				 */	
				 }
break;
case 31:
#line 268 "pascal.y"
	{
					yyval = newTreeNode(N_SIMPLE_TYPE_DECL);
				 	appendChild(yyval, yystack.l_mark[-2]);	
					appendChild(yyval, yystack.l_mark[0]);		
				/*          								N_SIMPLE_TYPE_DECL	  
				 *			                                  /	     	 \
				 *	    (N_INTEGER|N_REAL|N_CHAR|N_STRING|N_SYS_CON)  	(N_INTEGER|N_REAL|N_CHAR|N_STRING|N_SYS_CON)				
				 */			
				 }
break;
case 32:
#line 277 "pascal.y"
	{
					yyval = newTreeNode(N_SIMPLE_TYPE_DECL);
				 	appendChild(yyval, yystack.l_mark[-3]);	
					appendChild(yyval, yystack.l_mark[-2]);	
					appendChild(yyval, yystack.l_mark[0]);	
				/*          									N_SIMPLE_TYPE_DECL	  
				 *		/	    		                              |	     	 \
				 *	N_MINUS    (N_INTEGER|N_REAL|N_CHAR|N_STRING|N_SYS_CON)  	(N_INTEGER|N_REAL|N_CHAR|N_STRING|N_SYS_CON)				
				 */				
				 }
break;
case 33:
#line 287 "pascal.y"
	{
                   	yyval = newTreeNode(N_SIMPLE_TYPE_DECL);
				 	appendChild(yyval, yystack.l_mark[-4]);	
					appendChild(yyval, yystack.l_mark[-3]);
					appendChild(yyval, yystack.l_mark[-1]);	
					appendChild(yyval, yystack.l_mark[0]);		

				/*          									N_SIMPLE_TYPE_DECL	  
				 *		/	    		                              |	     	|			 \
				 *	N_MINUS    (N_INTEGER|N_REAL|N_CHAR|N_STRING|N_SYS_CON)  	N_MINUS		(N_INTEGER|N_REAL|N_CHAR|N_STRING|N_SYS_CON)				
				 */			
				 }
break;
case 34:
#line 299 "pascal.y"
	{
				  	yyval = newTreeNode(N_SIMPLE_TYPE_DECL);
				 	appendChild(yyval, yystack.l_mark[-2]);	
					appendChild(yyval, yystack.l_mark[0]);
				/*     N_SIMPLE_TYPE_DECL	  
				 *		/    	 \
				 *	  N_ID   	N_ID		
				 */						
				 }
break;
case 35:
#line 309 "pascal.y"
	{
					yyval = newTreeNode(N_ARRAY_TYPE_DECL);
				 	appendChild(yyval, yystack.l_mark[-3]);		
					appendChild(yyval, yystack.l_mark[0]);
				/*    		N_ARRAY_TYPE_DECL	  
				 *		/    	 				\
				 *	  N_SIMPLE_TYPE_DECL   		(N_SIMPLE_TYPE_DECL|N_ARRAY_TYPE_DECL|N_RECORD_TYPE_DECL)		
				 */						
				}
break;
case 36:
#line 320 "pascal.y"
	{
				 	yyval = yystack.l_mark[-1];		
				 }
break;
case 37:
#line 325 "pascal.y"
	{
					yyval = yystack.l_mark[-1];	
					appendChild(yyval, yystack.l_mark[0]);					
				}
break;
case 38:
#line 329 "pascal.y"
	{
					yyval = newTreeNode(N_RECORD_TYPE_DECL);
				 	appendChild(yyval, yystack.l_mark[0]);	
				/*          					 N_RECORD_TYPE_DECL	  
				 *			/				      |				   |           	\
				 *			N_FIELD_DECL   N_FIELD_DECL        ......  N_FIELD_DECL					
				 */	
				}
break;
case 39:
#line 339 "pascal.y"
	{
	 			yyval = newTreeNode(N_FIELD_DECL);
			 	appendChild(yyval, yystack.l_mark[-3]);	
				appendChild(yyval, yystack.l_mark[-1]);	
				/*          	N_FILED_DECL  
				 *			/				\
				 *			N_NAME_LIST   (N_SIMPLE_TYPE_DECL|N_ARRAY_TYPE_DECL|N_RECORD_TYPE_DECL)					
				 */	
		   }
break;
case 40:
#line 350 "pascal.y"
	{
			yyval = yystack.l_mark[-2];	
			appendChild(yyval, yystack.l_mark[0]); 
			/*          	N_NAME_LIST	  
			 *			/		 |	   |   	\
			 *			N_ID   N_ID  ......  N_ID					
			 */	
          }
break;
case 41:
#line 358 "pascal.y"
	{
			yyval = newTreeNode(N_NAME_LIST);
		 	appendChild(yyval, yystack.l_mark[0]);		
		  }
break;
case 42:
#line 364 "pascal.y"
	{
			yyval = yystack.l_mark[0];
		 }
break;
case 43:
#line 367 "pascal.y"
	{
			yyval = newTreeNode(N_VAR_PART); /*empty var part*/
		 }
break;
case 44:
#line 371 "pascal.y"
	{
				  yyval = yystack.l_mark[-1];
				  appendChild(yyval, yystack.l_mark[0]);	
			/*          	N_VAR_PART 
			 *			/		       |	        |   	\
			 *			N_VAR_DECL   N_VAR_DECL  ......  N_VAR_DECL					
			 */	
			  }
break;
case 45:
#line 379 "pascal.y"
	{
					yyval = newTreeNode(N_VAR_PART);
		 			appendChild(yyval, yystack.l_mark[0]);
			  }
break;
case 46:
#line 384 "pascal.y"
	{
		 	yyval = newTreeNode(N_VAR_DECL);
		 	appendChild(yyval, yystack.l_mark[-3]);	
			appendChild(yyval, yystack.l_mark[-1]);
			/*          	N_VAR_DECL 
			 *			/	     		\
			 *			N_NAME_LIST   	(N_SIMPLE_TYPE_DECL|N_ARRAY_TYPE_DECL|N_RECORD_TYPE_DECL)					
			 */	
		 }
break;
case 47:
#line 395 "pascal.y"
	{
			 		yyval = yystack.l_mark[-1];
					appendChild(yyval, yystack.l_mark[0]);
			/*          											N_ROUTINE_PART 
			 *			/	     								|								|			\
			 *			(N_FUNCTION_DECL|N_PROCEDURE_DECL)  (N_FUNCTION_DECL|N_PROCEDURE_DECL) .... (N_FUNCTION_DECL|N_PROCEDURE_DECL)					
			 */	
				}
break;
case 48:
#line 403 "pascal.y"
	{
			 		yyval = yystack.l_mark[-1];	
					appendChild(yyval, yystack.l_mark[0]);
			 }
break;
case 49:
#line 407 "pascal.y"
	{
			 		yyval = newTreeNode(N_ROUTINE_PART);
		 			appendChild(yyval, yystack.l_mark[0]);	
			 }
break;
case 50:
#line 411 "pascal.y"
	{
			 		yyval = newTreeNode(N_ROUTINE_PART);
		 			appendChild(yyval, yystack.l_mark[0]);	
			 }
break;
case 51:
#line 415 "pascal.y"
	{
			 		yyval = newTreeNode(N_ROUTINE_PART); /*EMPTY ROUTINE PART*/
		     }
break;
case 52:
#line 420 "pascal.y"
	{
			  		yyval = newTreeNode(N_FUNCTION_DECL);
		 			appendChild(yyval, yystack.l_mark[-3]);
					appendChild(yyval, yystack.l_mark[-1]);		
			/*          N_FUNCTION_DECL 
			 *			/	     		\
			 *		N_FUNCTION_HEAD 	N_ROUTINE 				
			 */	
			  }
break;
case 53:
#line 431 "pascal.y"
	{
			  		yyval = newTreeNode(N_FUNCTION_HEAD);
					appendChild(yyval, yystack.l_mark[-3]);	
					appendChild(yyval, yystack.l_mark[-2]);	
					appendChild(yyval, yystack.l_mark[0]);	
			/*          N_FUNCTION_HEAD 
			 *			/	   |  				\
			 *		  N_ID	 N_PARAMETERS	N_SIMPLE_TYPE_DECL 				
			 */	
			  }
break;
case 54:
#line 443 "pascal.y"
	{
			   		yyval = newTreeNode(N_PROCEDURE_DECL);
		 			appendChild(yyval, yystack.l_mark[-3]);	
					appendChild(yyval, yystack.l_mark[-1]);	
			/*         N_PROCEDURE_DECL 
			 *			/	     		\
			 *		N_PROCEDURE_HEAD	N_ROUTINE 				
			 */	
			   }
break;
case 55:
#line 454 "pascal.y"
	{
					yyval = newTreeNode(N_PROCEDURE_HEAD);
		 			appendChild(yyval, yystack.l_mark[-2]);
					appendChild(yyval, yystack.l_mark[-1]);	
					appendChild(yyval, yystack.l_mark[0]);	
			/*          N_PROCEDURE_HEAD 
			 *			/	   \  				
			 *		  N_ID	 N_PARAMETERS					
			 */	
			   }
break;
case 56:
#line 466 "pascal.y"
	{
				yyval = yystack.l_mark[-1];
		   }
break;
case 57:
#line 469 "pascal.y"
	{
				yyval = newTreeNode(N_PARAMETERS);
			/*          				N_PARAMETERS
			 *			/	     		|	    	|			\
			 *			N_PARA_TYPE  N_PARA_TYPE ....    N_PARA_TYPE					
			 */	
		   }
break;
case 58:
#line 478 "pascal.y"
	{
					yyval = yystack.l_mark[-2];	
					appendChild(yyval, yystack.l_mark[0]);	
			   }
break;
case 59:
#line 482 "pascal.y"
	{
					yyval = newTreeNode(N_PARAMETERS);
		 			appendChild(yyval, yystack.l_mark[0]);
			   }
break;
case 60:
#line 488 "pascal.y"
	{
					yyval = newTreeNode(N_PARA_TYPE);
		 			appendChild(yyval, yystack.l_mark[-2]);
					appendChild(yyval, yystack.l_mark[0]);		
			/*          	N_PARA_TYPE
			 *			/	     		\
			 *			N_NAME_LIST   N_SIMPLE_TYPE_DECL				
			 */			
			   }
break;
case 61:
#line 497 "pascal.y"
	{
					yyval = newTreeNode(N_PARA_TYPE);
		 			appendChild(yyval, yystack.l_mark[-2]);	
					appendChild(yyval, yystack.l_mark[0]);				
			   }
break;
case 62:
#line 504 "pascal.y"
	{
					yyval = yystack.l_mark[0];	
   			  }
break;
case 63:
#line 509 "pascal.y"
	{
					yyval = yystack.l_mark[0];
			  }
break;
case 64:
#line 514 "pascal.y"
	{
					yyval = yystack.l_mark[0];   		
			 }
break;
case 65:
#line 519 "pascal.y"
	{
					yyval = yystack.l_mark[-1];
			  }
break;
case 66:
#line 524 "pascal.y"
	{
			yyval = yystack.l_mark[-2];
			appendChild(yyval, yystack.l_mark[-1]);
			/*          				N_STMT_LIST
			 *			/	     		|	    	|			\
			 *			N_STMT          N_STMT     ....        N_STMT					
			 */	
		  }
break;
case 67:
#line 532 "pascal.y"
	{
			yyval = newTreeNode(N_STMT_LIST);  
		  }
break;
case 68:
#line 535 "pascal.y"
	{
		  	printError("expected an ';' after an statement");
		  }
break;
case 69:
#line 539 "pascal.y"
	{
		yyval = newTreeNode(N_STMT);
		appendChild(yyval, yystack.l_mark[-2]);	
		appendChild(yyval, yystack.l_mark[0]);
			/*          	N_STMT
			 *			/			\
			 *		N_INTEGER     (N_ASSIGN_STMT|N_PROC_STMT|N_COMPOUND_STMT|N_IF_STMT|N_REPEAT_STMT|N_WHILE_STMT|N_FOR_STMT|N_CASE_STMT|N_GOTO_STMT)   					
			 */	
     }
break;
case 70:
#line 548 "pascal.y"
	{
		yyval = newTreeNode(N_STMT);
		appendChild(yyval, yystack.l_mark[0]);

			/*          	N_STMT
			 *				 |
			 *		(N_ASSIGN_STMT|N_PROC_STMT|N_COMPOUND_STMT|N_IF_STMT|N_REPEAT_STMT|N_WHILE_STMT|N_FOR_STMT|N_CASE_STMT|N_GOTO_STMT)   					
			 */	
     }
break;
case 71:
#line 559 "pascal.y"
	{
					yyval = yystack.l_mark[0];
			   }
break;
case 72:
#line 562 "pascal.y"
	{
					yyval = yystack.l_mark[0];
			   }
break;
case 73:
#line 565 "pascal.y"
	{
					yyval = yystack.l_mark[0];
			   }
break;
case 74:
#line 568 "pascal.y"
	{
					yyval = yystack.l_mark[0];
			   }
break;
case 75:
#line 571 "pascal.y"
	{
					yyval = yystack.l_mark[0];
			   }
break;
case 76:
#line 574 "pascal.y"
	{
					yyval = yystack.l_mark[0];
			   }
break;
case 77:
#line 577 "pascal.y"
	{
					yyval = yystack.l_mark[0];
   			   }
break;
case 78:
#line 580 "pascal.y"
	{
					yyval = yystack.l_mark[0];
			   }
break;
case 79:
#line 583 "pascal.y"
	{
					yyval = yystack.l_mark[0];
			   }
break;
case 80:
#line 586 "pascal.y"
	{
			   	 printError("illegal statement");
			   }
break;
case 81:
#line 591 "pascal.y"
	{
					yyval = newTreeNode(N_ASSIGN_STMT);
					appendChild(yyval, yystack.l_mark[-2]);
					TreeNode* exp = newTreeNode(N_EXPRESSION);
					appendChild(exp, yystack.l_mark[0]);
					appendChild(yyval, exp);
			/*          	N_ASSIGN_STMT
			 *			/			  \
			 *		N_ID         N_EXPRESSION   					
			 */	
			}
break;
case 82:
#line 602 "pascal.y"
	{
					yyval = newTreeNode(N_ASSIGN_STMT);
					appendChild(yyval, yystack.l_mark[-5]);
					TreeNode* exp1 = newTreeNode(N_EXPRESSION);
					appendChild(exp1, yystack.l_mark[-3]);
					TreeNode* exp2 = newTreeNode(N_EXPRESSION);
					appendChild(exp2, yystack.l_mark[0]);
					appendChild(yyval, exp1);
					appendChild(yyval, exp2);
			/*          	N_ASSIGN_STMT
			 *			/		|			  \
			 *		N_ID   N_EXPRESSION       N_EXPRESSION   					
			 */	
			}
break;
case 83:
#line 616 "pascal.y"
	{
					yyval = newTreeNode(N_ASSIGN_STMT);
					appendChild(yyval, yystack.l_mark[-4]);
					appendChild(yyval, yystack.l_mark[-2]);
					TreeNode* exp = newTreeNode(N_EXPRESSION);
					appendChild(exp, yystack.l_mark[0]);
					appendChild(yyval, exp);
			/*          	N_ASSIGN_STMT
			 *			/		|			  \
			 *		N_ID   		N_ID       N_EXPRESSION   					
			 */	
			}
break;
case 84:
#line 629 "pascal.y"
	{
				yyval = newTreeNode(N_PROC_STMT);
				appendChild(yyval, yystack.l_mark[0]);
			/*          	N_PROC_STMT
			 *					|			  
			 *		       		N_ID        					
			 */	
		  }
break;
case 85:
#line 637 "pascal.y"
	{
				yyval = newTreeNode(N_PROC_STMT);
				appendChild(yyval, yystack.l_mark[-3]);
				appendChild(yyval, yystack.l_mark[-1]);
			/*         N_PROC_STMT
			 *			/		 \
			 *		N_ID   		N_ARGS_LIST          					
			 */	
		  }
break;
case 86:
#line 646 "pascal.y"
	{
				yyval = newTreeNode(N_PROC_STMT);
				appendChild(yyval, yystack.l_mark[0]);
			/*          	N_PROC_STMT
			 *					|			  
			 *		       		N_SYS_PROC        					
			 */	
		  }
break;
case 87:
#line 654 "pascal.y"
	{
				yyval = newTreeNode(N_PROC_STMT);
				appendChild(yyval, yystack.l_mark[-3]);
				appendChild(yyval, yystack.l_mark[-1]);
			/*         N_PROC_STMT
			 *			/		 \
			 *		N_SYS_PROC   N_EXPRESSION_LIST          					
			 */	
		  }
break;
case 88:
#line 663 "pascal.y"
	{
				yyval = newTreeNode(N_PROC_STMT);
				appendChild(yyval, yystack.l_mark[-3]);
				appendChild(yyval, yystack.l_mark[-1]);
			/*          N_PROC_STMT
			 *				|	 
			 *			 N_FACTOR            					
			 */	
		  }
break;
case 89:
#line 674 "pascal.y"
	{
				yyval = newTreeNode(N_IF_STMT);
				TreeNode* exp = newTreeNode(N_EXPRESSION);
				appendChild(exp, yystack.l_mark[-3]);				
				appendChild(yyval, exp);
				appendChild(yyval, yystack.l_mark[-1]);
				appendChild(yyval, yystack.l_mark[0]);

			/*          	N_IF_STMT
			 *		/			|		 \ 
			 *	  N_EXPRESSION  N_STMT  N_STMT        					
			 */	
		}
break;
case 90:
#line 689 "pascal.y"
	{
				yyval = yystack.l_mark[0];
			}
break;
case 91:
#line 692 "pascal.y"
	{
				yyval = newTreeNode(N_STMT); /*an stmt with empty child*/
			}
break;
case 92:
#line 697 "pascal.y"
	{
				yyval = newTreeNode(N_REPEAT_STMT);
				appendChild(yyval, yystack.l_mark[-2]);
				TreeNode* exp = newTreeNode(N_EXPRESSION);
				appendChild(exp, yystack.l_mark[0]);
				appendChild(yyval, exp);
			/*          	N_REPEAT_STMT
			 *		/					 \ 
			 *	  N_STMT_LIST    		N_EXPRESSION        					
			 */	
			}
break;
case 93:
#line 710 "pascal.y"
	{
				yyval = newTreeNode(N_WHILE_STMT);
				TreeNode* exp = newTreeNode(N_EXPRESSION);
				appendChild(exp, yystack.l_mark[-2]);
				appendChild(yyval, exp);
				appendChild(yyval, yystack.l_mark[0]);
			
			/*          	N_WHILE_STMT
			 *				/			 \ 
			 *	  N_EXPRESSION    		N_STMT        					
			 */	
		   }
break;
case 94:
#line 724 "pascal.y"
	{
				yyval = newTreeNode(N_FOR_STMT);
				appendChild(yyval, yystack.l_mark[-6]);
				TreeNode* exp1 = newTreeNode(N_EXPRESSION);
				appendChild(exp1, yystack.l_mark[-4]);
				appendChild(yyval, exp1);
				appendChild(yyval, yystack.l_mark[-3]);
				TreeNode* exp2 = newTreeNode(N_EXPRESSION);
				appendChild(exp2, yystack.l_mark[-2]);
				appendChild(yyval, exp2);
				appendChild(yyval, yystack.l_mark[0]);
			/*          	N_FOR_STMT
			 *		/		|           |               |       	 \ 
			 *	  N_ID  N_EXPRESSION (N_TO|N_DOWNTO) N_EXPRESSION N_STMT        					
			 */	
		 }
break;
case 95:
#line 742 "pascal.y"
	{
			yyval = yystack.l_mark[0];
		  }
break;
case 96:
#line 745 "pascal.y"
	{
			yyval = yystack.l_mark[0];
		  }
break;
case 97:
#line 750 "pascal.y"
	{
			yyval = newTreeNode(N_CASE_STMT);
			TreeNode* exp = newTreeNode(N_EXPRESSION);
			appendChild(exp, yystack.l_mark[-3]);
			appendChild(yyval, exp);
			appendChild(yyval, yystack.l_mark[-1]);
			/*       N_CASE_STMT
			 *		/      	 \ 
			 * N_EXPRESSION N_CASE_EXPR_LIST        					
			 */
		  }
break;
case 98:
#line 763 "pascal.y"
	{
					yyval = yystack.l_mark[-1];
					appendChild(yyval, yystack.l_mark[0]);
			/*       N_CASE_EXPR_LIST
			 *		/      	 |           |   \ 
			 * N_CASE_EXPR N_CASE_EXPR ... N_CASE_EXPR        					
			 */

			   }
break;
case 99:
#line 772 "pascal.y"
	{
					yyval = newTreeNode(N_CASE_EXPR_LIST);
					appendChild(yyval, yystack.l_mark[0]);
			   }
break;
case 100:
#line 777 "pascal.y"
	{
			yyval = newTreeNode(N_CASE_EXPR);
			appendChild(yyval, yystack.l_mark[-3]);
			appendChild(yyval, yystack.l_mark[-1]);
			/*      								 N_CASE_STMT
			 *										/      	     \ 
			 * 	  (N_INTEGER|N_REAL|N_CHAR|N_STRING|N_SYS_CON)   N_STMT        					
			 */
		  }
break;
case 101:
#line 786 "pascal.y"
	{
			yyval = newTreeNode(N_CASE_EXPR);
			appendChild(yyval, yystack.l_mark[-3]);
			appendChild(yyval, yystack.l_mark[-1]);

			/*      N_CASE_STMT
			 *		/	     \ 
			 * 	  N_ID   N_STMT        					
			 */
		  }
break;
case 102:
#line 798 "pascal.y"
	{
			yyval = newTreeNode(N_GOTO_STMT);
			appendChild(yyval, yystack.l_mark[-1]);
			
			/*      N_GOTO_STMT
			 *		   |
			 * 	     N_INTEGER        					
			 */
		  }
break;
case 103:
#line 809 "pascal.y"
	{
					yyval = yystack.l_mark[-2];

					TreeNode* exp = newTreeNode(N_EXPRESSION);
					appendChild(exp, yystack.l_mark[0]);
					appendChild(yyval, exp);
			    }
break;
case 104:
#line 816 "pascal.y"
	{
					yyval = newTreeNode(N_EXPRESSION_LIST);
					TreeNode* exp = newTreeNode(N_EXPRESSION);
					appendChild(exp, yystack.l_mark[0]);
					appendChild(yyval, exp);
			/*       N_EXPRESSION_LIST
			 *		/      	 |           |   \ 
			 * N_EXPRESSION N_EXPRESSION ... N_EXPRESSION        					
			 */
				}
break;
case 105:
#line 828 "pascal.y"
	{
					yyval = newTreeNode(N_EXP_GE);
					appendChild(yyval, yystack.l_mark[-2]);
					appendChild(yyval, yystack.l_mark[0]);
		   }
break;
case 106:
#line 833 "pascal.y"
	{
					yyval = newTreeNode(N_EXP_GT);
					appendChild(yyval, yystack.l_mark[-2]);
					appendChild(yyval, yystack.l_mark[0]);
		   }
break;
case 107:
#line 838 "pascal.y"
	{
					yyval = newTreeNode(N_EXP_LE);
					appendChild(yyval, yystack.l_mark[-2]);
					appendChild(yyval, yystack.l_mark[0]);
		   }
break;
case 108:
#line 843 "pascal.y"
	{
					yyval = newTreeNode(N_EXP_LT);
					appendChild(yyval, yystack.l_mark[-2]);
					appendChild(yyval, yystack.l_mark[0]);
		   }
break;
case 109:
#line 848 "pascal.y"
	{
					yyval = newTreeNode(N_EXP_EQUAL);
					appendChild(yyval, yystack.l_mark[-2]);
					appendChild(yyval, yystack.l_mark[0]);
		   }
break;
case 110:
#line 853 "pascal.y"
	{
					yyval = newTreeNode(N_EXP_UNEQUAL);
					appendChild(yyval, yystack.l_mark[-2]);
					appendChild(yyval, yystack.l_mark[0]);
		   }
break;
case 111:
#line 858 "pascal.y"
	{
					yyval = yystack.l_mark[0];
		   }
break;
case 112:
#line 863 "pascal.y"
	{
					yyval = newTreeNode(N_EXP_PLUS);
					appendChild(yyval, yystack.l_mark[-2]);
					appendChild(yyval, yystack.l_mark[0]);
     }
break;
case 113:
#line 868 "pascal.y"
	{
					yyval = newTreeNode(N_EXP_MINUS);
					appendChild(yyval, yystack.l_mark[-2]);
					appendChild(yyval, yystack.l_mark[0]);
	 }
break;
case 114:
#line 873 "pascal.y"
	{
					yyval = newTreeNode(N_EXP_OR);
					appendChild(yyval, yystack.l_mark[-2]);
					appendChild(yyval, yystack.l_mark[0]);
	 }
break;
case 115:
#line 878 "pascal.y"
	{
					yyval = yystack.l_mark[0];
	 }
break;
case 116:
#line 883 "pascal.y"
	{
					yyval = newTreeNode(N_EXP_MUL);
					appendChild(yyval, yystack.l_mark[-2]);
					appendChild(yyval, yystack.l_mark[0]);
	 }
break;
case 117:
#line 888 "pascal.y"
	{
					yyval = newTreeNode(N_EXP_DIV);
					appendChild(yyval, yystack.l_mark[-2]);
					appendChild(yyval, yystack.l_mark[-1]);
					appendChild(yyval, yystack.l_mark[0]);
	 }
break;
case 118:
#line 894 "pascal.y"
	{
					yyval = newTreeNode(N_EXP_MOD);
					appendChild(yyval, yystack.l_mark[-2]);
					appendChild(yyval, yystack.l_mark[-1]);
					appendChild(yyval, yystack.l_mark[0]);
	 }
break;
case 119:
#line 900 "pascal.y"
	{
					yyval = newTreeNode(N_EXP_AND);
					appendChild(yyval, yystack.l_mark[-2]);
					appendChild(yyval, yystack.l_mark[-1]);
					appendChild(yyval, yystack.l_mark[0]);
	 }
break;
case 120:
#line 906 "pascal.y"
	{
					yyval = yystack.l_mark[0];
	 }
break;
case 121:
#line 911 "pascal.y"
	{
					yyval = yystack.l_mark[0];
	   }
break;
case 122:
#line 914 "pascal.y"
	{
					yyval = newTreeNode(N_FACTOR);
					appendChild(yyval, yystack.l_mark[-3]);
					appendChild(yyval, yystack.l_mark[-1]);
			/*      N_FACTOR
			 *		/		\
			 * 	   N_ID      N_ARGS_LIST  					
			 */
	   }
break;
case 123:
#line 923 "pascal.y"
	{
					yyval = newTreeNode(N_FACTOR);
					appendChild(yyval, yystack.l_mark[0]);
			/*      N_FACTOR
			 *			|
			 * 	   N_SYS_FUNCT   					
			 */
       }
break;
case 124:
#line 931 "pascal.y"
	{
					yyval = newTreeNode(N_FACTOR);
					appendChild(yyval, yystack.l_mark[-3]);
					appendChild(yyval, yystack.l_mark[-1]);
			/*      		N_FACTOR
			 *			/			\
			 * 	   N_SYS_FUNCT   	N_ARGS_LIST				
			 */
	   }
break;
case 125:
#line 940 "pascal.y"
	{
					yyval = yystack.l_mark[0];
	   }
break;
case 126:
#line 943 "pascal.y"
	{
					yyval = yystack.l_mark[-1];
	   }
break;
case 127:
#line 946 "pascal.y"
	{
					yyval = newTreeNode(N_FACTOR);
					appendChild(yyval, yystack.l_mark[-1]);
					appendChild(yyval, yystack.l_mark[0]);
			/*      N_FACTOR
			 *		/		\
			 * N_NOT		N_FACTOR			
			 */
	   }
break;
case 128:
#line 955 "pascal.y"
	{
					yyval = newTreeNode(N_FACTOR);
					appendChild(yyval, yystack.l_mark[-1]);
					appendChild(yyval, yystack.l_mark[0]);
			/*      N_FACTOR
			 *		/		\
			 * N_MINUS		N_FACTOR			
			 */
	   }
break;
case 129:
#line 964 "pascal.y"
	{
					yyval = newTreeNode(N_FACTOR);
					appendChild(yyval, yystack.l_mark[-3]);
					TreeNode* exp = newTreeNode(N_EXPRESSION);
					appendChild(exp, yystack.l_mark[-1]);
					appendChild(yyval, exp);
				
			/*      N_FACTOR
			 *		/		\
			 * N_ID			N_EXPRESSION			
			 */
	   }
break;
case 130:
#line 976 "pascal.y"
	{
					yyval = newTreeNode(N_FACTOR);
					appendChild(yyval, yystack.l_mark[-2]);
					appendChild(yyval, yystack.l_mark[0]);
			/*      N_FACTOR
			 *		/		\
			 * N_ID			N_ID			
			 */
	   }
break;
case 131:
#line 987 "pascal.y"
	{
					yyval = yystack.l_mark[-2];
					yyval = newTreeNode(N_ARGS_LIST);
					TreeNode* exp = newTreeNode(N_EXPRESSION);
					appendChild(exp, yystack.l_mark[0]);
					appendChild(yyval, exp);
		  }
break;
case 132:
#line 994 "pascal.y"
	{
					yyval = newTreeNode(N_ARGS_LIST);
					TreeNode* exp = newTreeNode(N_EXPRESSION);
					appendChild(exp, yystack.l_mark[0]);
					appendChild(yyval, exp);
		  }
break;
#line 2071 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
