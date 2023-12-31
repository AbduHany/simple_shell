#include "shell.h"

/**
 * _getline - gets all of the input line from stdin
 * @lineptr: saves the input from stdin
 * @n: the number of charecters read form the stdin
 * @fd: filedescriptor to getline from
 * Return: the number of the charecters read
*/
ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	static ssize_t i;
	char *buffer, letter;
	int readbyte;
	size_t oldsize = 120, newsize;

	buffer = malloc(sizeof(char) * 120);
	if (buffer == NULL)
		return (-1);
	i = 0;
	do {
		if ((size_t)i == oldsize)
		{
			newsize = oldsize + 120;
			buffer = _realloc(buffer, oldsize, newsize);
			oldsize = newsize;
		}
		readbyte = read(fd, &letter, 1);
		if (readbyte == -1 || (readbyte == 0 && i == 0))
		{
			free(buffer);
			return (-1);
		}
		if (readbyte == 0 && i != 0)
		{
			i++;
			break;
		}
		buffer[i] = letter;
		i++;
	} while (letter != '\n' && letter != ';');
	buffer[i] = '\0';
	*lineptr = buffer;
	if (i < 120)
		*n = 120;
	else
		*n = newsize;
	return (i);
}
