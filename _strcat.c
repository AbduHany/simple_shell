#include "shell.h"
/**
 * _strcat - concatinates two strings
 * @s1: destination string
 * @s2: source string
 * Return: pointer to string where s2 is appended to s1.
*/
char* _strcat(char *s1, char *s2)
{
    char* result;
    int len_s1 = _strlen(s1);
    int len_s2 = _strlen(s2);
    int i, j;

    result = malloc(sizeof(char) * (len_s1 + len_s2 +1));

    for (i = 0; i < len_s1; i++)
        result[i] = s1[i];
    
    for (j = 0; j < (len_s2 + 1); j++)
        result[i + j] = s2[j];
    
    return (result);
}