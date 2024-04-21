#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void freeNode (struct letterNode *node){
    int i;
    for (i = 0; i < 26; i++){
        if (node->children[i] == NULL){
            freeNode(node->children[i]);
        }
        else{
            continue;
        }
    }
    free(node);
}
