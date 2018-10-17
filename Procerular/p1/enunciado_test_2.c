#include <stdio.h>
#include "generacion.h"

int main (int argc, char** argv)
{
    FILE* salida;

    if (argc != 2) {fprintf (stdout, "ERROR POCOS ARGUMENTOS\n"); return -1;}

    salida = fopen(argv[1],"w");

    escribir_subseccion_data(salida);
    escribir_cabecera_bss(salida);
    declarar_variable(salida, "x", ENTERO, 1);
    declarar_variable(salida, "y", ENTERO, 1);
    declarar_variable(salida, "z", ENTERO, 1);

    escribir_segmento_codigo(salida);
    escribir_inicio_main(salida);

    /* scanf(&x); */
    leer(salida,"x",ENTERO);

    /* scanf(&y); */
    leer(salida,"y",ENTERO);

    /* scanf(&z); */
    leer(salida,"z",ENTERO);

    /* x % 3 */
    escribir_operando(salida,"x",1);
    escribir_operando(salida,"3",0);
    resto(salida,1,0);

    /* printf x % 3 */
    escribir(salida,0,ENTERO);

    /* y % 3 */
    escribir_operando(salida,"y",1);
    escribir_operando(salida,"3",0);
    resto(salida,1,0);

    /* printf y % 3 */
    escribir(salida,0,ENTERO);

    /* z % 3 */
    escribir_operando(salida,"z",1);
    escribir_operando(salida,"3",0);
    resto(salida,1,0);

    /* printf z % 3 */
    escribir(salida,0,ENTERO);
    
    escribir_fin(salida);

    fclose(salida);
    return 0;
}
