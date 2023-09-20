#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"
/**
 * main - main function
 * Return: void
 */

int main(void)
{
pid_t pid;
char *lineptr = NULL;
size_t n = 0;
ssize_t read;
char *argv[] = {"/bin/ls", NULL};
pid = fork();
if (pid == -1)
{
        return (-1);
}
if (pid == 0)
{
printf("#cisfun$ ");

while ((read = getline(&lineptr, &n, stdin)) != EOF)
{
if (execve(argv[0], argv, environ) == -1)
{
perror("Error:");
printf("#cisfun$ ");
}
}
}
else
{
wait(NULL);
printf("#cisfun$ ");
}
return (0);
}
