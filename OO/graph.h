#ifndef GRAPH_H
#define GRAPH_H
#include <stdio.h>
#include "hash.h"

#define MAX_NAME 100

typedef struct {
    char name[MAX_NAME];
    Hash* th_ppal;
    Hash* th_func;
} TablaAmbito;

typedef struct {
    int index;
    char name[MAX_NAME];
    TablaAmbito tabla;
    int num_at_c;
    int num_at_i;
    int num_me_s;
    int num_me_ns;
} NodoGrafo;

/* Initializes a TablaAmbito correctly.
 * Input: 
 * 	    tabla: pointer to the TablaAmbito to initialize
 *      name: name for the TablaAmbito to have
 * Output: None
 */
void tablaInit(TablaAmbito* tabla, char* name);

/*TODO: funciones para insertar atributos de clase y instancia, metodos sobre y no sobres*/

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
 * 	    graph: the Graph to free
 * Output: None
 */
void freeGraph(Graph* graph);

/* Adds an edge to a graph.
 * Input:
 * 	    Graph: the Graph to add the edge to
 *      src: index of the parent class
 *      dest: index of the child class
 * Output: 0 if succesful, -1 if error
 */
int addEdge(Graph* graph, int src, int dest);

/* Adds a class to a graph.
 * Input:
 * 	    Graph: the Graph to add the class to
 *      class: pointer to the new class
 * Output: index assigned to class if succesful, -1 if error
 */
int addClass(Graph* graph, NodoGrafo * class);

/* Returns the class that an index refers to.
 * Input: 
 * 	    Graph: the Graph to get the class from
 *      index: the index of the class
 * Output: Pointer to the class with the index on the graph
 */
NodoGrafo* getClass(Graph* graph, int index);

/* Creates the .dot file for the graph.
 * Input: 
 * 	    Graph: the Graph to turn into a .dot file
 * Output: The inputted graph
 */
Graph * tablaSimbolosClasesToDot(Graph * graph);

/* Returns a list of the childs of a class.
 * Input: 
 * 	    Graph: the Graph to get the parents from
 *      index: the index of the class
 * Output: Pointer to the list of childs
 */
NodoLista* getChildList(Graph* graph, int src);

/* Returns a list of the parents of a class.
 * Input: 
 * 	    Graph: the Graph to get the parents from
 *      index: the index of the class
 * Output: Pointer to the list of parents
 */
NodoLista* getParentList(Graph* graph, int src);

/* Returns a list of the antecessors of a class (classes inherited from).
 * Input: 
 * 	    Graph: the Graph to get the parents from
 *      index: the index of the class
 * Output: Pointer to the list of parents
 */
NodoLista* getAntecessorList(Graph* graph, int src);

/* Tests the functionality of Graph.
 * Input: None
 * Output: always 0
 */
int test();

#endif
