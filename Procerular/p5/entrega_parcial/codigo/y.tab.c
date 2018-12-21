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
#include "omicron.h"
#include "generacion.h"
#include "graph.h"
#include "tabla.h"

extern int columna;
extern int fila;
extern int yylex();
extern FILE *yyin;
extern FILE *fout;
extern int flag_error;

int tipo_id_actual;
TablaAmbito * tabla_main;
elementoTablaSimbolos * elem;
char nombre_ambito_encontrado[MAX_NAME];
int tipo_declaracion;
int etiqueta = 1;

#line 88 "y.tab.c" /* yacc.c:339  */

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
#line 23 "omicron.y" /* yacc.c:355  */

    tipo_atributos atributos;

#line 244 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 261 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   276

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  111
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  221

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
      68,    69,    58,    56,    67,    57,    70,    59,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    64,
      72,    71,    73,     2,     2,     2,     2,     2,     2,     2,
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
       0,   108,   108,   114,   121,   131,   143,   148,   154,   162,
     168,   173,   178,   183,   188,   193,   198,   204,   209,   215,
     220,   226,   231,   236,   243,   248,   255,   262,   270,   276,
     282,   287,   293,   300,   306,   318,   324,   329,   335,   340,
     345,   351,   357,   363,   368,   374,   379,   384,   390,   396,
     401,   406,   412,   417,   423,   428,   433,   438,   443,   448,
     453,   459,   465,   470,   476,   499,   506,   511,   516,   522,
     543,   549,   557,   569,   575,   589,   595,   614,   619,   625,
     648,   657,   669,   678,   687,   696,   705,   714,   730,   736,
     742,   748,   754,   759,   764,   771,   776,   782,   788,   793,
     799,   804,   823,   832,   841,   850,   859,   869,   875,   882,
     889,   897
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
  "'}'", "';'", "'['", "']'", "','", "'('", "')'", "'.'", "'='", "'<'",
  "'>'", "$accept", "programa", "inicioTabla", "escribirHastaMain",
  "declaraciones", "declaracion", "modificadores_acceso", "clase",
  "declaracion_clase", "modificadores_clase", "clase_escalar", "tipo",
  "clase_objeto", "clase_vector", "identificadores",
  "identificadores_declaracion", "identificador", "funciones", "funcion",
  "tipo_retorno", "inherits", "parametros_funcion",
  "resto_parametros_funcion", "parametro_funcion", "declaraciones_funcion",
  "sentencias", "sentencia", "sentencia_simple", "destruir_objeto",
  "bloque", "asignacion", "elemento_vector", "condicional",
  "if_exp_sentencias", "if_exp", "bucle", "lectura", "escritura",
  "retorno_funcion", "exp", "identificador_clase", "lista_expresiones",
  "resto_lista_expresiones", "comparacion", "constante",
  "constante_logica", "constante_entera", YY_NULLPTR
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
     311,    33,   123,   125,    59,    91,    93,    44,    40,    41,
      46,    61,    60,    62
};
# endif

#define YYPACT_NINF -102

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-102)))

