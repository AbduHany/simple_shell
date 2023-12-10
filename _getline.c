#include "shell.h"

/**
 * _getline - gets all of the input line from stdin
 * @lineptr: saves the input from stdin
 * @n: the number of charecters read form the stdin
 * @stream: stream of input, if it was a file
 * Return: the number of the charecters read
*/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static ssize_t i;
	ssize_t readbytes;
	char *buffer, letter;
	int readflag;
	size_t oldsize = 120, newsize;

	(void)stream;
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
		readflag = read(STDIN_FILENO, &letter, 1);
		if (readflag == -1 || (readflag == 0 && i == 0))
		{
			free(buffer);
			return (-1);
		}
		if (readflag == 0 && i != 0)
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
	readbytes = i;
	return (readbytes);
}
