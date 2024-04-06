/*============================================================================
 FILE        : rotations.h
 AUTHORS     : Jesus Lorenzo C. Basuil
 DESCRIPTION : This file contains rotations functions (both single and double rotations)
               responsible for balancing out the AVL tree.
 REVISION HISTORY:
 Date:               By:                                     Description:
      28/03/2024        Jesus Lorenzo C. Basuil                   Starting the project
 Date:               By:                                     Description:
      30/03/2024        Jesus Lorenzo C. Basuil                   Finished revision and implementation
============================================================================*/

#ifndef ROTATIONS_H
#define ROTATIONS_H

struct node *leftTurn (struct node *x);
struct node *rightTurn (struct node *y);

#endif // ROTATIONS_H
