#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabla.h"

int dotTest() {
    NodoGrafo class[5];
    int i;
    FILE* fsalida;
    Graph* graph = createGraph();
    if(graph == NULL) {
        fprintf(stderr, "Error while creating graph");
        return 1;
    }
    fsalida = fopen("grafo.dot", "w");
    if(fsalida == NULL) {
        freeGraph(graph);
        fprintf(stderr, "Error while opening file");
        return 1;
    }
    strcpy(class[0].name, "Persona");
    strcpy(class[1].name, "Infante");
    strcpy(class[2].name, "Adulto");
    strcpy(class[3].name, "Anciano");
    strcpy(class[4].name, "Depotista");
    for(i = 0; i < 5; i++) {
        class[i].tabla = tablaInit(class[i].name);
        graphAddClass(graph, &class[i]);
    }
    insert_symbol(&(class[0].tabla->th_ppal), "esmujer", NULL);
    insert_symbol(&(class[0].tabla->th_ppal), "edad", NULL);
    insert_symbol(&(class[1].tabla->th_ppal), "percentil", NULL);
    insert_symbol(&(class[2].tabla->th_ppal), "percentil", NULL);
    insert_symbol(&(class[3].tabla->th_ppal), "sumar()", NULL);
    graphAddEdge(graph, 0, 1);
    graphAddEdge(graph, 0, 2);
    graphAddEdge(graph, 0, 3);
    graphAddEdge(graph, 1, 4);
    graphAddEdge(graph, 2, 4);
    graphAddEdge(graph, 3, 4);

    /* print the adjacency list representation of the above graph */
    graphToDot(graph, fsalida);
    for(i = 0; i < 5; i++) {
        tablaFree(class[i].tabla);
    }

    fclose(fsalida);
    freeGraph(graph);

    return 0;
}

int testTabla(char* fname) {
    TablaAmbito* tabla_main; /* Tabla de simbolos de main*/

    TablaSimbolosClases * ej_tabla_clases = NULL;

    FILE* fsalida = fopen(fname, "w");
    /* Inicializar la tabla de simbolos del main (ambito por defecto) */
    tabla_main = tablaInit("main");

    /* Inicializar la tabla de las clases */
    iniciarTablaSimbolosClases(&ej_tabla_clases, "ej_clases");

    /* Clase AA: tiene 1 atributo de instancia y uno de clase, tambien un metodo */
    abrirClase(ej_tabla_clases,"AA");
    graph_enrouteParentsLastNode(ej_tabla_clases);

    cerrarClase(ej_tabla_clases,"AA",0,0,0,0);

    abrirClaseHereda(ej_tabla_clases, "BB", "AA", NULL);
    graph_enrouteParentsLastNode(ej_tabla_clases);

    cerrarClase(ej_tabla_clases,"BB",0,0,0,0);

    /* Cerrar las tablas de simbolos */
    cerrarTablaSimbolosClases(ej_tabla_clases);

    tablaSimbolosClasesToDot(ej_tabla_clases, fsalida);

    /*liberarTablaSimbolosAmbitos(&tabla_main);*/
    tablaFree(tabla_main);
    liberarTablaSimbolosClases(ej_tabla_clases);
    fclose(fsalida);
    return 0;
}

