#include "shell.h"
/**
 * _execute - function which executes unix programs
 * @command: character array
 * @argv: array of arguments
 * Return: int
 */
int _execute(char **command, char **argv, int idx)
{
pid_t child;
int status;
char *full_cmd;

full_cmd = _getpath(command[0]);
if (!full_cmd)
{
print_error(argv[0], command[0], idx);
freearray2D(command);
return (127);
}

child = fork();
if (child == 0)
{
if (execve(full_cmd, command, environ) == -1)
{
free(full_cmd), full_cmd = NULL;
freearray2D(command);
}
}
else
{
waitpid(child, &status, 0);
freearray2D(command);
free(full_cmd), full_cmd = NULL;
}
return (WEXITSTATUS(status));
}
