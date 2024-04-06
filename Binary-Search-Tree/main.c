#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "searchers.h"
#include "insertNode.c"
#include "deleteNode.c"
#include "breadthFirst.c"

int foundIt = 0;

int main(){
    int choice, addTimes, numValue, searchChoice, deletor;
    struct node *root = NULL;
    printf("\nTime to go 'Tree Planting'\n");
    do{
        
    printf("\n[1]Add Nodes\n[2]Delete Nodes\n[3]Traverse Nodes\n[0]Exit");
    printf("\nYour choice: ");scanf("%d", &choice);

    switch(choice){
        case 1: 
            int i;
            printf("How many times would you like to add nodes?: "); scanf("%d", &addTimes);
            for (i = 0; i < addTimes; i++){
                printf("Enter a number: "); scanf("%d", &numValue);
                root = insertNode(root, numValue);
            }
            break;
        case 2: 
            printf ("\nEnter a number to delete: "); scanf("%d", &deletor);
            deleteNode(root, deletor, foundIt);
            if (foundIt != 0){
                printf("\n\nNumber Not Found Within Tree!\n");
            }
            else{
                printf("\n\nDeletion Successful!\n");
            }
            break;

        case 3: 
           do{
            printf("\nWhat type of search would you like to perform?"); 
            printf("\n\n[1]BREADTH FIRST\n[2]DEPTH FIRST: PREFIX\n[3]DEPTH FIRST: INFIX\n[4]DEPTH FIRST: POSTFIX\n[0]CANCEL\n\n");
            printf("Choice: "); scanf("%d", &searchChoice);
            switch (searchChoice){
                case 1: 
                    printf("Bradth First Search: ");
                    BFS(root);
                    printf("\n\n");
                    break;
                case 2: 
                    printf("Prefix Search: "); 
                    preOrder(root);
                    printf("\n\n");
                    break;
                case 3: 
                    printf("Infix Search: "); 
                    inOrder(root);
                    printf("\n\n");
                    break;
                case 4: 
                    printf("Prefix Search: "); 
                    postOrder(root);
                    printf("\n\n");
                    break;
                }
           }while(searchChoice!= 0);
            break;
        }
    }while(choice != 0);

    printf("\n\nISTG I need to master trees in C");

    return 0;
}