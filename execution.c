#include "main.h"
#include <stdio.h>

extern char **environ;
void execute(char **);
char *_getenv(char *);
char *get_location(char *);


/**
 * execute - execute file of an executable command
 * @argv: tokens of the command generated from getline
 *
 * Return: void
 */
void execute(char **argv)
{
	char *command_str = NULL, *command = NULL;

<<<<<<< HEAD

	printf("%s%d\n", argv[0], _strlen(argv[0]));
	var = get_env("PATH");
	printf("%s\n", var);
	env[0] = var;
	env[1] = NULL;

	if (execve(argv[0], argv, NULL) == -1)
		perror("Error");
=======
	if (argv)
	{
		command_str = argv[0];

		command = get_location(command_str);

		/*printf("%s\n", command);*/
		if (execve(command, argv, NULL) == -1)
			perror("Error");
	}
	(void)command;
}

/**
 * _getenv - return the value of the variable name passed to it
 * @name: the name of env variable to be searched
 *
 * Return: a pointet to a string of the value of the env variable passed
 * NULL if not found
 */

char *_getenv(char *name)
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

/**
 * get_location - get the location of an executable command file
 * @command: command string
 *
 * Return: string file_path
 */
char *get_location(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	int command_length, dir_length;
	struct stat buffer;

	path = _getenv("PATH");
	if (path)
	{
		path_copy = strdup(path);
		command_length = strlen(command);
		path_token = strtok(path_copy, ":");

		while (path_token != NULL)
		{
			dir_length = _strlen(path_token);
			file_path = malloc(command_length + dir_length + 2);
			_strcpy(file_path, path_token);
			_strcat(file_path, "/");
			_strcat(file_path, command);
			_strcat(file_path, "\0");

			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_copy);

		if (stat(command, &buffer) == 0)
			return (command);

		return (NULL);
	}
	return (NULL);
>>>>>>> main
}
