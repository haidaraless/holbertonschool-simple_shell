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
	char **temp = realloc(tokens, bufsize * sizeof(char *));

	if (!tokens)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	if (line == NULL || line[0] == '\0')
	{
		free(tokens);  /* Free the initially allocated memory if empty input */
		return (NULL);
	}

	token = strtok(line, " \t\n");  /* Tokenize input */
	while (token != NULL)
	{
		tokens[i++] = token;
		if (i >= bufsize)
		{
			bufsize += 64;

			if (!temp)
			{
				perror("realloc");
				free(tokens);  /* Free previously allocated memory before exit */
				exit(EXIT_FAILURE);
			}
			tokens = temp;  /* Assign the new memory location to tokens */
		}
		token = strtok(NULL, " \t\n");
	}
	tokens[i] = NULL;  /* Null-terminate the array of arguments */
	return (tokens);
}
