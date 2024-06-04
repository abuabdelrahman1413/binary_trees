#include "binary_trees.h"

/**
* binary_tree_depth - function that measures the depth of a node in\
* a binary tree
* @tree: the binary tree
* Return: the depth of the tree
*/

size_t binary_tree_depth(const binary_tree_t *tree)
{
    size_t depth = 0;
    
    while (tree)
    {
        depth++;
        tree = tree->left;
    }
    return depth;
}
/**
* is_perfect_fun - function that checks if a binary tree is perfect
* @tree: the binary tree
* @depth: the depth of the tree
* @level: the level of the current node
* Return: 1 if the tree is perfect, 0 otherwise.
*/
int is_perfect_fun(const binary_tree_t *tree, int depth, int level)
{
    if (tree == NULL)
        return (1);

    /*if we are leaf by the leftmost (the depth)*/
    if (!tree->left && !tree->right)
        return (depth == level + 1);
    /*if we have one child that is not perfect tree*/
    if (!tree->left || !tree->right)
        return (0);
    
    return (is_perfect_fun(tree->left, depth, level + 1) &&
                    is_perfect_fun(tree->right, depth, level + 1));

}
/**
* binary_tree_is_perfect -  function that checks if a binary tree is perfect
* @tree: the binary tree
* Return: 1 if the tree is perfect, 0 otherwise.
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    if (tree == NULL)
		  return (0);
    int depth;

    depth = binary_tree_depth(tree);
    return (is_perfect_fun(tree, depth, 0));

}
