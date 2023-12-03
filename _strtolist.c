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
	char *buffer = NULL, *temp;
	char *delim = " ";
	int i = 0, j;

	while (1)
	{
		str_arr = realloc(str_arr, sizeof(char *) * (i + 1));
		if (str_arr == NULL)
			return (NULL);
		buffer = strtok(str, delim);
		if (buffer == NULL)
			break;
		temp = malloc(sizeof(char) * (_strlen(buffer) + 1));
		if (temp == NULL)
		{
			for (j = i - 1; j >= 0; j--)
			{
				free(str_arr[j]);
			}
		}
		_strcpy(temp, buffer);
		str_arr[i] = temp;
		i++;
		str = NULL;
		temp = NULL;
	}
	str_arr[i] = NULL;
	return (str_arr);
}
