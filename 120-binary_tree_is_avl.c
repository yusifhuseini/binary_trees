#include <limits.h>
#include "binary_trees.h"

/**
 * binary_height - recursively calculate the height of the binary tree
 * @tree: tree
 *
 * Return: -1 or Height
 */
size_t binary_height(const binary_tree_t *tree)
{
	int lh, rh;

	if (tree == NULL)
		return (0);

	lh = binary_height(tree->left);
	rh = binary_height(tree->right);
	return (lh > rh ? lh + 1 : rh + 1);
}

/**
 * binary_tree_avl - checks if a binary tree is a valid AVL Tree recursively
 * @tree: tree
 *
 * Return: 1 0r 0
 */
int binary_tree_avl(const binary_tree_t *tree)
{
	int lh, rh, diff;

	if (tree == NULL)
		return (1);

	lh = binary_height(tree->left);
	rh = binary_height(tree->right);

	diff = lh > rh ? lh - rh : rh - lh;
	if (diff <= 1 && binary_tree_avl(tree->left)
	&& binary_tree_avl(tree->right))
		return (1);

	return (0);
}

/**
 * check_bst - checks if tree is a binary search tree
 * @tree: pointer to the root node of the tree
 * @min: minimum integer value
 * @max: maxium integer value
 *
 * Return: 1 if tree is binary search tree else 0
 */
int check_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (check_bst(tree->left, min, tree->n - 1)
			&& check_bst(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_avl - checks if a binary tree
 * is a valid AVL Tree
 * @tree: tree
 *
 * Return: 1 0r 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (check_bst(tree, INT_MIN, INT_MAX))
		return (binary_tree_avl(tree));
	return (0);
}
