/*============================================================================
 FILE        : treeStruct.h
 AUTHORS     : Jesus Lorenzo C. Basuil
 DESCRIPTION : This file contains the main tree structure. Note that each and every function
               will be using this for them to operate properly.
 REVISION HISTORY:
 Date:               By:                                     Description:
      28/03/2024        Jesus Lorenzo C. Basuil                   Starting the project
============================================================================*/


#ifndef TREESTRUCT_H
#define TREESTRUCT_H

struct node{
    int value, height;
    struct node *left, *right;
};

#endif // TREESTRUCT_H
