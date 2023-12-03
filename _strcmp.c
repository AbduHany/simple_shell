#include "shell.h"
/**
 * _strcmp - function that compares 2 strings lexicographically
 *
 * Description: if both are of same length it compares them lexicographically
 * if they are of different length:
 * - are equal in length -> decalres them to be equal
 *  -are not equal in length -> 2 cases
 *  1. the first n charecters are equal lexicographically, but one string is longer than
 * the other, it will decalre the longer to be grater
 * 2. the first n charecters are not equal lexicographically, it will compre them lexicographically
 * without worrying baout hte extra lenght of ont of them
 *
 * Return: 0 is they are equal, 1 if s1 is greater, -1 if s2 is greater
*/
int _strcmp(char *s1, char *s2)
{
    int len_s1 = _strlen(s1);
    int len_s2 = _strlen(s2);
    int i, result;

    if (len_s1  == len_s2)
    {
         for(i = 0; i < len_s1 ; i++)
            {
                if (s1[i] > s2[i])
                    return  1;
                else if (s1[i] < s2[i])
                    return  -1;
            }
            result  = (0);
    }
    else
    {
        if (len_s1 > len_s2)
        {
            for(i = 0; i < len_s2 ; i++)
            {
                if (s1[i] > s2[i])
                    return  1;
                else if (s1[i] < s2[i])
                    return  -1;
            }
            result = (1);
        }
        else if (len_s1 < len_s2)
        {
            for(i = 0; i < len_s1 ; i++)
            {
                if (s1[i] > s2[i])
                    return  1;
                else if (s1[i] < s2[i])
                    return  -1;
            }
            result = (-1);
        }
    }
    return result;
    
}
