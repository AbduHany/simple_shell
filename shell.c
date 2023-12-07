#include "shell.h"

/**
 * execute_command - creates a child process and executes command.
 * @args: array of argument strings to command.
 *
 * Return: void.
 */
void execute_command(char **args)
{
	pid_t pid;
	int wstatus;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(args);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve(args[0], args, environ);
		perror("Execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&wstatus);
		_freedouble(args);
	}
}

/**
 * initargs - reads input string from stdin
 * and creats the args string array.
 * Return: double pointer to the args array.
 */
char **initargs(void)
{
	char **args = NULL, *input = NULL;
	size_t size;
	ssize_t readbytes;
	int i;

	readbytes = getline(&input, &size, stdin);
	if (readbytes == -1)
	{
		write(STDOUT_FILENO, "\n", 1);
		free(input);
		exit(EXIT_SUCCESS);
	}
	if (input[0] == '\n') /* input is empty */
	{
		free(input);
		return (NULL);
	}
	for (i = 0; input[i] != '\n';)
		i++;
	input[i] = '\0';
	args = _strtolist(input, ' ');
	if (args == NULL || args[0] == NULL)
	{
		free(input);
		return (NULL);
	}
	free(input);
	return (args);
}

/**
 * interloop - runs interactive REPL loop for the shell.
 * @prog: name of the running shell.
 * Return: void.
 */
void interloop(__attribute__ ((unused)) char *prog)
{
	char **args, *command_name;
	int builtin_flag, found_in_PATH_flag = 0;

	while (1)
	{
		_putstr("($) ");
		args = initargs();
		if (args == NULL || args[0] == NULL)
			continue;
		builtin_flag = built_in(args);
		if (builtin_flag == 1)
		{
			_freedouble(args);
			continue;
		}
		else
		{
			if (access(args[0], X_OK | F_OK) == 0)
			{
				execute_command(args);
				continue;
			}
			command_name = args[0];
			found_in_PATH_flag = find_in_PATH(args);
			if (found_in_PATH_flag == 1)
			{
				execute_command(args);
				continue;
			}
			else
			{
				command_not_found(command_name);
				_freedouble(args);
				continue;
			}
		}
	}
	exit(EXIT_SUCCESS);
}

/**
 * noninter - executes shell in non-interactive mode.
 * @prog: name of the running shell.
 * Return: void.
 */
void noninter(__attribute__ ((unused)) char *prog)
{
	char **args;
	char *command_name;
	int builtin_flag, found_in_PATH_flag = 0;

	args = initargs();
	if (args == NULL || args[0] == NULL)
		exit(EXIT_SUCCESS);
	builtin_flag = built_in(args);
	if (builtin_flag == 1)
		_freedouble(args);

	else
	{
		if (access(args[0], X_OK | F_OK) == 0)
		{
			execute_command(args);
			exit(EXIT_SUCCESS);
		}
		command_name = args[0];
		found_in_PATH_flag = find_in_PATH(args);
		if (found_in_PATH_flag == 1)
		{
			execute_command(args);
			exit(EXIT_SUCCESS);
		}
		else
		{
			command_not_found(command_name);
			_freedouble(args);
			exit(EXIT_SUCCESS);
		}
	}
	exit(EXIT_SUCCESS);
}

/**
 * main - entry point.
 * @argc: number of arguments.
 * @argv: pointer to string array
 * of arguments.
 *
 * Return: 0 on success
 * on error, a different value.
 */
int main(__attribute__ ((unused)) int argc, char **argv)
{
	if (isatty(STDIN_FILENO) && isatty(STDERR_FILENO))
		interloop(argv[0]);
	else
	{
		noninter(argv[0]);
	}
	return (0);
}
