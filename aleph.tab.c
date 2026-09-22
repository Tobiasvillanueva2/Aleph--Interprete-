
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
#line 1 "aleph.y"

#include <stdio.h>
#include "aleph.h"
void yyerror(char *s);
extern int yylex();
tset salida;


/* Line 189 of yacc.c  */
#line 82 "aleph.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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
     IDVARIABLE = 258,
     IDCADENA = 259,
     ASIGNACION = 260,
     COMA = 261,
     LLAVE_I = 262,
     LLAVE_D = 263,
     CORCH_I = 264,
     CORCH_D = 265,
     INTE = 266,
     UN = 267,
     DIFC = 268,
     POPA = 269,
     PUSHA = 270,
     FUNC = 271,
     FUNCVOID = 272,
     RETORNA = 273,
     IF = 274,
     ELSE = 275,
     WHILE = 276,
     PERTENECE = 277,
     IGUAL = 278,
     SUMA = 279,
     RESTA = 280,
     MULT = 281,
     DIV = 282,
     MAYOR = 283,
     MENOR = 284,
     IGUALIGUAL = 285,
     DISTINTO = 286,
     AUTOMATA = 287,
     ANALIZA = 288,
     DETERMINIZAR = 289,
     ESAFD = 290,
     PAREN_I = 291,
     PAREN_D = 292,
     EOL = 293
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 8 "aleph.y"

    struct symbol* v;
    struct ast *a;
    char* e;
    struct symlist *sl;



