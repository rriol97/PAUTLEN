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
#line 1 "omicron.y" /* yacc.c:339  */

#include <stdio.h>

extern int columna;
extern int fila;
extern int yylex();
FILE *fout;

#line 75 "y.tab.c" /* yacc.c:339  */

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
    TOK_COMENTARIO = 258,
    TOK_SALTO = 259,
    TOK_BLANCO = 260,
    TOK_NONE = 261,
    TOK_CLASS = 262,
    TOK_INHERITS = 263,
    TOK_INSTANCE_OF = 264,
    TOK_DISCARD = 265,
    TOK_ITSELF = 266,
    TOK_FLECHA = 267,
    TOK_HIDDEN = 268,
    TOK_SECRET = 269,
    TOK_EXPOSED = 270,
    TOK_UNIQUE = 271,
    TOK_FUNCTION = 272,
    TOK_RETURN = 273,
    TOK_MAIN = 274,
    TOK_INT = 275,
    TOK_BOOLEAN = 276,
    TOK_ARRAY = 277,
    TOK_IF = 278,
    TOK_ELSE = 279,
    TOK_WHILE = 280,
    TOK_SCANF = 281,
    TOK_PRINTF = 282,
    TOK_IDENTIFICADOR = 283,
    TOK_IGUAL = 284,
    TOK_DISTINTO = 285,
    TOK_MENORIGUAL = 286,
    TOK_MAYORIGUAL = 287,
    TOK_OR = 288,
    TOK_AND = 289,
    TOK_CONSTANTE_ENTERA = 290,
    TOK_FALSE = 291,
    TOK_TRUE = 292,
    TOK_ERROR = 293,
    TOK_FOR = 294,
    TOK_SWITCH = 295,
    TOK_CASE = 296,
    TOK_DEFAULT = 297,
    TOK_FLOAT = 298,
    TOK_MALLOC = 299,
    TOK_CPRINTF = 300,
    TOK_FREE = 301,
    TOK_SET = 302,
    TOK_OF = 303,
    TOK_UNION = 304,
    TOK_INTERSECTION = 305,
    TOK_ADD = 306,
    TOK_CLEAR = 307,
    TOK_SIZE = 308,
    TOK_CONTAINS = 309,
    TOK_CONSTANTE_REAL = 310,
    UNARIO = 311
  };
#endif
/* Tokens.  */
#define TOK_COMENTARIO 258
#define TOK_SALTO 259
#define TOK_BLANCO 260
#define TOK_NONE 261
#define TOK_CLASS 262
#define TOK_INHERITS 263
#define TOK_INSTANCE_OF 264
#define TOK_DISCARD 265
#define TOK_ITSELF 266
#define TOK_FLECHA 267
#define TOK_HIDDEN 268
#define TOK_SECRET 269
#define TOK_EXPOSED 270
#define TOK_UNIQUE 271
#define TOK_FUNCTION 272
#define TOK_RETURN 273
#define TOK_MAIN 274
#define TOK_INT 275
#define TOK_BOOLEAN 276
#define TOK_ARRAY 277
#define TOK_IF 278
#define TOK_ELSE 279
#define TOK_WHILE 280
#define TOK_SCANF 281
#define TOK_PRINTF 282
#define TOK_IDENTIFICADOR 283
#define TOK_IGUAL 284
#define TOK_DISTINTO 285
#define TOK_MENORIGUAL 286
#define TOK_MAYORIGUAL 287
#define TOK_OR 288
#define TOK_AND 289
#define TOK_CONSTANTE_ENTERA 290
#define TOK_FALSE 291
#define TOK_TRUE 292
#define TOK_ERROR 293
#define TOK_FOR 294
#define TOK_SWITCH 295
#define TOK_CASE 296
#define TOK_DEFAULT 297
#define TOK_FLOAT 298
#define TOK_MALLOC 299
#define TOK_CPRINTF 300
#define TOK_FREE 301
#define TOK_SET 302
#define TOK_OF 303
#define TOK_UNION 304
#define TOK_INTERSECTION 305
#define TOK_ADD 306
#define TOK_CLEAR 307
#define TOK_SIZE 308
#define TOK_CONTAINS 309
#define TOK_CONSTANTE_REAL 310
#define UNARIO 311

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 10 "omicron.y" /* yacc.c:355  */

    char* cadena;
    float numero;

