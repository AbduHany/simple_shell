#include "shell.h"

/**
 * _strcat - concatenates two strings.
 * @s1: pointer of destination string concatenation.
 * @s2: pointer of source string concatenation.
 *
 * Return: Char pointer to concatenated string.
 */
char *_strcat(char *s1, char *s2)
{
	int i, len;

	len = 0;
	for (i = 0; s1[i] != '\0'; i++)
	{
		len++;
	}
	for (i = 0; s2[i] != '\0'; i++)
	{
		s1[len + i] = s2[i];
	}
	s1[len + i] = '\0';
	return (s1);
}
