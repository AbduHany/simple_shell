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
	int fd;

	if (access(argv[1], F_OK) == 0)
	{
		if (access(argv[1], R_OK) == 0)
			fd = open(argv[1], O_RDONLY);
		else
		{
			file_not_readable(argv);
			_freedouble(environ);
			exit(2);
		}
	}
	else
	{
		file_not_found(argv);
		_freedouble(environ);
		exit(2);
	}
	return (fd);
}
