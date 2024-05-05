#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "header.h"

bool isEmpty(struct letterNode *root){
    int i;
    for (i = 0; i < 26; i++)
        if (root->children[i])
            return false;
    return true;
}

struct letterNode *deleteNode(struct letterNode* root, char *deletor, int depth)
{
    if (!root){
        return NULL;
    }
    if (depth == strlen(deletor)) {

        if (root->endOfWord)
            root->endOfWord = false;

        if (isEmpty(root)) {
            remove (root);
            root = NULL;
        }
        return root;
    }

    int index = deletor[depth] - 'a';
    root->children[index] = deleteNode(root->children[index], deletor, depth + 1);

    if (isEmpty(root) && root->endOfWord == false) {
        remove (root);
        root = NULL;
    }

    return root;
}

int delSearch (struct letterNode *root, char *word){
    int i;
    struct letterNode *temp = root;

    for (i = 0; word[i]!= '\0'; i++){
        int position = word[i]-'a';
        if (temp->children[position] == NULL){
            return 0;
        }
        temp = temp->children[position];
    }
    if (temp!= NULL && temp->isEnd == 1){
        return 1;
    }
    return 0;
}

void delOperator (struct letterNode *root, char *word){
    if (delSearch(root, word) == 0){
        printf("\n\nWord not found within the tree!\n\n");
    }
    else{
        printf("\n\nSuccessfully deleted: %s within the tree!\n\n", word);
        deleteNode(root, word, 0);
    }
}