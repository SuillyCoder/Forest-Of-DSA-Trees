#include <stdio.h>
#include <stdlib.h>
#include "searchers.h"
#include "queueFunctions.c"

void BFS (struct node *root){
    if (root == NULL){
        return;
    }
    struct queue *temp = NULL;
    enqueue(&temp, root);
    while (temp != NULL){
        struct node *current = dequeue(&temp);
        printf(" %d ", current->value);
        if (current->left != NULL){
            enqueue(&temp, current->left);
        }
        if (current->right != NULL){
            enqueue(&temp, current->right);
        }
    }
}