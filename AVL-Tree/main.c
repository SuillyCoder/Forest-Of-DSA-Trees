/*============================================================================
 FILE        : main.c
 AUTHORS     : Jesus Lorenzo C. Basuil
               Dinzil P. Conejos
               Rafiq Reos M. Esler
               Georelle M. Ila

 DESCRIPTION : This project file simulates an AVL Tree data structure, wherein it allows the
               user to add nodes, delete nodes, traverse through nodes in 4 different ways,
               and search for specific nodes (if they exist).

 REVISION HISTORY:

 Date:               By:                                     Description:
      28/03/2024        Jesus Lorenzo C. Basuil                   Starting the project
 Date:               By:                                     Description:
      29/03/2024        Georelle M. Ila                           Added code for node searching
 Date:               By:                                     Description:
      29/03/2024        Dinzil P. Conejos                         Added code for node deletion
 Date:               By:                                     Description:
      29/03/2024        Rafiq Reos M. Esler                       Added code for node traversal
 Date:               By:                                     Description:
      30/03/2024        Jesus Lorenzo C. Basuil                   Finished revision and implementation
 Date:               By:                                     Description:
      30/03/2024        Jesus Lorenzo C. Basuil                   Finalized comments and overall state of project operation
Date:               By:                                     Description:
      31/03/2024        Jesus Lorenzo C. Basuil                   Implemented tree printing function and finalized project

============================================================================*/

//STANDARD LIBRARY INCLUSIONS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// HEADER FILE INCLUSONS

#include "treeStruct.h"
#include "balanceFactor.h"
#include "rotations.h"
#include "addAVL.h"
#include "deleteAVL.h"
#include "searchAVL.h"
#include "traverseAVL.h"
#include "printing.h"

int foundIt = 0;

int main()
{
    struct node *root = NULL;
    int choice, addNumber, travChoice, deletor, searchNum;
    char addAgain, exitor;
    do{
        system("cls");
        printf("DSA AVL Tree Program\n\n");
        printf("[1]Add Nodes\n[2]Delete Nodes\n[3]Traverse Nodes\n[4]Search Nodes\n[0]Exit");
        printf("\n\nYour choice: ");scanf("%d", &choice);

        while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 0){
             printf("\nEnter a valid choice: ");scanf("%d", &choice);
        }

        switch(choice){
            case 1:
                do{
                    system("cls");
                    printf("Enter a number: "); scanf("%d", &addNumber);
                    root = insertAVL(root, addNumber);
                    printf("\nSuccessfully added %d to the tree!\n\n", addNumber);
                    printf("Current Tree (NOTE: %d is the root) \n\n", root->value);
                    print_tree(root);

                    printf("\n\nAgain? [Y/N]: "); scanf(" %c", &addAgain);
                    while (toupper(addAgain) != 'Y' && toupper(addAgain) != 'N'){
                        printf("\nEnter a valid choice: ");scanf(" %c", &addAgain);
                    }
                }while(toupper(addAgain) == 'Y');
                break;
            case 2:
                system("cls");
                if (root == NULL){
                    printf("No nodes within tree to delete!");
                }
                else{
                    printf ("\nEnter a number to delete: "); scanf("%d", &deletor);
                    root = deleteNode(root, deletor, foundIt);
                    if (foundIt != 0){
                        printf("\n\nNumber Not Found Within Tree!\n");
                    }
                    else{
                        printf("\n\nDeletion of %d Successful!\n\n", deletor);
                        printf("Current Tree (NOTE: %d is the root) \n\n", root->value);
                        print_tree(root);
                    }
                }
                printf("\n\nPress any key to continue: "); scanf(" %c", &exitor);

                break;
            case 3:
                system("cls");
                if (root == NULL){
                    printf("No roots within the tree to traverse!");
                }
                else{
                    printf("How would you like to traverse and present the nodes?\n\n");
                    printf("[1]Breadth First Search\n");
                    printf("[2]Depth First Search (Pre-Order)\n");
                    printf("[3]Depth First Search (In-Order)\n");
                    printf("[4]Depth First Search (Post-Order)\n");
                    printf("[0]Cancel\n\n");
                    printf("Your choice: "); scanf("%d", &travChoice);

                    switch(travChoice){
                        case 1:
                            printf("\nCurrent Tree (NOTE: %d is the root) \n\n", root->value);
                            print_tree(root);
                            printf("\n\nNodes via Breadth First Search: ");
                            BFS(root);
                            break;
                        case 2:
                            printf("\nCurrent Tree (NOTE: %d is the root) \n\n", root->value);
                            print_tree(root);
                            printf("\n\nNodes in Pre-Order Fashion: ");
                            preorder(root);
                            break;
                        case 3:
                            printf("\nCurrent Tree (NOTE: %d is the root) \n\n", root->value);
                            print_tree(root);
                            printf("\n\nNodes in In-Order Fashion: ");
                            inorder(root);
                            break;
                        case 4:
                            printf("\nCurrent Tree (NOTE: %d is the root) \n\n", root->value);
                            print_tree(root);
                            printf("\n\nNodes in Post-Order Fashion: ");
                            postorder(root);
                            break;
                    }
                }

                printf("\n\nPress any key to continue: "); scanf(" %c", &exitor);
                break;
            case 4:
                system("cls");
                if (root == NULL){
                    printf("No nodes to search for!");
                }
                else{
                    printf("Enter node number to search for within tree: "); scanf("%d", &searchNum);
                    searchNode(root, searchNum);
                }
                printf("\n\nPress any key to continue: "); scanf(" %c", &exitor);
                break;
        }
    }while(choice != 0);

    system("cls");
    printf("\n\n======= AVL Tree Program Terminated! =======\n\n");
    return 0;
}
