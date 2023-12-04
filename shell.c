#include "shell.h"
/**
 * built_ins - function that handled the command whose paths are not
 * included int he PATH environment variable
*/
void built_in(char **args)
{
	int i = 0;

	char *built_ins[] = {"exit", "cd", NULL};
	void (*fucntions[]) () = {exit_function};

	while (built_ins[i] != NULL)
	{
		if (_strcmp(args[0], built_ins[i]) == 0)
		{
			(*fucntions[i])();
			break;
		}
		i++;
	}
}
/**
 * interloop - runs interactive REPL loop for the shell.
 * @prog: name of the running shell.
 * Return: void.
 */
void interloop(__attribute__ ((unused)) char *prog)
{
	char **args, *input;
	size_t size;
	ssize_t readbytes;
	pid_t pid;
	int i, wstatus;

	(void)prog;
	while (1)
	{
		input = NULL;
		args = NULL;
		_putstr("($) ");
		readbytes = getline(&input, &size, stdin);
		if (readbytes == -1)
			exit(EXIT_FAILURE);
		for (i = 0; input[i] != '\n';)
		i++;
		input[i] = '\0';
		args = _strtolist(input);
		free(input);
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
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			execve(args[0], args, environ);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(&wstatus);
			_freedouble(args);
		}

		_freedouble(args);
	}
	_freedouble(args);
	exit(EXIT_SUCCESS);
}

/**
 * noninter - executes shell in non-interactive mode.
 * @prog: name of the running shell.
 * Return: void.
 */
void noninter(char *prog)
{
	char *input = NULL, **args;
	size_t size;
	ssize_t readbytes;
	pid_t pid;
	int wstatus;
	int i;

	(void)prog;
	readbytes = getline(&input, &size, stdin);
	if (readbytes == -1)
	{
		perror("getline");
		exit(EXIT_FAILURE);
	}
	for (i = 0; input[i] != '\n';)
		i++;
	 input[i] = '\0';
	args = _strtolist(input);
	built_in(args);
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
		wait(&wstatus);
	free(input);
	_freedouble(args);
	exit(EXIT_SUCCESS);
}

/**
 * noninter - executes shell in non-interactive mode.
 * @prog: name of the running shell.
 * Return: void.
 */
void noninter(__attribute__ ((unused)) char *prog)
{
	char *input = NULL, **args = NULL;
	size_t size;
	ssize_t readbytes;
	pid_t pid;
	int wstatus, i;

	readbytes = getline(&input, &size, stdin);
	if (readbytes == -1)
	{
		perror("getline");
		exit(EXIT_FAILURE);
	}
	for (i = 0; input[i] != '\n';)
		i++;
	input[i] = '\0';
	args = _strtolist(input);
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
		wait(&wstatus);
	free(input);
	_freedouble(args);
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
	if (isatty(STDIN_FILENO)) /* interactive mode */
		interloop(argv[0]);
	else /* non-interactive mode */
		noninter(argv[0]);
	return (0);
}
