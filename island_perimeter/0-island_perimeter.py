#!/usr/bin/python3
"""Calculate the perimeter of an island given in the grid"""


def island_perimeter(grid):
    """Return the perimeter of the island described in grid"""
    if not grid:
        return 0

    row = len(grid)
    perimeter = 0

    for i in range(row):
        col = len(grid[i])
        for j in range(col):
            if grid[i][j] == 1:
                perimeter += 4
                # Check the top case
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2
                # Check the left case
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2

    return perimeter
