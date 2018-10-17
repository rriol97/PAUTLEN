#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"

extern int yylrx();

extern FILE* yyin;
FILE* fout;
extern int columna;
extern int fila;



int main(int argc, char* argv[]) {
    int ret;
    FILE* fin, fout;

    if (argc != 3) {
        printf("Formato entrada: ./%s <fin> <fout>\n", argv[0]);
        return EXIT_FAILURE;
    }

    fin = fopen("r", argv[1]);
    if (!fin) {
        printf("Apertura fichero entrada fallida\n");
        return EXIT_FAILURE;
    }
    fout = fopen("w", argv[2]);
    if (!fout) {
        printf("Apertura fichero salida fallida\n");
        return EXIT_FAILURE;
    }

    ret = yylex();

    while (ret != 0) {
        switch (ret) {
            case TOK_NONE:
                printf("TOK_NONE %d \n", TOK_NONE);
                break;
            case TOK_CLASS:
                printf("TOK_CLASS %d class\n", TOK_CLASS);
                break;
            case TOK_INHERITS:
                printf("TOK_INHERITS %d \n", TOK_INHERITS);
                break;
            case TOK_INSTANCE_OF:
                printf("TOK_INSTANCE_OF %d \n", TOK_INSTANCE_OF);
                break;
            case TOK_DISCARD:
                printf("TOK_DISCARD %d \n", TOK_DISCARD);
                break;
            case TOK_ITSELF:
                printf("TOK_ITSELF %d \n", TOK_ITSELF);
                break;
            case TOK_FLECHA:
                printf("TOK_FLECHA %d \n", TOK_FLECHA);
                break;
            case TOK_HIDDEN:
                printf("TOK_HIDDEN %d \n", TOK_HIDDEN);
                break;
            case TOK_SECRET:
                printf("TOK_SECRET %d \n", TOK_SECRET);
                break;
            case TOK_EXPOSED:
                printf("TOK_EXPOSED %d \n", TOK_EXPOSED);
                break;
            case TOK_UNIQUE:
                printf("TOK_UNIQUE %d \n", TOK_UNIQUE);
                break;
            case TOK_FUNCTION:
                printf("TOK_FUNCTION %d \n", TOK_FUNCTION);
                break;
            case TOK_RETURN:
                printf("TOK_RETURN %d \n", TOK_RETURN);
                break;
            case TOK_MAIN:
                printf("TOK_MAIN %d \n", TOK_MAIN);
                break;
            case TOK_INT:
                printf("TOK_INT %d \n", TOK_INT);
                break;
            case TOK_BOOLEAN:
                printf("TOK_BOOLEAN %d \n", TOK_BOOLEAN);
                break;
            case TOK_ARRAY:
                printf("TOK_ARRAY %d \n", TOK_ARRAY);
                break;
            case TOK_IF:
                printf("TOK_IF %d \n", TOK_IF);
                break;
            case TOK_ELSE:
                printf("TOK_ELSE %d \n", TOK_ELSE);
                break;
            case TOK_WHILE:
                printf("TOK_WHILE %d \n", TOK_WHILE);
                break;
            case TOK_SCANF:
                printf("TOK_SCANF %d \n", TOK_SCANF);
                break;
            case TOK_PRINTF:
                printf("TOK_PRINTF %d \n", TOK_PRINTF);
                break;



            default:
                printf("SIMBOLO SIMPLE %d %c", ret);
        }


        ret = yylex();
    }


}