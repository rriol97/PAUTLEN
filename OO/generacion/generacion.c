/**
Name: generacion.c
Author: Francisco de Vicente y Ricardo Riol
Desc: En este fichero se implementan las funciones que permiten la genración del
	codigo NASM
 */
#include "generacion_omicron.h"

#define LISTA_OP_EXTERNAS "scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean, print_endofline, print_blank, print_string, malloc, free"
#define PUNTERO_A_PILA "__esp"
#define VARIABLE 1
#define NO_VARIABLE 0

/*
	Código para el principio de la sección .bss.
Con seguridad sabes que deberás reservar una variable entera para guardar
el puntero de pila extendido (esp).
Se te sugiere el nombre __esp para esta variable.
*/
void escribir_cabecera_bss(FILE* fpasm) {

	if (!fpasm) {
		printf("Error de fichero (escribir_cabecera_bss)\n");
	} else {
		fprintf(fpasm, "segment .bss\n\t__esp resd 1\n");
	}
	return;
}

/*
   Declaración (con directiva db) de las variables que contienen el texto de los
mensajes para la identificación de errores en tiempo de ejecución.
En este punto, al menos, debes ser capaz de detectar la división por 0.
*/
void escribir_subseccion_data(FILE* fpasm) {

	if (!fpasm) {
		printf("Error de fichero (escribir_subsection_data)\n");
	} else {
		fprintf(fpasm, "segment .data\n\tmsg_error_division_por_0\tdb \"Division por 0\", 0\n");
	}
	return;
}

/*
   Para ser invocada en la sección .bss cada vez que se quiera declarar una variable:
El argumento nombre es el de la variable.
tipo puede ser ENTERO o BOOLEAN (observa la declaración de las constantes del
principio del fichero).
Esta misma función se invocará cuando en el compilador se declaren vectores, por
eso se adjunta un argumento final (tamano) que para esta primera práctica siempre
recibirá el valor 1.
*/
void declarar_variable(FILE* fpasm, char * nombre,  int tipo,  int tamano) {

	if (!fpasm) {
		printf("Error de fichero (declarar_variable)");
	} else {
		fprintf(fpasm, "\t_%s resd %d\n", nombre, tamano);
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
		fprintf(fpasm, "segment .text\n\tglobal main\nextern %s\n", LISTA_OP_EXTERNAS);
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
	} else {
		fprintf(fpasm, "main:\n\tmov dword [%s], %s\n", PUNTERO_A_PILA, PUNTERO_A_PILA);
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
	} else {
		fprintf(fpasm, "fin:\n\tmov dword [%s], %s\n\tret\n", PUNTERO_A_PILA, PUNTERO_A_PILA);
	}
	return;
}

/*
   Función que debe ser invocada cuando se sabe un operando de una operación
aritmético-lógica y se necesita i
	;fin escritura operando -----
ntroducirlo en la pila. nombre es la cadena de
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
	if (es_variable) {
		fprintf(fpasm, "\tpush dword _%s\n", nombre);
	}
	else if (fprintf(fpasm, "\tpush dword %s\n", nombre) <= 0) {
			printf("Error al meter el operando en la pila");
	}
	fprintf(fpasm, "\t;fin escritura operando -----\n");

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
		fprintf(fpasm, "\tpop dword eax\n\tmov eax, [eax]\n\tmov [_%s], eax\n", nombre);
	}
	else {
		fprintf(fpasm, "\tpop dword eax\n\tmov [_%s], eax\n", nombre);
	}
	fprintf(fpasm, "\t;fin asignacion -----\n\n");

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

	if (!fpasm) {
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
		fprintf(fpasm, "\t;fin suma -----\n\n");

	}
	return;
}
void restar(FILE* fpasm, int es_variable_1, int es_variable_2){

	if (!fpasm) {
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

	if (!fpasm) {
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

		fprintf(fpasm, "\timul ecx\n\tpush eax\n");
	}
	return;
}
void dividir(FILE* fpasm, int es_variable_1, int es_variable_2) {

	if (!fpasm) {
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

		fprintf(fpasm, "\tidiv ecx\n\tpush eax\n");
	}

	return;
}

void o(FILE* fpasm, int es_variable_1, int es_variable_2){
	if (!fpasm) {
		printf("Error de fichero (or)\n");
	}

	else {
		fprintf(fpasm,"\tpop ecx\n\tpop eax\n");     /* Sacamos ambos operandos de la pila */

		if (es_variable_1) {
			fprintf(fpasm, "\tmov eax, [eax]\n");
		}

		if (es_variable_2) {
			fprintf(fpasm, "\tmov ecx, [ecx]\n");
		}

		fprintf(fpasm, "\tor eax, ecx\n\tpush eax\n");
	}

	return;
}

