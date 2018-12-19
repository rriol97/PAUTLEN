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
#include "generacion_omicron.h"
#include "graph.h"
#include "tabla.h"

extern int columna;
extern int fila;
extern int yylex();
extern FILE *yyin;
extern FILE *fout;
extern int flag_error;

typedef struct {
    char nombre[MAX_LEN];
    char *nombre_args[MAX_LEN];
    int tipo_args[MAX_LEN];
    int nargs;
    int tipo_retorno;
} Fcn;

int tipo_id_actual;
TablaAmbito * tabla_main;
elementoTablaSimbolos * elem;
char nombre_ambito_encontrado[MAX_NAME];
int tipo_declaracion;
int etiqueta = 1;
char aux[MAX_LEN];
char msg[MAX_LEN];
int i;
int nlocalvar;
int hay_return = 0;
int flag_lista_exp = 0;

Fcn fcn;

#line 104 "y.tab.c" /* yacc.c:339  */

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
#line 39 "omicron.y" /* yacc.c:355  */

    tipo_atributos atributos;

#line 260 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 277 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   282

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  226

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
       0,   127,   127,   133,   140,   150,   155,   159,   164,   171,
     176,   180,   184,   188,   192,   196,   200,   205,   209,   214,
     218,   223,   227,   231,   237,   241,   247,   253,   260,   265,
     270,   274,   279,   286,   292,   304,   309,   313,   322,   329,
     354,   364,   368,   373,   378,   383,   388,   392,   397,   401,
     409,   414,   419,   423,   427,   432,   436,   441,   445,   449,
     453,   457,   461,   465,   470,   475,   479,   484,   506,   513,
     517,   521,   526,   547,   553,   561,   573,   579,   592,   606,
     611,   630,   636,   641,   664,   673,   685,   694,   703,   712,
     721,   730,   749,   755,   761,   767,   773,   779,   783,   789,
     794,   798,   803,   809,   813,   818,   822,   841,   850,   859,
     868,   877,   887,   893,   900,   907,   915
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
  "fn_declaracion", "fn_complete_name", "fn_name", "tipo_retorno",
  "inherits", "parametros_funcion", "resto_parametros_funcion",
  "parametro_funcion", "declaraciones_funcion", "sentencias", "sentencia",
  "sentencia_simple", "destruir_objeto", "bloque", "asignacion",
  "elemento_vector", "condicional", "if_exp_sentencias", "if_exp", "bucle",
  "bucle_inicio", "lectura", "escritura", "retorno_funcion", "exp",
  "activar_flag_lista_exp", "identificador_clase", "lista_expresiones",
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

#define YYPACT_NINF -115

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-115)))

