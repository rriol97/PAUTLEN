#include <stdio.h>
#include "generacion_omicron.h"


/*comprobar si tiene sentido*/
void asignarDestinoEnPila(FILE* fpasm, int es_variable) {
    fprintf(fpasm, "\tpop dword eax\n");
    if (es_variable) {
		fprintf(fpasm, "\tmov eax, [eax]\n");
	}
    fprintf(fpasm, "\tmov [esp], eax\n");

}

void instance_of (FILE * fd_asm, char * nombre_fuente_clase, 
                  int numero_atributos_instancia) {

    fprintf(fd_asm, "push dword %d\n", numero_atributos_instancia + 1);
    fprintf(fd_asm, "call malloc\n");
    fprintf(fd_asm, "add esp, 4\n");
    /*se deja el resultado en la cima de la pila*/
    fprintf(fd_asm, "push eax\n", nombre_fuente_clase);

}

void discardPila (FILE * fd_asm) {
    fprintf(fd_asm, "call free\n");
    fprintf(fd_asm, "add esp, 4\n");
}

/*nota: lo que digo sobre los bucles, probablemente convenga hacer un unico bucle al principio que guarde de que tipo es cada cosa y hacer los demas bucles sobre los subconjuntos obtenidos*/
void tablaSimbolosClasesANasm(FILE * fd_asm, TablaSimbolosClases* t) {
    if(fd_asm == NULL) {
        printf("Error de fichero\n");
        return;
    }
    if(t == NULL) {
        printf("Error: tabla de simbolos de clases no definida\n");
        return;
    }
    fprintf(fd_asm, "\tglobal ");
    /*bucle sobre todos los simbolos de todas las clases*/
    fprintf(fd_asm, "_set_offsets, _create_ms_table, _no_defined_method");
    fprintf(fd_asm, "\n\n");
    fprintf(fd_asm, "segment .data\n");
    fprintf(fd_asm, "\tmsg_error_indice_vector\tdb \"Indice de vector fuera de rango\", 0\n");
    /*bucle sobre los simbolos: si son ms que no estan sobreescribiendo uno anterior, añadir su offset*/

    /*bucle sobre los simbolos: si son at i que no estan sobreescribiendo uno anterior, añadir su offset*/

    fprintf(fd_asm, "segment .bss\n");
    fprintf(fd_asm, "\t__esp resd 4\n");
    /*bucle sobre las clases: escribir el tamaño*/

    /*bucle sobre los simbolos: si son objetos, escribirlos aqui*/

    /*bucle sobre los simbolos: si son at c escribirlos aqui*/

    fprintf(fd_asm, "segment .text\n");
    fprintf(fd_asm, "\textern malloc, free\n");
    fprintf(fd_asm, "\textern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean\n");
    fprintf(fd_asm, "\textern print_endofline, print_blank, print_string\n");
    fprintf(fd_asm, "\textern alfa_malloc, alfa_free, ld_float\n");

    /*bucle sobre los simbolos: si son ms escribir su def*/

    fprintf(fd_asm, "\t_no_defined_method\n");
    fprintf(fd_asm, "\t\tpush dword 0\n");
    fprintf(fd_asm, "\t\tcall print_int\n");
    fprintf(fd_asm, "\t\tadd esp, 4\n");
    fprintf(fd_asm, "\t\tcall print_endofline\n");
    fprintf(fd_asm, "\t\tret\n");

    /*bucle sobre los simbolos: si son mns escribir su def*/

    fprintf(fd_asm, "\t_set_offsets\n"); /*implementado en data*/
    fprintf(fd_asm, "\t\tret\n");
    fprintf(fd_asm, "\t_create_ms_table\n");

    /*escribir tabla de ms*/
}
