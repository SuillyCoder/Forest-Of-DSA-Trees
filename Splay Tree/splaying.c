#include <stdlib.h>
#include <stdio.h>
#include "treeStruct.h"
#include "zigzags.h"

struct leaf *splay (struct leaf *root, int number){
    if (root == NULL || root->value == number){
        return root;
    }

    if (root->value > number){
        if (root->left == NULL){
            return root;
        }
        if (root->left->value > number){
            (root->left)->left = splay((root->left)->left, number);
            root = rightTurn(root);
        }
        else if (root->left->value < number){
            (root->left)->right = splay((root->left)->right, number);
            if (root->left->right != NULL){
                root->left = leftTurn(root->left);
            }
        }
        return (root->left == NULL) ? root : rightTurn(root);
    }

    //==================================================//

     else{
         if (root->right == NULL){
            return root;
        }
        if (root->right->value > number){
            (root->right)->left = splay((root->right)->left, number);
            if ((root->right)->left != NULL){
                root->right = rightTurn(root->right);
            }
        }
        else if (root->right->value < number){
            (root->right)->right = splay((root->right)->right, number);
            root=leftTurn(root);
        }
        return (root->right == NULL) ? root : leftTurn(root);
    }
}