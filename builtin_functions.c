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
 * exit_function - exits the shell.
 * Return: void.
 */
void exit_function(void)
{
	exit(EXIT_SUCCESS);
}
