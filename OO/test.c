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

    TablaSimbolosClases * ej_tabla_clases=NULL;

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

int testBuscarIdNoCualificado(char* fname) {
    TablaAmbito* tabla_main; /* Tabla de simbolos de main*/

    TablaSimbolosClases * ej_tabla_clases=NULL;

    /* Inicializar la tabla de simbolos del main (ambito por defecto) */
    tabla_main = tablaInit("main");

    /* Inicializar la tabla de las clases */
    iniciarTablaSimbolosClases(&ej_tabla_clases, "ej_clases");

    /* Declarar variable global int v1*/
    insertarTablaSimbolosAmbitos(tabla_main, "main", "v1", ESCALAR, INT, VARIABLE, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, NINGUNO, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    /* Clase AA: tiene 1 atributo de instancia y uno de clase, tambien un metodo */
    abrirClase(ej_tabla_clases,"AA");
    graph_enrouteParentsLastNode(ej_tabla_clases);

    /*TODO: escribir correctamente esta funcion*/
    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "a1", ESCALAR, INT, VARIABLE, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, ACCESO_TODOS, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    /*TODO: terminar de redactar el test (programa omicron al final de la sesion 31/10 */

    cerrarClase(ej_tabla_clases,"AA",0,0,0,0);

    abrirClaseHereda(ej_tabla_clases, "BB", "AA", NULL);
    graph_enrouteParentsLastNode(ej_tabla_clases);

    cerrarClase(ej_tabla_clases,"BB",0,0,0,0);

    /* Cerrar las tablas de simbolos */
    cerrarTablaSimbolosClases(ej_tabla_clases);

    /*liberarTablaSimbolosAmbitos(&tabla_main);*/
    tablaFree(tabla_main);
    liberarTablaSimbolosClases(ej_tabla_clases);
    return 0;
}

/* Driver program to test above functions */
int main(int argc, char* argv[]) {
    /* create the graph */
    if(argc < 2) {
        printf("help: %s graph|dot|tabla [filename]\ngraph: test graph\ndot: test function to create .dot file\ntabla: test tablaSimbolosClases\n", argv[0]);
    } else if(strcmp(argv[1], "graph") == 0) {
        return test();
    } else if (strcmp(argv[1], "dot") == 0) {
        return dotTest();
    } else if (strcmp(argv[1], "tabla") == 0) {
        if(argc < 3) {
            printf("%s usage: %s %s [filename]", argv[1], argv[0], argv[1]);
        }
        else return testTabla(argv[2]);
    } else {
        printf("Unknown command.\nhelp: %s graph|dot\ngraph: test graph\ndot: test function to create .dot file\n", argv[0]);
    }
    return 0;

}
