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

extern int columna;
extern int fila;
extern int yylex();
extern FILE *yyin;
extern FILE *fout;
extern int flag_error;

#line 79 "y.tab.c" /* yacc.c:339  */

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
#line 14 "omicron.y" /* yacc.c:355  */

    tipo_atributos atributos;

#line 235 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 252 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   272

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  219

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
       0,    92,    92,    97,   103,   109,   118,   123,   129,   134,
     140,   145,   150,   155,   160,   165,   170,   176,   181,   186,
     191,   197,   202,   207,   214,   219,   226,   232,   239,   245,
     251,   256,   262,   271,   277,   283,   289,   294,   300,   305,
     310,   316,   322,   328,   333,   339,   344,   349,   355,   361,
     366,   371,   377,   382,   388,   393,   398,   403,   408,   413,
     418,   424,   430,   435,   441,   453,   458,   463,   468,   474,
     480,   485,   491,   497,   502,   508,   518,   523,   529,   539,
     549,   562,   572,   582,   592,   602,   612,   617,   623,   629,
     634,   639,   644,   649,   656,   661,   667,   673,   678,   684,
     689,   694,   699,   704,   709,   714,   720,   725,   731,   736,
     742
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
  "bloque", "asignacion", "elemento_vector", "condicional", "bucle",
  "lectura", "escritura", "retorno_funcion", "exp", "identificador_clase",
  "lista_expresiones", "resto_lista_expresiones", "comparacion",
  "constante", "constante_logica", "constante_entera", YY_NULLPTR
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

#define YYPACT_NINF -90

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-90)))

