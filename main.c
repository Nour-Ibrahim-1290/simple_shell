#include "main.h"
#include <stdio.h>

extern char **environ;

char *get_env(char *name);

/**
 * main - prompt to our shell
 *
 * Return: 0, -1 for exit
 */

int main(int ac, char **argv)
{
	char *prompt = "(eshell) $ ", *last_arg, *ptr;
	char *command = NULL, *command_copy = NULL, *token;
	const char *delim = " ";
	size_t n = 0;
	ssize_t num_chars_read;
	int num_tokens, i, len_last;

	/* voiding unused vars*/
	(void)ac;
	(void)ptr;
	while (1)
	{
		num_tokens = 0;
		print_str(prompt);
		num_chars_read = getline(&command, &n, stdin);

		/* checking error cases of getline() - exit conditions */
		if (num_chars_read == -1)
		{
			print_str("exiting shell ... \n");
			return (-1);
		}


		/* its better to include in parsing section */
		if (num_chars_read == 5)
		{
			if(_strcmp(command, "exit\n") == 0)
			{
				print_str("exiting shell ... \n");
				return (-1);
			}
		}
		/* create a copy from command*/
		command_copy = malloc(sizeof(char) * num_chars_read);
		if (command_copy == NULL)
		{
			perror("memory allocation error");
			return (-1);
		}
		strcpy(command_copy, command);

		/**Tokenization as the main part of Parsing*/
		/* split the command string into an array of tokens*/
		token = strtok(command, delim);
		/* determine number of tokens*/
		while (token != NULL)
		{
			/*if (*token == '\n')
				break;*/
			num_tokens++;
			token = strtok(NULL, delim);
		}
		num_tokens++;

		/* Read the tokens them selves*/
		argv = malloc(sizeof(char *) * num_tokens);

		token = strtok(command_copy, delim);
		for (i = 0; token != NULL; i++)
		{
			/*if (*token == '\n')
				*token = '\0';*/
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;


		last_arg = argv[num_tokens - 2];

		printf("%s%d\n", last_arg, _strlen(last_arg));

		/* omitting the new line character */
		len_last = _strlen(last_arg);
		if (len_last > 0 && last_arg[len_last - 1] == '\n')
			last_arg[len_last - 1] = '\0';

		/*printf("%s%d\n", last_arg, _strlen(last_arg));*/

		/*executable case */
		start_execute(argv);
	}
	free(command);
	free(command_copy);
}

/**
 * get_env - return the value of the variable name passed to it
 * @name: the name of env variable to be searched
 *
 * Return: a pointet to a string of the value of the env variable passed
 * NULL if not found
 */

char *get_env(char *name)
{
	char *var, *value, *str;
	unsigned int i = 0;

	while (environ[i] != NULL)
	{
		str = malloc(sizeof(char) * _strlen(environ[i]) + 1);
		if (str == NULL)
			return (NULL);
		str = _strcpy(str, environ[i]);
		var = strtok(str, "=");
		value = strtok(NULL, "=");

		if (_strcmp(var,name) == 0)
		{
			return (value);
		}
		free(str);
		i++;
	}
	return (NULL);
}
