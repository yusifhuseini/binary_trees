#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: pointer to the new root of the tree after rotation
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *newRoot;

	if (tree == NULL || tree->right == NULL)
		return (NULL);
	newRoot = tree->right;
	tree->right = newRoot->left;
	if (newRoot->left)
		newRoot->left->parent = tree;
	newRoot->left = tree;
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
