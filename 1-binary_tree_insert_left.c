#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: pointer to a parent node
 * @value: n data value of the new node
 *
 * Return: (binary_tree_t *) on SUCCESS or NULL on FAILURE
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *leftNode;

	if (parent == NULL)
		return (NULL);
	leftNode = binary_tree_node(parent, value);
	if (leftNode == NULL)
		return (NULL);
	if (parent->left)
		leftNode->left = parent->left, parent->left->parent = leftNode;

	parent->left = leftNode;

	return (leftNode);
}

