#include "shell.h"

/**
 * _strcpy - copies the string pointed by source to the destination.
 * @dest: destination string.
 * @src: source string.
 * Return: char pointer to copied string.
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
