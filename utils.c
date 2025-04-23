#include "simple_shell.h"
#include <stdlib.h>
/**
* free_tokens - Frees a NULL-terminated array of strings.
* @tokens: The array to free.
*/
void free_tokens(char **tokens)
{
	if (tokens)
		free(tokens);
}

/**
 * free_tokens_full - Frees a NULL-terminated array of strings and its elements.
 * @tokens: The array to free.
 */
void free_tokens_full(char **tokens)
{
int i = 0;
if (tokens)
{

while (tokens[i] != NULL)
{
free(tokens[i]);
i++;
}
free(tokens);
}
}

/**
 * parse_input - Parses the input string into tokens (commands and arguments)
 * @line: The input line to parse
 * Return: An array of tokens (commands and arguments)
 */

char **parse_input(char *line)
{
int bufsize = 64, position = 0;
char **tokens = malloc(bufsize * sizeof(char *));
char *token;

if (!tokens)
{
fprintf(stderr, "allocation error\n");
exit(1);
}

token = strtok(line, " \t\r\n\a");
while (token != NULL)
{
tokens[position] = token;
position++;

if (position >= bufsize)
{

bufsize += 64;
tokens = realloc(tokens, bufsize * sizeof(char *));
if (!tokens)
{

fprintf(stderr, "allocation error\n");
exit(1);
}
}

token = strtok(NULL, " \t\r\n\a");
}
tokens[position] = NULL;
return (tokens);
}

**
 * check_command_in_path - Checks if the command exists in the system's PATH
 * @command: The command to check
 * Return: 1 if the command exists in PATH, 0 otherwise
 */
int check_command_in_path(char *command)
{

char *path = getenv("PATH");
char *token = strtok(path, ":");
char full_path[1024];

while (token != NULL)
{
snprintf(full_path, sizeof(full_path), "%s/%s", token, command);
if (access(full_path, X_OK) == 0)
{
return (1);
}
token = strtok(NULL, ":");
}
return (0);
}
