/*============================================================================
 FILE        : balanceFactor.c
 AUTHORS     : Jesus Lorenzo C. Basuil
 DESCRIPTION : This file containts functions used to get tree height and balance factor
               which will be used by various other functions in the project.
 REVISION HISTORY:
 Date:               By:                                     Description:
      28/03/2024        Jesus Lorenzo C. Basuil                   Starting the project
Date:                By:                                     Description:
      30/03/2024        Jesus Lorenzo C. Basuil                   Finished revision and implementation
============================================================================*/

#include <stdlib.h>
#include "treeStruct.h"

/*
============================================================================
 FUNCTION    : int height (struct node *N)

 DESCRIPTION : a function responsible for getting the current height of the tree
                via an assigned pointer: 'N'.

 ARGUMENTS   :
                - struct node *N: pointer to the node to start calculating the height from.

 RETURNS     :
                - int: the height of the given node
===========================================================================
*/

//CALCULATE HEIGHT
int height(struct node *N) {
  if (N == NULL)
    return 0;
  return N->height;
}

/*
============================================================================
 FUNCTION    : int maximum(int a, int b)

 DESCRIPTION : a function that compares two children nodes (assigned as a and b), and returns
               the minimum value (AKA: The left child node).

 ARGUMENTS   :
                - int a: one child node of a parent node.
                - int b: another child node of a parent node.

 RETURNS     :
                - int: the minimum value between the two nodes
===========================================================================
*/

//GETTING THE MAXIMUM VALUE
int maximum(int a, int b) {
  return (a > b) ? a : b;
}

/*
============================================================================
 FUNCTION    : int getBalance(struct node *child)

 DESCRIPTION : a function that calculates for the balance factor of a given tree
               by subtracting the height of the left and theheight of the right
               trees respectively.

 ARGUMENTS   :
                - struct node *child: pointer towards the nodes whose balance factor is to be calculated.

 RETURNS     :
                - int: the balance factor of the given tree.
===========================================================================
*/


//OBTAINING THE BALANCE FACTOR
int getBalance (struct node *child){
    if (child == NULL){
        return 0;
    }
    return (height(child->left) - height(child->right));
}

