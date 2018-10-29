#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "graph.h"

/* Driver program to test above functions */
int main() {
    /* create the graph */
    Class class[5];
    int i;
    Graph* graph = createGraph();
    strcpy(class[0].name, "Persona");
    strcpy(class[1].name, "Infante");
    strcpy(class[2].name, "Adulto");
    strcpy(class[3].name, "Anciano");
    strcpy(class[4].name, "Depotista");
    for(i = 0; i < 5; i++)
        addClass(graph, &class[i]);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    /* print the adjacency list representation of the above graph */
    tablaSimbolosClasesToDot(graph);

    freeGraph(graph);

    return 0;
}
