#include "main.h"
#include <stdio.h>

/**
 * main - prompt to our shell
 * @ac: count of arguments
 * @argv: list of arguments
 * @env: list of enviroments
 *
 * Return: 0, -1 for exit
 */

int main(int ac, char **argv, char **env)
{
	char *prompt = "(shell) $ ";
	char *command = NULL;
	size_t n = 0;
	ssize_t num_chars_read;

	/* voiding unused vars*/
	(void)ac;

	/*signal(SIGINT, 0);*/
	while (1)
	{
		if (isatty(STDIN_FILENO))
			print_str(prompt);
		num_chars_read = getline(&command, &n, stdin);

		/* checking error cases of getline() - exit conditions */
		if (num_chars_read == -1)
		{
			print_str("exiting shell ... \n");
			return (-1);
		}

		/* Parse and execute the command*/
		parse(command, num_chars_read, env);
	}
	free(command);
	_free(argv);
	free(argv);
	_free(env);
	free(env);
}

