#include "binary_trees.h"

/**
 * shift_nodes - places nodes in the right order
 * @node: pointer to the node to be replaced
 * @sub: pointer to the substitute of node
 *
 * Return: void
 */
avl_t *shift_nodes(bst_t *node, bst_t *sub)
{
	if (sub != NULL)
		sub->parent = node->parent;
	return (sub);
}

/**
 * inorder_successor - finds the inorder successor of a tree node
 * @tree: pointer to the tree node
 *
 * Return: pointer to a successor or NULL
 */
avl_t *inorder_successor(bst_t *tree)
{
	bst_t *pivot, *trace;

	if (tree == NULL)
		return (NULL);
	trace = tree;
	if (trace->right)
	{
		pivot = trace->right;
		while (pivot->left)
			pivot = pivot->left;
		return (pivot);
	}
	/* Not needed for this, but adds to the standard algorithm */
	pivot = trace->parent;
	while (pivot && pivot->right == trace)
		pivot = pivot->parent, trace = pivot;
	return (pivot);
}

/**
 * _avl_remove - removes a node from a binary search tree
 * @node: pointer to the node to be deleted
 *
 * Return: pointer to the new root of the tree after deletion
 */
avl_t *_avl_remove(bst_t *node)
{
	bst_t *sub, *successor;

	if (node == NULL)
		return (NULL);
	if (node->left == NULL)
		successor = shift_nodes(node, node->right);
	else if (node->right == NULL)
		successor = shift_nodes(node, node->left);
	else
	{
		successor = inorder_successor(node);
		if (successor->parent != node)
		{
			sub = shift_nodes(successor, successor->right);
			if (successor == successor->parent->left)
				successor->parent->left = sub;
			else
				successor->parent->right = sub;
			successor->right = node->right;
			successor->right->parent = successor;
		}
		successor = shift_nodes(node, successor);
		successor->left = node->left;
		successor->left->parent = successor;
	}
	free(node);
	return (successor);
}

/**
 * avl_remove - removes a node from an AVL tree
 * @root: pointer to the root node of the tree
 * @value: value to remove in the tree
 *
 * Return: pointer to new root node after removing the value and rebalancing
 */
avl_t *avl_remove(avl_t *root, int value)
{
	int balance;

	if (root == NULL)
		return (root);
	if (value == root->n)
		root = _avl_remove(root);
	else if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);

	balance = binary_tree_balance(root);
	if (balance > 1 && binary_tree_balance(root->left) >= 0)
		return (binary_tree_rotate_right(root));
	if (balance < -1 && binary_tree_balance(root->right) <= 0)
		return (binary_tree_rotate_left(root));
	if (balance > 1 && binary_tree_balance(root->left) < 0)
	{
		root->left = binary_tree_rotate_left(root->left);
		return (binary_tree_rotate_right(root));
	}
	if (balance < -1 && binary_tree_balance(root->right) > 0)
	{
		root->right = binary_tree_rotate_right(root->right);
		return (binary_tree_rotate_left(root));
	}
	return (root);
}
