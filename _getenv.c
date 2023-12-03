#include "shell.h"

/**
 * _getenv - gets an environment variable.
 * @name: name of the var inside the environ list.
 *
 * Return: pointer to the value string of the var defined
 * by name.
 */
char *_getenv(const char *name)
{
	int i, j, flag;
	char **env = environ;

	for (i = 0; environ[i] != NULL; i++)
	{
		flag = 0;
		for (j = 0; name[j] != '\0' || env[i][j] != '='; j++)
		{
			if (name[j] != env[i][j])
			{
				flag = 1;
				break;
			}
			else if (env[i][j] == '=')
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			return (&env[i][j + 1]);
		}
	}
	return (NULL);
}
