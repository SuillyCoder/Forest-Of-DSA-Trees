#include <stdlib.h>
#include <stdio.h>
#include "header.h"

struct vertex *createVertex(int value){
    struct vertex *newVertex = (struct vertex*)malloc(sizeof(struct vertex));
    newVertex->next = NULL;
    newVertex->value = value;
    return newVertex;
}

struct graph *createGraph(unsigned long long vertices){
    struct graph *graphTree = (struct graph*)malloc(sizeof(struct graph));
    graphTree->vertexCount = vertices; 

    graphTree->adjLists = malloc(vertices * sizeof(struct vertex));
    graphTree->visited = malloc(vertices * sizeof(int));

    for(unsigned long long i = 0; i < vertices; i++){
        graphTree->adjLists[i] = NULL;
    }
    return graphTree;
}

void addEdge(struct graph *graphTree, int origin, int endpoint){
    struct vertex *newVertex = createVertex(endpoint);
    newVertex->next = graphTree->adjLists[origin];
    graphTree->adjLists[origin] = newVertex;

    newVertex = createVertex(origin);
    newVertex->next = graphTree->adjLists[endpoint];
    graphTree->adjLists[endpoint] = newVertex;  
}
