#include "shell.h"

/**
 * skiponearg - skips the argument that has a $ and no corresponding
 * variable.
 * @arg: adress of pointer to argument to be skipped.
 * Return: void.
 */
void skiponearg(char **arg)
{
	int i;

	free(arg[0]);
	for (i = 0;; i++)
	{
		if (arg[i + 1] == NULL)
		{
			arg[i] = NULL;
			break;
		}
		arg[i] = arg[i + 1];
	}
}

/**
 * replaceexit - replaces an argument with exit status.
 * @args: pointer to array of argument string to be executed.
 * @exitstatus: pointer to the exitstatus of the program.
 * Return: void.
 */
void replaceexit(char **args, int *exitstatus)
{
	int exitint;
	char *newarg;

	exitint = *exitstatus;
	newarg = _itoa(exitint);
	if (!newarg)
		return;
	free(*args);
	*args = newarg;
}

/**
 * replacepid - replaces an argument with its pid.
 * @args: pointer to array of argument string to be executed.
 * @exitstatus: pointer to the exitstatus of the program.
 * Return: void.
 */
void replacepid(char **args, int *exitstatus)
{
	pid_t pid;
	char *newarg;

	(void)exitstatus;
	pid = getpid();
	newarg = _itoa(pid);
	if (!newarg)
		return;
	free(*args);
	*args = newarg;
}

/**
 * handledollar - handles dollar sign variable and replaces the variables
 * with their corresponding values.
 * @args: pointer to array of argument strings to be executed.
 * @exitstatus: pointer to the exitstatus of the program.
 * Return: void.
 */
void handledollar(char **args, int *exitstatus)
{
	int i;
	char *tmpptr = NULL, *value, *newarg;

	if (args == NULL)
		return;
	for (i = 0; args[i] != NULL; i++)
	{
		newarg = NULL;
		if (args[i][0] == '$' && args[i][1] == '$' && args[i][2] == '\0')
			replacepid(&args[i], exitstatus);
		else if (args[i][0] == '$' && args[i][1] == '?' && args[i][2] == '\0')
			replaceexit(&args[i], exitstatus);
		else if (args[i][0] == '$' && args[i][1] != '\0')
		{
			tmpptr = &args[i][1];
			value = _getenv(tmpptr);
			if (value == NULL)
			{
				skiponearg(&args[i]);
				continue;
			}
			newarg = _strdup(value);
			if (newarg == NULL)
				continue;
			free(args[i]);
			args[i] = newarg;
		}
	}
}