#define YYTABLE_NINF -95

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -8,   -90,    13,   -38,   -90,   166,     6,    16,    25,   -90,
      14,   -90,   166,    29,   -90,   -90,   -90,   204,   230,    14,
      14,   -90,   -90,   -90,    -3,    19,    28,   -12,    35,   -90,
     -90,   -90,   -90,     9,    37,   -90,    62,    -5,     2,    49,
     103,     4,    -6,   230,    21,   -90,   -90,   -90,    23,   -90,
     -90,   -90,   -90,   -90,    17,   -90,   230,    31,    48,   -90,
      22,    46,   -90,    87,   -90,   -90,   -90,    88,   -90,   -90,
      42,   -90,   -90,   -90,   103,   103,   103,   -90,   210,    47,
     -90,   -90,   -90,   103,   103,    55,   -90,   210,   103,   103,
      -2,   -90,   -90,   -90,    65,    96,    69,    90,   -90,   -90,
      28,     0,    68,   103,   -90,   -90,   173,    72,   103,   103,
     103,   103,   103,   103,   109,   157,   178,   205,    95,    73,
     115,   210,   122,   210,    24,   -90,    89,   -90,   -90,   204,
     133,    -1,    94,   103,   103,   103,   103,   -90,   103,   103,
     -90,   -22,   -90,   -22,   -22,   -90,   -90,    97,   104,   105,
     -90,   103,   -90,   -90,   101,   106,   103,   103,   -90,    14,
     110,   114,   150,   156,   116,   129,   -90,   210,   210,   210,
     210,   210,   210,   103,   230,   230,    95,   103,   103,   127,
     210,   135,   133,   132,   -90,   -90,   138,    -1,   -90,   139,
     146,   147,   -90,   152,   153,   -90,   -90,   -90,    14,   160,
     166,   129,   -90,   177,   -90,   -90,   -90,   161,   -90,   -90,
     230,   -90,   163,   -90,   164,   230,   -90,   170,   -90
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,     0,     1,     5,    13,    14,    15,    16,
      36,     5,     6,    24,    10,    11,    12,    17,     0,    36,
      36,     7,    26,    27,     0,     0,     0,     0,     0,    18,
      25,    20,    19,     0,     0,    95,     0,     0,     0,     0,
       0,    94,     0,    50,     0,    60,    53,    54,     0,    62,
      63,    55,    56,    57,     0,    35,     0,     0,     0,    34,
       0,    32,     9,     0,    38,    39,    40,     0,    61,    77,
      86,   110,   109,   108,     0,     0,     0,    90,    76,     0,
      87,   106,   107,     0,     0,    73,    74,    75,     0,    97,
       0,     3,    51,    52,     0,     0,     0,     0,    28,     8,
       0,     0,     0,    97,    82,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    99,     0,
       0,    64,     0,    65,     0,     2,     0,    33,    41,    17,
       0,    43,     0,     0,     0,     0,     0,    88,     0,     0,
      89,    84,    83,    78,    79,    81,    80,    93,     0,     0,
      69,     0,    96,    59,     0,     0,    97,     0,    29,    36,
      30,     0,     0,     0,     0,    45,    91,   100,   101,   102,
     103,   104,   105,    97,     0,     0,    99,    97,    97,     0,
      68,     0,     0,    17,    46,    47,     0,     0,    42,     0,
       0,     0,    98,     0,     0,    58,    23,    31,    36,     0,
      49,    45,    92,    70,    72,    67,    66,     0,    22,    48,
       0,    44,     0,    21,     0,     0,    37,     0,    71
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -90,   -90,   -90,   238,   -11,   -90,   233,   -90,   -90,   -90,
     -90,    15,    10,   -90,    70,   151,   -90,   -15,   -90,   -90,
     -90,   -90,    53,    78,   -90,   -40,   -90,   -90,   -90,   -90,
     -90,   -18,   -90,   -90,   -90,   -90,   -90,   -30,   -16,   -89,
      83,   -90,   -90,   -90,   175
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    10,    11,    12,    13,    26,    27,    28,
      29,   162,   163,    32,   161,    60,    61,    18,    19,    67,
     130,   164,   188,   165,   210,    42,    43,    44,    45,    46,
      47,    77,    49,    50,    51,    52,    53,   118,    79,   119,
     152,   107,    80,    81,    82
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      48,    21,    54,    92,    55,    56,    78,   120,   128,    35,
      87,     1,   109,     4,   132,    64,    96,    22,    23,    22,
      23,    86,    14,    31,     5,    48,    70,    54,    30,    22,
      23,    17,    15,    71,    72,    73,   112,   113,    48,    57,
      54,    16,    63,    66,   104,   105,   106,    58,    65,    22,
      23,    24,    62,   115,   116,    74,    59,    91,   117,    75,
     121,    25,   129,    83,   123,    68,    76,   179,    69,    88,
      84,    25,    89,    35,   122,    90,    35,    85,   141,   142,
     143,   144,   145,   146,   189,    93,    99,    95,   193,   194,
      70,    25,   156,    70,    94,   157,    97,    71,    72,    73,
      71,    72,    73,   167,   168,   169,   170,    88,   171,   172,
     103,    98,   -94,   100,    35,   101,   102,   114,   159,    74,
      88,   176,    74,    75,   124,    71,    75,   180,   108,   109,
      76,    70,   125,    76,   190,   191,   131,   147,    71,    72,
      73,   140,   153,   154,   181,     6,     7,     8,     9,    17,
     155,   110,   111,   112,   113,   158,    48,    48,    54,    54,
      74,   160,   151,   166,    75,   173,   174,   175,   199,   177,
     214,    76,   198,   -17,   178,   217,   183,   182,   184,     6,
       7,     8,     9,   207,   185,   186,   -17,   -17,   -17,   209,
     108,   109,    48,   187,    54,   -36,   195,    48,   196,    54,
     200,   212,   133,   134,   135,   136,   108,   109,   202,   203,
     204,   108,   109,   110,   111,   112,   113,     6,     7,     8,
       9,   205,   206,   208,   213,   215,   148,   216,   -17,   110,
     111,   112,   113,   218,   110,   111,   112,   113,   108,   109,
      34,    35,   137,   108,   109,   138,   139,   149,    36,    20,
      33,   127,   197,    37,   211,    38,    39,    40,    41,   192,
       0,   110,   111,   112,   113,   201,   110,   111,   112,   113,
       0,   150,   126
};

