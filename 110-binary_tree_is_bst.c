#include <limits.h>
#include "binary_trees.h"

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
 * binary_tree_is_bst - checks if a tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a binary search tree, else 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (check_bst(tree, INT_MIN, INT_MAX));
}

