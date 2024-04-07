#include <stdio.h>
#include <stdlib.h>
#include "treeStruct.h"
#include "printTree.h"

struct leaf *searchLeaf(struct leaf *root, int number, int foundIt){
    // Case if the root is empty
    if (root == NULL)
    {
        return NULL;
    }

    //Case if the value of the root matches the user's entered number to delete
    if(root->value == number)
    {
        printf("\nCurrent Tree (NOTE: %d is the root) \n\n", root->value);
        printTree(root);
        printf("\n\nNode Value: %d exists within the tree!", root->value);
        foundIt = 1;
        return root;
    }

    //Searching process to find the exact number.
    if(number > root->value)
    {
        searchLeaf(root->right, number, foundIt);
    }
    else
    {
        searchLeaf(root->left, number, foundIt);
    }

    return root;
}