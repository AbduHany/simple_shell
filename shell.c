#include "shell.h"
int find_in_PATH(char **args)
{
	pathdirs_t *list_ptr;
	int flag = 0;
	char *full_path;

	list_ptr = create_path_list();
	
	while (list_ptr != NULL) 
	{
		full_path = malloc(_strlen((list_ptr->dir)) + _strlen(args[0]) + 1 + 1);
		_strcpy(full_path, (list_ptr->dir));
		full_path = strcat(full_path, "/");
		full_path = strcat(full_path, args[0]);


		if (access(full_path, X_OK | F_OK) == 0)
		{
			free(args[0]);
			args[0] = full_path;
			flag = 1;
			break;
		}
		free(full_path);
		list_ptr =list_ptr->next;
	}
	return (flag);
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
		exit(EXIT_FAILURE);
	if (input == NULL) /* input is empty */
		return (NULL);
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
	char *command_name;
	pid_t pid;
	int wstatus;
	int builtin_flag;
	int found_in_PATH_flag = 0;

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
			command_name = args[0]; 
			found_in_PATH_flag = find_in_PATH(args);
		}
		/*if (access(args[0], X_OK | F_OK) == -1)
		{
			perror("Access");
			continue;
		}*/

		if (found_in_PATH_flag == 1)
		{
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
		else
		{
			command_not_found(command_name);
			_freedouble(args);
			continue;
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
