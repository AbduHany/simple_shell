#include "shell.h"

/**
 * revstr - reverses a string.
 * @str: a pointer to the string.
 *
 * Return: a pointer to the reserved string.
 */
void revstr(char *str)
{
	int i, len;
	char tmp;

	for (i = 0, len = 0; str[i] != '\0'; i++)
		len++;
	for (i = 0; i < (len / 2); i++)
	{
		tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
	}
}

/**
 * _itoa - converts an int value to a string.
 * @num: the int to be converted to string.
 *
 * Return: char pointer to the converted string.
 */
char *_itoa(int num)
{
	int len = 0, temp, negflag = 0, rem, i;
	char *str;

	if (num == 0)
	{
		str = _strdup("0");
		if (!str)
			return (NULL);
		return (str);
	}
	if (num < 0)
	{
		len++;
		num = num * -1;
		negflag = 1;
	}
	temp = num;
	while (temp)
	{
		temp = temp / 10;
		len++;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	for (i = 0; num; i++, num = num / 10)
	{
		rem = num % 10;
		str[i] = rem + '0';
	}
	if (negflag)
		str[i++] = '-';
	str[i] = '\0';
	revstr(str);
	return (str);
}
