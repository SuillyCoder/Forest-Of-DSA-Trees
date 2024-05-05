#include <stdio.h> 
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "header.h"
#include "insertion.c"
#include "freeing.c"
#include "printing.c"
#include "searching.c"
#include "deletion.c"

int main(){
    struct letterNode *root = createNode('\0');
    int choice, i;
    char strInput[100], strSearch[100], lowercase[100], strDelete[100];
    char again;

    do{
        printf("\n\n========= LEXICAL TREE PROGRAM =========\n\n");
        printf("[1] Add String\n[2] Delete String\n[3] Search String\n[0] Exit\n\n");
        printf("Your choice: "); scanf("%d", &choice);

        while (choice != 1 && choice != 2 && choice != 3 && choice != 0){
            printf("Please enter a valid choice: "); scanf("%d", &choice);
        }

        switch(choice){
            case 1: 
                do{
                    fflush(stdin);
                    printf("\n\nEnter a word you would like to insert: ");
                    fgets(strInput, 100, stdin);
                    strInput[strcspn(strInput, "\n")] = '\0';
                    for (i = 0; i < strlen(strInput); i++){
                        lowercase[i] = tolower(strInput[i]);
                        lowercase[i+1] = '\0';
                    }
                    printf("\nSuccessfully inserted: %s into the tree!", lowercase);
                    root = insertNode(root, lowercase);
                    printf("\n\nAgain?: [Y/N]: "); scanf(" %c", &again);

                    while (toupper(again)!= 'Y' && toupper(again)!= 'N'){
                        printf("Enter a valid choice: "); scanf(" %c", &again);
                    }

                }while(toupper(again) != 'N');
                break;
            case 2:
                if (root == NULL){
                    printf("No Nodes to Delete!\n\n");
                }
                else{
                    do{
                        fflush(stdin);
                        printf("Insert word to delete: ");
                        fgets(strDelete, 100, stdin);
                        strDelete[strcspn(strDelete, "\n")] = '\0';
                        delOperator(root, strDelete);
                        printTrie(root);
                        printf("\n\nAgain?: [Y/N]: "); scanf(" %c", &again);

                    while (toupper(again)!= 'Y' && toupper(again)!= 'N'){
                        printf("Enter a valid choice: "); scanf(" %c", &again);
                }
                    }while(toupper(again) != 'N');
                }
                break;
            case 3:
                fflush(stdin);
                printf("What would you like to search for?");
                printf("\nEnter search prompt: ");
                fgets(strSearch, 100, stdin);
                strSearch[strcspn(strSearch, "\n")] = '\0';
                printSearch(root, strSearch);
                printTrie(root);
                break;
        }
    }while(choice != 0);

     printf("\n\n========= LEXICAL TREE PROGRAM =========\n\n");
     printf("           [ T E R M I N A T E D ]         \n\n");
     //freeNode(root);

    return 0;
}
