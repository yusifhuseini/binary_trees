#include "binary_trees.h"

/**
 * _avl_insert - performs clean avl insert into an avl tree
 * @node: pointer to the node to be inserted in
 * @value: new value to be inserted
 * @parent: pointer to the parent node of the newly created node
 * @new: double pointer to store the new node
 *
 * Return: pointer to the root node of tree after insertion or NULL on failure
 */
avl_t *_avl_insert(avl_t *node, int value, avl_t *parent, avl_t **new)
{
	int balance;

	if (node == NULL)
	{
		*new = binary_tree_node(parent, value);
		if (*new == NULL)
			return (NULL);
		return (*new);
	}
	if (value < node->n)
		node->left = _avl_insert(node->left, value, node, new);
	else if (value > node->n)
		node->right = _avl_insert(node->right, value, node, new);
	else
		return (node);
	balance = binary_tree_balance(node);
	if (balance > 1 && value < node->left->n)
		return (binary_tree_rotate_right(node));
	if (balance < -1 && value > node->right->n)
		return (binary_tree_rotate_left(node));
	if (balance > 1 && value > node->left->n)
	{
		node->left = binary_tree_rotate_left(node->left);
		return (binary_tree_rotate_right(node));
	}
	if (balance < -1 && value < node->right->n)
	{
		node->right = binary_tree_rotate_right(node->right);
		return (binary_tree_rotate_left(node));
	}
	return (node);
}

/**
 * avl_insert - inserts a value in an avl tree
 * @tree: double pointer to the root node of the avl tree
 * @value: value to store in the node to be inserted
 *
 * Return: pointer to the new node or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *newNode = NULL;

	if (tree == NULL)
		return (NULL);
	*tree = _avl_insert(*tree, value, *tree, &newNode);
	return (newNode);
}
