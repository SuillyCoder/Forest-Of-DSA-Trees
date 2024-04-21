#ifndef HEADER_H
#define HEADER_H

struct letterNode{
    char letter;
    int isEnd;
    struct letterNode *children[26];
};

struct letterNode *createNode (char letter);
struct letterNode *insertNode (struct letterNode *letterRoot, char *word);

void freeNode (struct letterNode *node);

int searchNodes (struct letterNode *root, char *word);

void printTrie (struct letterNode *root);
void printSearch (struct letterNode *root, char *word);


#endif
