#include "shell.h"
/**
 * 
*/
void change_dir(char *dir)
{
	int state;

	state = chdir(dir);
		if (state != 0)
			perror("cd, problem here");
}
/**
 * 
*/
void set_pwd(char* dir)
{
    int state;

    state = _setenv("PWD", dir, 1);
    if (state != 0)
            perror("setenv:");
}
/**
 * 
*/
void set_oldpwd(char* dir)
{
    int state;

    state = _setenv("OLDPWD", dir, 0);
    if (state != 0)
            perror("setenv:");
}
/**
 * 
*/
void set_oldpwd_overwrite(char* dir)
{
    int state;

    state = _setenv("OLDPWD", dir, 1);
    if (state != 0)
            perror("setenv:");
}
/**
 * 
*/

int is_directory(const char *path)
{
    struct stat statbuf;

    if (stat(path, &statbuf) != 0) /* assiggn the value to the dcelared struct */
    {
        perror("stat");
        return -1;
    }

    return (S_ISDIR(statbuf.st_mode));
}
/**
 * 
*/
void print_path(char *tmp)
{
    write(1, tmp, (_strlen(tmp) + 1));
	write(1, "\n",  1);
}

