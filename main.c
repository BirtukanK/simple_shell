#include "shell.h"

/**
 * main - main function
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0
 */
int main(int argc, char **argv)
{
char *line = NULL;
char **command = NULL;
int status = 0;
(void) argc;
(void) argv;

while (1)
{
line = read_line();
if (line == NULL)
{
if (isatty(STDIN_FILENO))
{
write(STDOUT_FILENO, "\n", 1);
}
return (status);
}


command = tokenizer(line);
if (!command)
continue;

status = _execute(command, argv);

}

}