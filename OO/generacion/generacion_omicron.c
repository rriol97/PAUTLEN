#include <stdio.h>
#include "generacion_omicron.h"

char * claseATabla(char * nombre_fuente_clase) {
    char* nombre_tabla;
    if(nombre_fuente_clase == NULL)
        return NULL;
    nombre_tabla = malloc(sizeof(char) * (strlen(nombre_fuente_clase) + strlen(PREFIJO_TABLA_METODOS_SOBREESCRIBIBLES) + 1));
    nombre_tabla = strcpy(nombre_tabla, PREFIJO_TABLA_METODOS_SOBREESCRIBIBLES);
    nombre_tabla = strcat(nombre_tabla, nombre_fuente_clase);
    return nombre_tabla;
}

void instance_of (FILE * fpasm, char * nombre_fuente_clase,
                  int numero_atributos_instancia) {
    char* nombre_tabla;
    if(fpasm == NULL)
        return;
    nombre_tabla = claseATabla(nombre_fuente_clase);
    if(nombre_tabla == NULL)
        return;

    fprintf(fpasm, "push dword %d\n", (numero_atributos_instancia + 1)*4);
    fprintf(fpasm, "call malloc\n");
    fprintf(fpasm, "add esp, 4\n");
    /*meto la tabla de ms en el lugar correspondiente*/
    fprintf(fpasm, "mov dword [eax], %s\n", nombre_tabla);
    /*se deja el resultado en la cima de la pila*/
    fprintf(fpasm, "push eax\n");

    free(nombre_tabla);
}

void discardPila (FILE * fpasm) {
    if(fpasm == NULL)
        return;

    fprintf(fpasm, "call free\n");
    fprintf(fpasm, "add esp, 4\n");
}

void llamarMetodoSobreescribibleCualificadoInstanciaPila(FILE * fpasm, char * nombre_metodo) {
    if(fpasm == NULL || nombre_metodo == NULL)
        return;

    fprintf(fpasm, "pop dword ebx\n");
    /*ebx = [_msa]*/
    fprintf(fpasm, "mov dword ebx, [ebx]\n");
    fprintf(fpasm, "mov dword ecx, [_offset_%s]\n", nombre_metodo);
    fprintf(fpasm, "lea ecx, [ebx+ecx]\n");
    fprintf(fpasm, "mov ecx, [ecx]\n");
    /*gestion de parametros?*/
    fprintf(fpasm, "call ecx\n");
}

void limpiarPila(FILE * fpasm, int num_argumentos) {
    if(fpasm == NULL || num_argumentos < 0)
        return;
    fprintf(fpasm, "add esp, %d\n", 4*num_argumentos);
}

void accederAtributoInstanciaDePila(FILE * fpasm, char * nombre_atributo) {
    if(fpasm == NULL || nombre_atributo == NULL)
        return;

    fprintf(fpasm, "pop dword ebx\n");
    fprintf(fpasm, "mov dword ecx, [_offset_%s]\n", nombre_atributo);
    fprintf(fpasm, "lea ecx, [ebx+ecx]\n");
}


/*comprobar si tiene sentido*/
void asignarDestinoEnPila(FILE* fpasm, int es_variable) {
    if(fpasm == NULL)
        return;

    fprintf(fpasm, "\tpop dword edx\n");
    fprintf(fpasm, "\tpop dword eax\n");
    if (es_variable) {
        fprintf(fpasm, "\tmov eax, [eax]\n");
    }
    fprintf(fpasm, "mov [edx], eax\n");
    fprintf(fpasm, "sub esp, 4\n");
}
