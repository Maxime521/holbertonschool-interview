#include "binary_trees.h"
/**
 * tree_size - Helper function to calculate the size of the tree
 * @tree: Pointer to the root node of the tree
 * Return: Size of the tree
 */
static size_t tree_size(const heap_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * heapify_down - Restores max heap property by moving node down
 * @node: Pointer to the node to heapify down
 */
static void heapify_down(heap_t *node)
{
	heap_t *largest = node;
	int tmp;

	if (node == NULL)
		return;

	if (node->left && node->left->n > largest->n)
		largest = node->left;
	if (node->right && node->right->n > largest->n)
		largest = node->right;
	if (largest != node)
	{
		tmp = node->n;
		node->n = largest->n;
		largest->n = tmp;
		heapify_down(largest);
	}
}

/**
 * find_last_node - Finds the last node in level-order traversal
 * @root: Pointer to the root node of the heap
 * @size: Size of the heap
 * Return: Pointer to the last node, or NULL on failure
 */
static heap_t *find_last_node(heap_t *root, size_t size)
{
	heap_t **queue;
	heap_t *last_node;
	int head, tail;

	queue = malloc(sizeof(heap_t *) * size);
	if (queue == NULL)
		return (NULL);

	head = 0;
	tail = 0;
	queue[tail++] = root;
	last_node = root;

	while (head < tail)
	{
		heap_t *current = queue[head++];

		last_node = current;

		if (current->left)
			queue[tail++] = current->left;
		if (current->right)
			queue[tail++] = current->right;
	}

	free(queue);
	return (last_node);
}

/**
* heap_extract - Function that extracts the root node of a Max Binary Heap
* @root: Double pointer to the root node of the heap
* Return: Value stored in the root node, or 0 on failure
*/

int heap_extract(heap_t **root)
{
	heap_t *last_node, *parent;
	size_t size;
	int value;

	if (root == NULL || *root == NULL)
		return (0);

	value = (*root)->n;

	if ((*root)->left == NULL && (*root)->right == NULL)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	size = tree_size(*root);
	last_node = find_last_node(*root, size);
	if (last_node == NULL)
		return (0);

	(*root)->n = last_node->n;
	parent = last_node->parent;
	if (parent->left == last_node)
		parent->left = NULL;
	else
		parent->right = NULL;
	free(last_node);
	heapify_down(*root);
	return (value);
}
