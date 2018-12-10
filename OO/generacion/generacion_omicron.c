#include <stdio.h>
#include "generacion_omicron.h"


elementoTablaSimbolos* mss[MAX_ETIQUETAS];
int n_mss = 0;
elementoTablaSimbolos* mnss[MAX_ETIQUETAS];
int n_mnss = 0;
elementoTablaSimbolos* ais[MAX_ETIQUETAS];
int n_ais = 0;
elementoTablaSimbolos* acs[MAX_ETIQUETAS];
int n_acs = 0;
NodoGrafo* clases[MAX_ETIQUETAS];
int n_clases = 0;

/*comprobar si tiene sentido*/
void asignarDestinoEnPila(FILE* fpasm, int es_variable) {
    fprintf(fpasm, "\tpop dword eax\n");
    if (es_variable) {
        fprintf(fpasm, "\tmov eax, [eax]\n");
    }
    fprintf(fpasm, "\tmov [esp], eax\n");
    fprintf(fd_asm, "sub esp, 4\n");
}

void instance_of (FILE * fd_asm, char * nombre_fuente_clase,
                  int numero_atributos_instancia) {

    fprintf(fd_asm, "push dword %d\n", (numero_atributos_instancia + 1)*4);
    fprintf(fd_asm, "call malloc\n");
    fprintf(fd_asm, "add esp, 4\n");
    /*se deja el resultado en la cima de la pila*/
    fprintf(fd_asm, "push eax\n");

}

void discardPila (FILE * fd_asm) {
    fprintf(fd_asm, "call free\n");
    fprintf(fd_asm, "add esp, 4\n");
}
