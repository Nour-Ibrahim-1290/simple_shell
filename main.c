#include "main.h"

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
	char *command = NULL, *error_head;
	size_t n = 0;
	ssize_t num_chars_read;
	int flag = 0;

	/* voiding unused vars*/
	(void)ac;
	error_head = malloc(sizeof(char) * _strlen(argv[0]));
	if (error_head == NULL)
		return (-1);

	error_head = argv[0];
	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			flag = 1;
			print_str(prompt);
		}
		num_chars_read = getline(&command, &n, stdin);

		/* checking error cases of getline() - exit conditions */
		if (num_chars_read == -1)
		{
			if (flag == 1)
				print_str("\n");
			return (-1);
		}

		/* Parse and execute the command*/
		parse(command, num_chars_read, env, error_head);


	}
	/*free(error_head);*/
	free(command);
	_free(argv);
	_free(env);

	return (0);
}
