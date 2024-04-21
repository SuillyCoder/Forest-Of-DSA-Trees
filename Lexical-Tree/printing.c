#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "header.h"

void printTrie (struct letterNode *root){
    int i;
    if (!root){
        return;
    }
    struct letterNode *temp = root;
    printf("%c ->", temp->letter);
    for (i = 0; i < 26; i++){
        printTrie(temp->children[i]);
    }
}

void printSearch (struct letterNode *root, char *word){
    printf("\nSearching for: %s", word);
    if (searchNodes(root, word) == 0){
        printf("\n\nWord not found within the tree!\n\n");
    }
    else{
        printf("\n\nFound string: %s within the tree!\n\n", word);
    }
}
