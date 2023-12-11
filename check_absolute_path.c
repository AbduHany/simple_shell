#include "shell.h"

/**
 * check_absolute_path - checks if the absolute path exists and is executable.
 * @args: array of argument strings.
 * @exitstatus: pointer to the program's exitstatus.
 * @prog: name of the shell.
 * @linenum: number of current line in shell.
 *
 * Return: 1 if executes command.
 * 0 if error encountered.
 */
int check_absolute_path(char **args, int *exitstatus, char *prog, int linenum)
{
	if (args[0][0] == '.' || args[0][0] == '/')
	{
		if (access(args[0], F_OK) == 0)
		{
			if (access(args[0], X_OK) == 0)
			{
				execute_command(args, exitstatus);
				return (1);
			}
			permissiondenied(args[0], linenum, prog);
			*exitstatus = 126;
			_freedouble(args);
			return (0);
		}
	}
	return (0);
}
