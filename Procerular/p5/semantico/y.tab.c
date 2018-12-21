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
    char nombre_args[MAX_LEN][MAX_LEN];
    char nombre_var[MAX_LEN][MAX_LEN];
    int tipo_args[MAX_LEN];
    int tipo_var[MAX_LEN];
    int nargs;
    int tipo_retorno;
} Fcn;

int tipo_id_actual;
TablaAmbito * tabla_main;
elementoTablaSimbolos * elem;
char nombre_ambito_encontrado[MAX_NAME];
int tipo_declaracion;
int tipo_clase;
int tamanio_vector_actual;
int etiqueta = 1;
char aux[MAX_LEN+100];
char fname_aux[MAX_LEN];
int nargs;
char msg[MAX_LEN*2];
int i;
int nlocalvar;
int hay_return = 0;
int flag_lista_exp = 0;
int en_funcion = 0;
int error_semantico = 0;

Fcn fcn;

#line 112 "y.tab.c" /* yacc.c:339  */

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
#line 47 "omicron.y" /* yacc.c:355  */

    tipo_atributos atributos;

#line 268 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 285 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   270

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  118
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  228

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
       0,   136,   136,   142,   149,   158,   163,   167,   172,   179,
     184,   188,   192,   196,   200,   204,   208,   213,   217,   223,
     230,   235,   239,   243,   249,   253,   259,   266,   273,   278,
     290,   294,   299,   313,   325,   349,   354,   359,   372,   409,
     434,   445,   449,   454,   459,   464,   469,   473,   478,   482,
     492,   497,   502,   506,   510,   515,   519,   524,   528,   532,
     536,   540,   544,   573,   578,   583,   587,   592,   633,   643,
     647,   651,   656,   689,   695,   703,   717,   723,   736,   743,
     771,   776,   795,   806,   811,   825,   839,   853,   867,   881,
     896,   910,   925,   963,   969,   975,   981,   987,  1012,  1016,
    1022,  1031,  1035,  1040,  1051,  1057,  1062,  1073,  1077,  1092,
    1107,  1122,  1137,  1152,  1168,  1174,  1181,  1188,  1196
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
  "bucle_medio", "bucle_inicio", "lectura", "escritura", "retorno_funcion",
  "exp", "activar_flag_lista_exp", "identificador_clase",
  "lista_expresiones", "intermedio", "resto_lista_expresiones",
  "comparacion", "constante", "constante_logica", "constante_entera", YY_NULLPTR
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

#define YYPACT_NINF -58

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-58)))