#define YYTABLE_NINF -96

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      13,  -102,    48,    -2,  -102,   139,    47,    50,    51,  -102,
      53,  -102,   139,    15,  -102,  -102,  -102,    88,   248,    53,
      53,  -102,  -102,  -102,    30,    40,    45,    12,    74,  -102,
    -102,  -102,  -102,    10,    59,  -102,    17,    29,    49,    70,
     105,   -22,    52,   248,    58,  -102,  -102,  -102,    55,  -102,
     103,   248,  -102,  -102,  -102,  -102,    60,  -102,   248,    64,
      68,  -102,    73,    80,  -102,   107,  -102,  -102,  -102,   120,
    -102,  -102,   -41,  -102,  -102,  -102,   105,   105,   105,  -102,
     198,    79,  -102,  -102,  -102,   105,   105,    86,  -102,   198,
     105,   105,    71,  -102,  -102,  -102,    77,    94,    95,   129,
     100,   135,  -102,  -102,    45,    -1,   101,   105,  -102,  -102,
     153,   102,   105,   105,   105,   105,   105,   105,   144,   134,
     161,   194,   180,   108,   146,   198,   148,   198,   248,  -102,
     -24,  -102,   113,  -102,  -102,    88,   152,    -3,   119,   105,
     105,   105,   105,  -102,   105,   105,  -102,   -20,  -102,   -20,
     -20,  -102,  -102,   128,   138,   140,  -102,   105,  -102,  -102,
     136,   137,   143,   105,   105,  -102,    53,   141,   145,   187,
     188,   154,   157,  -102,   198,   198,   198,   198,   198,   198,
     105,  -102,   248,   180,   105,   105,  -102,   155,   198,   166,
     152,    -5,  -102,  -102,   171,    -3,  -102,   165,   172,  -102,
     173,   174,  -102,  -102,  -102,    53,   177,   139,   157,  -102,
    -102,  -102,  -102,   178,  -102,  -102,   248,  -102,  -102,   181,
    -102
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,     0,     1,     5,    13,    14,    15,    16,
      36,     5,     6,    24,    10,    11,    12,    17,     0,    36,
      36,     7,    26,    27,     0,     0,     0,     0,     0,    18,
      25,    20,    19,     0,     0,    96,     0,     0,     0,     0,
       0,    95,     0,    50,     0,    60,    53,    54,     0,    62,
       0,     0,    63,    55,    56,    57,     0,    35,     0,     0,
       0,    34,     0,    32,     9,     0,    38,    39,    40,     0,
      61,    78,    87,   111,   110,   109,     0,     0,     0,    91,
      77,     0,    88,   107,   108,     0,     0,    74,    75,    76,
       0,    98,     0,     3,    51,    52,     0,     0,     0,     0,
       0,     0,    28,     8,     0,     0,     0,    98,    83,    86,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   100,     0,     0,    64,     0,    65,     0,    71,
       0,     2,     0,    33,    41,    17,     0,    43,     0,     0,
       0,     0,     0,    89,     0,     0,    90,    85,    84,    79,
      80,    82,    81,    94,     0,     0,    69,     0,    97,    59,
       0,     0,     0,    98,     0,    29,    36,    30,     0,     0,
       0,     0,    45,    92,   101,   102,   103,   104,   105,   106,
      98,    72,     0,   100,    98,    98,    70,     0,    68,     0,
       0,    17,    46,    47,     0,     0,    42,     0,     0,    99,
       0,     0,    58,    23,    31,    36,     0,    49,    45,    93,
      73,    67,    66,     0,    22,    48,     0,    44,    21,     0,
      37
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -102,  -102,  -102,   234,   -10,  -102,   229,  -102,  -102,  -102,
    -102,    76,     9,  -102,    72,   159,  -102,   -16,  -102,  -102,
    -102,  -102,    41,    66,  -102,   -38,  -102,  -102,  -102,  -102,
    -102,   -18,  -102,  -102,  -102,  -102,  -102,  -102,  -102,   -21,
     -17,  -101,    65,  -102,  -102,  -102,   163
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    10,    11,    12,    13,    26,    27,    28,
      29,   169,   170,    32,   168,    62,    63,    18,    19,    69,
     136,   171,   196,   172,   216,    42,    43,    44,    45,    46,
      47,    79,    49,    50,    51,    52,    53,    54,    55,   122,
      81,   123,   158,   111,    82,    83,    84
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      48,    56,    21,    57,    58,    94,   138,   134,     6,     7,
       8,     9,    17,    98,   113,    80,    66,    22,    23,    89,
     100,    88,    31,    71,    90,    48,    56,   107,    35,   -95,
      22,    23,     1,    48,    56,    22,    23,    24,   116,   117,
      48,    56,    68,    90,   163,    72,    91,   164,     4,    92,
      22,    23,    73,    74,    75,   108,   109,   110,   -36,    25,
       5,   135,   187,    14,   119,   120,    15,    16,    60,   121,
      17,   125,    25,    61,    76,   127,    64,    25,    77,   197,
     124,    65,    35,   200,   201,    78,   126,    70,    35,    30,
     162,   147,   148,   149,   150,   151,   152,    85,    87,    72,
      59,     6,     7,     8,     9,    72,    73,    74,    75,    67,
      48,    56,    73,    74,    75,    93,    35,    86,   174,   175,
     176,   177,    95,   178,   179,   166,    96,    97,    76,   101,
      99,   102,    77,    72,    76,   105,   183,   103,    77,    78,
      73,    74,    75,   188,   198,    78,   -17,   104,   106,   118,
     189,    90,     6,     7,     8,     9,   128,   130,   129,   -17,
     -17,   -17,    76,   131,    48,    56,    77,   112,   113,   137,
      73,   146,   153,    78,   160,   206,   161,   159,   219,   165,
     167,   205,   139,   140,   141,   142,   112,   113,   173,   213,
     114,   115,   116,   117,   112,   113,   180,   215,    48,    56,
     181,   -17,   182,   154,   184,   185,   186,   191,   190,   114,
     115,   116,   117,   112,   113,   192,   193,   114,   115,   116,
     117,   195,   143,   194,   202,   144,   145,   112,   113,   203,
     155,   112,   113,   207,   209,   210,   114,   115,   116,   117,
     214,   218,   211,   212,   220,    20,    33,   157,   199,   217,
     114,   115,   116,   117,   114,   115,   116,   117,    34,    35,
     156,   208,   204,   133,   132,     0,    36,     0,     0,     0,
       0,    37,     0,    38,    39,    40,    41
};

