#include <stdlib.h>
#include "searchers.h"

void enqueue (struct queue **head, struct node *number){
    struct queue *newNode = (struct queue*)malloc(sizeof(struct queue));
    newNode->queueNum = number;
    newNode->next = NULL;

    if (*head == NULL){
        *head = newNode;
    }
    else{
        struct queue *temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
struct node *dequeue (struct queue **head){
    if (*head == NULL){
        return NULL;
    }
    struct node *tempItem = (*head)->queueNum;
    struct queue *tempNode = *head;
    *head = (*head)->next;
     free(tempNode);
     return tempItem;
}