#define YYTABLE_NINF -105

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       7,   -58,    30,   -30,   -58,   135,    24,    26,    31,   -58,
      32,   -58,   135,    13,   -58,   -58,   -58,    55,   211,    32,
     211,    11,    -2,    32,   -58,   -58,   -58,    16,    54,    59,
      19,    89,   -58,   -58,   -58,   -58,     3,    69,   -58,    44,
      39,    41,    71,    49,    43,    37,   211,    52,   -58,   -58,
     -58,    56,   -58,   106,   211,   -58,   211,    49,   -58,   -58,
     -58,    63,   -58,    74,   135,    -6,   211,    73,    83,   -58,
      70,    86,   -58,   130,   -58,   -58,   -58,   132,   -58,   -58,
     -57,   -58,   -58,   -58,    49,    49,    49,   -58,   191,    92,
     -58,   -58,   -58,    49,   -58,    98,   -58,   191,    49,    95,
      67,   -58,   -58,   -58,   104,   111,   103,   105,   137,   152,
     -58,   -58,   -58,   155,   156,   113,   125,   127,   157,   -58,
     -58,    59,    -1,   -58,   -58,   -58,   -58,   145,   129,    49,
      49,    49,    49,    49,    49,   177,   154,   186,   140,    49,
     187,   191,   188,   191,   211,   -58,   -58,   164,   -46,   -58,
     -58,   -58,    -6,   -58,   -58,   161,   -58,   -58,    55,   200,
      95,    49,    49,    49,    49,   -58,    49,    49,   -58,    60,
     -58,    60,    60,   -58,   -58,   167,   178,   -58,   -58,   174,
     183,   185,   192,   -58,    95,    49,   125,   -58,    32,   179,
     194,   189,   191,   191,   191,   191,   191,   191,    95,   -58,
      49,   -58,    95,    95,   -58,   190,   191,   -58,   197,   200,
       4,   -58,   193,   174,   195,   196,   -58,   -58,   -58,    32,
     198,   -58,   -58,   -58,   -58,   203,   -58,   -58
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,     0,     1,     5,    13,    14,    15,    16,
      36,     5,     6,    24,    10,    11,    12,    17,     0,    36,
       0,     0,     0,    36,     7,    26,    27,     0,     0,     0,
       0,     0,    18,    25,    20,    19,     0,     0,   102,     0,
       0,     0,     0,     0,   101,     0,    53,     0,    63,    56,
      57,     0,    65,     0,     0,    66,     0,     0,    58,    59,
      60,     0,    35,     0,    52,    46,     0,     0,     0,    34,
       0,    32,     9,     0,    41,    42,    43,     0,    64,    83,
      92,   118,   117,   116,     0,     0,     0,    96,    82,     0,
      93,   114,   115,     0,    78,    79,    80,    81,     0,   105,
       0,     3,    54,    55,     0,     0,     0,     0,     0,     0,
      37,    51,    38,     0,     0,     0,    48,     0,     0,    28,
       8,     0,     0,    40,   100,    88,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    67,     0,    68,     0,    74,    76,     0,     0,    49,
      50,    39,     0,    45,     2,     0,    33,    44,    17,     0,
     105,     0,     0,     0,     0,    94,     0,     0,    95,    90,
      89,    84,    85,    87,    86,    99,     0,    72,    62,   107,
       0,     0,     0,    77,   105,     0,    48,    29,    36,    30,
       0,     0,   108,   109,   110,   111,   112,   113,   105,    75,
       0,   103,   105,   105,    73,     0,    71,    47,     0,     0,
      17,    97,     0,   107,     0,     0,    61,    23,    31,    36,
       0,    98,   106,    70,    69,     0,    22,    21
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -58,   -58,   -58,   243,   -11,   -58,   240,   -58,   -58,   -58,
     -58,   118,    -7,   -58,    58,   142,   -58,   -19,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,    82,   117,   -58,     8,   -58,
     -58,   -58,   -58,   -58,   -15,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -41,   -58,    -8,   -17,   -58,    57,
     -58,   -58,   -58,   -58
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    10,    11,    12,    13,    29,    30,    31,
      32,   113,   114,    35,   190,    70,    71,    18,    19,    20,
      21,    22,    77,   159,   115,   153,   116,   112,    45,    46,
      47,    48,    49,    50,    87,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    88,   160,    89,   138,   139,   201,
     128,    90,    91,    92
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      62,    24,    97,    51,    66,    51,    34,   157,    98,    74,
      61,   124,    61,  -101,    25,    26,   108,     6,     7,     8,
       9,    17,   184,    25,    26,   185,     1,    96,    63,    76,
       4,    51,     5,    25,    26,    27,    25,    26,    61,    51,
      14,    51,    15,   125,   126,   127,    61,    16,    61,    17,
      79,    51,   136,   111,   102,    38,    28,   137,    61,   141,
      38,   158,   106,   143,   107,    28,    65,   -36,     6,     7,
       8,     9,    80,    64,   117,    28,   140,    80,    38,    81,
      82,    83,    68,    72,    81,    82,    83,    69,   169,   170,
     171,   172,   173,   174,   130,    80,    73,    78,   179,    95,
     101,    84,    81,    82,    83,    85,    84,    93,    98,    94,
      85,    99,    86,   142,   100,    38,   103,    86,   133,   134,
     192,   193,   194,   195,    84,   196,   197,   104,    85,    51,
     105,    33,    80,   109,   120,    86,    61,   110,   118,    81,
      82,    83,   -17,   191,   206,    67,   119,   188,     6,     7,
       8,     9,   182,   121,    75,   -17,   -17,   -17,   122,   213,
     123,    84,   135,    98,  -104,    85,   145,   205,   146,   208,
     129,   130,    86,   144,   161,   162,   163,   164,   129,   130,
     148,   212,   151,   149,   150,   214,   215,   129,   130,   152,
     154,   220,   155,   131,   132,   133,   134,   -17,   168,   219,
     225,   131,   132,   133,   134,   175,   147,   129,   130,   178,
     131,   132,   133,   134,   165,   180,   181,   166,   167,   129,
     130,    37,    38,   176,   129,   130,   183,   187,   189,    39,
     131,   132,   133,   134,    40,   198,    41,    42,    43,    44,
     199,   200,   131,   132,   133,   134,   209,   131,   132,   133,
     134,   202,   177,   203,    23,   204,   210,    36,   211,   216,
     217,   226,   221,   156,   223,   224,   227,   218,   207,   186,
     222
};

