#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void deleteVertex(struct graph *graphTree, int deletor){
    int foundIt = 0;
    unsigned long long v;
    for (v = 0; v < graphTree->vertexCount; v++){
            struct vertex *current = graphTree->adjLists[v];
            struct vertex *previous = NULL;
            if (current != NULL){
            while (current){
                if (v == deletor) {
                    graphTree->adjLists[v] = current->next;
                    current = graphTree->adjLists[v];
                }
                else if (current->value == deletor){
                    if (previous == NULL){
                          graphTree->adjLists[v] = current->next;
                    }
                    else{
                        previous->next = current->next;
                    }
                    struct vertex *temp = current;
                    current = current->next;
                    free(temp);
                    foundIt = 1;
                }
                else{
                    previous = current;
                    current = current->next;
                 }
             }
        }
    }

    if (foundIt != 1) {
        printf("\n\nThis vertex does not exist within the Graph!\n\n");
    }
    else{
         printf("Vertex Value: %d has been successfully deleted", deletor);
    }
}
