#include "shell.h"

/**
 * _readfile - attempts to open file and returns the fd to the
 * opened file.
 * @argv: array of argument strings.
 * Return: filedescriptor number if successful
 * -1 if failed.
 */
int _readfile(char **argv)
{
	int fd = STDIN_FILENO;

	if (access(argv[1], R_OK) != -1)
	{
		fd = open(argv[1], O_RDONLY);
	}
	else
	{
		file_not_found(argv);
		_freedouble(environ);
		exit(127);
	}
	return (fd);
}
