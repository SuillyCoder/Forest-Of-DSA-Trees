#include <stdlib.h>
#include "header.h"

void swapNodes(int *a, int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}
