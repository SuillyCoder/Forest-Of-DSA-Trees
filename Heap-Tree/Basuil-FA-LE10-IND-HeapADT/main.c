#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "header.h"

int main(){
    int choice;

    int arrSize = 0;
    int *numArray = (int*)malloc((arrSize + 1) * sizeof(int));
    int numInput;

    do{
        system("cls");
        printf("=== MIN HEAP MENU ===\n\n");
        printf("[1] Add A Node: \n");
        printf("[2] Delete Root Node: \n");
        printf("[3] Exit\n\n");

        printf("Choice: "); scanf("%d", &choice);

        while (choice != 1 && choice != 2 && choice != 3){
            printf("Enter a valid choice: "); scanf("%d", &choice);
        }

        switch(choice){
            case 1:
                system("cls");
                printf("=== ADD NEW NODE ===\n\n");
                printf("Insert new node to add: "); scanf("%d", &numInput);
                insertNode(numArray, numInput, arrSize); arrSize++;
                numArray = realloc(numArray, arrSize+1 * sizeof(int));

                printf("\n\Final Heap Tree: \n\n");
                searchTreePrint(numArray, arrSize);
                printf("\n\nPress any key to return to MAIN MENU..."); getche();
                break;
            case 2:
                system("cls");
                deleteRoot(numArray, arrSize); arrSize--;
                printf("Heap Tree After Deletion: \n\n");
                searchTreePrint(numArray, arrSize);

                printf("\n\nPress any key to return to MAIN MENU..."); getche();
                break;

        }
    }while(choice != 3);

    system("cls");
    printf("\n\n====MIN HEAP PROGRAM TERMINATED====\n\n");


    return 0;
}
