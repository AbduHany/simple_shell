#include "shell.h"
/**
 * change_dir - changing dir
 * @dir: the dir to change to
*/
void change_dir(char *dir)
{
	int state;

	state = chdir(dir);
		if (state != 0)
			perror("cd, problem here");
}
/* for: cd*/
/**
 * is_directory - checks if the last item in a path is a dir or not
 * @path: the path of file to be checked
 * Return: non xero if it is not a dir , 0 if it is
*/
int is_directory(const char *path)
{
	struct stat statbuf;

	if (stat(path, &statbuf) != 0) /* assiggn the value to the dcelared struct */
	{
		perror("stat");
		return (-1);
	}

	return (S_ISDIR(statbuf.st_mode));
}
/**
 * print_path - priting a path
 * @tmp: the path to be printed
*/
void print_path(char *tmp)
{
	write(1, tmp, (_strlen(tmp) + 1));
	write(1, "\n",  1);
}

