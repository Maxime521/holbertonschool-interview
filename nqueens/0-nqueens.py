#!/usr/bin/python3
"""Solve the N queens puzzle using backtracking."""

import sys


def solve_nqueens(n, row, cols, diag1, diag2, positions):
    """Backtracking search for valid queen placements."""
    if row == n:
        solution = [[r, positions[r]] for r in range(n)]
        print(solution)
        return

    for col in range(n):
        d1 = row - col
        d2 = row + col
        if col in cols or d1 in diag1 or d2 in diag2:
            continue

        cols.add(col)
        diag1.add(d1)
        diag2.add(d2)
        positions[row] = col

        solve_nqueens(n, row + 1, cols, diag1, diag2, positions)

        cols.remove(col)
        diag1.remove(d1)
        diag2.remove(d2)


def main():
    """Entry point for argument validation and solving."""
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    solve_nqueens(n, 0, set(), set(), set(), [-1] * n)


if __name__ == "__main__":
    main()
