# Radix Sort

This project implements **LSD Radix Sort** in C to sort an array of non-negative integers in ascending order.

## Project Info

- **Repository:** `holbertonschool-interview`
- **Directory:** `radix_sort`
- **Files:** `0-radix_sort.c`, `sort.h`

## Function Prototype

```c
void radix_sort(int *array, size_t size);
```

## Requirements Covered

- Sort an array in ascending order using **LSD Radix Sort**.
- Assume all array values are non-negative integers.
- Use `malloc` and `free` for temporary storage.
- Print the array after each significant digit pass.

## How It Works

1. Find the maximum value in the array to determine the number of digit passes.
2. For each digit position (1, 10, 100, ...), perform a stable counting sort.
3. Print the array after each pass.
4. Continue until all significant digits are processed.

## Build Example

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-radix_sort.c print_array.c -o radix
./radix
```

## Example Output

```
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

71, 52, 13, 73, 96, 86, 7, 48, 19, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
```
