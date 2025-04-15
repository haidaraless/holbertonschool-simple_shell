#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* parse_input - Tokenizes the input line into command and arguments
* @line: The input string
* Return: A NULL-terminated array of strings (tokens)
*/
char **parse_input(char *line)
{
int bufsize = 64, i = 0;
char **tokens;
char *token;

tokens = malloc(bufsize * sizeof(char *));
if (!tokens)
{
perror("malloc");
exit(EXIT_FAILURE);
}

token = strtok(line, " \t\r\n");
while (token)
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

token = strtok(NULL, " \t\r\n");
}
tokens[i] = NULL;
return (tokens);
}