#define YYTABLE_NINF -101

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       1,  -115,    15,     2,  -115,    -4,    38,    60,    63,  -115,
      69,  -115,    -4,    16,  -115,  -115,  -115,    83,   254,    69,
     254,    39,    32,    69,  -115,  -115,  -115,    22,    77,    78,
      40,   100,  -115,  -115,  -115,  -115,     8,    87,  -115,    74,
      48,    49,    90,   149,     6,    45,   254,    55,  -115,  -115,
    -115,    50,  -115,    96,   254,  -115,   254,  -115,  -115,  -115,
      56,  -115,    66,    -4,    20,   254,    68,    71,  -115,    79,
      81,  -115,   113,  -115,  -115,  -115,   116,  -115,  -115,   -46,
    -115,  -115,  -115,   149,   149,   149,  -115,    80,    82,  -115,
    -115,  -115,   149,   149,    86,  -115,    80,   149,   149,   121,
    -115,  -115,  -115,   144,    92,    98,   101,   131,  -115,  -115,
    -115,   135,   137,    97,   103,   106,   136,  -115,  -115,    78,
       5,  -115,  -115,  -115,  -115,   162,   104,   149,   149,   149,
     149,   149,   149,   142,   169,   189,   203,   196,   105,   147,
      80,   148,    80,   254,  -115,  -115,   -63,  -115,  -115,  -115,
      20,  -115,  -115,   117,  -115,  -115,    83,   159,   149,   149,
     149,   149,   149,  -115,   149,   149,  -115,    -8,  -115,    -8,
      -8,  -115,  -115,   120,   138,   145,  -115,   149,  -115,  -115,
     129,   140,   141,   149,   149,   103,  -115,    69,   146,   152,
     155,    80,    80,    80,    80,    80,    80,   149,  -115,  -115,
     196,   149,   149,  -115,   163,    80,  -115,   153,   159,    18,
    -115,   164,  -115,   170,   171,  -115,  -115,  -115,    69,   178,
    -115,  -115,  -115,   179,  -115,  -115
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,     0,     1,     5,    13,    14,    15,    16,
      36,     5,     6,    24,    10,    11,    12,    17,     0,    36,
       0,     0,     0,    36,     7,    26,    27,     0,     0,     0,
       0,     0,    18,    25,    20,    19,     0,     0,   101,     0,
       0,     0,     0,     0,   100,     0,    53,     0,    63,    56,
      57,     0,    65,     0,     0,    66,     0,    58,    59,    60,
       0,    35,     0,    52,    46,     0,     0,     0,    34,     0,
      32,     9,     0,    41,    42,    43,     0,    64,    82,    91,
     116,   115,   114,     0,     0,     0,    95,    81,     0,    92,
     112,   113,     0,     0,    78,    79,    80,     0,   103,     0,
       3,    54,    55,     0,     0,     0,     0,     0,    37,    51,
      38,     0,     0,     0,    48,     0,     0,    28,     8,     0,
       0,    40,    99,    87,    90,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   105,     0,     0,
      67,     0,    68,     0,    74,    76,     0,    49,    50,    39,
       0,    45,     2,     0,    33,    44,    17,     0,   103,     0,
       0,     0,     0,    93,     0,     0,    94,    89,    88,    83,
      84,    86,    85,    98,     0,     0,    72,     0,   102,    62,
       0,     0,     0,   103,     0,    48,    29,    36,    30,     0,
       0,   106,   107,   108,   109,   110,   111,   103,    75,    77,
     105,   103,   103,    73,     0,    71,    47,     0,     0,    17,
      96,     0,   104,     0,     0,    61,    23,    31,    36,     0,
      97,    70,    69,     0,    22,    21
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -115,  -115,  -115,   198,   -11,  -115,   194,  -115,  -115,  -115,
    -115,    76,    -6,  -115,    35,   125,  -115,   -19,  -115,  -115,
    -115,  -115,  -115,  -115,  -115,    30,    99,  -115,    19,  -115,
    -115,  -115,  -115,  -115,     3,  -115,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,   -37,  -115,     7,  -114,    51,  -115,  -115,
    -115,   134
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    10,    11,    12,    13,    29,    30,    31,
      32,   111,   112,    35,   189,    69,    70,    18,    19,    20,
      21,    22,    76,   157,   113,   151,   114,   110,    45,    46,
      47,    48,    49,    50,    86,    52,    53,    54,    55,    56,
      57,    58,    59,   137,   158,    88,   138,   178,   126,    89,
      90,    91
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      61,    24,    87,   -17,    65,   183,    96,    34,   184,     6,
       7,     8,     9,   155,    73,     4,   -17,   -17,   -17,    97,
       1,    51,   122,    51,  -100,    60,   128,    60,    25,    26,
      75,     6,     7,     8,     9,    17,    25,    26,    27,    62,
      25,    26,    25,    26,   190,    95,   123,   124,   125,    51,
     131,   132,   109,    60,    14,   134,   135,    51,   -17,    51,
     136,    60,   140,    60,     5,   101,   142,   156,    51,   204,
      28,    97,    60,   105,    98,   106,    15,    99,    28,    16,
      78,   -36,    28,   211,   115,    38,    17,   213,   214,    33,
     167,   168,   169,   170,   171,   172,     6,     7,     8,     9,
      64,    63,    79,    66,    71,    67,    68,    72,   100,    80,
      81,    82,    74,   127,   128,    77,    92,    93,    94,   102,
     104,   103,   191,   192,   193,   194,   107,   195,   196,   108,
     139,    83,    38,   116,   117,    84,   129,   130,   131,   132,
     200,   120,    85,   118,   121,   187,    51,   205,   119,    79,
      60,    97,   133,   141,   143,    38,    80,    81,    82,   146,
      38,   144,   182,   147,   145,   148,   149,   150,   207,   152,
     173,    80,    79,   166,   179,   180,   181,    79,    83,    80,
      81,    82,    84,   186,    80,    81,    82,   188,   197,    85,
     219,   159,   160,   161,   162,   127,   128,   201,   218,   223,
     198,    83,   127,   128,   203,    84,    83,   199,   202,    23,
      84,    36,    85,   208,   209,   206,   216,    85,   129,   130,
     131,   132,   127,   128,   210,   129,   130,   131,   132,   127,
     128,   163,   215,   220,   164,   165,   127,   128,   174,   221,
     222,   224,   225,   217,   154,   129,   130,   131,   132,   185,
     153,   212,   129,   130,   131,   132,     0,     0,   175,   129,
     130,   131,   132,   177,    37,    38,     0,     0,     0,   176,
       0,     0,    39,     0,     0,     0,     0,    40,     0,    41,
      42,    43,    44
};

