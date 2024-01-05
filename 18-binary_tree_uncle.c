#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node to find the uncle
 *
 * Return: sibling node if found else NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *grandParent;

	if (!(node) || !(node->parent) || !(node->parent->parent))
		return (NULL);
	grandParent = node->parent->parent;
	if (grandParent->left == node->parent)
		return (grandParent->right);
	return (grandParent->left);
}

