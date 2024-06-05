#include "binary_trees.h"


/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: the node
 * Return: 1 if node is a leaf, 0 otherwise
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);
	if (node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}

/**
* binary_tree_leaves - counts the leaves in a binary tree
* @tree: the tree
* Return: the number of leaves
*/

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (binary_tree_is_leaf(tree))
		return (1);
	size_t leftSubTree = binary_tree_leaves(tree->left);
	size_t rightSubTree = binary_tree_leaves(tree->right);

	return (leftSubTree + rightSubTree);

}
