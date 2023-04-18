#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

/* strings prototypes */
int print_str(char*);
int _strcmp(char*, char*);
int _strlen(char*);
int _strncmp(char *, char *, int);
char *_strcat(char*, char*);
char *_strcpy(char*, char*);
char *_strncpy(char*, char*, int);
char *_strncat(char*, char*, int);

char *get_env(char*);
void start_execute(char**);
#endif