#line 232 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 249 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   308

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  209

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   311

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    61,     2,     2,     2,     2,     2,     2,
      67,    68,    58,    56,    71,    57,    69,    59,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    64,
      72,    70,    73,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    65,     2,    66,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    62,     2,    63,     2,     2,     2,     2,
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
      55,    60
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    76,    76,    81,    87,    92,    98,   103,   109,   114,
     119,   124,   129,   134,   139,   145,   150,   155,   160,   166,
     171,   178,   183,   189,   194,   200,   206,   212,   217,   223,
     229,   234,   240,   245,   250,   256,   262,   267,   273,   278,
     283,   289,   295,   300,   305,   311,   316,   322,   327,   332,
     337,   342,   347,   352,   358,   364,   369,   375,   380,   385,
     390,   395,   401,   407,   412,   418,   424,   429,   435,   441,
     446,   452,   457,   462,   467,   472,   477,   482,   487,   492,
     497,   502,   507,   512,   517,   522,   527,   533,   538,   544,
     550,   555,   561,   566,   571,   576,   581,   586,   591,   597,
     602,   608,   613,   619,   625
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_COMENTARIO", "TOK_SALTO",
  "TOK_BLANCO", "TOK_NONE", "TOK_CLASS", "TOK_INHERITS", "TOK_INSTANCE_OF",
  "TOK_DISCARD", "TOK_ITSELF", "TOK_FLECHA", "TOK_HIDDEN", "TOK_SECRET",
  "TOK_EXPOSED", "TOK_UNIQUE", "TOK_FUNCTION", "TOK_RETURN", "TOK_MAIN",
  "TOK_INT", "TOK_BOOLEAN", "TOK_ARRAY", "TOK_IF", "TOK_ELSE", "TOK_WHILE",
  "TOK_SCANF", "TOK_PRINTF", "TOK_IDENTIFICADOR", "TOK_IGUAL",
  "TOK_DISTINTO", "TOK_MENORIGUAL", "TOK_MAYORIGUAL", "TOK_OR", "TOK_AND",
  "TOK_CONSTANTE_ENTERA", "TOK_FALSE", "TOK_TRUE", "TOK_ERROR", "TOK_FOR",
  "TOK_SWITCH", "TOK_CASE", "TOK_DEFAULT", "TOK_FLOAT", "TOK_MALLOC",
  "TOK_CPRINTF", "TOK_FREE", "TOK_SET", "TOK_OF", "TOK_UNION",
  "TOK_INTERSECTION", "TOK_ADD", "TOK_CLEAR", "TOK_SIZE", "TOK_CONTAINS",
  "TOK_CONSTANTE_REAL", "'+'", "'-'", "'*'", "'/'", "UNARIO", "'!'", "'{'",
  "'}'", "';'", "'['", "']'", "'('", "')'", "'.'", "'='", "','", "'<'",
  "'>'", "$accept", "programa", "declaraciones", "declaracion",
  "modificadores_acceso", "clase", "declaracion_clase",
  "modificadores_clase", "clase_escalar", "tipo", "clase_objeto",
  "clase_vector", "identificadores", "funciones", "funcion",
  "tipo_retorno", "parametros_funcion", "resto_parametros_funcion",
  "parametro_funcion", "declaraciones_funcion", "sentencias", "sentencia",
  "sentencia_simple", "destruir_objeto", "bloque", "asignacion",
  "elemento_vector", "condicional", "bucle", "lectura", "escritura",
  "retorno_funcion", "exp", "identificador_clase", "lista_expresiones",
  "resto_lista_expresiones", "comparacion", "constante",
  "constante_logica", "constante_entera", "identificador", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,    43,    45,    42,    47,
     311,    33,   123,   125,    59,    91,    93,    40,    41,    46,
      61,    44,    60,    62
};
# endif

#define YYPACT_NINF -104

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-104)))

