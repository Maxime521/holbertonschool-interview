#!/usr/bin/python3
import sys


def is_safe(board, row, col, n):
    for i in range(col):
        if board[i] == row:
            return False

    i = col - 1
    j = row - 1
    while i >= 0 and j >= 0:
        if board[i] == j:
            return False
        i -= 1
        j -= 1

    i = col - 1
    j = row + 1
    while i >= 0 and j < n:
        if board[i] == j:
            return False
        i -= 1
        j += 1

    return True


def solve_nqueens(board, col, n, solutions):
    if col >= n:
        result = []
        for i in range(n):
            result.append([i, board[i]])
        solutions.append(result)
        return

    for row in range(n):
        if is_safe(board, row, col, n):
            board[col] = row
            solve_nqueens(board, col + 1, n, solutions)
            board[col] = -1


def print_solutions(solutions):
    for solution in solutions:
        print(solution)


if __name__ == "__main__":
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

    board = [-1] * n
    solutions = []
    solve_nqueens(board, 0, n, solutions)
    print_solutions(solutions)
