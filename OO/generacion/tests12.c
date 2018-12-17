#include <stdio.h>
#include "generacion_omicron.h"



int main(int argc, char ** argv)
{
    FILE * fd_asm;


    fd_asm = fopen(argv[1],"w");
    escribir_subseccion_data(fd_asm);

    
    escribir_cabecera_bss(fd_asm);
    
    // {A} a;
    declarar_variable(fd_asm, "a", 0, 1);
    // {B} b;
    declarar_variable(fd_asm, "b",  1,  1);
    // {C} c;
    declarar_variable(fd_asm, "c",  2,  1);

    // {C} c2;
    declarar_variable(fd_asm, "c2",  2,  1);

    escribir_segmento_codigo(fd_asm);
    fprintf(fd_asm,"\textern _msbA,  _msbB, _BmsbA, _msbC, _CmsbA, _CmsbB, _no_defined_method, _mcA, _mcB, _mcC,  _set_offsets, _create_ms_table, _offset_msbA, _offset_msbB,  _offset_msbC,  _offset_aia, _offset_aib, _offset_aic, _msA, _msB, _msC, _aca, _acb, _acc\n");


//*********************************
    // {C} factorial({C} parC)
    // { int var1, {C} var2;
    declararFuncion(fd_asm, "main_factorial@o2", 2);

    //    var2 = instance_of C();
    instance_of(fd_asm,"C",6);
    escribirVariableLocal(fd_asm,2);
    asignarDestinoEnPila(fd_asm,0);

    //    var2.aic = 9999;
    escribir_operando(fd_asm, "9999",0);
    escribirVariableLocal(fd_asm,2);
    accederAtributoInstanciaDePila(fd_asm, "aic");
    asignarDestinoEnPila(fd_asm, 0);

    //    print var2.aic;
    escribirVariableLocal(fd_asm,2);
    accederAtributoInstanciaDePila(fd_asm, "aic");
    escribir(fd_asm,1,ENTERO);

    //     printf parC.aic;
    escribirParametro(fd_asm, 0, 1);
    accederAtributoInstanciaDePila(fd_asm, "aic");
    escribir(fd_asm,1,ENTERO);

    //      return var2;
    escribirVariableLocal(fd_asm,2);
    retornarFuncion(fd_asm, 1);
    //}

//**********************************


// PROGRAMA PRINCIPAL

    escribir_inicio_main(fd_asm);
    fprintf(fd_asm,"\tcall _create_ms_table\n");


    // c = instanceof C;
    instance_of(fd_asm,"C",3);
    escribir_operando(fd_asm,"c",1);
    asignarDestinoEnPila(fd_asm,0);

    // c.aia= 10;
    escribir_operando(fd_asm, "10",0);
    escribir_operando(fd_asm, "c", 1);
    accederAtributoInstanciaDePila(fd_asm, "aia");
    asignarDestinoEnPila(fd_asm, 0);


    // c.aib= 100;
    escribir_operando(fd_asm, "100",0);
    escribir_operando(fd_asm, "c", 1);
    accederAtributoInstanciaDePila(fd_asm, "aib");
    asignarDestinoEnPila(fd_asm, 0);

    // c.aic= 1000;
    escribir_operando(fd_asm, "1000",0);
    escribir_operando(fd_asm, "c", 1);
    accederAtributoInstanciaDePila(fd_asm, "aic");
    asignarDestinoEnPila(fd_asm, 0);

    // b = c;
    escribir_operando(fd_asm,"c",1);
    escribir_operando(fd_asm,"b",1);
    asignarDestinoEnPila(fd_asm,1);
    
    // a = b;
    escribir_operando(fd_asm,"b",1);
    escribir_operando(fd_asm,"a",1);
    asignarDestinoEnPila(fd_asm,1);

    // printf a.aia;
    escribir_operando(fd_asm, "a", 1);
    accederAtributoInstanciaDePila(fd_asm, "aia");
    escribir(fd_asm,1,ENTERO);

    // printf b.aib;
    escribir_operando(fd_asm, "b", 1);
    accederAtributoInstanciaDePila(fd_asm, "aib");
    escribir(fd_asm,1,ENTERO);

    // printf c.aic;
    escribir_operando(fd_asm, "c", 1);
    accederAtributoInstanciaDePila(fd_asm, "aic");
    escribir(fd_asm,1,ENTERO);

    // c.msC();
    escribir_operando(fd_asm,"c",1);
    llamarMetodoSobreescribibleCualificadoInstanciaPila(fd_asm, "msbC");


    // c.msA();
    escribir_operando(fd_asm,"c",1);
    llamarMetodoSobreescribibleCualificadoInstanciaPila(fd_asm, "msbA");


    // b = instanceof B;
    instance_of(fd_asm,"B",2);
    escribir_operando(fd_asm,"b",1);
    asignarDestinoEnPila(fd_asm,0);

    // a = instanceof A;
    instance_of(fd_asm,"A",1);
    escribir_operando(fd_asm,"a",1);
    asignarDestinoEnPila(fd_asm,0);


    // a.msA();
    escribir_operando(fd_asm,"a",1);
    llamarMetodoSobreescribibleCualificadoInstanciaPila(fd_asm, "msbA");


    // b.msA();
    escribir_operando(fd_asm,"b",1);
    llamarMetodoSobreescribibleCualificadoInstanciaPila(fd_asm, "msbA");


    // c.msA();
    escribir_operando(fd_asm,"c",1);
    llamarMetodoSobreescribibleCualificadoInstanciaPila(fd_asm, "msbA");


//*******************

    // c2 = factorial(c);

    escribir_operando(fd_asm,"c",1);
    operandoEnPilaAArgumento(fd_asm,1);
    llamarFuncion(fd_asm,"main_factorial@o2",1);
    asignar(fd_asm,"c2",0);

    // printf c2.aic;

    escribir_operando(fd_asm,"c2",1);
    accederAtributoInstanciaDePila(fd_asm, "aic");
    escribir(fd_asm,1,ENTERO);

    // discard c2;
    escribir_operando(fd_asm,"c2",1);
    discardPila(fd_asm);


//************************

    // discard a;
    escribir_operando(fd_asm,"a",1);
    discardPila(fd_asm);

    // discard b;
    escribir_operando(fd_asm,"b",1);
    discardPila(fd_asm);


    // discard c;
    escribir_operando(fd_asm,"c",1);
    discardPila(fd_asm);




    escribir_fin(fd_asm);
    fclose(fd_asm);    

    return 0;
}


