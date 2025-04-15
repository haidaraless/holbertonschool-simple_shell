#include "simple_shell.h"

/**
* parse_input - Splits a line of input into an array of arguments.
* @line: The input string entered by the user.
*
* Description:
*   Tokenizes the user input based on whitespace (spaces, tabs, newlines).
*   Converts a single string like "ls -l /home" into a NULL-terminated
*   array of arguments: ["ls", "-l", "/home", NULL].
*
* Return: A dynamically allocated array of strings (arguments),
*         or NULL if memory allocation fails or the input is empty.
*/
char **parse_input(char *line)
{
	int bufsize = 64, i = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;
	char **new_tokens = realloc(tokens, bufsize * sizeof(char *));

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
			if (!new_tokens)
			{
				free(tokens);
				perror("realloc");
				exit(EXIT_FAILURE);
			}
			tokens = new_tokens;
		}
		token = strtok(NULL, " ");
	}
	tokens[i] = NULL;
	return (tokens);
}
