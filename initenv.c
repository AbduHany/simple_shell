#include "shell.h"

/**
 * initenv - initializes a copy of env into a char**.
 * then updates the global variable environ to point to it.
 *
 * Return: array of string of env variables.
 */
char **initenv(void)
{
	int i = 0, j, varnum = 0;
	char **env;

	for (i = 0; environ[i] != NULL; i++)
		varnum++;
	env = malloc((varnum + 1) * sizeof(char *));
	if (env == NULL)
		return (NULL);
	for (i = 0; environ[i] != NULL; i++)
	{
		env[i] = malloc(_strlen(environ[i]) + 1);
		if (env[i] == NULL)
		{
			for (j = i - 1; j >= 0; j--)
			{
				free(env[j]);
			}
			free(env);
			return (NULL);
		}
		_strcpy(env[i], environ[i]);
	}
	env[i] = NULL;
	return (env);
}
