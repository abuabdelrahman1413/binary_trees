#include "binary_trees.h"

/**
* binary_tree_height - function that measures the height of a node in a binary tree
* @tree: the binary tree
* Return: the height of the tree
*/

size_t binary_tree_height(const binary_tree_t *tree)
{
    if (tree == NULL)
		return 0;

    int lefth, righth;
    /*divide*/
    lefth = binary_tree_height(tree->left);
    righth = binary_tree_height(tree->right);
    if (lefth > righth)
    {
        /*add it to previous call*/
        return lefth + 1;
    }
    else
        return righth + 1;

}