static const yytype_int16 yycheck[] =
{
      19,    12,    39,     7,    23,    68,    43,    13,    71,    13,
      14,    15,    16,     8,     6,     0,    20,    21,    22,    65,
      19,    18,    68,    20,    70,    18,    34,    20,    20,    21,
      36,    13,    14,    15,    16,    17,    20,    21,    22,    20,
      20,    21,    20,    21,   158,    42,    83,    84,    85,    46,
      58,    59,    63,    46,    16,    92,    93,    54,    62,    56,
      97,    54,    99,    56,    62,    46,   103,    62,    65,   183,
      62,    65,    65,    54,    68,    56,    16,    71,    62,    16,
       6,    63,    62,   197,    65,    11,    17,   201,   202,    13,
     127,   128,   129,   130,   131,   132,    13,    14,    15,    16,
      68,    62,    28,    27,    64,    28,    28,     7,    63,    35,
      36,    37,    36,    33,    34,    28,    68,    68,    28,    64,
      24,    71,   159,   160,   161,   162,    70,   164,   165,    63,
       9,    57,    11,    65,    63,    61,    56,    57,    58,    59,
     177,    28,    68,    64,    28,   156,   143,   184,    67,    28,
     143,    65,    70,     9,    62,    11,    35,    36,    37,    28,
      11,    63,   143,    28,    63,    28,    69,    64,   187,    63,
      28,    35,    28,    69,    69,    28,    28,    28,    57,    35,
      36,    37,    61,    66,    35,    36,    37,    28,    68,    68,
     209,    29,    30,    31,    32,    33,    34,    68,   209,   218,
      62,    57,    33,    34,    63,    61,    57,    62,    68,    11,
      61,    17,    68,    67,    62,   185,    63,    68,    56,    57,
      58,    59,    33,    34,    69,    56,    57,    58,    59,    33,
      34,    69,    69,    69,    72,    73,    33,    34,    69,    69,
      69,    63,    63,   208,   119,    56,    57,    58,    59,   150,
     116,   200,    56,    57,    58,    59,    -1,    -1,    69,    56,
      57,    58,    59,    67,    10,    11,    -1,    -1,    -1,    66,
      -1,    -1,    18,    -1,    -1,    -1,    -1,    23,    -1,    25,
      26,    27,    28
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    19,    75,    76,     0,    62,    13,    14,    15,    16,
      77,    78,    79,    80,    16,    16,    16,    17,    91,    92,
      93,    94,    95,    77,    78,    20,    21,    22,    62,    81,
      82,    83,    84,    85,    86,    87,    80,    10,    11,    18,
      23,    25,    26,    27,    28,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     119,    91,   102,    62,    68,    91,    85,    28,    28,    89,
      90,    64,     7,     6,    85,    86,    96,    28,     6,    28,
      35,    36,    37,    57,    61,    68,   108,   117,   119,   123,
     124,   125,    68,    68,    28,   108,   117,    65,    68,    71,
      63,   102,    64,    71,    24,   102,   102,    70,    63,    78,
     101,    85,    86,    98,   100,   102,    65,    63,    64,    67,
      28,    28,    68,   117,   117,   117,   122,    33,    34,    56,
      57,    58,    59,    70,   117,   117,   117,   117,   120,     9,
     117,     9,   117,    62,    63,    63,    28,    28,    28,    69,
      64,    99,    63,   125,    89,     8,    62,    97,   118,    29,
      30,    31,    32,    69,    72,    73,    69,   117,   117,   117,
     117,   117,   117,    28,    69,    69,    66,    67,   121,    69,
      28,    28,   102,    68,    71,   100,    66,    78,    28,    88,
     120,   117,   117,   117,   117,   117,   117,    68,    62,    62,
     117,    68,    68,    63,   120,   117,    99,    91,    67,    62,
      69,   120,   121,   120,   120,    69,    63,    88,    78,    91,
      69,    69,    69,    91,    63,    63
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    74,    75,    75,    76,    77,    78,    78,    79,    79,
      80,    80,    80,    80,    80,    80,    80,    80,    81,    81,
      81,    82,    82,    82,    83,    84,    85,    85,    86,    87,
      88,    88,    89,    89,    90,    91,    91,    92,    93,    94,
      95,    96,    96,    96,    97,    98,    98,    99,    99,   100,
     100,   101,   101,   102,   102,   103,   103,   104,   104,   104,
     104,   104,   104,   104,   105,   106,   106,   107,   107,   107,
     107,   107,   108,   109,   110,   111,   112,   113,   114,   114,
     115,   116,   116,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   118,
     119,   119,   120,   120,   121,   121,   122,   122,   122,   122,
     122,   122,   123,   123,   124,   124,   125
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     7,     0,     0,     1,     2,     4,     3,
       2,     2,     2,     1,     1,     1,     1,     0,     1,     1,
       1,     9,     8,     7,     0,     1,     1,     1,     3,     5,
       1,     3,     1,     3,     1,     2,     0,     3,     3,     4,
       4,     1,     1,     1,     1,     2,     0,     3,     0,     2,
       2,     1,     0,     1,     2,     2,     1,     1,     1,     1,
       1,     6,     4,     1,     2,     1,     1,     3,     3,     7,
       7,     5,     4,     5,     3,     5,     3,     5,     2,     2,
       2,     2,     2,     3,     3,     3,     3,     2,     3,     3,
       2,     1,     1,     3,     3,     1,     5,     6,     3,     0,
       1,     1,     2,     0,     3,     0,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1
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
#line 128 "omicron.y" /* yacc.c:1646  */
    {
        escribir_fin(fout);
        tablaFree(tabla_main);
    }
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 134 "omicron.y" /* yacc.c:1646  */
    {
        escribir_fin(fout);
        tablaFree(tabla_main);
    }
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 140 "omicron.y" /* yacc.c:1646  */
    {
    /* Inic tabla simbolos */

    if ( abrirAmbitoClase(&tabla_main, "main", 1) == -1) { /* init tabla simbolos */
        printf("error inicializando en la tabla de simbolos");
    }
    escribir_subseccion_data(fout);
    escribir_cabecera_bss(fout);
}
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 150 "omicron.y" /* yacc.c:1646  */
    {
    escribir_segmento_codigo(fout);
    escribir_inicio_main(fout);
}
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 156 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 160 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 165 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo != (yyvsp[-1].atributos).tipo) {
            printf("Declaracion de distintos tipos NOT GOOD\n");
        }
    }
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 172 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 177 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 181 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 185 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 189 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 193 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 197 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 201 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 205 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 210 "omicron.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
    }
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 215 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 219 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 224 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 228 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 232 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 237 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 242 "omicron.y" /* yacc.c:1646  */
    {
       (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
    }
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 248 "omicron.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = ENTERO;
        tipo_declaracion = ENTERO;
    }
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 254 "omicron.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = BOOLEAN;
        tipo_declaracion = BOOLEAN;
    }
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 261 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 266 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 271 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 275 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 280 "omicron.y" /* yacc.c:1646  */
    {
        /* Aqui solo se accede al declarar varibles */
        (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
        nlocalvar++;
    }
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 287 "omicron.y" /* yacc.c:1646  */
    {
      (yyval.atributos).tipo = (yyvsp[-2].atributos).tipo;
    }
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 293 "omicron.y" /* yacc.c:1646  */
    {
        (yyval.atributos).direcciones = 1;
        (yyvsp[0].atributos).tipo = tipo_declaracion;

        printf("entro en una declaracion de variable (%s) [%d]\n", (yyvsp[0].atributos).lexema, (yyvsp[0].atributos).tipo);
        (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
        declarar_variable(fout, (yyvsp[0].atributos).lexema, (yyvsp[0].atributos).tipo, 1);
        insertarTablaSimbolosAmbitos(tabla_main, "main", (yyvsp[0].atributos).lexema, ESCALAR, (yyvsp[0].atributos).tipo, (yyvsp[0].atributos).direcciones, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, NINGUNO, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
    }
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 305 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 309 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 314 "omicron.y" /* yacc.c:1646  */
    {
        if (hay_return == 0) {
            sprintf(msg, "No hay return en funcion");
        }
        hay_return = 0;
    }
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 323 "omicron.y" /* yacc.c:1646  */
    {
        /**Ensamblador*/
        declararFuncion(fout, fcn.nombre, nlocalvar);
    }
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 330 "omicron.y" /* yacc.c:1646  */
    {
        for (i = 0; i < fcn.nargs; i++) {
            sprintf(aux, "@%d", fcn.tipo_args[i]);
            strcat(fcn.nombre, aux);
        }

        insertarTablaSimbolosAmbitos(tabla_main, "main", fcn.nombre, ESCALAR, fcn.tipo_retorno, FUNCION, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_TODOS, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
        if (AbrirAmbitoPrefijos(tabla_main, "main", fcn.nombre, ESCALAR, 0, fcn.tipo_retorno, 0, 1) == -1) {
            sprintf(msg, "Variable no encontrada\n");
            return -1;
        }
        /* Bucle para insertar los argumentos de la funcion */
        for (i = 0; i < fcn.nargs; i++) {
            strcat(aux, fcn.nombre);
            strcat(aux, "_");
            strcat(aux, fcn.nombre_args[i]);
            insertarTablaSimbolosAmbitos(tabla_main, "main", aux, PARAMETRO, fcn.tipo_args[i], ESCALAR, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, NINGUNO, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
        }

        nlocalvar = 0;

    }
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 355 "omicron.y" /* yacc.c:1646  */
    {
        strcpy(fcn.nombre, (yyvsp[0].atributos).lexema);
        fcn.nargs = 0;
        fcn.tipo_retorno = (yyvsp[-1].atributos).tipo;
    }
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 365 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 369 "omicron.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
    }
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 374 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 379 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 384 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 388 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 393 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 397 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 402 "omicron.y" /* yacc.c:1646  */
    {
        strcpy(fcn.nombre_args[fcn.nargs], (yyvsp[0].atributos).lexema);
        (yyvsp[0].atributos).tipo = (yyvsp[-1].atributos).tipo;
        fcn.tipo_args[fcn.nargs] = (yyvsp[0].atributos).tipo;
        fcn.nargs++;
    }
#line 1942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 410 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 415 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 419 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 424 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 428 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 433 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 437 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 442 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 446 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 450 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 454 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 458 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 462 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 466 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 471 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 476 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 480 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2061 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 485 "omicron.y" /* yacc.c:1646  */
    {
        //Buscamos en la tabla de simbolos el tipo de $1
        if (buscarIdNoCualificado(NULL, tabla_main, (yyvsp[-2].atributos).lexema, "main", &elem, nombre_ambito_encontrado) == OK) {
            (yyvsp[-2].atributos).tipo = elem->tipo;
        }
        else {
            sprintf(msg, "Variable no encontrada\n");
        }

        if ((yyvsp[-2].atributos).tipo != (yyvsp[0].atributos).tipo) {
          sprintf(msg, "Variables distintas\n");
        }

        char aux[50];
        if ((yyvsp[0].atributos).direcciones == 0) {
            sprintf(aux, "%d", (yyvsp[0].atributos).valor_entero);

        }
        asignar(fout, (yyvsp[-2].atributos).lexema, (yyvsp[0].atributos).direcciones);
    }
#line 2086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 507 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo != (yyvsp[0].atributos).tipo) {
            sprintf(msg, "tipos incompatibles");
        }
    }
#line 2096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 514 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 518 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2110 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 522 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 527 "omicron.y" /* yacc.c:1646  */
    {
        if (buscarIdNoCualificado(NULL, tabla_main, (yyvsp[-3].atributos).lexema, "main", &elem, nombre_ambito_encontrado) == OK) {
            (yyvsp[-3].atributos).tipo = elem->tipo;
            if (elem->clase != VECTOR) {
                sprintf(msg, "no es vector");
            }
            if ((yyvsp[-1].atributos).tipo != ENTERO) {
                sprintf(msg, "el indice debe ser de tipo entero");
            }

            (yyval.atributos).tipo = elem->tipo;
            (yyval.atributos).direcciones = 1;
            //Comprobacion indice, 0<i<64
        }
        else {
            sprintf(msg, "Variable no encontrada\n");
        }
    }
#line 2140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 548 "omicron.y" /* yacc.c:1646  */
    {
        ifthenelse_fin(fout, (yyvsp[-4].atributos).etiqueta);
    }
#line 2148 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 554 "omicron.y" /* yacc.c:1646  */
    {
        (yyval.atributos).etiqueta = (yyvsp[-2].atributos).etiqueta;

        ifthenelse_fin_then(fout, (yyvsp[-2].atributos).etiqueta);
    }
#line 2158 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 562 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo != BOOLEAN) {
            sprintf(msg, "condicion del if no booleano");
        }
        (yyval.atributos).etiqueta = etiqueta;
        etiqueta++;

        ifthenelse_inicio(fout, (yyvsp[-2].atributos).direcciones, (yyval.atributos).etiqueta);
    }
