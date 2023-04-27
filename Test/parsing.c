#include "main.h"

int exit_cmd(char *cmd);
int env_cmd(char *cmd, char **env);
int valid_cmd(char *cmd, char *err);
int parse(char *command, ssize_t num_chars_read, char **env, char *err);

/**
 * parse - parsing a command
 * @command: to be parsed
 * @num_chars_read: length of command
 * @env: list of enviroments from main func
 * @err: a pointer to the error_head
 *
 * Return: 0 Success, -1 failure
 */
int parse(char *command, ssize_t num_chars_read, char **env, char *err)
{
	char **argv;
	char *command_copy = NULL, *token = NULL;
	const char *delim = " \n";
	int num_tokens = 0, i, status;

	/* create a copy from command*/
	command_copy = malloc(sizeof(char) * num_chars_read + 1);
	if (command_copy == NULL)
	{
		/* 12: Cannot allocate memory */
		perror(err);
		return (-1);
	}
	_strcpy(command_copy, command);
	command_copy[num_chars_read] = '\0';

	/**Tokenization as the main part of Parsing*/
	/* split the command string into an array of tokens*/
	token = strtok(command, delim);
	/* determine number of tokens*/
	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	num_tokens++;

	/* Read the tokens them selves*/
	argv = malloc(sizeof(char *) * num_tokens);
	if (argv == NULL)
	{
		/* 12: Cannot allocate memory */
		perror(err);
		free(argv);
		free(command_copy);
		return (-1);
	}
	token = strtok(command_copy, delim);
	/* account for check 1 */
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		if (argv[i] == NULL)
		{
			/* 12: Cannot allocate memory*/
			perror(err);
			free(command_copy);
			_free(argv);
			free(command_copy);
			return (-1);
		}
		_strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;

	free(command_copy);

	/* Handling the Case of Pressing ENTER*/
	if (argv[0] == NULL)
	{
		_free(argv);
		return (0);
	}

	/* execute exit builtin command */
	if (exit_cmd(argv[0]) == 0)
	{
		_free(argv);
		/*_free(env);*/
		/*free(err);*/
		exit(0);
	}

	/* execute env builtin command */
	if (env_cmd(argv[0], env) == 0)
	{
		_free(argv);
		return (0);
	}

	/* executing executable commands*/
	status = execute(argv, env, err);

	_free(argv);

	return (status);
}

/**
 * exit_cmd - handling exit built-in command
 * @cmd: 1st token in argv from parse
 *
 * Return: 0 on success, -1 on fail
 */
int exit_cmd(char *cmd)
{
	/* handling exit*/
	if (_strcmp(cmd, "exit") == 0)
	{
		return (0);
	}
	return (-1);
}


/**
 * env_cmd - handling exit built-in command
 * @cmd: 1st token in argv from parse
 * @env: list of enviroments from main func
 *
 * Return: 0 Success, -1 other cmd
 */
int env_cmd(char *cmd, char **env)
{
	size_t i;

	/* handling exit*/
	if (_strcmp(cmd, "env") == 0)
	{
		for (i = 0; env[i] != NULL; i++)
		{
			print_str(env[i]);
			print_str("\n");
		}
		return (0);
	}

	return (-1);
}


