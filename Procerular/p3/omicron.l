%{
#include <stdio.h>
#include "tokens.h"
#include "y.tab.h"

int fila = 1;
int columna = 0;
int error_morfologico = 0;
int yyleng;
char *yytext;
File *fout;

%}
%option noyywrap

DIGITO [0-9]
ENTERO  {DIGITO}+
BLANCO [ \t]+
SALTO \n
COMENTARIO "//".*\n
ERROR .
IDENTIFICADOR [a-zA-Z]([A-Za-z0-9])*

%%
none { columna += yyleng; fprintf(fout, "D: %s", yytext); return TOK_NONE;}
class { columna += yyleng; fprintf(fout, "D: %s", yytext); return TOK_CLASS;}
inherits { columna += yyleng; fprintf(fout, "D: %s", yytext); return TOK_INHERITS;}
instance_of { columna += yyleng;fprintf(fout, "D: %s", yytext); return TOK_INSTANCE_OF;}
discard { columna += yyleng;fprintf(fout, "D: %s", yytext); return TOK_DISCARD;}
itself { columna += yyleng;fprintf(fout, "D: %s", yytext); return TOK_ITSELF;}
flecha { columna += yyleng;fprintf(fout, "D: %s", yytext); return TOK_FLECHA;}
hidden { columna += yyleng;fprintf(fout, "D: %s", yytext); return TOK_HIDDEN;}
secret { columna += yyleng;fprintf(fout, "D: %s", yytext); return TOK_SECRET;}
exposed { columna += yyleng;fprintf(fout, "D: %s", yytext); return TOK_EXPOSED;}
unique { columna += yyleng;fprintf(fout, "D: %s", yytext); return TOK_UNIQUE;}

function { columna += yyleng; return TOK_FUNCTION;}
return { columna += yyleng; return TOK_RETURN;}
main { columna += yyleng; return TOK_MAIN;}
int { columna += yyleng; return TOK_INT;}
boolean { columna += yyleng; return TOK_BOOLEAN;}
array { columna += yyleng; return TOK_ARRAY;}
if { columna += yyleng; return TOK_IF;}
else { columna += yyleng; return TOK_ELSE;}
while { columna += yyleng; return TOK_WHILE;}
scanf { columna += yyleng; return TOK_SCANF;}
printf { columna += yyleng; return TOK_PRINTF;}
false { columna += yyleng; return TOK_FALSE;}
true { columna += yyleng; return TOK_TRUE;}

";" { columna += yyleng; return yytext[0];}
"#" { columna += yyleng; return yytext[0];}
"," { columna += yyleng; return yytext[0];}
"=" { columna += yyleng; return yytext[0];}
"(" { columna += yyleng; return yytext[0];}
")" { columna += yyleng; return yytext[0];}
"{" { columna += yyleng; return yytext[0];}
"}" { columna += yyleng; return yytext[0];}
"[" { columna += yyleng; return yytext[0];}
"]" { columna += yyleng; return yytext[0];}
":" { columna += yyleng; return yytext[0];}
"+" { columna += yyleng; return yytext[0];}
"-" { columna += yyleng; return yytext[0];}
"/" { columna += yyleng; return yytext[0];}
"*" { columna += yyleng; return yytext[0];}
"<" { columna += yyleng; return yytext[0];}
">" { columna += yyleng; return yytext[0];}
"&" { columna += yyleng; return yytext[0];}
"!" { columna += yyleng; return yytext[0];}
"." { columna += yyleng; return yytext[0];}

"==" { columna += yyleng; return TOK_IGUAL;}
"!=" { columna += yyleng; return TOK_DISTINTO;}
"<=" { columna += yyleng; return TOK_MENORIGUAL;}
">=" { columna += yyleng; return TOK_MAYORIGUAL;}
"||" { columna += yyleng; return TOK_OR;}
"&&" { columna += yyleng; return TOK_AND;}
"->" { columna += yyleng; return TOK_FLECHA;}


{IDENTIFICADOR} {
    if (yyleng > MAX_LONG_ID) {
        fprintf(stderr, "ERROR MORFOLÓGICO :%d:%d: IDENTIFICADOR DEMASIADO LARGO (%s)\n", fila, columna, yytext);
        return TOK_ERROR;
    }
    else {
        columna += yyleng;
        return TOK_IDENTIFICADOR;
    }
}

{ENTERO} {
    columna += yyleng;
    return TOK_CONSTANTE_ENTERA;
}

{COMENTARIO} {
    columna = 0;
    fila += 1;

    return TOK_COMENTARIO;
}

{SALTO} {
    columna = 0;
    fila += 1;
    return TOK_SALTO;
}

{BLANCO} {
    columna += yyleng;
    return TOK_BLANCO;
}

{ERROR} {
    fprintf(stderr, "\nERROR");
    return TOK_ERROR;
}
%%
