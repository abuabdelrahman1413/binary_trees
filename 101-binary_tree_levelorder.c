#include "binary_trees.h"
/* https://www.enjoyalgorithms.com/blog/level-order-traversal-of-binary-tree */
/*-----------How this code works:-------------*/
/*
 * 1- First we calculate the height of the tree
 * 2- We then iterate through each level of the tree
 * 3- We then process each node of that level
 * 4- We then go to the next level
 * 5- We repeat this process until we reach the bottom of the tree
 **/

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
	size_t leftSubTree, rightSubTree;

	leftSubTree = binary_tree_height(tree->left);
	rightSubTree = binary_tree_height(tree->right);

	if (leftSubTree > rightSubTree)
		return (leftSubTree + 1);
	else
		return (rightSubTree + 1);
}

/**
* binary_tree_levelorder_recursive - function that goes through a binary tree
* @tree: pointer to the root node of the tree to traverse
* @level: level
* @func: pointer to a function to call for each node
* Return: void
*/


void binary_tree_levelorder_recursive(const binary_tree_t *tree,
				      size_t level, void (*func)(int))
{
	if (tree == NULL)
		return;
	if (level == 0)
		func(tree->n);
	else
	{
		binary_tree_levelorder_recursive(tree->left, level - 1, func);
		binary_tree_levelorder_recursive(tree->right, level - 1, func);
	}
}

/**
* binary_tree_levelorder - function that goes through a binary tree
* @tree: pointer to the root node of the tree to traverse
* @func: pointer to a function to call for each node
* Return: void
*/

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t heightOfTree = binary_tree_height(tree);

	for (size_t level = 0; level < heightOfTree; level++)
	{
		binary_tree_levelorder_recursive(tree, level, func);
	}

}
