#include "binary_trees.h"

/**
 * shift_nodes - places nodes in the right order
 * @tree: double pointer to the root node of the tree
 * @node: pointer to the node to be replaced
 * @sub: pointer to the substitute of node
 *
 * Return: void
 */
void shift_nodes(bst_t **tree, bst_t *node, bst_t *sub)
{
	if (node->parent == NULL)
		*tree = sub;
	else if (node->parent->left == node)
		node->parent->left = sub;
	else
		node->parent->right = sub;
	if (sub != NULL)
		sub->parent = node->parent;
}

/**
 * inorder_successor - finds the inorder successor of a tree node
 * @tree: pointer to the tree node
 *
 * Return: pointer to a successor or NULL
 */
bst_t *inorder_successor(bst_t *tree)
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
	pivot = trace->parent;
	while (pivot && pivot->right == trace)
		pivot = pivot->parent, trace = pivot;
	return (pivot);
}

/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: pointer to the root node of the BST to search
 * @value: value to search in the tree
 *
 * Return:  pointer to the node containing a value equals to value, or NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL || value == tree->n)
		return ((bst_t *) tree);
	if (value < tree->n)
		return (bst_search(tree->left, value));
	return (bst_search(tree->right, value));
}

/**
 * bst_remove - removes a node from a binary search tree
 * @root: pointer to the root node of the tree
 * @value: value to remove in the tree
 *
 * Return: pointer to the new root of the tree after deletion
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node, *successor;

	if (root == NULL)
		return (NULL);
	node = bst_search(root, value);
	if (node->left == NULL)
		shift_nodes(&root, node, node->right);
	else if (node->right == NULL)
		shift_nodes(&root, node, node->left);
	else
	{
		successor = inorder_successor(node);
		if (successor->parent != node)
		{
			shift_nodes(&root, successor, successor->right);
			successor->right = node->right;
			successor->right->parent = successor;
		}
		shift_nodes(&root, node, successor);
		successor->left = node->left;
		successor->left->parent = successor;
	}
	free(node);
	return (root);
}