static const yytype_uint8 yycheck[] =
{
      19,    12,    43,    18,    23,    20,    13,     8,    65,     6,
      18,    68,    20,    70,    20,    21,    57,    13,    14,    15,
      16,    17,    68,    20,    21,    71,    19,    42,    20,    36,
       0,    46,    62,    20,    21,    22,    20,    21,    46,    54,
      16,    56,    16,    84,    85,    86,    54,    16,    56,    17,
       6,    66,    93,    64,    46,    11,    62,    98,    66,   100,
      11,    62,    54,   104,    56,    62,    68,    63,    13,    14,
      15,    16,    28,    62,    66,    62,     9,    28,    11,    35,
      36,    37,    28,    64,    35,    36,    37,    28,   129,   130,
     131,   132,   133,   134,    34,    28,     7,    28,   139,    28,
      63,    57,    35,    36,    37,    61,    57,    68,    65,    68,
      61,    68,    68,     9,    71,    11,    64,    68,    58,    59,
     161,   162,   163,   164,    57,   166,   167,    71,    61,   144,
      24,    13,    28,    70,    64,    68,   144,    63,    65,    35,
      36,    37,     7,   160,   185,    27,    63,   158,    13,    14,
      15,    16,   144,    67,    36,    20,    21,    22,    28,   200,
      28,    57,    70,    65,    69,    61,    63,   184,    63,   188,
      33,    34,    68,    62,    29,    30,    31,    32,    33,    34,
      28,   198,    69,    28,    28,   202,   203,    33,    34,    64,
      63,   210,    35,    56,    57,    58,    59,    62,    69,   210,
     219,    56,    57,    58,    59,    28,    69,    33,    34,    69,
      56,    57,    58,    59,    69,    28,    28,    72,    73,    33,
      34,    10,    11,    69,    33,    34,    62,    66,    28,    18,
      56,    57,    58,    59,    23,    68,    25,    26,    27,    28,
      62,    67,    56,    57,    58,    59,    67,    56,    57,    58,
      59,    68,    66,    68,    11,    63,    62,    17,    69,    69,
      63,    63,    69,   121,    69,    69,    63,   209,   186,   152,
     213
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
     117,   120,    91,   102,    62,    68,    91,    85,    28,    28,
      89,    90,    64,     7,     6,    85,    86,    96,    28,     6,
      28,    35,    36,    37,    57,    61,    68,   108,   118,   120,
     125,   126,   127,    68,    68,    28,   108,   118,    65,    68,
      71,    63,   102,    64,    71,    24,   102,   102,   118,    70,
      63,    78,   101,    85,    86,    98,   100,   102,    65,    63,
      64,    67,    28,    28,    68,   118,   118,   118,   124,    33,
      34,    56,    57,    58,    59,    70,   118,   118,   121,   122,
       9,   118,     9,   118,    62,    63,    63,    69,    28,    28,
      28,    69,    64,    99,    63,    35,    89,     8,    62,    97,
     119,    29,    30,    31,    32,    69,    72,    73,    69,   118,
     118,   118,   118,   118,   118,    28,    69,    66,    69,   118,
      28,    28,   102,    62,    68,    71,   100,    66,    78,    28,
      88,   121,   118,   118,   118,   118,   118,   118,    68,    62,
      67,   123,    68,    68,    63,   121,   118,    99,    91,    67,
      62,    69,   121,   118,   121,   121,    69,    63,    88,    78,
      91,    69,   123,    69,    69,    91,    63,    63
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
     107,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     115,   116,   117,   117,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     119,   120,   120,   121,   121,   122,   123,   123,   124,   124,
     124,   124,   124,   124,   125,   125,   126,   126,   127
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
       7,     5,     4,     5,     3,     5,     3,     4,     2,     2,
       2,     2,     2,     2,     3,     3,     3,     3,     2,     3,
       3,     2,     1,     1,     3,     3,     1,     5,     6,     3,
       0,     1,     1,     3,     0,     0,     3,     0,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     1
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
#line 137 "omicron.y" /* yacc.c:1646  */
    {
        escribir_fin(fout);
        tablaFree(tabla_main);
    }
#line 1554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 143 "omicron.y" /* yacc.c:1646  */
    {
        escribir_fin(fout);
        tablaFree(tabla_main);
    }
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 149 "omicron.y" /* yacc.c:1646  */
    {
    /* Inic tabla simbolos */
    if ( abrirAmbitoClase(&tabla_main, "main", 1) == -1) { /* init tabla simbolos */
        printf("ERROR: No inicializada tabla de simbolos\n");
    }
    escribir_subseccion_data(fout);
    escribir_cabecera_bss(fout);
}
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 158 "omicron.y" /* yacc.c:1646  */
    {
    escribir_segmento_codigo(fout);
    escribir_inicio_main(fout);
}
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 164 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 168 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 173 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo != (yyvsp[-1].atributos).tipo) {
            printf("Declaracion de distintos tipos NOT GOOD\n");
        }
    }
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 180 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 185 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 189 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 193 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 197 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 201 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 205 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 209 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 213 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 218 "omicron.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
        tipo_clase = ESCALAR;
    }
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 224 "omicron.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
        tipo_clase = VECTOR;
        
    }
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 231 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 236 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 240 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 244 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 249 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 254 "omicron.y" /* yacc.c:1646  */
    {
       (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
    }
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 260 "omicron.y" /* yacc.c:1646  */
    {
        
        (yyval.atributos).tipo = ENTERO;
        tipo_declaracion = ENTERO;
    }
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 267 "omicron.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = BOOLEAN;
        tipo_declaracion = BOOLEAN;
    }
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 274 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 279 "omicron.y" /* yacc.c:1646  */
    {
        tamanio_vector_actual = (yyvsp[-1].atributos).valor_entero;
        (yyval.atributos).tipo = (yyvsp[-3].atributos).tipo;
        if ((tamanio_vector_actual < 1) || (tamanio_vector_actual > MAX_COLUMNAS_VECTOR)) {
            error_semantico = 1;
            sprintf (msg, "El tamanyo del vector excede los limites permitidos (1,64).\n");
            yyerror(msg);
        }
    }
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 291 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 295 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 300 "omicron.y" /* yacc.c:1646  */
    {
        /* Aqui solo se accede al declarar varibles */
        (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;

        if (en_funcion){
            strcpy(fcn.nombre_var[nlocalvar], (yyvsp[0].atributos).lexema);
            fcn.tipo_var[nlocalvar] = (yyvsp[0].atributos).tipo;
            nlocalvar++;
        }


    }
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 314 "omicron.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = (yyvsp[-2].atributos).tipo;

        if (en_funcion){
            strcpy(fcn.nombre_var[nlocalvar], (yyvsp[-2].atributos).lexema);
            fcn.tipo_var[nlocalvar] = (yyvsp[-2].atributos).tipo;
            nlocalvar++;
        }
    }
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 326 "omicron.y" /* yacc.c:1646  */
    {
        (yyval.atributos).direcciones = 1;
        (yyvsp[0].atributos).tipo = tipo_declaracion;
        
        (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;

        if (en_funcion == 0) {
            if (buscarIdNoCualificado(NULL, tabla_main, (yyvsp[0].atributos).lexema, "main", &elem, nombre_ambito_encontrado) == OK) {
               error_semantico = 1;
                yyerror("Declaracion duplicada");
            }
            if (tipo_clase == VECTOR) {
                insertarTablaSimbolosAmbitos(tabla_main, "main", (yyvsp[0].atributos).lexema, tipo_clase, (yyvsp[0].atributos).tipo, (yyvsp[0].atributos).direcciones, 1, 0, 0, 1, 0, tamanio_vector_actual, 0, 0, 0, 0, NINGUNO, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
                declarar_variable(fout, (yyvsp[0].atributos).lexema, (yyvsp[0].atributos).tipo, tamanio_vector_actual);
            }
            else {
                insertarTablaSimbolosAmbitos(tabla_main, "main", (yyvsp[0].atributos).lexema, tipo_clase, (yyvsp[0].atributos).tipo, (yyvsp[0].atributos).direcciones, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, NINGUNO, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
                declarar_variable(fout, (yyvsp[0].atributos).lexema, (yyvsp[0].atributos).tipo, 1);
            }
        }
    }
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 350 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 354 "omicron.y" /* yacc.c:1646  */
    {
        comienzo_sentencias(fout);
    }
#line 1860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 360 "omicron.y" /* yacc.c:1646  */
    {
        if (hay_return == 0) {
            error_semantico = 1;
            sprintf(msg, "Funcion %s sin sentencia de retorno.", fcn.nombre);
            yyerror(msg);
        }
        hay_return = 0;
        en_funcion = 0;

    }
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 373 "omicron.y" /* yacc.c:1646  */
    {
        /**Ensamblador*/
        declararFuncion(fout, fcn.nombre, nlocalvar);

        /* Bucle para insertar los argumentos de la funcion */
        for (i = 0; i < fcn.nargs; i++) {
            strcpy(aux, fcn.nombre);
            strcat(aux, "_");
            strcat(aux, fcn.nombre_args[i]);
            printf("introducimos el parametro %s en el ambito %s\n", aux, fcn.nombre);

            if (buscarParaDeclararIdTablaSimbolosAmbitos(tabla_main, aux, &elem, "main", nombre_ambito_encontrado) == OK) {
                error_semantico = 1;
                sprintf(msg, "Declaracion duplicada\n");
                yyerror(msg);
            }
            insertarTablaSimbolosAmbitos(tabla_main, "main", aux, FUNCION, fcn.tipo_args[i], PARAMETRO, 1, fcn.nargs, 0, 1, i, 1, 0, 0, 0, 0, NINGUNO, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
        
        }

        for (i = 0; i < nlocalvar; i++) {
            strcpy(aux, fcn.nombre);
            strcat(aux, "_");
            strcat(aux, fcn.nombre_var[i]);

            if (buscarParaDeclararIdTablaSimbolosAmbitos(tabla_main, aux, &elem, "main", nombre_ambito_encontrado) == OK) {
                error_semantico = 1;
                sprintf(msg, "Declaracion duplicada\n");
                yyerror(msg);
            }
            insertarTablaSimbolosAmbitos(tabla_main, "main", aux, FUNCION, fcn.tipo_var[i], VARIABLE, 1, 0, nlocalvar, i, 0, 1, 0, 0, 0, 0, NINGUNO, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
            
        }
    }
#line 1914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 410 "omicron.y" /* yacc.c:1646  */
    {
        for (i = 0; i < fcn.nargs; i++) {
            sprintf(aux, "@%d", fcn.tipo_args[i]);
            strcat(fcn.nombre, aux);
        }

        if (buscarIdNoCualificado(NULL, tabla_main, fname_aux, "main", &elem, nombre_ambito_encontrado) == OK) {
                error_semantico = 1;
                sprintf(msg, "Declaracion duplicada\n");
                yyerror(msg);
        }
        insertarTablaSimbolosAmbitos(tabla_main, "main", fcn.nombre, FUNCION, fcn.tipo_retorno, FUNCION, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_TODOS, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

        if (AbrirAmbitoPrefijos(tabla_main, "main", fcn.nombre, FUNCION, 0, fcn.tipo_retorno, 0, 1) == -1) {
                error_semantico = 1;
                sprintf(msg, "Acceso a funcion no declarada\n");
                yyerror(msg);
        }
        

        nlocalvar = 0;
    }
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 435 "omicron.y" /* yacc.c:1646  */
    {
        en_funcion = 1;
        strcpy(fcn.nombre, (yyvsp[0].atributos).lexema);
        fcn.nargs = 0;
        fcn.tipo_retorno = (yyvsp[-1].atributos).tipo;
    }
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 446 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 450 "omicron.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
    }
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 455 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 460 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 465 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 469 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 474 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 478 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 483 "omicron.y" /* yacc.c:1646  */
    {
        printf("precesamos argumento: %s (%d)\n", (yyvsp[0].atributos).lexema, fcn.nargs);
        strcpy(fcn.nombre_args[fcn.nargs], (yyvsp[0].atributos).lexema);
        printf("hago el strcpy bien\n");
        (yyvsp[0].atributos).tipo = (yyvsp[-1].atributos).tipo;
        fcn.tipo_args[fcn.nargs] = (yyvsp[0].atributos).tipo;
        fcn.nargs++;
    }
#line 2022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 493 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 498 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 502 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2043 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 507 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 511 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 516 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 520 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 525 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 529 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2085 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 533 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2092 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 537 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 541 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2106 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 545 "omicron.y" /* yacc.c:1646  */
    {
        flag_lista_exp = 0;

        strcat(fname_aux, (yyvsp[-3].atributos).lexema);
        strcat(fname_aux, aux);

        if (buscarIdNoCualificado(NULL, tabla_main, fname_aux, "main", &elem, nombre_ambito_encontrado) != OK) {
            error_semantico = 1;
            sprintf(msg, "Acceso a funcion no declarada (<%s>).\n", (yyvsp[-3].atributos).lexema);
            yyerror(msg);
        }
        if (elem->clase != FUNCION) {
            error_semantico = 1;
            sprintf(msg, "Acceso a funcion no declarada (<%s>).\n", (yyvsp[-3].atributos).lexema);
            yyerror(msg);
        }
        if (elem->numero_parametros != nargs) {
            error_semantico = 1;
            sprintf(msg, "Numero incorrecto de parametros en llamada a funcion.\n");
            yyerror(msg);
        }

        llamarFuncion(fout, fname_aux, nargs);

        (yyval.atributos).tipo = elem->tipo;
        (yyval.atributos).direcciones = 0;
    }
#line 2138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 574 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2145 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 579 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2152 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 584 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 588 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2166 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 593 "omicron.y" /* yacc.c:1646  */
    {

        if (en_funcion) {
            sprintf(aux, "%s_", fcn.nombre);
            strcat(aux, (yyvsp[-2].atributos).lexema);
            if (buscarParaDeclararIdTablaSimbolosAmbitos(tabla_main, aux, &elem, "main", nombre_ambito_encontrado) == OK) {
                asignar_en_funcion(fout, (yyvsp[0].atributos).direcciones, elem->posicion_variable_local+1);
            }
            else {
                error_semantico = 1;
                sprintf(msg, "Acceso a variable no declarada (<%s>).\n", (yyvsp[-2].atributos).lexema);
                yyerror(msg);
            }
        }
        else {
            //Buscamos en la tabla de simbolos el tipo de $1
            if (buscarIdNoCualificado(NULL, tabla_main, (yyvsp[-2].atributos).lexema, "main", &elem, nombre_ambito_encontrado) == OK) {
                (yyvsp[-2].atributos).tipo = elem->tipo;
            }
            else {
                error_semantico = 1;
                sprintf(msg, "Acceso a variable no declarada (<%s>).\n", (yyvsp[-2].atributos).lexema);
                yyerror(msg);
            }

            if ((yyvsp[-2].atributos).tipo != (yyvsp[0].atributos).tipo) {
                error_semantico = 1;
                sprintf(msg, "Asignacion incompatible.\n");
                yyerror(msg);
            }

            if ((yyvsp[0].atributos).direcciones == 0) {
                sprintf(aux, "%d", (yyvsp[0].atributos).valor_entero);

            }
            asignar(fout, (yyvsp[-2].atributos).lexema, (yyvsp[0].atributos).direcciones);
        }

    }
#line 2210 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 634 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo != (yyvsp[0].atributos).tipo) {
                error_semantico = 1;
                sprintf(msg, "Asignacion incompatible.\n");
                yyerror(msg);
        }
        asignarDestinoEnPila(fout, (yyvsp[0].atributos).direcciones);
    }
#line 2223 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 644 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2230 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 648 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2237 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 652 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2244 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 657 "omicron.y" /* yacc.c:1646  */
    {
        if (buscarIdNoCualificado(NULL, tabla_main, (yyvsp[-3].atributos).lexema, "main", &elem, nombre_ambito_encontrado) == OK) {
            (yyvsp[-3].atributos).tipo = elem->tipo;
            if (elem->clase != VECTOR) {
                error_semantico = 1;
                sprintf(msg, "Intento de indexacion de una variable que no es de tipo vector.\n");
                yyerror(msg);
            }
            if ((yyvsp[-1].atributos).tipo != ENTERO) {
                error_semantico = 1;
                sprintf(msg, "El indice en una operacion de indexacion tiene que ser de tipo entero.\n");
                yyerror(msg);
            }

            (yyval.atributos).tipo = elem->tipo;
            (yyval.atributos).direcciones = 1;

            if ((yyvsp[-1].atributos).valor_entero < 0 || (yyvsp[-1].atributos).valor_entero > MAX_COLUMNAS_VECTOR) {
                error_semantico = 1;
                sprintf(msg, "Intento de indexacion de una variable que no es de tipo vector.\n");
                yyerror(msg);
            }
            escribir_elemento_vector(fout, (yyvsp[-3].atributos).lexema, elem->tamanio, (yyvsp[-1].atributos).direcciones);
        }
        else {
                error_semantico = 1;
                sprintf(msg, "Acceso a variable no declarada (<%s>).\n", (yyvsp[-3].atributos).lexema);
                yyerror(msg);
        }
    }
#line 2279 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 690 "omicron.y" /* yacc.c:1646  */
    {
        ifthenelse_fin(fout, (yyvsp[-4].atributos).etiqueta);
    }
#line 2287 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 696 "omicron.y" /* yacc.c:1646  */
    {
        (yyval.atributos).etiqueta = (yyvsp[-2].atributos).etiqueta;

        ifthenelse_fin_then(fout, (yyvsp[-2].atributos).etiqueta);
    }
#line 2297 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 704 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo != BOOLEAN) {
            error_semantico = 1;
            sprintf(msg, "Condicional con condicion de tipo int.\n");
            yyerror(msg);
        }
        (yyval.atributos).etiqueta = etiqueta;
        etiqueta++;

        ifthenelse_inicio(fout, (yyvsp[-2].atributos).direcciones, (yyval.atributos).etiqueta);
    }
#line 2313 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 718 "omicron.y" /* yacc.c:1646  */
    {
        while_fin(fout, (yyvsp[-2].atributos).etiqueta);
    }
#line 2321 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 724 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo != BOOLEAN) {
            error_semantico = 1;
            sprintf(msg, "Bucle con condicion de tipo int.\n");
            yyerror(msg);
        }
        (yyval.atributos).etiqueta = (yyvsp[-3].atributos).etiqueta;
        
        while_exp_pila(fout, (yyvsp[-2].atributos).direcciones, (yyval.atributos).etiqueta);
    }
