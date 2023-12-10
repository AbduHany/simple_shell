#include "shell.h"

/**
 * set_env - adds or updates and existing environment variable.
 * @args: array of strings in program.
 * @exitstatus: pointer to the exitstatus of the program.
 *
 * Retrun: void
 */
void set_env(char **args, int *exitstatus)
{
	char *var, *val;

	(void)exitstatus;
	if (args[1] == NULL)
	{
		perror("setenv: ");
		return;
	}
	else if (args[1] == NULL)
	{
		perror("setenv: ");
		return;
	}
	var = args[1];
	val = args[2];
	_setenv(var, val, 1);
}

/**
 * _setenv - changes or adds an environment variable
 * @name: name string of the newly added var.
 * @value: value string to be added to name var.
 * @overwrite: a flag that determines whether to
 * overwrite an already existing var or not.
 *
 * Return: 0 on success and -1 on error.
 */
int _setenv(char *name, char *value, int overwrite)
{
	char **env = environ, **new_env;
	char *newstr = NULL;
	int i;

	newstr = malloc(sizeof(char) * (_strlen(name) + _strlen(value) + 2));
	if (newstr == NULL)
		return (-1);
	_strcpy(newstr, name); /* creating new key=val string */
	_strcat(newstr, "=");
	_strcat(newstr, value);

	for (i = 0; env[i] != NULL; i++)
	{
		if (_strncmp(env[i], name, _strlen(name)) == 0)
		{
			if (overwrite == 0)
			{
				free(newstr);
				return (-1);
			}
			free(env[i]);
			env[i] = newstr;
			return (0);
		}
	}
	new_env = malloc(sizeof(char *) * (i + 2));
	for (i = 0; env[i] != NULL; i++)
	{
		new_env[i] = malloc(sizeof(char) * (_strlen(env[i]) + 1));
		if (new_env[i] == NULL)
			return (-1);
		_strcpy(new_env[i], env[i]);
	}
	new_env[i++] = newstr;
	new_env[i] = NULL;
	_freedouble(environ);
	environ = new_env;
	return (0);
}
