/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "parser.y" /* yacc.c:339  */


#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"
#include "astree.h"
#include "lex.yy.h"
#include "semantic.h"

extern int lineNumber;
int getLineNumber(void);
int yyerror(char*);
AST *root;


#line 82 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    KW_BYTE = 258,
    KW_INT = 259,
    KW_LONG = 260,
    KW_FLOAT = 261,
    KW_BOOL = 262,
    KW_IF = 263,
    KW_THEN = 264,
    KW_ELSE = 265,
    KW_WHILE = 266,
    KW_FOR = 267,
    KW_READ = 268,
    KW_PRINT = 269,
    KW_RETURN = 270,
    KW_BREAK = 271,
    OPERATOR_LE = 272,
    OPERATOR_GE = 273,
    OPERATOR_EQ = 274,
    OPERATOR_DIF = 275,
    TK_IDENTIFIER = 276,
    LIT_INTEGER = 277,
    LIT_FLOAT = 278,
    LIT_TRUE = 279,
    LIT_FALSE = 280,
    LIT_CHAR = 281,
    LIT_STRING = 282
  };
#endif
/* Tokens.  */
#define KW_BYTE 258
#define KW_INT 259
#define KW_LONG 260
#define KW_FLOAT 261
#define KW_BOOL 262
#define KW_IF 263
#define KW_THEN 264
#define KW_ELSE 265
#define KW_WHILE 266
#define KW_FOR 267
#define KW_READ 268
#define KW_PRINT 269
#define KW_RETURN 270
#define KW_BREAK 271
#define OPERATOR_LE 272
#define OPERATOR_GE 273
#define OPERATOR_EQ 274
#define OPERATOR_DIF 275
#define TK_IDENTIFIER 276
#define LIT_INTEGER 277
#define LIT_FLOAT 278
#define LIT_TRUE 279
#define LIT_FALSE 280
#define LIT_CHAR 281
#define LIT_STRING 282

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 18 "parser.y" /* yacc.c:355  */

    AST *ast;
    HASH_NODE *symbol;

#line 181 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 198 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   321

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  142

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   282

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    31,     2,
      39,    44,    36,    34,    45,    35,    28,    37,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    43,    41,
      33,    40,    32,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    42,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    29,     2,
       2,     2,     2,    46,     2,    47,    30,     2,     2,     2,
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
      25,    26,    27
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    86,    86,    96,    96,    99,   100,   102,   103,   106,
     107,   108,   109,   110,   112,   113,   114,   115,   116,   117,
     119,   120,   122,   123,   125,   127,   129,   130,   132,   133,
     135,   137,   139,   140,   142,   143,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   155,   159,   161,
     161,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     183,   186,   188,   188
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "KW_BYTE", "KW_INT", "KW_LONG",
  "KW_FLOAT", "KW_BOOL", "KW_IF", "KW_THEN", "KW_ELSE", "KW_WHILE",
  "KW_FOR", "KW_READ", "KW_PRINT", "KW_RETURN", "KW_BREAK", "OPERATOR_LE",
  "OPERATOR_GE", "OPERATOR_EQ", "OPERATOR_DIF", "TK_IDENTIFIER",
  "LIT_INTEGER", "LIT_FLOAT", "LIT_TRUE", "LIT_FALSE", "LIT_CHAR",
  "LIT_STRING", "'.'", "'v'", "'~'", "'&'", "'>'", "'<'", "'+'", "'-'",
  "'*'", "'/'", "'['", "'('", "'='", "';'", "']'", "':'", "')'", "','",
  "'{'", "'}'", "$accept", "begin", "programa", "decl", "vardec",
  "vartype", "literal", "veclist", "vecrest", "fundec", "par", "parlist",
  "rest", "funcall", "funpar", "funlist", "funrest", "cmd", "printlist",
  "printrest", "expression", "block", "lcmd", "cmdend", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    46,   118,
     126,    38,    62,    60,    43,    45,    42,    47,    91,    40,
      61,    59,    93,    58,    41,    44,   123,   125
};
# endif

