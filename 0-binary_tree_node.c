#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: parent node
 * @value: node n data, integer
 *
 * Return: binary_tree_t node on SUCCESS or NULL on FAILURE
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode;

	newNode = (binary_tree_t *) malloc(sizeof(binary_tree_t));

	if (newNode == NULL)
		return (NULL);

	newNode->n = value, newNode->parent = parent;
	newNode->left = NULL, newNode->right = NULL;

	return (newNode);
}