/* Line 214 of yacc.c  */
#line 165 "aleph.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 177 "aleph.tab.c"

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
#define YYFINAL  53
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   499

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNRULES -- Number of states.  */
#define YYNSTATES  143

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

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
      35,    36,    37,    38
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     7,    10,    13,    15,    18,    20,    22,
      24,    26,    29,    31,    33,    35,    37,    39,    41,    45,
      50,    57,    62,    67,    69,    73,    75,    79,    81,    83,
      85,    87,    91,    95,    99,   103,   107,   111,   115,   119,
     123,   127,   131,   135,   139,   142,   146,   150,   153,   157,
     160,   164,   166,   170,   174,   177,   180,   182,   184,   186,
     192,   200,   206,   213,   219,   226,   232,   234,   238,   243,
     247,   251
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      40,     0,    -1,    40,    41,    38,    -1,    41,    38,    -1,
      40,    59,    -1,    59,    -1,    40,    56,    -1,    56,    -1,
      43,    -1,    44,    -1,    42,    -1,    18,    43,    -1,    18,
      -1,     4,    -1,    51,    -1,    52,    -1,    46,    -1,    61,
      -1,    36,    43,    37,    -1,    32,    36,    62,    37,    -1,
      33,    36,    43,     6,    43,    37,    -1,    34,    36,    43,
      37,    -1,    35,    36,    43,    37,    -1,     3,    -1,    45,
       5,    53,    -1,     3,    -1,     3,     6,    45,    -1,    49,
      -1,    50,    -1,    47,    -1,    48,    -1,    43,    24,    43,
      -1,    43,    25,    43,    -1,    43,    26,    43,    -1,    43,
      27,    43,    -1,    43,    28,    43,    -1,    43,    29,    43,
      -1,    43,    30,    43,    -1,    43,    31,    43,    -1,    43,
      12,    43,    -1,    43,    11,    43,    -1,    43,    13,    43,
      -1,    43,    22,    43,    -1,    43,    23,    43,    -1,    14,
      43,    -1,    43,    15,    43,    -1,     7,    53,     8,    -1,
       7,     8,    -1,     9,    53,    10,    -1,     9,    10,    -1,
      43,     6,    53,    -1,    43,    -1,     7,    55,     8,    -1,
      41,    38,    55,    -1,    41,    38,    -1,    56,    55,    -1,
      56,    -1,    57,    -1,    58,    -1,    19,    36,    43,    37,
      54,    -1,    19,    36,    43,    37,    54,    20,    54,    -1,
      21,    36,    43,    37,    54,    -1,    16,     3,    36,    60,
      37,    54,    -1,    16,     3,    36,    37,    54,    -1,    17,
       3,    36,    60,    37,    54,    -1,    17,     3,    36,    37,
      54,    -1,     3,    -1,     3,     6,    60,    -1,     3,    36,
      62,    37,    -1,     3,    36,    37,    -1,    43,     6,    62,
      -1,    43,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    41,    41,    42,    43,    44,    45,    46,    49,    50,
      51,    54,    55,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    73,    77,    78,    80,    81,    82,
      83,    86,    87,    88,    89,    92,    93,    94,    95,    98,
      99,   100,   101,   102,   105,   106,   109,   110,   113,   114,
     117,   118,   123,   126,   127,   128,   129,   132,   133,   136,
     137,   140,   145,   146,   147,   148,   151,   152,   155,   156,
     159,   160
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDVARIABLE", "IDCADENA", "ASIGNACION",
  "COMA", "LLAVE_I", "LLAVE_D", "CORCH_I", "CORCH_D", "INTE", "UN", "DIFC",
  "POPA", "PUSHA", "FUNC", "FUNCVOID", "RETORNA", "IF", "ELSE", "WHILE",
  "PERTENECE", "IGUAL", "SUMA", "RESTA", "MULT", "DIV", "MAYOR", "MENOR",
  "IGUALIGUAL", "DISTINTO", "AUTOMATA", "ANALIZA", "DETERMINIZAR", "ESAFD",
  "PAREN_I", "PAREN_D", "EOL", "$accept", "aleph", "sentencia",
  "retorna_sent", "expr", "asignacion", "list_asig", "operaciones",
  "op_num", "op_rel", "op_conj", "op_list", "lit_conj", "lit_list",
  "list_expr", "bloque", "lista_sent", "ctrl_stmt", "if_sent",
  "while_sent", "func_def", "param_list", "llamada", "arg_list", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    40,    40,    40,    40,    40,    41,    41,
      41,    42,    42,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    44,    45,    45,    46,    46,    46,
      46,    47,    47,    47,    47,    48,    48,    48,    48,    49,
      49,    49,    49,    49,    50,    50,    51,    51,    52,    52,
      53,    53,    54,    55,    55,    55,    55,    56,    56,    57,
      57,    58,    59,    59,    59,    59,    60,    60,    61,    61,
      62,    62
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     2,     1,     2,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     3,     4,
       6,     4,     4,     1,     3,     1,     3,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     2,     3,     2,
       3,     1,     3,     3,     2,     2,     1,     1,     1,     5,
       7,     5,     6,     5,     6,     5,     1,     3,     4,     3,
       3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    23,    13,     0,     0,     0,     0,     0,    12,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,     8,
       9,     0,    16,    29,    30,    27,    28,    14,    15,     7,
      57,    58,     5,    17,     0,     0,    23,    47,    51,     0,
      49,     0,    44,     0,     0,    11,     0,     0,     0,     0,
       0,     0,     0,     1,     0,     6,     4,     3,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    25,    26,    69,    71,     0,     0,    46,
      48,     0,     0,     0,     0,     0,     0,     0,     0,    18,
       2,    40,    39,    41,    45,    42,    43,    31,    32,    33,
      34,    35,    36,    37,    38,    24,     0,    68,    50,    66,
       0,     0,     0,     0,     0,     0,    19,     0,    21,    22,
      70,     0,     0,    63,     0,    65,     0,    59,    61,     0,
      67,     0,     0,    56,    62,    64,     0,    20,    54,    52,
      55,    60,    53
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    16,   131,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    39,   123,   132,   133,    30,    31,
      32,   111,    33,    77
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -110
static const yytype_int16 yypact[] =
{
      83,    47,  -110,   125,   159,   167,     3,     6,   167,   -10,
      -9,    -8,    -6,    -2,     5,   167,     4,    -5,  -110,   413,
    -110,    37,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,    51,    75,    34,  -110,   325,    65,
    -110,    64,  -110,    40,    44,   413,   167,   167,   167,   167,
     167,   167,   193,  -110,    43,  -110,  -110,  -110,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,    82,  -110,  -110,   351,    48,   167,  -110,
    -110,    13,    14,   214,   235,    54,   377,   256,   277,  -110,
    -110,   451,   434,   434,  -110,   468,   468,    79,    79,    78,
      78,   160,   160,   160,   160,  -110,   167,  -110,  -110,    89,
      91,    59,    91,    76,    91,    91,  -110,   167,  -110,  -110,
    -110,   119,   117,  -110,    91,  -110,    91,   103,  -110,   298,
    -110,    87,   122,   117,  -110,  -110,    91,  -110,   117,  -110,
    -110,  -110,  -110
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -110,  -110,    15,  -110,    -3,  -110,    93,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,    -1,   297,  -109,    19,  -110,  -110,
     121,   -72,  -110,   -34
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -26
static const yytype_int16 yytable[] =
{
      38,    38,    42,    41,    53,    45,    43,     1,     2,    44,
     113,     3,    52,     4,    85,    17,   109,   109,     5,    29,
       6,     7,     8,     9,   140,    10,    46,    47,    48,   142,
      49,    54,    76,    57,    50,    55,    11,    12,    13,    14,
      15,    51,    72,    83,    84,    76,    86,    87,    88,   130,
     110,   112,   -25,    34,    73,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,    38,
      35,   105,   120,    79,    80,    38,    81,   108,    36,     2,
      82,    90,     3,    35,     4,   107,     1,     2,    34,     5,
       3,   116,     4,    61,    61,   121,   124,     5,   122,     6,
       7,     8,     9,    76,    10,    66,    67,    11,    12,    13,
      14,    15,    75,   126,   129,    11,    12,    13,    14,    15,
       1,     2,   109,   136,     3,   138,     4,    74,    36,     2,
     139,     5,     3,    37,     4,     8,     9,    56,    10,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
      12,    13,    14,    15,     0,     0,     0,    11,    12,    13,
      14,    15,    36,     2,     0,     0,     3,     0,     4,    40,
      36,     2,     0,     5,     3,    61,     4,     0,     0,     0,
       0,     5,     0,     0,    64,    65,    66,    67,     0,     0,
       0,    11,    12,    13,    14,    15,     0,     0,     0,    11,
      12,    13,    14,    15,    58,    59,    60,     0,    61,     0,
       0,     0,     0,     0,     0,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    58,    59,    60,     0,    61,
      89,     0,     0,     0,     0,     0,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    58,    59,    60,     0,
      61,   114,     0,     0,     0,     0,     0,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    58,    59,    60,
       0,    61,   115,     0,     0,     0,     0,     0,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    58,    59,
      60,     0,    61,   118,     0,     0,     0,     0,     0,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    58,
      59,    60,     0,    61,   119,     0,     0,     0,     0,     0,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    78,     0,     0,     0,   137,    58,    59,    60,     0,
      61,     0,     0,     0,     0,     0,     0,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,   106,     0,     0,
       0,     0,    58,    59,    60,     0,    61,     0,     0,     0,
       0,     0,     0,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,   117,     0,     0,     0,     0,    58,    59,
      60,     0,    61,     0,     0,     0,     0,     0,     0,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,   125,
       0,   127,   128,     0,     0,     0,     0,     0,     0,     0,
       0,   134,     0,   135,    58,    59,    60,     0,    61,     0,
       0,     0,     0,   141,     0,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    58,     0,     0,     0,    61,
       0,     0,     0,     0,     0,     0,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    61,     0,     0,     0,
       0,     0,     0,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    61,     0,     0,     0,     0,     0,     0,
       0,     0,    64,    65,    66,    67,    68,    69,    70,    71
};

static const yytype_int16 yycheck[] =
{
       3,     4,     5,     4,     0,     8,     3,     3,     4,     3,
      82,     7,    15,     9,    48,     0,     3,     3,    14,     0,
      16,    17,    18,    19,   133,    21,    36,    36,    36,   138,
      36,    16,    35,    38,    36,    16,    32,    33,    34,    35,
      36,    36,     5,    46,    47,    48,    49,    50,    51,   121,
      37,    37,     5,     6,     3,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      36,    72,   106,     8,    10,    78,    36,    78,     3,     4,
      36,    38,     7,    36,     9,    37,     3,     4,     6,    14,
       7,    37,     9,    15,    15,     6,    37,    14,     7,    16,
      17,    18,    19,   106,    21,    26,    27,    32,    33,    34,
      35,    36,    37,    37,   117,    32,    33,    34,    35,    36,
       3,     4,     3,    20,     7,    38,     9,    34,     3,     4,
       8,    14,     7,     8,     9,    18,    19,    16,    21,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    32,    33,    34,
      35,    36,     3,     4,    -1,    -1,     7,    -1,     9,    10,
       3,     4,    -1,    14,     7,    15,     9,    -1,    -1,    -1,
      -1,    14,    -1,    -1,    24,    25,    26,    27,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    11,    12,    13,    -1,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    11,    12,    13,    -1,    15,
      37,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    11,    12,    13,    -1,
      15,    37,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    11,    12,    13,
      -1,    15,    37,    -1,    -1,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    11,    12,
      13,    -1,    15,    37,    -1,    -1,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    11,
      12,    13,    -1,    15,    37,    -1,    -1,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      -1,     6,    -1,    -1,    -1,    37,    11,    12,    13,    -1,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,     6,    -1,    -1,
      -1,    -1,    11,    12,    13,    -1,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,     6,    -1,    -1,    -1,    -1,    11,    12,
      13,    -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,   112,
      -1,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   124,    -1,   126,    11,    12,    13,    -1,    15,    -1,
      -1,    -1,    -1,   136,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    11,    -1,    -1,    -1,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    25,    26,    27,    28,    29,    30,    31
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     7,     9,    14,    16,    17,    18,    19,
      21,    32,    33,    34,    35,    36,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    56,
      57,    58,    59,    61,     6,    36,     3,     8,    43,    53,
      10,    53,    43,     3,     3,    43,    36,    36,    36,    36,
      36,    36,    43,     0,    41,    56,    59,    38,    11,    12,
      13,    15,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,     5,     3,    45,    37,    43,    62,     6,     8,
      10,    36,    36,    43,    43,    62,    43,    43,    43,    37,
      38,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    53,     6,    37,    53,     3,
      37,    60,    37,    60,    37,    37,    37,     6,    37,    37,
      62,     6,     7,    54,    37,    54,    37,    54,    54,    43,
      60,    41,    55,    56,    54,    54,    20,    37,    38,     8,
      55,    54,    55
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
#line 41 "aleph.y"
    {salida=eval((yyvsp[(2) - (3)].a));if (salida)muestra(salida); printf("\n");;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 42 "aleph.y"
    {salida=eval((yyvsp[(1) - (2)].a));if (salida)muestra(salida);printf("\n");;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 43 "aleph.y"
    {eval((yyvsp[(2) - (2)].a));;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 44 "aleph.y"
    {eval((yyvsp[(1) - (1)].a));;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 45 "aleph.y"
    {eval((yyvsp[(2) - (2)].a));;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 46 "aleph.y"
    {eval((yyvsp[(1) - (1)].a));;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 54 "aleph.y"
    {(yyval.a)=newast(RETURN,(yyvsp[(2) - (2)].a),NULL);;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 55 "aleph.y"
    {(yyval.a)=newast(RETURN,NULL,NULL);;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 58 "aleph.y"
    {(yyval.a)=newelem((yyvsp[(1) - (1)].e));;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 63 "aleph.y"
    {(yyval.a)=(yyvsp[(2) - (3)].a);;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 64 "aleph.y"
    {(yyval.a)=newast(CONSTRUYE_AF,(yyvsp[(3) - (4)].a),NULL);;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 65 "aleph.y"
    {(yyval.a)=newast(ANALIZA_AF,(yyvsp[(3) - (6)].a),(yyvsp[(5) - (6)].a));;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 66 "aleph.y"
    {(yyval.a)=newast(DETERMINIZAR_AF,(yyvsp[(3) - (4)].a),NULL);;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 67 "aleph.y"
    {(yyval.a)=newast(ESAFD_AF,(yyvsp[(3) - (4)].a),NULL);;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 68 "aleph.y"
    {(yyval.a)=newref((yyvsp[(1) - (1)].v));;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 73 "aleph.y"
    {(yyval.a)=newast(M_ASIG,(yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 77 "aleph.y"
    {(yyval.a)=newast(L_IDVAR,newref((yyvsp[(1) - (1)].v)),NULL);;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 78 "aleph.y"
    {(yyval.a)=newast(L_IDVAR,newref((yyvsp[(1) - (3)].v)),(yyvsp[(3) - (3)].a));;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 86 "aleph.y"
    {(yyval.a)=newast(OP_SUMA,(yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 87 "aleph.y"
    {(yyval.a)=newast(OP_RESTA,(yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 88 "aleph.y"
    {(yyval.a)=newast(OP_MULT,(yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 89 "aleph.y"
    {(yyval.a)=newast(OP_DIV,(yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 92 "aleph.y"
    {(yyval.a)=newast(CMP_MAYOR,(yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 93 "aleph.y"
    {(yyval.a)=newast(CMP_MENOR,(yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 94 "aleph.y"
    {(yyval.a)=newast(CMP_IGUALIGUAL,(yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 95 "aleph.y"
    {(yyval.a)=newast(CMP_DISTINTO,(yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 98 "aleph.y"
    {(yyval.a)=newast(OP_UN,(yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 99 "aleph.y"
    {(yyval.a)=newast(OP_INTE,(yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 100 "aleph.y"
    {(yyval.a)=newast(OP_DIFC,(yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 101 "aleph.y"
    {(yyval.a)=newast(CMP_PERTENECE,(yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 102 "aleph.y"
    {(yyval.a)=newast(CMP_IGUAL,(yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 105 "aleph.y"
    {(yyval.a)=newast(OP_POP,(yyvsp[(2) - (2)].a),NULL);;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 106 "aleph.y"
    {(yyval.a)=newast(OP_PUSH,(yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 109 "aleph.y"
    {(yyval.a)=newast(SET,(yyvsp[(2) - (3)].a),NULL);;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 110 "aleph.y"
    {(yyval.a)=newast(NULOCONJ,NULL,NULL);;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 113 "aleph.y"
    {(yyval.a)=newast(LIST,(yyvsp[(2) - (3)].a),NULL);;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 114 "aleph.y"
    {(yyval.a)=newast(NULOLIST,NULL,NULL);;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 117 "aleph.y"
    {(yyval.a)=newast(LIST_E,(yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 118 "aleph.y"
    {(yyval.a)=newast(LIST_E,(yyvsp[(1) - (1)].a),NULL);;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 123 "aleph.y"
    {(yyval.a)=(yyvsp[(2) - (3)].a);;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 126 "aleph.y"
    {(yyval.a)=newast(LIST_STMT,(yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 127 "aleph.y"
    {(yyval.a)=newast(LIST_STMT,(yyvsp[(1) - (2)].a),NULL);;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 128 "aleph.y"
    {(yyval.a)=newast(LIST_STMT,(yyvsp[(1) - (2)].a),(yyvsp[(2) - (2)].a));;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 129 "aleph.y"
    {(yyval.a)=newast(LIST_STMT,(yyvsp[(1) - (1)].a),NULL);;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 136 "aleph.y"
    {(yyval.a)=newif((yyvsp[(3) - (5)].a),(yyvsp[(5) - (5)].a),NULL);;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 137 "aleph.y"
    {(yyval.a)=newif((yyvsp[(3) - (7)].a),(yyvsp[(5) - (7)].a),(yyvsp[(7) - (7)].a));;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 140 "aleph.y"
    {(yyval.a)=newast(OP_WHILE,(yyvsp[(3) - (5)].a),(yyvsp[(5) - (5)].a));;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 145 "aleph.y"
    {(yyval.a)=newfunc((yyvsp[(2) - (6)].v),(yyvsp[(4) - (6)].sl),(yyvsp[(6) - (6)].a),0);;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 146 "aleph.y"
    {(yyval.a)=newfunc((yyvsp[(2) - (5)].v),NULL,(yyvsp[(5) - (5)].a),0);;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 147 "aleph.y"
    {(yyval.a)=newfunc((yyvsp[(2) - (6)].v),(yyvsp[(4) - (6)].sl),(yyvsp[(6) - (6)].a),1);;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 148 "aleph.y"
    {(yyval.a)=newfunc((yyvsp[(2) - (5)].v),NULL,(yyvsp[(5) - (5)].a),1);;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 151 "aleph.y"
    {(yyval.sl)=newsymlist((yyvsp[(1) - (1)].v),NULL);;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 152 "aleph.y"
    {(yyval.sl)=newsymlist((yyvsp[(1) - (3)].v),(yyvsp[(3) - (3)].sl));;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 155 "aleph.y"
    {(yyval.a)=newcall((yyvsp[(1) - (4)].v),(yyvsp[(3) - (4)].a));;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 156 "aleph.y"
    {(yyval.a)=newcall((yyvsp[(1) - (3)].v),NULL);;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 159 "aleph.y"
    {(yyval.a)=newast(LIST_E,(yyvsp[(1) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 160 "aleph.y"
    {(yyval.a)=newast(LIST_E,(yyvsp[(1) - (1)].a),NULL);;}
    break;



/* Line 1455 of yacc.c  */
#line 1965 "aleph.tab.c"
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
#line 164 "aleph.y"

int main(int argc, char **argv)
{
    yyparse();
}
void yyerror(char *s)
{
    fprintf(stderr, "error: %s\n", s);
}

