#include "binary_trees.h"

int perfect(const binary_tree_t *tree, size_t idealDepth, size_t level);

/**
 * binary_tree_is_perfect - binary_tree_is_perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is perfect, else 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t idealDepth = 0;
	binary_tree_t *node;

	if (tree == NULL)
		return (0);
	node = tree->left;
	while (node)
		node = node->left, ++idealDepth;
	return (perfect(tree, idealDepth, 0));
}

/**
 * perfect - checks if level of leaves equal idealDepth
 * @tree: pointer to the root node of the tree to check
 * @idealDepth: depth of the first leaf node
 * @level: level of tree, defaults to 0
 *
 * Return: 1 if tree is perfect, else 0
 */
int perfect(const binary_tree_t *tree, size_t idealDepth, size_t level)
{
	if (tree == NULL)
		return (1);
	if (tree->left == NULL && tree->right == NULL)
		return (idealDepth == level);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (perfect(tree->left, idealDepth, level + 1)
			&& perfect(tree->right, idealDepth, level + 1));
}

