#include <stdlib.h>
#include "binary_trees.h"
#include <stdio.h>

/**
 * get_insertion_parent - Finds the first node missing a child (BFS)
 * @root: pointer to the root node
 * Return: Parent node where the new node should be inserted
 */
heap_t *get_insertion_parent(heap_t *root)
{
	int head = 0, tail = 0;
	heap_t **queue_nodes = malloc(sizeof(heap_t *) * 1024);

	if (queue_nodes == NULL)
		return (NULL);

	queue_nodes[tail++] = root;

	while (head < tail)
	{
		heap_t *current_node = queue_nodes[head++];

		if (!current_node->left || !current_node->right)
		{
			free(queue_nodes);
			return (current_node);
		}

		if (current_node->left)
			queue_nodes[tail++] = current_node->left;
		if (current_node->right)
			queue_nodes[tail++] = current_node->right;
	}

	free(queue_nodes);
	return (NULL);
}

/**
 * heapify_up - Bubbles up a node to maintain Max Heap property
 * @node: Node to move if necessary
 * Return: The final node after bubbling
 */
heap_t *heapify_up(heap_t *node)
{
	int swap_value;

	while (node->parent && node->n > node->parent->n)
	{
		swap_value = node->n;
		node->n = node->parent->n;
		node->parent->n = swap_value;
		node = node->parent;
	}
	return (node);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * @value: Value to insert
 * Return: Pointer to the inserted node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_heap_node, *parent_node;

	if (root == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	parent_node = get_insertion_parent(*root);
	if (parent_node == NULL)
		return (NULL);

	new_heap_node = binary_tree_node(parent_node, value);
	if (new_heap_node == NULL)
		return (NULL);

	if (parent_node->left == NULL)
		parent_node->left = new_heap_node;
	else
		parent_node->right = new_heap_node;

	return (heapify_up(new_heap_node));
}