static const yytype_int16 yycheck[] =
{
      18,    18,    12,    19,    20,    43,   107,     8,    13,    14,
      15,    16,    17,    51,    34,    36,     6,    20,    21,    40,
      58,    39,    13,     6,    65,    43,    43,    68,    11,    70,
      20,    21,    19,    51,    51,    20,    21,    22,    58,    59,
      58,    58,    33,    65,    68,    28,    68,    71,     0,    71,
      20,    21,    35,    36,    37,    76,    77,    78,    63,    62,
      62,    62,   163,    16,    85,    86,    16,    16,    28,    90,
      17,    92,    62,    28,    57,    96,    64,    62,    61,   180,
       9,     7,    11,   184,   185,    68,     9,    28,    11,    13,
     128,   112,   113,   114,   115,   116,   117,    68,    28,    28,
      24,    13,    14,    15,    16,    28,    35,    36,    37,    33,
     128,   128,    35,    36,    37,    63,    11,    68,   139,   140,
     141,   142,    64,   144,   145,   135,    71,    24,    57,    65,
      70,    63,    61,    28,    57,    28,   157,    64,    61,    68,
      35,    36,    37,   164,   182,    68,     7,    67,    28,    70,
     166,    65,    13,    14,    15,    16,    62,    28,    63,    20,
      21,    22,    57,    63,   182,   182,    61,    33,    34,    68,
      35,    69,    28,    68,    28,   191,    28,    69,   216,    66,
      28,   191,    29,    30,    31,    32,    33,    34,    69,   205,
      56,    57,    58,    59,    33,    34,    68,   207,   216,   216,
      62,    62,    62,    69,    68,    68,    63,    62,    67,    56,
      57,    58,    59,    33,    34,    28,    28,    56,    57,    58,
      59,    64,    69,    69,    69,    72,    73,    33,    34,    63,
      69,    33,    34,    62,    69,    63,    56,    57,    58,    59,
      63,    63,    69,    69,    63,    11,    17,    67,   183,   208,
      56,    57,    58,    59,    56,    57,    58,    59,    10,    11,
      66,   195,   190,   104,   101,    -1,    18,    -1,    -1,    -1,
      -1,    23,    -1,    25,    26,    27,    28
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    19,    75,    76,     0,    62,    13,    14,    15,    16,
      77,    78,    79,    80,    16,    16,    16,    17,    91,    92,
      77,    78,    20,    21,    22,    62,    81,    82,    83,    84,
      85,    86,    87,    80,    10,    11,    18,    23,    25,    26,
      27,    28,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   114,    91,    91,    85,
      28,    28,    89,    90,    64,     7,     6,    85,    86,    93,
      28,     6,    28,    35,    36,    37,    57,    61,    68,   105,
     113,   114,   118,   119,   120,    68,    68,    28,   105,   113,
      65,    68,    71,    63,    99,    64,    71,    24,    99,    70,
      99,    65,    63,    64,    67,    28,    28,    68,   113,   113,
     113,   117,    33,    34,    56,    57,    58,    59,    70,   113,
     113,   113,   113,   115,     9,   113,     9,   113,    62,    63,
      28,    63,   120,    89,     8,    62,    94,    68,   115,    29,
      30,    31,    32,    69,    72,    73,    69,   113,   113,   113,
     113,   113,   113,    28,    69,    69,    66,    67,   116,    69,
      28,    28,    99,    68,    71,    66,    78,    28,    88,    85,
      86,    95,    97,    69,   113,   113,   113,   113,   113,   113,
      68,    62,    62,   113,    68,    68,    63,   115,   113,    91,
      67,    62,    28,    28,    69,    64,    96,   115,    99,   116,
     115,   115,    69,    63,    88,    78,    91,    62,    97,    69,
      63,    69,    69,    91,    63,    78,    98,    96,    63,    99,
      63
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    74,    75,    75,    76,    77,    78,    78,    79,    79,
      80,    80,    80,    80,    80,    80,    80,    80,    81,    81,
      81,    82,    82,    82,    83,    84,    85,    85,    86,    87,
      88,    88,    89,    89,    90,    91,    91,    92,    93,    93,
      93,    94,    95,    95,    96,    96,    97,    97,    98,    98,
      99,    99,   100,   100,   101,   101,   101,   101,   101,   101,
     101,   102,   103,   103,   104,   104,   104,   104,   104,   105,
     106,   107,   108,   109,   110,   110,   111,   112,   112,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   114,   114,   115,   115,   116,
     116,   117,   117,   117,   117,   117,   117,   118,   118,   119,
     119,   120
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     7,     0,     0,     1,     2,     4,     3,
       2,     2,     2,     1,     1,     1,     1,     0,     1,     1,
       1,     9,     8,     7,     0,     1,     1,     1,     3,     5,
       1,     3,     1,     3,     1,     2,     0,    11,     1,     1,
       1,     1,     2,     0,     3,     0,     2,     2,     1,     0,
       1,     2,     2,     1,     1,     1,     1,     1,     6,     4,
       1,     2,     1,     1,     3,     3,     7,     7,     5,     4,
       5,     3,     5,     7,     2,     2,     2,     2,     2,     3,
       3,     3,     3,     2,     3,     3,     2,     1,     1,     3,
       3,     1,     4,     6,     3,     1,     1,     2,     0,     3,
       0,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     1
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
#line 109 "omicron.y" /* yacc.c:1646  */
    {
        escribir_fin(fout);
        tablaFree(tabla_main);
    }
#line 1527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 115 "omicron.y" /* yacc.c:1646  */
    {
        escribir_fin(fout);
        tablaFree(tabla_main);
    }
#line 1536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 121 "omicron.y" /* yacc.c:1646  */
    {
    /* Inic tabla simbolos */

    if ( abrirAmbitoClase(&tabla_main, "main", 1) == -1) { /* init tabla simbolos */
        printf("error inicializando en la tabla de simbolos");
    }
    escribir_subseccion_data(fout);
    escribir_cabecera_bss(fout);
}
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 131 "omicron.y" /* yacc.c:1646  */
    {


        //Buscamos la variable en

    //getVarsTS
    //Declararlas

    escribir_segmento_codigo(fout);
    escribir_inicio_main(fout);
}
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 144 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tdeclaraciones: declaracion\n");
    }
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 149 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tdeclaraciones: declaracion, declaraciones\n");
    }
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 155 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo != (yyvsp[-1].atributos).tipo) {
            printf("Declaracion de distintos tipos NOT GOOD\n");
        }
        // Lo suyo sería hacer aqui las declaraciones
    }
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 163 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tdeclaracion: modificadores_acceso declaracion_clase ';'\n");
    }
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 169 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tmodificadores_acceso: TOK_HIDDEN TOK_UNIQUE\n");
    }
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 174 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tmodificadores_acceso: TOK_SECRET TOK_UNIQUE\n");
    }
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 179 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tmodificadores_acceso: TOK_EXPOSED TOK_UNIQUE\n");
    }
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 184 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tmodificadores_acceso: TOK_HIDDEN\n");
    }
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 189 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tmodificadores_acceso: TOK_SECRET\n");
    }
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 194 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tmodificadores_acceso: TOK_EXPOSED\n");
    }
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 199 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tmodificadores_acceso: TOK_UNIQUE\n");
    }
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 204 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tmodificadores_acceso:\n");
    }
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 210 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tclase: clase_escalar\n");
        (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
    }
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 216 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tclase: clase_vector\n");
    }
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 221 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tclase: clase_objeto\n");
    }
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 227 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tdeclaracion_clase: modificadores_clase TOK_CLASS TOK_IDENTIFICADOR inherits identificadores '{' declaraciones funciones '}'\n");
    }
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 232 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tdeclaracion_clase: modificadores_clase TOK_CLASS TOK_IDENTIFICADOR inherits identificadores '{' declaraciones funciones '}'\n");
    }
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 237 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tdeclaracion_clase: modificadores_clase TOK_CLASS TOK_IDENTIFICADOR '{' declaraciones funciones '}'\n");
    }
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 243 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tmodificadores_clase:\n");
    }
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 249 "omicron.y" /* yacc.c:1646  */
    {
       //fprintf(fout, ";R:\tclase_escalar: tipo\n");
       (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
    }
#line 1731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 256 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\ttipo: TOK_INT\n");
        (yyval.atributos).tipo = ENTERO;
        tipo_declaracion = ENTERO;
    }
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 263 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\ttipo: TOK_BOOLEAN\n");
        (yyval.atributos).tipo = BOOLEAN;
        tipo_declaracion = BOOLEAN;
    }
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 271 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tclase_objeto: '{' TOK_IDENTIFICADOR '}'\n");
    }
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 277 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tclase_vector: TOK_ARRAY tipo '[' constante_entera ']'\n");
    }
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 283 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tidentificadores: TOK_IDENTIFICADOR\n");
    }
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 288 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tidentificadores: TOK_IDENTIFICADOR ',' identificadores\n");
    }
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 294 "omicron.y" /* yacc.c:1646  */
    {
        /* Aqui solo se accede al declarar varibles */
        (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;

    }
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 301 "omicron.y" /* yacc.c:1646  */
    {
      (yyval.atributos).tipo = (yyvsp[-2].atributos).tipo;
    }
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 307 "omicron.y" /* yacc.c:1646  */
    {
  (yyval.atributos).direcciones = 1;
  (yyvsp[0].atributos).tipo = tipo_declaracion;

  printf("entro en una declaracion de variable (%s) [%d]\n", (yyvsp[0].atributos).lexema, (yyvsp[0].atributos).tipo);
  (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
  declarar_variable(fout, (yyvsp[0].atributos).lexema, (yyvsp[0].atributos).tipo, 1);
  // TODO: insertar en tabla simbolos
  insertarTablaSimbolosAmbitos(tabla_main, "main", (yyvsp[0].atributos).lexema, ESCALAR, (yyvsp[0].atributos).tipo, (yyvsp[0].atributos).direcciones, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, NINGUNO, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
}
#line 1816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 319 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tfunciones: funcion funciones\n");
    }
#line 1824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 324 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tfunciones:\n");
    }
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 330 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tfuncion: TOK_FUNCTION modificadores_acceso tipo_retorno TOK_IDENTIFICADOR '(' parametros_funcion ')' '{' declaraciones_funcion sentencias '}'\n");
    }
