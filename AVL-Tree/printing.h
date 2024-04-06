/*============================================================================
 FILE        : printing.h
 AUTHORS     : Jesus Lorenzo C. Basuil
 DESCRIPTION : This file contains the function responsible for printing the graphical representation
               of the AVL tree.
 REVISION HISTORY:
 Date:               By:                                     Description:
      31/03/2024        Jesus Lorenzo C. Basuil                      Starting the project
============================================================================*/

#ifndef PRINTING_H
#define PRINTING_H

void in_order(struct node* root, int spaces);
void print_tree(struct node* root);

#endif // PRINTING_H
