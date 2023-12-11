#include "shell.h"
/**
 * 
*/
char* _strdup(char *str)
{
    char *copy;
    int len, i;

    len = _strlen(str);

    copy = malloc((sizeof(char) * len) + 1);

    for (i = 0; i <= len; i++)
    {
        copy[i] = str [i];
    }

    return (copy);
    
}