#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: pointer to a parent node
 * @value: n data value of the new node
 *
 * Return: (binary_tree_t *) on SUCCESS or NULL on FAILURE
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *rightNode;

	if (parent == NULL)
		return (NULL);
	rightNode = binary_tree_node(parent, value);
	if (rightNode == NULL)
		return (NULL);
	if (parent->right)
		rightNode->right = parent->right, parent->right->parent = rightNode;

	parent->right = rightNode;

	return (rightNode);
}

