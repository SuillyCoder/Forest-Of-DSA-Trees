/*============================================================================
 FILE        : deleteAVL.h
 AUTHORS     : Dinzil P. Conejos
 DESCRIPTION : This file contains the deletion function of the program along with
               the implementations of deletion process functions.
 REVISION HISTORY:
 Date:               By:                                     Description:
      29/03/2024        Dinzil P. Conejos                                Starting the project
============================================================================*/


#ifndef DELETEAVL_H
#define DELETEAVL_H

struct node *minValueNode(struct node* entry);
struct node *deleteNode(struct node* root, int number, int foundIt);


#endif // DELETEAVL_H
