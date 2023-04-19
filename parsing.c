#include "main.h"

/**
 * parse - parsing a command
 * @command: to be parsed
 * @num_chars_read: length of command
 * @argv: tokens of command
 */
void parse(char *command, ssize_t num_chars_read, char **argv)
{
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

	token = strtok(command_copy, delim);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * _strlen(token));
		_strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;

	/* Handling the Case of Pressing ENTER*/
	if (argv[0] == NULL)
		return;

	/* handling exit*/
	if (_strcmp(argv[0], "exit") == 0)
	{
		print_str("exiting shell...\n");
		exit(0);
	}

	execute(argv);

	free(command_copy);
}
