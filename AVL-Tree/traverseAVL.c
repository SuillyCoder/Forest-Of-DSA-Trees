/*============================================================================
 FILE        : traverseAVL.c
 AUTHORS     : Rafiq Reos M. Esler
 DESCRIPTION : The file contains the functions for both Breadth First search traversal and Depth
               First Search traversal (all 3 variants of it).
 REVISION HISTORY:
 Date:               By:                                     Description:
      29/03/2024        Rafiq Reos M. Esler                       Starting the project
============================================================================*/

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "treeStruct.h"

/*
============================================================================
 FUNCTION    : void BFS(struct node* root)

 DESCRIPTION : A function to perform breadth first search traversal

 ARGUMENTS   :
                - struct node *root: pointer to the root node to start searching and displaying from.

 RETURNS     :
                - N/A
===========================================================================
*/

void BFS(struct node* root) {
  if (root == NULL) {
    return;
  }

  // Create a queue for BFS
  struct node* queue[100];  // Adjust size as needed
  int front = 0, rear = -1;

  // Enqueue the root node
  queue[++rear] = root;

  while (front <= rear) {
    // Dequeue a node and print its data
    struct node* current = queue[front++];
    printf("%d ", current->value);

    // Enqueue left and right child (if not NULL)
    if (current->left) {
      queue[++rear] = current->left;
    }
    if (current->right) {
      queue[++rear]  = current->right;
    }
  }
}
/*
============================================================================
 FUNCTION    : void preorder(struct node* node)

 DESCRIPTION : A function to perform depth first search traversal in a pre-order manner.

 ARGUMENTS   :
                - struct node *node: pointer to the root node to start searching and displaying from.

 RETURNS     :
                - N/A
===========================================================================
*/

void preorder(struct node* node) {
    if (node != NULL) {
        printf("%d ", node->value);
        preorder(node->left);
        preorder(node->right);
    }
}

/*
============================================================================
 FUNCTION    : void inorder(struct node* node)

 DESCRIPTION : A function to perform depth first search traversal in a in-order manner.

 ARGUMENTS   :
                - struct node *node: pointer to the root node to start searching and displaying from.

 RETURNS     :
                - N/A
===========================================================================
*/

void inorder(struct node* node) {
    if (node != NULL) {
        preorder(node->left);
        printf("%d ", node->value);
        preorder(node->right);
    }
}
/*
============================================================================
 FUNCTION    : void postorder(struct node* node)

 DESCRIPTION : A function to perform depth first search traversal in a post-order manner.

 ARGUMENTS   :
                - struct node *node: pointer to the root node to start searching and displaying from.

 RETURNS     :
                - N/A
===========================================================================
*/

void postorder(struct node* node) {
    if (node != NULL) {
        preorder(node->left);
        preorder(node->right);
        printf("%d ", node->value);
    }
}



