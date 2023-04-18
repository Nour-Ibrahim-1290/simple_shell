#include "main.h"
#include <stdio.h>


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
		
		/* omitting the new line character */
		last_arg = argv[num_tokens - 2];
		len_last = _strlen(last_arg);
		if (len_last > 0 && last_arg[len_last - 1] == '\n')
			last_arg[len_last - 1] = '\0';
		
		printf("%s\n", get_env("PATH"));

		/*executable case */
		/*start_execute(argv);*/
	}
	free(command);
	free(command_copy);
}
