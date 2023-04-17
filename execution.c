#include "main.h"

/**
 *
 */

void start_execute(char **argv)
{
	char *path;
	char *command;

	if (argv != NULL)
	{
		command = argv[0];

		path = malloc(sizeof(char) * (_strlen(command) + 9));
		if (path == NULL)
		{
			print_str("memory allocation error");
			return;
		}
		path = _strcpy(path, "/usr/bin/");
		path = _strcat(path, command);
		
		print_str(path);
		print_str(getenv("PATH"));

		if (execve(path, argv, NULL) == -1)
		{
			perror("Error: ");
		}

		free(path);
	}
}
