#include <stdio.h>
#include <stdlib.h>
#include "breadthOperators.c"
#include "header.h"

void breadth (struct graph *graphTree, int startVertex){
    printf("\n");
    struct queue *list = createQueue();

    graphTree->visited[startVertex] = 1;
    enqueue(list, startVertex);
    while (!isEmpty(list)){
        int current = dequeue(list);
        printf("%d ->", current);
        struct vertex *temp = graphTree->adjLists[current];
        while (temp){
            if (graphTree->visited[temp->value] == 0){
                graphTree->visited[temp->value] = 1;
                enqueue(list, temp->value);
            }
            temp = temp->next;
        }
    }

}
