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

	return;
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

	return;
}

/** ^^^^^^^^^^^^^^^^^^^^^^^^ IMPLEMENTADO HASTA AQUI ^^^^^^^^^^^^^^^^^^^^^^^^ */

/*
   Función que debe ser invocada cuando se sabe un operando de una operación 
aritmético-lógica y se necesita introducirlo en la pila. nombre es la cadena de 
caracteres del operando tal y como debería aparecer en el fuente NASM 
es_variable indica si este operando es una variable (como por ejemplo b1) con un
1 u otra cosa (como por ejemplo 34) con un 0. Recuerda que en el primer caso 
internamente se representará como _b1 y, sin embargo, en el segundo se 
representará tal y como esté en el argumento (34).
*/
void escribir_operando(FILE* fpasm, char* nombre, int es_variable) {

	if (!fpasm) {
		printf("Error de fichero (escribir_operando)\n");
	} 
	else if (fprintf(fpasm, "\tpush dword %s\n", nombre) <= 0) {
			printf("Error al meter el operando en la pila");
	}

	return;
}

/*
	Genera el código para asignar valor a la variable de nombre nombre. 
Se toma el valor de la cima de la pila. El último argumento es el que indica si 
lo que hay en la cima de la pila es una referencia (1) o ya un valor explícito (0).
*/
void asignar(FILE* fpasm, char* nombre, int es_variable) {
	if (!fpasm) {
		printf("Error de fichero (asignar)");
	}
	else if (es_variable) {
		fprintf(fpasm, "\tpop dword eax\n\tmov eax [eax]\n\tmov [%s], eax\n", nombre);
	}
	else {
		fprintf(fpasm, "\tpop dword eax\n\tmov [%s], eax\n", nombre);
	}

	return;
}

/* FUNCIONES ARITMÉTICO-LÓGICAS BINARIAS */
/*
   En todas ellas se realiza la operación como se ha resumido anteriormente:
Se extrae de la pila los operandos
Se realiza la operación
Se guarda el resultado en la pila
Los dos últimos argumentos indican respectivamente si lo que hay en la pila es una referencia a un valor o un valor explícito.
Deben tenerse en cuenta las peculiaridades de cada operación. En este sentido sí hay que mencionar explícitamente que, en el caso de la división, se debe controlar si el divisor es “0” y en ese caso se debe saltar a la rutina de error controlado (restaurando el puntero de pila en ese caso y comprobando en el retorno que no se produce “Segmentation Fault”)
*/
void sumar(FILE* fpasm, int es_variable_1, int es_variable_2) {

	if (!pasm) {
		printf("Error de fichero (sumar)\n");
	}
	else {
		fprintf(fpasm, "\tpop eax\n\tpop edx\n");

		if (es_variable_1) {
			fprintf(fpasm, "\tmov edx, [edx]\n");
		} 

		if (es_variable_2) {
			fprintf(fpasm, "\tmov eax, [eax]\n");
		} 

		fprintf(fpasm, "\tadd edx, eax\n\tpush edx\n");

	}
	return;
}
void restar(FILE* fpasm, int es_variable_1, int es_variable_2){

	if (!pasm) {
		printf("Error de fichero (restar)\n");
	}
	else {
		fprintf(fpasm, "\tpop eax\n\tpop edx\n");

		if(es_variable_1) {
			fprintf(fpasm, "\tmov edx, [edx]\n");
		} 

		if (es_variable_2) {
			fprintf(fpasm, "\tmov eax, [eax]\n");
		} 

		fprintf(fpasm, "\tsub edx, eax\n\tpush edx\n");

	}
	return;
}	

void multiplicar(FILE* fpasm, int es_variable_1, int es_variable_2) {

	if (!pasm) {
		printf("Error del fichero (multiplicar)\n");
	}
	else {
		fprintf(fpasm, "\tpop ecx\n\tpop eax\n");

		if (es_variable_1) {
			fprintf(fpasm, "\tmov eax, [eax]\n");
		} 

		if (es_variable_2) {
			fprintf(fpasm, "\tmov ecx, [ecx]\n");
		} 

		fprintf(fpasm, "\timul ecx\n\tpush eax");
	}
	return;
}
void dividir(FILE* fpasm, int es_variable_1, int es_variable_2) {

	if (!pasm) {
		printf("Error del fichero (dividir)\n");
	}

	else {
		fprintf(fpasm, "\tpop ecx\n\tpop eax\n");

		if (es_variable_1) {
			fprintf(fpasm, "\tmov eax, [eax]\n");
		} 

		if (es_variable_2) {
			fprintf(fpasm, "\tmov ecx, [ecx]\n");
		} 

		fprintf(fpasm, "\tidiv ecx\n\tpush eax");
	}
	
	return;
}

void o(FILE* fpasm, int es_variable_1, int es_variable_2);
void y(FILE* fpasm, int es_variable_1, int es_variable_2);

void cambiar_signo(FILE* fpasm, int es_variable);
/*
   Función aritmética de cambio de signo. 
   Es análoga a las binarias, excepto que sólo requiere de un acceso a la pila ya que sólo usa un operando.
*/

void no(FILE* fpasm, int es_variable, int cuantos_no);
/*
   Función monádica lógica de negación. No hay un código de operación de la ALU 
   que realice esta operación por lo que se debe codificar un algoritmo que, si encuentra en la cima de la pila un 0 deja en la cima un 1 y al contrario.
   El último argumento es el valor de etiqueta que corresponde (sin lugar a dudas, la implementación del algoritmo requerirá etiquetas). Véase en los ejemplos de programa principal como puede gestionarse el número de etiquetas cuantos_no.
*/

/* FUNCIONES COMPARATIVAS */
/* 
   Todas estas funciones reciben como argumento si los elementos a comparar son o no variables. El resultado de las operaciones, que siempre será un booleano (“1” si se cumple la comparación y “0” si no se cumple), se deja en la pila como en el resto de operaciones. Se deben usar etiquetas para poder gestionar los saltos necesarios para implementar las comparaciones.
*/
void igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta);
void distinto(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta);
void menor_igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta);
void mayor_igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta);
void menor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta);
void mayor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta);

/* FUNCIONES DE ESCRITURA Y LECTURA */
/*
   Se necesita saber el tipo de datos que se va a procesar (ENTERO o BOOLEANO) ya que hay diferentes funciones de librería para la lectura (idem. escritura) de cada tipo.
   Se deben insertar en la pila los argumentos necesarios, realizar la llamada (call) a la función de librería correspondiente y limpiar la pila.
*/
void leer(FILE* fpasm, char* nombre, int tipo);
void escribir(FILE* fpasm, int es_variable, int tipo);

/** VVVVVVVVVVVVVVVVVVVVVVVVVVVVV MAIN DE TEST VVVVVVVVVVVVVVVVVVVVVVVVVVVVV */

int main(int argc, char* argv[]) {
	FILE* salida;
	if (argc != 2) {
		fprintf (stdout, "ERROR POCOS ARGUMENTOS\n"); 
		return EXIT_FAILURE;
	}
	salida = fopen(argv[1], "w");

	/** <funcion a probar> */
	escribir_fin(salida);
	asignar(salida, "nombre", 0);
	escribir_operando(salida, "nombre2", 1);

	fclose(salida);

	return EXIT_SUCCESS;
}