#line 1840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 336 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\ttipo_retorno: TOK_NONE\n");
    }
#line 1848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 341 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\ttipo_retorno: tipo\n");
    }
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 346 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\ttipo_retorno: clase_objeto\n");
    }
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 352 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tinherits: TOK_INHERITS\n");
    }
#line 1872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 358 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tparametros_funcion: parametro_funcion resto_parametros_funcion\n");
    }
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 363 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tparametros_funcion:\n");
    }
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 369 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tresto_parametros_funcion: ';' parametro_funcion resto_parametros_funcion\n");
    }
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 374 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tresto_parametros_funcion:\n");
    }
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 380 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tparametro_funcion: tipo TOK_IDENTIFICADOR\n");
    }
#line 1912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 385 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tparametro_funcion: clase_objeto TOK_IDENTIFICADOR\n");
    }
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 391 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tdeclaraciones_funcion: declaraciones\n");
    }
#line 1928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 396 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tdeclaraciones_funcion:\n");
    }
#line 1936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 402 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tsentencias: sentencia\n");
    }
#line 1944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 407 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tsentencias: sentencia sentencias\n");
    }
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 413 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tsentencia: sentencia_simple ';'\n");
    }
#line 1960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 418 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tsentencia: bloque\n");
    }
#line 1968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 424 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tsentencia_simple: asignacion\n");
    }
