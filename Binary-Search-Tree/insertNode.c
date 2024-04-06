#include "createNode.c"
#include "functions.h"
#include <stdlib.h>

struct node *insertNode(struct node *entry, int num){
    if (entry == NULL){
        return createNode(num);
    }
    if (num > entry->value){
        entry->right = insertNode(entry->right, num);
    }
    else{
        entry->left = insertNode(entry->left, num);
    }
    return entry;
}

