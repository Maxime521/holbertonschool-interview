# Find The Loop

This project implements a function that finds the node where a loop starts in a singly linked list.

## Prototype

```c
listint_t *find_listint_loop(listint_t *head);
```

## Requirements

- Returns the address of the node where the loop starts.
- Returns `NULL` if there is no loop.
- No `malloc`, `free`, or arrays.
- At most two variables declared in the function.

## Approach

Uses Floyd's cycle detection (tortoise and hare):

1. Detect a meeting point with slow and fast pointers.
2. Reset one pointer to the head and advance both one step at a time.
3. The meeting point is the start of the loop.
