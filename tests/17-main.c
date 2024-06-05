#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * create_binary_tree - Creates a binary tree node
 * @parent: Pointer to the parent node
 * @value: Value to store in the new node
 * Return: Pointer to the newly created node
 */
binary_tree_t *create_binary_tree(binary_tree_t *parent, int value)
{
	binary_tree_t *node = binary_tree_node(parent, value);

	if (node == NULL)
		exit(1);

	return (node);
}

/**
 * link_binary_tree_nodes - Links nodes of a binary tree
 * @parent: Pointer to the parent node
 * @child: Pointer to the child node
 */
void link_binary_tree_nodes(binary_tree_t *parent, binary_tree_t *child)
{
	if (child == NULL)
	{
		free(parent);
		exit(1);
	}

	if (parent != NULL)
	{
		parent->left = child;
		child->parent = parent;
	}
}

/**
 * main - Entry point
 * Return: Always 0 (Success)
 */
int main(void)
{
	binary_tree_t *root, *sibling;

	root = create_binary_tree(NULL, 98);
	link_binary_tree_nodes(root, create_binary_tree(root, 12));
	link_binary_tree_nodes(root, create_binary_tree(root, 128));
	link_binary_tree_nodes(root->left, create_binary_tree(root->left, 54));
	link_binary_tree_nodes(root->right, create_binary_tree(root->right, 402));
	link_binary_tree_nodes(root->left, create_binary_tree(root->left, 10));
	link_binary_tree_nodes(root->right, create_binary_tree(root->right, 110));
	link_binary_tree_nodes(root->right->right,
	create_binary_tree(root->right->right, 200));
	link_binary_tree_nodes(root->right->right,
	create_binary_tree(root->right->right, 512));

	binary_tree_print(root);

	sibling = binary_tree_sibling(root->left);
	printf("Sibling of %d: %d\n", root->left->n, sibling ? sibling->n : -1);
	sibling = binary_tree_sibling(root->right->left);
	printf("Sibling of %d: %d\n",
	root->right->left->n, sibling ? sibling->n : -1);
	sibling = binary_tree_sibling(root->left->right);
	printf("Sibling of %d: %d\n",
	root->left->right->n, sibling ? sibling->n : -1);
	sibling = binary_tree_sibling(root);
	printf("Sibling of %d: %p\n", root->n, (void *)sibling);

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
