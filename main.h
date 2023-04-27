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
#include <errno.h>

/* execution */
char *_getenv(char *, char **);
void execute(char **, char **, char *);
void execute_lite(char **, char **, char *);
char *get_location(char *, char **);
void _free(char **);

/* parsing */
void parse(char *, ssize_t, char **, char *);
int exit_cmd(char *);
int valid_cmd(char *, char *);
int env_cmd(char *, char **);

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

