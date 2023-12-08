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
char *_strcpy(char *dest, const char *src);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, size_t n);
char* _strcat(char *s1, char *s2);
void _putinterr(int linenum);

/* environment variable functions */
char *_getenv(char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);

/* built in commands */
void print_env(char **args);
void exit_function(char **args);
int built_in(char **args);
void cd(char **args);
void pwd(__attribute__ ((unused)) char **args);

/* memory functions */
void _freedouble(char **s);
void _freepathlist(pathdirs_t *head);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* shell.c main functions */
char **initargs(int *linenum, int *exitstatus);
void command_not_found(char *command_name, int linenum, char *prog);
<<<<<<< HEAD
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void execute_command(char **args);
=======
ssize_t _getline(char **input, size_t *len, FILE *stream);
void execute_command(char **args, int *exitstatus);
>>>>>>> 8a877985fc9e8406e3a6daec7575456b1e75e994
int find_in_PATH(char **args);
pathdirs_t *create_path_list(void);

#endif
