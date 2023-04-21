#include "main.h"
#include <stdio.h>

void execute(char **);
char *_getenv(char *);
char *get_location(char *);
void _free(char **argv);


/**
 * execute - execute file of an executable command
 * @argv: tokens of the command generated from getline
 *
 * Return: void
 */
void execute(char **argv)
{
	char *command_str = NULL, *command = NULL;
	pid_t pid, wpid;
	int status;

	if (argv)
	{
		command_str = argv[0];
		_strcpy_at(command_str, argv[0], _strlen("/bin/"));

		command = get_location(command_str);

		if (command == NULL)
			perror("./hsh: No such file or directory");

		pid = fork();
		if (pid == 0)
		{
			/* execution */
			if (execve(command, argv, NULL) == -1)
				perror("Error");
			exit(EXIT_FAILURE);
		}
		else if (pid < 0)
		{
			perror("./hsh");
		}
		else
		{
			do {
				wpid = waitpid(pid, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
	}
	(void)command;
	(void)wpid;
	_free(argv);
}

/**
 * _free - free command tokens 2D array
 * @argv: 2D array
 *
 * Return: void
 */
void _free(char **argv)
{
	int i = 0;

	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
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
		path_copy = _strdup(path);
		command_length = _strlen(command);
		path_token = strtok(path_copy, ":");

		while (path_token != NULL)
		{
			dir_length = _strlen(path_token);
			file_path = malloc(sizeof(char) * (command_length + dir_length + 2));
			if (file_path == NULL)
				return (NULL);

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
}

