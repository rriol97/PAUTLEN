/*
Autores: Francisco de Vicente Lana y Ricardo Riol Gonzalez
Numero de grupo: 1311
Grupo de trabajo: 4

Desc: programa principal que se encarga de analizar semantico
    cierta entrada segun las normas y patrones del lenguaje omicron.
*/
#include <stdio.h>
#include <stdlib.h>

/* Globales externas de flex y bison */
extern int yylex();
extern int yyparse();

extern FILE *yyin;
FILE *fout;

int main(int argc, char *argv[])
{
    /* Comprobacion args de entrada */
    if (argc != 3)
    {
        printf("Formato entrada: pruebaSintactico <fin> <fout>\n");
        return EXIT_FAILURE;
    }

    /* Apertura dichero entrada */
    yyin = fopen(argv[1], "r");
    if (!yyin)
    {
        printf("Apertura fichero entrada fallida\n");
        return EXIT_FAILURE;
    }

    /* Apertura fichero salida */
    fout = fopen(argv[2], "w");
    if (!fout)
    {
        printf("Apertura fichero salida fallida\n");
        return EXIT_FAILURE;
    }

    /* Llamada a la funcion que realiza el analisis */
    if (yyparse() != 0)
    {
        fclose(yyin);
        fclose(fout);
        return EXIT_FAILURE;
    }

    /* Cierre de ficheros */
    fclose(yyin);
    fclose(fout);

    return EXIT_SUCCESS;
}
