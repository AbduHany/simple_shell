#include "shell.h"

/**
 * _putinterr - prints an int value to stderr.
 * @a: integer to be printed.
 *
 * Return: void.
 */
void _putinterr(int linenum)
{
	int rem;
	char *dig = malloc(1);

	while (linenum)
	{
		rem = linenum % 10;
		*dig = rem + '0';
		write(2, dig, 1);
		linenum = linenum / 10;
	}
	free(dig);
}