#define YYPACT_NINF -68

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-68)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -68,    49,    65,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,    30,   -68,   -27,    31,    65,   -19,    23,    60,    37,
      40,   -68,   -68,   -68,   -68,   -68,   -68,    50,    47,   -68,
      65,   -68,    48,   -68,   -19,    52,    37,    12,   -68,   -19,
     -68,   -68,    56,    57,    72,    78,   282,   282,   -68,    10,
      71,   -68,    66,   -19,   -68,   282,   282,    94,   -68,    18,
     282,   282,   -68,   -68,   -68,   242,   265,   282,   282,    12,
     -68,   -68,   -68,   111,   132,    73,   282,   282,    42,   153,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   -68,   242,   195,   265,    71,   108,    12,
     282,   216,    75,    88,   265,   -68,   -18,   -18,   -18,   -18,
      42,    42,    42,   -18,   -18,    27,    27,   -68,   -68,   -68,
      93,   -68,    12,   -68,    69,   -68,   282,   -68,   -68,   282,
     124,   282,    75,   265,    12,    90,   -68,   -68,   282,   174,
      12,   -68
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,    11,     9,    12,    13,    10,     3,
       5,     0,     6,     0,     0,    27,     0,     0,     0,    29,
       0,    14,    15,    16,    17,    18,    19,     0,    21,    25,
       0,    26,     0,     7,     0,     0,    29,    47,    24,    23,
       8,    28,     0,     0,     0,     0,     0,     0,    44,     0,
      73,    45,     0,    23,    20,     0,     0,     0,    39,    52,
       0,     0,    53,    69,    38,    50,    46,     0,     0,    47,
      71,    70,    22,     0,     0,     0,     0,    33,    67,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    48,    50,     0,    36,    73,     0,    47,
       0,     0,    35,     0,    31,    68,    57,    56,    54,    55,
      64,    65,    66,    63,    62,    58,    59,    60,    61,    49,
       0,    72,    47,    40,     0,    51,     0,    32,    30,     0,
      42,     0,    35,    37,    47,     0,    34,    43,     0,     0,
      47,    41
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -68,   -68,   -68,   -68,   -68,   134,    13,   -68,    84,   -68,
     123,   -68,   102,   -68,    15,   -68,    22,   -67,   -68,    62,
     -46,   125,   -68,    61
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     9,    10,    18,    62,    35,    54,    12,
      19,    20,    31,    63,   102,   103,   127,    50,    64,    93,
      94,    51,    52,    70
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      65,    66,    97,    21,    22,    23,    24,    25,    26,    73,
      74,    14,    15,    16,    78,    79,    89,    90,    91,    92,
      42,    95,    96,    43,    44,    45,    46,    47,    48,    27,
     101,   104,   123,    49,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,    39,    67,     3,
      68,    13,    53,    17,   124,   130,    76,    77,    37,    80,
      81,    82,    83,    91,    92,    28,    53,   137,     4,     5,
       6,     7,     8,   141,    87,    88,    89,    90,    91,    92,
     104,    29,    30,   133,    32,   135,    80,    81,    82,    83,
      34,    33,   139,    40,    37,    55,    56,    84,    85,    58,
      86,    87,    88,    89,    90,    91,    92,    80,    81,    82,
      83,    57,    69,    71,   131,    75,   100,   122,    84,    85,
     126,    86,    87,    88,    89,    90,    91,    92,    80,    81,
      82,    83,   128,   129,   134,   138,    11,    72,    41,    84,
      85,   132,    86,    87,    88,    89,    90,    91,    92,    80,
      81,    82,    83,    36,   136,    98,   119,    38,   121,     0,
      84,    85,     0,    86,    87,    88,    89,    90,    91,    92,
      80,    81,    82,    83,     0,     0,    99,     0,     0,     0,
       0,    84,    85,     0,    86,    87,    88,    89,    90,    91,
      92,    80,    81,    82,    83,     0,     0,   105,     0,     0,
       0,     0,    84,    85,     0,    86,    87,    88,    89,    90,
      91,    92,    80,    81,    82,    83,     0,     0,   140,     0,
       0,     0,     0,    84,    85,     0,    86,    87,    88,    89,
      90,    91,    92,    80,    81,    82,    83,   120,     0,     0,
       0,     0,     0,     0,    84,    85,     0,    86,    87,    88,
      89,    90,    91,    92,     0,     0,     0,     0,   125,    80,
      81,    82,    83,    59,    21,    22,    23,    24,    25,    26,
      84,    85,    60,    86,    87,    88,    89,    90,    91,    92,
       0,    61,    80,    81,    82,    83,     0,     0,     0,     0,
       0,     0,     0,    84,    85,     0,    86,    87,    88,    89,
      90,    91,    92,    59,    21,    22,    23,    24,    25,    26,
       0,     0,    60,     0,     0,     0,     0,     0,     0,     0,
       0,    61
};

