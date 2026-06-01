#!/usr/bin/python3
"""
Module for calculating rainwater retention.
Given a list of wall heights, calculates how many square units
of water will be retained after it rains.
"""


def rain(walls):
    """
    Calculate how many square units of water will be retained after it rains.

    Args:
        walls: A list of non-negative integers representing wall heights.

    Returns:
        Integer indicating total amount of rainwater retained.
    """
    if not walls or len(walls) < 3:
        return 0

    n = len(walls)
    total_water = 0

    # Precompute max height to the left for each position (excluding current)
    max_left = [0] * n
    for i in range(1, n):
        max_left[i] = max(max_left[i - 1], walls[i - 1])

    # Precompute max height to the right for each position (excluding current)
    max_right = [0] * n
    for i in range(n - 2, -1, -1):
        max_right[i] = max(max_right[i + 1], walls[i + 1])

    # Calculate water trapped at each position
    for i in range(1, n - 1):
        water = min(max_left[i], max_right[i]) - walls[i]
        if water > 0:
            total_water += water

    return total_water
