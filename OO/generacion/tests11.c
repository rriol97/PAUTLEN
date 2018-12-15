#include <stdio.h>
#include "generacion_omicron.h"



int main(int argc, char ** argv)
{
    FILE * fd_asm;


    fd_asm = fopen(argv[1],"w");
    escribir_subseccion_data(fd_asm);

    
    escribir_cabecera_bss(fd_asm);
    
    declarar_variable(fd_asm, "a", 0, 1);
    declarar_variable(fd_asm, "b",  1,  1);
    declarar_variable(fd_asm, "c",  2,  1);

    escribir_segmento_codigo(fd_asm);
    fprintf(fd_asm,"\textern _msA,  _msB, _BmsA, _msC, _CmsA, _CmsB, _no_defined_method, _mcA, _mcB, _mcC,  _set_offsets, _create_ms_table, _offset_msA, _offset_msB,  _offset_msC,  _offset_aia, _offset_aib, _offset_aic, _msA, _msB, _msC, _aca, _acb, _acc\n");





    escribir_inicio_main(fd_asm);
    fprintf(fd_asm,"\tcall _create_ms_table\n");


    instance_of(fd_asm,"C",3);
    escribir_operando(fd_asm,"c",1);
    asignarDestinoEnPila(fd_asm,0);

    escribir_operando(fd_asm,"c",1);
    escribir_operando(fd_asm,"b",1);
    asignarDestinoEnPila(fd_asm,1);
    
    escribir_operando(fd_asm,"b",1);
    escribir_operando(fd_asm,"a",1);
    asignarDestinoEnPila(fd_asm,1);


    escribir_operando(fd_asm,"c",1);
    discardPila(fd_asm);


    instance_of(fd_asm,"B",2);
    escribir_operando(fd_asm,"b",1);
    asignarDestinoEnPila(fd_asm,0);

    instance_of(fd_asm,"A",1);
    escribir_operando(fd_asm,"a",1);
    asignarDestinoEnPila(fd_asm,0);

    escribir_operando(fd_asm,"a",1);
    discardPila(fd_asm);

    escribir_operando(fd_asm,"b",1);
    discardPila(fd_asm);

    escribir_fin(fd_asm);
    fclose(fd_asm);    

    return 0;
}
