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
 * handledollar - handles dollar sign variable and replaces the variables
 * with their corresponding values.
 * @args: pointer to array of argument strings to be executed.
 * @exitstatus: pointer to the exitstatus of the program.
 * Return: void.
 */
void handledollar(char **args, int *exitstatus)
{
	int i, exit;
	char *tmpptr = NULL, *value, *newarg;
	pid_t pid;

	if (args == NULL)
		return;
	for (i = 0; args[i] != NULL; i++)
	{
		newarg = NULL;
		if (args[i][0] == '$' && args[i][1] == '$' && args[i][2] == '\0')
		{
			pid = getpid();
			newarg = _itoa(pid);
			if (!newarg)
				continue;
			free(args[i]);
			args[i] = newarg;
			continue;
		}
		else if (args[i][0] == '$' && args[i][1] == '?' && args[i][2] == '\0')
		{
			exit = *exitstatus;
			newarg = _itoa(exit);
			if (!newarg)
				continue;
			free(args[i]);
			args[i] = newarg;
			continue;
		}
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
