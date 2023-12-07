#include "shell.h"

/**
 * _putinterr - prints an int value to stderr.
 * @linenum: integer to be printed.
 *
 * Return: void.
 */
void _putinterr(int linenum)
{
	int rem, temp, len = 0, i = 0;
	char *num;

	temp = linenum;
	while (temp)
	{
		temp = temp / 10;
		len++;
	}

	num = malloc(sizeof(char) * (len));
	if (num == NULL)
		return;

	while (linenum)
	{
		rem = linenum % 10;
		num[i] = rem + '0';
		linenum = linenum / 10;
		i++;
	}
	for (i = (len - 1); i >= 0; i--)
	{
		write(2, &num[i], 1);
	}
	free(num);
}
