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
    tablaSimbolosClasesAbrirAmbitoEnClase(ej_tabla_clases, "AA", "ma1@1", ESCALAR, ACCESO_TODOS, INT, 0, 1); 
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
    insertarTablaSimbolosAmbitos(tabla_main, "f1@3", "pf1", ESCALAR, BOOLEAN, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, NINGUNO, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

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
    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "ha1", ESCALAR, INT, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_CLASE, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    if(buscarParaDeclararMiembroInstancia(ej_tabla_clases, "AA", "xa1", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 53 Buscar: ERROR (AA_xA1) NO ESTÁ EN AA (SOLO SE BUSCA EN AA) SE PUEDE DECLARAR\n\n");
    } else {
        printf("Caso 53 FALLIDO Buscar: AA_xA1 ENCONTRADO EN %s\n\n", nombre_ambito_encontrado);
    }

    /*declarar variable exposed unique int xa1*/
    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "xa1", ESCALAR, INT, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_TODOS, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    if(buscarParaDeclararMiembroInstancia(ej_tabla_clases, "AA", "mA1@1", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 53 Buscar: ERROR (AA_mA1@1) SE PUEDE DECLARAR\n\n");
    } else {
        printf("Caso 53 FALLIDO Buscar: AA_mA1@1 ENCONTRADO EN %s\n\n", nombre_ambito_encontrado);
    }

    /*declarar function secret int mA1@1*/
    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "mA1@1", ESCALAR, INT, FUNCION, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_HERENCIA, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

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
    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "mA1@1@3", ESCALAR, INT, FUNCION, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_HERENCIA, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

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
    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "mA3@1@3", ESCALAR, INT, FUNCION, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_TODOS, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    cerrarClase(ej_tabla_clases,"AA",0,0,0,0);

    /*TODO: implementar esta parte del test*/
    /* Clase BB: tiene 3 atributos de clase y 3 metodos de clase */
    /*abrirClase(ej_tabla_clases,"BB");

    if(buscarParaDeclararMiembroInstancia(ej_tabla_clases, "BB", "sa1", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 50 Buscar: ERROR (BB_sA1) NO ESTÁ EN BB (SOLO SE BUSCA EN BB) SE PUEDE DECLARAR\n\n");
    } else {
        printf("Caso 50 FALLIDO Buscar: BB_sA1 ENCONTRADO EN %s\n\n", nombre_ambito_encontrado);
    }*/

    /*declarar variable secret unique int sa1*/
    /*insertarTablaSimbolosClases(ej_tabla_clases, "BB", "sa1", ESCALAR, INT, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_HERENCIA, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    if(buscarParaDeclararMiembroInstancia(ej_tabla_clases, "BB", "ha1", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 50 Buscar: ERROR (BB_hA1) NO ESTÁ EN BB (SOLO SE BUSCA EN BB) SE PUEDE DECLARAR\n\n");
    } else {
        printf("Caso 50 FALLIDO Buscar: BB_hA1 ENCONTRADO EN %s\n\n", nombre_ambito_encontrado);
    }*/

    /*declarar variable hidden unique int ha1*/
    /*insertarTablaSimbolosClases(ej_tabla_clases, "BB", "ha1", ESCALAR, INT, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_CLASE, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    if(buscarParaDeclararMiembroInstancia(ej_tabla_clases, "BB", "xa1", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 50 Buscar: ERROR (BB_xA1) NO ESTÁ EN BB (SOLO SE BUSCA EN BB) SE PUEDE DECLARAR\n\n");
    } else {
        printf("Caso 50 FALLIDO Buscar: BB_xA1 ENCONTRADO EN %s\n\n", nombre_ambito_encontrado);
    }*/

    /*declarar variable exposed unique int xa1*/
    /*insertarTablaSimbolosClases(ej_tabla_clases, "BB", "xa1", ESCALAR, INT, VARIABLE, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_TODOS, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    if(buscarParaDeclararMiembroInstancia(ej_tabla_clases, "BB", "MB1@1", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 50 Buscar: ERROR (BB_MB1@1) NO ESTÁ EN BB (SOLO SE BUSCA EN BB) SE PUEDE DECLARAR\n\n");
    } else {
        printf("Caso 50 FALLIDO Buscar: BB_MB1@1 ENCONTRADO EN %s\n\n", nombre_ambito_encontrado);
    }*/

    /*declarar function secret int MB1@1*/
    /*insertarTablaSimbolosClases(ej_tabla_clases, "BB", "MB1@1", ESCALAR, INT, FUNCION, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_HERENCIA, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    if(buscarParaDeclararMiembroInstancia(ej_tabla_clases, "BB", "MA1@1", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 50 Buscar: ERROR (BB_MA1@1) NO ESTÁ EN BB (SOLO SE BUSCA EN BB) SE PUEDE DECLARAR\n\n");
    } else {
        printf("Caso 50 FALLIDO Buscar: BB_MA1@1 ENCONTRADO EN %s\n\n", nombre_ambito_encontrado);
    }*/

    /*declarar function hidden int MA1@1*/
    /*insertarTablaSimbolosClases(ej_tabla_clases, "BB", "MA1@1", ESCALAR, INT, FUNCION, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_CLASE, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    if(buscarParaDeclararMiembroInstancia(ej_tabla_clases, "BB", "MA2@1@1", &e, nombre_ambito_encontrado) == ERR) {
        printf("Caso 50 Buscar: ERROR (BB_MA2@1@1) NO ESTÁ EN BB (SOLO SE BUSCA EN BB) SE PUEDE DECLARAR\n\n");
    } else {
        printf("Caso 50 FALLIDO Buscar: BB_MA1@1@1 ENCONTRADO EN %s\n\n", nombre_ambito_encontrado);
    }*/

    /*declarar function exposed int MA2@1@1*/
    /*insertarTablaSimbolosClases(ej_tabla_clases, "BB", "MA2@1@1", ESCALAR, INT, FUNCION, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_TODOS, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    cerrarClase(ej_tabla_clases,"BB",0,0,0,0);*/

    cerrarAmbitoPrefijos(tabla_main);

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
        }
    }
    printf("help: %s graph|dot|tabla [filename]|binc|bdmc|bdmi\ngraph: test graph\ndot: test function to create .dot file\ntabla: test tablaSimbolosClases\nbinc: test buscarIdNoCualificado\nbdmc: test buscarDeclararMiembroClase\nbdmi: test buscarDeclararMiembroInstancia\n", argv[0]);
    return 0;

}
