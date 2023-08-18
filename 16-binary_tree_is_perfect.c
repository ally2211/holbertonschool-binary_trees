#include "binary_trees.h"

/**
 * depth - determine the depth of a node
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return:  depth
 */
size_t depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	while (tree)
	{
		depth++;
		tree = tree->parent;
	}
	return (depth);
}
/**
 * is_perfect - determine if a tree is perfect
 * @tree: Pointer to the root node of the tree to check.
 * @depth_first_leaf: depth first leaf
 * @current: depth
 *
 * Return: 1 is true
 */
int is_perfect(const binary_tree_t *tree, int depth_first_leaf, int current)
{
	if (!tree)
		return (1);

	/* If it's a leaf node.*/
	if (!tree->left && !tree->right)
	{
		if (depth_first_leaf == current)
			return (1);
		else
			return (0);
	}

	/* If node has only one child.*/
	if (!tree->left || !tree->right)
		return (0);

	/* Recursively check left and right subtrees.*/
	if (is_perfect(tree->left, depth_first_leaf, current + 1))
	{
		if (is_perfect(tree->right, depth_first_leaf, current + 1))
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is perfect, otherwise 0. If tree is NULL, return 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth_of_first_leaf;

	if (!tree)
		return (0);

	depth_of_first_leaf = depth(tree) + 1;

	return (is_perfect(tree, depth_of_first_leaf, 1));
}

