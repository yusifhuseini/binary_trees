#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: pointer to the new root of the tree after rotation
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *newRoot;

	if (tree == NULL || tree->left == NULL)
		return (NULL);
	newRoot = tree->left;
	tree->left = newRoot->right;
	if (newRoot->right)
		newRoot->right->parent = tree;
	newRoot->right = tree;
	if (tree->parent)
	{
		if (tree->parent->left == tree)
			tree->parent->left = newRoot;
		else
			tree->parent->right = newRoot;
	}
	newRoot->parent = tree->parent;
	tree->parent = newRoot;
	return (newRoot);
}
