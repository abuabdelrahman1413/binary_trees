#include <stdlib.h>
#include <stdio.h>
#include "../binary_trees.h"

/* Function prototypes for helper functions */
int create_node(binary_tree_t **node, binary_tree_t *parent, int value);
void free_tree(binary_tree_t *root);
int setup_tree(binary_tree_t **root);

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	binary_tree_t *root = NULL;
	binary_tree_t *uncle;

	if (setup_tree(&root) == 1)
		return (1);

	binary_tree_print(root);

	uncle = binary_tree_uncle(root->right->left);
	printf("Uncle of %d: %d\n", root->right->left->n, uncle ? uncle->n : -1);
	uncle = binary_tree_uncle(root->left->right);
	printf("Uncle of %d: %d\n", root->left->right->n, uncle ? uncle->n : -1);
	uncle = binary_tree_uncle(root->left);
	printf("Uncle of %d: %p\n", root->left->n, (void *)uncle);

	/* Clean up */
	free_tree(root);

	return (0);
}

/**
 * create_node - Creates a new node in the binary tree
 * @node: Double pointer to the node to create
 * @parent: Pointer to the parent node
 * @value: Value to assign to the new node
 *
 * Return: 0 on success, 1 on failure
 */
int create_node(binary_tree_t **node, binary_tree_t *parent, int value)
{
	*node = binary_tree_node(parent, value);
	if (*node == NULL)
	{
		if (parent != NULL)
			free(parent);
		return (1);
	}
	return (0);
}

/**
 * setup_tree - Sets up the binary tree
 * @root: Double pointer to the root of the tree
 *
 * Return: 0 on success, 1 on failure
 */
int setup_tree(binary_tree_t **root)
{
	if (create_node(root, NULL, 98) ||
		create_node(&(*root)->left, *root, 12) ||
		create_node(&(*root)->right, *root, 128) ||
		create_node(&(*root)->left->right, (*root)->left, 54) ||
		create_node(&(*root)->right->right, (*root)->right, 402) ||
		create_node(&(*root)->left->left, (*root)->left, 10) ||
		create_node(&(*root)->right->left, (*root)->right, 110) ||
		create_node(&(*root)->right->right->left, (*root)->right->right, 200) ||
		create_node(&(*root)->right->right->right, (*root)->right->right, 512))
	{
		free_tree(*root);
		return (1);
	}
	return (0);
}

/**
 * free_tree - Frees the binary tree
 * @root: Pointer to the root of the tree
 */
void free_tree(binary_tree_t *root)
{
	if (root == NULL)
		return;

	free_tree(root->left);
	free_tree(root->right);
	free(root);
}