int Test2(){
    TablaAmbito* tabla_main; /* Tabla de simbolos de main*/
    TablaSimbolosClases * ej_tabla_clases = NULL;
    char nombre_ambito_encontrado[MAX_NAME];
    elementoTablaSimbolos* e = NULL;
    FILE* fsalida = fopen("salida.txt", "w");

    /* Inicializar la tabla de simbolos del main (ambito por defecto) */
    tabla_main = tablaInit("main");

    /* Inicializar la tabla de las clases */
    iniciarTablaSimbolosClases(&ej_tabla_clases, "ej_clases");

    /* Declarar variable global int v1*/
    insertarTablaSimbolosAmbitos(tabla_main, "main", "v1", ESCALAR, INT, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, NINGUNO, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    /* Clase AA: tiene 8 metodos */
    abrirClase(ej_tabla_clases,"AA");
    graph_enrouteParentsLastNode(ej_tabla_clases);

    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "mA1@1", ESCALAR, INT, FUNCION, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_HERENCIA, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
    abrirAmbitoEnClase(ej_tabla_clases, "AA", "mA1@1", ESCALAR, ACCESO_TODOS, INT, 0, 1);
    
    if(buscarParaDeclararIdLocalEnMetodo(ej_tabla_clases, "AA", "p1", &e, nombre_ambito_encontrado) == ERR){
      printf("CASO 60:OK. NO SE HA ENCONTRADO EL ID Y SE PUEDE DECLARAR");
        insertarTablaSimbolosClases(ej_tabla_clases, "AA", "p1", ESCALAR, INT, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_CLASE, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
    }
    else printf("CASO 60:FALLIDO. SE HA ENCONTRADO EL ID Y NO SE PUEDE DECLARAR");
    printf("\n");

    cerrarAmbitoEnClase(ej_tabla_clases, "AA");
    
    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "mA2@1@1", ESCALAR, INT, FUNCION, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_HERENCIA, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
    abrirAmbitoEnClase(ej_tabla_clases, "AA", "mA2@1@1", ESCALAR, ACCESO_TODOS, INT, 0, 1);
    
    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "p1", ESCALAR, INT, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_CLASE, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
    if(buscarParaDeclararIdLocalEnMetodo(ej_tabla_clases, "AA", "p1", &e, nombre_ambito_encontrado) == ERR){
        printf("CASO 61:FALLIDO. NO SE HA ENCONTRADO EL ID Y SE PUEDE DECLARAR");
        insertarTablaSimbolosClases(ej_tabla_clases, "AA", "p1", ESCALAR, INT, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_CLASE, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
    }
    else printf("CASO 61:OK. SE HA ENCONTRADO EL ID Y NO SE PUEDE DECLARAR");
    printf("\n");
    
    cerrarAmbitoEnClase(ej_tabla_clases, "AA");
    
    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "mA3@1@3", ESCALAR, INT, FUNCION, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_HERENCIA, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
    abrirAmbitoEnClase(ej_tabla_clases, "AA", "mA3@1@3", ESCALAR, ACCESO_TODOS, INT, 0, 1);
    
    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "p1", ESCALAR, INT, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_CLASE, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
    if(buscarParaDeclararIdLocalEnMetodo(ej_tabla_clases, "AA", "mA3", &e, nombre_ambito_encontrado) == ERR){
        printf("CASO 62:OK. NO SE HA ENCONTRADO EL ID Y SE PUEDE DECLARAR");
        insertarTablaSimbolosClases(ej_tabla_clases, "AA", "mA3", ESCALAR, INT, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_CLASE, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
    }
    else printf("CASO 62:FALLIDO. SE HA ENCONTRADO EL ID Y NO SE PUEDE DECLARAR");
    printf("\n");

    cerrarAmbitoEnClase(ej_tabla_clases, "AA");
    
    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "mA4", ESCALAR, INT, FUNCION, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_HERENCIA, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
    abrirAmbitoEnClase(ej_tabla_clases, "AA", "mA4", ESCALAR, ACCESO_TODOS, INT, 0, 1);
    
    if(buscarParaDeclararIdLocalEnMetodo(ej_tabla_clases, "AA", "v2", &e, nombre_ambito_encontrado) == ERR){
        printf("CASO 63:OK. NO SE HA ENCONTRADO EL ID Y SE PUEDE DECLARAR");
        insertarTablaSimbolosClases(ej_tabla_clases, "AA", "v2", ESCALAR, INT, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_CLASE, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
    }
    else printf("CASO 63:FALLIDO. SE HA ENCONTRADO EL ID Y NO SE PUEDE DECLARAR");
    printf("\n");
    
    cerrarAmbitoEnClase(ej_tabla_clases, "AA");

    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "mA5@1", ESCALAR, INT, FUNCION, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_HERENCIA, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
    abrirAmbitoEnClase(ej_tabla_clases, "AA", "mA5@1", ESCALAR, ACCESO_TODOS, INT, 0, 1);
    
    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "v1", ESCALAR, INT, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_CLASE, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
    if(buscarParaDeclararIdLocalEnMetodo(ej_tabla_clases, "AA", "v1", &e, nombre_ambito_encontrado) == ERR){
        printf("CASO 64:FALLIDO. NO SE HA ENCONTRADO EL ID Y SE PUEDE DECLARAR");
    }
    else printf("CASO 64:OK. SE HA ENCONTRADO EL ID Y NO SE PUEDE DECLARAR");
    printf("\n");
    
    cerrarAmbitoEnClase(ej_tabla_clases, "AA");

    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "mA6", ESCALAR, INT, FUNCION, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_HERENCIA, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
    abrirAmbitoEnClase(ej_tabla_clases, "AA", "mA6", ESCALAR, ACCESO_TODOS, INT, 0, 1);
    
    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "v1", ESCALAR, INT, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_CLASE, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
    if(buscarParaDeclararIdLocalEnMetodo(ej_tabla_clases, "AA", "v1", &e, nombre_ambito_encontrado) == ERR){
        printf("CASO 65:FALLIDO. NO SE HA ENCONTRADO EL ID Y SE PUEDE DECLARAR");
    }
    else printf("CASO 65:OK. SE HA ENCONTRADO EL ID Y NO SE PUEDE DECLARAR");
    printf("\n");
    
    cerrarAmbitoEnClase(ej_tabla_clases, "AA");

    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "mA7@1", ESCALAR, INT, FUNCION, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_HERENCIA, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
    abrirAmbitoEnClase(ej_tabla_clases, "AA", "mA7@1", ESCALAR, ACCESO_TODOS, INT, 0, 1);
    
    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "p1", ESCALAR, INT, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_CLASE, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
    if(buscarParaDeclararIdLocalEnMetodo(ej_tabla_clases, "AA", "mA7", &e, nombre_ambito_encontrado) == ERR){
        printf("CASO 66:OK. NO SE HA ENCONTRADO EL ID Y SE PUEDE DECLARAR");
    }
    else printf("CASO 66:FALLIDO. SE HA ENCONTRADO EL ID Y NO SE PUEDE DECLARAR");
    printf("\n");
    
    cerrarAmbitoEnClase(ej_tabla_clases, "AA");

    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "mA8", ESCALAR, INT, FUNCION, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_HERENCIA, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
    abrirAmbitoEnClase(ej_tabla_clases, "AA", "mA8", ESCALAR, ACCESO_TODOS, INT, 0, 1);
    
    if(buscarParaDeclararIdLocalEnMetodo(ej_tabla_clases, "AA", "mA8", &e, nombre_ambito_encontrado) == ERR){
        printf("CASO 67:OK. NO SE HA ENCONTRADO EL ID Y SE PUEDE DECLARAR");
    }
    else printf("CASO 67:FALLIDO. SE HA ENCONTRADO EL ID Y NO SE PUEDE DECLARAR");
    printf("\n");
    
    cerrarAmbitoEnClase(ej_tabla_clases, "AA");


    cerrarAmbitoPrefijos(tabla_main);

    cerrarAmbito(tabla_main);

    /* Cerrar las tablas de simbolos */
    cerrarTablaSimbolosClases(ej_tabla_clases);

    tablaSimbolosClasesToDot(ej_tabla_clases, fsalida);

    tablaFree(tabla_main);
    liberarTablaSimbolosClases(ej_tabla_clases);
    fclose(fsalida);
    return 0;
}

int TestNuevo(){
    TablaAmbito* tabla_main; /* Tabla de simbolos de main*/
    TablaSimbolosClases * ej_tabla_clases = NULL;
    char nombre_ambito_encontrado[MAX_NAME];
    elementoTablaSimbolos* e = NULL;
    FILE* fsalida = fopen("salida.txt", "w");

    /* Inicializar la tabla de simbolos del main (ambito por defecto) */
    tabla_main = tablaInit("main");

    /* Inicializar la tabla de las clases */
    iniciarTablaSimbolosClases(&ej_tabla_clases, "ej_clases");


    /*Buscar previamente a la declaracion el Id*/
   if( buscarParaDeclararIdTablaSimbolosAmbitos(tabla_main, "v1", &e, "main", nombre_ambito_encontrado) == OK)
    printf("Caso 54: FALLIDO. Ya está declarado el Id\n");
    else{
        printf("Caso 54: OK. No existe el Id\n");
        /* Declarar variable global int v1*/
        insertarTablaSimbolosAmbitos(tabla_main, "main", "v1", ESCALAR, INT, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, NINGUNO, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    }

    /*Buscar previamente a la declaracion el Id*/
   if( buscarParaDeclararIdTablaSimbolosAmbitos(tabla_main, "v1", &e, "main", nombre_ambito_encontrado) == OK)
    printf("Caso 57: OK. Ya está declarado el Id\n");
    else{
        printf("Caso 57: FALLIDO. No existe el Id\n");
    }

    /*Buscar previamente a la declaracion el Id*/
   if( buscarParaDeclararIdTablaSimbolosAmbitos(tabla_main, "f1@1", &e, "main", nombre_ambito_encontrado) == OK)
    printf("Caso 55: FALLIDO. Ya está declarado el Id\n");
    else{
        printf("Caso 55: OK. No existe el Id\n");
        /* Declarar funcion f1*/
        insertarTablaSimbolosAmbitos(tabla_main, "main", "f1@1", ESCALAR, INT, FUNCION, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, NINGUNO, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    }

    AbrirAmbitoPrefijos(tabla_main, "main", "f1@1", ESCALAR, 0, INT, 0, 1);


   /*Buscar previamente a la declaracion el Id*/
   if( buscarParaDeclararIdTablaSimbolosAmbitos(tabla_main, "p1", &e, "main", nombre_ambito_encontrado) == OK)
    printf("Caso 56: FALLIDO. Ya está declarado el Id\n");
    else{
        printf("Caso 56: OK. No existe el Id\n");
    insertarTablaSimbolosAmbitos(tabla_main, "main", "p1", ESCALAR, INT, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, NINGUNO, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
    }

    cerrarAmbitoPrefijos(tabla_main);

  /*Buscar previamente a la declaracion el Id*/
   if( buscarParaDeclararIdTablaSimbolosAmbitos(tabla_main, "f1@1", &e, "main", nombre_ambito_encontrado) == OK)
    printf("Caso 58: OK. Ya está declarado el Id\n");
    else{
        printf("Caso 58: FALLIDO. No existe el Id\n");
    }


  /*Buscar previamente a la declaracion el Id*/
    buscarParaDeclararIdTablaSimbolosAmbitos(tabla_main, "f2@1@1", &e, "main", nombre_ambito_encontrado);

    insertarTablaSimbolosAmbitos(tabla_main, "main", "f2@1@1", ESCALAR, INT, FUNCION, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, NINGUNO, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);


    AbrirAmbitoPrefijos(tabla_main, "main", "f2@1@1", ESCALAR, 0, INT, 0, 1);


   /*Buscar previamente a la declaracion el Id*/
   buscarParaDeclararIdTablaSimbolosAmbitos(tabla_main, "p1", &e, "main", nombre_ambito_encontrado);

    insertarTablaSimbolosAmbitos(tabla_main, "main", "p1", ESCALAR, INT, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, NINGUNO, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

  /*Buscar previamente a la declaracion el Id*/
   if( buscarParaDeclararIdTablaSimbolosAmbitos(tabla_main, "p1", &e, "main", nombre_ambito_encontrado) == OK)
    printf("Caso 59: OK. Ya está declarado el parámetro\n");
    else{
        printf("Caso 59: FALLIDO. No esta declarado el parámetro\n");
    }


    cerrarAmbitoPrefijos(tabla_main);

    cerrarAmbito(tabla_main);

    /* Cerrar las tablas de simbolos */
    cerrarTablaSimbolosClases(ej_tabla_clases);

    tablaSimbolosClasesToDot(ej_tabla_clases, fsalida);

    tablaFree(tabla_main);
    liberarTablaSimbolosClases(ej_tabla_clases);
    fclose(fsalida);
    return 0;
}

int testBuscarIdNoCualificado() {
    TablaAmbito* tabla_main; /* Tabla de simbolos de main*/
    TablaSimbolosClases * ej_tabla_clases = NULL;
    char nombre_ambito_encontrado[MAX_NAME];
    elementoTablaSimbolos* e = NULL;
    FILE* fsalida = fopen("salida.txt", "w");

    /* Inicializar la tabla de simbolos del main (ambito por defecto) */
    tabla_main = tablaInit("main");

    /* Inicializar la tabla de las clases */
    iniciarTablaSimbolosClases(&ej_tabla_clases, "ej_clases");

    /* Declarar variable global int v1*/
    insertarTablaSimbolosAmbitos(tabla_main, "main", "v1", ESCALAR, INT, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, NINGUNO, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    /* Clase AA: tiene 1 atributo de instancia y uno de clase, tambien un metodo */
    abrirClase(ej_tabla_clases,"AA");
    graph_enrouteParentsLastNode(ej_tabla_clases);

    /*declarar variable exposed unique int a1*/
    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "a1", ESCALAR, INT, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_TODOS, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    /*declarar variable hidden int sa1*/
    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "sa1", ESCALAR, INT, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_CLASE, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    /*declarar function exposed int ma1@3*/
    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "ma1@1", ESCALAR, INT, FUNCION, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_TODOS, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
    abrirAmbitoEnClase(ej_tabla_clases, "AA", "ma1@1", ESCALAR, ACCESO_TODOS, INT, 0, 1);
    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "pmA1", ESCALAR, BOOLEAN, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, NINGUNO, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    /*declarar variable int v1ma1*/
    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "v1ma1", ESCALAR, INT, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, NINGUNO, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    /*buscamos id no cualificado v1: esta en main*/
    if(buscarIdNoCualificado(ej_tabla_clases, tabla_main, "v1", "AA", &e, nombre_ambito_encontrado) == OK) {
        printf("CASO 20 -- OK\n-->Elemento \"v1\" en \"buscarIdNoCualificado\" desde \"AA (mA1@1)\" ENCONTRADO en %s\n\n", nombre_ambito_encontrado);
    } else {
        printf("CASO 20 FALLIDO\n-->Elemento \"v1\" en \"buscarIdNoCualificado\" desde \"AA (mA1@1)\" NO ENCONTRADO en main\n\n");
    }

    /*buscamos id no cualificado x: no esta*/
    if(buscarIdNoCualificado(ej_tabla_clases, tabla_main, "x", "AA", &e, nombre_ambito_encontrado) == ERR) {
        printf("CASO 21 -- ERR\n-->FALLO en la busqueda del id \"x\" en \"buscarIdNoCualificado\" desde \"AA (mA1@1)\"\n\n");
    } else {
        printf("CASO 21 FALLIDO\n-->Elemento \"x\" en \"buscarIdNoCualificado\" desde \"AA (mA1@1)\" ENCONTRADO cuando no existe (en ambito %s)\n\n", nombre_ambito_encontrado);
    }

    cerrarAmbitoEnClase(ej_tabla_clases, "AA");

    cerrarClase(ej_tabla_clases,"AA",0,0,0,0);

    /*declarar function int f1@3*/
    insertarTablaSimbolosAmbitos(tabla_main, "main", "f1@3", ESCALAR, INT, FUNCION, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_TODOS, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
    AbrirAmbitoPrefijos(tabla_main, "main", "f1@3", ESCALAR, ACCESO_TODOS, INT, 0, 1);
    insertarTablaSimbolosAmbitos(tabla_main, "main", "pf1", ESCALAR, BOOLEAN, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, NINGUNO, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    /* Declarar variable de funcion int vlf11*/
    insertarTablaSimbolosAmbitos(tabla_main, "main", "vlf11", ESCALAR, INT, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, NINGUNO, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    /*buscamos id no cualificado pf1: esta en la funcion en main*/
    if(buscarIdNoCualificado(ej_tabla_clases, tabla_main, "pf1", "main", &e, nombre_ambito_encontrado) == OK) {
        printf("CASO 24 -- OK\n-->Elemento \"pf1\" en \"buscarIdNoCualificado\" desde \"main (f1@3)\" ENCONTRADO en %s\n\n", nombre_ambito_encontrado);
    } else {
        printf("CASO 24 FALLIDO\n-->Elemento \"pf1\" en \"buscarIdNoCualificado\" desde \"main (f1@3)\" NO ENCONTRADO en f1@3\n\n");
    }

    /*buscamos id no cualificado v1: esta en main*/
    if(buscarIdNoCualificado(ej_tabla_clases, tabla_main, "v1", "main", &e, nombre_ambito_encontrado) == OK) {
        printf("CASO 25 -- OK\n-->Elemento \"v1\" en \"buscarIdNoCualificado\" desde \"main (f1@3)\" ENCONTRADO en main\n\n");
    } else {
        printf("CASO 25 FALLIDO\n-->Elemento \"v1\" en \"buscarIdNoCualificado\" desde \"main (f1@3)\" NO ENCONTRADO en main\n\n");
    }

    /*buscamos id no cualificado a1: no esta*/
    if(buscarIdNoCualificado(ej_tabla_clases, tabla_main, "a1", "main", &e, nombre_ambito_encontrado) == ERR) {
        printf("CASO 26 -- ERR\n-->FALLO en la busqueda del id \"a1\" en \"buscarIdNoCualificado\" desde \"main (f1@3)\"\n\n");
    } else {
        printf("CASO 26 FALLIDO\n-->Elemento \"a1\" en \"buscarIdNoCualificado\" desde \"main (f1@3)\" ENCONTRADO cuando no existe (en ambito %s)\n\n", nombre_ambito_encontrado);
    }

    cerrarAmbitoPrefijos(tabla_main);

    /*buscamos id no cualificado v1: esta en main*/
    if(buscarIdNoCualificado(ej_tabla_clases, tabla_main, "v1", "main", &e, nombre_ambito_encontrado) == OK) {
        printf("CASO 22 -- OK\n-->Elemento \"v1\" en \"buscarIdNoCualificado\" desde \"main\" ENCONTRADO en main\n\n");
    } else {
        printf("CASO 22 FALLIDO\n-->Elemento \"v1\" en \"buscarIdNoCualificado\" desde \"main\" NO ENCONTRADO en main\n\n");
    }

    /*buscamos id no cualificado x: no esta*/
    if(buscarIdNoCualificado(ej_tabla_clases, tabla_main, "x", "main", &e, nombre_ambito_encontrado) == ERR) {
        printf("CASO 23 -- ERR\n-->FALLO en la busqueda del id \"x\" en \"buscarIdNoCualificado\" desde \"main\"\n\n");
    } else {
        printf("CASO 23 FALLIDO\n-->Elemento \"x\" en \"buscarIdNoCualificado\" desde \"main\" ENCONTRADO cuando no existe (en ambito %s)\n\n", nombre_ambito_encontrado);
    }

    /* Cerrar las tablas de simbolos */
    cerrarTablaSimbolosClases(ej_tabla_clases);

    tablaSimbolosClasesToDot(ej_tabla_clases, fsalida);

    tablaFree(tabla_main);
    liberarTablaSimbolosClases(ej_tabla_clases);
    fclose(fsalida);
    return 0;
}

int testBuscarDeclararMiembroClase() {
    TablaAmbito* tabla_main; /* Tabla de simbolos de main*/
    TablaSimbolosClases * ej_tabla_clases = NULL;
    char nombre_ambito_encontrado[MAX_NAME];
    elementoTablaSimbolos* e = NULL;
    FILE* fsalida = fopen("salida.txt", "w");

    /* Inicializar la tabla de simbolos del main (ambito por defecto) */
    tabla_main = tablaInit("main");

    /* Inicializar la tabla de las clases */
    iniciarTablaSimbolosClases(&ej_tabla_clases, "ej_clases");

    /* Clase AA: tiene 3 atributos de clase y 3 metodos de clase */
    abrirClase(ej_tabla_clases,"AA");
    graph_enrouteParentsLastNode(ej_tabla_clases);

    if(buscarParaDeclararMiembroClase(ej_tabla_clases, "AA", "sa1", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 50 Buscar: ERROR (AA_sA1) NO ESTÁ EN AA (SOLO SE BUSCA EN AA) SE PUEDE DECLARAR\n\n");
    } else {
        printf("Caso 50 FALLIDO Buscar: AA_sA1 ENCONTRADO EN %s\n\n", nombre_ambito_encontrado);
    }

    /*declarar variable secret unique int sa1*/
    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "sa1", ESCALAR, INT, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_HERENCIA, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    if(buscarParaDeclararMiembroClase(ej_tabla_clases, "AA", "sa1", &e, nombre_ambito_encontrado) == OK) {
        printf("Caso 49 Buscar: OK (AA_sA1) YA ESTÁ EN %s (SOLO SE BUSCA EN AA) NO SE PUEDE DECLARAR\n\n", nombre_ambito_encontrado);
    } else {
        printf("Caso 49 FALLIDO Buscar: AA_sA1 NO ENCONTRADO EN AA\n\n");
    }

    if(buscarParaDeclararMiembroClase(ej_tabla_clases, "AA", "ha1", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 50 Buscar: ERROR (AA_hA1) NO ESTÁ EN AA (SOLO SE BUSCA EN AA) SE PUEDE DECLARAR\n\n");
    } else {
        printf("Caso 50 FALLIDO Buscar: AA_hA1 ENCONTRADO EN %s\n\n", nombre_ambito_encontrado);
    }

    /*declarar variable hidden unique int ha1*/
    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "ha1", ESCALAR, INT, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_CLASE, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    if(buscarParaDeclararMiembroClase(ej_tabla_clases, "AA", "xa1", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 50 Buscar: ERROR (AA_xA1) NO ESTÁ EN AA (SOLO SE BUSCA EN AA) SE PUEDE DECLARAR\n\n");
    } else {
        printf("Caso 50 FALLIDO Buscar: AA_xA1 ENCONTRADO EN %s\n\n", nombre_ambito_encontrado);
    }

    /*declarar variable exposed unique int xa1*/
    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "xa1", ESCALAR, INT, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_TODOS, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    if(buscarParaDeclararMiembroClase(ej_tabla_clases, "AA", "MA1@1", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 50 Buscar: ERROR (AA_MA1@1) NO ESTÁ EN AA (SOLO SE BUSCA EN AA) SE PUEDE DECLARAR\n\n");
    } else {
        printf("Caso 50 FALLIDO Buscar: AA_MA1@1 ENCONTRADO EN %s\n\n", nombre_ambito_encontrado);
    }

    /*declarar function secret int MA1@1*/
    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "MA1@1", ESCALAR, INT, FUNCION, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_HERENCIA, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    if(buscarParaDeclararMiembroClase(ej_tabla_clases, "AA", "MA1@1", &e, nombre_ambito_encontrado) == OK) {
        printf("Caso 49 Buscar: OK (AA_MA1@1) YA ESTÁ EN %s (SOLO SE BUSCA EN AA) NO SE PUEDE DECLARAR\n\n", nombre_ambito_encontrado);
    } else {
        printf("Caso 49 FALLIDO Buscar: AA_MA1@1 NO ENCONTRADO EN AA\n\n");
    }

    if(buscarParaDeclararMiembroClase(ej_tabla_clases, "AA", "MA1@1@1", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 50 Buscar: ERROR (AA_MA1@1@1) NO ESTÁ EN AA (SOLO SE BUSCA EN AA) SE PUEDE DECLARAR\n\n");
    } else {
        printf("Caso 50 FALLIDO Buscar: AA_MA1@1@1 ENCONTRADO EN %s\n\n", nombre_ambito_encontrado);
    }
    /*declarar function exposed int MA1@1@1*/
    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "MA1@1@1", ESCALAR, INT, FUNCION, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_TODOS, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    cerrarClase(ej_tabla_clases,"AA",0,0,0,0);

    /* Clase BB: tiene 3 atributos de clase y 3 metodos de clase */
    abrirClase(ej_tabla_clases,"BB");

    if(buscarParaDeclararMiembroClase(ej_tabla_clases, "BB", "sa1", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 50 Buscar: ERROR (BB_sA1) NO ESTÁ EN BB (SOLO SE BUSCA EN BB) SE PUEDE DECLARAR\n\n");
    } else {
        printf("Caso 50 FALLIDO Buscar: BB_sA1 ENCONTRADO EN %s\n\n", nombre_ambito_encontrado);
    }

    /*declarar variable secret unique int sa1*/
    insertarTablaSimbolosClases(ej_tabla_clases, "BB", "sa1", ESCALAR, INT, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_HERENCIA, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    if(buscarParaDeclararMiembroClase(ej_tabla_clases, "BB", "ha1", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 50 Buscar: ERROR (BB_hA1) NO ESTÁ EN BB (SOLO SE BUSCA EN BB) SE PUEDE DECLARAR\n\n");
    } else {
        printf("Caso 50 FALLIDO Buscar: BB_hA1 ENCONTRADO EN %s\n\n", nombre_ambito_encontrado);
    }

    /*declarar variable hidden unique int ha1*/
    insertarTablaSimbolosClases(ej_tabla_clases, "BB", "ha1", ESCALAR, INT, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_CLASE, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    if(buscarParaDeclararMiembroClase(ej_tabla_clases, "BB", "xa1", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 50 Buscar: ERROR (BB_xA1) NO ESTÁ EN BB (SOLO SE BUSCA EN BB) SE PUEDE DECLARAR\n\n");
    } else {
        printf("Caso 50 FALLIDO Buscar: BB_xA1 ENCONTRADO EN %s\n\n", nombre_ambito_encontrado);
    }

    /*declarar variable exposed unique int xa1*/
    insertarTablaSimbolosClases(ej_tabla_clases, "BB", "xa1", ESCALAR, INT, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_TODOS, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    if(buscarParaDeclararMiembroClase(ej_tabla_clases, "BB", "MB1@1", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 50 Buscar: ERROR (BB_MB1@1) NO ESTÁ EN BB (SOLO SE BUSCA EN BB) SE PUEDE DECLARAR\n\n");
    } else {
        printf("Caso 50 FALLIDO Buscar: BB_MB1@1 ENCONTRADO EN %s\n\n", nombre_ambito_encontrado);
    }

    /*declarar function secret int MB1@1*/
    insertarTablaSimbolosClases(ej_tabla_clases, "BB", "MB1@1", ESCALAR, INT, FUNCION, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_HERENCIA, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    if(buscarParaDeclararMiembroClase(ej_tabla_clases, "BB", "MA1@1", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 50 Buscar: ERROR (BB_MA1@1) NO ESTÁ EN BB (SOLO SE BUSCA EN BB) SE PUEDE DECLARAR\n\n");
    } else {
        printf("Caso 50 FALLIDO Buscar: BB_MA1@1 ENCONTRADO EN %s\n\n", nombre_ambito_encontrado);
    }

    /*declarar function hidden int MA1@1*/
    insertarTablaSimbolosClases(ej_tabla_clases, "BB", "MA1@1", ESCALAR, INT, FUNCION, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_CLASE, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    if(buscarParaDeclararMiembroClase(ej_tabla_clases, "BB", "MA2@1@1", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 50 Buscar: ERROR (BB_MA2@1@1) NO ESTÁ EN BB (SOLO SE BUSCA EN BB) SE PUEDE DECLARAR\n\n");
    } else {
        printf("Caso 50 FALLIDO Buscar: BB_MA1@1@1 ENCONTRADO EN %s\n\n", nombre_ambito_encontrado);
    }

    /*declarar function exposed int MA2@1@1*/
    insertarTablaSimbolosClases(ej_tabla_clases, "BB", "MA2@1@1", ESCALAR, INT, FUNCION, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_TODOS, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    cerrarClase(ej_tabla_clases,"BB",0,0,0,0);

    cerrarAmbitoPrefijos(tabla_main);

    /* Cerrar las tablas de simbolos */
    cerrarTablaSimbolosClases(ej_tabla_clases);

    tablaSimbolosClasesToDot(ej_tabla_clases, fsalida);

    tablaFree(tabla_main);
    liberarTablaSimbolosClases(ej_tabla_clases);
    fclose(fsalida);
    return 0;
}

int testBuscarDeclararMiembroInstancia() {
    TablaAmbito* tabla_main; /* Tabla de simbolos de main*/
    TablaSimbolosClases * ej_tabla_clases = NULL;
    char nombre_ambito_encontrado[MAX_NAME];
    elementoTablaSimbolos* e = NULL;
    FILE* fsalida = fopen("salida.txt", "w");

    /* Inicializar la tabla de simbolos del main (ambito por defecto) */
    tabla_main = tablaInit("main");

    /* Inicializar la tabla de las clases */
    iniciarTablaSimbolosClases(&ej_tabla_clases, "ej_clases");

    /* Clase AA: tiene 3 atributos de instancia y 3 metodos de instancia */
    abrirClase(ej_tabla_clases,"AA");
    graph_enrouteParentsLastNode(ej_tabla_clases);

    if(buscarParaDeclararMiembroInstancia(ej_tabla_clases, "AA", "sa1", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 53 Buscar: ERROR (AA_sA1) SE PUEDE DECLARAR\n\n");
    } else {
        printf("Caso 53 FALLIDO Buscar: AA_sA1 ENCONTRADO EN %s\n\n", nombre_ambito_encontrado);
    }

    /*declarar variable secret int sa1*/
    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "sa1", ESCALAR, INT, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_HERENCIA, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    if(buscarParaDeclararMiembroInstancia(ej_tabla_clases, "AA", "sa1", &e, nombre_ambito_encontrado) == OK) {
        printf("Caso 51 Buscar: OK (AA_sA1) YA ESTÁ EN %s NO SE PUEDE DECLARAR\n\n", nombre_ambito_encontrado);
    } else {
        printf("Caso 51 FALLIDO Buscar: AA_sA1 NO ENCONTRADO EN AA\n\n");
    }

    if(buscarParaDeclararMiembroInstancia(ej_tabla_clases, "AA", "ha1", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 53 Buscar: ERROR (AA_hA1) SE PUEDE DECLARAR\n\n");
    } else {
        printf("Caso 53 FALLIDO Buscar: AA_hA1 ENCONTRADO EN %s\n\n", nombre_ambito_encontrado);
    }

    /*declarar variable hidden unique int ha1*/
    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "ha1", ESCALAR, INT, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_CLASE, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    if(buscarParaDeclararMiembroInstancia(ej_tabla_clases, "AA", "xa1", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 53 Buscar: ERROR (AA_xA1) NO ESTÁ EN AA (SOLO SE BUSCA EN AA) SE PUEDE DECLARAR\n\n");
    } else {
        printf("Caso 53 FALLIDO Buscar: AA_xA1 ENCONTRADO EN %s\n\n", nombre_ambito_encontrado);
    }

    /*declarar variable exposed unique int xa1*/
    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "xa1", ESCALAR, INT, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_TODOS, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    if(buscarParaDeclararMiembroInstancia(ej_tabla_clases, "AA", "mA1@1", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 53 Buscar: ERROR (AA_mA1@1) SE PUEDE DECLARAR\n\n");
    } else {
        printf("Caso 53 FALLIDO Buscar: AA_mA1@1 ENCONTRADO EN %s\n\n", nombre_ambito_encontrado);
    }

    /*declarar function secret int mA1@1*/
    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "mA1@1", ESCALAR, INT, FUNCION, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_HERENCIA, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    if(buscarParaDeclararMiembroInstancia(ej_tabla_clases, "AA", "mA1@1", &e, nombre_ambito_encontrado) == OK) {
        printf("Caso 51 Buscar: OK (AA_mA1@1) YA ESTÁ EN %s NO SE PUEDE DECLARAR\n\n", nombre_ambito_encontrado);
    } else {
        printf("Caso 51 FALLIDO Buscar: AA_mA1@1 NO ENCONTRADO EN AA\n\n");
    }

    if(buscarParaDeclararMiembroInstancia(ej_tabla_clases, "AA", "mA1@1@3", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 53 Buscar: ERROR (AA_mA1@1@3) SE PUEDE DECLARAR\n\n");
    } else {
        printf("Caso 53 FALLIDO Buscar: AA_mA1@1@3 ENCONTRADO EN %s\n\n", nombre_ambito_encontrado);
    }
    /*declarar function secret int mA1@1@3*/
    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "mA1@1@3", ESCALAR, INT, FUNCION, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_HERENCIA, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    if(buscarParaDeclararMiembroInstancia(ej_tabla_clases, "AA", "mA2", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 53 Buscar: ERROR (AA_mA2) SE PUEDE DECLARAR\n\n");
    } else {
        printf("Caso 53 FALLIDO Buscar: AA_mA2 ENCONTRADO EN %s\n\n", nombre_ambito_encontrado);
    }
    /*declarar function hidden int mA2*/
    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "mA2", ESCALAR, INT, FUNCION, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_CLASE, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    if(buscarParaDeclararMiembroInstancia(ej_tabla_clases, "AA", "mA3@1@3", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 53 Buscar: ERROR (AA_mA3@1@3) SE PUEDE DECLARAR\n\n");
    } else {
        printf("Caso 53 FALLIDO Buscar: AA_mA3@1@3 ENCONTRADO EN %s\n\n", nombre_ambito_encontrado);
    }
    /*declarar function exposed int mA3@1@3*/
    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "mA3@1@3", ESCALAR, INT, FUNCION, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_TODOS, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    cerrarClase(ej_tabla_clases,"AA",0,0,0,0);

    /* Clase BB: tiene 3 atributos de clase y 3 metodos de clase */
    abrirClaseHereda(ej_tabla_clases,"BB", "AA");

    if(buscarParaDeclararMiembroInstancia(ej_tabla_clases, "BB", "sa1", &e, nombre_ambito_encontrado) == OK) {
        printf("Caso 52 Buscar: OK (AA_sA1) DECLARADO EN %s ES ATRIBUTO DE INSTANCIA ACCESIBLE CON ACCESO secret NO SE PUEDE DECLARAR\n\n", nombre_ambito_encontrado);
    } else {
        printf("Caso 52 FALLIDO Buscar: AA_sA1 NO ENCONTRADO EN AA\n\n");
    }

    if(buscarParaDeclararMiembroInstancia(ej_tabla_clases, "BB", "ha1", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 52 Buscar: ERROR (BB_ha1) EXISTE AA_ha1 (EN %s) PERO NO ES ACCESIBLE PORQUE ES HIDDEN SE PUEDE DECLARAR\n\n", nombre_ambito_encontrado);
    } else {
        printf("Caso 52 FALLIDO Buscar: BB_ha1 NO SE PUEDE DECLARAR CUANDO DEBERIA (encontrado en %s)\n\n", nombre_ambito_encontrado);
    }

    /*declarar variable hidden int ha1*/
    insertarTablaSimbolosClases(ej_tabla_clases, "BB", "ha1", ESCALAR, INT, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_CLASE, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    if(buscarParaDeclararMiembroInstancia(ej_tabla_clases, "BB", "hb1", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 52 Buscar: ERROR (BB_hb1) NO EXISTE, SE PUEDE DECLARAR\n\n");
    } else {
        printf("Caso 52 FALLIDO Buscar: hb1 ENCONTRADO EN %s\n\n", nombre_ambito_encontrado);
    }

    /*declarar variable hidden int hb1*/
    insertarTablaSimbolosClases(ej_tabla_clases, "BB", "hb1", ESCALAR, INT, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_CLASE, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    if(buscarParaDeclararMiembroInstancia(ej_tabla_clases, "BB", "xa1", &e, nombre_ambito_encontrado) == OK) {
        printf("Caso 52 Buscar: OK (AA_sA1) DECLARADO EN %s ES ATRIBUTO DE INSTANCIA ACCESIBLE CON ACCESO exposed NO SE PUEDE DECLARAR\n\n", nombre_ambito_encontrado);
    } else {
        printf("Caso 52 FALLIDO Buscar: AA_sA1 NO ENCONTRADO EN AA\n\n");
    }

    if(buscarParaDeclararMiembroInstancia(ej_tabla_clases, "BB", "mA1@1", &e, nombre_ambito_encontrado) == OK) {
        if(e->tipo_miembro == MIEMBRO_NO_UNICO) {
            printf("Caso 52 Buscar: OK (AA_mA1@1) EXISTE EN LA JERARQUIA (%s) ES ACCESIBLE (SECRET) Y ES SOBREESCRIBIBLE: SE ESTÁ SOBREESCRIBIENDO\n\n", nombre_ambito_encontrado);
        } else {
            printf("Caso 52 FALLIDO Buscar: AA_mA1@1 ENCONTRADO EN %s y NO SOBREESCRIBIBLE\n\n", nombre_ambito_encontrado);
        }
    } else {
        printf("Caso 52 FALLIDO Buscar: AA_mA1@1 NO ENCONTRADO EN AA\n\n");
    }
    /*declarar function secret int mA1@1*/
    insertarTablaSimbolosClases(ej_tabla_clases, "BB", "mA1@1", ESCALAR, INT, FUNCION, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_HERENCIA, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    if(buscarParaDeclararMiembroInstancia(ej_tabla_clases, "BB", "mB1@1", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 53 Buscar: ERROR (BB_mB1) NO EXISTE EN NINGÚN LUGAR SE PUEDE DECLARAR\n\n");
    } else {
        printf("Caso 53 FALLIDO Buscar: mB1@1 ENCONTRADO EN %s\n\n", nombre_ambito_encontrado);
    }
    /*declarar function secret int mB1@1*/
    insertarTablaSimbolosClases(ej_tabla_clases, "BB", "mB1@1", ESCALAR, INT, FUNCION, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_HERENCIA, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    if(buscarParaDeclararMiembroInstancia(ej_tabla_clases, "BB", "mA2", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 52 Buscar: ERROR (AA_mA2) mA2 EXISTE EN %s PERO NO ES ACCESIBLE (HIDDEN) SE PUEDE DECLARAR\n\n", nombre_ambito_encontrado);
    } else {
        printf("Caso 52 FALLIDO Buscar: mA2 ENCONTRADO EN %s\n\n", nombre_ambito_encontrado);
    }
    /*declarar function hidden int mA2*/
    insertarTablaSimbolosClases(ej_tabla_clases, "BB", "mA2", ESCALAR, INT, FUNCION, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_CLASE, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    if(buscarParaDeclararMiembroInstancia(ej_tabla_clases, "BB", "mA3@3@1", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 52 Buscar: ERROR (BB_mA3@3@1) NO EXISTE EN NINGÚN LUGAR SE PUEDE DECLARAR\n\n");
    } else {
        printf("Caso 52 FALLIDO Buscar: mA3@3@1 ENCONTRADO EN %s\n\n", nombre_ambito_encontrado);
    }
    /*declarar function exposed int mA3@3@1*/
    insertarTablaSimbolosClases(ej_tabla_clases, "BB", "mA3@3@1", ESCALAR, INT, FUNCION, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_TODOS, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    cerrarClase(ej_tabla_clases,"BB",0,0,0,0);

    cerrarAmbitoPrefijos(tabla_main);

    /* Cerrar las tablas de simbolos */
    cerrarTablaSimbolosClases(ej_tabla_clases);

    tablaSimbolosClasesToDot(ej_tabla_clases, fsalida);

    tablaFree(tabla_main);
    liberarTablaSimbolosClases(ej_tabla_clases);
    fclose(fsalida);
    return 0;
}

int testBuscarUso() {
    TablaAmbito* tabla_main; /* Tabla de simbolos de main*/
    TablaSimbolosClases * ej_tabla_clases = NULL;
    char nombre_ambito_encontrado[MAX_NAME];
    elementoTablaSimbolos* e = NULL;
    int aaindex, bbindex, ccindex, ddindex, eeindex, ffindex;
    FILE* fsalida = fopen("salida.txt", "w");

    /* Inicializar la tabla de simbolos del main (ambito por defecto) */
    tabla_main = tablaInit("main");

    /* Inicializar la tabla de las clases */
    iniciarTablaSimbolosClases(&ej_tabla_clases, "ej_clases");

    /* Clase AA: tiene 3 atributos de instancia y 3 metodos de instancia */
    aaindex = abrirClase(ej_tabla_clases,"AA");
    graph_enrouteParentsLastNode(ej_tabla_clases);

    /*declarar variable exposed {AA} inspub*/
    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "inspub", OBJETO, -aaindex, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_TODOS, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    /*declarar variable secret {AA} insprot*/
    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "insprot", OBJETO, -aaindex, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_HERENCIA, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    /*declarar variable hidden {AA} inspriv*/
    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "inspriv", OBJETO, -aaindex, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_CLASE, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    /*declarar variable exposed unique {AA} clasepub*/
    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "clasepub", OBJETO, -aaindex, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_TODOS, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    /*declarar variable secret unique {AA} claseprot*/
    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "claseprot", OBJETO, -aaindex, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_HERENCIA, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    /*declarar variable hidden unique {AA} clasepriv*/
    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "clasepriv", OBJETO, -aaindex, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_CLASE, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    /*declarar variable exposed {AA} miaa*/
    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "miaa", OBJETO, -aaindex, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_TODOS, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    /*declarar function secret int prueba*/
    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "prueba", ESCALAR, INT, FUNCION, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_HERENCIA, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
    abrirAmbitoEnClase(ej_tabla_clases, "AA", "prueba", ESCALAR, ACCESO_HERENCIA, INT, 0, 1);

    if(buscarIdCualificadoInstancia(ej_tabla_clases, tabla_main, "miaa", "inspriv", "AA", &e, nombre_ambito_encontrado) == OK) {
        printf("Caso 48: SE ACCEDE DESDE UN MÉTODO A UN ATRIBUTO (inspriv) QUE EXISTE EN LA JERARQUÍA (AA) Y ESTÁ ACCESIBLE (inspriv es hidden pero estamos en AA) A TRAVÉS DE UNA INSTANCIA QUE SÍ ESTÁ ACCESIBLE (miaa)\n\n");
    } else {
        printf("Caso 48 FALLIDO Buscar: inspriv NO ACCESIBLE CUANDO DEBERIA\n\n");
    }

    if(buscarIdCualificadoInstancia(ej_tabla_clases, tabla_main, "miaa", "insprot", "AA", &e, nombre_ambito_encontrado) == OK) {
        printf("Caso 47.3: SE ACCEDE DESDE UN MÉTODO A UN ATRIBUTO (insprot) QUE EXISTE EN LA JERARQUÍA Y ESTÁ ACCESIBLE (insprot es secret) CUALIFICANDO POR UNA INSTANCIA ACCESIBLE (miaa)\n\n");
    } else {
        printf("Caso 47.3 FALLIDO Buscar: insprot NO ACCESIBLE CUANDO DEBERIA\n\n");
    }

    if(buscarIdCualificadoInstancia(ej_tabla_clases, tabla_main, "miaa", "inspub", "AA", &e, nombre_ambito_encontrado) == OK) {
        printf("Caso 47.3: SE ACCEDE DESDE UN MÉTODO A UN ATRIBUTO (inspub) QUE EXISTE EN LA JERARQUÍA Y ESTÁ ACCESIBLE (inspub es exposed) CUALIFICANDO POR UNA INSTANCIA ACCESIBLE (miaa)\n\n");
    } else {
        printf("Caso 47.3 FALLIDO Buscar: inspub NO ACCESIBLE CUANDO DEBERIA\n\n");
    }

    if(buscarIdCualificadoClase(ej_tabla_clases, "AA", "claseprot", "AA", &e, nombre_ambito_encontrado) == OK) {
        printf("Caso 35: SE BUSCA DESDE UN MÉTODO ALGO DE UNA CLASE (AA) QUE ESTÁ EN LA JERARQUÍA Y ES ACCESIBLE (claseprot es secret y estamos en la clase)\n\n");
    } else {
        printf("Caso 35 FALLIDO Buscar: claseprot NO ACCESIBLE CUANDO DEBERIA\n\n");
    }

    if(buscarIdCualificadoClase(ej_tabla_clases, "AA", "clasepub", "AA", &e, nombre_ambito_encontrado) == OK) {
        printf("Caso 35: SE BUSCA DESDE UN MÉTODO ALGO DE UNA CLASE (AA) QUE ESTÁ EN LA JERARQUÍA Y ES ACCESIBLE (clasepub es exposed)\n\n");
    } else {
        printf("Caso 35 FALLIDO Buscar: clasepub NO ACCESIBLE CUANDO DEBERIA\n\n");
    }

    cerrarAmbitoEnClase(ej_tabla_clases, "AA");

    cerrarClase(ej_tabla_clases,"AA",0,0,0,0);

    /* Clase BB*/
    bbindex = abrirClaseHereda(ej_tabla_clases,"BB", "AA");

        /*declarar variable exposed {BB} mibb*/
    insertarTablaSimbolosClases(ej_tabla_clases, "BB", "mibb", OBJETO, -bbindex, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_TODOS, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    cerrarClase(ej_tabla_clases,"BB",0,0,0,0);

    /* Declarar variable global {BB} MainMiBB*/
    insertarTablaSimbolosAmbitos(tabla_main, "main", "MainMiBB", OBJETO, -bbindex, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, NINGUNO, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    /* Declarar variable global {BB} MainMiBB2*/
    insertarTablaSimbolosAmbitos(tabla_main, "main", "MainMiBB2", OBJETO, -bbindex, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, NINGUNO, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
    
    if(buscarIdCualificadoInstancia(ej_tabla_clases, tabla_main, "MainMiBB", "insnoexiste", "main", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 40.1: SE BUSCA ALGO QUE NO EXISTE CUALIFICADO POR UNA INSTANCIA QUE EXISTE Y ES GLOBAL\n\n");
    } else {
        printf("Caso 40.1 FALLIDO Buscar: insnoexiste ENCONTRADO CUANDO NO EXISTE\n\n");
    }

    /* Clase CC*/
    ccindex = abrirClase(ej_tabla_clases,"CC");

        /*declarar variable exposed {CC} micc*/
    insertarTablaSimbolosClases(ej_tabla_clases, "CC", "micc", OBJETO, -ccindex, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_TODOS, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    cerrarClase(ej_tabla_clases,"CC",0,0,0,0);

    /* Clase DD*/
    ddindex = abrirClaseHereda(ej_tabla_clases,"DD", "AA", "CC");

        /*declarar variable exposed {DD} midd*/
    insertarTablaSimbolosClases(ej_tabla_clases, "DD", "midd", OBJETO, -ddindex, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_TODOS, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    cerrarClase(ej_tabla_clases,"DD",0,0,0,0);

    /* Clase EE*/
    eeindex = abrirClaseHereda(ej_tabla_clases,"EE", "BB", "DD");

    /*declarar variable exposed {EE} miee*/
    insertarTablaSimbolosClases(ej_tabla_clases, "EE", "miee", OBJETO, -eeindex, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_TODOS, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

/*declarar function exposed none mE*/
    insertarTablaSimbolosClases(ej_tabla_clases, "EE", "mE", ESCALAR, NINGUNO, FUNCION, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_TODOS, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    abrirAmbitoEnClase(ej_tabla_clases, "EE", "mE", ESCALAR, ACCESO_TODOS, NINGUNO, 0, 1);

    /*declarar variable {EE} varLoc*/
    insertarTablaSimbolosClases(ej_tabla_clases, "EE", "varLoc", OBJETO, -eeindex, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_TODOS, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    if(buscarIdCualificadoClase(ej_tabla_clases, "EE", "claseNoExiste", "EE", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 37: DESDE DENTRO DE UN MÉTODO, SE ACCEDE A ALGO CUALIFICADO POR UNA CLASE (EE) QUE EXISTE PERO LO BUSCADO NO EXISTE (claseNoExiste)\n\n");
    } else {
        printf("Caso 37 FALLIDO Buscar: claseNoExiste ENCONTRADO CUANDO NO DEBERIA\n\n");
    }

    if(buscarIdCualificadoClase(ej_tabla_clases, "noExiste", "claseNoExiste", "EE", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 38: DESDE DENTRO DE UN MÉTODO, SE ACCEDE A ALGO CUALIFICADO POR UNA CLASE (noExiste) QUE NO EXISTE\n\n");
    } else {
        printf("Caso 38 FALLIDO Buscar: noExiste ENCONTRADO CUANDO NO DEBERIA\n\n");
    }

    if(buscarIdCualificadoInstancia(ej_tabla_clases, tabla_main, "MainMiBB2", "inspub", "EE", &e, nombre_ambito_encontrado) == OK) {
        printf("Caso 46.3: DESDE DENTRO DE UN MÉTODO, SE BUSCA ALGO CUALIFICADO POR UNA INSTANCIA DE UNA CLASE (B) QUE ES UNA VARIABLE GLOBAL Y LO BUSCADO ES UN ATRIBUTO (inspub) QUE NO ESTÁ EN LA CLASE PERO SÍ EN LA JERARQUÍA (en A) Y ES ACCESIBLE (exposed)\n\n");
    } else {
        printf("Caso 46.3 FALLIDO Buscar: MainMiBB2.inspub NO ACCESIBLE CUANDO DEBERIA\n\n");
    }

    if(buscarIdCualificadoInstancia(ej_tabla_clases, tabla_main, "miee", "insNoExiste", "EE", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 47.1: DESDE UN MÉTODO SE ACCEDE A ALGO CUALIFICADO POR UNA INSTANCIA (miee) QUE ES UN ATRIBUTO ACCESIBLE EN ESTE CASO DE LA MISMA CLASE PERO EL ATRIBUTO BUSCADO (insNoExiste) NO EXISTE\n\n");
    } else {
        printf("Caso 47.1 FALLIDO Buscar: insNoExiste ENCONTRADO CUANDO NO DEBERIA\n\n");
    }

    if(buscarIdCualificadoInstancia(ej_tabla_clases, tabla_main, "varLoc", "inspub", "EE", &e, nombre_ambito_encontrado) == OK) {
        printf("Caso 45.3: DESDE UN METODO SE ACCEDE A ALGO CUALIFICADO POR UNA INSTANCIA (varLoc) QUE ES UNA VARIABLE LOCAL DEL MÉTODO DE UN CLASE QUE EXISTE (E) Y LA COSA BUSCADA (inspub) ES UNA ATRIBUTO QUE AUNQUE NO ESTÁ EN LA CLASE SÍ ESTÁ EN  LA JERARQUÍA (A) Y ES ACCESIBLE (exposed)\n\n");
    } else {
        printf("Caso 45.3 FALLIDO Buscar: varLoc.inspub NO ACCESIBLE CUANDO DEBERIA\n\n");
    }

    cerrarAmbitoEnClase(ej_tabla_clases, "EE");

    cerrarClase(ej_tabla_clases,"EE",0,0,0,0);

    /* Clase FF*/
    ffindex = abrirClaseHereda(ej_tabla_clases,"FF", "CC", "EE");

        /*declarar variable exposed {FF} miff*/
    insertarTablaSimbolosClases(ej_tabla_clases, "FF", "miff", OBJETO, -ffindex, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_TODOS, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    cerrarClase(ej_tabla_clases,"FF",0,0,0,0);

    insertarTablaSimbolosAmbitos(tabla_main, "main", "prueba", ESCALAR, INT, FUNCION, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_TODOS, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
    AbrirAmbitoPrefijos(tabla_main, "main", "prueba", ESCALAR, ACCESO_TODOS, INT, 0, 1);

    if(buscarIdCualificadoClase(ej_tabla_clases, "AA", "clasepriv", "main", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 32: ACCESOS DESDE UNA FUNCIÓN GLOBAL (prueba) A ALGO CUALIFICADO POR UNA CLASE (A) QUE EXISTE Y LO BUSCADO (clasepriv) ES ATRIBUTO DE ESA CLASE SON DE CLASE Y NO ES ACCESIBLE \n\n");
    } else {
        printf("Caso 32 FALLIDO Buscar: clasepriv ACCESIBLE CUANDO NO DEBERIA\n\n");
    }

    if(buscarIdCualificadoClase(ej_tabla_clases, "AA", "clasepub", "main", &e, nombre_ambito_encontrado) == OK) {
        printf("Caso 31: ACCESOS DESDE UNA FUNCIÓN GLOBAL (prueba) A ALGO CUALIFICADO POR UNA CLASE (A) QUE EXISTE Y LO BUSCADO (clasepub) ES ATRIBUTO DE ESA CLASE SON DE CLASE Y ES ACCESIBLE \n\n");
    } else {
        printf("Caso 31 FALLIDO Buscar: clasepriv NO ACCESIBLE CUANDO DEBERIA\n\n");
    }

    if(buscarIdCualificadoClase(ej_tabla_clases, "AA", "claseNoExiste", "main", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 33: ACCESOS DESDE UNA FUNCIÓN GLOBAL (prueba) A ALGO CUALIFICADO POR UNA CLASE (A) QUE EXISTE Y LO BUSCADO (claseNoExiste) NO \n\n");
    } else {
        printf("Caso 33 FALLIDO Buscar: claseNoExiste ENCONTRADO CUANDO NO DEBERIA\n\n");
    }

    if(buscarIdCualificadoClase(ej_tabla_clases, "noExiste", "claseNoExiste", "main", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 34: ACCESO DESDE FUNCIÓN GLOBAL DE ALGO CUALIFICADO POR UNA CLASE QUE NO EXISTE \n\n");
    } else {
        printf("Caso 34 FALLIDO Buscar: noExiste ENCONTRADO CUANDO NO DEBERIA\n\n");
    }

    if(buscarIdCualificadoInstancia(ej_tabla_clases, tabla_main, "MainMiBB2", "insNoExiste", "main", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 43.1: ACCESO DESDE UNA FUNCIÓN GLOBAL (prueba) DE UN ID (insNoExiste) CUALIFICADO POR UNA INSTANCIA (MainMiBB2) QUE EXISTE COMO VARIABLE GLOBAL DE UNA CLASE (B) QUE NO TIENE ESE ATRIBUTO DE NINGUNA MANERA\n\n");
    } else {
        printf("Caso 43.1 FALLIDO Buscar: MainMiBB2.insNoExiste ENCONTRADO CUANDO NO EXISTE\n\n");
    }

    cerrarAmbitoPrefijos(tabla_main);

    insertarTablaSimbolosAmbitos(tabla_main, "main", "f2", ESCALAR, NINGUNO, FUNCION, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_TODOS, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
    AbrirAmbitoPrefijos(tabla_main, "main", "f2", ESCALAR, ACCESO_TODOS, NINGUNO, 0, 1);

    if(buscarIdCualificadoInstancia(ej_tabla_clases, tabla_main, "MainMiBB2", "inspub", "main", &e, nombre_ambito_encontrado) == OK) {
        printf("Caso 42.3: ACCESO DESDE UNA FUNCIÓN GLOBAL (f2) DE UN ID (inspub) CUALIFICADO POR UNA INSTANCIA (MainMiBB2) QUE EXISTE COMO VARIABLE GLOBAL DE UNA CLASE (B) QUE NO TIENE ESOS ATRIBUTOS PERO QUE SÍ LOS TIENE SU JERARQUIA (A) Y ADEMÁS DESDE ELLA (B) ES ACCESIBLE (exposed)\n\n");
    } else {
        printf("Caso 42.3 FALLIDO Buscar: MainMiBB2.inspub NO ACCESIBLE CUANDO DEBERIA\n\n");
    }

    if(buscarIdCualificadoInstancia(ej_tabla_clases, tabla_main, "MainMiBB2", "inspriv", "main", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 43.3: ACCESO DESDE UNA FUNCIÓN GLOBAL (f2) DE UN ID (inspub y inspriv) CUALIFICADO POR UNA INSTANCIA (MainMiBB2) QUE EXISTE COMO VARIABLE GLOBAL DE UNA CLASE (B) QUE NO TIENE ESOS ATRIBUTOS PERO QUE SÍ LOS TIENE SU JERARQUIA (A) Y ADEMÁS DESDE ELLA (B) NO ES ACCESIBLE (hidden)\n\n");
    } else {
        printf("Caso 43.3 FALLIDO Buscar: MainMiBB2.inspriv ACCESIBLE CUANDO NO DEBERIA (seguro?)\n\n");
    }

    cerrarAmbitoPrefijos(tabla_main);

    if(buscarIdCualificadoClase(ej_tabla_clases, "JJ", "noExiste", "main", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 30: DESDE EL CÓDIGO DE MAIN SE BUSCA ALGO CUALIFICADO POR UNA CLASE QUE NO EXISTE (JJ) \n\n");
    } else {
        printf("Caso 30 FALLIDO Buscar: JJ ENCONTRADO CUANDO NO DEBERIA\n\n");
    }

    if(buscarIdCualificadoInstancia(ej_tabla_clases, tabla_main, "MainMiBB2", "inspub", "main", &e, nombre_ambito_encontrado) == OK) {
        printf("Caso 40.3: ESDE EL CÓDIGO DE MAIN SE BUSCA ALGO CUALIFICADO POR UNA INSTANCIA (MainMiBB2) QUE EXISTE COMO VARIABLE GLOBAL DE UNA CLASE (B) QUE NO TIENE ESOS ATRIBUTOS PERO QUE SÍ LOS TIENE SU JERARQUIA (A) Y ADEMÁS DESDE ELLA (B) ES ACCESIBLE (exposed)\n\n");
    } else {
        printf("Caso 40.3 FALLIDO Buscar: MainMiBB2.inspub NO ACCESIBLE CUANDO DEBERIA\n\n");
    }

    if(buscarIdCualificadoClase(ej_tabla_clases, "AA", "clasepub", "main", &e, nombre_ambito_encontrado) == OK) {
        printf("Caso 27.1: DESDE EL CÓDIGO DE MAIN SE BUSCA ALGO CUALIFICADO POR UNA CLASE QUE EXISTE (AA) Y EL ID BUSCADO (clasepub) ES UN ATRIBUTO QUE EXISTE EN LA CLASE, ACCESIBLE Y ATRIBUTO DE CLASE\n\n");
    } else {
        printf("Caso 27.1 FALLIDO Buscar: AA.clasepub NO ACCESIBLE CUANDO DEBERIA\n\n");
    }

    if(buscarIdCualificadoClase(ej_tabla_clases, "AA", "clasepriv", "main", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 28: DESDE EL CÓDIGO DE MAIN SE BUSCA ALGO CUALIFICADO POR UNA CLASE QUE EXISTE (AA) Y EL ID BUSCADO (clasepriv) ES UN ATRIBUTO QUE EXISTE EN LA CLASE, NO ACCESIBLE (hidden)\n\n");
    } else {
        printf("Caso 28 FALLIDO Buscar: AA.clasepriv ACCESIBLE CUANDO NO DEBERIA\n\n");
    }

    if(buscarIdCualificadoClase(ej_tabla_clases, "AA", "claseNoExiste", "noExiste", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 29: DESDE EL CÓDIGO DE MAIN SE BUSCA ALGO CUALIFICADO POR UNA CLASE QUE EXISTE (AA) Y EL ID BUSCADO (noExiste) NO EXISTE\n\n");
    } else {
        printf("Caso 29 FALLIDO Buscar: claseNoExiste ENCONTRADO CUANDO NO DEBERIA\n\n");
    }

    /* Cerrar las tablas de simbolos */
    cerrarTablaSimbolosClases(ej_tabla_clases);

    tablaSimbolosClasesToDot(ej_tabla_clases, fsalida);

    tablaFree(tabla_main);
    liberarTablaSimbolosClases(ej_tabla_clases);
    fclose(fsalida);
    return 0;
}

/* Driver program to test above functions */
int main(int argc, char* argv[]) {
    /* create the graph */
    if(argc >= 2) {
        if(strcmp(argv[1], "graph") == 0) {
            return test();
        } else if (strcmp(argv[1], "dot") == 0) {
            return dotTest();
        } else if (strcmp(argv[1], "tabla") == 0) {
            if(argc < 3) {
                printf("%s usage: %s %s [filename]", argv[1], argv[0], argv[1]);
            }
            else return testTabla(argv[2]);
        } else if (strcmp(argv[1], "binc") == 0) {
            return testBuscarIdNoCualificado();
        } else if (strcmp(argv[1], "bdmc") == 0) {
            return testBuscarDeclararMiembroClase();
        } else if (strcmp(argv[1], "bdmi") == 0) {
            return testBuscarDeclararMiembroInstancia();
        } else if (strcmp(argv[1], "buso") == 0) {
            return testBuscarUso();
        } else if (strcmp(argv[1], "nuevo") == 0) {
            return TestNuevo();
        } else if(strcmp(argv[1], "2") == 0) {
          return Test2();
        }

    }
    printf("help: %s graph|dot|tabla [filename]|binc|bdmc|bdmi|buso|nuevo|2\ngraph: test graph\ndot: test function to create .dot file\ntabla: test tablaSimbolosClases\nbinc: test buscarIdNoCualificado\nbdmc: test buscarDeclararMiembroClase\nbdmi: test buscarDeclararMiembroInstancia\nbuso: test buscarUso\nnuevo: test buscarParaDeclararIdTablaSimbolosAmbitos\n2: test buscarParaDeclararIdLocalEnMetodo\n", argv[0]);
    return 0;

}
