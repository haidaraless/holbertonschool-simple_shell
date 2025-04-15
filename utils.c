#include "simple_shell.h"

/**
* free_tokens - Frees a NULL-terminated array of strings.
* @tokens: The array to free.
*/
void free_tokens(char **tokens)
{
	int i = 0;

	if (!tokens)
		return;

	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}
