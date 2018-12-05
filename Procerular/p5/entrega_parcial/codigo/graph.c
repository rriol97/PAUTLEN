#include <stdio.h> 
#include <stdlib.h> 
#include "graph.h"

/* Define maximum number of vertices in the graph*/
#define MAX_CLASSES 200

/* Data structure to store graph*/
struct _Graph {
    /* An array of pointers to NodoLista to represent adjacency list*/
    NodoLista* child_list[MAX_CLASSES];  /*represents arrows that start on the node*/
    NodoLista* parent_list[MAX_CLASSES]; /*represents arrows that end on the node*/
    NodoGrafo* nodos[MAX_CLASSES];
    int num_classes;
    NodoLista* antecessors[MAX_CLASSES]; /*list of all the antecessor nodes, including non direct parents*/
};

/* A data structure to store adjacency list nodes of the graph*/
struct _NodoLista {
    int dest;
    NodoLista* next;
};

/* A utility function to create a new adjacency list node */
NodoLista* newNode(int dest) {
    NodoLista* new_node = (NodoLista*) malloc(sizeof (NodoLista));
    if (new_node == NULL)
        return NULL;
    new_node->dest = dest;
    new_node->next = NULL;
    return new_node;
}

void freeNode(NodoLista* node) {
    NodoLista* next;
    if (node == NULL)
        return;
    next = node->next;
    free(node);
    freeNode(next);
}

int addAntecessors(Graph* graph, int src, int dest) {
    int indexes_in[MAX_CLASSES] = {0}; /*lista que guarda si un indice esta ya en la lista*/
    NodoLista* aux;
    NodoLista* new_node, *head, *tail;
    
    /*recorremos la lista ya existente hasta el final*/
    for(aux = graph->antecessors[dest]; aux != NULL; aux = aux->next) {
        indexes_in[aux->dest] = 1;
    }
    /*crea una lista para almacenar los nuevos padres de mas reciente a mas antiguo*/
    /*empezando por src*/
    head = newNode(src);
    if (head == NULL)
        return -1;
    tail = head;
    
    /*recorrer lista de padres de src*/
    for(aux = graph->parent_list[src]; aux != NULL; aux = aux->next) {
        /*si la clase no esta en la lista*/
        if(indexes_in[aux->dest] == 0) {
            /*añade la clase a la nueva lista*/
            new_node = newNode(aux->dest);
            if (new_node == NULL) {
                freeNode(head);
                return -1;
            }
            tail->next = new_node;
            tail = new_node;
        }
    }     
    /*añade la lista a la lista de padres de dest*/
    tail->next = graph->antecessors[dest];
    graph->antecessors[dest] = head;
    return 0;
}

TablaAmbito* tablaInit(char* name) {
    TablaAmbito* tabla;
    if(name == NULL)
        return NULL;
    tabla = malloc(sizeof(TablaAmbito));
    if(tabla == NULL)
        return NULL;
    strcpy(tabla->name, name);
    strcpy(tabla->func_name, "");
    tabla->th_ppal = NULL;
    tabla->th_func = NULL;
    return tabla;
}

void tablaFree(TablaAmbito* tabla) {
    if(tabla == NULL)
        return;
    clear_symbols(&(tabla->th_ppal));
    clear_symbols(&(tabla->th_func));
    free(tabla);
}

int nodoListaGetIndex(NodoLista * nodo) {
    if(nodo == NULL)
        return -1;
    return nodo->dest;
}

NodoLista* nodoListaGetNext(NodoLista* nodo) {
    if(nodo == NULL)
        return NULL;
    return nodo->next;
}

Graph* createGraph() {
    int i;
    Graph* graph = (Graph*) malloc(sizeof (Graph));
    if (graph == NULL)
        return NULL;

    for (i = 0; i < MAX_CLASSES; i++) {
        graph->child_list[i] = NULL;
        graph->parent_list[i] = NULL;
        graph->nodos[i] = NULL;
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
        freeNode(graph->antecessors[i]);
    }

    free(graph);
}

/*Adds an edge to the graph*/
int graphAddEdge(Graph* graph, int src, int dest) {
    NodoLista* new_node;
    if (graph == NULL || src < 0 || src == dest || dest >= graph->num_classes)
        return -1;

    if(src > dest)
        return graphAddEdge(graph, dest, src);

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
    
    /* Finally updates the list of antecessors*/
    return addAntecessors(graph, src, dest);
}

