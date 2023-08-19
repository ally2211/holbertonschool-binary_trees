#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node in a binary tree
 * @node: pointer to the node to find the uncle for
 *
 * Description: If node is NULL, return NULL.
 *              If node has no uncle, return NULL.
 *
 * Return: pointer to the uncle node, or NULL if no uncle or if node is NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	/* Check node is NULL or if it doesn't have a parent or grandparent*/
	if (!node || !node->parent || !node->parent->parent)
		return (NULL);

	/* If the parent of the node is the left child of the grandparent*/
	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);

	/* If the parent of the node is the right child of the grandparent*/
	if (node->parent->parent->right == node->parent)
		return (node->parent->parent->left);

	/* If the node doesn't have an uncle, return NULL*/
		return (NULL);
}