#line 2336 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 737 "omicron.y" /* yacc.c:1646  */
    {
        while_inicio(fout, etiqueta);
        (yyval.atributos).etiqueta = etiqueta;
        etiqueta++;
    }
#line 2346 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 744 "omicron.y" /* yacc.c:1646  */
    {
        if (en_funcion) {
            sprintf(aux, "%s_", fcn.nombre);
            strcat(aux, (yyvsp[-1].atributos).lexema);
            if (buscarParaDeclararIdTablaSimbolosAmbitos(tabla_main, aux, &elem, "main", nombre_ambito_encontrado) != OK) {
                sprintf(msg, "Varible local no encontrada\n");
                return -1;
            }
            escribirVariableLocal(fout, elem->posicion_variable_local+1);
            leer(fout, (yyvsp[0].atributos).lexema, elem->tipo);
        }
        else {
            if (buscarIdNoCualificado(NULL, tabla_main, (yyvsp[0].atributos).lexema, "main", &elem, nombre_ambito_encontrado) != OK) {
                sprintf(msg, "no encontrado\n");
                return -1;
            } else {
                if (elem->clase == FUNCION || elem->clase == VECTOR) {
                    sprintf(msg, "no se puede imprimir funciones ni vectores\n");
                    return -1;
                }

                escribir_operando(fout, (yyvsp[0].atributos).lexema, (yyvsp[0].atributos).direcciones);
                leer(fout, (yyvsp[0].atributos).lexema, elem->tipo);
            }
        }
    }
