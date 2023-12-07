#include "shell.h"

/**
 * _freedouble - frees an array of char * pointers.
 * @s: pointer to array of pointers.
 *
 * Return: void
 */
void _freedouble(char **s)
{
	int i = 0;

	while (s[i] != NULL)
	{
		free(s[i]);
		i++;
	}
	if (s)
		free(s);
}
