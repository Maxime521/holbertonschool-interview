#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * same_word - compare fixed-length word against string region
 * @a: first string
 * @b: second string
 * @len: number of chars to compare
 * Return: 1 if equal, 0 otherwise
 */
static int same_word(char const *a, char const *b, int len)
{
	return (strncmp(a, b, (size_t)len) == 0);
}

/**
 * find_word - find index of token in words
 * @token: current word in scanned string
 * @words: array of words
 * @nb_words: number of words
 * @word_len: common words length
 * Return: index in words, or -1 if not found
 */
static int find_word(char const *token, char const **words,
	int nb_words, int word_len)
{
	int i;

	for (i = 0; i < nb_words; i++)
	{
		if (same_word(token, words[i], word_len))
			return (i);
	}
	return (-1);
}

/**
 * match_at - checks if concatenation exists at index start
 * @s: source string
 * @start: start index
 * @words: array of words
 * @nb_words: number of words
 * @word_len: common words length
 * @seen: usage counts for current window
 * Return: 1 if valid concatenation, 0 otherwise
 */
static int match_at(char const *s, int start, char const **words,
	int nb_words, int word_len, int *seen)
{
	int k, idx;
	char const *token;

	for (k = 0; k < nb_words; k++)
		seen[k] = 0;
	for (k = 0; k < nb_words; k++)
	{
		token = s + start + (k * word_len);
		idx = find_word(token, words, nb_words, word_len);
		if (idx < 0)
			return (0);
		seen[idx]++;
		if (seen[idx] > 0 && seen[idx] > 1)
		{
			int allowed = 0, i;

			for (i = 0; i < nb_words; i++)
				if (same_word(words[i], words[idx], word_len))
					allowed++;
			if (seen[idx] > allowed)
				return (0);
		}
	}
	return (1);
}

/**
 * find_substring - finds all starting indices of valid word concatenations
 * @s: string to scan
 * @words: list of words
 * @nb_words: number of words in list
 * @n: output number of found indices
 * Return: allocated array of indices, or NULL if none/error
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int s_len, word_len, total_len, i, count;
	int *out, *seen;

	if (!s || !words || !n || nb_words <= 0 || !words[0])
		return (NULL);
	*n = 0;
	word_len = (int)strlen(words[0]);
	if (word_len <= 0)
		return (NULL);
	s_len = (int)strlen(s);
	total_len = nb_words * word_len;
	if (s_len < total_len)
		return (NULL);
	out = malloc((size_t)(s_len + 1) * sizeof(int));
	seen = malloc((size_t)nb_words * sizeof(int));
	if (!out || !seen)
	{
		free(out);
		free(seen);
		return (NULL);
	}
	count = 0;
	for (i = 0; i <= s_len - total_len; i++)
	{
		if (match_at(s, i, words, nb_words, word_len, seen))
			out[count++] = i;
	}
	free(seen);
	if (count == 0)
	{
		free(out);
		return (NULL);
	}
	*n = count;
	return (out);
}