#line 1976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 429 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tsentencia_simple: lectura\n");
    }
#line 1984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 434 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tsentencia_simple: escritura\n");
    }
#line 1992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 439 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tsentencia_simple: retorno_funcion\n");
    }
#line 2000 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 444 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tsentencia_simple: identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");
    }
#line 2008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 449 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tsentencia_simple: TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");
    }
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 454 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tsentencia_simple: destruir_objeto\n");
    }
#line 2024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 460 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tdestruir_objeto: TOK_DISCARD TOK_IDENTIFICADOR\n");
    }
#line 2032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 466 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tbloque: condicional\n");
    }
#line 2040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 471 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tbloque: bucle\n");
    }
#line 2048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 477 "omicron.y" /* yacc.c:1646  */
    {
        //Buscamos en la tabla de simbolos el tipo de $1
        if (buscarIdNoCualificado(NULL, tabla_main, (yyvsp[-2].atributos).lexema, "main", &elem, nombre_ambito_encontrado) == OK) {
            (yyvsp[-2].atributos).tipo = elem->tipo;
        }
        else {
            printf("Error: Variable no encontrada\n");
        }

        if ((yyvsp[-2].atributos).tipo != (yyvsp[0].atributos).tipo) {
          printf("Error: Variables distintas\n");
        }

        char aux[50];
        if ((yyvsp[0].atributos).direcciones == 0) {
            sprintf(aux, "%d", (yyvsp[0].atributos).valor_entero);

        }
        //escribir_operando(fout, aux, $3.direcciones);
        asignar(fout, (yyvsp[-2].atributos).lexema, (yyvsp[0].atributos).direcciones);
    }
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 500 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo != (yyvsp[0].atributos).tipo) {
            printf("Error: tipos incompatibles");
        }
    }
