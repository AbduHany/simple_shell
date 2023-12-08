#include "shell.h"
#define MAX_BUFFER_SIZE 5000
/**
 * 
*/
ssize_t _getline(char **lineptr, size_t *n, __attribute__ ((unused)) FILE *stream)
{
    ssize_t read_bytes;
    static char buffer[MAX_BUFFER_SIZE];

    read_bytes = read(0, buffer, sizeof(buffer));

    *lineptr = buffer;

    *n = read_bytes; /* new line charceter is included in the count */

    return (read_bytes);
}