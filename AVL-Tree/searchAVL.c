/*============================================================================
 FILE        : searchAVL.c
 AUTHORS     : Georelle M. Ila
 DESCRIPTION : This file contains the function for the user to search for
               a specific node within the tree and see if it exists or not.
 REVISION HISTORY:
 Date:               By:                                     Description:
      29/03/2024        Georelle M. Ila                          Starting the project
============================================================================*/

#include <stdlib.h>
#include <stdio.h>
#include "treeStruct.h"
#include "printing.h"


/*
============================================================================
 FUNCTION    : struct node* searchNode(struct node* root, int key)

 DESCRIPTION : a function responsible for searching through the given AVL tree and
               verifying if a specific node exists or not.

 ARGUMENTS   :
                - struct node *root: pointer to the node to start searching from.
                - int key: the number to be find (entered by the user)

 RETURNS     :
                - struct *node: pointer towards a given node that contains the value
===========================================================================
*/

struct node* searchNode(struct node* root, int key)
{
    // Case if the root is empty
    if (root == NULL)
    {
        return NULL;
    }

    //Case if the value of the root matches the user's entered number to delete
    if(root->value == key)
    {
        printf("\nCurrent Tree (NOTE: %d is the root) \n\n", root->value);
        print_tree(root);
        printf("\n\nNode Value: %d exists within the tree!", root->value);
        return root;
    }

    //Searching process to find the exact number.
    if(key > root->value)
    {
        searchNode(root->right, key);
    }
    else
    {
        searchNode(root->left, key);
    }
}


