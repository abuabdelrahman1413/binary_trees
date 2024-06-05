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
	binary_tree_t *uncle;

	root = binary_tree_node(NULL, 98);
	if (root == NULL)
		return (1);

	root->left = binary_tree_node(root, 12);
	if (root->left == NULL)
	{
		free(root);
		return (1);
	}

	root->right = binary_tree_node(root, 128);
	if (root->right == NULL)
	{
		free(root->left);
		free(root);
		return (1);
	}

	root->left->right = binary_tree_node(root->left, 54);
	if (root->left->right == NULL)
	{
		free(root->left);
		free(root->right);
		free(root);
		return (1);
	}

	root->right->right = binary_tree_node(root->right, 402);
	if (root->right->right == NULL)
	{
		free(root->left->right);
		free(root->left);
		free(root->right);
		free(root);
		return (1);
	}

	root->left->left = binary_tree_node(root->left, 10);
	if (root->left->left == NULL)
	{
		free(root->left->right);
		free(root->left);
		free(root->right->right);
		free(root->right);
		free(root);
		return (1);
	}

	root->right->left = binary_tree_node(root->right, 110);
	if (root->right->left == NULL)
	{
		free(root->left->left);
		free(root->left->right);
		free(root->left);
		free(root->right->right);
		free(root->right);
		free(root);
		return (1);
	}

	root->right->right->left = binary_tree_node(root->right->right, 200);
	if (root->right->right->left == NULL)
	{
		free(root->left->left);
		free(root->left->right);
		free(root->left);
		free(root->right->left);
		free(root->right->right);
		free(root->right);
		free(root);
		return (1);
	}

	root->right->right->right = binary_tree_node(root->right->right, 512);
	if (root->right->right->right == NULL)
	{
		free(root->left->left);
		free(root->left->right);
		free(root->left);
		free(root->right->left);
		free(root->right->right->left);
		free(root->right->right);
		free(root->right);
		free(root);
		return (1);
	}

	binary_tree_print(root);

	uncle = binary_tree_uncle(root->right->left);
	printf("Uncle of %d: %d\n", root->right->left->n, uncle ? uncle->n : -1);
	uncle = binary_tree_uncle(root->left->right);
	printf("Uncle of %d: %d\n", root->left->right->n, uncle ? uncle->n : -1);
	uncle = binary_tree_uncle(root->left);
	printf("Uncle of %d: %p\n", root->left->n, (void *)uncle);

	/* Clean up */
	free(root->left->left);
	free(root->left->right);
	free(root->right->left);
	free(root->right->right->left);
	free(root->right->right->right);
	free(root->left);
	free(root->right);
	free(root);

	return (0);
}
