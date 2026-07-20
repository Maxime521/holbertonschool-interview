# Double Circular Linked List

This project implements functions to add nodes to a double circular linked list.

## Project Info

- **Repository:** `holbertonschool-interview`
- **Directory:** `double_circular_linked_list`
- **Files:** `0-add_node.c`, `list.h`

## Function Prototypes

```c
List *add_node_end(List **list, char *str);
List *add_node_begin(List **list, char *str);
```

## Requirements Covered

- Add a new node to the **end** of a double circular linked list.
- Add a new node to the **beginning** of a double circular linked list.
- Copy the given string into the new node with `strdup`.
- Return the address of the new node, or `NULL` on failure.

## How It Works

- An empty list is represented by `NULL`.
- A single-node list points to itself for both `prev` and `next`.
- **End insertion:** insert the new node between the current last node and the head.
- **Begin insertion:** insert the new node before the head and update the list pointer.

## Build Example

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-add_node.c -o a.out
./a.out
```