#define YYTABLE_NINF -88

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -3,   -44,    35,   109,  -104,    26,    40,    42,  -104,   119,
      53,   190,    44,   280,    53,  -104,  -104,  -104,    34,   280,
    -104,  -104,  -104,    60,    23,    23,    31,    80,  -104,  -104,
    -104,  -104,    23,  -104,    11,    21,    30,    23,    82,  -104,
      27,   280,    36,  -104,  -104,  -104,    29,  -104,  -104,  -104,
    -104,  -104,    32,    24,  -104,  -104,  -104,  -104,    23,    41,
      38,    50,    43,    23,  -104,    23,  -104,  -104,  -104,  -104,
    -104,    82,    82,    82,  -104,   120,    45,  -104,  -104,  -104,
     -36,    82,    82,  -104,    46,   120,  -104,  -104,  -104,    25,
      23,    82,    82,    48,    54,  -104,    92,  -104,  -104,  -104,
       7,    15,  -104,   209,    68,    82,    82,    82,    82,    82,
      82,    23,    82,   228,   236,    23,   120,   -26,   192,   111,
      69,    23,   120,    17,    62,    23,   119,    82,    82,    82,
      82,  -104,    82,    82,  -104,    15,  -104,    15,    15,  -104,
    -104,    71,    74,    84,    85,    81,    82,    82,  -104,    82,
    -104,  -104,    95,    23,    23,    96,    99,  -104,   104,    53,
     120,   120,   120,   120,   120,   120,    82,  -104,   280,   280,
      82,   105,   120,   111,    82,  -104,  -104,   110,    17,  -104,
     119,   112,   117,   126,   128,   125,  -104,  -104,   133,   190,
      99,    53,  -104,  -104,   156,  -104,  -104,  -104,  -104,   280,
    -104,   132,   140,   144,  -104,   280,  -104,   150,  -104
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    30,     1,    11,    12,    13,    14,    15,
      30,     4,    21,     0,    30,     8,     9,    10,     0,     0,
       5,    23,    24,     0,     0,     0,     0,     0,    16,    22,
      18,    17,     0,    88,     0,     0,     0,     0,     0,   104,
       0,    43,     0,    53,    46,    47,     0,    55,    56,    48,
      49,    50,     0,    87,    29,    32,    33,    34,     0,     0,
       0,     0,     0,    27,     7,     0,    54,    70,   103,   102,
     101,     0,     0,     0,    83,    69,     0,    80,    99,   100,
      79,     0,     0,    67,    66,    68,     3,    44,    45,     0,
       0,     0,    90,     0,     0,     2,     0,    25,     6,    28,
       0,    75,    78,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    90,     0,     0,     0,    58,     0,     0,    92,
       0,     0,    57,    36,     0,     0,    15,     0,     0,     0,
       0,    81,     0,     0,    82,    77,    76,    71,    72,    74,
      73,    86,     0,     0,     0,     0,    90,     0,    62,     0,
      89,    52,     0,     0,     0,     0,    38,    26,     0,    30,
      93,    94,    95,    96,    97,    98,    90,    84,     0,     0,
      90,     0,    61,    92,    90,    39,    40,     0,     0,    35,
      15,     0,     0,     0,     0,     0,    51,    91,     0,    42,
      38,    30,    20,    85,    63,    65,    59,    60,    41,     0,
      37,     0,     0,     0,    19,     0,    31,     0,    64
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -104,  -104,    -6,  -104,   205,  -104,  -104,  -104,  -104,     2,
       9,  -104,   -50,    -7,  -104,  -104,  -104,    33,    37,  -104,
     -18,  -104,  -104,  -104,  -104,  -104,   -11,  -104,  -104,  -104,
    -104,  -104,   127,    -9,  -103,    49,  -104,  -104,  -104,   121,
     -13
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    10,    11,    12,    25,    26,    27,    28,   153,
     154,    31,    62,    13,    14,    58,   155,   179,   156,   199,
      40,    41,    42,    43,    44,    45,    74,    47,    48,    49,
      50,    51,   119,    76,   120,   150,   104,    77,    78,    79,
      80
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      53,    59,    46,    19,    52,    20,    53,    54,    46,   142,
      52,    61,    63,    99,    29,   125,     1,    67,     3,    66,
      56,    30,    33,    87,    84,    60,    83,    57,    53,    91,
      46,   112,    52,   -87,   115,     4,    33,    21,    22,    39,
      55,   146,    15,   171,   147,    94,    68,    69,    70,   106,
      63,    39,   100,    39,    21,    22,    16,   121,    17,    33,
      68,    69,    70,   182,    21,    22,    23,   185,    71,   126,
       9,   188,    72,   109,   110,   158,    39,   117,    73,    24,
      21,    22,    71,    68,    69,    70,    72,    65,    81,    91,
      86,    92,    73,    33,    93,    64,    24,    82,   141,    89,
      88,    90,   145,    96,    95,    71,    24,    98,   152,    72,
      39,    91,    63,    97,   111,    73,   -15,    68,    69,    70,
     159,   123,     5,     6,     7,     8,     9,    68,   157,   -15,
     -15,   -15,     5,     6,     7,     8,   134,   151,   166,    71,
     175,   176,   167,    72,   105,   106,   168,   169,   170,    73,
     183,   184,   181,   105,   106,    53,    53,    46,    46,    52,
      52,    75,   174,   178,   177,    85,   180,   107,   108,   109,
     110,   -15,   189,   186,   191,   192,   107,   108,   109,   110,
     202,   203,   149,   198,   201,   193,    53,   207,    46,   194,
      52,   195,    53,   196,    46,   204,    52,   -15,   101,   102,
     103,   197,   205,     5,     6,     7,     8,   206,   113,   114,
     -15,   -15,   -15,   208,    18,   190,   116,   124,   118,     0,
     122,     0,   187,   200,     0,   105,   106,     0,     0,     0,
       0,     0,   135,   136,   137,   138,   139,   140,   127,   128,
     129,   130,   105,   106,     0,     0,     0,     0,   107,   108,
     109,   110,   -15,     0,   160,   161,   162,   163,   148,   164,
     165,   105,   106,     0,     0,   107,   108,   109,   110,   105,
     106,     0,     0,     0,   172,     0,   173,   131,     0,     0,
       0,   132,   133,     0,   107,   108,   109,   110,     0,     0,
      32,    33,   107,   108,   109,   110,   143,     0,    34,     0,
       0,     0,     0,    35,   144,    36,    37,    38,    39
};

