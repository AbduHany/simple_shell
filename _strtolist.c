#include "shell.h"

/**
 * assign_mem - assigns memory space for word characters.
 * @words: the double pointer to the words array.
 * @word_count: number of words.
 * @str: the string of original words.
 * @delim: delimiting character.
 *
 * Return: void.
 */
void assign_mem(char **words, int word_count, char *str, char delim)
{
	int i, wlen, j;

	for (i = 0, j = 0, wlen = 0; str[i] != '\0'; i++)
	{
		if (j == word_count)
			return;
		if (str[i] != delim)
		{
			wlen++;
			if (str[i + 1] == delim || str[i + 1] == '\0')
			{
				words[j] = (char *) malloc((wlen + 1) * sizeof(char));
				j++;
				wlen = 0;
			}
		}
	}
}

/**
 * countwords - counts number of space separated words
 * in a string.
 * @str: pointer to string to be counted.
 * @delim: delimiting character.
 *
 * Return: number of words
 */
int countwords(char *str, char delim)
{
	int i, word_count;

	word_count = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != delim)
		{
			if (i == 0 || str[i - 1] == delim)
				word_count++;
		}
	}
	return (word_count);
}
/**
 * _strtolist - splits a string into words.
 * @str: pointer to string to be split.
 * @delim: delimiting character.
 *
 * Return: a double char pointer to the array of words.
 */
char **_strtolist(char *str, char delim)
{
	int word_count, i, j, k;
	char **words;

	if (str == NULL || *str == '\0')
		return (NULL);
	word_count = countwords(str, delim);
	if (word_count == 0)
		return (NULL);
	words = malloc((word_count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	assign_mem(words, word_count, str, delim);
	for (i = 0, j = 0, k = 0; str[i] != '\0'; i++)
	{
		if (str[i] != delim)
		{
			words[j][k] = str[i];
			k++;
			if (str[i + 1] == delim || str[i + 1] == '\0')
			{
				words[j][k] = '\0';
				k = 0;
				j++;
			}
		}
	}
	words[word_count] = NULL;
	return (words);
}
