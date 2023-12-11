#include "shell.h"
/**
 * 
*/
void change_dir(char *dir)
{
	int state;

	state = chdir(dir);
		if (state != 0)
			perror("cd");
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
		