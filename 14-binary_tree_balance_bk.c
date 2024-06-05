#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a node in a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t leftSubTree, rightSubTree;

	if (tree == NULL)
		return (0);

	leftSubTree = binary_tree_height(tree->left);
	rightSubTree = binary_tree_height(tree->right);

	if (leftSubTree > rightSubTree)
		return (leftSubTree + 1);
	else
		return (rightSubTree + 1);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: balance factor, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		NULL;

	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}