void y(FILE* fpasm, int es_variable_1, int es_variable_2){

	if (!fpasm) {
		printf("Error de fichero (and)\n");
	}

	else {
		fprintf(fpasm,"\tpop ecx\n\tpop eax\n");     /* Sacamos ambos operandos de la pila */

		if (es_variable_1) {
			fprintf(fpasm, "\tmov eax, [eax]\n");
		}

		if (es_variable_2) {
			fprintf(fpasm, "\tmov ecx, [ecx]\n");
		}

		fprintf(fpasm, "\tand eax, ecx\n\tpush eax\n");
	}

	return;
}

/*
   Función aritmética de cambio de signo.
   Es análoga a las binarias, excepto que sólo requiere de un acceso a la pila ya que sólo usa un operando.
*/
void cambiar_signo(FILE* fpasm, int es_variable) {

	if (!fpasm) {
		printf("Error de fichero (cambiar signo)\n");
	}
	else {
		fprintf(fpasm, "\tpush -1\n");

		if (es_variable) {
			multiplicar(fpasm, VARIABLE, NO_VARIABLE);
		} else {
			multiplicar(fpasm, VARIABLE, VARIABLE);
		}
	}

	return;
}

/*
   Función monádica lógica de negación. No hay un código de operación de la ALU
   que realice esta operación por lo que se debe codificar un algoritmo que, si encuentra en la cima de la pila un 0 deja en la cima un 1 y al contrario.
   El último argumento es el valor de etiqueta que corresponde (sin lugar a dudas, la implementación del algoritmo requerirá etiquetas). Véase en los ejemplos de programa principal como puede gestionarse el número de etiquetas cuantos_no.
*/
void no(FILE* fpasm, int es_variable, int cuantos_no) {

	if (!fpasm) {
		printf("Error de fichero (negacion)\n");
	}

	else {
		/*Metemos en eax el argumento*/
		fprintf(fpasm, "\tpop eax\n");

		if (es_variable) {
			fprintf(fpasm, "\tmov eax, [eax]\n");
		}

		/*Comparamos con 0 el argumento */
		fprintf(fpasm, "\tcmp eax, 0\n");
		fprintf(fpasm, "\tje near escribir1_%d\n\tpush dword 0\n\tjmp near fin_no_%d\nescribir1_%d:\n\tpush dword 1\nfin_no_%d:\n", cuantos_no, cuantos_no, cuantos_no, cuantos_no);
	}

	return;
}


/* FUNCIONES COMPARATIVAS */
/*
   Todas estas funciones reciben como argumento si los elementos a comparar son o no variables. El resultado de las operaciones,
   que siempre será un BOOLEAN (“1” si se cumple la comparación y “0” si no se cumple), se deja en la pila como en el resto de
   operaciones. Se deben usar etiquetas para poder gestionar los saltos necesarios para implementar las comparaciones.
*/
void igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta) {
	if (!fpasm) {
		printf("Error de fichero (negacion)\n");
	}

	else {

		fprintf (fpasm, "\tpop ecx\n\tpop eax\n");

		if (es_variable1) {
			fprintf(fpasm, "\tmov eax, [eax]\n");
		}

		if (es_variable2) {
			fprintf(fpasm, "\tmov ecx, [ecx]\n");
		}

		fprintf(fpasm, "\tcmp eax, ecx\n\tje near igual_%d\n\tpush dword 0\n\tjmp near final_%d\nigual_%d:\n\tpush dword 1\nfinal_%d:\n", etiqueta, etiqueta, etiqueta, etiqueta);
		fprintf(fpasm, "\t;fin igualacion -----\n\n");
	}

	return;
}

