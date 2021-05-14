/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_FUNCTION = 258,
     T_SUBROUTINE = 259,
     T_END = 260,
     T_INTEGER = 261,
     T_REAL = 262,
     T_LOGICAL = 263,
     T_STRING = 264,
     T_CHARACTER = 265,
     T_RECORD = 266,
     T_ENDREC = 267,
     T_DATA = 268,
     T_CONTINUE = 269,
     T_GOTO = 270,
     T_CALL = 271,
     T_READ = 272,
     T_WRITE = 273,
     T_IF = 274,
     T_THEN = 275,
     T_ELSE = 276,
     T_ENDIF = 277,
     T_DO = 278,
     T_ENDO = 279,
     T_STOP = 280,
     T_RETURN = 281,
     T_ICONST = 282,
     T_RCONST = 283,
     T_LCONST = 284,
     T_CCONST = 285,
     T_SCONST = 286,
     T_OROP = 287,
     T_ANDOP = 288,
     T_NOTOP = 289,
     T_RELOP = 290,
     T_ADDOP = 291,
     T_MULOP = 292,
     T_DIVOP = 293,
     T_POWEROP = 294,
     T_LPAREN = 295,
     T_RPAREN = 296,
     T_COMMA = 297,
     T_ASSIGN = 298,
     T_COLON = 299,
     T_COMMENT = 300,
     T_ID = 301
   };
#endif
/* Tokens.  */
#define T_FUNCTION 258
#define T_SUBROUTINE 259
#define T_END 260
#define T_INTEGER 261
#define T_REAL 262
#define T_LOGICAL 263
#define T_STRING 264
#define T_CHARACTER 265
#define T_RECORD 266
#define T_ENDREC 267
#define T_DATA 268
#define T_CONTINUE 269
#define T_GOTO 270
#define T_CALL 271
#define T_READ 272
#define T_WRITE 273
#define T_IF 274
#define T_THEN 275
#define T_ELSE 276
#define T_ENDIF 277
#define T_DO 278
#define T_ENDO 279
#define T_STOP 280
#define T_RETURN 281
#define T_ICONST 282
#define T_RCONST 283
#define T_LCONST 284
#define T_CCONST 285
#define T_SCONST 286
#define T_OROP 287
#define T_ANDOP 288
#define T_NOTOP 289
#define T_RELOP 290
#define T_ADDOP 291
#define T_MULOP 292
#define T_DIVOP 293
#define T_POWEROP 294
#define T_LPAREN 295
#define T_RPAREN 296
#define T_COMMA 297
#define T_ASSIGN 298
#define T_COLON 299
#define T_COMMENT 300
#define T_ID 301




/* Copy the first part of user declarations.  */


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 2 "syntactical.y"
{
    int integerval;
    double doubleval;
    char *stringval;
}
/* Line 193 of yacc.c.  */
#line 195 "syntactical.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */
#line 8 "syntactical.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include "hash_table.h"

    extern int yylex();
    extern int yytext;
    extern FILE *yyin;
    extern void yyterminate();

    // HASHTBL *table;


    int scope = 0;
    extern int lines;
    extern int errors;

    void yyerror(const char *message);


