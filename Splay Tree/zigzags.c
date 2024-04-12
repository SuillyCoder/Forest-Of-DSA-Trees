#include <stdlib.h>
#include "treeStruct.h"

struct leaf *leftTurn(struct leaf *x){
    struct leaf *y = x->right;
    x->right = y->left;
    y->left = x;
    
    return y;

}
struct leaf *rightTurn(struct leaf *x){
    struct leaf *y = x->left;
    x->left = y->right;
    y->right = x;
    
    return y;
}