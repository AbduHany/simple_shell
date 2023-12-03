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

int _putchar(char c);
int _putstr(char *str);
char **_strtolist(char *str);
int _strlen(char *str);
char *_strcpy(char *dest, const char *src);
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
pathdirs_t *create_path_list(void);
void _freedouble(char **s);

#endif
