#include "main.h"



void exit_cmd(char *cmd);
int env_cmd(char *cmd, char **env);
int valid_cmd(char *cmd);
void parse(char *command, ssize_t num_chars_read, char **env);

/**
 * parse - parsing a command
 * @command: to be parsed
 * @num_chars_read: length of command
 * @env: list of enviroments from main func
 *
 * Return: void
 */
void parse(char *command, ssize_t num_chars_read, char **env)
{
	char **argv;
	char *command_copy = NULL, *token;
	const char *delim = " \n";
	int num_tokens = 0, i;

	/* create a copy from command*/
	command_copy = malloc(sizeof(char) * num_chars_read);
	if (command_copy == NULL)
	{
		perror("memory allocation error");
		return;
	}
	_strcpy(command_copy, command);


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
		perror("memory allocation error");
		return;
	}
	token = strtok(command_copy, delim);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * _strlen(token));
		if (argv[i] == NULL)
		{
			perror("memory allocation erroe");
			return;
		}
		_strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;

	free(command_copy);
	/* Handling the Case of Pressing ENTER*/
	if (argv[0] == NULL)
		return;

	/* execute exit builtin command*/
	exit_cmd(argv[0]);

	/* execute env builtin command*/
	if (env_cmd(argv[0], env) == 0)
		return;

	/* check if a valid entry or not*/
	if (valid_cmd(argv[0]) == 1)
		return;

	execute(argv, env);
}

/**
 * exit_cmd - handling exit built-in command
 * @cmd: 1st token in argv from parse
 *
 * Return: void
 */
void exit_cmd(char *cmd)
{
	/* handling exit*/
	if (_strcmp(cmd, "exit") == 0)
	{
		print_str("exiting shell...\n");
		exit(0);
	}
}


/**
 * env_cmd - handling exit built-in command
 * @cmd: 1st token in argv from parse
 * @env: list of enviroments from main func
 *
 * Return: 0 Success, 1 other cmd
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

	return (1);
}


/**
 * valid_cmd - check if  the command is_valid
 * @cmd: 1st token in argv from parse
 *
 * Return: 0 Success, 1 error
 */
int valid_cmd(char *cmd)
{
	/* handling exit*/
	if (_strncmp(cmd, "/bin/", _strlen("/bin/")) != 0)
	{
		perror("./hsh: No such file or directory");
		return (1);
	}

	return (0);
}
