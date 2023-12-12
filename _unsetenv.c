#include "shell.h"

/**
 * unset_env - deletes a variable from the environ list.
 * @args: array of arguments in program.
 * @exitstatus: pointer to exitstatus of program.
 * @linenum: the number of the line of the command
 * @prog: the name of the shell
 * Return: void.
 */
void unset_env(char **args, int *exitstatus, int linenum, char *prog)
{
	int i = 0, ret;
	char *var;

	(void) linenum;
	(void)exitstatus;
	(void)prog;
	if (args[1] == NULL)
	{
		perror("unsetenv: ");
		return;
	}
	var = args[1];
	while (args[1][i] != '\0')
	{
		if (args[1][i] == '=')
			return;
		i++;
	}
	ret = _unsetenv(var);
	if (ret != 0)
	{
		perror("unsetenv: ");
		return;
	}
}

/**
 * shrinkenv - shrinks the env list by 1 and deletes the
 * variable at del_location.
 * @size: new size of the env list.
 * @del_location: the location of the var to be deleted.
 *
 * Return: array of string to the env list.
 */
char **shrinkenv(int size, int del_location)
{
	char **new_env, **env = environ;
	int i, j, k;

	new_env = malloc(sizeof(char *) * size);
	if (new_env == NULL)
		return (NULL);
	for (i = 0, j = 0; env[i] != NULL; i++, j++)
	{
		if (i == del_location)
		{
			i++;
		}
		if (env[i] == NULL)
			break;
		new_env[j] = malloc(strlen(env[i]) + 1);
		if (new_env[j] == NULL)
		{
			for (k = j - 1; k >= 0; k--)
				free(new_env[k]);
			free(new_env);
			return (NULL);
		}
		strcpy(new_env[j], env[i]);
	}
	new_env[j] = NULL;
	return (new_env);
}

/**
 * _unsetenv - deletes the variable name from the environment
 * @name: name string of the variable to be unset.
 * Return: 0 on success and -1 on failure.
 */
int _unsetenv(char *name)
{
	char **env = environ, **new_env;
	int i, j, del_location, del_flag = 0, varlen, size;

	for (i = 0; env[i] != NULL; i++)
	{
		for (j = 0, varlen = 0; env[i][j] != '='; j++)
			varlen++;
		if (_strlen(name) == varlen)
		{
			if (_strncmp(name, env[i], varlen) == 0)
			{
				del_flag = 1;
				del_location = i;
			}
		}
	}
	if (del_flag == 0)
		return (-1);
	size = i;
	new_env = shrinkenv(size, del_location);
	if (new_env == NULL)
		return (-1);
	_freedouble(environ);
	environ = new_env;
	return (0);
}
