#include "simple_shell.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * execute_command - creates a child process to run an external command.
 * @args: array of strings representing the command and its arguments.
 *
 * Description:
 *   uses fork to create a new process. In the child process, it replaces
 *   itself with the specified command using execvp(). The parent waits
 *   for the child to complete. If the command is not found, an error
 *   message is printed.
 */
void execute_command(char **args)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		/* Child process */
		if (execve(args[0], args, environ) == -1)
			perror("simple_shell");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		/* Fork failed */
		perror("fork");
	}
	else
	{
		/* Parent process waits */
		wait(NULL);
	}
}
