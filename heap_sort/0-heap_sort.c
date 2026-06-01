#include "sort.h"

/**
 * sift_down - Sifts down an element in the heap to maintain heap property
 * @array: The array to heapify
 * @size: Size of the array
 * @root: Root index of the subtree
 * @end: End index of the heap
 */
void sift_down(int *array, size_t size, size_t root, size_t end)
{
	size_t max = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;
	int temp;

	/* Find the maximum among root, left child, and right child */
	if (left < end && array[left] > array[max])
		max = left;

	if (right < end && array[right] > array[max])
		max = right;

	/* If root is not the maximum, swap and continue sifting down */
	if (max != root)
	{
		temp = array[root];
		array[root] = array[max];
		array[max] = temp;
		print_array(array, size);
		sift_down(array, size, max, end);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort
 * @array: The array to sort
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	int temp;
	size_t i;

	if (array == NULL || size < 2)
		return;

	/* Build max heap */
	for (i = size / 2; i > 0; i--)
		sift_down(array, size, i - 1, size);

	/* Extract elements from heap one by one */
	for (i = size - 1; i > 0; i--)
	{
		/* Move current root to end */
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);

		/* Heapify the reduced heap */
		sift_down(array, size, 0, i);
	}
}
