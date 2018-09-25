/**
Name: generacion.c
Author: Francisco de Vicente y Ricardo Riol 
Desc: En este fichero se implementan las funciones que permiten la genración del código NASM
 */

#include "generacion.h"

/**Funciones implementadas*/

/*
Código para el principio de la sección .bss.
Con seguridad sabes que deberás reservar una variable entera para guardar
el puntero de pila extendido (esp). 
Se te sugiere el nombre __esp para esta variable.
*/
void escribir_cabecera_bss(FILE* fpasm) {
	char definicion[] = "segment .bss";
	char puntero_pila[] = "\t__esp resd 1"

	if (!fpasm) {
		printf("Error de fichero (escribir_cabecera_bss)\n");
	} else {

		/** Escribimos en el fichero la definición del segmento .bss e inicializamos el puntero de pila*/
		if (fprintf(fpasm, "%s\n", definicion) > 0) {
			if (fprintf(fpasm, "%s\n", puntero_pila) <= 0) {
				printf("Error inicializando el puntero de pila\n");
			}
		} else {
			printf("Error definiendo el segmento .bss\n");
		}
	}

	return;
}

/*
   Declaración (con directiva db) de las variables que contienen el texto de los mensajes para la identificación de errores
   en tiempo de ejecución.
   En este punto, al menos, debes ser capaz de detectar la división por 0.
*/
void escribir_subseccion_data(FILE* fpasm){
	char mensaje[] = "segment.data\n\tmsg_error_division_por_0\tdb \"Division por 0\", 0"

	if (!fpasm) {
		printf("Error de fichero (escribir_subsection_data)\n");
	} else {

		if (fprintf(fpasm, "%s\n", mensaje) < 0) {
			printf("Error declarando subseccion data\n");
		}
	}	

	return;
}


/*
   Para ser invocada en la sección .bss cada vez que se quiera declarar una variable:
El argumento nombre es el de la variable.
tipo puede ser ENTERO o BOOLEANO (observa la declaración de las constantes del principio del fichero).
Esta misma función se invocará cuando en el compilador se declaren vectores, por eso se adjunta un argumento final
(tamano) que para esta primera práctica siempre recibirá el valor 1. */

void declarar_variable(FILE* fpasm, char * nombre,  int tipo,  int tamano){
	/** Variable donde guardaremos la declaracion de la variable en ensamblador*/
	char *declaracion = "";

	if (!fpasm) {
		pritnf("Error de fichero (declarar_variable");
	} else {
		sprintf(declaracion, "\t_%s resd %d", nombre, tamano);
		fprintf(fpasm, "%s\n", declaracion);
	}
	
	return;
}