void distinto(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta) {
	if (!fpasm) {
		printf("Error de fichero (negacion)\n");
	}

	else {

		fprintf (fpasm, "\tpop ecx\n\tpop eax\n");

		if (es_variable1) {
			fprintf(fpasm, "\tmov eax, [eax]\n");
		}

		if (es_variable2) {
			fprintf(fpasm, "\tmov ecx, [ecx]\n");
		}

		fprintf(fpasm, "\tcmp eax, ecx\n\tje near igual_%d\n\tpush dword 1\n\tjmp near final_%d\nigual_%d:\n\tpush dword 0\nfinal_%d:\n", etiqueta, etiqueta, etiqueta, etiqueta);
	}

	return;
}

void menor_igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta) {
	if (!fpasm) {
		printf("Error de fichero (negacion)\n");
	}

	else {

		fprintf (fpasm, "\tpop edx\n\tpop eax\n");

		if (es_variable1) {
			fprintf(fpasm, "\tmov eax, [eax]\n");
		}

		if (es_variable2) {
			fprintf(fpasm, "\tmov edx, [edx]\n");
		}

		fprintf(fpasm, "\tcmp eax, edx\n\tjle near menor_igual_%d\n\tpush dword 0\n\tjmp near final_%d\nmenor_igual_%d:\n\tpush dword 1\nfinal_%d:\n", etiqueta, etiqueta, etiqueta, etiqueta);
	}

	return;
}
void mayor_igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta) {
	if (!fpasm) {
		printf("Error de fichero (negacion)\n");
	}

	else {

		fprintf (fpasm, "\tpop edx\n\tpop eax\n");

		if (es_variable1) {
			fprintf(fpasm, "\tmov eax, [eax]\n");
		}

		if (es_variable2) {
			fprintf(fpasm, "\tmov edx, [edx]\n");
		}

		fprintf(fpasm, "\tcmp eax, edx\n\tjge near mayor_igual_%d\n\tpush dword 0\n\tjmp near final_%d\nmayor_igual_%d:\n\tpush dword 1\nfinal_%d:\n", etiqueta, etiqueta, etiqueta, etiqueta);
	}

	return;
}

void menor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta) {
	if (!fpasm) {
		printf("Error de fichero (negacion)\n");
	}

	else {

		fprintf (fpasm, "\tpop edx\n\tpop eax\n");

		if (es_variable1) {
			fprintf(fpasm, "\tmov eax, [eax]\n");
		}

		if (es_variable2) {
			fprintf(fpasm, "\tmov edx, [edx]\n");
		}

		fprintf(fpasm, "\tcmp eax, edx\n\tjl near menor_%d\n\tpush dword 0\n\tjmp near final_%d\nmenor_%d:\n\tpush dword 1\nfinal_%d:\n", etiqueta, etiqueta, etiqueta, etiqueta);
	}

	return;
}

void mayor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta) {
	if (!fpasm) {
		printf("Error de fichero (negacion)\n");
	}

	else {

		fprintf (fpasm, "\tpop edx\n\tpop eax\n");

		if (es_variable1) {
			fprintf(fpasm, "\tmov eax, [eax]\n");
		}

		if (es_variable2) {
			fprintf(fpasm, "\tmov edx, [edx]\n");
		}

		fprintf(fpasm, "\tcmp eax, edx\n\tjg near mayor_%d\n\tpush dword 0\n\tjmp near final_%d\nmayor_%d:\n\tpush dword 1\nfinal_%d:\n", etiqueta, etiqueta, etiqueta, etiqueta);
	}

	return;
}

