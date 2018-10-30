#ifndef GRAPH_H
#define GRAPH_H
#include <stdio.h>
#include "class.h"

typedef struct _Graph Graph;

/* Creates a graph.
 * Input: None
 * Output: the newly created Graph
 */
Graph* createGraph();

/* Frees a graph.
 * Input: 
   	    Graph: the Graph to free
 * Output: None
 */
void freeGraph(Graph* graph);

/* Adds an edge to a graph.
 * Input:
   	    Graph: the Graph to add the edge to
        src: index of the parent class
        dest: index of the child class
 * Output: 0 if succesful, -1 if error
 */
int addEdge(Graph* graph, int src, int dest);

/* Adds a class to a graph.
 * Input:
   	    Graph: the Graph to add the class to
        class: pointer to the new class
 * Output: index assigned to class if succesful, -1 if error
 */
int addClass(Graph* graph, Class * class);

/* Returns the class that an index refers to.
 * Input: 
   	    Graph: the Graph to get the class from
        index: the index of the class
 * Output: Pointer to the class with the index on the graph
 */
Class* getClass(Graph* graph, int index);

/* Creates the .dot file for the graph.
 * Input: 
   	    Graph: the Graph to turn into a .dot file
 * Output: The inputted graph
 */
Graph * tablaSimbolosClasesToDot(Graph * graph);

/* Returns a list of the parent of a class.
 * Input: 
   	    Graph: the Graph to get the parents from
        index: the index of the class
        size: pointer to store the size of the returning array
 * Output: Pointer to the allocated list of parents, user must free it when necessary
 */
Class** getParentList(Graph* graph, int src, int* size);

#endif