static const yytype_int16 yycheck[] =
{
      46,    47,    69,    22,    23,    24,    25,    26,    27,    55,
      56,    38,    39,    40,    60,    61,    34,    35,    36,    37,
       8,    67,    68,    11,    12,    13,    14,    15,    16,    16,
      76,    77,    99,    21,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    34,    38,     0,
      40,    21,    39,    22,   100,   122,    38,    39,    46,    17,
      18,    19,    20,    36,    37,    42,    53,   134,     3,     4,
       5,     6,     7,   140,    32,    33,    34,    35,    36,    37,
     126,    21,    45,   129,    44,   131,    17,    18,    19,    20,
      43,    41,   138,    41,    46,    39,    39,    28,    29,    21,
      31,    32,    33,    34,    35,    36,    37,    17,    18,    19,
      20,    39,    41,    47,    45,    21,    43,     9,    28,    29,
      45,    31,    32,    33,    34,    35,    36,    37,    17,    18,
      19,    20,    44,    40,    10,    45,     2,    53,    36,    28,
      29,   126,    31,    32,    33,    34,    35,    36,    37,    17,
      18,    19,    20,    30,   132,    44,    94,    32,    97,    -1,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      17,    18,    19,    20,    -1,    -1,    44,    -1,    -1,    -1,
      -1,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    17,    18,    19,    20,    -1,    -1,    44,    -1,    -1,
      -1,    -1,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    17,    18,    19,    20,    -1,    -1,    44,    -1,
      -1,    -1,    -1,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    17,    18,    19,    20,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    42,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    39,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    21,    22,    23,    24,    25,    26,    27,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    49,    50,     0,     3,     4,     5,     6,     7,    51,
      52,    53,    57,    21,    38,    39,    40,    22,    53,    58,
      59,    22,    23,    24,    25,    26,    27,    54,    42,    21,
      45,    60,    44,    41,    43,    55,    58,    46,    69,    54,
      41,    60,     8,    11,    12,    13,    14,    15,    16,    21,
      65,    69,    70,    54,    56,    39,    39,    39,    21,    21,
      30,    39,    54,    61,    66,    68,    68,    38,    40,    41,
      71,    47,    56,    68,    68,    21,    38,    39,    68,    68,
      17,    18,    19,    20,    28,    29,    31,    32,    33,    34,
      35,    36,    37,    67,    68,    68,    68,    65,    44,    44,
      43,    68,    62,    63,    68,    44,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    67,
      42,    71,     9,    65,    68,    42,    45,    64,    44,    40,
      65,    45,    62,    68,    10,    68,    64,    65,    45,    68,
      44,    65
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    51,    52,    52,    53,
      53,    53,    53,    53,    54,    54,    54,    54,    54,    54,
      55,    55,    56,    56,    57,    58,    59,    59,    60,    60,
      61,    62,    63,    63,    64,    64,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    66,    67,
      67,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      69,    70,    71,    71
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     5,     7,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     0,     2,     0,     6,     2,     2,     0,     3,     0,
       4,     1,     2,     0,     3,     0,     3,     6,     2,     2,
       5,    11,     6,     8,     1,     1,     2,     0,     2,     2,
       0,     4,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     1,
       3,     2,     3,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 86 "parser.y" /* yacc.c:1646  */
    {root = (yyval.ast);
                astDecompile((yyval.ast));
                astPrint((yyval.ast),0);
                checkAndSetTypes((yyvsp[0].ast));
                checkUndeclared();
                checkOperands((yyvsp[0].ast));
                fprintf(stderr,"%d Semantic errors\n", getSemanticError());
                /*checkSemantic($$);*/
                }
#line 1418 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 96 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_PROG, 0,(yyvsp[-1].ast),(yyvsp[0].ast),0,0, getLineNumber());}
#line 1424 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 96 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = 0;}
#line 1430 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 99 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate (AST_PROG_VARDECL, 0, (yyvsp[0].ast), 0, 0, 0,getLineNumber()); }
#line 1436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 100 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate (AST_PROG_FUNCDECL, 0, (yyvsp[0].ast), 0, 0, 0, getLineNumber()); }
#line 1442 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 102 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_DECL, (yyvsp[-3].symbol),(yyvsp[-4].ast),(yyvsp[-1].ast),0,0,getLineNumber());}
#line 1448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 103 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_ARRDECL,(yyvsp[-5].symbol),(yyvsp[-6].ast),astCreate(AST_VECSIZE, (yyvsp[-3].symbol), 0, 0, 0, 0,getLineNumber()),(yyvsp[-1].ast),0,getLineNumber());}
#line 1454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 106 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_TYPEINT,0,0,0,0,0,getLineNumber());}
#line 1460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 107 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_TYPEBOOL,0,0,0,0,0,getLineNumber());}
#line 1466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 108 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_TYPEBYTE,0,0,0,0,0,getLineNumber());}
#line 1472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 109 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_TYPELONG,0,0,0,0,0,getLineNumber());}
#line 1478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 110 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_TYPEFLOAT,0,0,0,0,0,getLineNumber());}
#line 1484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 112 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_SYMBOL,(yyvsp[0].symbol),0,0,0,0,getLineNumber());}
#line 1490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 113 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_SYMBOL,(yyvsp[0].symbol),0,0,0,0,getLineNumber());}
#line 1496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 114 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_SYMBOL,(yyvsp[0].symbol),0,0,0,0,getLineNumber());}
#line 1502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 115 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_SYMBOL,(yyvsp[0].symbol),0,0,0,0,getLineNumber());}
#line 1508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 116 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_SYMBOL,(yyvsp[0].symbol),0,0,0,0,getLineNumber());}
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 117 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_SYMBOL,(yyvsp[0].symbol),0,0,0,0,getLineNumber());}
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 119 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astCreate(AST_VECLIST,0,(yyvsp[-1].ast),(yyvsp[0].ast),0,0,getLineNumber());}
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 120 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = 0;}
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 122 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astCreate(AST_VECREST,0,(yyvsp[-1].ast),(yyvsp[0].ast),0,0,getLineNumber());}
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 123 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = 0;}
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 125 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_FUNDEC,(yyvsp[-4].symbol),(yyvsp[-5].ast),(yyvsp[-2].ast),(yyvsp[0].ast),0,getLineNumber());}
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 127 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_PAR, (yyvsp[0].symbol), (yyvsp[-1].ast), 0, 0, 0,getLineNumber());}
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 129 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_PARLIST, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0,getLineNumber());}
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 130 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = 0;}
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 132 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_PARLIST_REST, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0,getLineNumber());}
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 133 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = 0;}
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 135 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astCreate(AST_FUNCALL,(yyvsp[-3].symbol),(yyvsp[-1].ast),0,0,0,getLineNumber());}
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 137 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 139 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = astCreate(AST_FUNLIST, 0,(yyvsp[-1].ast),(yyvsp[0].ast),0,0,getLineNumber());}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 140 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = 0;}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 142 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_FUNLIST_REST, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0,getLineNumber()); }
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 143 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = 0;}
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 145 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_ASS,(yyvsp[-2].symbol),(yyvsp[0].ast),0,0,0,getLineNumber());}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 146 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_VECTORASS,(yyvsp[-5].symbol),(yyvsp[-3].ast),(yyvsp[0].ast),0,0,getLineNumber());}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 147 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_PRINT,0,(yyvsp[0].ast),0,0,0,getLineNumber());}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 148 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_READ, (yyvsp[0].symbol), 0, 0, 0, 0,getLineNumber()); }
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 149 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_WHILE,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0,getLineNumber());}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 150 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_FOR,(yyvsp[-8].symbol),(yyvsp[-6].ast),(yyvsp[-4].ast),(yyvsp[-2].ast),(yyvsp[0].ast),getLineNumber());}
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 151 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_IF,0,(yyvsp[-3].ast),(yyvsp[0].ast),0,0,getLineNumber());}
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 152 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_IFELSE,0,(yyvsp[-5].ast),(yyvsp[-2].ast),(yyvsp[0].ast),0,getLineNumber());}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 153 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_BREAK,0,0,0,0,0,getLineNumber());}
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 154 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 155 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_RETURN,0,(yyvsp[0].ast),0,0,0,getLineNumber());}
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 155 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = 0;}
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 159 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_PRINTLIST,0,(yyvsp[-1].ast),(yyvsp[0].ast),0,0,getLineNumber());}
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 161 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_PRINTLIST_REST,0,(yyvsp[-1].ast),(yyvsp[0].ast),0,0,getLineNumber());}
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 161 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = 0; }
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 163 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = astCreate(AST_VECREAD, (yyvsp[-3].symbol), (yyvsp[-1].ast), 0, 0, 0,getLineNumber());}
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 164 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_SYMBOL,(yyvsp[0].symbol),0,0,0,0,getLineNumber());}
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 165 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=(yyvsp[0].ast);}
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 166 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_EQ,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0,getLineNumber());}
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 167 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_DIFF,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0,getLineNumber());}
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 168 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_GE,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0,getLineNumber());}
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 169 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_LE,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0,getLineNumber());}
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 170 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_ADD,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0,getLineNumber());}
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 171 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_SUB,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0,getLineNumber());}
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 172 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_MUL,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0,getLineNumber());}
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 173 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_DIV,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0,getLineNumber());}
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 174 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_LESS,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0,getLineNumber());}
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 175 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_GREATER,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0,getLineNumber());}
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 176 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_POINT,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0,getLineNumber());}
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 177 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_OR,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0,getLineNumber());}
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 178 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_AND,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0,getLineNumber());}
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 179 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_TIL,0,(yyvsp[0].ast),0,0,0,getLineNumber());}
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 180 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_PARENTHESIS,0,(yyvsp[-1].ast),0,0,0,getLineNumber());}
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 181 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 183 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_BLOCK,0,(yyvsp[-1].ast),0,0,0,getLineNumber());}
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 186 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_LCMD,0,(yyvsp[-1].ast),(yyvsp[0].ast),0,0,getLineNumber());}
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 188 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=astCreate(AST_CMDEND,0,(yyvsp[-1].ast),(yyvsp[0].ast),0,0,getLineNumber());}
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 188 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = 0;}
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1848 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 190 "parser.y" /* yacc.c:1906  */


int yyerror(char *msg) {
    fprintf(stderr, "Erro de sintaxe na linha %d!\n", getLineNumber());
    exit(3); //codigo de erro sintatico padrao
}
