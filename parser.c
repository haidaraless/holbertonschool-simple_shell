#include "simple_shell.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
* parse_input - Splits a line of input into an array of arguments.
* @line: The input string entered by the user.
*
* Return: A dynamically allocated array of strings (arguments),
*         or NULL if memory allocation fails or the input is empty.
*/
char **parse_input(char *line)
{
int bufsize = 64, i = 0;
char **tokens = malloc(bufsize * sizeof(char *));
char *token;
char **temp;

if (!tokens)
{
perror("malloc");
exit(EXIT_FAILURE);
}

token = strtok(line, " \t\r\n");  /* support all whitespace */
while (token != NULL)
{
tokens[i] = strdup(token);  /* duplicate string to avoid use-after-free */
if (!tokens[i])
{
perror("strdup");
exit(EXIT_FAILURE);
}
i++;

if (i >= bufsize)
{
bufsize += 64;
temp = realloc(tokens, bufsize *sizeof(char *));
if (!temp)
{
free_tokens(tokens);
perror("realloc");
exit(EXIT_FAILURE);
}
tokens = temp;
}
token = strtok(NULL, " \t\r\n");
}
tokens[i] = NULL;
return (tokens);
}
