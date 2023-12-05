#include "shell.h"

/**
 * built_in - function that handled the command whose paths are not
 * included int he PATH environment variable
 * @args: the arguments of given command
 * Return: 1 if the given command was a built in and was excuted,
 * 0 is the given command was not a built in.
*/
int built_in(char **args)
{
	int i = 0;
	int flag = 0;
	char *built_ins[] = {"exit", "env", NULL};

	void (*fucntions[]) (char **argu) = {exit_function, print_env, NULL};
	while (built_ins[i] != NULL)
	{
		if (_strcmp(args[0], built_ins[i]) == 0)
		{
			(*fucntions[i])(args);
			flag = 1;
			break;
		}
		i++;
	}
	return (flag);
}

/**
 * exit_function - exits the shell.
 * @args: the arguments of given command
 * Return: void.
 */
void exit_function(char **args)
{
	_freedouble(args);
	exit(EXIT_SUCCESS);
}


/**
 * print_env - prints the current environment variables.
 * @args: the arguments of given command.
 * Return: void
 */
void print_env(char **args)
{
	int i = 0;

	(void)args;
	while (environ[i] != NULL)
	{
		_putstr(environ[i]);
		_putchar('\n');
		i++;
	}
}
