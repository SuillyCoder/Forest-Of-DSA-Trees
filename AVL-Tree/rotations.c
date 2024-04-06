/*============================================================================
 FILE        : rotations.c
 AUTHORS     : Jesus Lorenzo C. Basuil
 DESCRIPTION : This file contains rotations functions (both single and double rotations)
               responsible for balancing out the AVL tree.
 REVISION HISTORY:
 Date:               By:                                     Description:
      28/03/2024        Jesus Lorenzo C. Basuil                   Starting the project
 Date:               By:                                     Description:
      30/03/2024        Jesus Lorenzo C. Basuil                   Finished revision and implementation
============================================================================*/


#include <stdlib.h>
#include "treeStruct.h"
#include "balanceFactor.h"

/*
============================================================================
 FUNCTION    : struct node *leftTurn(struct node *x)

 DESCRIPTION : A utility function to perform a left rotation on the subtree
               rooted with the given node 'x'.

 ARGUMENTS   :
                - struct node *x: Pointer to the root node of the subtree to be
                  rotated.

 RETURNS     :
                - struct node*: Pointer to the root of the rotated subtree.
===========================================================================
*/


struct node *leftTurn (struct node *x){
    struct node *y = x->right;
    struct node *temp = y->left;

    //Rotation Operation
    y->left = x;
    x->right = temp;

    //Recalculating Height
    x->height = maximum(height(y->left), height(y->right)) + 1;
    y->height = maximum(height(x->left), height(x->right)) + 1;

    //Returns the node
    return y;
}

/*
============================================================================
 FUNCTION    : struct node *rightTurn(struct node *y)

 DESCRIPTION : A utility function to perform a right rotation on the subtree
               rooted with the given node 'y'.

 ARGUMENTS   :
                - struct node *y: Pointer to the root node of the subtree to be
                  rotated.

 RETURNS     :
                - struct node*: Pointer to the root of the rotated subtree.
===========================================================================
*/

struct node *rightTurn (struct node *y){
    struct node *x = y->left;
    struct node *temp = x->right;

    //Rotation Operation
    x->right = y;
    y->left = temp;

    //Recalculating Height
    y->height = maximum(height(y->left), height(y->right)) + 1;
    x->height = maximum(height(x->left), height(x->right)) + 1;

    //Returns the Node
    return x;
}
