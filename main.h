#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int print_str(char *str);
int _strcmp(char * command, char *str);
int _strlen(char *s);
void start_execute(char **argv);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

#endif

