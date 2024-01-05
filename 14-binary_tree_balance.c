#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree);

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to count the number of nodes
 *
 * Return: number of internal nodes in size_t
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_height(tree->left)
			- binary_tree_height(tree->right));
}


/**
 * binary_tree_height - meassures height of a binary tree
 * @tree: pointer to the root node of the tree to measure
 *
 * Return: height in size_t
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	int lh, rh;

	if (tree == NULL)
		return (0);
	lh = 1 + binary_tree_height(tree->left);
	rh = 1 + binary_tree_height(tree->right);
	return (lh > rh ? lh : rh);
}

