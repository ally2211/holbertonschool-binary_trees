#include "binary_trees.h"


/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree.
 * @tree: Pointer to the root node of the tree to count the number of nodes.
 *
 * Return: Number of nodes with at least one child, or 0 if tree is NULL.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count;

	if (tree == NULL)
		return (0);

	/*check if is a leaf node */
	if (tree->left == NULL && tree->right == NULL)
		return (0);

	/* count for the current node has at least one child. */
	count = 1;
	/* Recursively count the nodes in left subtree */
	if (tree->left != NULL)
		count += binary_tree_nodes(tree->left);

	/* Recursively count the nodes in the right subtree */
	if (tree->right != NULL)
		count += binary_tree_nodes(tree->right);

	/* Return the total count.*/
	return (count);
}