static const yytype_int16 yycheck[] =
{
      18,    12,    18,    43,    19,    20,    36,     9,     8,    11,
      40,    19,    34,     0,   103,     6,    56,    20,    21,    20,
      21,    39,    16,    13,    62,    43,    28,    43,    13,    20,
      21,    17,    16,    35,    36,    37,    58,    59,    56,    24,
      56,    16,     7,    33,    74,    75,    76,    28,    33,    20,
      21,    22,    64,    83,    84,    57,    28,    63,    88,    61,
      90,    62,    62,    68,    94,    28,    68,   156,     6,    65,
      68,    62,    68,    11,     9,    71,    11,    28,   108,   109,
     110,   111,   112,   113,   173,    64,    64,    70,   177,   178,
      28,    62,    68,    28,    71,    71,    65,    35,    36,    37,
      35,    36,    37,   133,   134,   135,   136,    65,   138,   139,
      68,    63,    70,    67,    11,    28,    28,    70,   129,    57,
      65,   151,    57,    61,    28,    35,    61,   157,    33,    34,
      68,    28,    63,    68,   174,   175,    68,    28,    35,    36,
      37,    69,    69,    28,   159,    13,    14,    15,    16,    17,
      28,    56,    57,    58,    59,    66,   174,   175,   174,   175,
      57,    28,    67,    69,    61,    68,    62,    62,   183,    68,
     210,    68,   183,     7,    68,   215,    62,    67,    28,    13,
      14,    15,    16,   198,    28,    69,    20,    21,    22,   200,
      33,    34,   210,    64,   210,    63,    69,   215,    63,   215,
      62,    24,    29,    30,    31,    32,    33,    34,    69,    63,
      63,    33,    34,    56,    57,    58,    59,    13,    14,    15,
      16,    69,    69,    63,    63,    62,    69,    63,    62,    56,
      57,    58,    59,    63,    56,    57,    58,    59,    33,    34,
      10,    11,    69,    33,    34,    72,    73,    69,    18,    11,
      17,   100,   182,    23,   201,    25,    26,    27,    28,   176,
      -1,    56,    57,    58,    59,   187,    56,    57,    58,    59,
      -1,    66,    97
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
     107,   108,   109,   110,   112,    91,    91,    85,    28,    28,
      89,    90,    64,     7,     6,    85,    86,    93,    28,     6,
      28,    35,    36,    37,    57,    61,    68,   105,   111,   112,
     116,   117,   118,    68,    68,    28,   105,   111,    65,    68,
      71,    63,    99,    64,    71,    70,    99,    65,    63,    64,
      67,    28,    28,    68,   111,   111,   111,   115,    33,    34,
      56,    57,    58,    59,    70,   111,   111,   111,   111,   113,
       9,   111,     9,   111,    28,    63,   118,    89,     8,    62,
      94,    68,   113,    29,    30,    31,    32,    69,    72,    73,
      69,   111,   111,   111,   111,   111,   111,    28,    69,    69,
      66,    67,   114,    69,    28,    28,    68,    71,    66,    78,
      28,    88,    85,    86,    95,    97,    69,   111,   111,   111,
     111,   111,   111,    68,    62,    62,   111,    68,    68,   113,
     111,    91,    67,    62,    28,    28,    69,    64,    96,   113,
      99,    99,   114,   113,   113,    69,    63,    88,    78,    91,
      62,    97,    69,    63,    63,    69,    69,    91,    63,    78,
      98,    96,    24,    63,    99,    62,    63,    99,    63
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
     106,   106,   107,   108,   108,   109,   110,   110,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   112,   112,   113,   113,   114,   114,
     115,   115,   115,   115,   115,   115,   116,   116,   117,   117,
     118
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
       7,    11,     7,     2,     2,     2,     2,     2,     3,     3,
       3,     3,     2,     3,     3,     2,     1,     1,     3,     3,
       1,     4,     6,     3,     1,     1,     2,     0,     3,     0,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1
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
#line 93 "omicron.y" /* yacc.c:1646  */
    {
        escribir_fin(fout);
    }
#line 1513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 98 "omicron.y" /* yacc.c:1646  */
    {
        escribir_fin(fout);
    }
#line 1521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 103 "omicron.y" /* yacc.c:1646  */
    {
    /* Inic tabla simbolos */
    escribir_subseccion_data(fout);
    escribir_cabecera_bss(fout);    
}
#line 1531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 109 "omicron.y" /* yacc.c:1646  */
    {
    
    //getVarsTS
    //Declararlas

    escribir_segmento_codigo(fout);
    escribir_inicio_main(fout);
}
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 119 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tdeclaraciones: declaracion\n");
    }
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 124 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tdeclaraciones: declaracion, declaraciones\n");
    }
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 130 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tdeclaracion: modificadores_acceso clase identificadores ';'\n");
    }
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 135 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tdeclaracion: modificadores_acceso declaracion_clase ';'\n");
    }
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 141 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tmodificadores_acceso: TOK_HIDDEN TOK_UNIQUE\n");
    }
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 146 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tmodificadores_acceso: TOK_SECRET TOK_UNIQUE\n");
    }
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 151 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tmodificadores_acceso: TOK_EXPOSED TOK_UNIQUE\n");
    }
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 156 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tmodificadores_acceso: TOK_HIDDEN\n");
    }
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 161 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tmodificadores_acceso: TOK_SECRET\n");
    }
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 166 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tmodificadores_acceso: TOK_EXPOSED\n");
    }
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 171 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tmodificadores_acceso: TOK_UNIQUE\n");
    }
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 176 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tmodificadores_acceso:\n");
    }
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 182 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tclase: clase_escalar\n");
    }
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 187 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tclase: clase_vector\n");
    }
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 192 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tclase: clase_objeto\n");
    }
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 198 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tdeclaracion_clase: modificadores_clase TOK_CLASS TOK_IDENTIFICADOR inherits identificadores '{' declaraciones funciones '}'\n");
    }
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 203 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tdeclaracion_clase: modificadores_clase TOK_CLASS TOK_IDENTIFICADOR inherits identificadores '{' declaraciones funciones '}'\n");
    }
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 208 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tdeclaracion_clase: modificadores_clase TOK_CLASS TOK_IDENTIFICADOR '{' declaraciones funciones '}'\n");
    }
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 214 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tmodificadores_clase:\n");
    }
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 220 "omicron.y" /* yacc.c:1646  */
    {
       //fprintf(fout, ";R:\tclase_escalar: tipo\n"); 
       (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
    }
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 227 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\ttipo: TOK_INT\n");
        (yyval.atributos).tipo = ENTERO;
    }
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 233 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\ttipo: TOK_BOOLEAN\n");
        (yyval.atributos).tipo = BOOLEAN;
    }
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 240 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tclase_objeto: '{' TOK_IDENTIFICADOR '}'\n");
    }
