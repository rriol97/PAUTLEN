#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern int yyparse();
//extern int yyval;

extern FILE *yyin;
FILE *fout;
extern int columna;
extern int fila;
extern char *yytext;

int main(int argc, char *argv[])
{

    if (argc != 3)
    {
        printf("Formato entrada: pruebaSintactico <fin> <fout>\n");
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

    yyparse() != 0

    fclose(yyin);
    fclose(fout);

    return EXIT_SUCCESS;
}
