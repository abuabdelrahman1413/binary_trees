#include "binary_trees.h"

/**
* binary_tree_size - function that measures the size of a node in a binary tree
* @tree: the binary tree
* Return: the size of the tree
*/

size_t binary_tree_size(const binary_tree_t *tree)
{

	if (!tree)
		return  (0);
	size_t leftSub = binary_tree_size(tree->left);
	size_t rightSub = binary_tree_size(tree->right);

	return (1 + leftSub + rightSub);
}
