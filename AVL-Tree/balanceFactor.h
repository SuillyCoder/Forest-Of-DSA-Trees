/*============================================================================
 FILE        : balanceFactor.h
 AUTHORS     : Jesus Lorenzo C. Basuil
 DESCRIPTION : This file containts functions used to get tree height and balance factor
               which will be used by various other functions in the project.
 REVISION HISTORY:
 Date:               By:                                     Description:
      28/03/2024        Jesus Lorenzo C. Basuil                   Starting the project
Date:                By:                                     Description:
      30/03/2024        Jesus Lorenzo C. Basuil                   Finished revision and implementation
============================================================================*/

#ifndef BALANCEFACTOR_H
#define BALANCEFACTOR_H

int height(struct node *child);
int maximum(int a, int b);
int getBalance (struct node *child);

#endif // BALANCEFACTOR_H
