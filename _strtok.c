#include "shell.h"
/**
 * _strtok -  tokenizes a string using delimeters as a perator
 * 
*/
char** _strtok(char *str, char delimeter)
{
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] == delimeter)
        {
            i++;
            while (str[i] == delimeter)
                i++;
            
            
            
            
        }
        
    }
    
}