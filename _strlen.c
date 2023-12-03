#include "shell.h"

/**
 * _strlen - counts the number of characters in a string.
 * @str: char pointer to the string.
 * Return: number of bytes in a string.
 */
int _strlen(char *str)
{
	int i = 0, count = 0;

	if (str == NULL)
		return (-1);
	while (str[i] != '\0')
	{
		count++;
		i++;
	}
	return (count);
}
