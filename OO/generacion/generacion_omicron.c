#include <stdio.h>
#include "generacion_omicron.h"

#define MAX_NUM 1000

elementoTablaSimbolos* mss[MAX_NUM];
int n_mss = 0; 
elementoTablaSimbolos* mnss[MAX_NUM];
int n_mnss = 0; 
elementoTablaSimbolos* ais[MAX_NUM];
int n_ais = 0; 
elementoTablaSimbolos* acs[MAX_NUM];
int n_acs = 0; 
NodoGrafo* clases[MAX_NUM];
int n_clases = 0;

void rellenarLista(TablaSimbolosClases* t) {
    int i;
    Hash *point, *tmp;
    NodoGrafo* class;
    elementoTablaSimbolos* e;
    Graph* grafo = tablaSimbolosClasesGrafo(t);
    for(i = 0; (class=graphGetClass(grafo, i)) != NULL; i++) {
        clases[i] = clases;
        HASH_ITER(hh, class->tabla->th_ppal, point, tmp) {
            e = point->value;
            switch(e->clase) {
                case METODO_SOBREESCRIBIBLE:
                    mss[n_mss] = e;
                    n_mss++;
                    break;
                case METODO_NO_SOBREESCRIBIBLE:
                    mnss[n_mnss] = e;
                    n_mnss++;
                    break;
                case ATRIBUTO_CLASE:
                    acs[n_acs] = e;
                    n_acs++;
                    break;
                case ATRIBUTO_INSTANCIA:
                    ais[n_ais] = e;
                    n_ais++;
                    break;
                default:
                    break;
            }
        }
    }
    n_clases = i;
}


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
    fprintf(fd_asm, "push eax\n");

}

void discardPila (FILE * fd_asm) {
    fprintf(fd_asm, "call free\n");
    fprintf(fd_asm, "add esp, 4\n");
}

/*nota: lo que digo sobre los bucles, probablemente convenga hacer un unico bucle al principio que guarde de que tipo es cada cosa y hacer los demas bucles sobre los subconjuntos obtenidos*/
void tablaSimbolosClasesANasm(FILE * fd_asm, TablaSimbolosClases* t) {
    int i, j;
    if(fd_asm == NULL) {
        printf("Error de fichero\n");
        return;
    }
    if(t == NULL) {
        printf("Error: tabla de simbolos de clases no definida\n");
        return;
    }
    rellenarLista(t);
    fprintf(fd_asm, "\tglobal ");
    /*bucle sobre todos los simbolos de todas las clases*/
    /*TODO*/
    fprintf(fd_asm, "_set_offsets, _create_ms_table, _no_defined_method");
    fprintf(fd_asm, "\n\n");

    fprintf(fd_asm, "segment .data\n");
    fprintf(fd_asm, "\tmsg_error_indice_vector\tdb \"Indice de vector fuera de rango\", 0\n");
    /*bucle sobre los simbolos: si son ms que no estan sobreescribiendo uno anterior, añadir su offset*/
    for(i = 0, j = 0; i < n_mss; i++) {
        if(mss[i]->posicion_acumulada_metodos_sobreescritura == j*4) {
            /*no sobreescribe*/
            fprintf(fd_asm, "\t_offset_%s dd %d\n", mss[i]->clave, mss[i]->posicion_acumulada_metodos_sobreescritura);
            j++;
        }
    }

    /*bucle sobre los simbolos: si son at i que no estan sobreescribiendo uno anterior, añadir su offset*/
    for(i = 0; i < n_ais; i++) {
        fprintf(fd_asm, "\t_offset_%s dd %d\n", ais[i]->clave, ais[i]->posicion_acumulada_atributos_instancia + 4);
    }

    fprintf(fd_asm, "segment .bss\n");
    fprintf(fd_asm, "\t__esp resd 4\n");
    /*bucle sobre las clases: escribir el tamaño de la tabla de ms*/
    for(i = 0, j = 0; i < n_clases; i++) {
        j += clases[i]->num_me_s;
        fprintf(fd_asm, "\t_ms%s resd %d\n", clases[i]->nombre, j);
    }
    /*bucle sobre los simbolos: si son objetos, escribirlos aqui*/
    /*no se como va esto, parece necesitar acceso a main que no tenemos*/
    /*posiblemente no sea necesario aqui*/

    /*bucle sobre los simbolos: si son at c escribirlos aqui*/
    for(i = 0; i < n_acs; i++) {
        fprintf(fd_asm, "\t_%s resd 1\n", acs[i]->clave);
    }

    fprintf(fd_asm, "segment .text\n");
    fprintf(fd_asm, "\textern malloc, free\n");
    fprintf(fd_asm, "\textern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean\n");
    fprintf(fd_asm, "\textern print_endofline, print_blank, print_string\n");
    fprintf(fd_asm, "\textern alfa_malloc, alfa_free, ld_float\n");

    /*bucle sobre los simbolos: si son ms escribir su def*/
    for(i = 0; i < n_mss; i++) {
        fprintf(fd_asm, "_%s:\n", mss[i]->clave);
        /*TODO: def?*/
    }

    fprintf(fd_asm, "\t_no_defined_method\n");
    fprintf(fd_asm, "\t\tpush dword 0\n");
    fprintf(fd_asm, "\t\tcall print_int\n");
    fprintf(fd_asm, "\t\tadd esp, 4\n");
    fprintf(fd_asm, "\t\tcall print_endofline\n");
    fprintf(fd_asm, "\t\tret\n");

    /*bucle sobre los simbolos: si son mns escribir su def*/
    for(i = 0; i < n_mnss; i++) {
        fprintf(fd_asm, "_%s:\n", mnss[i]->clave);
        /*TODO: def?*/
    }

    fprintf(fd_asm, "\t_set_offsets\n"); /*implementado en data*/
    fprintf(fd_asm, "\t\tret\n");
    fprintf(fd_asm, "\t_create_ms_table\n");

    /*escribir tabla de ms*/
}
