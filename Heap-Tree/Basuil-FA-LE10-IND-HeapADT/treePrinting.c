#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

void searchTreePrint(int numArray[], int arrSize){
    int cutOff = 0;
    int princrement = 0;
    while(cutOff < arrSize){
        int leafPrinter = 0;
        int levelPrint = pow(2, princrement);


        //CODE TO DO THE LEVEL PRINTING

        while(leafPrinter < levelPrint && cutOff < arrSize){


            printf(" %d ", numArray[cutOff]);

            cutOff++;
            leafPrinter++;
            princrement++;
        }

        printf("\n");
    }
}
