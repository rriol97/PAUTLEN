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
    /*Reservo memoria para la instancia*/
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
    /*la direccion esta en la cima de la pila, sacamos la instancia a liberar*/
    fprintf(fpasm, "pop dword ebx\n");
    /*metemos la instancia como parametro*/
    fprintf(fpasm, "push dword [ebx]\n");
    /*llamamos a free*/
    fprintf(fpasm, "call free\n");
    fprintf(fpasm, "add esp, 4\n");
}

void llamarMetodoSobreescribibleCualificadoInstanciaPila(FILE * fpasm, char * nombre_metodo) {
    if(fpasm == NULL || nombre_metodo == NULL)
        return;
    
    /*saco la instancia de la pila*/
    fprintf(fpasm, "pop dword ebx\n");
    /*TODO: comprobar si hay que hacer otro mov dword ebx, [ebx]*/
    /*obtengo la direccion de la tabla de metodos*/
    fprintf(fpasm, "mov dword ebx, [ebx]\n");
    /*obtengo el offset del metodo*/
    fprintf(fpasm, "mov dword ecx, [_offset_%s]\n", nombre_metodo);
    /*obtengo la direccion del metodo*/
    fprintf(fpasm, "lea ecx, [ebx+ecx]\n");
    /*obtengo el metodo*/
    fprintf(fpasm, "mov ecx, [ecx]\n");
    /*suponemos que la gestion de parametros se ha hecho previamente
    de forma que los parametros estan en la pila por debajo de la instancia*/
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

    /*extraigo la instancia de la pila*/
    fprintf(fpasm, "pop dword ebx\n");
    /*TODO: comprobar si hay que hacer otro mov dword ebx, [ebx]*/
    /*obtengo el offset del atributo*/
    fprintf(fpasm, "mov dword ecx, [_offset_%s]\n", nombre_atributo);
    /*obtengo la direccion del atributo*/
    fprintf(fpasm, "lea ecx, [ebx+ecx]\n");
    /*introduzco la direccion del atributo en pila*/
    fprintf(fpasm, "push dword ecx\n");
}

void asignarDestinoEnPila(FILE* fpasm, int es_variable) {
    if(fpasm == NULL)
        return;

    /*obtengo la direccion donde dejar el valor*/
    fprintf(fpasm, "\tpop dword edx\n");
    /*obtengo el valor*/
    fprintf(fpasm, "\tpop dword eax\n");
    if (es_variable) {
        /*si es variable obtengo el valor que contiene*/
        fprintf(fpasm, "\tmov eax, [eax]\n");
    }
    /*asigno el valor en la direccion*/
    fprintf(fpasm, "mov [edx], eax\n");
}