static const yytype_int16 yycheck[] =
{
      13,    19,    13,    10,    13,    11,    19,    14,    19,   112,
      19,    24,    25,    63,    12,     8,    19,     6,    62,    32,
      18,    12,    11,    41,    37,    23,    37,    18,    41,    65,
      41,    67,    41,    69,     9,     0,    11,    20,    21,    28,
       6,    67,    16,   146,    70,    58,    35,    36,    37,    34,
      63,    28,    65,    28,    20,    21,    16,     9,    16,    11,
      35,    36,    37,   166,    20,    21,    22,   170,    57,    62,
      17,   174,    61,    58,    59,   125,    28,    90,    67,    62,
      20,    21,    57,    35,    36,    37,    61,     7,    67,    65,
      63,    67,    67,    11,    70,    64,    62,    67,   111,    70,
      64,    69,   115,    65,    63,    57,    62,    64,   121,    61,
      28,    65,   125,    63,    69,    67,     7,    35,    36,    37,
     126,    67,    13,    14,    15,    16,    17,    35,    66,    20,
      21,    22,    13,    14,    15,    16,    68,    68,    67,    57,
     153,   154,    68,    61,    33,    34,    62,    62,    67,    67,
     168,   169,   159,    33,    34,   168,   169,   168,   169,   168,
     169,    34,    67,    64,    68,    38,    62,    56,    57,    58,
      59,    62,    62,    68,   180,    63,    56,    57,    58,    59,
      24,   199,    71,   189,   191,    68,   199,   205,   199,    63,
     199,    63,   205,    68,   205,    63,   205,     7,    71,    72,
      73,    68,    62,    13,    14,    15,    16,    63,    81,    82,
      20,    21,    22,    63,     9,   178,    89,    96,    91,    -1,
      93,    -1,   173,   190,    -1,    33,    34,    -1,    -1,    -1,
      -1,    -1,   105,   106,   107,   108,   109,   110,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    62,    -1,   127,   128,   129,   130,    66,   132,
     133,    33,    34,    -1,    -1,    56,    57,    58,    59,    33,
      34,    -1,    -1,    -1,   147,    -1,   149,    68,    -1,    -1,
      -1,    72,    73,    -1,    56,    57,    58,    59,    -1,    -1,
      10,    11,    56,    57,    58,    59,    68,    -1,    18,    -1,
      -1,    -1,    -1,    23,    68,    25,    26,    27,    28
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    19,    75,    62,     0,    13,    14,    15,    16,    17,
      76,    77,    78,    87,    88,    16,    16,    16,    78,    87,
      76,    20,    21,    22,    62,    79,    80,    81,    82,    83,
      84,    85,    10,    11,    18,    23,    25,    26,    27,    28,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   107,   114,    87,     6,    83,    84,    89,    94,
      83,   114,    86,   114,    64,     7,   114,     6,    35,    36,
      37,    57,    61,    67,   100,   106,   107,   111,   112,   113,
     114,    67,    67,   100,   114,   106,    63,    94,    64,    70,
      69,    65,    67,    70,   114,    63,    65,    63,    64,    86,
     114,   106,   106,   106,   110,    33,    34,    56,    57,    58,
      59,    69,    67,   106,   106,     9,   106,   114,   106,   106,
     108,     9,   106,    67,   113,     8,    62,    29,    30,    31,
      32,    68,    72,    73,    68,   106,   106,   106,   106,   106,
     106,   114,   108,    68,    68,   114,    67,    70,    66,    71,
     109,    68,   114,    83,    84,    90,    92,    66,    86,    76,
     106,   106,   106,   106,   106,   106,    67,    68,    62,    62,
      67,   108,   106,   106,    67,   114,   114,    68,    64,    91,
      62,    87,   108,    94,    94,   108,    68,   109,   108,    62,
      92,    76,    63,    68,    63,    63,    68,    68,    76,    93,
      91,    87,    24,    94,    63,    62,    63,    94,    63
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    74,    75,    75,    76,    76,    77,    77,    78,    78,
      78,    78,    78,    78,    78,    78,    79,    79,    79,    80,
      80,    81,    82,    83,    83,    84,    85,    86,    86,    87,
      87,    88,    89,    89,    89,    90,    90,    91,    91,    92,
      92,    93,    93,    94,    94,    95,    95,    96,    96,    96,
      96,    96,    96,    96,    97,    98,    98,    99,    99,    99,
      99,    99,   100,   101,   101,   102,   103,   103,   104,   105,
     105,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   107,   107,   108,
     108,   109,   109,   110,   110,   110,   110,   110,   110,   111,
     111,   112,   112,   113,   114
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     5,     1,     2,     4,     3,     2,     2,
       2,     1,     1,     1,     1,     0,     1,     1,     1,     9,
       7,     0,     1,     1,     1,     3,     5,     1,     2,     2,
       0,    11,     1,     1,     1,     2,     0,     3,     0,     2,
       2,     1,     0,     1,     2,     2,     1,     1,     1,     1,
       1,     6,     4,     1,     2,     1,     1,     3,     3,     7,
       7,     5,     4,     7,    11,     7,     2,     2,     2,     2,
       2,     3,     3,     3,     3,     2,     3,     3,     2,     1,
       1,     3,     3,     1,     4,     6,     3,     1,     1,     2,
       0,     3,     0,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     1
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
#line 77 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tprograma: TOK_MAIN '{' declaraciones funciones sentencias '}'\n");
    }
