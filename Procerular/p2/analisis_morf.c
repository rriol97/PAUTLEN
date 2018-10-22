#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"

extern int yylrx();
extern int yylex();

extern FILE *yyin;
extern int columna;
extern int fila;
extern char *yytext;

int main(int argc, char *argv[])
{
    int ret;
    FILE *fout;

    if (argc != 3)
    {
        printf("Formato entrada: %s <fin> <fout>\n", argv[0]);
        return EXIT_FAILURE;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin)
    {
        printf("Apertura fichero entrada fallida\n");
        return EXIT_FAILURE;
    }
    fout = fopen(argv[2], "w");
    if (!fout)
    {
        printf("Apertura fichero salida fallida\n");
        return EXIT_FAILURE;
    }

    ret = yylex();

    while (ret != 0)
    {
        switch (ret)
        {
        case TOK_NONE:
            fprintf(fout, "TOK_NONE %d none\n", TOK_NONE);
            break;
        case TOK_CLASS:
            fprintf(fout, "TOK_CLASS %d class\n", TOK_CLASS);
            break;
        case TOK_INHERITS:
            fprintf(fout, "TOK_INHERITS %d inherits\n", TOK_INHERITS);
            break;
        case TOK_INSTANCE_OF:
            fprintf(fout, "TOK_INSTANCE_OF %d instance_of\n", TOK_INSTANCE_OF);
            break;
        case TOK_DISCARD:
            fprintf(fout, "TOK_DISCARD %d discard\n", TOK_DISCARD);
            break;
        case TOK_ITSELF:
            fprintf(fout, "TOK_ITSELF %d itself\n", TOK_ITSELF);
            break;
        case TOK_FLECHA:
            fprintf(fout, "TOK_FLECHA %d ->\n", TOK_FLECHA);
            break;
        case TOK_HIDDEN:
            fprintf(fout, "TOK_HIDDEN %d hidden\n", TOK_HIDDEN);
            break;
        case TOK_SECRET:
            fprintf(fout, "TOK_SECRET %d secret\n", TOK_SECRET);
            break;
        case TOK_EXPOSED:
            fprintf(fout, "TOK_EXPOSED %d exposed\n", TOK_EXPOSED);
            break;
        case TOK_UNIQUE:
            fprintf(fout, "TOK_UNIQUE %d unique\n", TOK_UNIQUE);
            break;
        case TOK_FUNCTION:
            fprintf(fout, "TOK_FUNCTION %d function\n", TOK_FUNCTION);
            break;
        case TOK_RETURN:
            fprintf(fout, "TOK_RETURN %d return\n", TOK_RETURN);
            break;
        case TOK_MAIN:
            fprintf(fout, "TOK_MAIN %d main\n", TOK_MAIN);
            break;
        case TOK_INT:
            fprintf(fout, "TOK_INT %d int\n", TOK_INT);
            break;
        case TOK_BOOLEAN:
            fprintf(fout, "TOK_BOOLEAN %d boolean\n", TOK_BOOLEAN);
            break;
        case TOK_ARRAY:
            fprintf(fout, "TOK_ARRAY %d array\n", TOK_ARRAY);
            break;
        case TOK_IF:
            fprintf(fout, "TOK_IF %d if\n", TOK_IF);
            break;
        case TOK_ELSE:
            fprintf(fout, "TOK_ELSE %d else\n", TOK_ELSE);
            break;
        case TOK_WHILE:
            fprintf(fout, "TOK_WHILE %d while\n", TOK_WHILE);
            break;
        case TOK_SCANF:
            fprintf(fout, "TOK_SCANF %d scanf\n", TOK_SCANF);
            break;
        case TOK_PRINTF:
            fprintf(fout, "TOK_PRINTF %d printf\n", TOK_PRINTF);
            break;
        case TOK_FALSE:
            fprintf(fout, "TOK_FALSE %d false\n", TOK_FALSE);
            break;
        case TOK_TRUE:
            fprintf(fout, "TOK_TRUE %d true\n", TOK_TRUE);
            break;
        case TOK_IGUAL:
            fprintf(fout, "TOK_IGUAL %d ==\n", TOK_IGUAL);
            break;
        case TOK_DISTINTO:
            fprintf(fout, "TOK_DISTINTO %d !=\n", TOK_DISTINTO);
            break;
        case TOK_MENORIGUAL:
            fprintf(fout, "TOK_MENORIGUAL %d <=\n", TOK_MENORIGUAL);
            break;
        case TOK_MAYORIGUAL:
            fprintf(fout, "TOK_MAYORIGUAL %d >=\n", TOK_MAYORIGUAL);
            break;
        case TOK_AND:
            fprintf(fout, "TOK_AND %d &&\n", TOK_AND);
            break;
        case TOK_OR:
            fprintf(fout, "TOK_OR %d ||\n", TOK_OR);
            break;
        case TOK_IDENTIFICADOR:
            fprintf(fout, "TOK_IDENTIFICADOR %d %s\n", TOK_IDENTIFICADOR, yytext);
            break;
        case TOK_CONSTANTE_ENTERA:
            fprintf(fout, "TOK_CONSTANTE_ENTERA %d %s\n", TOK_CONSTANTE_ENTERA, yytext);
            break;
        case TOK_SALTO:
            break;
        case TOK_BLANCO:
            break;   
        case TOK_OK:
            fprintf(fout, "TOK_COMENTARIO %d %s", TOK_OK, yytext);
            break;      
        case TOK_ERROR:
            fprintf(fout, "TOK_ERROR %d %s", TOK_ERROR, yytext);
            break;    

        default:
            fprintf(fout, "SIMBOLO SIMPLE %d %s\n", ret, yytext);
        }

        ret = yylex();
    }

    fclose(yyin);
    fclose(fout);

    return 1;
}