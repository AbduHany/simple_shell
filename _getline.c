#include "shell.h"

/**
 * _getline - reads string from stdin and allocates memory
 * for it and then assigns it at the input string.
 * @input: string that will be filled with read bytes.
 * @len: size of bytes allocated for the string.
 * @stream: file buffer to read from.
 *
 * Return: signed size of read bytes.
 * -1 if error encountered.
 */
ssize_t _getline(char **input, size_t *len, FILE *stream)
{
	char *buffer = NULL;
	ssize_t i = 0;

	*len = 0;
	do {
		if ((size_t)i == *len)
		{
			*len = (*len) * 2;
			if (*len == 0)
				*len = 120;
		}
		buffer = realloc(buffer, *len);
		if (buffer == NULL)
			return (-1);
		buffer[i] = fgetc(stream);
		if (buffer[i] == '\n')
		{
			buffer[i] = '\0';
			break;
		}
		i++;
	} while (buffer[i] != EOF);
	*input = buffer;
	return (i);
}
