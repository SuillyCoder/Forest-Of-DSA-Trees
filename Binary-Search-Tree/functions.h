#ifndef FUNCTIONS_H
#define FUNCTIONS_H


struct node{
    int value;
    struct node *left, *right;
};


struct node *createNode(int num);
struct node *insertNode(struct node *node, int num);
struct node *deleteNode(struct node *root, int num, int foundIt);
struct node *minValueNode(struct node *root);


#endif