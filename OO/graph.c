#include <stdio.h> 
#include <stdlib.h> 
#include "graph.h"

/* Define maximum number of vertices in the graph*/
#define MAX_CLASSES 200

/* Data structure to store graph*/
struct _Graph {
    /* An array of pointers to NodoLista to represent adjacency list*/
    struct NodoLista* child_list[MAX_CLASSES];  /*represents arrows that start on the node*/
    struct NodoLista* parent_list[MAX_CLASSES]; /*represents arrows that end on the node*/
    NodoGrafo* nodos[MAX_CLASSES];
    int num_classes;
    int* antecessors[MAX_CLASSES]; /*list of all the antecessor nodes, including non direct parents*/
};

/* A data structure to store adjacency list nodes of the graph*/
struct NodoLista {
    int dest;
    struct NodoLista* next;
};

/* A utility function to create a new adjacency list node */
struct NodoLista* newNode(int dest) {
    struct NodoLista* new_node = (struct NodoLista*) malloc(sizeof (struct NodoLista));
    if (new_node == NULL)
        return NULL;
    new_node->dest = dest;
    new_node->next = NULL;
    return new_node;
}

void freeNode(struct NodoLista* node) {
    struct NodoLista* next;
    if (node == NULL)
        return;
    next = node->next;
    free(node);
    freeNode(next);
}

int addAntecessors(Graph* graph, int src, int dest) {
    int indexes_in[MAX_CLASSES] = {0}; /*lista que guarda si un indice esta ya en la lista*/
    int i;
    struct NodoLista* aux;
    
    /*recorremos la lista ya existente hasta encontrar un -1*/
    for(i = 0; graph->antecessors[src][i] != -1; i++) {
        indexes_in[graph->antecessors[src][i]] = 1;
    }
    
    /*recorrer lista de padres de dest*/
    for(aux = graph->parent_list[dest]i; aux != NULL; aux = aux->next) {
        /*si la clase no esta en la lista*/
        if(indexes_in[aux->dest] == 0) {
            /*añade la clase a la lista de padres de src*/
            graph->antecessors[src][i] = aux->dest;
            indexes_in[aux->dest] = 1;
            i++;
        }
    }     
    /*añade dest a la lista de padres*/
    graph->antecessors[src][i] = dest;
    indexes_in[dest] = 1;
    return 0;
}

void tablaInit(TablaAmbito* tabla, char* name) {
    if(tabla == NULL || name == NULL)
        return;
    strcpy(tabla->name, name);
    tabla->th_ppal = NULL;
    tabla->th_func = NULL;
    return;
}

Graph* createGraph() {
    int i;
    Graph* graph = (Graph*) malloc(sizeof (Graph));
    if (graph == NULL)
        return NULL;

    for (i = 0; i < MAX_CLASSES; i++) {
        graph->child_list[i] = NULL;
        graph->parent_list[i] = NULL;
        graph->classes[i] = NULL;
        graph->antecessors[i] = NULL;
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
        freeNode(graph->parent_list[i]);
        free(graph->antecessors[i]);
    }

    free(graph);
}

/*Adds an edge to the graph*/
int addEdge(Graph* graph, int src, int dest) {
    struct NodoLista* new_node;
    if (graph == NULL || src < 0 || src == dest || dest >= graph->num_classes)
        return -1;

    if(src > dest)
        return addEdge(graph, dest, src);

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
        freeNode(new_node);
        return -1;
    }
    new_node->next = graph->parent_list[dest];
    graph->parent_list[dest] = new_node;
    return addAntecessors(graph, src, dest);
}

/*Adds a class to the graph*/
int addClass(Graph* graph, NodoGrafo* nodo) {
    if (graph == NULL || class == NULL || graph->num_classes == MAX_CLASSES)
        return -1;
    /*Reserva memoria para la lista de padres*/
    graph->antecessors[graph->num_classes] = malloc(num_classes*sizeof(int));
    if(graph->antecessors[graph->num_classes] == NULL) {
        return -1;
    }
    /*Inicializa la lista de padres a -1*/
    memset(graph->antecessors[graph->num_classes], -1, num_classes*sizeof(int));
    graph->classes[graph->num_classes] = class;
    class->index = graph->num_classes;
    graph->num_classes++;
    return class->index;
}

/*Gets the class that a certain index represents*/
NodoGrafo* getClass(Graph* graph, int index) {
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
        struct NodoLista* pCrawl = graph->child_list[i];
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

Graph * tablaSimbolosClasesToDot(Graph * graph) {
    FILE* f;
    int i;
    struct NodoLista* next;
    Hash *s;

    f = fopen("grafo.dot", "w");
    fprintf(f, "digraph grafo_clases  { rankdir=BT;\nedge [arrowhead = empty]\n");
    for(i = 0; i<graph->num_classes; i++) {
        fprintf(f, "%s [label=\"{%s|%s\\l", graph->classes[i]->name, graph->classes[i]->name, graph->classes[i]->name);

        for(s=graph->classes[i]->tabla.th_ppal; s != NULL; s=s->hh.next) {
            fprintf(f, "%s\\l", s->name);
        }
        fprintf(f, "}\"][shape=record];\n");
    }
    for(i = 0; i<graph->num_classes; i++) {
        next = graph->parent_list[i];
        while(next != NULL) {
            fprintf(f, "%s -> %s ;\n", graph->classes[i]->name, graph->classes[next->dest]->name);
            next = next->next;
        }
    }
    fprintf(f, "edge [arrowhead = normal]\n");
    for(i = 0; i<graph->num_classes; i++) {
        fprintf(f, "%sN%d [label=\"%s\"][shape=oval];\n", graph->classes[i]->name, i, graph->classes[i]->name);
    }
    for(i = 0; i < (graph->num_classes - 1); i++) {
        fprintf(f, "%sN%d -> %sN%d ;\n",  graph->classes[i]->name, i,  graph->classes[i+1]->name, i+1);
    }
    fprintf(f, "\n}");
    fclose(f);
    return graph;
}

int* getParentList(Graph* graph, int src) {
    if (graph == NULL || src < 0 || src >= graph->num_classes)
        return NULL;
    return graph->antecessors[src];
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
