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