/* FUNCIONES DE ESCRITURA Y LECTURA */
/*
   Se necesita saber el tipo de datos que se va a procesar (ENTERO o BOOLEAN) ya que hay diferentes funciones de librería para la lectura (idem. escritura) de cada tipo.
   Se deben insertar en la pila los argumentos necesarios, realizar la llamada (call) a la función de librería correspondiente y limpiar la pila.
*/
void leer(FILE* fpasm, char* nombre, int tipo) {
	if (!fpasm) {
		printf("Error de fichero (lectura)\n");
	}

	else {

		/*fprintf(fpasm, "\tpush dword _%s\n", nombre);*/

		if (tipo == ENTERO) {
			fprintf(fpasm, "\tcall scan_int\n");
		}

		else if (tipo == BOOLEAN) {
			fprintf(fpasm, "\tcall scan_boolean\n");
		}

		else {
			printf("Error en la lectura. Tipo no reconocido\n");
		}

		fprintf(fpasm, "\tadd esp, 4\n");
		fprintf(fpasm, "\t;fin lectura -----\n\n");
	}

	return;
}

void escribir(FILE* fpasm, int es_variable, int tipo) {

	if (!fpasm) {
		printf("Error de fichero (lectura)\n");
	}

	else {

		fprintf(fpasm, "\tpop eax\n");

		if (es_variable) {
			fprintf(fpasm, "\tmov eax, [eax]\n");
		}

		fprintf(fpasm, "\tpush dword eax\n");

		if (tipo == ENTERO) {
			fprintf(fpasm, "\tcall print_int\n");
		}

		else if(tipo == BOOLEAN) {
			fprintf(fpasm, "\tcall print_boolean\n");
		}

		else {
			printf("Error en la escritura. Tipo no reconocido\n");
		}

		fprintf(fpasm, "\tadd esp, 4\n\tcall print_endofline\n");
		fprintf(fpasm, "\t;fin escritura -----\n\n");
	}

	return;

}

void ifthenelse_inicio(FILE* fpasm, int es_direccion, int etiqueta) {
	if (!fpasm) {
		printf("Error de fichero (lectura)\n");
	}

	fprintf(fpasm, "\tpop eax\n");
	if (es_direccion) {
		fprintf(fpasm, "\tmov eax, [eax]\n");
	}
	fprintf(fpasm, "\tcmp eax, 0\n");
	fprintf(fpasm, "\tje near fin_if_%d\n", etiqueta);

	return;
}

void ifthenelse_fin_then(FILE* fpasm, int etiqueta) {
	if (!fpasm) {
		printf("Error de fichero (lectura)\n");
	}

	fprintf(fpasm, "\tjmp near fin_ifelse_%d\n", etiqueta);
	fprintf(fpasm, "fin_if_%d:\n", etiqueta);

	return;
}

void ifthenelse_fin(FILE* fpasm, int etiqueta) {
	if (!fpasm) {
		printf("Error de fichero (lectura)\n");
	}

	fprintf(fpasm, "fin_ifelse_%d:\n", etiqueta);

	return;
}



void inicio_if(FILE* fpasm, int etiqueta, int es_direccion) {
	if (!fpasm) {
		printf("Error de fichero (lectura)\n");
	}

	fprintf(fpasm, "\tpop eax\n");
	if (es_direccion) {
		fprintf(fpasm, "\tmov eax, [eax]\n");
	}
	fprintf(fpasm, "\tcmp eax, 0\n");
	fprintf(fpasm, "\tje near fin_ifsimple_%d\n", etiqueta);

	return;
}

void while_inicio(FILE * fpasm, int etiqueta) {
	if (!fpasm) {
		return;
	}

	fprintf(fpasm, "while_%d:\n", etiqueta);
}

void while_exp_pila(FILE * fpasm, int exp_es_variable, int etiqueta) {
	if (!fpasm) {
		return;
	}

	fprintf(fpasm, "\tpop eax\n");
	if (exp_es_variable) {
		fprintf(fpasm, "\tmov eax, [eax]\n");
	}
	fprintf(fpasm, "\tcmp eax, 0\n");
	fprintf(fpasm, "\tje near fin_while_%d\n", etiqueta);
}

void while_fin(FILE * fpasm, int etiqueta) {
	if (!fpasm) {
		return;
	}

	fprintf(fpasm, "\twhile_%d:\n", etiqueta);
	fprintf(fpasm, "fin_while_%d:\n", etiqueta);
}