#line 2172 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 574 "omicron.y" /* yacc.c:1646  */
    {
        while_fin(fout, (yyvsp[-2].atributos).etiqueta);
    }
#line 2180 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 580 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo != BOOLEAN) {
            sprintf(msg, "condicion del if no booleano");
        }
        (yyval.atributos).etiqueta = etiqueta;
        etiqueta++;

        while_inicio(fout, (yyval.atributos).etiqueta);
        while_exp_pila(fout, (yyvsp[-2].atributos).direcciones, (yyval.atributos).etiqueta);
    }
#line 2195 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 593 "omicron.y" /* yacc.c:1646  */
    {
        if (buscarIdNoCualificado(NULL, tabla_main, (yyvsp[0].atributos).lexema, "main", &elem, nombre_ambito_encontrado) != OK) {
            sprintf(msg, "Elem no encontrado\n");
        } else {
            if (elem->clase == FUNCION || elem->clase == VECTOR) {
                sprintf(msg, "no se puede imprimir funciones ni vectores\n");
            }

            escribir_operando(fout, (yyvsp[0].atributos).lexema, (yyvsp[0].atributos).direcciones);
            leer(fout, (yyvsp[0].atributos).lexema, elem->tipo);
        }
    }
#line 2212 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 607 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2219 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 612 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[0].atributos).direcciones == 1) {
            if(buscarIdNoCualificado(NULL, tabla_main, (yyvsp[0].atributos).lexema, "main", &elem, nombre_ambito_encontrado) == OK) {
                escribir_operando(fout, (yyvsp[0].atributos).lexema, (yyvsp[0].atributos).direcciones);
                escribir(fout, (yyvsp[0].atributos).direcciones, elem->tipo);
            }
            else {
                sprintf(msg, "Elem no encontrado\n");
            }
        }
        else{
            escribir(fout, (yyvsp[0].atributos).direcciones, (yyvsp[0].atributos).tipo);
        }


    }
