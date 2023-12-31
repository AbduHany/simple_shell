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
 * illegal_number - when exit takes a invalid argument
 * @x: the invalid argument as a string
 * @linenum: the number of the line of the exit command
 * @prog: the name of the current shell
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

/* for: cd*/
/**
 * illegal_option - when cd takes an invalid argument
 * @x: the invalid argument as a string
 * @linenum: the number of the line of the exit command
 * @prog: the name of the current shell
*/
void illegal_option(char *x, int linenum, char *prog)
{
	write(2, prog, _strlen(prog));
	write(2, ": ", 2);
	_putinterr(linenum);
	write(2, ": ", 2);
	write(2, "cd", _strlen("cd"));
	write(2, ": ", 2);
	write(2, "Illegal option: ", _strlen("Illegal option: "));
	write(2, x, _strlen(x));
	write(2, "\n", 1);
}
/**
 * not_dir - whend the arguument following cd is not a dir
 * @x: the invalid argument as a string
 * @linenum: the number of the line of the exit command
 * @prog: the name of the current shell
*/
void not_dir(char *x, int linenum, char *prog)
{
	write(2, prog, _strlen(prog));
	write(2, ": ", 2);
	_putinterr(linenum);
	write(2, ": ", 2);
	write(2, "cd", _strlen("cd"));
	write(2, ": ", 2);
	write(2, "can't cd to ", _strlen("can't cd to "));
	write(2, x, _strlen(x));
	write(2, "\n", 1);
}
