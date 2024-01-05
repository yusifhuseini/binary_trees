#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to common ancestor node or NULL
 */
binary_tree_t *binary_trees_ancestor(
		const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *fstParent, *secParent;

	if (first == NULL || second == NULL)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *) first);
	fstParent = first->parent, secParent = second->parent;
	if (first == secParent || !fstParent
			|| (!fstParent->parent && secParent))
		return (binary_trees_ancestor(first, secParent));
	else if (second == secParent || !secParent
			|| (!secParent->parent && fstParent))
		return (binary_trees_ancestor(fstParent, second));
	return (binary_trees_ancestor(fstParent, secParent));
}
