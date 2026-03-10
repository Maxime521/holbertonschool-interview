#include "palindrome.h"

/**
 * is_palindrome - checks if a number is a palindrome
 * @n: the number to check
 *
 * Return: 1 if the number is a palindrome, 0 otherwise
 */

int is_palindrome(unsigned long n)
{
	unsigned long reversed = 0, original = n;

	while (n > 0)
	{
		reversed = reversed * 10 + n % 10;
		n /= 10;
	}

	return (reversed == original);
}
