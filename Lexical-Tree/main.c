#include <stdio.h> 
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "header.h"
#include "insertion.c"
#include "freeing.c"
#include "printing.c"
#include "searching.c"

int main(){
    struct letterNode *root = createNode('\0');
    int choice;
    char strInput[100], strSearch[100];
    char again;

    do{
        printf("========= LEXICAL TREE PROGRAM =========\n\n");
        printf("[1] Add String\n[2] Search String\n[0] Exit\n\n");
        printf("Your choice: "); scanf("%d", &choice);

        while (choice != 1 && choice != 2 && choice != 0){
            printf("Please enter a valid choice: "); scanf("%d", &choice);
        }

        switch(choice){
            case 1: 
                do{
                    fflush(stdin);
                    printf("\n\nEnter a word you would like to insert: ");
                    fgets(strInput, 100, stdin);
                    strInput[strcspn(strInput, "\n")] = '\0';
                    printf("\nSuccessfully inserted: %s into the tree!", strInput);
                    root = insertNode(root, strInput);
                    printf("\n\nAgain?: [Y/N]: "); scanf(" %c", &again);

                    while (toupper(again)!= 'Y' && toupper(again)!= 'N'){
                        printf("Enter a valid choice: "); scanf(" %c", &again);
                    }

                }while(toupper(again) != 'N');
                break;
            case 2:
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