#line 2084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 507 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tasignacion: elemento_vector '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");
    }
#line 2092 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 512 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tasignacion: TOK_IDENTIFICADOR '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");
    }
#line 2100 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 517 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tasignacion: identificador_clase '.' TOK_IDENTIFICADOR '=' exp\n");
    }
#line 2108 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 523 "omicron.y" /* yacc.c:1646  */
    {
        if (buscarIdNoCualificado(NULL, tabla_main, (yyvsp[-3].atributos).lexema, "main", &elem, nombre_ambito_encontrado) == OK) {
            (yyvsp[-3].atributos).tipo = elem->tipo;
            if (elem->clase != VECTOR) {
                printf("Error: no es vector");
            }
            if ((yyvsp[-1].atributos).tipo != ENTERO) {
                printf("Error: el indice debe ser de tipo entero");
            }

            (yyval.atributos).tipo = elem->tipo;
            (yyval.atributos).direcciones = 1;
            //Comprobacion indice, 0<i<64
        }
        else {
            printf("Error: Variable no encontrada\n");
        }
    }
#line 2131 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 544 "omicron.y" /* yacc.c:1646  */
    {
        fin_if_else(fout, (yyvsp[-4].atributos).etiqueta);
    }
#line 2139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 550 "omicron.y" /* yacc.c:1646  */
    {
        (yyval.atributos).etiqueta = (yyvsp[-2].atributos).etiqueta;

        medio_if_else(fout, (yyvsp[-2].atributos).etiqueta);
    }
#line 2149 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 558 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo != BOOLEAN) {
            printf("Error: condicion del if no booleano");
        }
        (yyval.atributos).etiqueta = etiqueta;
        etiqueta++;

        inicio_if_else(fout, (yyval.atributos).etiqueta, (yyvsp[-2].atributos).direcciones);
    }
#line 2163 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 570 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tbucle: TOK_WHILE '(' exp ')' '{' sentencias '}'\n");
    }
