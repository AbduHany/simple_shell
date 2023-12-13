#include "shell.h"

/**
 * file_not_found - prints the file not found error.
 * @argv: array of argument strings to program.
 *
 * Return: void.
 */
void file_not_found(char **argv)
{
	write(2, argv[0], _strlen(argv[0]));
	write(2, ": 0: Can't open ", 16);
	write(2, argv[1], _strlen(argv[1]));
	write(2, "\n", 1);
}

/**
 * file_not_readable - prints the file not found error.
 * @argv: array of argument strings to program.
 *
 * Return: void.
 */
void file_not_readable(char **argv)
{
	write(2, argv[0], _strlen(argv[0]));
	write(2, ": 0: cannot open ", 17);
	write(2, argv[1], _strlen(argv[1]));
	write(2, ": Permission denied\n", 20);
}
