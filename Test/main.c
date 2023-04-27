#include "main.h"


void sig_handler(int sig_num);

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
	int flag = 0, status = 0;

	/* voiding unused vars*/
	(void)ac;
	error_head = malloc(sizeof(char) * _strlen(argv[0]));
	if (error_head == NULL)
	{
		_free(argv);
		_free(env);
		free(command);
		free(error_head);
		return (-1);
	}

	/* preserving shell exe file name as error head*/
	error_head = argv[0];

	/* setting signal status*/
	/*signal(SIGINT, sig_handler);*/
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
			{
				print_str("\n");
				free(command);
			}
			exit(0);
		}

		/* Parse and execute the command*/
		status = parse(command, num_chars_read, env, error_head);
	}
	/*free(error_head);*/
	free(command);
	_free(argv);
	_free(env);
	return (status);
}


/**
 * sig_handler - checks if Ctrl C is pressed
 * @sig_num: int
 */
void sig_handler(int sig_num)
{
	if (sig_num == SIGINT)
	{
		print_str("\n(shell) $ ");
	}
}
