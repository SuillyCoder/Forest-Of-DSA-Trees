#include <stdio.h>
#include <stdlib.h>
#include "treeStruct.h"

void preOrder(struct leaf *root){
    if (root != NULL){
        printf(" %d ", root->value);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct leaf *root){
    if (root != NULL){
        inOrder(root->left);
        printf(" %d ", root->value);
        inOrder(root->right);
    }
}

void postOrder(struct leaf *root){
    if (root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf(" %d ", root->value);
    }
}

void breadth (struct leaf *root){
     if (root != NULL){
        return;
     }
        struct leaf *leafQueue[100];
        int front = 0, rear = -1;

        leafQueue[++rear] = root;

        while(front <= rear){
            struct leaf *current = leafQueue[front++];
            printf(" %d ", current->value);

            if (current->left){
                leafQueue[++rear] = current->left;
            }
            if (current->right){
                leafQueue[++rear] = current->right;
            }
        }
}
