#include "shell.h"
/**
 * compare - compares n characters form each string,
 * this is to shorten
 * the number of lines of the _strncmp functoin
 * @s1: stringg 1
 * @s2: stirng 2
 * @n: the numbet of charceters to be compared from the 2 strings
 * Return: 0 on equality, -1 if s2 is greater, 1 if s1 is greater
*/
int compare(char *s1, char *s2, size_t n)
{
	size_t i;
	int result;

	for (i = 0; i < n ; i++)
	{
		if (s1[i] > s2[i])
		{
			result = (1);
			break;
		}
		else if (s1[i] < s2[i])
		{
			result = (-1);
			break;
		}
	}
	return (result);
}
/**
 * _strncmp - compares the 2 strings s1 and s upto n charecters
 * @s1: stringg 1
 * @s2: stirng 2
 * @n: the numbet of charceters to be compared from the 2 strings
 * Return: 0 on equality, -1 if s2 is greater, 1 if s1 is greater
*/
int _strncmp(char *s1, char *s2, size_t n)
{
	size_t len_s1 = _strlen(s1), len_s2 = _strlen(s2);
	int result;

	if (len_s1 >= n && len_s2 >= n)
	{
		compare(s1, s2, n);
		result = (0);
	}
	else
	{
		if (len_s1 == len_s2)
		{
			compare(s1, s2, len_s1);
			result = (0);
		}
		else if (len_s1 > len_s2)
		{
			compare(s1, s2, len_s2);
			result = (1);
		}
		else
		{
			compare(s1, s2, len_s1);
			result = (-1);
		}
	}
	return (result);
}
