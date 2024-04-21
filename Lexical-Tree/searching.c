#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "header.h"

int searchNodes (struct letterNode *root, char *word){
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
