#include "shell.h"

/**
 * _putstr - writes the string str to stdout.
 * @str: character pointer to string to be printed.
 *
 * Return: on success number of characters written.
 * on error, -1 is returned.
 */
int _putstr(char *str)
{
	int written_bytes = 0, i = 0;

	if (str == NULL)
		return (-1);
	while (str[i] != '\0')
	{
		written_bytes += _putchar(str[i]);
		i++;
	}
	return (written_bytes);
}
