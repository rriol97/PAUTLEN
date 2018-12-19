#ifndef GRAPH_H
#define GRAPH_H
#include <stdio.h>
#include "hash.h"

#define MAX_NAME 100

typedef struct {
    char name[MAX_NAME];
    Hash* th_ppal;
    char func_name[MAX_NAME];
    Hash* th_func;
} TablaAmbito;

typedef struct {
    int index;
    char name[MAX_NAME];
    TablaAmbito* tabla;
    int num_at_c;
    int num_at_i;
    int num_me_s;
    int num_me_ns;
} NodoGrafo;

/* Initializes a TablaAmbito correctly.
 * Input:
 *      name: name for the TablaAmbito to have
 * Output: pointer to the TablaAmbito initialized
 */
TablaAmbito* tablaInit(char* name);

/* Frees a TablaAmbito.
 * Input:
 *      tabla: TablaAmbito to free
 * Output: None
 */
void tablaFree(TablaAmbito* tabla);

typedef struct _NodoLista NodoLista;

/* Gets the index that a NodoLista stores
 * Input:
 * 	    nodo: pointer to the NodoLista
 * Output: the index that it stores
 */
int nodoListaGetIndex(NodoLista * nodo);

/* Gets the next NodoLista
 * Input:
 * 	    nodo: pointer to the current NodoLista
 * Output: the next NodoLista on the linked list
 */
NodoLista* nodoListaGetNext(NodoLista* nodo);

typedef struct _Graph Graph;

/* Creates a graph.
 * Input: None
 * Output: the newly created Graph
 */
Graph* createGraph();

/* Frees a graph.
 * Input:
 *      graph: the Graph to free
 * Output: None
 */
void freeGraph(Graph* graph);

/* Adds an edge to a graph.
 * Input:
 *      Graph: the Graph to add the edge to
 *      src: index of the parent class
 *      dest: index of the child class
 * Output: 0 if succesful, -1 if error
 */
int graphAddEdge(Graph* graph, int src, int dest);

/* Adds a class to a graph.
 * Input:
 *      Graph: the Graph to add the class to
 *      class: pointer to the new class
 * Output: index assigned to class if succesful, -1 if error
 */
int graphAddClass(Graph* graph, NodoGrafo * class);

/* Returns the class that an index refers to.
 * Input:
 *      Graph: the Graph to get the class from
 *      index: the index of the class
 * Output: Pointer to the class with the index on the graph
 */
NodoGrafo* graphGetClass(Graph* graph, int index);

/* Returns the class that a name refers to.
 * Input:
 *      Graph: the Graph to get the class from
 *      name: the name of the class
 * Output: Pointer to the class with the name on the graph
 */
NodoGrafo* graphGetClassFromName(Graph* graph, char* name);

/* Creates the .dot file for the graph.
 * Input:
 *      Graph: the Graph to turn into a .dot file
 * Output: The inputted graph
 */
Graph * graphToDot(Graph * graph, FILE* fsalida);

/* Returns a list of the childs of a class.
 * Input:
 *      Graph: the Graph to get the parents from
 *      index: the index of the class
 * Output: Pointer to the list of childs
 */
NodoLista* graphGetChildList(Graph* graph, int src);

/* Returns a list of the parents of a class.
 * Input:
 *      Graph: the Graph to get the parents from
 *      index: the index of the class
 * Output: Pointer to the list of parents
 */
NodoLista* graphGetParentList(Graph* graph, int src);

/* Returns a list of the antecessors of a class (classes inherited from).
 * Input:
 *      Graph: the Graph to get the parents from
 *      index: the index of the class
 * Output: Pointer to the list of parents
 */
NodoLista* graphGetAntecessorList(Graph* graph, int src);

/* Tests the functionality of Graph.
 * Input: None
 * Output: always 0
 */
int test();

void printGraph(Graph* graph);

#endif
