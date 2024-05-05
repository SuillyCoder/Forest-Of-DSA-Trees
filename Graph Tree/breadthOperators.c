#include <stdio.h>
#include <stdlib.h>
#include "header.h"

struct queue *createQueue(void){
    struct queue *list = (struct queue*)malloc(sizeof(struct queue));
    list->front = -1;
    list->rear = -1;
    return list;
}

int isEmpty (struct queue *list){
    if (list->rear == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue (struct queue *list, int value){
    if (list->rear == 500 - 1){
        printf("\n\nQueue is at full capacity!\n\n");
    }
    else{
        if (list->front == -1){
            list->front = 0;
        }
        list->rear++;
        list->items[list->rear] = value;
    }
}

int dequeue (struct queue *list){
    int item; 
    if (isEmpty(list)){
        item = -1;
    }
    else{
        item = list->items[list->front];
        list->front++;
        if (list->front > list->rear){
            list->front = list->rear = -1;
        }
    }
    return item;
}
