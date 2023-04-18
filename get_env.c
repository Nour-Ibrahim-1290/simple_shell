#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * get_env - return the value of the variable name passed to it
 * @name: the name of env variable to be searched
 *
 * Return: a pointet to a string of the value of the env variable passed
 * NULL if not found
 */

char *get_env(char *name)
{
	extern char **environ;
    char *value = NULL;
    size_t i;
    size_t name_len = _strlen(name);

    for (i = 0; environ[i] != NULL; i++)
	{
        if ((_strncmp(name, environ[i], name_len) == 0) &&
            (environ[i][name_len] == '=')) 
			{
            	value = &environ[i][name_len + 1];
            	break;
       		}
    }
    return (value);
}

/* test the function */
/*
int main(void)
{
	char *var;
	var = get_env("HOME");
	printf("%s\n", var);
	return 1;
}
*/
