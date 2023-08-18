#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is full, otherwise 0. If tree is NULL, return 0.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	/* If tree is NULL.*/
	if (!tree)
		return (0);

	/* If it's a leaf node. */
	if (!tree->left && !tree->right)
		return (1);

	/* If node has either one left or one right child but not both.*/
	if (!tree->left || !tree->right)
		return (0);

	/* If the node has both left and right children, check for both subtrees.*/
	return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
}