#line 1731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 246 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tclase_vector: TOK_ARRAY tipo '[' constante_entera ']'\n");
    }
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 252 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tidentificadores: TOK_IDENTIFICADOR\n");
    }
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 257 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tidentificadores: TOK_IDENTIFICADOR ',' identificadores\n");
    }
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 263 "omicron.y" /* yacc.c:1646  */
    {
        /* Aqui solo se accede al declarar varibles */
        declarar_variable(fout, (yyvsp[0].atributos).lexema, (yyvsp[0].atributos).tipo, 1);
        // TODO: insertar en tabla simbolos
        
        
    }
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 272 "omicron.y" /* yacc.c:1646  */
    {
      /* Preguntar a Ortega*/
    }
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 278 "omicron.y" /* yacc.c:1646  */
    {
    strcpy((yyval.atributos).lexema, (yyvsp[0].atributos).lexema);
    (yyval.atributos).direcciones = (yyvsp[0].atributos).direcciones;
}
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 284 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tfunciones: funcion funciones\n");
    }
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 289 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tfunciones:\n");
    }
#line 1800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 295 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tfuncion: TOK_FUNCTION modificadores_acceso tipo_retorno TOK_IDENTIFICADOR '(' parametros_funcion ')' '{' declaraciones_funcion sentencias '}'\n");
    }
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 301 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\ttipo_retorno: TOK_NONE\n");
    }
#line 1816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 306 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\ttipo_retorno: tipo\n");
    }
#line 1824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 311 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\ttipo_retorno: clase_objeto\n");
    }
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 317 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tinherits: TOK_INHERITS\n");
    }
#line 1840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 323 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tparametros_funcion: parametro_funcion resto_parametros_funcion\n");
    }
#line 1848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 328 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tparametros_funcion:\n");
    }
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 334 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tresto_parametros_funcion: ';' parametro_funcion resto_parametros_funcion\n");
    }
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 339 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tresto_parametros_funcion:\n");
    }
#line 1872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 345 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tparametro_funcion: tipo TOK_IDENTIFICADOR\n");
    }
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 350 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tparametro_funcion: clase_objeto TOK_IDENTIFICADOR\n");   
    }
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 356 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tdeclaraciones_funcion: declaraciones\n");
    }
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 361 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tdeclaraciones_funcion:\n");
    }
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 367 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tsentencias: sentencia\n");
    }
#line 1912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 372 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tsentencias: sentencia sentencias\n");
    }
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 378 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tsentencia: sentencia_simple ';'\n");
    }
#line 1928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 383 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tsentencia: bloque\n");
    }
