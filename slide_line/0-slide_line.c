#include "slide_line.h"

/**
 * slide_left - Slides non-zero elements to the left
 * @line: Pointer to array of integers
 * @size: Size of the array
 */
static void slide_left(int *line, size_t size)
{
	size_t i, j;

	for (i = 0, j = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			if (j != i)
				line[j] = line[i];
			j++;
		}
	}
	for (; j < size; j++)
		line[j] = 0;
}

/**
 * slide_right - Slides non-zero elements to the right
 * @line: Pointer to array of integers
 * @size: Size of the array
 */
static void slide_right(int *line, size_t size)
{
	size_t i, j;

	for (i = size, j = size; i > 0; i--)
	{
		if (line[i - 1] != 0)
		{
			if (j != i)
				line[j - 1] = line[i - 1];
			j--;
		}
	}
	for (; j > 0; j--)
		line[j - 1] = 0;
}

/**
 * merge_left - Merges identical adjacent elements to the left
 * @line: Pointer to array of integers
 * @size: Size of the array
 */
static void merge_left(int *line, size_t size)
{
	size_t i;

	for (i = 0; i < size - 1; i++)
	{
		if (line[i] != 0 && line[i] == line[i + 1])
		{
			line[i] *= 2;
			line[i + 1] = 0;
		}
	}
}

/**
 * merge_right - Merges identical adjacent elements to the right
 * @line: Pointer to array of integers
 * @size: Size of the array
 */
static void merge_right(int *line, size_t size)
{
	size_t i;

	for (i = size; i > 1; i--)
	{
		if (line[i - 1] != 0 && line[i - 1] == line[i - 2])
		{
			line[i - 1] *= 2;
			line[i - 2] = 0;
		}
	}
}

/**
 * slide_line - Slides and merges an array of integers
 * @line: Pointer to array of integers
 * @size: Size of the array
 * @direction: SLIDE_LEFT or SLIDE_RIGHT
 *
 * Return: 1 upon success, 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);

	if (direction == SLIDE_LEFT)
	{
		slide_left(line, size);
		merge_left(line, size);
		slide_left(line, size);
	}
	else
	{
		slide_right(line, size);
		merge_right(line, size);
		slide_right(line, size);
	}

	return (1);
}
