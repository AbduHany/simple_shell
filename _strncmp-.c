#include "shell.h"

/**
 * _strncmp - compares the 2 strings s1 and s upto n charecters
 * @s1: first string to be compared.
 * @s2: second string to be compared.
 * n: num of bytes be compared.
 *
 * Return: positive value if s1 is longer
 * negative if s2 is longer
 * 0 if equal.
 */
int _strncmp(char *s1, char *s2, size_t n)
{
	size_t len_s1 = _strlen(s1);
	size_t len_s2 = _strlen(s2);
	size_t i;

	if (len_s1 >= n && len_s2 >= n)
	{
		for (i = 0; i < n ; i++)
		{
			if (s1[i] > s2[i])
				return (1);
			else if (s1[i] < s2[i])
				return (-1);
		}
		return  (0);
	}
	else
	{
		if (len_s1 == len_s2)
		{
			for (i = 0; i < len_s1 ; i++)
			{
				if (s1[i] > s2[i])
					return (1);
				else if (s1[i] < s2[i])
					return (-1);
			}
			return  (0);
		}
		else if (len_s1 > len_s2)
		{
			for (i = 0; i < len_s2 ; i++)
			{
				if (s1[i] > s2[i])
					return (1);
				else if (s1[i] < s2[i])
					return (-1);
			}
			return (1);
		}
		else
		{
			for (i = 0; i < len_s1 ; i++)
			{
				if (s1[i] > s2[i])
					return (1);
				else if (s1[i] < s2[i])
					return (-1);
			}
			return (-1);
		}
	}
}
