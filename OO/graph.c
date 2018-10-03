#include <stdio.h> 
#include <stdlib.h> 
#include "graph.h"

/* Define maximum number of vertices in the graph*/
#define MAX_CLASSES 200

/* Data structure to store graph*/
struct _Graph {
    /* An array of pointers to Node to represent adjacency list*/
    struct Node* child_list[MAX_CLASSES];
    struct Node* parent_list[MAX_CLASSES];
    Class* classes[MAX_CLASSES];
    int num_classes;
};

/* A data structure to store adjacency list nodes of the graph*/
struct Node {
    int dest;
    struct Node* next;
};

/* A utility function to create a new adjacency list node */
struct Node* newNode(int dest) {
    struct Node* new_node = (struct Node*) malloc(sizeof (struct Node));
    new_node->dest = dest;
    new_node->next = NULL;
    return new_node;
}

/* A utility function that creates a graph */
Graph* createGraph() {
    Graph* graph = (Graph*) malloc(sizeof (Graph));

    int i;
    for (i = 0; i < N; i++) {
        graph->child_list[i] = NULL;
        graph->parent_list[i] = NULL;
    }

    for (i = 0; i < MAX_CLASSES; i++) {
        graph->classes[i] = NULL;
    }

    graph->num_classes = 0;

    return graph;
}

void freeGraph(Graph* graph) {
    int i;

    for (i = 0; graph->child_list[i] != NULL; i++) {
        free(graph->child_list[i]);
    }
    
    for (i = 0; graph->parent_list[i] != NULL; i++) {
        free(graph->parent_list[i]);
    }
}

/*Adds an edge to the graph*/
void addEdge(Graph* graph, int src, int dest) {
    /* Add an edge from src to dest.  A new node is  
     * added to the adjacency list of src.  The node 
     * is added at the beginning */
    struct Node* new_node = newNode(dest);
    new_node->next = graph->child_list[src];
    graph->child_list[src] = new_node;

    /* Since graph is undirected, add an edge from 
     * dest to src also */
    new_node = newNode(src);
    new_node->next = graph->parent_list[dest];
    graph->parent_list[dest] = new_node;
}

/*Adds a class to the graph*/
void addClass(Graph* graph, Class* class) {
    graph->classes[graph->num_classes] = class;
    graph->num_classes++;
}

/*Gets the class that a certain index represents*/
Class* getClass(Graph* graph, int index) {
    return graph->classes[index];
}

/* A utility function to print the adjacency list  
 * representation of graph */
void printGraph(Graph* graph) {
    int i;
    for (i = 0; i < graph->num_classes; i++) {
        struct Node* pCrawl = graph->child_list[i];
        printf("\n Adjacency list of vertex %d\n head ", i);
        while (pCrawl) {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

/* Driver program to test above functions */
int test() {
    /* create the graph */
    Graph* graph = createGraph();
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    graph->num_classes = 5;

    /* print the adjacency list representation of the above graph */
    printGraph(graph);
    
    freeGraph(graph);

    return 0;
}
