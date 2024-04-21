#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "header.h"

struct letterNode *createNode (char letter){
    int i;
    struct letterNode *newNode = (struct letterNode*)calloc(1, sizeof(struct letterNode));
    for (i = 0; i < 26; i++){
        newNode->children[i] = NULL;
    }
    newNode->isEnd = 0;
    newNode->letter = letter;

    return newNode;

}

struct letterNode *insertNode (struct letterNode *letterRoot, char *word){
    int i;
    struct letterNode *temp = letterRoot;

    for (i = 0; word[i] != '\0'; i++){
        int index = (int) word[i] - 'a';
        if (temp->children[index] == NULL){
            temp->children[index] = createNode(word[i]);
        }
        else{
            //Do nothing, actually.
        }
        temp = temp->children[index];
    }
    temp->isEnd = 1;
    return letterRoot;
}
