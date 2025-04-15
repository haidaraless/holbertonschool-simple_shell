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
*         or NULL if memory allocation fails.
*/
char **parse_input(char *line)
{
	char *token;
	char **tokens = malloc(64 * sizeof(char *));
	int i = 0;

	if (!tokens)
	{
		perror("malloc");
		return (NULL);
	}

	token = strtok(line, " \t\n");
	while (token)
	{
		tokens[i++] = token;
		token = strtok(NULL, " \t\n");
	}

	tokens[i] = NULL;
	return (tokens);
}
