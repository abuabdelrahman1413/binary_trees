#include "binary_trees.h"

/**
* binary_tree_size - function that measures the size of a node in a binary tree
* @tree: the binary tree
* Return: the size of the tree
*/

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t leftSub = 0, rightSub = 0;

	if (!tree)
		return  (0);
	leftSub = binary_tree_size(tree->left);
	rightSub = binary_tree_size(tree->right);

	return (1 + leftSub + rightSub);
}
