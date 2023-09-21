#ifndef SHELL
#define SHELL
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

#define DELIM " \t\n"
extern char **environ;

char *read_line(void);
char **tokenizer(char *line);
void freearray2D(char **arr);
int _execute(char **command, char **argv, int idx);
char *_getenv(char *variable);
char *_getpath(char *command);

char *_strcpy(char *dest, char *src);
char *_strcat(char *s1, char *s2);
int _strlen(char *str);
int _strcmp(char *str1, char *str2);
char *_strdup(const char *str);
void reverse_string(char *str, int len);
char *_itoa(int n);
void print_error(char *name, char *cmd, int idx);
#endif