#line 2240 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 631 "omicron.y" /* yacc.c:1646  */
    {
        retornarFuncion(fout, (yyvsp[0].atributos).direcciones);
        hay_return = 1;
    }
#line 2249 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 637 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2256 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 642 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN) {
            sprintf(msg, "La suma requiere que ambos operandos sean numeros");
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
#line 2282 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 665 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN) {
            sprintf(msg, "La resta requiere que ambos operandos sean numeros");
        }
        (yyval.atributos).tipo = ENTERO;
        (yyval.atributos).direcciones = 0;
    }
#line 2294 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 674 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN) {
            sprintf(msg, "La division requiere que ambos operandos sean numeros");
        }
        if ((yyvsp[0].atributos).tipo == 0) {
            sprintf(msg, "La division entre 0 no se permite");
        }
        (yyval.atributos).tipo = ENTERO;
        (yyval.atributos).direcciones = 0;
    }
#line 2309 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 686 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN) {
            sprintf(msg, "La multiplicacion requiere que ambos operandos sean numeros");
        }
        (yyval.atributos).tipo = ENTERO;
        (yyval.atributos).direcciones = 0;
    }
#line 2321 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 695 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[0].atributos).tipo == BOOLEAN) {
            sprintf(msg, "El cambio de signo requiere operandos que sean numeros");
        }
        (yyval.atributos).tipo = ENTERO;
        (yyval.atributos).direcciones = 0;
    }
