#include "shell.h"
/**
 * tokenizer - a function which used for tokenizing
 * @line: string to tokenize
 * Return: tokenized character
 */
char **tokenizer(char *line)
{
char *token = NULL, *tmp = NULL;
char **command = NULL;
int count = 0, i = 0;

if (!line)
	return (NULL);
tmp = _strdup(line);

token = strtok(tmp, DELIM);
if (token == NULL)
{
free(line), line = NULL;
free(tmp), tmp = NULL;
return (NULL);
}
while (token)
{
count++;
token = strtok(NULL, DELIM);
}
free(tmp), tmp = NULL;

command = malloc(sizeof(char *) * (count + 1));
if (!command)
{
free(line), line = NULL;
return (NULL);
}
token = strtok(line, DELIM);
while (token)
{
command[i] = _strdup(token);
token = strtok(NULL, DELIM);
i++;
}
free(line), line = NULL;
command[i] = NULL;
return (command);
}
