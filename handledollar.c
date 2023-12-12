#include "shell.h"

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
		tmpptr = &args[i][1];
		value = _getenv(tmpptr);
		if (value == NULL)
			continue;
		newarg = _strdup(value);
		if (newarg == NULL)
			continue;
		free(args[i]);
		args[i] = newarg;
	}
}
