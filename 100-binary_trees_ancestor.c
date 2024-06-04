
#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 *
 * @first: A pointer to the first node.
 * @second: A pointer to the second node.
 *
 * Return: A pointer to the lowest common ancestor node of the two given nodes.
 *         If no common ancestor was found, your function must return NULL.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
                                    const binary_tree_t *second)
{
    if (!first || !second) {
        return NULL;
    }

    const binary_tree_t *f = first;
    const binary_tree_t *s = second;

    while (f && s) {
        if (f == s) {
            return (binary_tree_t *)f;
        }

        // Check if one node is an ancestor of the other
        if (f->parent) {
            if (is_descendant(f->parent, second)) {
                return (binary_tree_t *)f->parent;
            }
            f = f->parent;
        } else if (s->parent) {
            if (is_descendant(s->parent, first)) {
                return (binary_tree_t *)s->parent;
            }
            s = s->parent;
        } else {
            // No more parents to explore, no common ancestor
            return NULL;
        }
    }

    return NULL;
}

// Helper function to check if a node is a descendant of another
bool is_descendant(const binary_tree_t *parent, const binary_tree_t *node) {
    while (node) {
        if (node == parent) {
            return true;
        }
        node = node->parent;
    }
    return false;
}
