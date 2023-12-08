#include "shell.h"
#define BUFFER_SIZE 5000
/**
 * _getline - gets all of the input line from stdin
 * @lineptr: saves the input from stdin 
 * @n: the number of charecters read form the stdin
 * @stream: stream of input, if it was a file
 * Return: the number of the charecters read
*/
ssize_t _getline(char **lineptr, size_t *n, __attribute__ ((unused)) FILE *stream)
{
    ssize_t read_bytes;
    static char buffer[BUFFER_SIZE];
		
    read_bytes = read(0, buffer, sizeof(buffer));

    *lineptr = buffer;

    *n = read_bytes; /* new line charceter is included in the count */

    return (read_bytes);
}