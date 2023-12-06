#include "shell.h"

/**
 * find_in_PATH - checks if given command is found in the
 * PATH variable.
 * @args: array of arguments whose first argument is to be checked.
 *
 * Return: 1 if command was found in PATH variable, 0 if otherwise.
 */
int find_in_PATH(char **args)
{
	pathdirs_t *list_ptr, *head;
	int flag = 0;
	char *full_path;

	list_ptr = create_path_list();
	head = list_ptr;
	while (list_ptr != NULL)
	{
		full_path = malloc(_strlen((list_ptr->dir)) + _strlen(args[0]) + 1 + 1);
		_strcpy(full_path, (list_ptr->dir));
		full_path = _strcat(full_path, "/");
		full_path = _strcat(full_path, args[0]);
		if (access(full_path, X_OK | F_OK) == 0)
		{
			free(args[0]);
			args[0] = full_path;
			flag = 1;
			break;
		}
		free(full_path);
		list_ptr = list_ptr->next;
	}
	_freepathlist(head);
	return (flag);
}
