#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure
 *
 * Return: size in size_t
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t d;

	if (tree == NULL)
		return (0);
	d = 1 + binary_tree_size(tree->left) + binary_tree_size(tree->right);
	return (d);
}

/**
 * is_complete - checks if tree is complete
 * @root: pointer to tree node
 * @index: node index in tree
 * @size: number of nodes in the tree
 *
 * Return: 1 if complete else 0
 */
int is_complete(const binary_tree_t *root, size_t index, size_t size)
{
	if (root == NULL)
		return (1);
	if (index >= size)
		return (0);
	return (is_complete(root->left, 2 * index + 1, size)
			&& is_complete(root->right, 2 * index + 2, size));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if complete, 0 if not and if tree is NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (tree == NULL)
		return (0);
	size = binary_tree_size(tree);
	return (is_complete(tree, 0, size));
}

/**
 * maxheap - checks if a node data is greater than its children
 * @tree: tree node
 *
 * Return: 0 or 1
 */
int maxheap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);
	if ((tree->left && (tree->left->n >= tree->n)) ||
	(tree->right && (tree->right->n >= tree->n)))
	{
		return (0);
	}
	return (maxheap(tree->left) && maxheap(tree->right));
}

/**
 * binary_tree_is_heap - check if a binary tree is a max heap
 * @tree: tree
 *
 * Return: 0 or 1
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (binary_tree_is_complete(tree))
	{
		return (maxheap(tree));
	}
	return (0);
}
