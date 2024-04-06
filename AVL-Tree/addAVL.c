/*============================================================================
 FILE        : addAVL.c
 AUTHORS     : Jesus Lorenzo C. Basuil
 DESCRIPTION : This file contains the functions responsible for node creation and
               node insertion within the AVL tree.
 REVISION HISTORY:
 Date:               By:                                     Description:
      28/03/2024        Jesus Lorenzo C. Basuil                   Starting the project
Date:                By:                                     Description:
      30/03/2024        Jesus Lorenzo C. Basuil                   Finished revision and implementation
============================================================================*/

#include <stdlib.h>
#include "treeStruct.h"
#include "balanceFactor.h"
#include "rotations.h"

/*
============================================================================
 FUNCTION    : struct node *addAVL(int number)

 DESCRIPTION : A function responsible for creating a new node basing its template
               from the default tree structure..

 ARGUMENTS   :
                - int number: the number the user enters to be inserted in a node
 RETURNS     :
                - struct node*: the newly created node.
===========================================================================
*/

struct node *addAVL(int number){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->value = number;
    newNode->left = NULL; newNode->right = NULL;
    newNode->height = 1;
    return (newNode);
};

/*
============================================================================
 FUNCTION    : struct node *insertAVL(struct node *entry, int number)

 DESCRIPTION : A function responsible for inserting the newly created node within the tree structure.

 ARGUMENTS   :
                - int number: the number the user enters to be inserted in a node.
                - struct node *entry: a pointer towards the root node to be inserted within the tree.
 RETURNS     :
                - struct node*: the newly created node.
===========================================================================
*/

struct node *insertAVL(struct node *entry, int number){
    //Insertion Process
    if (entry == NULL){
        return (addAVL(number));
    }

    if (number > entry->value){
        entry->right = insertAVL(entry->right, number);
    }
    else if (number < entry->value){
        entry->left = insertAVL(entry->left, number);
    }
    else{
         return entry;
    }

    //Updating of the Height and Balance Factor

    entry->height = 1 + maximum(height(entry->left), height(entry->right));

    int balance = getBalance(entry);

        //Returning Right-Rotated Entries

    if (balance > 1 && number < (entry->left)->value){
        return rightTurn(entry);
    }
    if (balance > 1 && number > (entry->left)->value){
        entry->left = leftTurn(entry->left);
        return rightTurn(entry);
    }

       //Returning Left-Rotated Entries

    if (balance < -1 && number > (entry->right)->value){
        return leftTurn(entry);
    }
    if (balance < -1 && number < (entry->right)->value){
        entry->right = rightTurn(entry->right);
        return leftTurn(entry);
    }

    return entry;
};
