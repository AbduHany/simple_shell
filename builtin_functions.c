#include "shell.h"
#include <libgen.h>
#include <unistd.h>

/**
 * built_in - function that handled the command whose paths are not
 * included int he PATH environment variable
 * @args: the arguments of given command
 * @exitstatus: pointer to the exitstatus of the shell.
 * Return: 1 if the given command was a built in and was excuted,
 * 0 is the given command was not a built in.
 */
int built_in(char **args, int *exitstatus, int linenum, char *prog)
{
	int i = 0;
	int flag = 0;
	char *built_ins[] = {
		"exit", "env", "cd", "pwd", "setenv", "unsetenv", NULL};

	void (*fucntions[]) (char **argu, int *exitstatus, int linenum, char *prog) = {exit_function,
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
 * Return: void.
 */
void exit_function(char **args, int *exitstatus,  int linenum, char *prog)
{
	char status;
	(void)exitstatus;
	if (args[1] != NULL)
	{
		if (args[1][0] == '-')
			illegal_number(args[1], linenum, prog);
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
 * 
 * print_env - prints the current environment variables.
 * @args: the arguments of given command
 * @exitstatus: pointer to the exitstatus of the shell.
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
 *
 * Return: void.
 */
void cd(char **args, int *exitstatus, int linenum, char *prog)
{
	int state;
	char *tmp;
	char *legal_options = "LP@";

	char *dir_name = malloc(1024);

	(void)exitstatus;
	if (getcwd(dir_name, 1024) == NULL) /* get the current dir */
		perror("getcwd:");

	if (args[1] == NULL || (args[1][0] == '~' && args[1][1] == '\0'))/* if the command is cd with no aruguments */
	{
		change_dir(_getenv("HOME"));
		
		state = _setenv("PWD", _getenv("HOME"), 1);
		if (state != 0)
			perror("setenv:");
	}
	else if ((args[1][0]) == '-') /* cd - */
	{
		if (((args[1][1]) != '\0'))
		{
			if (legal_options[0]!= args[1][1] && legal_options[1]!= args[1][1] &&
			legal_options[2]!= args[1][1])
				illegal_option(args[1], linenum, prog);
		}
		else
		{
			if (_getenv("OLDPWD") != NULL)
			{	
				change_dir(_getenv("OLDPWD"));
				tmp = _strdup(_getenv("OLDPWD"));
				print_path(tmp);

				state = _setenv("OLDPWD", _getenv("PWD"), 1);
				
				if (state != 0)
					perror("setenv:");
				state = _setenv("PWD", tmp, 1);
			
				if (state != 0)
					perror("setenv:");
				free(tmp);		
			}
			else
			{
				state = _setenv("OLDPWD", _getenv("PWD"), 0);
				if (state != 0)
					perror("setenv:");
			}
		}	
	}
	else
	{
		if (access(args[1], F_OK) == 0)
		{
			if (is_directory(args[1]) == 0)
				not_dir(args[1], linenum, prog);
			else
			{
				state = chdir(args[1]); /* change the dir to the given arg */
				if (state != 0)
					perror("cd");
				else
				{
					if (_getenv("OLDPWD") == NULL)
						_setenv("OLDPWD", dir_name, 0); /* dir_name is the dir before chdir */
					else
						_setenv("OLDPWD", dir_name, 1);

					if (getcwd(dir_name, 1024) == NULL) /* dir name here is the current dir */
						perror("getcwd:");

					state = _setenv("PWD", dir_name, 1); /* set the current dir to dir_name */
					if (state != 0)
						perror("setenv:");
				}
			}
		}
		else
			not_dir(args[1], linenum, prog);
	}
	free(dir_name);
}
/**
 * pwd - prints the current dir.
 * @args: the arguments of given command.
 * @exitstatus: pointer to the exitstatus of the shell.
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
