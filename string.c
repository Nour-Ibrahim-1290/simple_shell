#include "main.h"
#include <stdio.h>

int print_str(char *str);
int _strcmp(char * command, char *str);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);

/**
 * print_str - print string to the standard output
 * @str: string to print
 * 
 * Return: number of chars printed
 */

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

/**
 * strcmp_exit - compare the 2 strings
 * @command: command to compare
 * @sttr: string to comapre to
 *
 * Return: 0 Success, -1 for failure
 */
int _strcmp(char *command, char *str)
{
	int i = 0;

	while(command[i] && str[i])
	{
		if (command[i] != str[i])
			return (-1);
		i++;
	}

	return (0);
}

/**
 * _strlen - a function that returns the length of a string.
 * @s: the string to be calculated for its length
 *
 * Return: int value contains the length
 */

int _strlen(char *s)
{
	int i, len;

	i = 0;
	len = 0;

	while (*(s + i) != '\0')
	{	len++;
		i++;
	}

	return (len);
}

/**
 * _strcpy -  a function that copies the string pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest.
 * @dest: the destination
 * @src: the source to copy to
 *
 * Return: char pointer.
 */

char *_strcpy(char *dest, char *src)
{
	int i, len;

	len = _strlen(src);
	i = 0;

	while (i <= len)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	return (dest);
}


/**
 * _strcat - a function that concatenates two strings.
 * @dest: the destination string to be concatenated to
 * @src: the source string to concatenate
 *
 * Description: it will use at most n bytes from src
 * and src does not need to be null-terminated if it contains n or more bytes
 *
 * Return: a pointer to the resulting string dest.
 */

char *_strcat(char *dest, char *src)
{
	int i, j, destLen, srcLen;

	destLen = _strlen(dest);
	srcLen = _strlen(src);
	j = 0;
	
	for (i = destLen; i < (destLen + srcLen); i++)
	{
		*(dest + i) = *(src + j);
		j++;
		if (*(src + j) == '\0')
		{
			return (dest);
		}
	}
	return (dest);
}