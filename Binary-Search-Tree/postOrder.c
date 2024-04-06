#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void postOrder(struct node *root){
    if (root != NULL){
        preOrder(root->left);
        preOrder(root->right);
        printf(" %d ", root->value);
    }
}