#line 1936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 389 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tsentencia_simple: asignacion\n");
    }
#line 1944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 394 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tsentencia_simple: lectura\n");
    }
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 399 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tsentencia_simple: escritura\n");
    }
#line 1960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 404 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tsentencia_simple: retorno_funcion\n");
    }
#line 1968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 409 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tsentencia_simple: identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");
    }
#line 1976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 414 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tsentencia_simple: TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");
    }
#line 1984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 419 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tsentencia_simple: destruir_objeto\n");
    }
#line 1992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 425 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tdestruir_objeto: TOK_DISCARD TOK_IDENTIFICADOR\n");
    }
#line 2000 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 431 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tbloque: condicional\n");
    }
#line 2008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 436 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tbloque: bucle\n");
    }
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 442 "omicron.y" /* yacc.c:1646  */
    {
        // TODO: comprobar tipos
        //fprintf(fout, ";R:\tasignacion: TOK_IDENTIFICADOR '=' exp\n");
        char aux[50];
        if ((yyvsp[0].atributos).direcciones == 0) {
            sprintf(aux, "%d", (yyvsp[0].atributos).valor_entero);
        }
        escribir_operando(fout, aux, (yyvsp[0].atributos).direcciones);
        asignar(fout, (yyvsp[-2].atributos).lexema, (yyvsp[-2].atributos).direcciones);
    }
#line 2031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 454 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tasignacion: elemento_vector '=' exp\n");
    }
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 459 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tasignacion: elemento_vector '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");
    }
#line 2047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 464 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tasignacion: TOK_IDENTIFICADOR '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");
    }
#line 2055 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 469 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tasignacion: identificador_clase '.' TOK_IDENTIFICADOR '=' exp\n");
    }
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 475 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\telemento_vector: TOK_IDENTIFICADOR '[' exp ']'\n");
    }
#line 2071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 481 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tcondicional: TOK_IF '(' exp ')' '{' sentencias '}'\n");
    }
#line 2079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 486 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tcondicional: TOK_IF '(' exp ')' '{' sentencias '}' TOK_ELSE '{' sentencias '}'\n");
    }
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 492 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tbucle: TOK_WHILE '(' exp ')' '{' sentencias '}'\n");
    }
#line 2095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 498 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tlectura: TOK_SCANF TOK_IDENTIFICADOR\n");
    }
#line 2103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 503 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tlectura: TOK_SCANF elemento_vector\n");
    }
#line 2111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 509 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tescritura: TOK_PRINTF exp\n");
        printf("--------> %d\n", (yyvsp[0].atributos).tipo);
        //$2.tipo = ENTERO;
        escribir_operando(fout, (yyvsp[0].atributos).lexema, (yyvsp[0].atributos).direcciones);
        escribir(fout, (yyvsp[0].atributos).direcciones, (yyvsp[0].atributos).tipo);
    }
#line 2123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 519 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tretorno_funcion: TOK_RETURN exp\n");
    }
#line 2131 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 524 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tretorno_funcion: TOK_RETURN TOK_NONE\n");
    }
#line 2139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 530 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\texp: exp '+' exp\n");
        if ((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN) {
            //sprintf(msg, "La suma requiere que ambos operandos sean numeros");
        }
        (yyval.atributos).tipo = ENTERO;
        (yyval.atributos).valor_entero = (yyvsp[-2].atributos).valor_entero + (yyvsp[0].atributos).valor_entero;
    }
#line 2152 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 540 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\texp: exp '-' exp\n");
        if ((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN) {
            //sprintf(msg, "La resta requiere que ambos operandos sean numeros");
        }
        (yyval.atributos).tipo = ENTERO;
        (yyval.atributos).valor_entero = (yyvsp[-2].atributos).valor_entero - (yyvsp[0].atributos).valor_entero;
    }
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 550 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\texp: exp '/' exp\n");
        if ((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN) {
            //sprintf(msg, "La suma requiere que ambos operandos sean numeros");
        }
        if ((yyvsp[0].atributos).tipo == 0) {
            //sprintf(msg, "La division entre 0 no se permite");
        }
        (yyval.atributos).tipo = ENTERO;
        (yyval.atributos).valor_entero = (yyvsp[-2].atributos).valor_entero + (yyvsp[0].atributos).valor_entero;
    }
