
void asignarDestinoEnPila(FILE* fpasm, int es_variable);

/*  push dword <1 + n_at_instancia>
    call malloc
    add esp, 4
    mov [<variable>], eax*/
void instance_of (FILE * fd_asm, char * nombre_fuente_clase, 
                  int numero_atributos_instancia);

/*add esp, 4*/
void discardPila (FILE * fd_asm);
