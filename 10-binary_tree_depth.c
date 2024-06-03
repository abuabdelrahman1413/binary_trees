#include "binary_trees.h"

/**
* binary_tree_depth - function that measures the depth of a node in\
* a binary tree
* @tree: the binary tree
* Return: the depth of the tree
*/

size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->parent == NULL)
		return (0);
	return (1 + binary_tree_depth(tree->parent));
}
