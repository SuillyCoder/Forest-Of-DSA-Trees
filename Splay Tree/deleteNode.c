#include <stdlib.h>
#include <stdio.h>
#include "treeStruct.h"
#include "operations.h"

int foundIt = 0;

struct leaf *minValue(struct leaf *root){
    struct leaf *current = root;

    while(current->left != NULL){
        current = current->left;
    }
    return current;
}


struct leaf *deleteLeaf(struct leaf *root, int deletor){
    //BASE CASE
    if (root == NULL){
        return root;
    }

    // FINDING THE NUMBER TO BE DELETED:

    if (deletor < root->value){
        root->left = deleteLeaf(root->left, deletor);
    }

    else if (deletor > root ->value){
        root->right = deleteLeaf(root->right, deletor);
    }

    // CASE 1 & CASE 2:

    else{
        if (root->left == NULL){
            struct leaf *temp = root->right;
            free(root);
            foundIt = 1;
            return temp;;
        }
        else if(root->right == NULL){
            struct leaf *temp = root->left;
            free(root);
            foundIt = 1;
            return temp;
        }
    //CASE 3:

        struct leaf *temp = minValue(root->right);
        root->value = temp->value;
        root->right = deleteLeaf(root->right, temp->value);
    }

    return root;
}