#line 2333 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 704 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo == ENTERO || (yyvsp[0].atributos).tipo == ENTERO) {
            sprintf(msg, "La conjuncion requiere operandos que sean booleans");
        }
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).direcciones = 0;
    }
#line 2345 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 713 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo == ENTERO || (yyvsp[0].atributos).tipo == ENTERO) {
            sprintf(msg, "La disyuncion requiere operandos que sean booleans");
        }
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).direcciones = 0;
    }
#line 2357 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 722 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[0].atributos).tipo == ENTERO) {
            sprintf(msg, "La negacion requiere operandos que sean booleans");
        }
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).direcciones = 0;
    }
#line 2369 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 731 "omicron.y" /* yacc.c:1646  */
    {
      if (buscarIdNoCualificado(NULL, tabla_main, (yyvsp[0].atributos).lexema, "main", &elem, nombre_ambito_encontrado) == OK){
          (yyvsp[0].atributos).tipo = elem->tipo;
      }
      else {
          printf("Error:Variable no encontrada\n");
      }
      //diapo90 gen
      escribir_operando(fout, (yyvsp[0].atributos).lexema, 1);
      if (flag_lista_exp == 1) {
          operandoEnPilaAArgumento(fout, 1);
      }

      //TODO comprobar que no sea de categoria funcion ni clase vector
      (yyval.atributos).tipo = elem->tipo;
      (yyval.atributos).direcciones = 1;
    }
