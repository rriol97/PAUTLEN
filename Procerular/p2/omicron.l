%{
#include <stdio.h>
#include "tokens.h"

int fila;
int columna;
int yyleng;
int yytext;

%}
%option noyywrap

DIGITO [0-9]
ENTERO  {DIGITO}+
LETRA [A-Z]
BALNCO [ \t]+
SALTO \n
COMENTARIO "//".*\n 
ERROR .
IDENTIFICADOR ([a-z]|[A-Z])([A-Z][a-z][0-9])*

%%
class { columna += yyleng; return TOK_CLASS;}
inherits { columna += yyleng; return TOK_INHERITS;}
instance_of { columna += yyleng; return TOK_INSTANCE_OF;}
dicard { columna += yyleng; return TOK_DISCARD;}
itself { columna += yyleng; return TOK_ITSELF;}
flecha { columna += yyleng; return TOK_FLECHA;}
hidden { columna += yyleng; return TOK_HIDDEN;}
secret { columna += yyleng; return TOK_SECRET;}
exposed { columna += yyleng; return TOK_EXPOSED;}
unique { columna += yyleng; return TOK_UNIQUE;}

function { columna += yyleng; return TOK_FUNCTION;}
return { columna += yyleng; return TOK_RETURN;}
main { columna += yyleng; return TOK_MAIN;}
int { columna += yyleng; return TOK_INT;}
boolean { columna += yyleng; return TOK_BOOLEAN;}     
none { columna += yyleng; return TOK_NONE;}
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

    return;
}

{SALTO} {
    columna = 0;
    fila += 1;
    return;
}

{BLANCO} {
    columna += yyleng;
    return;
}

{LETRA} {
    columna += yyleng;
    return;
}

{ERROR} {
    fprintf(stderr, "\nERROR");
    return TOK_ERROR;
}
%%
