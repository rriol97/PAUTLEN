/**
Name: generacion.c
Author: Francisco de Vicente y Ricardo Riol 
Desc: En este fichero se implementan las funciones que permiten la genración del 
	código NASM
 */

#include "generacion.h"

#define LISTA_OP_EXTERNAS "scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean"
#define PUNTERO_A_PILA "__esp"

/** Funciones implementadas*/

/*
	Código para el principio de la sección .bss.
Con seguridad sabes que deberás reservar una variable entera para guardar
el puntero de pila extendido (esp). 
Se te sugiere el nombre __esp para esta variable.
*/
void escribir_cabecera_bss(FILE* fpasm) {
	char definicion[] = "segment .bss";
	char puntero_pila[] = "\t__esp resd 1";

	if (!fpasm) {
		printf("Error de fichero (escribir_cabecera_bss)\n");
	} else {

		/** Escribimos en el fichero la definición del segmento .bss e 
			inicializamos el puntero de pila*/
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
   Declaración (con directiva db) de las variables que contienen el texto de los 
mensajes para la identificación de errores en tiempo de ejecución.
En este punto, al menos, debes ser capaz de detectar la división por 0.
*/
void escribir_subseccion_data(FILE* fpasm){
	char mensaje[] = "segment.data\n\tmsg_error_division_por_0\tdb \"Division por 0\", 0";

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
tipo puede ser ENTERO o BOOLEANO (observa la declaración de las constantes del 
principio del fichero).
Esta misma función se invocará cuando en el compilador se declaren vectores, por 
eso se adjunta un argumento final (tamano) que para esta primera práctica siempre 
recibirá el valor 1. 
*/
void declarar_variable(FILE* fpasm, char * nombre,  int tipo,  int tamano){
	/** Variable donde guardaremos la declaracion de la variable en ensamblador*/
	char *declaracion = "";

	if (!fpasm) {
		printf("Error de fichero (declarar_variable)");
	} else {
		sprintf(declaracion, "\t_%s resd %d", nombre, tamano);
		fprintf(fpasm, "%s\n", declaracion);
	}

	return;
}

/*
   Para escribir el comienzo del segmento .text, básicamente se indica que se 
exporta la etiqueta main y que se usarán las funciones declaradas en la 
librería olib.o
*/
void escribir_segmento_codigo(FILE* fpasm) {

	if (!fpasm) {
		printf("Error de fichero (escribir_segmento_codigo)\n");
	} else {

		if (fprintf(fpasm, "segment .text\n") <= 0) {
			printf("Error definiendo el segmento de codigo\n");
		} 
		else if (fprintf(fpasm, "\tglobal main\n") <= 0) {
			printf("Error declarando main\n");
		} 
		else if (fprintf(fpasm, "extern %s", LISTA_OP_EXTERNAS)) {
			printf("Error declarando operaciones externas");
		}
	}

	return;
}

/* 
   En este punto se debe escribir, al menos, la etiqueta main y la sentencia que 
guarda el puntero de pila en su variable (se recomienda usar __esp).
*/
void escribir_inicio_main(FILE* fpasm) {

	if (!fpasm) {
		printf("Error de fichero (escribir_inicio_main)\n");
	} 
	else if (fprintf(fpasm, "main:\n") <= 0) {
		printf("Error al escribir main");
	}
	else if (fprintf(fpasm, "\tmov dword [%s], %s\n", PUNTERO_A_PILA, PUNTERO_A_PILA) <= 0) {
		printf("Error guardando la variable de pila");
	}
}

/*
   Al final del programa se escribe:
El código NASM para salir de manera controlada cuando se detecta un error en 
tiempo de ejecución (cada error saltará a una etiqueta situada en esta zona en 
la que se imprimirá el correspondiente mensaje y se saltará a la zona de 
finalización del programa).
En el final del programa se debe:
 ·Restaurar el valor del puntero de pila (a partir de su variable __esp)
 ·Salir del programa (ret).
*/
void escribir_fin(FILE* fpasm) {
	if (!fpasm) {
		printf("Error de fichero (escribir_fin)\n");
	} 
	// TODO: hace falta escribir el resto de etiquetas para errores de ex.?
	else if (fprintf(fpasm, "fin:\n") <= 0) {
		printf("Error al escribir fin");
	}
	else if (fprintf(fpasm, "\tmov dword [%s], %s\n", PUNTERO_A_PILA, PUNTERO_A_PILA) <= 0) {
		printf("Error reestableciendo la variable de pila");
	}
	else if (fprintf(fpasm, "\tret\n") <= 0) {
		printf("Error al escribir el retorno");
	}
}

/** ^^^^^^^^^^^^^^^^^^^^^^^^ IMPLEMENTADO HASTA AQUI ^^^^^^^^^^^^^^^^^^^^^^^^ */

int main(int argc, char* argv[]) {
	FILE* salida;
	if (argc != 2) {
		fprintf (stdout, "ERROR POCOS ARGUMENTOS\n"); 
		return EXIT_FAILURE;
	}
	salida = fopen(argv[1], "w");

	/** <funcion a probar> */
	escribir_fin(salida);

	fclose(salida);

	return EXIT_SUCCESS;
}