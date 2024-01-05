#include "binary_trees.h"

/**
 * sorted_array_avl - build an AVL tree from a sorted array recursively
 * @array: sorted array
 * @start: start
 * @end: end
 * @root: parent node
 *
 * Return: pointer to created node
 */
avl_t *sorted_array_avl(int *array, int start, int end, avl_t *root)
{
	int mid;

	if (array == NULL)
		return (NULL);

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	root = binary_tree_node(root, array[mid]);
	if (root == NULL)
		return (NULL);

	root->left = sorted_array_avl(array, start, mid - 1, root);
	root->right = sorted_array_avl(array, mid + 1, end, root);

	return (root);
}

/**
 * sorted_array_to_avl - build an AVL tree from a sorted array
 * @array: sorted array
 * @size: size of array
 *
 * Return: pointer to root node
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	if (array == NULL)
		return (NULL);

	return (sorted_array_avl(array, 0, (int)size - 1, root));
}

