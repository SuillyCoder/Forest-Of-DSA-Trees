#include "functions.h"
#include <stdlib.h>

struct node *createNode(int num){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->value = num;
    newNode->left = NULL; newNode-> right = NULL;

    return newNode;
}
