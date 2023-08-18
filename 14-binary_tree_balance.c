#include "binary_trees.h"

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

	left_height = (int) 9-binary_tree_height(tree->left);
	right_height = (int) 9-binary_tree_height(tree->right);
 
	return (left_height - right_height);
}