/*Adds a class to the graph*/
int graphAddClass(Graph* graph, NodoGrafo* nodo) {
    if (graph == NULL || nodo == NULL || graph->num_classes == MAX_CLASSES)
        return -1;
    graph->nodos[graph->num_classes] = nodo;
    nodo->index = graph->num_classes;
    graph->num_classes++;
    return nodo->index;
}

/*Gets the class that a certain index represents*/
NodoGrafo* graphGetClass(Graph* graph, int index) {
    if (graph == NULL || index < 0 || index >= graph->num_classes)
        return NULL;
    return graph->nodos[index];
}

NodoGrafo* graphGetClassFromName(Graph* graph, char* name) {
    int i;
    if (graph == NULL || name == NULL)
        return NULL;
    for(i = 0; i < graph->num_classes; i++) {
        if(strcmp(graph->nodos[i]->name, name) == 0)
            return graph->nodos[i];
    }
    return NULL;
}

/* A utility function to print the adjacency list  
 * representation of graph */
void printGraph(Graph* graph) {
    int i;
    if (graph == NULL)
        return;
    for (i = 0; i < graph->num_classes; i++) {
        NodoLista* pCrawl = graph->child_list[i];
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
        printf("\nAntecessors of %d: ", i);
        pCrawl = graph->antecessors[i];
        while (pCrawl) {
            printf(" %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

Graph * graphToDot(Graph * graph, FILE* fsalida) {
    int i;
    NodoLista* next;
    Hash *s;

    fprintf(fsalida, "digraph grafo_clases  { rankdir=BT;\nedge [arrowhead = empty]\n");
    for(i = 0; i<graph->num_classes; i++) {
        fprintf(fsalida, "%s [label=\"{%s|%s\\l", graph->nodos[i]->name, graph->nodos[i]->name, graph->nodos[i]->name);

        for(s=graph->nodos[i]->tabla->th_ppal; s != NULL; s=s->hh.next) {
            fprintf(fsalida, "%s\\l", s->name);
        }
        fprintf(fsalida, "}\"][shape=record];\n");
    }
    for(i = 0; i<graph->num_classes; i++) {
        next = graph->parent_list[i];
        while(next != NULL) {
            fprintf(fsalida, "%s -> %s ;\n", graph->nodos[i]->name, graph->nodos[next->dest]->name);
            next = next->next;
        }
    }
    fprintf(fsalida, "edge [arrowhead = normal]\n");
    for(i = 0; i<graph->num_classes; i++) {
        fprintf(fsalida, "%sN%d [label=\"%s\"][shape=oval];\n", graph->nodos[i]->name, i, graph->nodos[i]->name);
    }
    for(i = 0; i < (graph->num_classes - 1); i++) {
        fprintf(fsalida, "%sN%d -> %sN%d ;\n",  graph->nodos[i]->name, i,  graph->nodos[i+1]->name, i+1);
    }
    fprintf(fsalida, "\n}");
    return graph;
}

NodoLista* graphGetChildList(Graph* graph, int src) {
    if (graph == NULL || src < 0 || src >= graph->num_classes)
        return NULL;
    return graph->child_list[src];
}

NodoLista* graphGetParentList(Graph* graph, int src) {
    if (graph == NULL || src < 0 || src >= graph->num_classes)
        return NULL;
    return graph->parent_list[src];
}

NodoLista* graphGetAntecessorList(Graph* graph, int src) {
    if (graph == NULL || src < 0 || src >= graph->num_classes)
        return NULL;
    return graph->antecessors[src];
}

/* Driver program to test above functions */
int test() {
    /* create the graph */
    Graph* graph = createGraph();
    graph->num_classes = 5;
    graphAddEdge(graph, 0, 1);
    graphAddEdge(graph, 0, 4);
    graphAddEdge(graph, 1, 2);
    graphAddEdge(graph, 1, 3);
    graphAddEdge(graph, 1, 4);
    graphAddEdge(graph, 2, 3);
    graphAddEdge(graph, 3, 4);

    /* print the adjacency list representation of the above graph */
    printGraph(graph);

    freeGraph(graph);

    return 0;
}
