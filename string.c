#include "main.h"
#include <stdio.h>

int print_str(char *str);
int _strcmp(char *command, char *str);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strncmp(char *, char *, int);
char *_strdup(char *);
char *_strcpy_at(char *s1, char *s2, int n);

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

	/* handling if write fails */
	while (str[len] != '\0')
	{
		write(1, &str[len], 1);
		len++;
	}
	return (len);
}

/**
 * _strcmp - compare the 2 strings
 * @command: command to compare
 * @str: string to comapre to
 *
 * Return: 0 Success, -1 for failure
 */
int _strcmp(char *command, char *str)
{
	int i = 0;

	while (command[i] && str[i])
	{
		if (command[i] != str[i])
			return (-1);
		i++;
	}

	return (0);
}

/**
 * _strdup - duplicate a src string and return it
 * @src: string to duplicate
 *
 * Return: duplicated string
 */
char *_strdup(char *src)
{
	char *dest;
	int i = 0, len;

	if (src == NULL)
		return (NULL);

	len = _strlen(src);
	dest = malloc(sizeof(char) * len);
	if (dest == NULL)
		return (NULL);

	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}

	return (dest);
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
	int i, src_len, dest_len;

	src_len = _strlen(src);
	dest_len = _strlen(dest);
	i = 0;

	while (i <= src_len && src_len <= dest_len)
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


/**
 * _strncmp - a function that compares two strings.
 * @s1: the first string
 * @s2: the second string to be compared to s1
 * @n: the limit
 *
 * Return: if s1 < s2  --> -ve vlaue
 *		   if s1 == s2 --> zero
 *		   if s1 > s2  --> +ve value
 */

int _strncmp(char *s1, char *s2, int n)
{
	int i;

	i = 0;
	while (*(s1 + i) != '\0' && *(s2 + i) != '\0' && i < n)
	{
		if (*(s1 + i) == *(s2 + i))
		{
			i++;
		}
		else
			break;
	}

	if (*(s1 + i) == *(s2 + i) || i == n)
	{
		return (0);
	}
	else
		return ((int)(*(s1 + i)) - (int)(*(s2 + i)));
}

/**
 * _strcpy_at - copy s2 strings strat from n bytes
 * @s1: first string
 * @s2: 2nd string
 * @n: position to copy from
 *
 * Return: copied string
 */

char *_strcpy_at(char *s1, char *s2, int n)
{
	int i = 0, j = 0, len = _strlen(s2);

	if (s2 == NULL)
		return (NULL);

	while (i < len && s2[i] != '\0')
	{
		if (i < n)
		{
			i++;
			continue;
		}
		s1[j] = s2[i];
		i++;
		j++;
	}

	len = _strlen(s1);
	while (j < len)
		s1[j++] = '\0';

	return (s1);
}
