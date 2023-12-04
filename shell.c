#include "shell.h"

/**
 * initargs - reads input string from stdin
 * and creats the args string array.
 * Return: double pointer to the args array.
 */
char **initargs(void)
{
	char **args, *input;
	size_t size;
	ssize_t readbytes;
	int i;

	input = NULL;
	args = NULL;
	readbytes = getline(&input, &size, stdin);
	if (readbytes == -1)
		exit(EXIT_FAILURE);

	for (i = 0; input[i] != '\n';)
		i++;
	input[i] = '\0';
	args = _strtolist(input);
	if (args == NULL || args[0] == NULL)
		return (NULL);
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
	char **args;
	pid_t pid;
	int wstatus;

	while (1)
	{
		_putstr("($) ");
		args = initargs();
		if (args == NULL || args[0] == NULL)
			continue;
		built_in(args);
		if (access(args[0], X_OK | F_OK) == -1)
		{
			perror("Access");
			continue;  /* Skip to the next iteration of the loop */
		}
		pid = fork();
		if (pid == -1)
		{
			perror("Fork");
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
	pid_t pid;
	int wstatus;

	args = initargs();
	built_in(args);
	if (access(args[0], X_OK | F_OK) == -1)
	{
		perror("access");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		perror(prog);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve(args[0], args, environ);
		perror(prog);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&wstatus);
		_freedouble(args);
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
