
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 ".\\pascal.y"

	#include <stdio.h>
	#include <ctype.h>
	#include <stdlib.h>
	#include "util.h"
	#include "globals.h"
	#define YYSTYPE TreeNode*

	int totalLine;
	TreeNode * root;
	int hasError;


/* Line 189 of yacc.c  */
#line 87 "pascal.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     AND = 258,
     ARRAY = 259,
     ASSIGN = 260,
     BEGINN = 261,
     CASE = 262,
     CHAR = 263,
     COLON = 264,
     COMMA = 265,
     CONST = 266,
     DIV = 267,
     DO = 268,
     DOT = 269,
     DOTDOT = 270,
     DOWNTO = 271,
     ELSE = 272,
     END = 273,
     EQUAL = 274,
     FOR = 275,
     FUNCTION = 276,
     GE = 277,
     GOTO = 278,
     GT = 279,
     ID = 280,
     IF = 281,
     INTEGER = 282,
     LB = 283,
     LE = 284,
     LP = 285,
     LT = 286,
     MINUS = 287,
     MOD = 288,
     MUL = 289,
     NOT = 290,
     OF = 291,
     OR = 292,
     PLUS = 293,
     PROCEDURE = 294,
     PROGRAM = 295,
     RB = 296,
     READ = 297,
     REAL = 298,
     RECORD = 299,
     REPEAT = 300,
     RP = 301,
     SEMI = 302,
     STRING = 303,
     SYS_CON = 304,
     SYS_FUNCT = 305,
     SYS_PROC = 306,
     SYS_TYPE = 307,
     THEN = 308,
     TO = 309,
     TYPE = 310,
     UNEQUAL = 311,
     UNTIL = 312,
     VAR = 313,
     WHILE = 314
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 188 "pascal.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   527

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  171
/* YYNRULES -- Number of states.  */
#define YYNSTATES  332

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   314

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    11,    13,    17,    21,    25,    28,
      31,    34,    37,    43,    44,    47,    48,    51,    57,    62,
      67,    69,    71,    73,    75,    77,    79,    82,    83,    86,
      89,    91,    96,   101,   103,   105,   107,   109,   111,   115,
     119,   124,   130,   134,   138,   142,   149,   156,   163,   170,
     177,   181,   185,   188,   190,   195,   200,   205,   209,   211,
     215,   219,   222,   223,   226,   229,   231,   236,   241,   246,
     249,   252,   254,   256,   257,   262,   267,   272,   278,   284,
     290,   296,   301,   306,   311,   315,   319,   323,   324,   328,
     332,   334,   338,   342,   346,   349,   351,   353,   357,   361,
     362,   366,   370,   372,   374,   376,   378,   380,   382,   384,
     386,   388,   390,   392,   396,   403,   409,   411,   416,   418,
     423,   428,   433,   438,   443,   448,   454,   457,   458,   463,
     468,   477,   479,   481,   487,   493,   499,   502,   504,   509,
     514,   519,   522,   526,   528,   532,   536,   540,   544,   548,
     552,   554,   558,   562,   566,   568,   572,   576,   580,   584,
     586,   588,   593,   595,   600,   602,   606,   609,   612,   617,
     621,   625
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      61,     0,    -1,    62,    63,    14,    -1,    62,    63,     1,
      -1,     1,    -1,    40,    25,    47,    -1,    40,     1,    47,
      -1,    40,    25,     1,    -1,    65,    93,    -1,    65,     1,
      -1,    65,    93,    -1,    65,     1,    -1,    66,    67,    70,
      80,    83,    -1,    -1,    11,    68,    -1,    -1,    11,     1,
      -1,    68,    25,    19,    69,    47,    -1,    25,    19,    69,
      47,    -1,    25,    19,    69,     1,    -1,    27,    -1,    43,
      -1,     8,    -1,    48,    -1,    49,    -1,     1,    -1,    55,
      71,    -1,    -1,    55,     1,    -1,    71,    72,    -1,    72,
      -1,    25,    19,    73,    47,    -1,    25,    19,    73,     1,
      -1,    74,    -1,    75,    -1,    76,    -1,    52,    -1,    25,
      -1,    30,    79,    46,    -1,    69,    15,    69,    -1,    32,
      69,    15,    69,    -1,    32,    69,    15,    32,    69,    -1,
      25,    15,    25,    -1,    30,    79,     1,    -1,    25,    15,
       1,    -1,     4,    28,    74,    41,    36,    73,    -1,     4,
       1,    74,    41,    36,    73,    -1,     4,    28,    74,     1,
      36,    73,    -1,     4,    28,    74,    41,     1,    73,    -1,
       4,    28,    74,    41,    36,     1,    -1,    44,    77,    18,
      -1,    44,    77,     1,    -1,    77,    78,    -1,    78,    -1,
      79,     9,    73,    47,    -1,    79,     9,    73,     1,    -1,
      79,     1,    73,    47,    -1,    79,    10,    25,    -1,    25,
      -1,    79,     1,    25,    -1,    79,    10,     1,    -1,    58,
      81,    -1,    -1,    58,     1,    -1,    81,    82,    -1,    82,
      -1,    79,     9,    73,    47,    -1,    79,     1,    73,    47,
      -1,    79,     9,    73,     1,    -1,    83,    84,    -1,    83,
      86,    -1,    84,    -1,    86,    -1,    -1,    85,    47,    64,
      47,    -1,    85,     1,    64,    47,    -1,    85,    47,    64,
       1,    -1,    21,    25,    88,     9,    74,    -1,    21,     1,
      88,     9,    74,    -1,    21,    25,    88,     1,    74,    -1,
      21,    25,    88,     9,     1,    -1,    87,    47,    64,    47,
      -1,    87,     1,    64,    47,    -1,    87,    47,    64,     1,
      -1,    39,    25,    88,    -1,    39,     1,    88,    -1,    30,
      89,    46,    -1,    -1,    30,    89,     1,    -1,    89,    47,
      90,    -1,    90,    -1,    89,     1,    90,    -1,    91,     9,
      74,    -1,    92,     9,    74,    -1,    58,    79,    -1,    79,
      -1,    94,    -1,     6,    95,    18,    -1,    95,    96,    47,
      -1,    -1,    95,    96,     1,    -1,    27,     9,    97,    -1,
      97,    -1,    98,    -1,    99,    -1,    94,    -1,   100,    -1,
     102,    -1,   103,    -1,   104,    -1,   106,    -1,   109,    -1,
       1,    -1,    25,     5,   111,    -1,    25,    28,   111,    41,
       5,   111,    -1,    25,    14,    25,     5,   111,    -1,    25,
      -1,    25,    30,   115,    46,    -1,    51,    -1,    51,    30,
     110,    46,    -1,    42,    30,   114,    46,    -1,    25,    30,
     115,     1,    -1,    42,    30,   114,     1,    -1,    51,    30,
     110,     1,    -1,    42,     1,   114,    46,    -1,    26,   111,
      53,    96,   101,    -1,    17,    96,    -1,    -1,    45,    95,
      57,   111,    -1,    59,   111,    13,    96,    -1,    20,    25,
       5,   111,   105,   111,    13,    96,    -1,    54,    -1,    16,
      -1,     7,   111,    36,   107,    18,    -1,     7,   111,    36,
     107,     1,    -1,     7,   111,     1,   107,    18,    -1,   107,
     108,    -1,   108,    -1,    69,     9,    96,    47,    -1,    25,
       9,    96,    47,    -1,    69,     9,    96,     1,    -1,    23,
      27,    -1,   110,    10,   111,    -1,   111,    -1,   111,    22,
     112,    -1,   111,    24,   112,    -1,   111,    29,   112,    -1,
     111,    31,   112,    -1,   111,    19,   112,    -1,   111,    56,
     112,    -1,   112,    -1,   112,    38,   113,    -1,   112,    32,
     113,    -1,   112,    37,   113,    -1,   113,    -1,   113,    34,
     114,    -1,   113,    12,   114,    -1,   113,    33,   114,    -1,
     113,     3,   114,    -1,   114,    -1,    25,    -1,    25,    30,
     115,    46,    -1,    50,    -1,    50,    30,   115,    46,    -1,
      69,    -1,    30,   111,    46,    -1,    35,   114,    -1,    32,
     114,    -1,    25,    28,   111,    41,    -1,    25,    14,    25,
      -1,   115,    10,   111,    -1,   111,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    74,    74,    88,    91,    95,    98,   101,   105,   115,
     119,   129,   133,   148,   153,   156,   159,   164,   175,   187,
     192,   195,   198,   201,   204,   207,   212,   215,   218,   224,
     228,   239,   248,   253,   256,   259,   264,   272,   280,   288,
     297,   307,   319,   328,   331,   336,   345,   348,   351,   354,
     359,   362,   367,   371,   381,   390,   393,   398,   406,   410,
     413,   418,   421,   424,   429,   437,   442,   451,   454,   459,
     467,   471,   475,   479,   484,   493,   496,   501,   511,   514,
     517,   522,   531,   534,   539,   549,   554,   557,   564,   569,
     573,   577,   582,   591,   598,   603,   608,   613,   617,   625,
     628,   632,   641,   652,   655,   658,   661,   664,   667,   670,
     673,   676,   679,   684,   695,   709,   722,   730,   739,   747,
     756,   765,   768,   771,   775,   780,   795,   798,   803,   816,
     830,   848,   851,   856,   867,   870,   875,   884,   889,   898,
     908,   913,   924,   931,   943,   948,   953,   958,   963,   968,
     973,   978,   983,   988,   993,   998,  1003,  1008,  1013,  1018,
    1023,  1026,  1035,  1043,  1052,  1055,  1058,  1067,  1076,  1088,
    1099,  1105
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AND", "ARRAY", "ASSIGN", "BEGINN",
  "CASE", "CHAR", "COLON", "COMMA", "CONST", "DIV", "DO", "DOT", "DOTDOT",
  "DOWNTO", "ELSE", "END", "EQUAL", "FOR", "FUNCTION", "GE", "GOTO", "GT",
  "ID", "IF", "INTEGER", "LB", "LE", "LP", "LT", "MINUS", "MOD", "MUL",
  "NOT", "OF", "OR", "PLUS", "PROCEDURE", "PROGRAM", "RB", "READ", "REAL",
  "RECORD", "REPEAT", "RP", "SEMI", "STRING", "SYS_CON", "SYS_FUNCT",
  "SYS_PROC", "SYS_TYPE", "THEN", "TO", "TYPE", "UNEQUAL", "UNTIL", "VAR",
  "WHILE", "$accept", "program", "program_head", "routine", "sub_routine",
  "routine_head", "label_part", "const_part", "const_expr_list",
  "const_value", "type_part", "type_decl_list", "type_definition",
  "type_decl", "simple_type_decl", "array_type_decl", "record_type_decl",
  "field_decl_list", "field_decl", "name_list", "var_part",
  "var_decl_list", "var_decl", "routine_part", "function_decl",
  "function_head", "procedure_decl", "procedure_head", "parameters",
  "para_decl_list", "para_type_list", "var_para_list", "val_para_list",
  "routine_body", "compound_stmt", "stmt_list", "stmt", "non_label_stmt",
  "assign_stmt", "proc_stmt", "if_stmt", "else_clause", "repeat_stmt",
  "while_stmt", "for_stmt", "direction", "case_stmt", "case_expr_list",
  "case_expr", "goto_stmt", "expression_list", "expression", "expr",
  "term", "factor", "args_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    61,    61,    62,    62,    62,    63,    63,
      64,    64,    65,    66,    67,    67,    67,    68,    68,    68,
      69,    69,    69,    69,    69,    69,    70,    70,    70,    71,
      71,    72,    72,    73,    73,    73,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    75,    75,    75,    75,    75,
      76,    76,    77,    77,    78,    78,    78,    79,    79,    79,
      79,    80,    80,    80,    81,    81,    82,    82,    82,    83,
      83,    83,    83,    83,    84,    84,    84,    85,    85,    85,
      85,    86,    86,    86,    87,    87,    88,    88,    88,    89,
      89,    89,    90,    90,    91,    92,    93,    94,    95,    95,
      95,    96,    96,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    98,    98,    98,    99,    99,    99,    99,
      99,    99,    99,    99,    99,   100,   101,   101,   102,   103,
     104,   105,   105,   106,   106,   106,   107,   107,   108,   108,
     108,   109,   110,   110,   111,   111,   111,   111,   111,   111,
     111,   112,   112,   112,   112,   113,   113,   113,   113,   113,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     115,   115
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     1,     3,     3,     3,     2,     2,
       2,     2,     5,     0,     2,     0,     2,     5,     4,     4,
       1,     1,     1,     1,     1,     1,     2,     0,     2,     2,
       1,     4,     4,     1,     1,     1,     1,     1,     3,     3,
       4,     5,     3,     3,     3,     6,     6,     6,     6,     6,
       3,     3,     2,     1,     4,     4,     4,     3,     1,     3,
       3,     2,     0,     2,     2,     1,     4,     4,     4,     2,
       2,     1,     1,     0,     4,     4,     4,     5,     5,     5,
       5,     4,     4,     4,     3,     3,     3,     0,     3,     3,
       1,     3,     3,     3,     2,     1,     1,     3,     3,     0,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     6,     5,     1,     4,     1,     4,
       4,     4,     4,     4,     4,     5,     2,     0,     4,     4,
       8,     1,     1,     5,     5,     5,     2,     1,     4,     4,
       4,     2,     3,     1,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     3,     1,     3,     3,     3,     3,     1,
       1,     4,     1,     4,     1,     3,     2,     2,     4,     3,
       3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,     0,    13,     0,     0,     1,     0,     0,
      15,     6,     7,     5,     3,     2,     9,    99,     8,    96,
       0,    27,     0,    16,     0,    14,     0,    62,   112,     0,
      97,     0,     0,   116,     0,     0,     0,    99,   118,     0,
     105,     0,   102,   103,   104,   106,   107,   108,   109,   110,
     111,     0,     0,    28,     0,    26,    30,     0,    73,    25,
      22,   160,    20,     0,     0,     0,    21,    23,    24,   162,
     164,     0,   150,   154,   159,     0,   141,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   100,    98,
       0,     0,     0,    29,    63,    58,     0,    61,    65,     0,
       0,    12,    71,     0,    72,     0,     0,     0,     0,     0,
     167,   166,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   113,
       0,     0,   171,     0,     0,   101,     0,     0,     0,     0,
     143,     0,    19,    18,     0,     0,    37,     0,     0,     0,
      36,     0,     0,    33,    34,    35,     0,     0,     0,    64,
      87,    87,    87,    87,    69,    70,    13,    13,    13,    13,
     169,     0,     0,   165,     0,     0,     0,     0,   137,   148,
     144,   145,   146,   147,     0,   149,   152,   153,   151,   158,
     156,   157,   155,     0,     0,     0,   121,     0,   117,   127,
     124,   122,   120,   128,   123,     0,   119,   129,    17,     0,
       0,     0,     0,     0,     0,    53,     0,     0,    32,    31,
      59,     0,     0,    60,    57,     0,     0,     0,    85,    84,
       0,     0,     0,     0,     0,   168,   161,   163,     0,     0,
     135,   136,   134,   133,   132,   131,     0,   115,     0,   170,
       0,   125,   142,     0,     0,    44,    42,    43,    38,     0,
      51,    50,    52,     0,     0,    39,    67,    68,    66,     0,
       0,     0,    90,     0,     0,     0,     0,     0,    75,    11,
      10,    76,    74,    82,    83,    81,     0,     0,     0,   114,
     126,     0,     0,     0,    59,     0,    40,     0,     0,     0,
       0,    88,    86,     0,     0,     0,    78,    79,    80,    77,
     139,   140,   138,     0,     0,     0,     0,     0,    41,    56,
      55,    54,    91,    89,    92,    93,   130,    46,    47,    48,
      49,    45
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     8,   230,   231,    10,    21,    25,    70,
      27,    55,    56,   152,   153,   154,   155,   214,   215,   270,
      58,    97,    98,   101,   102,   103,   104,   105,   226,   271,
     272,   273,   274,    18,    40,    22,    41,    42,    43,    44,
      45,   251,    46,    47,    48,   246,    49,   177,   178,    50,
     139,   132,    72,    73,    74,   133
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -202
static const yytype_int16 yypact[] =
{
      91,  -202,   152,    17,  -202,   -19,    19,  -202,   101,   122,
      36,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,
     195,   107,    12,  -202,   157,   174,   234,   123,  -202,   354,
    -202,   204,   207,   177,   354,   231,     4,  -202,   213,   354,
    -202,    20,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,
    -202,   141,   227,  -202,   230,   235,  -202,   236,   109,  -202,
    -202,   282,  -202,   354,   354,   354,  -202,  -202,  -202,   222,
    -202,    60,   156,   198,  -202,   263,  -202,   354,   249,   354,
     354,   431,   250,   354,   354,   112,   354,   392,  -202,  -202,
      30,   141,   254,  -202,  -202,  -202,   229,   252,  -202,   244,
     246,   109,  -202,    77,  -202,    80,   253,   354,   354,   442,
    -202,  -202,   354,   179,   354,   354,   354,   354,   354,   179,
     354,   354,   354,   354,   354,   354,   354,   354,   354,   391,
     277,   448,   391,   133,   191,  -202,   239,    26,   354,   140,
     391,   191,  -202,  -202,   258,   124,   278,   252,   141,   252,
    -202,   285,    82,  -202,  -202,  -202,   286,   254,   279,  -202,
     291,   291,   291,   291,  -202,  -202,  -202,  -202,  -202,  -202,
    -202,   471,    -4,  -202,    14,   322,   327,   369,  -202,   156,
     156,   156,   156,   156,   382,   156,   198,   198,   198,  -202,
    -202,  -202,  -202,   427,   354,   321,  -202,   354,  -202,   320,
    -202,  -202,  -202,   391,  -202,   354,  -202,  -202,  -202,    21,
      21,   290,   154,   325,   184,  -202,   298,   141,  -202,  -202,
      18,   292,    89,  -202,  -202,    -9,   333,   194,  -202,  -202,
     297,   150,    93,   300,    97,  -202,  -202,  -202,   191,   191,
    -202,  -202,   336,  -202,  -202,  -202,   354,   391,   354,   391,
     191,  -202,   391,   309,   106,  -202,  -202,   308,  -202,   240,
    -202,  -202,  -202,   286,   254,  -202,  -202,  -202,  -202,   252,
     313,     9,  -202,   343,   344,    21,    21,   324,  -202,  -202,
    -202,  -202,  -202,  -202,  -202,  -202,   310,    98,   413,   391,
    -202,   330,   335,    22,  -202,   141,  -202,   311,    99,   318,
     308,    -9,  -202,    -9,    21,    21,  -202,  -202,   346,  -202,
    -202,  -202,  -202,   191,   254,   254,   254,   316,  -202,  -202,
    -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,
     346,  -202
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -202,  -202,  -202,  -202,   224,   359,  -202,  -202,  -202,   -51,
    -202,  -202,   314,  -142,  -201,  -202,  -202,  -202,   160,   -54,
    -202,  -202,   281,  -202,   274,  -202,   284,  -202,   266,  -202,
    -189,  -202,  -202,   149,    -8,   345,  -130,   306,  -202,  -202,
    -202,  -202,  -202,  -202,  -202,  -202,  -202,   276,   -67,  -202,
    -202,   -27,   393,   317,   -39,    53
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -96
static const yytype_int16 yytable[] =
{
      90,    19,    71,    96,   199,    83,   197,    81,   253,   254,
     301,   207,    87,    28,   221,   222,    95,     7,    17,    29,
      12,    88,    59,   316,   197,   110,   111,   201,    11,    60,
      30,   142,    31,   211,    84,    32,   109,    33,    34,    35,
     144,   151,   236,    96,   136,   137,   146,    20,    62,   269,
     129,   147,   131,   148,    36,   302,   303,    37,   317,   140,
     237,   113,   176,    38,    66,   -37,    13,    89,   176,    67,
      68,    39,   202,   150,   306,   307,   309,   143,   166,   114,
     171,   168,   115,   218,   116,   189,   190,   191,   192,   117,
     267,   118,     1,   212,   281,   216,   119,   213,   284,   311,
     320,   193,    14,   324,   325,   151,   151,   292,   286,   287,
     241,   203,   322,    28,   323,    15,   120,   241,    17,    29,
     290,   297,   298,    16,   167,   209,   176,   169,    17,   219,
      99,     2,    31,   176,   196,    32,   268,    33,    34,    35,
     282,   204,    59,   197,   285,   312,   321,   293,   100,    60,
     205,   279,   210,     5,    36,   257,    17,    37,   151,   151,
     216,   172,    26,    38,   158,   174,   265,   247,    62,   138,
     249,    39,   327,   328,   329,   331,    51,     6,   252,   198,
      59,    57,    77,   326,    66,   260,   206,    60,   121,    67,
      68,    78,    28,   122,   123,   276,    23,    17,    29,    52,
     258,   124,   261,   277,   175,    79,    62,    80,   296,    95,
     125,    31,   151,   151,    32,   299,    33,    34,    35,   288,
      24,   289,    66,    19,   151,   151,   151,    67,    68,    75,
     156,   126,   127,    36,    76,    53,    37,    94,   157,   158,
      82,    59,    38,    86,   318,   160,    91,   162,    60,    92,
      39,    28,   112,   151,   151,    59,    17,    29,   145,    54,
      54,    95,    60,   151,   151,   151,   151,    62,   128,   161,
      31,   163,   295,    32,   130,    33,    34,    95,   170,   146,
     223,    62,   194,    66,   147,   200,   148,    59,    67,    68,
     145,   255,    36,   211,    60,    37,   106,    66,   149,   263,
     217,    38,    67,    68,   224,   208,   150,   264,   158,    39,
     107,   220,   108,    62,   300,   256,   147,   330,   148,   300,
     145,   225,   -95,   158,    60,   308,   248,   -94,   158,    66,
     149,   238,    60,   294,    67,    68,   239,   250,   150,   266,
     259,   146,   275,    62,   278,   -25,   147,   283,   148,   146,
     291,    62,   304,   305,   147,    59,   148,   310,   319,    66,
     149,   -25,    60,     9,    67,    68,   314,    66,   150,    93,
      59,   315,    67,    68,   262,   164,   150,    60,   159,    61,
     280,    62,    85,   242,    63,   165,    64,   240,   135,    65,
      60,   232,   233,   234,   175,   184,    62,    66,     0,     0,
     243,     0,    67,    68,    69,   141,     0,   175,     0,    62,
     114,   114,    66,   115,   115,   116,   116,    67,    68,     0,
     117,   117,   118,   118,     0,    66,   313,   227,   228,   229,
      67,    68,   114,     0,     0,   115,     0,   116,   186,   187,
     188,     0,   117,   244,   118,     0,   114,   120,   120,   115,
     114,   116,     0,   115,     0,   116,   117,     0,   118,     0,
     117,   114,   118,     0,   115,     0,   116,   114,     0,   120,
     115,   117,   116,   118,     0,     0,     0,   117,     0,   118,
       0,   245,     0,   120,   134,     0,     0,   120,   173,   195,
     114,     0,     0,   115,     0,   116,     0,     0,   120,     0,
     117,     0,   118,     0,   120,     0,     0,   179,   180,   181,
     182,   183,   235,   185,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   120
};

static const yytype_int16 yycheck[] =
{
      51,     9,    29,    57,   134,     1,    10,    34,   209,   210,
       1,   141,    39,     1,   156,   157,    25,     0,     6,     7,
       1,     1,     1,     1,    10,    64,    65,     1,    47,     8,
      18,     1,    20,    15,    30,    23,    63,    25,    26,    27,
      91,    92,    46,    97,    83,    84,    25,    11,    27,    58,
      77,    30,    79,    32,    42,    46,    47,    45,    36,    86,
      46,     1,   113,    51,    43,    47,    47,    47,   119,    48,
      49,    59,    46,    52,   275,   276,   277,    47,     1,    19,
     107,     1,    22,     1,    24,   124,   125,   126,   127,    29,
       1,    31,     1,   147,     1,   149,    36,   148,     1,     1,
       1,   128,     1,   304,   305,   156,   157,     1,   238,   239,
     177,   138,   301,     1,   303,    14,    56,   184,     6,     7,
     250,   263,   264,     1,    47,     1,   177,    47,     6,    47,
      21,    40,    20,   184,     1,    23,    47,    25,    26,    27,
      47,     1,     1,    10,    47,    47,    47,    41,    39,     8,
      10,     1,    28,     1,    42,     1,     6,    45,   209,   210,
     214,   108,    55,    51,    10,   112,   217,   194,    27,    57,
     197,    59,   314,   315,   316,   317,    19,    25,   205,    46,
       1,    58,     5,   313,    43,     1,    46,     8,    32,    48,
      49,    14,     1,    37,    38,     1,     1,     6,     7,    25,
      46,     3,    18,     9,    25,    28,    27,    30,   259,    25,
      12,    20,   263,   264,    23,   269,    25,    26,    27,   246,
      25,   248,    43,   231,   275,   276,   277,    48,    49,    25,
       1,    33,    34,    42,    27,     1,    45,     1,     9,    10,
       9,     1,    51,    30,   295,     1,    19,     1,     8,    19,
      59,     1,    30,   304,   305,     1,     6,     7,     4,    25,
      25,    25,     8,   314,   315,   316,   317,    27,     5,    25,
      20,    25,    32,    23,    25,    25,    26,    25,    25,    25,
       1,    27,     5,    43,    30,    46,    32,     1,    48,    49,
       4,     1,    42,    15,     8,    45,    14,    43,    44,     1,
      15,    51,    48,    49,    25,    47,    52,     9,    10,    59,
      28,    25,    30,    27,     1,    25,    30,     1,    32,     1,
       4,    30,     9,    10,     8,     1,     5,     9,    10,    43,
      44,     9,     8,    25,    48,    49,     9,    17,    52,    47,
      15,    25,     9,    27,    47,     9,    30,    47,    32,    25,
      41,    27,     9,     9,    30,     1,    32,    47,    47,    43,
      44,    15,     8,     4,    48,    49,    36,    43,    52,    55,
       1,    36,    48,    49,   214,   101,    52,     8,    97,    25,
     231,    27,    37,     1,    30,   101,    32,    18,    82,    35,
       8,   167,   168,   169,    25,   119,    27,    43,    -1,    -1,
      18,    -1,    48,    49,    50,    13,    -1,    25,    -1,    27,
      19,    19,    43,    22,    22,    24,    24,    48,    49,    -1,
      29,    29,    31,    31,    -1,    43,    13,   161,   162,   163,
      48,    49,    19,    -1,    -1,    22,    -1,    24,   121,   122,
     123,    -1,    29,    16,    31,    -1,    19,    56,    56,    22,
      19,    24,    -1,    22,    -1,    24,    29,    -1,    31,    -1,
      29,    19,    31,    -1,    22,    -1,    24,    19,    -1,    56,
      22,    29,    24,    31,    -1,    -1,    -1,    29,    -1,    31,
      -1,    54,    -1,    56,    53,    -1,    -1,    56,    46,    41,
      19,    -1,    -1,    22,    -1,    24,    -1,    -1,    56,    -1,
      29,    -1,    31,    -1,    56,    -1,    -1,   114,   115,   116,
     117,   118,    41,   120,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    40,    61,    62,     1,    25,     0,    63,    65,
      66,    47,     1,    47,     1,    14,     1,     6,    93,    94,
      11,    67,    95,     1,    25,    68,    55,    70,     1,     7,
      18,    20,    23,    25,    26,    27,    42,    45,    51,    59,
      94,    96,    97,    98,    99,   100,   102,   103,   104,   106,
     109,    19,    25,     1,    25,    71,    72,    58,    80,     1,
       8,    25,    27,    30,    32,    35,    43,    48,    49,    50,
      69,   111,   112,   113,   114,    25,    27,     5,    14,    28,
      30,   111,     9,     1,    30,    95,    30,   111,     1,    47,
      69,    19,    19,    72,     1,    25,    79,    81,    82,    21,
      39,    83,    84,    85,    86,    87,    14,    28,    30,   111,
     114,   114,    30,     1,    19,    22,    24,    29,    31,    36,
      56,    32,    37,    38,     3,    12,    33,    34,     5,   111,
      25,   111,   111,   115,    53,    97,   114,   114,    57,   110,
     111,    13,     1,    47,    69,     4,    25,    30,    32,    44,
      52,    69,    73,    74,    75,    76,     1,     9,    10,    82,
       1,    25,     1,    25,    84,    86,     1,    47,     1,    47,
      25,   111,   115,    46,   115,    25,    69,   107,   108,   112,
     112,   112,   112,   112,   107,   112,   113,   113,   113,   114,
     114,   114,   114,   111,     5,    41,     1,    10,    46,    96,
      46,     1,    46,   111,     1,    10,    46,    96,    47,     1,
      28,    15,    79,    69,    77,    78,    79,    15,     1,    47,
      25,    73,    73,     1,    25,    30,    88,    88,    88,    88,
      64,    65,    64,    64,    64,    41,    46,    46,     9,     9,
      18,   108,     1,    18,    16,    54,   105,   111,     5,   111,
      17,   101,   111,    74,    74,     1,    25,     1,    46,    15,
       1,    18,    78,     1,     9,    69,    47,     1,    47,    58,
      79,    89,    90,    91,    92,     9,     1,     9,    47,     1,
      93,     1,    47,    47,     1,    47,    96,    96,   111,   111,
      96,    41,     1,    41,    25,    32,    69,    73,    73,    79,
       1,     1,    46,    47,     9,     9,    74,    74,     1,    74,
      47,     1,    47,    13,    36,    36,     1,    36,    69,    47,
       1,    47,    90,    90,    74,    74,    96,    73,    73,    73,
       1,    73
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 74 ".\\pascal.y"
    {
			(yyval) = newTreeNode(N_PROGRAM);
			appendChild((yyval), (yyvsp[(1) - (3)]));
			appendChild((yyval), (yyvsp[(2) - (3)]));

			/*          N_PROGRAM
			 *			/		\
			 *			N_ID  	N_ROUTINE
			 */

			if (!hasError) hasError = 0;
			root = (yyval);
			totalLine = lineno;
		;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 88 ".\\pascal.y"
    {
			printError("missing the <DOT> of the end of program");
		;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 91 ".\\pascal.y"
    {
			printError("syntax error");
		;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 95 ".\\pascal.y"
    {
				(yyval) = (yyvsp[(2) - (3)]);
				;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 98 ".\\pascal.y"
    {
			 	printError("missing <RPOGRAM NAME>");
			 ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 101 ".\\pascal.y"
    {
			 	printError("missing ';'");
			 ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 105 ".\\pascal.y"
    {
			(yyval) = newTreeNode(N_ROUTINE);
			appendChild((yyval), (yyvsp[(1) - (2)]));
			appendChild((yyval), (yyvsp[(2) - (2)]));
			/*          	N_ROUTINE
			 *			/				\
			 *			N_ROUTINE_HEAD  	N_STMT_LIST
			 */

		;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 115 ".\\pascal.y"
    {
			printError("missing program body");
		;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 119 ".\\pascal.y"
    {
				(yyval) = newTreeNode(N_ROUTINE);
				appendChild((yyval), (yyvsp[(1) - (2)]));
				appendChild((yyval), (yyvsp[(2) - (2)]));
			/*          	N_ROUTINE	  //the same as N_ROUTINE
			 *			/				\
			 *			N_ROUTINE_HEAD  	N_STMT_LIST
			 */

			;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 129 ".\\pascal.y"
    {
				printError("missing function body");
			;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 133 ".\\pascal.y"
    {
				 (yyval) = newTreeNode(N_ROUTINE_HEAD);
				 appendChild((yyval), (yyvsp[(1) - (5)]));
				 appendChild((yyval), (yyvsp[(2) - (5)]));
				 appendChild((yyval), (yyvsp[(3) - (5)]));
				 appendChild((yyval), (yyvsp[(4) - (5)]));
				 appendChild((yyval), (yyvsp[(5) - (5)]));

				/*          								N_ROUTINE_HEAD
				 *			/				|				|	        |                 |           	\
				 *			N_LABEL_PART   N_CONST_PART  N_TYPE_PART  N_VAR_PART  N_ROUTINE_PART N_ROUTINE_PART
				 */
			 ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 148 ".\\pascal.y"
    {
		   		(yyval) = newTreeNode(N_LABEL_PART);
           ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 153 ".\\pascal.y"
    {
			   (yyval) = (yyvsp[(2) - (2)]);
		   ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 156 ".\\pascal.y"
    {
           		(yyval) = newTreeNode(N_CONST_PART);  //an N_CONST_PART with empty child
		   ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 159 ".\\pascal.y"
    {
				printError("missing const expr list");
			;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 164 ".\\pascal.y"
    {
					 (yyval) = (yyvsp[(1) - (5)]);  					//eliminate left recursion
					 TreeNode* exp = newTreeNode(N_CONST_PART_EXP);
					 appendChild(exp, (yyvsp[(2) - (5)]));
					 appendChild(exp, (yyvsp[(4) - (5)]));
					 appendChild((yyval), exp);
				/*          					    N_CONST_PART
				 *			/				      |				   |           	\
				 *			N_CONST_PART_EXP   N_CONST_PART_EXP  ......  N_CONST_PART_EXP
				 */
				;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 175 ".\\pascal.y"
    {
					 (yyval) = newTreeNode(N_CONST_PART);
					 TreeNode* exp = newTreeNode(N_CONST_PART_EXP);
					 appendChild(exp, (yyvsp[(1) - (4)]));
					 appendChild(exp, (yyvsp[(3) - (4)]));
					 appendChild((yyval), exp);

				/*          				N_CONST_PART_EXP
				 *							/	     	\
				 *			               N_ID       (N_INTEGER|N_REAL|N_CHAR|N_STRING|N_SYS_CON)
				 */
				;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 187 ".\\pascal.y"
    {
				printError("missing ';'");
				;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 192 ".\\pascal.y"
    {
				 (yyval) = (yyvsp[(1) - (1)]);
			;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 195 ".\\pascal.y"
    {
				(yyval) = (yyvsp[(1) - (1)]);
			;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 198 ".\\pascal.y"
    {
				 (yyval) = (yyvsp[(1) - (1)]);
			;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 201 ".\\pascal.y"
    {
				 (yyval) = (yyvsp[(1) - (1)]);
			;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 204 ".\\pascal.y"
    {
				 (yyval) = (yyvsp[(1) - (1)]);
			;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 207 ".\\pascal.y"
    {
				printError("illegal const value");
			;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 212 ".\\pascal.y"
    {
				 (yyval) = (yyvsp[(2) - (2)]);
		  ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 215 ".\\pascal.y"
    {
				 (yyval) = newTreeNode(N_TYPE_PART);	 //an N_TYPE_PART with empty child
		  ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 218 ".\\pascal.y"
    {
				printError("missing type decl list");
			;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 224 ".\\pascal.y"
    {
	 		     	(yyval) = (yyvsp[(1) - (2)]);   //eliminate left recursion
				 	appendChild((yyval), (yyvsp[(2) - (2)]));
		  	   ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 228 ".\\pascal.y"
    {
					 (yyval) = newTreeNode(N_TYPE_PART);
					 appendChild((yyval), (yyvsp[(1) - (1)]));

				/*          					    N_TYPE_PART
				 *			/				      |				   |           	\
				 *			N_TYPE_DEFINITION   N_TYPE_DEFINITION  ......  N_TYPE_DEFINITION
				 */
				;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 239 ".\\pascal.y"
    {
	 			 (yyval) = newTreeNode(N_TYPE_DEFINITION);
				 appendChild((yyval), (yyvsp[(1) - (4)]));
				 appendChild((yyval), (yyvsp[(3) - (4)]));
				/*          				N_TYPE_DEFINITION
				 *							/	     	\
				 *			               N_ID      (N_SIMPLE_TYPE_DECL|N_ARRAY_TYPE_DECL|N_RECORD_TYPE_DECL)
				 */
		        ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 248 ".\\pascal.y"
    {
					printError("missing ';'");
				;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 253 ".\\pascal.y"
    {
	 			(yyval) = (yyvsp[(1) - (1)]);
		  ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 256 ".\\pascal.y"
    {
				 (yyval) = (yyvsp[(1) - (1)]);
		  ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 259 ".\\pascal.y"
    {
				 (yyval) = (yyvsp[(1) - (1)]);
		  ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 264 ".\\pascal.y"
    {
				 	(yyval) = newTreeNode(N_SIMPLE_TYPE_DECL);
				 	appendChild((yyval), (yyvsp[(1) - (1)]));
				/*          N_SIMPLE_TYPE_DECL
				 *					|
				 *			    N_SYS_TYPE
				 */
				 ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 272 ".\\pascal.y"
    {
					(yyval) = newTreeNode(N_SIMPLE_TYPE_DECL);
				 	appendChild((yyval), (yyvsp[(1) - (1)]));
				/*          N_SIMPLE_TYPE_DECL
				 *					|
				 *			       N_ID
				 */
				 ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 280 ".\\pascal.y"
    {
					(yyval) = newTreeNode(N_SIMPLE_TYPE_DECL);
					appendChild((yyval), (yyvsp[(2) - (3)]));
				/*          N_SIMPLE_TYPE_DECL
				 *					|
				 *			    N_NAME_LIST
				 */
				 ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 288 ".\\pascal.y"
    {
					(yyval) = newTreeNode(N_SIMPLE_TYPE_DECL);
				 	appendChild((yyval), (yyvsp[(1) - (3)]));
					appendChild((yyval), (yyvsp[(3) - (3)]));
				/*          								N_SIMPLE_TYPE_DECL
				 *			                                  /	     	 \
				 *	    (N_INTEGER|N_REAL|N_CHAR|N_STRING|N_SYS_CON)  	(N_INTEGER|N_REAL|N_CHAR|N_STRING|N_SYS_CON)
				 */
				 ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 297 ".\\pascal.y"
    {
					(yyval) = newTreeNode(N_SIMPLE_TYPE_DECL);
				 	appendChild((yyval), (yyvsp[(1) - (4)]));
					appendChild((yyval), (yyvsp[(2) - (4)]));
					appendChild((yyval), (yyvsp[(4) - (4)]));
				/*          									N_SIMPLE_TYPE_DECL
				 *		/	    		                              |	     	 \
				 *	N_MINUS    (N_INTEGER|N_REAL|N_CHAR|N_STRING|N_SYS_CON)  	(N_INTEGER|N_REAL|N_CHAR|N_STRING|N_SYS_CON)
				 */
				 ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 307 ".\\pascal.y"
    {
                   	(yyval) = newTreeNode(N_SIMPLE_TYPE_DECL);
				 	appendChild((yyval), (yyvsp[(1) - (5)]));
					appendChild((yyval), (yyvsp[(2) - (5)]));
					appendChild((yyval), (yyvsp[(4) - (5)]));
					appendChild((yyval), (yyvsp[(5) - (5)]));

				/*          									N_SIMPLE_TYPE_DECL
				 *		/	    		                              |	     	|			 \
				 *	N_MINUS    (N_INTEGER|N_REAL|N_CHAR|N_STRING|N_SYS_CON)  	N_MINUS		(N_INTEGER|N_REAL|N_CHAR|N_STRING|N_SYS_CON)
				 */
				 ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 319 ".\\pascal.y"
    {
				  	(yyval) = newTreeNode(N_SIMPLE_TYPE_DECL);
				 	appendChild((yyval), (yyvsp[(1) - (3)]));
					appendChild((yyval), (yyvsp[(3) - (3)]));
				/*     N_SIMPLE_TYPE_DECL
				 *		/    	 \
				 *	  N_ID   	N_ID
				 */
				 ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 328 ".\\pascal.y"
    {
					printError("missing right parenthness");
				;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 331 ".\\pascal.y"
    {
				printError("missing identifier after ..");
				;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 336 ".\\pascal.y"
    {
					(yyval) = newTreeNode(N_ARRAY_TYPE_DECL);
				 	appendChild((yyval), (yyvsp[(3) - (6)]));
					appendChild((yyval), (yyvsp[(6) - (6)]));
				/*    		N_ARRAY_TYPE_DECL
				 *		/    	 				\
				 *	  N_SIMPLE_TYPE_DECL   		(N_SIMPLE_TYPE_DECL|N_ARRAY_TYPE_DECL|N_RECORD_TYPE_DECL)
				 */
				;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 345 ".\\pascal.y"
    {
					printError("missing left barcket");
				;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 348 ".\\pascal.y"
    {
					printError("missing right barcket");
				;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 351 ".\\pascal.y"
    {
					printError("missing 'OF' after right barcket");
				;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 354 ".\\pascal.y"
    {
					printError("missing type declarations");
				;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 359 ".\\pascal.y"
    {
				 	(yyval) = (yyvsp[(2) - (3)]);
				 ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 362 ".\\pascal.y"
    {
					 printError("missing closing 'end'");
				;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 367 ".\\pascal.y"
    {
					(yyval) = (yyvsp[(1) - (2)]);
					appendChild((yyval), (yyvsp[(2) - (2)]));
				;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 371 ".\\pascal.y"
    {
					(yyval) = newTreeNode(N_RECORD_TYPE_DECL);
				 	appendChild((yyval), (yyvsp[(1) - (1)]));
				/*          					 N_RECORD_TYPE_DECL
				 *			/				      |				   |           	\
				 *			N_FIELD_DECL   N_FIELD_DECL        ......  N_FIELD_DECL
				 */
				;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 381 ".\\pascal.y"
    {
	 			(yyval) = newTreeNode(N_FIELD_DECL);
			 	appendChild((yyval), (yyvsp[(1) - (4)]));
				appendChild((yyval), (yyvsp[(3) - (4)]));
				/*          	N_FILED_DECL
				 *			/				\
				 *			N_NAME_LIST   (N_SIMPLE_TYPE_DECL|N_ARRAY_TYPE_DECL|N_RECORD_TYPE_DECL)
				 */
		   ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 390 ".\\pascal.y"
    {
				printError("missing ';'");
			;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 393 ".\\pascal.y"
    {
				printError("missing ':'");
			;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 398 ".\\pascal.y"
    {
			(yyval) = (yyvsp[(1) - (3)]);
			appendChild((yyval), (yyvsp[(3) - (3)]));
			/*          	N_NAME_LIST
			 *			/		 |	   |   	\
			 *			N_ID   N_ID  ......  N_ID
			 */
          ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 406 ".\\pascal.y"
    {
			(yyval) = newTreeNode(N_NAME_LIST);
		 	appendChild((yyval), (yyvsp[(1) - (1)]));
		  ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 410 ".\\pascal.y"
    {
				printError("missing ','");
			;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 413 ".\\pascal.y"
    {
				printError("missing identifier");
		  ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 418 ".\\pascal.y"
    {
			(yyval) = (yyvsp[(2) - (2)]);
		 ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 421 ".\\pascal.y"
    {
			(yyval) = newTreeNode(N_VAR_PART); //empty var part
		 ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 424 ".\\pascal.y"
    {
				printError("missing var declaration list");
		;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 429 ".\\pascal.y"
    {
				  (yyval) = (yyvsp[(1) - (2)]);
				  appendChild((yyval), (yyvsp[(2) - (2)]));
			/*          	N_VAR_PART
			 *			/		       |	        |   	\
			 *			N_VAR_DECL   N_VAR_DECL  ......  N_VAR_DECL
			 */
			  ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 437 ".\\pascal.y"
    {
					(yyval) = newTreeNode(N_VAR_PART);
		 			appendChild((yyval), (yyvsp[(1) - (1)]));
			  ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 442 ".\\pascal.y"
    {
		 	(yyval) = newTreeNode(N_VAR_DECL);
		 	appendChild((yyval), (yyvsp[(1) - (4)]));
			appendChild((yyval), (yyvsp[(3) - (4)]));
			/*          	N_VAR_DECL
			 *			/	     		\
			 *			N_NAME_LIST   	(N_SIMPLE_TYPE_DECL|N_ARRAY_TYPE_DECL|N_RECORD_TYPE_DECL)
			 */
		 ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 451 ".\\pascal.y"
    {
			printError("missing ':'");
		;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 454 ".\\pascal.y"
    {
			printError("missing ';'");
		;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 459 ".\\pascal.y"
    {
			 		(yyval) = (yyvsp[(1) - (2)]);
					appendChild((yyval), (yyvsp[(2) - (2)]));
			/*          											N_ROUTINE_PART
			 *			/	     								|								|			\
			 *			(N_FUNCTION_DECL|N_PROCEDURE_DECL)  (N_FUNCTION_DECL|N_PROCEDURE_DECL) .... (N_FUNCTION_DECL|N_PROCEDURE_DECL)
			 */
				;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 467 ".\\pascal.y"
    {
			 		(yyval) = (yyvsp[(1) - (2)]);
					appendChild((yyval), (yyvsp[(2) - (2)]));
			 ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 471 ".\\pascal.y"
    {
			 		(yyval) = newTreeNode(N_ROUTINE_PART);
		 			appendChild((yyval), (yyvsp[(1) - (1)]));
			 ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 475 ".\\pascal.y"
    {
			 		(yyval) = newTreeNode(N_ROUTINE_PART);
		 			appendChild((yyval), (yyvsp[(1) - (1)]));
			 ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 479 ".\\pascal.y"
    {
			 		(yyval) = newTreeNode(N_ROUTINE_PART); //EMPTY ROUTINE PART
		     ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 484 ".\\pascal.y"
    {
			  		(yyval) = newTreeNode(N_FUNCTION_DECL);
		 			appendChild((yyval), (yyvsp[(1) - (4)]));
					appendChild((yyval), (yyvsp[(3) - (4)]));
			/*          N_FUNCTION_DECL
			 *			/	     		\
			 *		N_FUNCTION_HEAD 	N_ROUTINE
			 */
			  ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 493 ".\\pascal.y"
    {
				printError("missing ';'");		
			;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 496 ".\\pascal.y"
    {
				printError("missing ';'");		
			;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 501 ".\\pascal.y"
    {
			  		(yyval) = newTreeNode(N_FUNCTION_HEAD);
					appendChild((yyval), (yyvsp[(2) - (5)]));
					appendChild((yyval), (yyvsp[(3) - (5)]));
					appendChild((yyval), (yyvsp[(5) - (5)]));
			/*          N_FUNCTION_HEAD
			 *			/	   |  				\
			 *		  N_ID	 N_PARAMETERS	N_SIMPLE_TYPE_DECL
			 */
			  ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 511 ".\\pascal.y"
    {
					printError("missing function name");				  
			  ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 514 ".\\pascal.y"
    {
					printError("missing ':'");				  
			  ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 517 ".\\pascal.y"
    {
					printError("missing function type declaration");				  
			  ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 522 ".\\pascal.y"
    {
			   		(yyval) = newTreeNode(N_PROCEDURE_DECL);
		 			appendChild((yyval), (yyvsp[(1) - (4)]));
					appendChild((yyval), (yyvsp[(3) - (4)]));
			/*         N_PROCEDURE_DECL
			 *			/	     		\
			 *		N_PROCEDURE_HEAD	N_ROUTINE
			 */
			   ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 531 ".\\pascal.y"
    {
				printError("missing ';'");		
			;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 534 ".\\pascal.y"
    {
				printError("missing ';'");		
			;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 539 ".\\pascal.y"
    {
					(yyval) = newTreeNode(N_PROCEDURE_HEAD);
		 			appendChild((yyval), (yyvsp[(1) - (3)]));
					appendChild((yyval), (yyvsp[(2) - (3)]));
					appendChild((yyval), (yyvsp[(3) - (3)]));
			/*          N_PROCEDURE_HEAD
			 *			/	   \
			 *		  N_ID	 N_PARAMETERS
			 */
			   ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 549 ".\\pascal.y"
    {
					printError("missing procedure name");	
				;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 554 ".\\pascal.y"
    {
				(yyval) = (yyvsp[(2) - (3)]);
		   ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 557 ".\\pascal.y"
    {
				(yyval) = newTreeNode(N_PARAMETERS);
			/*          				N_PARAMETERS
			 *			/	     		|	    	|			\
			 *			N_PARA_TYPE  N_PARA_TYPE ....    N_PARA_TYPE
			 */
		   ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 564 ".\\pascal.y"
    {
					printError("missing right paretheses");	
			;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 569 ".\\pascal.y"
    {
					(yyval) = (yyvsp[(1) - (3)]);
					appendChild((yyval), (yyvsp[(3) - (3)]));
			   ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 573 ".\\pascal.y"
    {
					(yyval) = newTreeNode(N_PARAMETERS);
		 			appendChild((yyval), (yyvsp[(1) - (1)]));
			   ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 577 ".\\pascal.y"
    {
					printError("missing ';'");	
				;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 582 ".\\pascal.y"
    {
					(yyval) = newTreeNode(N_PARA_TYPE);
		 			appendChild((yyval), (yyvsp[(1) - (3)]));
					appendChild((yyval), (yyvsp[(3) - (3)]));
			/*          	N_PARA_TYPE
			 *			/	     		\
			 *			N_NAME_LIST   N_SIMPLE_TYPE_DECL
			 */
			   ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 591 ".\\pascal.y"
    {
					(yyval) = newTreeNode(N_PARA_TYPE);
		 			appendChild((yyval), (yyvsp[(1) - (3)]));
					appendChild((yyval), (yyvsp[(3) - (3)]));
			   ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 598 ".\\pascal.y"
    {
					(yyval) = (yyvsp[(2) - (2)]);
   			  ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 603 ".\\pascal.y"
    {
					(yyval) = (yyvsp[(1) - (1)]);
			  ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 608 ".\\pascal.y"
    {
					(yyval) = (yyvsp[(1) - (1)]);
			 ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 613 ".\\pascal.y"
    {
					(yyval) = (yyvsp[(2) - (3)]);
			  ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 617 ".\\pascal.y"
    {
			(yyval) = (yyvsp[(1) - (3)]);
			appendChild((yyval), (yyvsp[(2) - (3)]));
			/*          				N_STMT_LIST
			 *			/	     		|	    	|			\
			 *			N_STMT          N_STMT     ....        N_STMT
			 */
		  ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 625 ".\\pascal.y"
    {
			(yyval) = newTreeNode(N_STMT_LIST);
		  ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 628 ".\\pascal.y"
    {
		  	printError("expected an ';' after an statement");
		  ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 632 ".\\pascal.y"
    {
		(yyval) = newTreeNode(N_STMT);
		appendChild((yyval), (yyvsp[(1) - (3)]));
		appendChild((yyval), (yyvsp[(3) - (3)]));
			/*          	N_STMT
			 *			/			\
			 *		N_INTEGER     (N_ASSIGN_STMT|N_PROC_STMT|N_COMPOUND_STMT|N_IF_STMT|N_REPEAT_STMT|N_WHILE_STMT|N_FOR_STMT|N_CASE_STMT|N_GOTO_STMT)
			 */
     ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 641 ".\\pascal.y"
    {
		(yyval) = newTreeNode(N_STMT);
		appendChild((yyval), (yyvsp[(1) - (1)]));

			/*          	N_STMT
			 *				 |
			 *		(N_ASSIGN_STMT|N_PROC_STMT|N_COMPOUND_STMT|N_IF_STMT|N_REPEAT_STMT|N_WHILE_STMT|N_FOR_STMT|N_CASE_STMT|N_GOTO_STMT)
			 */
     ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 652 ".\\pascal.y"
    {
					(yyval) = (yyvsp[(1) - (1)]);
			   ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 655 ".\\pascal.y"
    {
					(yyval) = (yyvsp[(1) - (1)]);
			   ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 658 ".\\pascal.y"
    {
					(yyval) = (yyvsp[(1) - (1)]);
			   ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 661 ".\\pascal.y"
    {
					(yyval) = (yyvsp[(1) - (1)]);
			   ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 664 ".\\pascal.y"
    {
					(yyval) = (yyvsp[(1) - (1)]);
			   ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 667 ".\\pascal.y"
    {
					(yyval) = (yyvsp[(1) - (1)]);
			   ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 670 ".\\pascal.y"
    {
					(yyval) = (yyvsp[(1) - (1)]);
   			   ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 673 ".\\pascal.y"
    {
					(yyval) = (yyvsp[(1) - (1)]);
			   ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 676 ".\\pascal.y"
    {
					(yyval) = (yyvsp[(1) - (1)]);
			   ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 679 ".\\pascal.y"
    {
			   	 printError("illegal statement");
			   ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 684 ".\\pascal.y"
    {
					(yyval) = newTreeNode(N_ASSIGN_STMT);
					appendChild((yyval), (yyvsp[(1) - (3)]));
					TreeNode* exp = newTreeNode(N_EXPRESSION);
					appendChild(exp, (yyvsp[(3) - (3)]));
					appendChild((yyval), exp);
			/*          	N_ASSIGN_STMT
			 *			/			  \
			 *		N_ID         N_EXPRESSION
			 */
			;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 695 ".\\pascal.y"
    {
					(yyval) = newTreeNode(N_ASSIGN_STMT);
					appendChild((yyval), (yyvsp[(1) - (6)]));
					TreeNode* exp1 = newTreeNode(N_EXPRESSION);
					appendChild(exp1, (yyvsp[(3) - (6)]));
					TreeNode* exp2 = newTreeNode(N_EXPRESSION);
					appendChild(exp2, (yyvsp[(6) - (6)]));
					appendChild((yyval), exp1);
					appendChild((yyval), exp2);
			/*          	N_ASSIGN_STMT
			 *			/		|			  \
			 *		N_ID   N_EXPRESSION       N_EXPRESSION
			 */
			;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 709 ".\\pascal.y"
    {
					(yyval) = newTreeNode(N_ASSIGN_STMT);
					appendChild((yyval), (yyvsp[(1) - (5)]));
					appendChild((yyval), (yyvsp[(3) - (5)]));
					TreeNode* exp = newTreeNode(N_EXPRESSION);
					appendChild(exp, (yyvsp[(5) - (5)]));
					appendChild((yyval), exp);
			/*          	N_ASSIGN_STMT
			 *			/		|			  \
			 *		N_ID   		N_ID       N_EXPRESSION
			 */
			;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 722 ".\\pascal.y"
    {
				(yyval) = newTreeNode(N_PROC_STMT);
				appendChild((yyval), (yyvsp[(1) - (1)]));
			/*          	N_PROC_STMT
			 *					|
			 *		       		N_ID
			 */
		  ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 730 ".\\pascal.y"
    {
				(yyval) = newTreeNode(N_PROC_STMT);
				appendChild((yyval), (yyvsp[(1) - (4)]));
				appendChild((yyval), (yyvsp[(3) - (4)]));
			/*         N_PROC_STMT
			 *			/		 \
			 *		N_ID   		N_ARGS_LIST
			 */
		  ;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 739 ".\\pascal.y"
    {
				(yyval) = newTreeNode(N_PROC_STMT);
				appendChild((yyval), (yyvsp[(1) - (1)]));
			/*          	N_PROC_STMT
			 *					|
			 *		       		N_SYS_PROC
			 */
		  ;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 747 ".\\pascal.y"
    {
				(yyval) = newTreeNode(N_PROC_STMT);
				appendChild((yyval), (yyvsp[(1) - (4)]));
				appendChild((yyval), (yyvsp[(3) - (4)]));
			/*         N_PROC_STMT
			 *			/		 \
			 *		N_SYS_PROC   N_EXPRESSION_LIST
			 */
		  ;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 756 ".\\pascal.y"
    {
				(yyval) = newTreeNode(N_PROC_STMT);
				appendChild((yyval), (yyvsp[(1) - (4)]));
				appendChild((yyval), (yyvsp[(3) - (4)]));
			/*          N_PROC_STMT
			 *				|
			 *			 N_FACTOR
			 */
		  ;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 765 ".\\pascal.y"
    {
				printError("missing right paretheses");
			;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 768 ".\\pascal.y"
    {
				printError("missing right paretheses");	  
		  ;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 771 ".\\pascal.y"
    {

				printError("missing right paretheses");	
		  ;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 775 ".\\pascal.y"
    {
				printError("missing left paretheses");	  
		  ;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 780 ".\\pascal.y"
    {
				(yyval) = newTreeNode(N_IF_STMT);
				TreeNode* exp = newTreeNode(N_EXPRESSION);
				appendChild(exp, (yyvsp[(2) - (5)]));
				appendChild((yyval), exp);
				appendChild((yyval), (yyvsp[(4) - (5)]));
				appendChild((yyval), (yyvsp[(5) - (5)]));

			/*          	N_IF_STMT
			 *		/			|		 \
			 *	  N_EXPRESSION  N_STMT  N_STMT
			 */
		;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 795 ".\\pascal.y"
    {
				(yyval) = (yyvsp[(2) - (2)]);
			;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 798 ".\\pascal.y"
    {
				(yyval) = newTreeNode(N_STMT); //an stmt with empty child
			;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 803 ".\\pascal.y"
    {
				(yyval) = newTreeNode(N_REPEAT_STMT);
				appendChild((yyval), (yyvsp[(2) - (4)]));
				TreeNode* exp = newTreeNode(N_EXPRESSION);
				appendChild(exp, (yyvsp[(4) - (4)]));
				appendChild((yyval), exp);
			/*          	N_REPEAT_STMT
			 *		/					 \
			 *	  N_STMT_LIST    		N_EXPRESSION
			 */
			;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 816 ".\\pascal.y"
    {
				(yyval) = newTreeNode(N_WHILE_STMT);
				TreeNode* exp = newTreeNode(N_EXPRESSION);
				appendChild(exp, (yyvsp[(2) - (4)]));
				appendChild((yyval), exp);
				appendChild((yyval), (yyvsp[(4) - (4)]));

			/*          	N_WHILE_STMT
			 *				/			 \
			 *	  N_EXPRESSION    		N_STMT
			 */
		   ;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 830 ".\\pascal.y"
    {
				(yyval) = newTreeNode(N_FOR_STMT);
				appendChild((yyval), (yyvsp[(2) - (8)]));
				TreeNode* exp1 = newTreeNode(N_EXPRESSION);
				appendChild(exp1, (yyvsp[(4) - (8)]));
				appendChild((yyval), exp1);
				appendChild((yyval), (yyvsp[(5) - (8)]));
				TreeNode* exp2 = newTreeNode(N_EXPRESSION);
				appendChild(exp2, (yyvsp[(6) - (8)]));
				appendChild((yyval), exp2);
				appendChild((yyval), (yyvsp[(8) - (8)]));
			/*          	N_FOR_STMT
			 *		/		|           |               |       	 \
			 *	  N_ID  N_EXPRESSION (N_TO|N_DOWNTO) N_EXPRESSION N_STMT
			 */
		 ;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 848 ".\\pascal.y"
    {
			(yyval) = (yyvsp[(1) - (1)]);
		  ;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 851 ".\\pascal.y"
    {
			(yyval) = (yyvsp[(1) - (1)]);
		  ;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 856 ".\\pascal.y"
    {
			(yyval) = newTreeNode(N_CASE_STMT);
			TreeNode* exp = newTreeNode(N_EXPRESSION);
			appendChild(exp, (yyvsp[(2) - (5)]));
			appendChild((yyval), exp);
			appendChild((yyval), (yyvsp[(4) - (5)]));
			/*       N_CASE_STMT
			 *		/      	 \
			 * N_EXPRESSION N_CASE_EXPR_LIST
			 */
		  ;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 867 ".\\pascal.y"
    {
					printError("missing 'end'");		  
			;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 870 ".\\pascal.y"
    {
					printError("missing 'of'");		  
			;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 875 ".\\pascal.y"
    {
					(yyval) = (yyvsp[(1) - (2)]);
					appendChild((yyval), (yyvsp[(2) - (2)]));
			/*       N_CASE_EXPR_LIST
			 *		/      	 |           |   \
			 * N_CASE_EXPR N_CASE_EXPR ... N_CASE_EXPR
			 */

			   ;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 884 ".\\pascal.y"
    {
					(yyval) = newTreeNode(N_CASE_EXPR_LIST);
					appendChild((yyval), (yyvsp[(1) - (1)]));
			   ;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 889 ".\\pascal.y"
    {
			(yyval) = newTreeNode(N_CASE_EXPR);
			appendChild((yyval), (yyvsp[(1) - (4)]));
			appendChild((yyval), (yyvsp[(3) - (4)]));
			/*      								 N_CASE_STMT
			 *										/      	     \
			 * 	  (N_INTEGER|N_REAL|N_CHAR|N_STRING|N_SYS_CON)   N_STMT
			 */
		  ;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 898 ".\\pascal.y"
    {
			(yyval) = newTreeNode(N_CASE_EXPR);
			appendChild((yyval), (yyvsp[(1) - (4)]));
			appendChild((yyval), (yyvsp[(3) - (4)]));

			/*      N_CASE_STMT
			 *		/	     \
			 * 	  N_ID   N_STMT
			 */
		  ;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 908 ".\\pascal.y"
    {
				printError("missing ';'");	
			;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 913 ".\\pascal.y"
    {
			(yyval) = newTreeNode(N_GOTO_STMT);
			appendChild((yyval), (yyvsp[(1) - (2)]));

			/*      N_GOTO_STMT
			 *		   |
			 * 	     N_INTEGER
			 */
		  ;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 924 ".\\pascal.y"
    {
					(yyval) = (yyvsp[(1) - (3)]);

					TreeNode* exp = newTreeNode(N_EXPRESSION);
					appendChild(exp, (yyvsp[(3) - (3)]));
					appendChild((yyval), exp);
			    ;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 931 ".\\pascal.y"
    {
					(yyval) = newTreeNode(N_EXPRESSION_LIST);
					TreeNode* exp = newTreeNode(N_EXPRESSION);
					appendChild(exp, (yyvsp[(1) - (1)]));
					appendChild((yyval), exp);
			/*       N_EXPRESSION_LIST
			 *		/      	 |           |   \
			 * N_EXPRESSION N_EXPRESSION ... N_EXPRESSION
			 */
				;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 943 ".\\pascal.y"
    {
					(yyval) = newTreeNode(N_EXP_GE);
					appendChild((yyval), (yyvsp[(1) - (3)]));
					appendChild((yyval), (yyvsp[(3) - (3)]));
		   ;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 948 ".\\pascal.y"
    {
					(yyval) = newTreeNode(N_EXP_GT);
					appendChild((yyval), (yyvsp[(1) - (3)]));
					appendChild((yyval), (yyvsp[(3) - (3)]));
		   ;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 953 ".\\pascal.y"
    {
					(yyval) = newTreeNode(N_EXP_LE);
					appendChild((yyval), (yyvsp[(1) - (3)]));
					appendChild((yyval), (yyvsp[(3) - (3)]));
		   ;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 958 ".\\pascal.y"
    {
					(yyval) = newTreeNode(N_EXP_LT);
					appendChild((yyval), (yyvsp[(1) - (3)]));
					appendChild((yyval), (yyvsp[(3) - (3)]));
		   ;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 963 ".\\pascal.y"
    {
					(yyval) = newTreeNode(N_EXP_EQUAL);
					appendChild((yyval), (yyvsp[(1) - (3)]));
					appendChild((yyval), (yyvsp[(3) - (3)]));
		   ;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 968 ".\\pascal.y"
    {
					(yyval) = newTreeNode(N_EXP_UNEQUAL);
					appendChild((yyval), (yyvsp[(1) - (3)]));
					appendChild((yyval), (yyvsp[(3) - (3)]));
		   ;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 973 ".\\pascal.y"
    {
					(yyval) = (yyvsp[(1) - (1)]);
		   ;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 978 ".\\pascal.y"
    {
					(yyval) = newTreeNode(N_EXP_PLUS);
					appendChild((yyval), (yyvsp[(1) - (3)]));
					appendChild((yyval), (yyvsp[(3) - (3)]));
     ;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 983 ".\\pascal.y"
    {
					(yyval) = newTreeNode(N_EXP_MINUS);
					appendChild((yyval), (yyvsp[(1) - (3)]));
					appendChild((yyval), (yyvsp[(3) - (3)]));
	 ;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 988 ".\\pascal.y"
    {
					(yyval) = newTreeNode(N_EXP_OR);
					appendChild((yyval), (yyvsp[(1) - (3)]));
					appendChild((yyval), (yyvsp[(3) - (3)]));
	 ;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 993 ".\\pascal.y"
    {
					(yyval) = (yyvsp[(1) - (1)]);
	 ;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 998 ".\\pascal.y"
    {
					(yyval) = newTreeNode(N_EXP_MUL);
					appendChild((yyval), (yyvsp[(1) - (3)]));
					appendChild((yyval), (yyvsp[(3) - (3)]));
	 ;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 1003 ".\\pascal.y"
    {
					(yyval) = newTreeNode(N_EXP_DIV);
					appendChild((yyval), (yyvsp[(1) - (3)]));
					appendChild((yyval), (yyvsp[(3) - (3)]));
	 ;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 1008 ".\\pascal.y"
    {
					(yyval) = newTreeNode(N_EXP_MOD);
					appendChild((yyval), (yyvsp[(1) - (3)]));
					appendChild((yyval), (yyvsp[(3) - (3)]));
	 ;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 1013 ".\\pascal.y"
    {
					(yyval) = newTreeNode(N_EXP_AND);
					appendChild((yyval), (yyvsp[(1) - (3)]));
					appendChild((yyval), (yyvsp[(3) - (3)]));
	 ;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 1018 ".\\pascal.y"
    {
					(yyval) = (yyvsp[(1) - (1)]);
	 ;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 1023 ".\\pascal.y"
    {
					(yyval) = (yyvsp[(1) - (1)]);
	   ;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 1026 ".\\pascal.y"
    {
					(yyval) = newTreeNode(N_FACTOR);
					appendChild((yyval), (yyvsp[(1) - (4)]));
					appendChild((yyval), (yyvsp[(3) - (4)]));
			/*      N_FACTOR
			 *		/		\
			 * 	   N_ID      N_ARGS_LIST
			 */
	   ;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 1035 ".\\pascal.y"
    {
					(yyval) = newTreeNode(N_FACTOR);
					appendChild((yyval), (yyvsp[(1) - (1)]));
			/*      N_FACTOR
			 *			|
			 * 	   N_SYS_FUNCT
			 */
       ;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 1043 ".\\pascal.y"
    {
					(yyval) = newTreeNode(N_FACTOR);
					appendChild((yyval), (yyvsp[(1) - (4)]));
					appendChild((yyval), (yyvsp[(3) - (4)]));
			/*      		N_FACTOR
			 *			/			\
			 * 	   N_SYS_FUNCT   	N_ARGS_LIST
			 */
	   ;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 1052 ".\\pascal.y"
    {
					(yyval) = (yyvsp[(1) - (1)]);
	   ;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 1055 ".\\pascal.y"
    {
					(yyval) = (yyvsp[(2) - (3)]);
	   ;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 1058 ".\\pascal.y"
    {
					(yyval) = newTreeNode(N_FACTOR);
					appendChild((yyval), (yyvsp[(1) - (2)]));
					appendChild((yyval), (yyvsp[(2) - (2)]));
			/*      N_FACTOR
			 *		/		\
			 * N_NOT		N_FACTOR
			 */
	   ;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 1067 ".\\pascal.y"
    {
					(yyval) = newTreeNode(N_FACTOR);
					appendChild((yyval), (yyvsp[(1) - (2)]));
					appendChild((yyval), (yyvsp[(2) - (2)]));
			/*      N_FACTOR
			 *		/		\
			 * N_MINUS		N_FACTOR
			 */
	   ;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 1076 ".\\pascal.y"
    {
					(yyval) = newTreeNode(N_FACTOR);
					appendChild((yyval), (yyvsp[(1) - (4)]));
					TreeNode* exp = newTreeNode(N_EXPRESSION);
					appendChild(exp, (yyvsp[(3) - (4)]));
					appendChild((yyval), exp);

			/*      N_FACTOR
			 *		/		\
			 * N_ID			N_EXPRESSION
			 */
	   ;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 1088 ".\\pascal.y"
    {
					(yyval) = newTreeNode(N_FACTOR);
					appendChild((yyval), (yyvsp[(1) - (3)]));
					appendChild((yyval), (yyvsp[(3) - (3)]));
			/*      N_FACTOR
			 *		/		\
			 * N_ID			N_ID
			 */
	   ;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 1099 ".\\pascal.y"
    {
					(yyval) = (yyvsp[(1) - (3)]);
					TreeNode* exp = newTreeNode(N_EXPRESSION);
					appendChild(exp, (yyvsp[(3) - (3)]));
					appendChild((yyval), exp);
		  ;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 1105 ".\\pascal.y"
    {
					(yyval) = newTreeNode(N_ARGS_LIST);
					TreeNode* exp = newTreeNode(N_EXPRESSION);
					appendChild(exp, (yyvsp[(1) - (1)]));
					appendChild((yyval), exp);
		  ;}
    break;



/* Line 1455 of yacc.c  */
#line 3694 "pascal.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 1113 ".\\pascal.y"

int yyerror(char *a){
	hasError = 1;
	return 0;
}


int printError(char *a){
	fprintf(stderr, "line %d: %s\n", lineno, a);
}