#line 1509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 82 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tprograma: TOK_MAIN '{' funciones sentencias '}'\n");
    }
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 88 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tdeclaraciones: declaracion\n");
    }
#line 1525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 93 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tdeclaraciones: declaracion declaraciones\n");
    }
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 99 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tdeclaracion: modificadores_acceso clase identificadores ';'\n");
    }
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 104 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tdeclaracion: modificadores_acceso declaracion_clase ';'\n");
    }
#line 1549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 110 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tmodificadores_acceso: TOK_HIDDEN TOK_UNIQUE\n");
    }
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 115 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tmodificadores_acceso: TOK_SECRET TOK_UNIQUE\n");
    }
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 120 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tmodificadores_acceso: TOK_EXPOSED TOK_UNIQUE\n");
    }
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 125 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tmodificadores_acceso: TOK_HIDDEN\n");
    }
#line 1581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 130 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tmodificadores_acceso: TOK_SECRET\n");
    }
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 135 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tmodificadores_acceso: TOK_EXPOSED\n");
    }
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 140 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tmodificadores_acceso: TOK_UNIQUE\n");
    }
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 145 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tmodificadores_acceso:\n");
    }
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 151 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tclase: clase_escalar\n");
    }
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 156 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tclase: clase_vector\n");
    }
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 161 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tclase: clase_objeto\n");
    }
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 167 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tdeclaracion_clase: modificadores_clase TOK_CLASS identificador TOK_INHERITS identificadores '{' declaraciones funciones '}'\n");
    }
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 172 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tdeclaracion_clase: modificadores_clase TOK_CLASS identificador '{' declaraciones funciones '}'\n");
    }
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 178 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tmodificadores_clase:\n");
    }
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 184 "omicron.y" /* yacc.c:1646  */
    {
       fprintf(fout, ";R:\tclase_escalar: tipo\n"); 
    }
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 190 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\ttipo: TOK_INT\n");
    }
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 195 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\ttipo: TOK_BOOLEAN\n");
    }
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 201 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tclase_objeto: '{' identificador '}'\n");
    }
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 207 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tclase_vector: TOK_ARRAY tipo '[' constante_entera ']'\n");
    }
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 213 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tidentificadores: identificador\n");
    }
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 218 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tidentificadores: identificador identificadores\n");
    }
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 224 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tfunciones: funcion funciones\n");
    }
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 229 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tfunciones:\n");
    }
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 235 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tfuncion: TOK_FUNCTION modificadores_acceso tipo_retorno identificador '(' parametros_funcion ')' '{' declaraciones_funcion sentencias '}'\n");
    }
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 241 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\ttipo_retorno: TOK_NONE\n");
    }
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 246 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\ttipo_retorno: tipo\n");
    }
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 251 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\ttipo_retorno: clase_objeto\n");
    }
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 257 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tparametros_funcion: parametro_funcion resto_parametros_funcion\n");
    }
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 262 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tparametros_funcion:\n");
    }
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 268 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tresto_parametros_funcion: ';' parametro_funcion resto_parametros_funcion\n");
    }
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 273 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tresto_parametros_funcion:\n");
    }
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 279 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tparametro_funcion: tipo identificador\n");
    }
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 284 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tparametro_funcion: clase_objeto identificador\n");   
    }
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 290 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tdeclaraciones_funcion: declaraciones\n");
    }
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 295 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tdeclaraciones_funcion:\n");
    }
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 301 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tsentencias: sentencia\n");
    }
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 306 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tsentencias: sentencia sentencias\n");
    }
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 312 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tsentencia: sentencia_simple ';'\n");
    }
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 317 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tsentencia: bloque\n");
    }
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 323 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tsentencia_simple: asignacion\n");
    }
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 328 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tsentencia_simple: lectura\n");
    }
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 333 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tsentencia_simple: escritura\n");
    }
