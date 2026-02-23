#include <stdio.h>
#include <stdlib.h>
#include "sandpiles.h"

/**
 * is_stable - Check if sandpile is stable
 * @grid: 3x3 grid to check
 * Return: 1 if stable, 0 if not stable
 */
static int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * print_sandpile - Print a sandpile grid
 * @grid: 3x3 grid to print
 */
static void print_sandpile(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * stabilize_sandpile - Stabilize an unstable sandpile
 * @grid: 3x3 grid to stabilize
 */
static void stabilize_sandpile(int grid[3][3])
{
	int i, j, temp[3][3];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			temp[i][j] = grid[i][j];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (temp[i][j] > 3)
			{
				grid[i][j] -= 4;
				if (i > 0)
					grid[i - 1][j] += 1;
				if (i < 2)
					grid[i + 1][j] += 1;
				if (j > 0)
					grid[i][j - 1] += 1;
				if (j < 2)
					grid[i][j + 1] += 1;
			}
		}
	}
}

/**
 * sandpiles_sum - Compute the sum of two sandpiles
 * @grid1: First sandpile (result will be stored here)
 * @grid2: Second sandpile
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];

	while (!is_stable(grid1))
	{
		print_sandpile(grid1);
		stabilize_sandpile(grid1);
	}
}
