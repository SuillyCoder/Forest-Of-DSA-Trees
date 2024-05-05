#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void displayGraph(struct graph *graphTree){
    unsigned long long v;
    for (v = 0; v < graphTree->vertexCount; v++){
            struct vertex *temp = graphTree->adjLists[v];
            if (temp != NULL){
            printf("\nVertex: %llu \n\n %llu -> ", v, v);
            while (temp){
                printf("%d -> ", temp->value);
                temp = temp->next;
            }
            printf(" NULL");
            printf("\n");
            }
    }
}