#line 1885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 338 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tsentencia_simple: retorno_funcion\n");
    }
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 343 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tsentencia_simple: identificador_clase '.' identificador '(' lista_expresiones ')'\n");
    }
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 348 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tsentencia_simple: identificador '(' lista_expresiones ')'\n");
    }
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 353 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tsentencia_simple: destruir_objeto\n");
    }
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 359 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tdestruir_objeto: TOK_DISCARD identificador\n");
    }
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 365 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tbloque: condicional\n");
    }
#line 1933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 370 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tbloque: bucle\n");
    }
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 376 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tasignacion: identificador '=' exp\n");
    }
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 381 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tasignacion: elemento_vector '=' exp\n");
    }
#line 1957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 386 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tasignacion: elemento_vector '=' TOK_INSTANCE_OF identificador '(' lista_expresiones ')'\n");
    }
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 391 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tasignacion: identificador '=' TOK_INSTANCE_OF identificador '(' lista_expresiones ')'\n");
    }
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 396 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tasignacion: identificador_clase '.' identificador '=' exp\n");
    }
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 402 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\telemento_vector: identificador '[' exp ']'\n");
    }
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 408 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tcondicional: TOK_IF '(' exp ')' '{' sentencias '}'\n");
    }
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 413 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tcondicional: TOK_IF '(' exp ')' '{' sentencias '}' TOK_ELSE '{' sentencias '}'\n");
    }
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 419 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tbucle: TOK_WHILE '(' exp ')' '{' sentencias '}'\n");
    }
