#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//HEADER FILE DECLARATIONS

#include "operations.h"
#include "treeStruct.h"
#include "printTree.h"
#include "splaying.h"
#include "traversals.h"
#include "searcher.h"
#include "zigzags.h"

int foundIt = 0;

struct leaf *root = NULL;

int main(){
   char choice, getOut, keepGoing;
   int searchChoice, numInput, deletor;

   do{
    printf("*******===Splay Tree Practice Module===*******\n\n");
    printf("[A] Add Leaf Nodes\n");
    printf("[B] Delete Leaf Nodes\n");
    printf("[C] Traverse Leaf Nodes\n");
    printf("[D] Search Leaf Nodes\n");
    printf("[X] Exit\n\n");

    printf("Your Choice: "); scanf("%c", &choice);

    while (toupper(choice) != 'A' && toupper(choice) != 'B' && toupper(choice) != 'C' && toupper(choice) != 'D' && toupper(choice) != 'X'){
        printf("Enter a valid choice: "); scanf(" %c", &choice);
    }
    switch(toupper(choice)){
        case 'A': 
    //============================ CASE CODE TO DELETE NODES ===============================//
            do{
                printf("Enter a number for a node: "); scanf("%d", &numInput);
                root = insertLeaf(root, numInput);
                printf("Current Tree (Note: %d is the root): \n\n", root->value);
                printTree(root);
                printf("\n\nAgain? [Y/N]: "); scanf(" %c", &keepGoing);
                while (toupper(keepGoing) != 'Y' && toupper(keepGoing) != 'N'){
                    printf("Enter a valid choice: "); scanf(" %c", &keepGoing);
                }
            printf("\n\n");
            }while(toupper(keepGoing) != 'N');
            break;

    //============================ CASE CODE TO DELETE NODES ===============================//
        case 'B': 
            if (root == NULL){
                printf("No Nodes to Delete!\n");
                printf("Press Any Key to Continue: "); scanf(" %c", &getOut);
                printf("\n\n");
            }
            else{
                do{
                    printf("Enter a node to delete: "); scanf("%d", &deletor);
                    deleteLeaf(root, deletor, foundIt);
                    if (foundIt != 1){
                        printf("Successfully deleted %d from the tree!\n\n", deletor);
                        printf("Current Tree (Note: %d is the root): \n\n", root->value);
                        printTree(root);
                    }
                    else{
                        printf("Node not found within the tree!\n\nCurrent Tree:\n\n");
                        printTree(root);
                    }
                 printf("\n\nAgain? [Y/N]: "); scanf(" %c", &keepGoing);
                 while (toupper(keepGoing) != 'Y' && toupper(keepGoing) != 'N'){
                    printf("Enter a valid choice: "); scanf(" %c", &keepGoing);
                 } 
                }while(toupper(keepGoing) == 'Y');
            }
            break;
     //============================ CASE CODE TO DELETE NODES ===============================//

        case 'C':
           if (root == NULL){
                printf("No Nodes to Traverse!\n");
                printf("Press Any Key to Continue: "); scanf(" %c", &getOut);
                printf("\n\n");
            }
            else{
                do{

                printf("\nWhich search mode would you like to opt for?\n\n");
                printf("[1] Breadth First Search Traversal: \n");
                printf("[2] Depth First Search (Pre Order) Traversal: \n");
                printf("[3] Depth First Search (In Order) Traversal: \n");
                printf("[4] Depth First Search (Post Order) Traversal: \n");
                printf("[0] Exit");
                printf("\nYour choice: "); scanf("%d", &searchChoice);

                while(searchChoice != 1 && searchChoice != 2 && searchChoice != 3 && 
                searchChoice != 4 && searchChoice != 0){
                    printf("Enter a valid choice: "); scanf(" %d", &searchChoice);
                }

                switch(searchChoice){
                    case 1: 
                        printf("Current Tree (Note: %d is the root): \n\n", root->value);
                        printTree(root);
                        printf("\nBreadth First Search Tree Results: \n");
                        breadth(root);

                        printf("Press Any Key to Continue: "); scanf(" %c", &getOut);
                        break;
                    case 2: 
                        printf("Current Tree (Note: %d is the root): \n\n", root->value);
                        printTree(root);
                        printf("\nDepth First Search (Pre Order) Tree Results: \n\n");
                        preOrder(root);

                        printf("\n\nPress Any Key to Continue: "); scanf(" %c", &getOut);
                        break;
                    case 3: 
                        printf("Current Tree (Note: %d is the root): \n\n", root->value);
                        printTree(root);
                        printf("\nDepth First Search (In Order) Tree Results: \n\n");
                        inOrder(root);

                        printf("\n\nPress Any Key to Continue: "); scanf(" %c", &getOut);
                        break;
                    case 4: 
                        printf("Current Tree (Note: %d is the root): \n\n", root->value);
                        printTree(root);
                        printf("\nDepth First Search (Post Order) Tree Results: \n\n");
                        postOrder(root);

                        printf("\n\nPress Any Key to Continue: "); scanf(" %c", &getOut);
                        break;
                    }
                }while(searchChoice != 0);
            }
            break;

    //============================ CASE CODE TO SEARCH NODES ===============================//
        case 'D':
            if (root == NULL){
                printf("\nNo Nodes to Search For!\n\n");
            }
            else{
                int searchNum;
                printf("Enter a number to search for: "); scanf("%d", &searchNum);
                printf("\nCurrent Tree (NOTE: %d is the root) \n\n", root->value);
                printTree(root);
                searchLeaf(root, searchNum, foundIt);
                if (foundIt == 1){
                    printf("\n\nNode Value: %d exists within the tree!", root->value);
                }
                else{
                    printf("Node was not found within the tree");
                }
            }
            printf("Press Any Key to Continue: "); scanf(" %c", &getOut);
            break;
    }
   }while(toupper(choice) != 'X');

      printf("\n\n*******===Splay Tree Practice Module===*******\n\n");
      printf("          [  T E R M I N A T E D  ]      \n\n");
    return 0;
    
}