#include "binary_trees.h"

/**
 * bst_insert - Inserts a value into a Binary Search Tree (BST).
 * @tree: A pointer to a pointer to the root node of the BST.
 * @value: The value to insert into the BST.
 *
 * Return: A pointer to the newly inserted node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
	return (*tree);
	}
	else
	{
		bst_t *tmp = *tree;
		bst_t *parent = NULL;

	while (tmp != NULL)
	{
		parent = tmp;
		if (value <= tmp->n)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	}

	if (value <= parent->n)
	{
		parent->left = binary_tree_node(parent, value);
		return (parent->left);
	}
	else
	{
		parent->right = binary_tree_node(parent, value);
		return (parent->right);
	}
	}
}
