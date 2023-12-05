#include "shell.h"

/**
 * command_not_found - prints custom error message when command
 * can't be found in PATH variable
 * @command_name: the command name that was not found
*/
void command_not_found(char *command_name)
{
	char **buffer;
	int i = 0;

	buffer = malloc(sizeof(char *) * 4);
	buffer[0] = command_name;
	buffer[1] = ":";
	buffer[2] = "command not found\n";
	buffer[3] = NULL;

	while (buffer[i] != NULL)
	{
		write(2, buffer[i], _strlen(buffer[i]));
		i++;
	}
	free(buffer);
}
