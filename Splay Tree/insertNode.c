#include <stdio.h>
#include <stdlib.h>
#include "treeStruct.h"
#include "splaying.h"

struct leaf *createLeaf(int value){
    struct leaf *newLeaf = (struct leaf*)malloc(sizeof(struct leaf));
    newLeaf->value = value;
    newLeaf->right = NULL; newLeaf->left = NULL;

    return newLeaf;
}

struct leaf *insertLeaf(struct leaf *root, int number){
    if (root==NULL){
        return createLeaf(number);
    }
    root = splay(root, number);

    if (root->value == number){
        return root;
    }
    struct leaf *temp  = createLeaf(number);

    if (root->value > number){
        temp->right = root;
        temp->left = root->left;
        root->left = NULL;
    }
    else{
        temp->left = root;
        temp->right = root->right;
        root->right = NULL;
    }

    return temp;
}
