#include "shell.h"
#include <libgen.h>
#include <unistd.h>

/**
 * built_in - function that handled the command whose paths are not
 * included int he PATH environment variable
 * @args: the arguments of given command
 * @exitstatus: pointer to the exitstatus of the shell.
 * @linenum: the number off the line of hte command
 * @prog: the name of the running shell
 * Return: 1 if the given command was a built in and was excuted,
 * 0 is the given command was not a built in.
 */
int built_in(char **args, int *exitstatus, int linenum, char *prog)
{
	int i = 0;
	int flag = 0;
	char *built_ins[] = {
		"exit", "env", "cd", "pwd", "setenv", "unsetenv", NULL};

	void (*fucntions[]) (char **argu, int *exitstatus,
	 int linenum, char *prog) = {exit_function,
		print_env, cd, pwd, set_env, unset_env, NULL};

	while (built_ins[i] != NULL)
	{
		if (_strcmp(args[0], built_ins[i]) == 0)
		{
			(*fucntions[i])(args, exitstatus, linenum, prog);
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
 * @exitstatus: pointer to the exitstatus of the shell.
 * @linenum: the number off the line of hte command
 * @prog: the name of the running shell
 * Return: void.
 */
void exit_function(char **args, int *exitstatus,  int linenum, char *prog)
{
	char status;
	(void)exitstatus;
	if (args[1] != NULL)
	{
		if (args[1][0] == '-' || (_hasalpha(args[1]) == 1))
		{
			illegal_number(args[1], linenum, prog);
			*exitstatus = 2;
		}
		else
		{
			status = _atoi(args[1]);
			_freedouble(environ);
			_freedouble(args);
			exit(status);
		}
	}
	else
	{
		_freedouble(environ);
		_freedouble(args);
		exit(*exitstatus);
	}
}
/**
 * print_env - prints the current environment variables.
 * @args: the arguments of given command
 * @exitstatus: pointer to the exitstatus of the shell.
 * @linenum: the number off the line of hte command
 * @prog: the name of the running shell
 * Return: void
 */
void print_env(char **args, int *exitstatus, int linenum, char *prog)
{
	int i = 0;

	(void)linenum;
	(void)prog;
	(void)exitstatus;
	(void)args;
	while (environ[i] != NULL)
	{
		_putstr(environ[i]);
		_putchar('\n');
		i++;
	}
}


/**
 * cd - changes current dir.
 * @args: the arguments of given command.
 * @exitstatus: pointer to the exitstatus of the shell.
 * @linenum: the number off the line of hte command
 * @prog: the name of the running shell
 * Return: void.
 */
void cd(char **args, int *exitstatus, int linenum, char *prog)
{
	char *legal_options = "LP@";
	char *dir_name = malloc(1024);

	(void)exitstatus;
	if (getcwd(dir_name, 1024) == NULL) /* get the current dir */
		perror("getcwd:");

	if (args[1] == NULL || (args[1][0] == '~' && args[1][1] == '\0'))
		go_to_home();

	else if ((args[1][0]) == '-') /* cd - */
	{
		if (((args[1][1]) != '\0'))
		{
			if (legal_options[0] != args[1][1] && legal_options[1] != args[1][1] &&
			legal_options[2] != args[1][1])
			{
				illegal_option(args[1], linenum, prog);
				*exitstatus = 2;
			}
		}
		else
			switch_current_dir();
	}
	else /* normal path is provided */
		change_to_new_dir(exitstatus, dir_name, linenum, prog, args);

	free(dir_name);
}
/**
 * pwd - prints the current dir.
 * @args: the arguments of given command.
 * @exitstatus: pointer to the exitstatus of the shell.
 * @linenum: the number off the line of hte command
 * @prog: the name of the running shell
 * Return: void
 */
void pwd(char **args, int *exitstatus,  int linenum, char *prog)
{
	char *dir_name = malloc(1024);

	(void)linenum;
	(void)prog;
	(void)args;
	(void)exitstatus;
	if (getcwd(dir_name, 1024) == NULL)
		perror("pwd:");
	write(1, dir_name, _strlen(dir_name) + 1);
	_putchar('\n');
	free(dir_name);
}
