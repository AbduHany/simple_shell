#include "shell.h"
#include <libgen.h>
#include <unistd.h>

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
	char *built_ins[] = {"exit", "env", "cd", "pwd", NULL};

	void (*fucntions[]) (char **argu) = {exit_function, print_env, cd, pwd, NULL};
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
/**
 * cd - chnages current dir
 * @args: the arguments of given command.
 * Return: void
 */
void cd(char **args)
{
	int state;

	state = chdir(args[1]);
	if (state != 0)
		perror("cd:");
}
/**
 * pwd - prints the current dir.
 * @args: the arguments of given command.
 * Return: void
 */
void pwd(__attribute__ ((unused)) char **args)
{
	char *dir_name = malloc(1024);

	if (getcwd(dir_name, 1024) == NULL)
		perror("pwd:");
	write(1, dir_name, strlen(dir_name) + 1);
	_putchar('\n');
	free(dir_name);
}
