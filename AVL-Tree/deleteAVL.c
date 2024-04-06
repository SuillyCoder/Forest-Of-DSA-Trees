/*============================================================================
 FILE        : deleteAVL.c
 AUTHORS     : Dinzil P. Conejos
 DESCRIPTION : This file contains the deletion function of the program along with
               the implementations of deletion process functions.
 REVISION HISTORY:
 Date:               By:                                     Description:
      29/03/2024        Dinzil P. Conejos                                Starting the project
============================================================================*/

#include <stdlib.h>
#include "treeStruct.h"
#include "balanceFactor.h"
#include "rotations.h"

/*
============================================================================
 FUNCTION    : struct node *minValueNode(struct node* entry)

 DESCRIPTION : Given a non-empty binary search tree, return the
               node with the minimum key value found in that tree.
               Note that the entire tree does not need to be searched.

 ARGUMENTS   :
                - struct node* entry: Pointer to the root of the subtree to be
                  searched.

 RETURNS     :
                - struct node*: Pointer to the node with the minimum key value.
===========================================================================
*/


struct node *minValueNode(struct node* entry)
{
	struct node* current = entry;

	/* loop down to find the leftmost leaf */
	while (current->left != NULL)
		current = current->left;
	return current;
}

/*
============================================================================
 FUNCTION    : struct node* deleteNode(struct node* root, int number, int foundIt)

 DESCRIPTION : Recursive function to delete a node with the given key
               from subtree with the given root. It returns root of
               the modified subtree.

 ARGUMENTS   :
                - struct Node* root: Pointer to the root of the subtree
                  from which the node is to be deleted.
                - int number: The key value of the node to be deleted.
                - int foundIt: A flag indicator that checks if the key value
                               exists within the tree and has been found.

 RETURNS     :
                - struct node*: Pointer to the root of the modified subtree
                  after deletion.
===========================================================================
*/


struct node *deleteNode(struct node* root, int number, int foundIt)
{
	// STEP 1: PERFORM STANDARD BST DELETE

	if (root == NULL)
		return root;

	// If the key to be deleted is smaller than the
	// root's key, then it lies in left subtree
	if (number < root->value )
		root->left = deleteNode(root->left, number, foundIt);

	// If the key to be deleted is greater than the
	// root's key, then it lies in right subtree
	else if(number > root->value )
		root->right = deleteNode(root->right, number, foundIt);

	// if key is same as root's key, then This is
	// the node to be deleted
	else
	{
		// node with only one child or no child
		if( (root->left == NULL) || (root->right == NULL) )
		{
			struct node *temp = root->left ? root->left : root->right;

			// No child case
			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else // One child case
			*root = *temp; // Copy the contents of
							// the non-empty child
			free(temp);
			foundIt = 1;
		}
		else
		{
			// node with two children: Get the inorder
			// successor (smallest in the right subtree)
			struct node* temp = minValueNode(root->right);

			// Copy the inorder successor's data to this node
			root->value = temp->value;

			// Delete the inorder successor
			root->right = deleteNode(root->right, temp->value, foundIt);
		}
	}

	// If the tree had only one node then return
	if (root == NULL){
        return root;
	}

	// STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
	root->height = 1 + maximum(height(root->left),height(root->right));

	// STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
	// check whether this node became unbalanced)
	int balance = getBalance(root);

	// If this node becomes unbalanced, then there are 4 cases

	// Left Left Case
	if (balance > 1 && getBalance(root->left) >= 0){
        return rightTurn(root);
	}

	// Left Right Case
	if (balance > 1 && getBalance(root->left) < 0)
	{
		root->left = leftTurn(root->left);
		return rightTurn(root);
	}

	// Right Right Case
	if (balance < -1 && getBalance(root->right) <= 0){
		return leftTurn(root);
    }

	// Right Left Case
	if (balance < -1 && getBalance(root->right) > 0)
	{
		root->right = rightTurn(root->right);
		return leftTurn(root);
	}

	return root;
}


