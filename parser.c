#include <stdlib.h>
#include <string.h>
#include "simple_shell.h"

/**
* parse_input - Tokenizes a line into arguments
* @line: user input
* Return: NULL-terminated array of arguments
*/
char **parse_input(char *line)
{
int bufsize = 64, i = 0;
char **tokens = malloc(bufsize * sizeof(char *));
char *token;

if (!tokens)
{
perror("malloc");
exit(EXIT_FAILURE);
}

token = strtok(line, " ");
while (token != NULL)
{
tokens[i++] = token;

if (i >= bufsize)
{
bufsize += 64;
tokens = realloc(tokens, bufsize *sizeof(char *));
if (!tokens)
{
perror("realloc");
exit(EXIT_FAILURE);
}
}
token = strtok(NULL, " ");
}
tokens[i] = NULL;
return (tokens);
}
