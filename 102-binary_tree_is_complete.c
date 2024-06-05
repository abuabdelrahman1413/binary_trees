#include "binary_trees.h"

/**
 * binary_tree_is_complete - function that checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{

	if (tree == NULL)
		return (0);
	Queue *queue = createQueue();

	enqueue(queue, (binary_tree_t *)tree);
	int firstIncompleteNode = 0;
	while(!isQueueEmpty(queue))
	{

	}
}
