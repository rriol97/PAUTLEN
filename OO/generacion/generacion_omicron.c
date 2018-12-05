#include <stdio.h>
#include "generacion_omicron.h"

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


