/*============================================================================
 FILE        : addAVL.h
 AUTHORS     : Jesus Lorenzo C. Basuil
 DESCRIPTION : This file contains the functions responsible for node creation and
               node insertion within the AVL tree.
 REVISION HISTORY:
 Date:               By:                                     Description:
      28/03/2024        Jesus Lorenzo C. Basuil                   Starting the project
Date:                By:                                     Description:
      30/03/2024        Jesus Lorenzo C. Basuil                   Finished revision and implementation
============================================================================*/

#ifndef ADDAVL_H
#define ADDAVL_H

struct node *addAVL(int number);
struct node *insertAVL(struct node *entry, int number);

#endif // ADDAVL_H

