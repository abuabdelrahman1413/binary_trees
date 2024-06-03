#include "binary_trees.h"

/**
* binary_tree_is_full - function that checks if a binary tree is full
* @tree: the binary tree
* Return: 1 if the tree is full, 0 otherwise.
*/
int binary_tree_is_full(const binary_tree_t *tree)
{
    if (tree == NULL)
		  return (0);
    
    /* if we are leaf then it's full*/
    if (tree->left == NULL && tree->right == NULL)
        return (1);
    /*check every node by looping*/
    if (tree->left != NULL && tree->right != NULL)
        return (binary_tree_is_full(tree->left)
        &&  binary_tree_is_full(tree->right));
    /*else we are not full*/
    return (0);
}