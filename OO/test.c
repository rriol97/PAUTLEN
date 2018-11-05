#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "tabla.h"

int dotTest() {
    NodoGrafo class[5];
    int i;
    Graph* graph = createGraph();
    strcpy(class[0].name, "Persona");
    strcpy(class[1].name, "Infante");
    strcpy(class[2].name, "Adulto");
    strcpy(class[3].name, "Anciano");
    strcpy(class[4].name, "Depotista");
    for(i = 0; i < 5; i++) {
        tablaInit(&class[i].tabla, class[i].name);
        graphAddClass(graph, &class[i]);
    }
    insert_symbol(&(class[0].tabla.th_ppal), "esmujer", NULL);
    insert_symbol(&(class[0].tabla.th_ppal), "edad", NULL);
    insert_symbol(&(class[1].tabla.th_ppal), "percentil", NULL);
    insert_symbol(&(class[2].tabla.th_ppal), "percentil", NULL);
    insert_symbol(&(class[3].tabla.th_ppal), "sumar()", NULL);
    graphAddEdge(graph, 0, 1);
    graphAddEdge(graph, 0, 2);
    graphAddEdge(graph, 0, 3);
    graphAddEdge(graph, 1, 4);
    graphAddEdge(graph, 2, 4);
    graphAddEdge(graph, 3, 4);

    /* print the adjacency list representation of the above graph */
    tablaSimbolosClasesToDot(graph);
    for(i = 0; i < 5; i++) {
        clear_symbols(&(class[i].tabla.th_ppal));
    }

    freeGraph(graph);

    return 0;
}

int testTabla() {
    tablaSimbolosClases * ej_tabla_clases=NULL;
    /* Inicializar la tabla de las clases */
    iniciarTablaSimbolosClases(&ej_tabla_clases, "ej_clases");
    /* Cerrar las tablas de simbolos */
    abrirClase(ej_tabla_clases,"AA");
    cerrarClase(ej_tabla_clases,"AA",0,0,0,0);       
    cerrarTablaSimbolosClases(ej_tabla_clases);
    liberarTablaSimbolosClases(ej_tabla_clases);
    /*fclose(fsalida);*/

    return 0;
}

/* Driver program to test above functions */
int main(int argc, char* argv[]) {
    /* create the graph */
    if(argc < 2) {
        printf("help: %s graph|dot|tabla\ngraph: test graph\ndot: test function to create .dot file\ntabla: test tablaSimbolosClases\n", argv[0]);
    } else if(strcmp(argv[1], "graph") == 0) {
        return test();
    } else if (strcmp(argv[1], "dot") == 0) {
        return dotTest();
    } else if (strcmp(argv[1], "tabla") == 0) {
        return testTabla();
    } else {
        printf("Unknown command.\nhelp: %s graph|dot\ngraph: test graph\ndot: test function to create .dot file\n", argv[0]);
    }
    return 0;

}
