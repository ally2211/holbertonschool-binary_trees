#include "binary_trees.h"

/**
 * depth_leftmost_leaf - determine the depth of a node
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return:  depth
 */
static int depth_leftmost_leaf(const binary_tree_t *tree)
{
	int depth = 0;

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
 * @depth: depth of leftmost leaf
 * @level: current level
 *
 * Return: 1 is true
 */
int is_perfect(const binary_tree_t *tree, int depth, int level)
{
	if (!tree)
		return (1);

	/* If it's a leaf node.*/
	if (!tree->left && !tree->right)
		return (depth == level);

	if (!tree->left && !tree->right)
		return (0);

	/* Recursively check left and right subtrees.*/
	if (is_perfect(tree->left, depth, level + 1))
	{
		if (is_perfect(tree->right, depth, level + 1))
			return (1);
	}

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
	int depth;

	if (!tree)
		return (0);

	depth = depth_leftmost_leaf(tree) + 1;

	return (is_perfect(tree, depth, 1));
}

