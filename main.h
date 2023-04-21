#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

/* external envirment variable*/
extern char **environ;

/* handling enviromental values */
char *_getenv(char *);
void execute(char **);
char *get_location(char *);

/* parsing */
void parse(char *, ssize_t);

/* string functions */
int print_str(char *);
int _strcmp(char *, char *);
int _strlen(char *);
char *_strcat(char *, char *);
char *_strcpy(char *, char *);
int _strncmp(char *, char *, int);
char *_strdup(char *);
char *_strcpy_at(char *, char *, int);

#endif

