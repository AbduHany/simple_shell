#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

extern char **environ;

char* _getenv(char *var_name)
{
    char **envVar;

    /* Search for the environment variable directly in the environ array */
    for (envVar = environ; *envVar != NULL; ++envVar)
    {
        if (_strncmp(*envVar, var_name, _strlen(var_name)) == 0 && (*envVar)[_strlen(var_name)] == '=')
        {
            /*Found the environment variable */
            return (*envVar + _strlen(var_name) + 1); /* +1 to skip the '=' character */
        }
    }

    /* Environment variable not found */
    return NULL;
}


/* for testing 
int main()
{
    char *var_name = "PATH";
    char *value = _getenv(var_name);

    if (value != NULL) {
        printf("Value of %s: %s\n", var_name, value);
    } else {
        printf("Environment variable %s not found.\n", var_name);
    }

    return 0;
}
*/