#include "simple_shell.h"
#include <stdlib.h>
#include <string.h>

/**
 * parse_input - splits a line of input into an array of arguments.
 * @line: the input string entered by the user.
 *
 * Description:
 *   tokenizes the user input based on whitespace (spaces, tabs, newlines).
 *   converts a single string like "ls -l /home" into a NULL-terminated
 *   array of arguments: ["ls", "-l", "/home", NULL].
 *
 * Return: a dynamically allocated array of strings (arguments),
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
		exit(EXIT_FAILURE);
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
