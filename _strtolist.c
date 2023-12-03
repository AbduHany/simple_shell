#include "shell.h"

/**
 * _strtolist - takes a string and tokenizes it
 * creating an array of token strings.
 * @str: string to be tokenized.
 *
 * Return: double pointer to the array of tokens.
 */
char **_strtolist(char *str)
{
	char **str_arr = NULL;
	char *buffer = NULL;
	char *delim = " ";
	int i = 0;

	while (1)
	{
		str_arr = realloc(str_arr, sizeof(char *) * (i + 1));
		if (str_arr == NULL)
			return (NULL);
		buffer = strtok(str, delim);
		if (buffer == NULL)
			break;
		str_arr[i] = buffer;
		i++;
		str = NULL;
	}
	str_arr[i] = NULL;
	return (str_arr);
}
