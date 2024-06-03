#include "binary_trees.h"

/**
* binary_tree_uncle - function that finds the uncle of a node
* @node: node to check if it uncle
* Return: Pointer to the uncle node, or NULL if no uncle exists.
*/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
    if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		  return (NULL);
    binary_tree_t *parent, *grandparent;

    parent = node->parent;
    grandparent = parent->parent;
    if (grandparent->left == parent)
        return grandparent->right;
    else
        return grandparent->left;
}