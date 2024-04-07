#include <stdio.h>
#include <stdlib.h>
#include "treeStruct.h"

void positioning (struct leaf *root, int spaces){
    if (root == NULL){
        return;
    }
    spaces += 5;

    positioning(root->right, spaces);
    printf("%*s", spaces, "");
    printf("%d\n", root->value);

    positioning(root->left, spaces);
}

void printTree (struct leaf *root){
    positioning(root, 0);
}