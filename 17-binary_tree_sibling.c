#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node in a binary tree
 * @node: pointer to the node to find the sibling for
 *
 * Description: If node is NULL or the parent is NULL, return NULL.
 *              If node has no sibling, return NULL.
 *
 * Return: pointer to the sibling node
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	/* Check if the node is NULL or if the parent is NULL*/
	if (!node || !node->parent)
		return (NULL);

	/* If the node is its parent's left child, return the right child*/
	if (node->parent->left == node)
		return (node->parent->right);

	/* If the node is its parent's right child, return the left child*/
	if (node->parent->right == node)
		return (node->parent->left);

	/* If the node doesn't have a sibling, return NULL*/
	return (NULL);
}
