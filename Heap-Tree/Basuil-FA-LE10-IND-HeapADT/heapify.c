#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "header.h"

void heapify(int numArray[], int arrSize, int i) {
   printf("\n\nCurrent Heap Tree: \n\n");
   searchTreePrint(numArray, arrSize);
    printf("\n\nPress SPACEBAR to continue \n\n");

   getche();

  int smallest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < arrSize && numArray[l] < numArray[smallest])
    smallest = l;

  if (r < arrSize && numArray[r] < numArray[smallest])
    smallest = r;

  if (smallest != i) {
    swapNodes(&numArray[i], &numArray[smallest]);
    heapify(numArray, arrSize, smallest);
  }

}
