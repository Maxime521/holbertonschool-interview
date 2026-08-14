#include "binary_trees.h"
#include <limits.h>

/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Height of the tree, 0 if tree is NULL
 */
int height(const binary_tree_t *tree)
{
	int left_h, right_h;

	if (!tree)
		return (0);

	left_h = height(tree->left);
	right_h = height(tree->right);

	if (left_h > right_h)
		return (left_h + 1);
	return (right_h + 1);
}

/**
 * is_avl_helper - Checks if a binary tree is a valid AVL recursively
 * @tree: Pointer to the current node
 * @min: Minimum allowed value
 * @max: Maximum allowed value
 *
 * Return: 1 if valid AVL, 0 otherwise
 */
int is_avl_helper(const binary_tree_t *tree, int min, int max)
{
	int left_h, right_h, diff;

	if (!tree)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	left_h = height(tree->left);
	right_h = height(tree->right);
	diff = left_h - right_h;

	if (diff > 1 || diff < -1)
		return (0);

	return (is_avl_helper(tree->left, min, tree->n) &&
		is_avl_helper(tree->right, tree->n, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
