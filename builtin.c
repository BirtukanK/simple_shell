#include "shell.h"
/**
 * is_builtin - a function works builtin functionality
 * @command: command to work on
 * Return: integer
 */
int is_builtin(char *command)
{
char *builtins[] = {
"exit", "env", "setenv", "cd", NULL
};
int i;

for (i = 0; builtins[i]; i++)
{
if (_strcmp(command, builtins[i]) == 0)
return (1);
}
return (0);
}

/**
 * handle_builtin - function to handle builtins
 * @command: pointer to a character
 * @args: arguments used
 * @status: status of command
 * @idx: index
 * Return: nothing
 */
void handle_builtin(char **command, char **args, int status, int idx)
{
(void) args;
(void) idx;
if (_strcmp(command[0], "exit") == 0)
exit_shell(command, status);
else if (_strcmp(command[0], "env") == 0)
print_env(command, status);
}
/**
 * exit_shell - function to exit shell
 * @command: command to execute
 * @status: status
 * Return: nothing
 */
void exit_shell(char **command, int status)
{
freearray2D(command);
exit(status);
}

/**
 * print_env - function to print environment
 * @command: command to print
 * @status: status of command
 * Return: nothing
 */
void print_env(char **command, int status)
{
int i;
(void) status;

for (i = 0; environ[i]; i++)
{
write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
write(STDOUT_FILENO, "\n", 1);
}
freearray2D(command);
}
