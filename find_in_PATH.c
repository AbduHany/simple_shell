#include "shell.h"

/**
 * find_in_PATH - checks if given command is found in the
 * PATH variable.
 * @args: array of arguments whose first argument is to be checked.
 * @exitstatus: pointer to the program's exitstatus.
 * @prog: name of the shell.
 * @linenum: number of current line in shell.
 *
 * Return: 1 if command was found in PATH variable, 0 if otherwise.
 */
int find_in_PATH(char **args, int *exitstatus, char *prog, int linenum)
{
	pathdirs_t *list_ptr = create_path_list(), *head;
	int flag = 0;
	char *full_path;

	head = list_ptr;
	while (list_ptr != NULL)
	{
		full_path = malloc(_strlen((list_ptr->dir)) + _strlen(args[0]) + 1 + 1);
		_strcpy(full_path, (list_ptr->dir));
		full_path = _strcat(full_path, "/");
		full_path = _strcat(full_path, args[0]);
		if (access(full_path, F_OK) == 0)
		{
			if (access(full_path, X_OK) == 0)
			{
				free(args[0]);
				args[0] = full_path;
				execute_command(args, exitstatus);
				flag = 1;
				break;
			}
			else
			{
				permissiondenied(args[0], linenum, prog);
				*exitstatus = 126;
				free(full_path);
				_freepathlist(head);
				return (0);
			}
		}
		free(full_path);
		list_ptr = list_ptr->next;
	}
	if (flag == 0)
	{
		command_not_found(args[0], linenum, prog);
		*exitstatus = 127;
	}
	_freepathlist(head);
	return (flag);
}
