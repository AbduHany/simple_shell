#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/resource.h>
#include <sys/time.h>

extern char **environ;

/**
 * struct pathdirs - a struct containing directories
 * in PATH variable.
 * @dir: first member and has string to a single directory
 * in PATH.
 * @next: pointer to the next struct pathdir in the linked
 * list.
 */
typedef struct pathdirs
{
	char *dir;
	struct pathdirs *next;
} pathdirs_t;


/* string functions */
int _putchar(char c);
int _putstr(char *str);
char **_strtolist(char *str, char delim);
int _strlen(char *str);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, size_t n);
char* _strcat(char *s1, char *s2);
void _putinterr(int linenum);
int _atoi(char *s);
char* _strdup(char *str);

/* environment variable functions */
char *_getenv(char *name);
int _setenv(char *name, char *value, int overwrite);
int _unsetenv(char *name);

/* built in commands */
void print_env(char **args,  int *exitstatus);
void exit_function(char **args,  int *exitstatus);
int built_in(char **args,  int *exitstatus);
void cd(char **args,  int *exitstatus);
void pwd(char **args,  int *exitstatus);
void set_env(char **args, int *exitstatus);
void unset_env(char **args, int *exitstatus);

/* built in helpers*/
void change_dir(char *dir);
void set_pwd(char* dir);
void set_oldpwd(char* dir);
void set_oldpwd_overwrite(char* dir);
int is_directory(const char *path);
void illegal_number(char *x, int linenum, char *prog);

/* memory functions */
void _freedouble(char **s);
void _freepathlist(pathdirs_t *head);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* shell.c main functions */
char **initargs(int *linenum, int *exitstatus);
void command_not_found(char *command_name, int linenum, char *prog);
void permissiondenied(char *command_name, int linenum, char *prog);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void execute_command(char **args, int *exitstatus);
int check_absolute_path(char **args, int *exitstatus, char *prog, int linenum);
int find_in_PATH(char **args);
pathdirs_t *create_path_list(void);
char **initenv(void);

#endif
