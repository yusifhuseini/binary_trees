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
 * heap_insert - inserts a value in Max Binary Heap
 * @root: double pointer to the root node of the Heap to insert the value
 * @value: value to store in the node to be inserted
 *
 * Return: a pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *newNode, *trace, *tree;
	int size, leafNodes, nodes, level;

	if (root == NULL)
		return (NULL);
	if (*root == NULL)
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	size = binary_tree_size(tree);
	leafNodes = size;
	/* Calculate number of leaf nodes */
	for (level = 0, nodes = 1; leafNodes >= nodes; nodes *= 2, level++)
		leafNodes -= nodes;
	/* Determine parent node for the new node to be inserted */
	for (level = 1 << (level - 1); level != 1; level >>= 1)
		tree = leafNodes & level ? tree->right : tree->left;
	newNode = binary_tree_node(tree, value);
	/* Assign new node as the appropriate child node of it parent node */
	if (leafNodes & 1)
		tree->right = newNode;
	else
		tree->left = newNode;
	trace = newNode;
	for (; trace->parent && (trace->n > trace->parent->n); trace = trace->parent)
	{
		nodes = trace->n;
		trace->n = trace->parent->n;
		trace->parent->n = nodes;
		newNode = newNode->parent;
	}
	return (newNode);
}