#line 2171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 576 "omicron.y" /* yacc.c:1646  */
    {
        if (buscarIdNoCualificado(NULL, tabla_main, (yyvsp[0].atributos).lexema, "main", &elem, nombre_ambito_encontrado) != OK) {
            printf("Error: Elem no encontrado\n");
        } else {
            if (elem->clase == FUNCION || elem->clase == VECTOR) {
                printf("Error: no se puede imprimir funciones ni vectores\n");
            }

            escribir_operando(fout, (yyvsp[0].atributos).lexema, (yyvsp[0].atributos).direcciones);
            leer(fout, (yyvsp[0].atributos).lexema, elem->tipo);
        }
    }
#line 2188 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 590 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tlectura: TOK_SCANF elemento_vector\n");
    }
#line 2196 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 596 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[0].atributos).direcciones == 1) {
            if(buscarIdNoCualificado(NULL, tabla_main, (yyvsp[0].atributos).lexema, "main", &elem, nombre_ambito_encontrado) == OK) {
                escribir_operando(fout, (yyvsp[0].atributos).lexema, (yyvsp[0].atributos).direcciones);
                escribir(fout, (yyvsp[0].atributos).direcciones, elem->tipo);
            }
            else {
                printf("Error: Elem no encontrado\n");
            }
        }
        else{
            escribir(fout, (yyvsp[0].atributos).direcciones, (yyvsp[0].atributos).tipo);
        }


    }
#line 2217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 615 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tretorno_funcion: TOK_RETURN exp\n");
    }
#line 2225 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 620 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tretorno_funcion: TOK_RETURN TOK_NONE\n");
    }
#line 2233 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 626 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN) {
            printf("Error: La suma requiere que ambos operandos sean numeros");
        }

        printf("op1: %s tipo(%d) direc(%d)\n", (yyvsp[-2].atributos).lexema, (yyvsp[-2].atributos).tipo, (yyvsp[-2].atributos).direcciones);
        printf("op2: %s tipo(%d) direc(%d)\n", (yyvsp[0].atributos).lexema, (yyvsp[0].atributos).tipo, (yyvsp[0].atributos).direcciones);

        if ((yyvsp[-2].atributos).direcciones) {
            //escribir_operando(fout, $1.lexema, $1.direcciones);
        }
        if ((yyvsp[0].atributos).direcciones) {
            //escribir_operando(fout, $3.lexema, $3.direcciones);
        }

        sumar(fout, (yyvsp[-2].atributos).direcciones, (yyvsp[0].atributos).direcciones);

        (yyval.atributos).tipo = ENTERO;
        (yyval.atributos).direcciones = 0;

    }
#line 2259 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 649 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN) {
            printf("Error: La resta requiere que ambos operandos sean numeros");
        }
        (yyval.atributos).tipo = ENTERO;
        (yyval.atributos).direcciones = 0;
    }
#line 2271 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 658 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN) {
            printf("Error: La division requiere que ambos operandos sean numeros");
        }
        if ((yyvsp[0].atributos).tipo == 0) {
            printf("Error: La division entre 0 no se permite");
        }
        (yyval.atributos).tipo = ENTERO;
        (yyval.atributos).direcciones = 0;
    }
#line 2286 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 670 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN) {
            printf("Error: La multiplicacion requiere que ambos operandos sean numeros");
        }
        (yyval.atributos).tipo = ENTERO;
        (yyval.atributos).direcciones = 0;
    }
#line 2298 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 679 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[0].atributos).tipo == BOOLEAN) {
            printf("Error: El cambio de signo requiere operandos que sean numeros");
        }
        (yyval.atributos).tipo = ENTERO;
        (yyval.atributos).direcciones = 0;
    }
#line 2310 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 688 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo == ENTERO || (yyvsp[0].atributos).tipo == ENTERO) {
            printf("Error: La conjuncion requiere operandos que sean booleans");
        }
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).direcciones = 0;
    }
#line 2322 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 697 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo == ENTERO || (yyvsp[0].atributos).tipo == ENTERO) {
            printf("Error: La disyuncion requiere operandos que sean booleans");
        }
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).direcciones = 0;
    }
#line 2334 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 706 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[0].atributos).tipo == ENTERO) {
            printf("Error: La negacion requiere operandos que sean booleans");
        }
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).direcciones = 0;
    }
