#include "binary_trees.h"

/**
 * binary_height - meassures height of a binary tree
 * @tree: pointer to the root node of the tree to measure
 *
 * Return: height in size_t
 */
size_t binary_height(const binary_tree_t *tree)
{
	int lh, rh;

	if (tree == NULL)
		return (0);
	lh = 1 + binary_height(tree->left);
	rh = 1 + binary_height(tree->right);
	return (lh > rh ? lh : rh);
}

/**
 * printCurrentLevel - print current level
 * @tree: tree
 * @level: tree level
 * @func: print func
 *
 * Return: void
 */
void printLevel(
		const binary_tree_t *tree, size_t level, void (*func)(int))
{
	if (tree == NULL)
		return;
	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		printLevel(tree->left, level - 1, func);
		printLevel(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - goes through a BT using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t h, i;

	if (tree == NULL || func == NULL)
		return;

	h = binary_height(tree);
	for (i = 1; i <= h; i++)
		printLevel(tree, i, func);
}
