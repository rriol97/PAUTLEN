#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokens.h"

extern int yylrx();
extern int yylex();
extern int yyparse();
//extern int yyval;

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
        printf("Formato entrada: pruebaSintactico <fin> <fout>\n", argv[0]);
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


    if (yyparse() != 0) {
        /* Error sintactico */
        printf("bien");
    }
    else {
        printf("mal");
    }

    fclose(yyin);
    fclose(fout);

    return EXIT_SUCCESS;
}
