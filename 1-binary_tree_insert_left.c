#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as a left-child of
 *                           another node in a binary tree.
 * @parent: A pointer to the node to insert the left-child in.
 * @value: The value to store in the new node.
 *
 * Return: If parent is NULL or an error occurs - NULL.
 *         Otherwise - a pointer to the new node.
 *
 * Description: If parent already has a left-child, the new node
 *              takes its place, and the old left-child is set as
 *              the left-child of the new node.
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	/*Check if the parent node is NULL*/
	if (parent == NULL)
		return (NULL);

	/* Create a new node with the given value*/
	binary_tree_t *new_node = binary_tree_node(parent, value);

	if (new_node == NULL)
	{
		return (NULL);
	}

	/* If the parent already has a left child*/
	if (parent->left != NULL)
	{
		/*Set the new node's left child to the current left child of the parent*/
		new_node->left = parent->left;

		/*Set the parent of the current left child to the new node*/
		parent->left->parent = new_node;
	}

	/*Set the parent's left pointer to the new node*/
	parent->left = new_node;

	return (new_node);
}
