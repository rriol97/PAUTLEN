#ifndef GRAPH_H
#define GRAPH_H
#include <stdio.h>

#define MAX_NAME 100

typedef struct {
    int index;
    char name[MAX_NAME];
    /*TablaAmbito tabla;*/
} Class;

typedef struct _Graph Graph;

Graph* createGraph();

void freeGraph(Graph* graph);

/*0 if succesful, -1 if error*/
int addEdge(Graph* graph, int src, int dest);

/*0 if succesful, -1 if error*/
int addClass(Graph* graph, Class * class);

Class* getClass(Graph* graph, int index);

#endif