#line 2377 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 772 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2384 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 777 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[0].atributos).direcciones == 1) {
            if(buscarIdNoCualificado(NULL, tabla_main, (yyvsp[0].atributos).lexema, "main", &elem, nombre_ambito_encontrado) == OK) {
                //escribir_operando(fout, $2.lexema, $2.direcciones);
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
#line 2405 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 796 "omicron.y" /* yacc.c:1646  */
    {
        if (en_funcion == 0) {
            error_semantico = 1;
            sprintf(msg, "Sentencia de retorno fuera del cuerpo de una función.\n");
            yyerror(msg);
        }
        retornarFuncion(fout, (yyvsp[0].atributos).direcciones);
        hay_return = 1;
    }
#line 2419 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 807 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 812 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN) {
            error_semantico = 1;
            sprintf(msg, "Operacion aritmetica con operandos boolean.\n");
            yyerror(msg);
        }

        sumar(fout, (yyvsp[-2].atributos).direcciones, (yyvsp[0].atributos).direcciones);

        (yyval.atributos).tipo = ENTERO;
        (yyval.atributos).direcciones = 0;
    }
#line 2443 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 826 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN) {
            error_semantico = 1;
            sprintf(msg, "Operacion aritmetica con operandos boolean.\n");
            yyerror(msg);
        }

        restar(fout, (yyvsp[-2].atributos).direcciones, (yyvsp[0].atributos).direcciones);

        (yyval.atributos).tipo = ENTERO;
        (yyval.atributos).direcciones = 0;
    }
