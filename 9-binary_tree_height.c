#include "binary_trees.h"


/**
 * binary_tree_height - meassures height of a binary tree
 * @tree: pointer to the root node of the tree to measure
 *
 * Return: height in size_t
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	int lh, rh;

	if (tree == NULL || (!tree->left && !tree->right))
		return (0);
	lh = 1 + binary_tree_height(tree->left);
	rh = 1 + binary_tree_height(tree->right);
	return (lh > rh ? lh : rh);
}

