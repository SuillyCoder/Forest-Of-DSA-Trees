/*============================================================================
 FILE        : printing.c
 AUTHORS     : Jesus Lorenzo C. Basuil
 DESCRIPTION : This file contains the function responsible for printing the graphical representation
               of the AVL tree.
 REVISION HISTORY:
 Date:               By:                                     Description:
      31/03/2024        Jesus Lorenzo C. Basuil                      Starting the project
============================================================================*/


#include <stdio.h>
#include <stdlib.h>
#include "treeStruct.h"

/*
============================================================================
 FUNCTION    : void positioning(struct node* root, int spaces)

 DESCRIPTION : This function is responsible for putting each of the added
               nodes in the correct position in the added tree.


 ARGUMENTS   :
                - struct node* entry: Pointer to the root of the subtree to be
                  searched.

 RETURNS     :
                N/A
===========================================================================
*/


void positioning(struct node* root, int spaces) {
    // Base case
    if (root == NULL) {
        return;
    }

    // Increase indentation for the next level
    spaces += 5;

    // Print right subtree first
    positioning(root->right, spaces);

    // Print current node with leading spaces
    printf("%*s", spaces, ""); // Use "*" for dynamic width
    printf("%d\n", root->value);

    // Print left subtree
    positioning(root->left, spaces);
}

/*
============================================================================
 FUNCTION    : void print_tree(struct node* root)

 DESCRIPTION : This function is responsible for printing the actual tree
               once the nodes have been set in place.

 ARGUMENTS   :
                - struct node* root: Pointer to the root of the
                  tree to start printing from
                - int spaces: The number of spaces to print between
                numbers in the tree.

 RETURNS     :
                N/A
===========================================================================
*/

void print_tree(struct node* root) {
    // Pass initial space count as 0
    positioning(root, 0);
}