#line 2013 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 425 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tlectura: TOK_SCANF identificador\n");
    }
#line 2021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 430 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tlectura: TOK_SCANF elemento_vector\n");
    }
#line 2029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 436 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tescritura: TOK_PRINTF exp\n");
    }
#line 2037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 442 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tretorno_funcion: TOK_RETURN exp\n");
    }
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 447 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tretorno_funcion: TOK_RETURN TOK_NONE\n");
    }
#line 2053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 453 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\texp: exp '+' exp\n");
    }
#line 2061 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 458 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\texp: exp '-' exp\n");
    }
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 463 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\texp: exp '/' exp\n");
    }
#line 2077 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 468 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\texp: exp '*' exp\n");
    }
#line 2085 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 473 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\texp: '-' exp\n");
    }
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 478 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\texp: exp TOK_AND exp\n");
    }
#line 2101 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 483 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\texp: exp TOK_OR exp\n");
    }
#line 2109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 488 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\texp: '!' exp\n");
    }
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 493 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\texp: identificador\n");
    }
#line 2125 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 498 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\texp: constante\n");
    }
#line 2133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 503 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\texp: '(' exp ')'\n");
    }
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 508 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\texp: '(' comparacion ')'\n");
    }
#line 2149 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 513 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\texp: elemento_vector\n");
    }
#line 2157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 518 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\texp: identificador '(' lista_expresiones ')'\n");
    }
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 523 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\texp: identificador_clase '.' identificador '(' lista_expresiones ')'\n");
    }
#line 2173 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 528 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\texp: identificador_clase '.' identificador\n");
    }
#line 2181 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 534 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tidentificador_clase: identificador\n");
    }
#line 2189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 539 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tidentificador_clase: TOK_ITSELF\n");
    }
#line 2197 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 545 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tlista_expresiones: exp resto_lista_expresiones\n");
    }
#line 2205 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 550 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tlista_expresiones:\n");
    }
#line 2213 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 556 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tresto_lista_expresiones: ',' exp resto_lista_expresiones\n");
    }
#line 2221 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 561 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tlista_expresiones:\n");
    }
#line 2229 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 567 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tcomparacion: exp TOK_IGUAL exp\n");
    }
#line 2237 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 572 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tcomparacion: exp TOK_DISTINTO exp\n");
    }
#line 2245 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 577 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tcomparacion: exp TOK_MENORIGUAL exp\n");
    }
#line 2253 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 582 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tcomparacion: exp TOK_MAYORIGUAL exp\n");
    }
#line 2261 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 587 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tcomparacion: exp '<' exp\n");
    }
#line 2269 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 592 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tcomparacion: exp '>' exp\n");
    }
#line 2277 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 598 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tconstante: constante_logica\n");
    }
#line 2285 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 603 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tconstante: constante_entera\n");
    }
#line 2293 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 609 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tconstante_logica: TOK_TRUE\n");
    }
#line 2301 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 614 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tconstante_logica: TOK_FALSE\n");
    }
#line 2309 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 620 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tconstante_entera: TOK_CONSTANTE_ENTERA\n");
    }
#line 2317 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 626 "omicron.y" /* yacc.c:1646  */
    {
        fprintf(fout, ";R:\tidentificador: TOK_IDENTIFICADOR\n");
    }
#line 2325 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2329 "y.tab.c" /* yacc.c:1646  */
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
#line 631 "omicron.y" /* yacc.c:1906  */


int yyerror(char* s) {
    fprintf(stderr, "ERROR SINTÁCTICO:%d:%d\n", fila, columna);
    return -1;
}
