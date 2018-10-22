#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"

extern int yylrx();

extern FILE *yyin;
FILE *fout;
extern int columna;
extern int fila;

int main(int argc, char *argv[])
{
    int ret;
    FILE *fin, *fout;

    if (argc != 3)
    {
        printf("Formato entrada: ./%s <fin> <fout>\n", argv[0]);
        return EXIT_FAILURE;
    }

    fin = fopen("r", argv[1]);
    if (!fin)
    {
        printf("Apertura fichero entrada fallida\n");
        return EXIT_FAILURE;
    }
    fout = fopen("w", argv[2]);
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
            printf("TOK_NONE %d none\n", TOK_NONE);
            break;
        case TOK_CLASS:
            printf("TOK_CLASS %d class\n", TOK_CLASS);
            break;
        case TOK_INHERITS:
            printf("TOK_INHERITS %d inherits\n", TOK_INHERITS);
            break;
        case TOK_INSTANCE_OF:
            printf("TOK_INSTANCE_OF %d instance_of\n", TOK_INSTANCE_OF);
            break;
        case TOK_DISCARD:
            printf("TOK_DISCARD %d discard\n", TOK_DISCARD);
            break;
        case TOK_ITSELF:
            printf("TOK_ITSELF %d itself\n", TOK_ITSELF);
            break;
        case TOK_FLECHA:
            printf("TOK_FLECHA %d ->\n", TOK_FLECHA);
            break;
        case TOK_HIDDEN:
            printf("TOK_HIDDEN %d hidden\n", TOK_HIDDEN);
            break;
        case TOK_SECRET:
            printf("TOK_SECRET %d secret\n", TOK_SECRET);
            break;
        case TOK_EXPOSED:
            printf("TOK_EXPOSED %d exposed\n", TOK_EXPOSED);
            break;
        case TOK_UNIQUE:
            printf("TOK_UNIQUE %d unique\n", TOK_UNIQUE);
            break;
        case TOK_FUNCTION:
            printf("TOK_FUNCTION %d function\n", TOK_FUNCTION);
            break;
        case TOK_RETURN:
            printf("TOK_RETURN %d return\n", TOK_RETURN);
            break;
        case TOK_MAIN:
            printf("TOK_MAIN %d main\n", TOK_MAIN);
            break;
        case TOK_INT:
            printf("TOK_INT %d int\n", TOK_INT);
            break;
        case TOK_BOOLEAN:
            printf("TOK_BOOLEAN %d boolean\n", TOK_BOOLEAN);
            break;
        case TOK_ARRAY:
            printf("TOK_ARRAY %d array\n", TOK_ARRAY);
            break;
        case TOK_IF:
            printf("TOK_IF %d if\n", TOK_IF);
            break;
        case TOK_ELSE:
            printf("TOK_ELSE %d else\n", TOK_ELSE);
            break;
        case TOK_WHILE:
            printf("TOK_WHILE %d while\n", TOK_WHILE);
            break;
        case TOK_SCANF:
            printf("TOK_SCANF %d scanf\n", TOK_SCANF);
            break;
        case TOK_PRINTF:
            printf("TOK_PRINTF %d printf\n", TOK_PRINTF);
            break;
        case TOK_FALSE:
            printf("TOK_FALSE %d false\n", TOK_FALSE);
            break;
        case TOK_TRUE:
            printf("TOK_TRUE %d true\n", TOK_TRUE);
            break;
        case TOK_IGUAL:
            printf("TOK_IGUAL %d ==\n", TOK_IGUAL);
            break;
        case TOK_DISTINTO:
            printf("TOK_DISTINTO %d !=\n", TOK_DISTINTO);
            break;
        case TOK_MENORIGUAL:
            printf("TOK_MENORIGUAL %d <=\n", TOK_MENORIGUAL);
            break;
        case TOK_MAYORIGUAL:
            printf("TOK_MAYORIGUAL %d >=\n", TOK_MAYORIGUAL);
            break;
        case TOK_AND:
            printf("TOK_AND %d &&\n", TOK_AND);
            break;
        case TOK_OR:
            printf("TOK_OR %d ||\n", TOK_OR);
            break;
        case TOK_IDENTIFICADOR:
        // TODO
            printf("TOK_IDENTIFICADOR %d %s\n", TOK_IDENTIFICADOR);
            break;
        case TOK_CONSTANTE_ENTERA:
        // TODO
            printf("TOK_CONSTANTE_ENTERA %d %s\n", TOK_CONSTANTE_ENTERA);
            break;

        default:
        // TODO
            printf("SIMBOLO SIMPLE %d %c", ret, );
        }

        ret = yylex();
    }
}