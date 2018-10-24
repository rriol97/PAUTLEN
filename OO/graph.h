#ifndef GRAPH_H
#define GRAPH_H
#include <stdio.h>
#include "class.h"

typedef struct _Graph Graph;

Graph* createGraph();

void freeGraph(Graph* graph);

/*0 if succesful, -1 if error*/
int addEdge(Graph* graph, int src, int dest);

/*0 if succesful, -1 if error*/
int addClass(Graph* graph, Class * class);

Class* getClass(Graph* graph, int index);

Graph * tablaSimbolosClasesToDot(Graph * graph);

#endif