#line 2346 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 715 "omicron.y" /* yacc.c:1646  */
    {
      if (buscarIdNoCualificado(NULL, tabla_main, (yyvsp[0].atributos).lexema, "main", &elem, nombre_ambito_encontrado) == OK){
          (yyvsp[0].atributos).tipo = elem->tipo;
      }
      else {
          printf("Error:Variable no encontrada\n");
      }
      //diapo90 gen
      escribir_operando(fout, (yyvsp[0].atributos).lexema, 1);

      //TODO comprobar que no sea de categoria funcion ni clase vector
      (yyval.atributos).tipo = elem->tipo;
      (yyval.atributos).direcciones = 1;
    }
#line 2365 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 731 "omicron.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
        (yyval.atributos).direcciones = (yyvsp[0].atributos).direcciones;
    }
#line 2374 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 737 "omicron.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;
        (yyval.atributos).direcciones = (yyvsp[-1].atributos).direcciones;
    }
#line 2383 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 743 "omicron.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;
        (yyval.atributos).direcciones = (yyvsp[-1].atributos).direcciones;
    }
#line 2392 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 749 "omicron.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
        (yyval.atributos).direcciones = (yyvsp[0].atributos).direcciones;
    }
#line 2401 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 755 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\texp: TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");
    }
#line 2409 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 760 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\texp: identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");
    }
#line 2417 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 765 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\texp: identificador_clase '.' TOK_IDENTIFICADOR\n");
    }
#line 2425 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 772 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tidentificador_clase: TOK_IDENTIFICADOR\n");
    }
#line 2433 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 777 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tidentificador_clase: TOK_ITSELF\n");
    }
#line 2441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 783 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tlista_expresiones: exp resto_lista_expresiones\n");
    }
#line 2449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 788 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tlista_expresiones:\n");
    }
#line 2457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 794 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tresto_lista_expresiones: ',' exp resto_lista_expresiones\n");
    }
#line 2465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 799 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tlista_expresiones:\n");
    }
#line 2473 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 805 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN) {
            printf("Error: La division requiere que ambos operandos sean numeros");
        }
        if ((yyvsp[-2].atributos).direcciones == 1) {
            //escribir_operando(fout, $1.lexema, $1.direcciones);
        }
        if ((yyvsp[0].atributos).direcciones == 1) {
            //escribir_operando(fout, $3.lexema, $3.direcciones);
        }

        igual(fout, (yyvsp[-2].atributos).direcciones, (yyvsp[0].atributos).direcciones, etiqueta);
        etiqueta++;

        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).direcciones = 0;
    }
#line 2495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 824 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN) {
            printf("Error: La division requiere que ambos operandos sean numeros");
        }
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).direcciones = 0;
    }
#line 2507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 833 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN) {
            printf("Error: La division requiere que ambos operandos sean numeros");
        }
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).direcciones = 0;
    }
#line 2519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 842 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN) {
            printf("Error: La division requiere que ambos operandos sean numeros");
        }
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).direcciones = 0;
    }
#line 2531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 851 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN) {
            printf("Error: La division requiere que ambos operandos sean numeros");
        }
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).direcciones = 0;
    }
#line 2543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 860 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN) {
            printf("Error: La division requiere que ambos operandos sean numeros");
        }
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).direcciones = 0;
    }
#line 2555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 870 "omicron.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
        (yyval.atributos).direcciones = (yyvsp[0].atributos).direcciones;
    }
#line 2564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 876 "omicron.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
        (yyval.atributos).direcciones = (yyvsp[0].atributos).direcciones;
    }
#line 2573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 883 "omicron.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).direcciones = 0;
        escribir_operando(fout, "1", 0);
    }
#line 2583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 890 "omicron.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).direcciones = 0;
        escribir_operando(fout, "0", 0);
    }
#line 2593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 898 "omicron.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = ENTERO;
        (yyval.atributos).direcciones = 0;
        sprintf((yyvsp[0].atributos).lexema, "%d", (yyvsp[0].atributos).valor_entero);
        escribir_operando(fout, (yyvsp[0].atributos).lexema, 0);
    }
#line 2604 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2608 "y.tab.c" /* yacc.c:1646  */
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
#line 906 "omicron.y" /* yacc.c:1906  */


int yyerror(char* s) {
    if (!flag_error)
    {
        //fprintf(stderr, "ERROR SINTÁCTICO:%d:%d\n", fila, columna);
    }
    flag_error = 0;
    return -1;
}
