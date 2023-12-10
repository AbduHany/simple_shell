#include "shell.h"

/**
 * unset_env - deletes a variable from the environ list.
 * @args: array of arguments in program.
 * @exitstatus: pointer to exitstatus of program.
 *
 * Return: void.
 */
void unset_env(char **args, int *exitstatus)
{
	(void)args;
	(void)exitstatus;
}

/**
 * _unsetenv - deletes the variable name from the environment
 * @name: name string of the variable to be unset.
 * Return: 0 on success and -1 on failure.
 */
int _unsetenv(char *name)
{
	char **env = environ, **new_env;
	int i, j, del_location, del_flag = 0;

	for (i = 0; env[i] != NULL; i++)
	{
		if (strncmp(env[i], name, strlen(name)) == 0)
		{
			del_flag = 1;
			del_location = i;
		}
	}
	if (del_flag == 0)
		return (-1);
	else if (del_flag == 1)
	{
		new_env = malloc(sizeof(char *) * i);
		if (new_env == NULL)
			return (-1);
		for (i = 0, j = 0; env[i] != NULL; i++, j++)
		{
			if (i == del_location)
			{
				i++;
			}
			new_env[j] = malloc(strlen(env[i]) + 1);
			if (new_env[j] == NULL)
				return (-1);
			strcpy(new_env[j], env[i]);
		}
	}
	new_env[j] = NULL;
	_freedouble(environ);
	environ = new_env;
	return (0);
}
