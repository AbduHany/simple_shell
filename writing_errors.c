#include "shell.h"

/**
 * command_not_found - prints custom error message when command
 * can't be found in PATH variable
 * @command_name: the command name that was not found.
 * @linenum: number of line where error was encountered.
 * @prog: name of the running shell program.
*/
void command_not_found(char *command_name, int linenum, char *prog)
{
	write(2, prog, _strlen(prog));
	write(2, ": ", 2);
	_putinterr(linenum);
	write(2, ": ", 2);
	write(2, command_name, _strlen(command_name));
	write(2, ": not found\n", 12);
}

/**
 * permissiondenied - prints the permission denied message to
 * stderr.
 * @command_name: the command name that was not found.
 * @linenum: number of line where error was encountered.
 * @prog: name of the running shell program.
 */
void permissiondenied(char *command_name, int linenum, char *prog)
{
	write(2, prog, _strlen(prog));
	write(2, ": ", 2);
	_putinterr(linenum);
	write(2, ": ", 2);
	write(2, command_name, _strlen(command_name));
	write(2, ": Permission denied\n", 20);
}


/* for: exit*/
/**
 * 
*/
void illegal_number(char *x, int linenum, char *prog)
{
	write(2, prog, _strlen(prog));
	write(2, ": ", 2);
	_putinterr(linenum);
	write(2, ": ", 2);
	write(2, "exit", _strlen("exit"));
	write(2, ": ", 2);
	write(2, "Illegal number: ", _strlen("Illegal number: "));
	write(2, x, _strlen(x));
	write(2, "\n", 1);
}