#line 2460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 840 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN) {
            error_semantico = 1;
            sprintf(msg, "Operacion aritmetica con operandos boolean.\n");
            yyerror(msg);
        }
        
        dividir(fout, (yyvsp[-2].atributos).direcciones, (yyvsp[0].atributos).direcciones);

        (yyval.atributos).tipo = ENTERO;
        (yyval.atributos).direcciones = 0;
    }
#line 2477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 854 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN) {
            error_semantico = 1;
            sprintf(msg, "Operacion aritmetica con operandos boolean.\n");
            yyerror(msg);
        }

        multiplicar(fout, (yyvsp[-2].atributos).direcciones, (yyvsp[0].atributos).direcciones);

        (yyval.atributos).tipo = ENTERO;
        (yyval.atributos).direcciones = 0;
    }
#line 2494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 868 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[0].atributos).tipo == BOOLEAN) {
            error_semantico = 1;
            sprintf(msg, "Operacion aritmetica con operandos boolean.\n");
            yyerror(msg);
        }

        cambiar_signo(fout, (yyvsp[0].atributos).direcciones);

        (yyval.atributos).tipo = ENTERO;
        (yyval.atributos).direcciones = 0;
    }
#line 2511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 882 "omicron.y" /* yacc.c:1646  */
    {

        if ((yyvsp[-2].atributos).tipo == ENTERO || (yyvsp[0].atributos).tipo == ENTERO) {
            error_semantico = 1;
            sprintf(msg, "Operacion logica con operandos int.\n");
            yyerror(msg);
        }

        y(fout, (yyvsp[-2].atributos).direcciones, (yyvsp[0].atributos).direcciones);

        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).direcciones = 0;
    }
