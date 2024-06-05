#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	binary_tree_t *root;
	int perfect;

	root = binary_tree_node(NULL, 98);
	if (root == NULL)
		return (1);

	root->left = binary_tree_node(root, 12);
	if (root->left == NULL)
	{
		free(root);
		return (1);
	}

	root->right = binary_tree_node(root, 402);
	if (root->right == NULL)
	{
		free(root->left);
		free(root);
		return (1);
	}

	binary_tree_insert_right(root->left, 54);
	binary_tree_insert_right(root, 128);
	root->left->left = binary_tree_node(root->left, 10);
	if (root->left->left == NULL)
	{
		free(root->left);
		free(root->right);
		free(root);
		return (1);
	}

	binary_tree_print(root);
	perfect = binary_tree_is_perfect(root);
	printf("Perfect: %d\n\n", perfect);

	root->right->right->left = binary_tree_node(root->right->right, 10);
	binary_tree_print(root);
	perfect = binary_tree_is_perfect(root);
	printf("Perfect: %d\n\n", perfect);

	root->right->right->right = binary_tree_node(root->right->right, 10);
	binary_tree_print(root);
	perfect = binary_tree_is_perfect(root);
	printf("Perfect: %d\n", perfect);

	return (0);
}
