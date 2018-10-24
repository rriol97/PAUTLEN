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
    if (new_node == NULL)
        return NULL;
    new_node->dest = dest;
    new_node->next = NULL;
    return new_node;
}

void freeNode(struct Node* node) {
    struct Node* next;
    if (node == NULL)
        return;
    next = node->next;
    free(node);
    freeNode(next);
}

/* A utility function that creates a graph */
Graph* createGraph() {
    int i;
    Graph* graph = (Graph*) malloc(sizeof (Graph));
    if (graph == NULL)
        return NULL;

    for (i = 0; i < MAX_CLASSES; i++) {
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

    if (graph == NULL)
        return;

    for (i = 0; i < graph->num_classes; i++) {
        freeNode(graph->child_list[i]);
    }

    for (i = 0; i < graph->num_classes; i++) {
        freeNode(graph->parent_list[i]);
    }

    free(graph);
}

/*Adds an edge to the graph*/
int addEdge(Graph* graph, int src, int dest) {
    struct Node* new_node;
    if (graph == NULL || src < 0 || src >= graph->num_classes || dest < 0 || dest >= graph->num_classes)
        return -1;
    /* Add an edge from src to dest.  A new node is  
     * added to the adjacency list of src.  The node 
     * is added at the beginning */
    new_node = newNode(dest);
    if (new_node == NULL)
        return -1;
    new_node->next = graph->child_list[src];
    graph->child_list[src] = new_node;

    /* Since graph is undirected, add an edge from 
     * dest to src also */
    new_node = newNode(src);
    if (new_node == NULL) {
        new_node = graph->child_list[src];
        graph->child_list[src] = new_node->next;
        return -1;
    }
    new_node->next = graph->parent_list[dest];
    graph->parent_list[dest] = new_node;
    return 0;
}

/*Adds a class to the graph*/
int addClass(Graph* graph, Class* class) {
    if (graph == NULL || class == NULL || graph->num_classes == MAX_CLASSES)
        return -1;
    graph->classes[graph->num_classes] = class;
    class->index = graph->num_classes;
    graph->num_classes++;
    return 0;
}

/*Gets the class that a certain index represents*/
Class* getClass(Graph* graph, int index) {
    if (graph == NULL || index < 0 || index >= graph->num_classes)
        return NULL;
    return graph->classes[index];
}

/* A utility function to print the adjacency list  
 * representation of graph */
void printGraph(Graph* graph) {
    int i;
    if (graph == NULL)
        return;
    for (i = 0; i < graph->num_classes; i++) {
        struct Node* pCrawl = graph->child_list[i];
        printf("\n Adjacency list of vertex %d\n head ", i);
        while (pCrawl) {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\nParent list: ");
        pCrawl = graph->parent_list[i];
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
    graph->num_classes = 5;
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    /* print the adjacency list representation of the above graph */
    printGraph(graph);

    freeGraph(graph);

    return 0;
}
