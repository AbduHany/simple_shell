#include "shell.h"


/* for: cd*/
/**
 * switch_current_dir - switched between oldpwd and pwd
 * when using 'cd -'
*/
void switch_current_dir(void)
{
	int state;
	char *tmp;

	if (_getenv("OLDPWD") != NULL)
	{
		change_dir(_getenv("OLDPWD"));
		tmp = _strdup(_getenv("OLDPWD"));
		print_path(tmp);

		state = _setenv("OLDPWD", _getenv("PWD"), 1);

		if (state != 0)
			perror("setenv:");
		state = _setenv("PWD", tmp, 1);

		if (state != 0)
			perror("setenv:");
		free(tmp);
	}
	else
	{
		state = _setenv("OLDPWD", _getenv("PWD"), 0);
		if (state != 0)
			perror("setenv:");
	}
}

/**
 * go_to_home - goes to path in the $HOME env var
*/
void go_to_home(void)
{
	int state;

	if (_getenv("HOME") == NULL)
		return;

	change_dir(_getenv("HOME"));

	state = _setenv("PWD", _getenv("HOME"), 1);
	if (state != 0)
		perror("setenv:");
}
/**
 * change_to_new_dir - goed to dir specified after cd
 * @exitstatus: the exit status to exit with throughg out the program
 * @dir_name: current dir name
 * @linenum: number of line of commmand
 * @prog: name of the shell
 * @args: the argumnets of the command
*/
void change_to_new_dir(int *exitstatus, char *dir_name,
int linenum, char *prog, char **args)
{
	int state;

	if (access(args[1], F_OK) == 0)
	{
		if (is_directory(args[1]) == 0) /* the igven path it not a dir*/
		{
			not_dir(args[1], linenum, prog);
			*exitstatus = 1;
		}
		else
		{
			if (access(args[1], X_OK) == 0)
			{
				state = chdir(args[1]); /* change the dir to the given arg */
				if (state != 0)
					perror("cd");
			else
			{
				if (_getenv("OLDPWD") == NULL)
					_setenv("OLDPWD", dir_name, 0); /* dir_name is the dir before chdir */
				else
					_setenv("OLDPWD", dir_name, 1);
				if (getcwd(dir_name, 1024) == NULL) /* dir name here is the current dir */
					perror("getcwd:");
				_setenv("PWD", dir_name, 1); /* set the current dir to dir_name */
			}
			}
			else
			{
				permissiondenied(args[1], linenum, prog);
				*exitstatus = 1;
			}
		}
	}
	else
	{
		not_dir(args[1], linenum, prog); /* the given dir does not exist */
		*exitstatus = 1;
	}
}
