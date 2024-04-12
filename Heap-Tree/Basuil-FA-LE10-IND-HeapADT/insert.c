#include <stdio.h>
#include <stdlib.h>
#include "header.h"


void insertNode(int numArray[], int newNum, int arrSize)
{
  if (arrSize == 0)
  {
    numArray[0] = newNum;
    arrSize += 1;
  }
  else
  {
    numArray[arrSize] = newNum;
    arrSize += 1;
    for (int i = arrSize / 2 - 1; i >= 0; i--)
    {
      heapify(numArray, arrSize, i);
    }
  }
}
