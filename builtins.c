#include "simple_shell.h"

/**
* handle_builtin - checks and executes built-in commands
* @args: command and arguments
* Return: 1 if a built-in was handled, 0 otherwise
*/
int handle_builtin(char **args)
{
	if (args[0] == NULL)
		return 0;

	if (strcmp(args[0], "exit") == 0)
		exit(0);
	else if (strcmp(args[0], "env") == 0)
	{
		extern char **environ;

		for (int i = 0; environ[i] != NULL; i++)
			printf("%s\n", environ[i]);
		return (1);
	}

	return (0);
}
