#include "shell.h"

/**
 * interloop - runs interactive REPL loop for the shell.
 * @prog: name of the running shell.
 * Return: void.
 */
void interloop(char *prog)
{
	char **args, *input;
	size_t size;
	ssize_t readbytes;
	pid_t pid;
	int i, wstatus;

	while (1)
	{
		input = NULL;
		_putstr("($) ");
		readbytes = getline(&input, &size, stdin);
		if (readbytes == -1)
			break;
		for (i = 0; input[i] != '\n';)
			i++;
		input[i] = '\0';
		args = _strtolist(input);
		pid = fork();
		if (pid == -1)
			exit(EXIT_FAILURE);
		else if (pid == 0)
		{
			execve(args[0], args, environ);
		        perror(prog);
		}
		else
		{
			wait(&wstatus);
		}
		free(input);
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
int main(__attribute__ ((unused)) int argc, char **argv, char **envp)
{
	pid_t pid;
	int status;
	char **new_argv = &argv[1];

	if (isatty(STDIN_FILENO) && isatty(STDERR_FILENO))
		interloop(argv[0]);
	else
	{
		pid = fork();
		if (pid == -1)
		{
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if(execve(new_argv[0], new_argv, envp) == -1)
			{
				perror(argv[0]);
				exit(EXIT_FAILURE);
			}
		}
		wait(&status);
	}
	return (0);
}
