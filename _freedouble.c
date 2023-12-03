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

	if (s == NULL || s[i] == NULL)
		return;
	while (s[i] != NULL)
	{
		free(s[i]);
		i++;
	}
}
