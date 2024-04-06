#include <stdlib.h>
#include "functions.h"

//TO FIND THE MINIMUM VALUE FOR CASE 3: 

struct node *minValueNode(struct node *root){
    struct node *current = root;

    while(current->left != NULL){
        current = current->left;
    }
    return current;
}


struct node *deleteNode(struct node *root, int num, int foundIt){
    //BASE CASE
    if (root == NULL){
        return root;
    }

    // FINDING THE NUMBER TO BE DELETED:

    if (num < root->value){
        root->left = deleteNode(root->left, num, foundIt);
    }

    else if (num > root ->value){
        root->right = deleteNode(root->right, num, foundIt);
    }

    // CASE 1 & CASE 2: 

    else{
        if (root->left == NULL){
            struct node *temp = root->right;
            free(root);
            foundIt = 1;
            return temp;
        }
        else if(root->right == NULL){
            struct node *temp = root->left;
            free(root);
            foundIt = 1;
            return temp;
        }
    //CASE 3: 

        struct node *temp = minValueNode(root->right); 
        root->value = temp->value;
        root->right = deleteNode(root->right, temp->value, foundIt);
    }

    return root;
}