#include "binary_trees.h"

/**
 * _bst_insert - performs clean avl insert into an avl tree
 * @node: pointer to the node to be inserted in
 * @value: new value to be inserted
 * @parent: pointer to the parent node of the newly created node
 * @new: double pointer to store the new node
 *
 * Return: pointer to the root node of tree after insertion or NULL on failure
 */
bst_t *_bst_insert(bst_t *node, int value, bst_t *parent, bst_t **new)
{
	if (node == NULL)
	{
		*new = binary_tree_node(parent, value);
		if (*new == NULL)
			return (NULL);
		return (*new);
	}
	if (value < node->n)
		node->left = _bst_insert(node->left, value, node, new);
	else if (value > node->n)
		node->right = _bst_insert(node->right, value, node, new);
	return (node);
}

/**
 * bst_insert - inserts a value in a binary search tree
 * @tree: is a double pointer to the root node of the BST
 * @value: is the value to store in the node to be inserted
 *
 * Return: a pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *newNode = NULL;

	if (tree == NULL)
		return (NULL);
	*tree = _bst_insert(*tree, value, *tree, &newNode);
	return (newNode);
}
