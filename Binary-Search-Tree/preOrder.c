#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void preOrder(struct node *root){
    if (root != NULL){
        printf(" %d ", root->value);
        preOrder(root->left);
        preOrder(root->right);
    }
}