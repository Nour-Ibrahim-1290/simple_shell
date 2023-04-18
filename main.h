#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <sys/stat.h>

/* handling enviromental values */
char *_getenv(char *name);
void execute(char **argv);
char *get_location(char *command);

/* parsing */
void parse(char *, ssize_t, char **);

/* string functions */
int print_str(char *str);
int _strcmp(char * command, char *str);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strncmp(char *, char *, int);

#endif
