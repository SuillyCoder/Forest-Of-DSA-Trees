#ifndef SEARCHERS_H
#define SEARCHERS_H

#include "preOrder.c"
#include "inOrder.c"
#include "postOrder.c"

#include "functions.h"

struct queue{
    struct node *queueNum;
    struct queue *next;
};

void preOrder(struct node *root);
void inOrder(struct node *root);
void postOrder(struct node *root);

void enqueue(struct queue **head, struct node *number);
struct node *dequeue (struct queue **head);
void BFS (struct node *root);


#endif