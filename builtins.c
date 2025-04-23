#include "simple_shell.h"

/**
* handle_builtin - checks and executes built-in commands
* @args: command and arguments
* Return: 1 if a built-in was handled, 0 otherwise
*/
int handle_builtin(char **args)
{
	if (args[0] == NULL)
		return (0);

	if (strcmp(args[0], "exit") == 0)
	{
	 if (args[1] != NULL)
	{

	fprintf(stderr, "exit: too many arguments\n");
	return (1);

	}
		free(args);
		exit(0);
	}
	return (0);
}
