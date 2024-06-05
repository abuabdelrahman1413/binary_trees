#include "binary_trees.h"

/**
* binary_tree_height - function that measures the height of a node\
* in a binary tree
* @tree: the binary tree
* Return: the height of the tree
*/

size_t binary_tree_height(const binary_tree_t *tree)
{

	if (!tree)
		return (0);
	/*if the node is the leaf height is 0*/
	if (!tree->left && !tree->right)
		return (0);

	size_t leftSubTree, rightSubTree;

	leftSubTree = binary_tree_height(tree->left);
	rightSubTree = binary_tree_height(tree->right);

	if (leftSubTree >= rightSubTree)
		return (leftSubTree + 1);
	else
		return (rightSubTree + 1);
}
