# Merge Sort

This project implements **top-down Merge Sort** in C to sort an array of integers in ascending order.

## Project Info

- **Repository:** `holbertonschool-interview`
- **Directory:** `merge_sort`
- **Files:** `0-merge_sort.c`, `0-O`, `sort.h`

## Function Prototype

```c
void merge_sort(int *array, size_t size);
```

## Requirements Covered

- Sort an array in ascending order using **top-down Merge Sort**.
- When splitting an array, the left subarray size is always less than or equal to the right subarray size.
  - Example: `{1, 2, 3, 4, 5}` → `{1, 2}` and `{3, 4, 5}`
- Sort the left subarray before the right subarray.
- Print merge steps during execution.
- Use `malloc` and `free` only once each.

## How It Works

1. Allocate a temporary buffer once at the start of `merge_sort`.
2. Recursively divide the array into two halves.
3. Sort the left half, then the right half.
4. Merge the two sorted halves back into the original array.
5. Print each merge step with `[left]`, `[right]`, and `[Done]` output.
6. Free the temporary buffer at the end.

## Complexity

The file `0-O` contains:

- Best case: `O(nlog(n))`
- Average case: `O(nlog(n))`
- Worst case: `O(nlog(n))`

## Build Example

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-merge_sort.c print_array.c -o merge
./merge
```

## Example Output

```
19, 48, 99, 71, 13, 52, 96, 73, 86, 7
Merging...
[left]: 19
[right]: 48
[Done]: 19, 48
...
[Done]: 7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
```