/* Line 216 of yacc.c.  */
#line 228 "syntactical.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   349

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNRULES -- Number of states.  */
#define YYNSTATES  211

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

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
      45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    10,    14,    20,    24,    25,    27,
      29,    31,    33,    37,    39,    44,    46,    50,    52,    54,
      56,    59,    61,    64,    69,    74,    77,    81,    85,    87,
      92,    96,   100,   103,   105,   107,   109,   110,   112,   114,
     116,   118,   121,   123,   126,   128,   130,   132,   134,   136,
     138,   140,   142,   144,   146,   148,   150,   154,   158,   162,
     167,   169,   173,   175,   179,   183,   187,   191,   195,   199,
     203,   206,   209,   211,   213,   217,   220,   227,   231,   233,
     243,   249,   252,   255,   258,   262,   264,   266,   274,   279,
     282,   283,   287,   289,   291,   299,   301,   303,   311,   315,
     317,   324,   327,   328,   332,   339,   345,   348,   353
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,    49,     5,    88,    -1,    50,    64,    -1,
      50,    51,    52,    -1,    50,    11,    56,    12,    52,    -1,
      50,    13,    58,    -1,    -1,     6,    -1,     7,    -1,     8,
      -1,    10,    -1,    52,    42,    53,    -1,    53,    -1,    46,
      40,    54,    41,    -1,    46,    -1,    54,    42,    55,    -1,
      55,    -1,    27,    -1,    46,    -1,    56,    57,    -1,    57,
      -1,    51,    52,    -1,    11,    56,    12,    52,    -1,    58,
      42,    46,    59,    -1,    46,    59,    -1,    38,    60,    38,
      -1,    60,    42,    61,    -1,    61,    -1,    62,    37,    36,
      63,    -1,    62,    37,    63,    -1,    62,    37,     9,    -1,
      36,    63,    -1,    63,    -1,     9,    -1,    27,    -1,    -1,
      27,    -1,    28,    -1,    29,    -1,    30,    -1,    64,    65,
      -1,    65,    -1,    66,    67,    -1,    67,    -1,    27,    -1,
      68,    -1,    84,    -1,    69,    -1,    73,    -1,    75,    -1,
      76,    -1,    77,    -1,    14,    -1,    26,    -1,    25,    -1,
      70,    43,    72,    -1,    70,    43,     9,    -1,    70,    44,
      46,    -1,    70,    40,    71,    41,    -1,    46,    -1,    71,
      42,    72,    -1,    72,    -1,    72,    32,    72,    -1,    72,
      33,    72,    -1,    72,    35,    72,    -1,    72,    36,    72,
      -1,    72,    37,    72,    -1,    72,    38,    72,    -1,    72,
      39,    72,    -1,    34,    72,    -1,    36,    72,    -1,    70,
      -1,    63,    -1,    40,    72,    41,    -1,    15,    66,    -1,
      15,    46,    42,    40,    74,    41,    -1,    74,    42,    66,
      -1,    66,    -1,    19,    40,    72,    41,    66,    42,    66,
      42,    66,    -1,    19,    40,    72,    41,    68,    -1,    16,
      70,    -1,    17,    78,    -1,    18,    82,    -1,    78,    42,
      79,    -1,    79,    -1,    70,    -1,    40,    78,    42,    46,
      43,    80,    41,    -1,    72,    42,    72,    81,    -1,    42,
      72,    -1,    -1,    82,    42,    83,    -1,    83,    -1,    72,
      -1,    40,    82,    42,    46,    43,    80,    41,    -1,    85,
      -1,    87,    -1,    19,    40,    72,    41,    20,    49,    86,
      -1,    21,    49,    22,    -1,    22,    -1,    23,    46,    43,
      80,    49,    24,    -1,    88,    89,    -1,    -1,    90,    49,
       5,    -1,    51,     3,    46,    40,    91,    41,    -1,     4,
      46,    40,    91,    41,    -1,     4,    46,    -1,    51,    52,
      42,    91,    -1,    51,    52,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   144,   144,   146,   148,   149,   150,   151,   153,   154,
     155,   156,   158,   159,   161,   162,   164,   165,   167,   168,
     170,   171,   173,   174,   176,   177,   179,   181,   182,   184,
     185,   186,   187,   188,   189,   191,   192,   194,   195,   196,
     197,   199,   200,   202,   203,   205,   207,   208,   210,   211,
     212,   213,   214,   215,   216,   217,   219,   220,   222,   223,
     224,   226,   227,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   242,   243,   245,   246,   248,
     249,   251,   253,   254,   256,   257,   259,   260,   262,   264,
     265,   267,   268,   270,   271,   273,   274,   276,   278,   279,
     281,   283,   284,   286,   288,   289,   290,   292,   293
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_FUNCTION", "T_SUBROUTINE", "T_END",
  "T_INTEGER", "T_REAL", "T_LOGICAL", "T_STRING", "T_CHARACTER",
  "T_RECORD", "T_ENDREC", "T_DATA", "T_CONTINUE", "T_GOTO", "T_CALL",
  "T_READ", "T_WRITE", "T_IF", "T_THEN", "T_ELSE", "T_ENDIF", "T_DO",
  "T_ENDO", "T_STOP", "T_RETURN", "T_ICONST", "T_RCONST", "T_LCONST",
  "T_CCONST", "T_SCONST", "T_OROP", "T_ANDOP", "T_NOTOP", "T_RELOP",
  "T_ADDOP", "T_MULOP", "T_DIVOP", "T_POWEROP", "T_LPAREN", "T_RPAREN",
  "T_COMMA", "T_ASSIGN", "T_COLON", "T_COMMENT", "T_ID", "$accept",
  "program", "body", "declarations", "type", "vars", "undef_variable",
  "dims", "dim", "fields", "field", "vals", "value_list", "values",
  "value", "repeat", "constant", "statements", "labeled_statement",
  "label", "statement", "simple_statement", "assignment", "variable",
  "expressions", "expression", "goto_statement", "labels", "if_statement",
  "subroutine_call", "io_statement", "read_list", "read_item",
  "iter_space", "step", "write_list", "write_item", "compound_statement",
  "branch_statement", "tail", "loop_statement", "subprograms",
  "subprogram", "header", "formal_parameters", 0
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
     295,   296,   297,   298,   299,   300,   301
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    50,    50,    50,    50,    51,    51,
      51,    51,    52,    52,    53,    53,    54,    54,    55,    55,
      56,    56,    57,    57,    58,    58,    59,    60,    60,    61,
      61,    61,    61,    61,    61,    62,    62,    63,    63,    63,
      63,    64,    64,    65,    65,    66,    67,    67,    68,    68,
      68,    68,    68,    68,    68,    68,    69,    69,    70,    70,
      70,    71,    71,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    73,    73,    74,    74,    75,
      75,    76,    77,    77,    78,    78,    79,    79,    80,    81,
      81,    82,    82,    83,    83,    84,    84,    85,    86,    86,
      87,    88,    88,    89,    90,    90,    90,    91,    91
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     3,     5,     3,     0,     1,     1,
       1,     1,     3,     1,     4,     1,     3,     1,     1,     1,
       2,     1,     2,     4,     4,     2,     3,     3,     1,     4,
       3,     3,     2,     1,     1,     1,     0,     1,     1,     1,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     4,
       1,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     1,     1,     3,     2,     6,     3,     1,     9,
       5,     2,     2,     2,     3,     1,     1,     7,     4,     2,
       0,     3,     1,     1,     7,     1,     1,     7,     3,     1,
       6,     2,     0,     3,     6,     5,     2,     4,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       7,     0,     0,     0,     1,   102,     8,     9,    10,    11,
       0,     0,    53,     0,     0,     0,     0,     0,     0,    55,
      54,    45,    60,     0,     3,    42,     0,    44,    46,    48,
       0,    49,    50,    51,    52,    47,    95,    96,     2,     0,
       0,     0,    21,     0,     6,     0,    75,    81,     0,    86,
      82,    85,    37,    38,    39,    40,     0,     0,     0,    73,
      72,    93,    83,    92,     0,     0,    15,     4,    13,    41,
      43,     0,     0,     0,     0,     0,   101,     7,     0,    22,
       0,    20,    36,    25,     0,     0,     0,     0,     0,    70,
      71,    93,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    62,    57,    56,    58,
     106,     0,     0,     0,     5,    34,    37,     0,     0,    28,
       0,    33,     0,     0,     0,    84,     0,    74,     0,    63,
      64,    65,    66,    67,    68,    69,    91,     0,     0,     7,
      18,    19,     0,    17,    12,    59,     0,     0,     0,   103,
      23,    32,    26,    36,     0,    24,    78,     0,    60,    60,
       0,     7,     0,    80,     0,     0,    14,     0,    61,     0,
       0,     0,    27,    31,     0,    30,    76,     0,     0,     0,
       0,     0,     0,    90,   100,    16,   108,   105,     0,    29,
      77,     0,     0,     0,     7,    99,    97,     0,     0,    88,
       0,   104,    87,    94,     0,     0,     0,    89,   107,    98,
      79
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     3,    40,    67,    68,   142,   143,    41,
      42,    44,    83,   118,   119,   120,    59,    24,    25,    26,
      27,    28,    29,    60,   105,    61,    31,   157,    32,    33,
      34,    50,    51,   139,   199,    62,    63,    35,    36,   196,
      37,    38,    76,    77,   170
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -153
static const yytype_int16 yypact[] =
{
    -153,     9,    36,   136,  -153,  -153,  -153,  -153,  -153,  -153,
     338,     3,  -153,   -19,    12,    19,    79,    31,    15,  -153,
    -153,  -153,  -153,    52,   158,  -153,   205,  -153,  -153,  -153,
     124,  -153,  -153,  -153,  -153,  -153,  -153,  -153,   110,   338,
      52,    85,  -153,    86,    91,    93,  -153,    26,    19,    26,
     106,  -153,  -153,  -153,  -153,  -153,   228,   228,    79,  -153,
      26,   297,   118,  -153,   228,   122,   130,   138,  -153,  -153,
    -153,   228,     4,   143,   148,   199,  -153,  -153,   180,   138,
      52,  -153,    53,  -153,   157,   186,   183,    19,   228,  -153,
     102,   267,   187,   228,   228,   228,   228,   228,   228,   228,
      79,   277,   228,    -7,    52,   -24,   297,  -153,   297,  -153,
     198,   181,   231,    52,   138,  -153,   202,   185,    35,  -153,
     203,  -153,    86,   220,    29,  -153,   267,  -153,   242,   304,
      92,   196,   102,    72,   209,  -153,  -153,   191,   248,  -153,
    -153,  -153,   116,  -153,  -153,  -153,   228,    95,   210,  -153,
     138,  -153,  -153,    53,    58,  -153,  -153,   137,   206,   216,
     221,  -153,   218,  -153,   228,   239,  -153,    -7,   297,    52,
     224,    95,  -153,  -153,   185,  -153,  -153,   220,   228,   228,
     228,   175,   220,   259,  -153,  -153,   225,  -153,   234,  -153,
    -153,   236,   238,   287,  -153,  -153,  -153,   247,   228,  -153,
      18,  -153,  -153,  -153,   227,   244,   220,   297,  -153,  -153,
    -153
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -153,  -153,   -71,  -153,    -2,   -37,  -100,  -153,   126,   268,
     -31,  -153,   189,  -153,   164,  -153,   -75,  -153,   303,   -11,
     295,  -132,  -153,    -3,  -153,   -42,  -153,  -153,  -153,  -153,
    -153,   283,   -50,    21,  -153,   280,   -65,  -153,  -153,  -153,
    -153,  -153,  -153,  -153,  -152
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -36
static const yytype_int16 yytable[] =
{
      30,    23,    46,    79,   144,   163,   112,   121,    21,     4,
      81,    47,    49,   107,    89,    90,    91,   145,   146,   188,
     140,    30,   101,    30,     6,     7,     8,    45,     9,   106,
     108,    52,    53,    54,    55,   136,    75,   125,    56,   141,
      57,     5,   151,   114,    88,    49,   126,    81,   208,    43,
      22,   129,   130,   131,   132,   133,   134,   135,    22,    48,
     138,    65,   115,   136,    66,    22,    71,   173,   165,    48,
      73,    64,   163,   152,   125,   158,   150,   153,   121,   175,
     116,    53,    54,    55,    49,    52,    53,    54,    55,   117,
     181,     6,     7,     8,   174,     9,    39,    80,    66,   189,
     144,     6,     7,     8,   168,     9,    52,    53,    54,    55,
      98,    99,   156,    56,    74,    57,     6,     7,     8,    58,
       9,    49,   183,   205,    82,    22,   162,    95,    96,    97,
      98,    99,   186,    84,    30,    85,   138,   138,   193,    97,
      98,    99,     6,     7,     8,   169,     9,    10,    87,    11,
      12,    13,    14,    15,    16,    17,   207,   166,   167,    18,
     100,    19,    20,    21,    71,   102,   190,    72,    73,   169,
     103,   197,    12,    13,    14,    15,    16,    17,   176,   177,
     104,    18,    22,    19,    20,    21,     6,     7,     8,   109,
       9,    39,   113,   162,   110,   210,   194,   195,   169,   191,
     192,    30,   111,   122,    22,    12,    13,    14,    15,    16,
     160,   161,    52,    53,    54,    55,    19,    20,    21,    12,
      13,    14,    15,    16,    17,   124,   123,   148,    18,   128,
      19,    20,    96,    97,    98,    99,   149,    22,   147,   -35,
     154,    12,    13,    14,    15,    16,   160,    21,    99,   178,
     171,    22,    19,    20,    21,    52,    53,    54,    55,   179,
     182,   180,    56,   184,    57,   187,   209,   200,    88,    52,
      53,    54,    55,    22,    22,   201,    56,   202,    57,   203,
      93,    94,    58,    95,    96,    97,    98,    99,   159,   206,
     164,    93,    94,   185,    95,    96,    97,    98,    99,    93,
      94,   198,    95,    96,    97,    98,    99,    78,   127,    93,
      94,   155,    95,    96,    97,    98,    99,   172,   137,    93,
      94,    70,    95,    96,    97,    98,    99,    69,   204,    93,
      94,    86,    95,    96,    97,    98,    99,    94,    92,    95,
      96,    97,    98,    99,     6,     7,     8,     0,     9,    39
};

static const yytype_int16 yycheck[] =
{
       3,     3,    13,    40,   104,   137,    77,    82,    27,     0,
      41,    14,    15,     9,    56,    57,    58,    41,    42,   171,
      27,    24,    64,    26,     6,     7,     8,    46,    10,    71,
      72,    27,    28,    29,    30,   100,    38,    87,    34,    46,
      36,     5,   117,    80,    40,    48,    88,    78,   200,    46,
      46,    93,    94,    95,    96,    97,    98,    99,    46,    40,
     102,    46,     9,   128,    46,    46,    40,     9,   139,    40,
      44,    40,   204,    38,   124,    46,   113,    42,   153,   154,
      27,    28,    29,    30,    87,    27,    28,    29,    30,    36,
     161,     6,     7,     8,    36,    10,    11,    12,    46,   174,
     200,     6,     7,     8,   146,    10,    27,    28,    29,    30,
      38,    39,   123,    34,     4,    36,     6,     7,     8,    40,
      10,   124,   164,   194,    38,    46,   137,    35,    36,    37,
      38,    39,   169,    42,   137,    42,   178,   179,   180,    37,
      38,    39,     6,     7,     8,   147,    10,    11,    42,    13,
      14,    15,    16,    17,    18,    19,   198,    41,    42,    23,
      42,    25,    26,    27,    40,    43,   177,    43,    44,   171,
      40,   182,    14,    15,    16,    17,    18,    19,    41,    42,
      42,    23,    46,    25,    26,    27,     6,     7,     8,    46,
      10,    11,    12,   204,    46,   206,    21,    22,   200,   178,
     179,   204,     3,    46,    46,    14,    15,    16,    17,    18,
      19,    20,    27,    28,    29,    30,    25,    26,    27,    14,
      15,    16,    17,    18,    19,    42,    40,    46,    23,    42,
      25,    26,    36,    37,    38,    39,     5,    46,    40,    37,
      37,    14,    15,    16,    17,    18,    19,    27,    39,    43,
      40,    46,    25,    26,    27,    27,    28,    29,    30,    43,
      42,    40,    34,    24,    36,    41,    22,    42,    40,    27,
      28,    29,    30,    46,    46,    41,    34,    41,    36,    41,
      32,    33,    40,    35,    36,    37,    38,    39,    46,    42,
      42,    32,    33,   167,    35,    36,    37,    38,    39,    32,
      33,    42,    35,    36,    37,    38,    39,    39,    41,    32,
      33,   122,    35,    36,    37,    38,    39,   153,    41,    32,
      33,    26,    35,    36,    37,    38,    39,    24,    41,    32,
      33,    48,    35,    36,    37,    38,    39,    33,    58,    35,
      36,    37,    38,    39,     6,     7,     8,    -1,    10,    11
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    48,    49,    50,     0,     5,     6,     7,     8,    10,
      11,    13,    14,    15,    16,    17,    18,    19,    23,    25,
      26,    27,    46,    51,    64,    65,    66,    67,    68,    69,
      70,    73,    75,    76,    77,    84,    85,    87,    88,    11,
      51,    56,    57,    46,    58,    46,    66,    70,    40,    70,
      78,    79,    27,    28,    29,    30,    34,    36,    40,    63,
      70,    72,    82,    83,    40,    46,    46,    52,    53,    65,
      67,    40,    43,    44,     4,    51,    89,    90,    56,    52,
      12,    57,    38,    59,    42,    42,    78,    42,    40,    72,
      72,    72,    82,    32,    33,    35,    36,    37,    38,    39,
      42,    72,    43,    40,    42,    71,    72,     9,    72,    46,
      46,     3,    49,    12,    52,     9,    27,    36,    60,    61,
      62,    63,    46,    40,    42,    79,    72,    41,    42,    72,
      72,    72,    72,    72,    72,    72,    83,    41,    72,    80,
      27,    46,    54,    55,    53,    41,    42,    40,    46,     5,
      52,    63,    38,    42,    37,    59,    66,    74,    46,    46,
      19,    20,    66,    68,    42,    49,    41,    42,    72,    51,
      91,    40,    61,     9,    36,    63,    41,    42,    43,    43,
      40,    49,    42,    72,    24,    55,    52,    41,    91,    63,
      66,    80,    80,    72,    21,    22,    86,    66,    42,    81,
      42,    41,    41,    41,    41,    49,    42,    72,    91,    22,
      66
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
        case 7:
#line 151 "syntactical.y"
    {;}
    break;

  case 90:
#line 265 "syntactical.y"
    {;}
    break;

  case 102:
#line 284 "syntactical.y"
    {;}
    break;


/* Line 1267 of yacc.c.  */
#line 1660 "syntactical.tab.c"
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
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
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


#line 296 "syntactical.y"


int main(int argc, char *argv[]){

    int token;

    // if(!(table = hashtbl_create(10, NULL))){
    //     yyerror("failed to create hash table");
    //     exit(-1);
    // }

    if(argc > 1){
        yyin = fopen(argv[1], "r");
        if(yyin == NULL){
            yyerror("unable to find file");
            return -1;
        }
    }

    yyparse();

    // hashtbl_get(table, scope);
    fclose(yyin);
    // hashtbl_destroy(table);

    if(errors > 0){
        printf("Total errors: %d\n", errors);
        printf("Syntactical analysis failed!\n");
        return -1;
    }
    else{
        printf("Syntactical analysis successful!\n");
        return 0;
    }
}

void yyerror(const char *message){
    printf("Error in line %d: %s\n", lines, message);
    errors++;
}
