#include "shell.h"

/**
 * _setenv - changes or adds an environment variable
 * @name: name string of the newly added var.
 * @value: value string to be added to name var.
 * @overwrite: a flag that determines whether to
 * overwrite an already existing var or not.
 *
 * Return: 0 on success and -1 on error.
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	char **env = environ, **new_env;
	char *newstr = NULL;
	int i;

	newstr = malloc(sizeof(char) * (strlen(name) + strlen(value) + 2));
	if (newstr == NULL)
		return (-1);
	strcpy(newstr, name); /* creating new key=val string */
	strcat(newstr, "=");
	strcat(newstr, value);

	for (i = 0; env[i] != NULL; i++)
	{
		if (strncmp(env[i], name, strlen(name)) == 0)
		{
			if (overwrite == 0)
			{
				free(newstr);
				return (-1);
			}
			env[i] = newstr;
			return (0);
		}
	}
	new_env = malloc(sizeof(char *) * (i + 2));
	for (i = 0; env[i] != NULL; i++)
	{
		new_env[i] = malloc(sizeof(char) * (strlen(env[i]) + 1));
		if (new_env[i] == NULL)
			return (-1);
		strcpy(new_env[i], env[i]);
	}
	new_env[i++] = newstr;
	new_env[i] = NULL;
	environ = new_env;
	return (0);
}
