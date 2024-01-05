#include "binary_trees.h"

/**
 * array_to_avl - builds a Binary Search Tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 *
 * Return: pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_avl(int *array, size_t size)
{
	size_t x;
	bst_t *avltree = NULL;

	if (array == NULL)
		return (NULL);
	for (x = 0; x < size; x++)
		avl_insert(&avltree, array[x]);
	return (avltree);
}
