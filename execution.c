#include "main.h"
#include <stdio.h>
/**
 *
 */

extern char **environ;

void start_execute(char **argv)
{
	char *var;
	char **env = (char **)malloc(2* sizeof(char*));

	printf("%s%d\n", argv[0], _strlen(argv[0]));
	var = get_env("PATH");
	printf("%s\n", var);
	env[0] = var;
	env[1] = NULL;

	if (execve(argv[0], argv, env) == -1)
		perror("Error");
}