#line 2529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 897 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo == ENTERO || (yyvsp[0].atributos).tipo == ENTERO) {
            error_semantico = 1;
            sprintf(msg, "Operacion logica con operandos int.\n");
            yyerror(msg);
        }

        o(fout, (yyvsp[-2].atributos).direcciones, (yyvsp[0].atributos).direcciones);

        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).direcciones = 0;
    }
#line 2546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 911 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[0].atributos).tipo == ENTERO) {
            error_semantico = 1;
            sprintf(msg, "Operacion logica con operandos int.\n");
            yyerror(msg);
        }

        no(fout, (yyvsp[0].atributos).direcciones, etiqueta);
        etiqueta++;

        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).direcciones = 0;
    }
#line 2564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 926 "omicron.y" /* yacc.c:1646  */
    {
        if (en_funcion) {
            sprintf(aux, "%s_", fcn.nombre);
            strcat(aux, (yyvsp[0].atributos).lexema);

            if(buscarParaDeclararIdTablaSimbolosAmbitos(tabla_main, aux, &elem, "main", nombre_ambito_encontrado) != OK) {
                error_semantico = 1;
                sprintf(msg, "Acceso a variable no declarada <%s>\n", (yyvsp[0].atributos).lexema);
                yyerror(msg);
            }
            printf("[[[ Encontramos %s en el ambito %s ]]]\n", aux, nombre_ambito_encontrado);

            if (elem->categoria == PARAMETRO) {
                escribirParametro(fout, elem->posicion_parametro, elem->numero_parametros);
            }
            else if (elem->categoria == VARIABLE) {
                escribirVariableLocal(fout, elem->posicion_variable_local+1);
            }

        } else {
            if (buscarIdNoCualificado(NULL, tabla_main, (yyvsp[0].atributos).lexema, "main", &elem, nombre_ambito_encontrado) == OK) {
                (yyvsp[0].atributos).tipo = elem->tipo;
            }
            else {
                printf("Error:Variable no encontrada (%s)\n", (yyvsp[0].atributos).lexema);
            }
            escribir_operando(fout, (yyvsp[0].atributos).lexema, 1);
            if (flag_lista_exp == 1) {
                operandoEnPilaAArgumento(fout, 1);
            }
        }

        //TODO comprobar que no sea de categoria funcion ni clase vector
        (yyval.atributos).tipo = elem->tipo;
        (yyval.atributos).direcciones = 1;
    }
#line 2605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 964 "omicron.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
        (yyval.atributos).direcciones = (yyvsp[0].atributos).direcciones;
    }
#line 2614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 970 "omicron.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;
        (yyval.atributos).direcciones = (yyvsp[-1].atributos).direcciones;
    }
#line 2623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 976 "omicron.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;
        (yyval.atributos).direcciones = (yyvsp[-1].atributos).direcciones;
    }
#line 2632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 982 "omicron.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
        (yyval.atributos).direcciones = (yyvsp[0].atributos).direcciones;
    }
