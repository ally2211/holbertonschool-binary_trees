#include "binary_trees.h"

/**
 * tree_height - Helper function to compute the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 * 
 * Return: The height of the tree, or 0 if tree is NULL.
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t left_height;
	size_t right_height;

	if (!tree)
		return (0);

	left_height = tree_height(tree->left);
	right_height = tree_height(tree->right);

	if (left_height > right_height)
		return (1 + left_height);
	else
		return (1 + right_height);
}
/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the balance factor.
 *
 * Return: The balance factor of the tree, or 0 if tree is NULL.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int right_height;
	int left_height;

	if (!tree)
		return (0);

	left_height = (int) tree_height(tree->left);
	right_height = (int) tree_height(tree->right);
 
	return (left_height - right_height);
}
