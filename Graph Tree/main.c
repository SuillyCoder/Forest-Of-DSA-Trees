#include <stdio.h>
#include <stdlib.h>
#include "header.h"

#include "insertion.c"
#include "deletion.c"
#include "displaying.c"
#include "breadthFirst.c"

int main(void) {
    int vertexInput, connector, numStart;
    struct graph *newGraph = createGraph(500);

    int choice, searchChoice, delChoice;
    do{
        printf ("\n\n====== GRAPH TREE PROGRAM =======\n\n");
        printf("[1] Add Edge Connection\n[2] Delete Edge Connection\n[3] Display Graph\n[0] Exit\n\n");
        printf("Your Choice: "); scanf("%d", &choice);

        while (choice != 1 &&  choice != 2 && choice != 3 && choice != 0){
            printf("Invalid Choice. Please try again: "); scanf("%d", &choice);
        }

        switch(choice){
            case 1: 
                printf("Enter a numerical vertex: ");
                scanf("%d", &vertexInput);
                printf("\nEnter another numerical vertex to connect to: ");
                scanf("%d", &connector);
                addEdge(newGraph, vertexInput, connector);
                break;
            case 2: 
                printf("Vertex would you like to delete?: "); 
                scanf("%d", &delChoice);
                deleteVertex(newGraph, delChoice);
                break;
            case 3: 
                printf ("\n\nWhich way do you want to print it?\n\n");
                printf("[1] Programiz Linear Method\n[2] Programiz BFS Method\n\n");
                printf("Your Choice: "); scanf("%d", &searchChoice);

                while (searchChoice != 1 &&  searchChoice != 2){
                    printf("Invalid Choice. Please try again: "); scanf("%d", &searchChoice);
                }

                switch (searchChoice){
                    case 1: 
                        displayGraph(newGraph);
                        break;
                    case 2: 
                        printf("\n\nWhich number do you want to start from?: ");
                        scanf("%d", &numStart);
                        breadth(newGraph, numStart);
                        break;
                }
                break;
        }
    }while(choice != 0);

    printf ("\n\n====== GRAPH TREE PROGRAM =======\n\n");
    printf("    [T E R M I N A T E D ]      ");
    return 0;
}