#line 2641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 988 "omicron.y" /* yacc.c:1646  */
    {
        flag_lista_exp = 0;

        strcat(fname_aux, (yyvsp[-4].atributos).lexema);
        strcat(fname_aux, aux);


        if (buscarIdNoCualificado(NULL, tabla_main, fname_aux, "main", &elem, nombre_ambito_encontrado) != OK) {
            error_semantico = 1;
            sprintf(msg, "Acceso a variable no declarada <%s>\n", (yyvsp[-4].atributos).lexema);
            yyerror(msg);
        }
        if (elem->clase != FUNCION) {
            error_semantico = 1;
            sprintf(msg, "Acceso a variable no declarada <%s>\n", (yyvsp[-4].atributos).lexema);
            yyerror(msg);
        }

        llamarFuncion(fout, fname_aux, nargs);

        (yyval.atributos).tipo = elem->tipo;
        (yyval.atributos).direcciones = 0;
    }
#line 2669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1013 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1017 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1022 "omicron.y" /* yacc.c:1646  */
    {
        if (flag_lista_exp) {
                error_semantico = 1;
                sprintf(msg, "No esta permitido el uso de llamadas a funciones como parametros de otras\n");
                yyerror(msg);
        }
        flag_lista_exp = 1;
    }
#line 2696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1032 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1036 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1041 "omicron.y" /* yacc.c:1646  */
    {
        
        if ((yyvsp[-1].atributos).tipo == ENTERO) {
            strcat(aux, "@1");
        } else {
            strcat(aux, "@3");
        }
    }
#line 2723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1051 "omicron.y" /* yacc.c:1646  */
    {
        nargs = 0;
    }
#line 2731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1057 "omicron.y" /* yacc.c:1646  */
    {
        nargs = 1;
        aux[0] = '\0';
    }
#line 2740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1063 "omicron.y" /* yacc.c:1646  */
    {
        nargs++;
        if ((yyvsp[-1].atributos).tipo == ENTERO) {
            strcat(aux, "@1");
        } else {
            strcat(aux, "@3");
        }
    }
#line 2753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1073 "omicron.y" /* yacc.c:1646  */
    {
    }
#line 2760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1078 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN) {
            error_semantico = 1;
            sprintf(msg, "Comparacion con datos boolean.\n");
            yyerror(msg);
        }

        igual(fout, (yyvsp[-2].atributos).direcciones, (yyvsp[0].atributos).direcciones, etiqueta);
        etiqueta++;
        
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).direcciones = 0;
    }
#line 2778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1093 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN) {
            error_semantico = 1;
            sprintf(msg, "Comparacion con datos boolean.\n");
            yyerror(msg);
        }

        distinto(fout, (yyvsp[-2].atributos).direcciones, (yyvsp[0].atributos).direcciones, etiqueta);
        etiqueta++;

        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).direcciones = 0;
    }
#line 2796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1108 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN) {
            error_semantico = 1;
            sprintf(msg, "Comparacion con datos boolean.\n");
            yyerror(msg);
        }

        menor_igual(fout, (yyvsp[-2].atributos).direcciones, (yyvsp[0].atributos).direcciones, etiqueta);
        etiqueta++;

        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).direcciones = 0;
    }
#line 2814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1123 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN) {
            error_semantico = 1;
            sprintf(msg, "Comparacion con datos boolean.\n");
            yyerror(msg);
        }

        mayor_igual(fout, (yyvsp[-2].atributos).direcciones, (yyvsp[0].atributos).direcciones, etiqueta);
        etiqueta++;

        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).direcciones = 0;
    }
#line 2832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1138 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN) {
            error_semantico = 1;
            sprintf(msg, "Comparacion con datos boolean.\n");
            yyerror(msg);
        }

        menor(fout, (yyvsp[-2].atributos).direcciones, (yyvsp[0].atributos).direcciones, etiqueta);
        etiqueta++;

        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).direcciones = 0;
    }
#line 2850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1153 "omicron.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN) {
            error_semantico = 1;
            sprintf(msg, "Comparacion con datos boolean.\n");
            yyerror(msg);
        }

        mayor(fout, (yyvsp[-2].atributos).direcciones, (yyvsp[0].atributos).direcciones, etiqueta);
        etiqueta++;

        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).direcciones = 0;
    }
#line 2868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1169 "omicron.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
        (yyval.atributos).direcciones = (yyvsp[0].atributos).direcciones;
    }
#line 2877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1175 "omicron.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
        (yyval.atributos).direcciones = (yyvsp[0].atributos).direcciones;
    }
#line 2886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1182 "omicron.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).direcciones = 0;
        escribir_operando(fout, "1", 0);
    }
#line 2896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1189 "omicron.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).direcciones = 0;
        escribir_operando(fout, "0", 0);
    }
#line 2906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1197 "omicron.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = ENTERO;
        (yyval.atributos).direcciones = 0;
        sprintf((yyvsp[0].atributos).lexema, "%d", (yyvsp[0].atributos).valor_entero);
        escribir_operando(fout, (yyvsp[0].atributos).lexema, 0);
    }
#line 2917 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2921 "y.tab.c" /* yacc.c:1646  */
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
#line 1205 "omicron.y" /* yacc.c:1906  */


int yyerror(char* s) {
    if (!flag_error && error_semantico == 0)
    {
        fprintf(stderr, "ERROR SINTÁCTICO:%d:%d\n", fila, columna);
    }
    if (error_semantico)
    {
        fprintf(stderr, "****Error semantico en lin %d: %s\n", fila, s);
    }
    flag_error = 0;
    error_semantico = 0;
    return -1;
}
