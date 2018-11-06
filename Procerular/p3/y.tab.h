/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
