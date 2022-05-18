#ifndef SHELL_H
#define SHELL_H

/* Libraries */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* Constants */
#define BUFSIZE 1024

/* Functions */
int shell_loop(char **env);

/* Aux functions */
void _puts(char *str);
int _putchar(char c);
char *_strdup(char *str);
int _strcmp(char *, char *);
void free_tokens(char **tokens);
char *string_nconcat(char *s1, char *s2, unsigned int n);
int not_found(char *command);
int _strlen(char *s);
char *path_finder(char **env);
#endif
