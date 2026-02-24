#include "lists.h"
#include <stddef.h>

/**
 * reverse_list - reverses a singly linked list
 * @head: pointer to the head list
 *
 * Return: pointer to the new head of the reversed list
 */
listint_t *reverse_list(listint_t *head)
{
	listint_t *prev = NULL;
	listint_t *current = head;
	listint_t *next = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return (prev);
}

/**
 * find_middle - finds the middle of a linked list
 * @head: pointer to the head of the list
 * @prev_slow: pointer to store the node before middle
 *
 * Return: pointer to the middle node
 */
listint_t *find_middle(listint_t *head, listint_t **prev_slow)
{
	listint_t *slow, *fast;

	slow = fast = head;
	*prev_slow = NULL;

	while (fast != NULL && fast->next != NULL)
	{
		*prev_slow = slow;
		slow = slow->next;
		fast = fast->next->next;
	}

	if (fast != NULL)
	{
		*prev_slow = slow;
		slow = slow->next;
	}

	return (slow);
}

/**
 * compare_halves - compares two halves of a linked list
 * @first: pointer to first half
 * @second: pointer to second half
 *
 * Return: 1 if equal, 0 if different
 */
int compare_halves(listint_t *first, listint_t *second)
{
	while (second != NULL && first != NULL)
	{
		if (second->n != first->n)
			return (0);
		second = second->next;
		first = first->next;
	}
	return (1);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to the head of the list
 *
 * Return: 1 if the list is a palindrome, 0 if not palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *middle, *second_half, *prev_slow;
	int result;

	if (*head == NULL || (*head)->next == NULL)
		return (1);

	middle = find_middle(*head, &prev_slow);

	if (prev_slow != NULL)
		prev_slow->next = NULL;

	second_half = reverse_list(middle);
	result = compare_halves(*head, second_half);

	second_half = reverse_list(second_half);
	if (prev_slow != NULL)
		prev_slow->next = second_half;
	else
		*head = second_half;

	return (result);
}
