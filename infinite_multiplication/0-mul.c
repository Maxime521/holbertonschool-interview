#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int _putchar(char c);

/**
 * print_error_and_exit - prints "Error" and exits with status 98
 */
void print_error_and_exit(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(98);
}

/**
 * print_ull - prints an unsigned long long number
 * @n: number to print
 */
void print_ull(unsigned long long n)
{
	if (n / 10)
		print_ull(n / 10);
	_putchar((n % 10) + '0');
}

/**
 * print_string - prints a string using _putchar
 * @str: string to print
 */
void print_string(char *str)
{
	if (str)
		while (*str)
			_putchar(*str++);
}

/**
 * is_digit_string - checks if a string contains only digits
 * @str: string to check
 * Return: 1 if all digits, 0 otherwise
 */
int is_digit_string(char *str)
{
	if (!str || !*str)
		return (0);
	while (*str)
		if (*str < '0' || *str++ > '9')
			return (0);
	return (1);
}

/**
 * remove_leading_zeros - removes leading zeros from a number string
 * @str: string to process (will be freed by caller)
 * Return: pointer to new string without leading zeros (caller must free)
 */
static char *remove_leading_zeros(char *str)
{
	int len, start;
	char *result;

	if (str == NULL)
		return (NULL);

	len = strlen(str);
	start = 0;
	while (start < len - 1 && str[start] == '0')
		start++;

	result = malloc(len - start + 1);
	if (result == NULL)
	{
		free(str);
		return (NULL);
	}
	strcpy(result, str + start);
	free(str);
	return (result);
}

/**
 * multiply_strings - multiplies two number strings
 * @num1: first number string
 * @num2: second number string
 * Return: pointer to result string (caller must free)
 */
char *multiply_strings(char *num1, char *num2)
{
	int len1, len2, i, j, k, product, carry;
	char *result;

	if (num1[0] == '0' || num2[0] == '0')
	{
		result = malloc(2);
		if (result)
		{
			result[0] = '0';
			result[1] = '\0';
		}
		return (result);
	}

	len1 = strlen(num1);
	len2 = strlen(num2);
	result = malloc(len1 + len2 + 1);
	if (result == NULL)
		return (NULL);
	memset(result, '0', len1 + len2);
	result[len1 + len2] = '\0';

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			k = i + j + 1;
			product = (num1[i] - '0') * (num2[j] - '0') + (result[k] - '0') + carry;
			result[k] = (product % 10) + '0';
			carry = product / 10;
		}
		result[i] += carry;
	}

	return (remove_leading_zeros(result));
}

/**
 * main - multiplies two positive numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	char *result;

	if (argc != 3)
		print_error_and_exit();

	if (!is_digit_string(argv[1]) || !is_digit_string(argv[2]))
		print_error_and_exit();

	result = multiply_strings(argv[1], argv[2]);
	if (result == NULL)
		print_error_and_exit();

	print_string(result);
	_putchar('\n');

	free(result);
	return (0);
}
