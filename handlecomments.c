#include "shell.h"

/**
 * handlecomments - handles comments prefixed with '#' character.
 * @args: pointer to array of argument strings to be executed.
 * @exitstatus: pointer to the exitstatus of the program.
 * Return: void.
 */
void handlecomments(char **args, int *exitstatus)
{
	int i, j;

	(void)exitstatus;
	if (args == NULL)
		return;
	for (i = 0; args[i] != NULL; i++)
	{
		if (args[i][0] == '#')
		{
			j = i + 1;
			while (args[j] != NULL)
			{
				free(args[j]);
				j++;
			}
			free(args[i]);
			args[i] = NULL;
			break;
		}
	}
}