#line 2181 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 563 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\texp: exp '*' exp\n");
        if ((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN) {
            //sprintf(msg, "La multiplicacion requiere que ambos operandos sean numeros");
        }
        (yyval.atributos).tipo = ENTERO;
        (yyval.atributos).valor_entero = (yyvsp[-2].atributos).valor_entero * (yyvsp[0].atributos).valor_entero;
    }
#line 2194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 573 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\texp: '-' exp\n");
        if ((yyvsp[0].atributos).tipo == BOOLEAN) {
            //sprintf(msg, "El cambio de signo requiere operandos que sean numeros");
        }
        (yyval.atributos).tipo = ENTERO;
        (yyval.atributos).valor_entero = - (yyvsp[0].atributos).valor_entero;
    }
#line 2207 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 583 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\texp: exp TOK_AND exp\n");
        if ((yyvsp[-2].atributos).tipo == ENTERO || (yyvsp[0].atributos).tipo == ENTERO) {
            //sprintf(msg, "La conjuncion requiere operandos que sean booleans");
        }
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).valor_entero = (yyvsp[-2].atributos).valor_entero && (yyvsp[0].atributos).valor_entero;
    }
#line 2220 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 593 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\texp: exp TOK_OR exp\n");
        if ((yyvsp[-2].atributos).tipo == ENTERO || (yyvsp[0].atributos).tipo == ENTERO) {
            //sprintf(msg, "La disyuncion requiere operandos que sean booleans");
        }
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).valor_entero = (yyvsp[-2].atributos).valor_entero || (yyvsp[0].atributos).valor_entero;
    }
#line 2233 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 603 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\texp: '!' exp\n");
        if ((yyvsp[0].atributos).tipo == ENTERO) {
            //sprintf(msg, "La negacion requiere operandos que sean booleans");
        }
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).valor_entero = !((yyvsp[0].atributos).valor_entero);
    }
#line 2246 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 613 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\texp: TOK_IDENTIFICADOR\n");
    }
#line 2254 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 618 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\texp: constante\n");
        (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
    }
#line 2263 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 624 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\texp: '(' exp ')'\n");
        (yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;
    }
#line 2272 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 630 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\texp: '(' comparacion ')'\n");
    }
#line 2280 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 635 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\texp: elemento_vector\n");
    }
#line 2288 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 640 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\texp: TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");
    }
#line 2296 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 645 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\texp: identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");
    }
#line 2304 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 650 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\texp: identificador_clase '.' TOK_IDENTIFICADOR\n");
    }
#line 2312 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 657 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tidentificador_clase: TOK_IDENTIFICADOR\n");
    }
#line 2320 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 662 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tidentificador_clase: TOK_ITSELF\n");
    }
#line 2328 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 668 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tlista_expresiones: exp resto_lista_expresiones\n");
    }
#line 2336 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 673 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tlista_expresiones:\n");
    }
#line 2344 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 679 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tresto_lista_expresiones: ',' exp resto_lista_expresiones\n");
    }
#line 2352 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 684 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tlista_expresiones:\n");
    }
#line 2360 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 690 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tcomparacion: exp TOK_IGUAL exp\n");
    }
#line 2368 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 695 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tcomparacion: exp TOK_DISTINTO exp\n");
    }
#line 2376 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 700 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tcomparacion: exp TOK_MENORIGUAL exp\n");
    }
#line 2384 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 705 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tcomparacion: exp TOK_MAYORIGUAL exp\n");
    }
#line 2392 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 710 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tcomparacion: exp '<' exp\n");
    }
#line 2400 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 715 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tcomparacion: exp '>' exp\n");
    }
#line 2408 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 721 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tconstante: constante_logica\n");
    }
#line 2416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 726 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tconstante: constante_entera\n");
    }
#line 2424 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 732 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tconstante_logica: TOK_TRUE\n");
    }
#line 2432 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 737 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tconstante_logica: TOK_FALSE\n");
    }
#line 2440 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 743 "omicron.y" /* yacc.c:1646  */
    {
        //fprintf(fout, ";R:\tconstante_entera: TOK_CONSTANTE_ENTERA\n");
    }
#line 2448 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2452 "y.tab.c" /* yacc.c:1646  */
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
#line 748 "omicron.y" /* yacc.c:1906  */


int yyerror(char* s) {
    if (!flag_error) 
    {
        //fprintf(stderr, "ERROR SINTÁCTICO:%d:%d\n", fila, columna);
    }
    flag_error = 0;
    return -1;
}
