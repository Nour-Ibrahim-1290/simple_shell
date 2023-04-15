#include "main.h"
#include <stdio.h>

/**
 *
 *
 */

int print_str(char *str);

int main(void)
{
	char *prompt = "(eshell) $ ";
	char *command;
	size_t n = 0;
	ssize_t num_chars_read;

	while (1)
	{
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
			if(strcmp(command, "exit\n") == 0)
			{
				print_str("exiting shell ... \n");
				return (-1);
			}
		}
		print_str(command);
	}
}

int print_str(char *str)
{
	int len = 0;

	if (str == NULL)
		return (-1);
	
	/* printf("%s\n", str); */
	/* handling if write fails */
	while (str[len] != '\0')
	{
		write(1, &str[len], 1);
		len++;
	}
	return (len);
}
