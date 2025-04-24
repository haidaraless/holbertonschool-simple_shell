#include "simple_shell.h"

/**
* handle_builtin - checks and executes built-in commands
* @args: command and arguments
* Return: 1 if a built-in was handled, 0 otherwise
*/
int handle_builtin(char **args)
{
if (strcmp(args[0], "env") == 0)
{
int i = 0;
while (environ[i])
printf("%s\n", environ[i++]);
return (1);
}
return (0);
}
