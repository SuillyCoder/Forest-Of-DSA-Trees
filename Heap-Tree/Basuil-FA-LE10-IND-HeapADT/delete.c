#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void deleteRoot (int numArray[], int arrSize){
    int last = numArray[arrSize-1];
    numArray[0] = last;
    heapify(numArray, arrSize, 0);
}