#line 2391 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 750 "omicron.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
        (yyval.atributos).direcciones = (yyvsp[0].atributos).direcciones;
    }
#line 2400 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 756 "omicron.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;
        (yyval.atributos).direcciones = (yyvsp[-1].atributos).direcciones;
    }
#line 2409 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 762 "omicron.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;
        (yyval.atributos).direcciones = (yyvsp[-1].atributos).direcciones;
    }
#line 2418 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 768 "omicron.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
        (yyval.atributos).direcciones = (yyvsp[0].atributos).direcciones;
    }
#line 2427 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 774 "omicron.y" /* yacc.c:1646  */
    {
        flag_lista_exp = 0;
        llamarFuncion(fout, fcn.nombre, fcn.nargs);
    }
#line 2436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 780 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2443 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 784 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2450 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 789 "omicron.y" /* yacc.c:1646  */
    {
        flag_lista_exp = 1;
    }
#line 2458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 795 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 799 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 804 "omicron.y" /* yacc.c:1646  */
    {

    }
#line 2480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 809 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 814 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 818 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 823 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN) {
            sprintf(msg, "La division requiere que ambos operandos sean numeros");
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
#line 2523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 842 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN) {
            sprintf(msg, "La division requiere que ambos operandos sean numeros");
        }
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).direcciones = 0;
    }
#line 2535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 851 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN) {
            sprintf(msg, "La division requiere que ambos operandos sean numeros");
        }
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).direcciones = 0;
    }
#line 2547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 860 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN) {
            sprintf(msg, "La division requiere que ambos operandos sean numeros");
        }
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).direcciones = 0;
    }
#line 2559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 869 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN) {
            sprintf(msg, "La division requiere que ambos operandos sean numeros");
        }
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).direcciones = 0;
    }
#line 2571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 878 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN) {
            sprintf(msg, "La division requiere que ambos operandos sean numeros");
        }
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).direcciones = 0;
    }
#line 2583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 888 "omicron.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
        (yyval.atributos).direcciones = (yyvsp[0].atributos).direcciones;
    }
#line 2592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 894 "omicron.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
        (yyval.atributos).direcciones = (yyvsp[0].atributos).direcciones;
    }
#line 2601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 901 "omicron.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).direcciones = 0;
        escribir_operando(fout, "1", 0);
    }
#line 2611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 908 "omicron.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).direcciones = 0;
        escribir_operando(fout, "0", 0);
    }
#line 2621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 916 "omicron.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = ENTERO;
        (yyval.atributos).direcciones = 0;
        sprintf((yyvsp[0].atributos).lexema, "%d", (yyvsp[0].atributos).valor_entero);
        escribir_operando(fout, (yyvsp[0].atributos).lexema, 0);
    }
#line 2632 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2636 "y.tab.c" /* yacc.c:1646  */
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
#line 924 "omicron.y" /* yacc.c:1906  */


int yyerror(char* s) {
    if (!flag_error)
    {
        fprintf(stderr, "ERROR SINTÁCTICO:%d:%d\n", fila, columna);
    }
    if (!flag_error)
    {
        fprintf(stderr, "****Error semantico en lin %d: %s\n", fila, msg);
    }
    flag_error = 0;
    return -1;
}
