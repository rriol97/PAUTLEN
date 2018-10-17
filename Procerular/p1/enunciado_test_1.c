#include <stdio.h>
#include "generacion.h"

int main (int argc, char** argv)
{
    FILE* salida;

    if (argc != 2) {fprintf (stdout, "ERROR POCOS ARGUMENTOS\n"); return -1;}

    salida = fopen(argv[1],"w");

    escribir_subseccion_data(salida);
    escribir_cabecera_bss(salida);
    declarar_variable(salida, "b1", BOOLEANO, 1);
    declarar_variable(salida, "x", ENTERO, 1);
    declarar_variable(salida, "y", ENTERO, 1);

    escribir_segmento_codigo(salida);
    escribir_inicio_main(salida);

    /* scanf(&x); */
    leer(salida,"x",ENTERO);

    /* scanf(&y); */
    leer(salida,"y",ENTERO);

    /* (x - y) */
    escribir_operando(salida,"x",1);
    escribir_operando(salida,"y",1);
    restar(salida,1,1);

    /* printf 3 * (x - y) */
    escribir_operando(salida,"3",0);
    multiplicar(salida,1,0);
    escribir(salida,1,ENTERO);

    /* b1 = (x > 3) */
    escribir_operando(salida,"x",1);
    escribir_operando(salida,"3",0);
    mayor(salida,1,0,1);
    asignar(salida,"b1",0);
    
    /* printf x */
    escribir_operando(salida,"x",1);
    escribir(salida,1,ENTERO);

    /* printf 3 */
    escribir_operando(salida,"3",0);
    escribir(salida,0,ENTERO);

    /* printf b1 */
    escribir_operando(salida,"b1",1);
    escribir(salida,1,BOOLEANO);
    
    escribir_fin(salida);

    fclose(salida);
    return 0;
}
