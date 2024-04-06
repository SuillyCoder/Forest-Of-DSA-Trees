/*============================================================================
 FILE        : traverseAVL.h
 AUTHORS     : Rafiq Reos M. Esler
 DESCRIPTION : The file contains the functions for both Breadth First search traversal and Depth
               First Search traversal (all 3 variants of it).
 REVISION HISTORY:
 Date:               By:                                     Description:
      29/03/2024        Rafiq Reos M. Esler                       Starting the project
============================================================================*/

#ifndef TRAVERSEAVL_H
#define TRAVERSEAVL_H

void BFS(struct node *root);
void preorder(struct node *root);
void inorder(struct node *root);
void postorder(struct node *root);

#endif // TRAVERSEAVL_H
