#include "shell.h"

/**
 * _getenv - gets an environment variable.
 * @name: name of the var inside the environ list.
 *
 * Return: pointer to the value string of the var defined
 * by name.
 */
char *_getenv(char *name)
{
	int i, k, flag = 0, complen;
	char **env = environ;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (k = 0, complen = 0; env[i][k] != '='; k++)
			complen++;
		if (_strlen(name) == complen)
		{
			if (_strncmp(name, env[i], complen) == 0)
				flag = 1;
		}
		if (flag == 1)
		{
			return (&env[i][complen]);
		}
	}
	return (NULL);
}
