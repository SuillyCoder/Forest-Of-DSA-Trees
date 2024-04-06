#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void inOrder(struct node *root){
    if (root != NULL){
        preOrder(root->left);
        printf(" %d ", root->value);
        preOrder(root->right);
    }
}