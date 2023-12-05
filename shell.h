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
char **_strtolist(char *str);
int _strlen(char *str);
char *_strcpy(char *dest, const char *src);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, size_t n);

/* environment variable functions */
char *_getenv(char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);

/* built in commands */
void print_env(char **args);
void exit_function(char **args);
int built_in(char **args);

/* memory functions */
void _freedouble(char **s);
void _freepathlist(pathdirs_t *head);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* shell.c main functions */
char **_strtolist(char *str);
char **initargs(void);
void command_not_found(char *command_name);
ssize_t _getline(char **input, size_t *len, FILE *stream);
void execute_command(char **args);
int find_in_PATH(char **args)
pathdirs_t *create_path_list(void);

#endif
