#include "binary_trees.h"

/**
* binary_tree_height - function that measures the height of a node\
* in a binary tree
* @tree: the binary tree
* Return: the height of the tree
*/

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t leftSubTree = 0, rightSubTree = 0;

	if (tree == NULL)
		return (0);

	if (tree != NULL)
	{
		if (tree->left != NULL)
			leftSubTree = 1 + binary_tree_height(tree->left);
		else
			leftSubTree = 0;
		if (tree->right != NULL)
			rightSubTree = 1 + binary_tree_height(tree->right);
		else
			rightSubTree = 0;
	}
	if (leftSubTree > rightSubTree)
		return (leftSubTree);
	else
		return (rightSubTree);

}
