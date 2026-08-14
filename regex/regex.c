#include <stdlib.h>
#include <string.h>
#include "regex.h"

/**
 * char_match - checks if a pattern char matches a string char
 * @s: character from string
 * @p: character from pattern
 *
 * Return: 1 if matches, 0 otherwise
 */
static int char_match(char s, char p)
{
	return (p == '.' || p == s);
}

/**
 * init_empty_matches - initializes dp row for empty string
 * @dp: dp table
 * @pattern: regex pattern
 * @m: pattern length
 */
static void init_empty_matches(unsigned char *dp, char const *pattern, int m)
{
	int j;

	dp[0] = 1;
	for (j = 2; j <= m; j++)
	{
		if (pattern[j - 1] == '*' && dp[j - 2])
			dp[j] = 1;
	}
}

/**
 * fill_dp - fills dp table for all string/pattern prefixes
 * @dp: dp table
 * @str: string to match
 * @pattern: regex pattern
 * @n: string length
 * @m: pattern length
 */
static void fill_dp(unsigned char *dp, char const *str,
	char const *pattern, int n, int m)
{
	int i, j, idx;

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			idx = i * (m + 1) + j;
			if (pattern[j - 1] == '*' && j > 1)
			{
				if (dp[i * (m + 1) + (j - 2)])
					dp[idx] = 1;
				if (char_match(str[i - 1], pattern[j - 2]) &&
					dp[(i - 1) * (m + 1) + j])
					dp[idx] = 1;
			}
			else if (char_match(str[i - 1], pattern[j - 1]))
				dp[idx] = dp[(i - 1) * (m + 1) + (j - 1)];
		}
	}
}

/**
 * regex_match - Checks if a pattern matches a string
 * @str: String to scan
 * @pattern: Regular expression pattern
 * Return: 1 if pattern matches str, otherwise 0
 */

int regex_match(char const *str, char const *pattern)
{
	int n, m;
	unsigned char *dp;

	if (!str || !pattern)
		return (0);

	n = (int)strlen(str);
	m = (int)strlen(pattern);
	dp = calloc((size_t)(n + 1) * (size_t)(m + 1), sizeof(unsigned char));
	if (!dp)
		return (0);

	init_empty_matches(dp, pattern, m);
	fill_dp(dp, str, pattern, n, m);
	n = dp[n * (m + 1) + m];
	free(dp);
	return (n);
}
