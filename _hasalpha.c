#include "shell.h"
/**
 * _hasalpha - function to check whther the string has letters or not
 * used for exit builtin function
 * @str: the strin to be checked
 * Return: 0 if it does not,  1if it does.
*/
int _hasalpha(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
			return (1);

		i++;
	}
	return (0);
}
