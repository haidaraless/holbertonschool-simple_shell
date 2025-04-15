#include "simple_shell.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

extern char **environ;

/**
* execute_command - creates a child process to run an external command.
* @args: array of strings representing the command and its arguments.
*
* Description:
*   Uses fork to create a new process. In the child process, it replaces
*   itself with the specified command using execve(). The parent waits
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
		{
			perror(args[0]); /* Specific error message with command name */
		}
		exit(EXIT_FAILURE);  /* Exit if execve fails */
	}
	else if (pid < 0)
	{
		perror("fork"); /* Fork failed */
	}
	else
	{
		/* Parent process waits and checks child exit status */
		int status;

		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			int exit_status = WEXITSTATUS(status);

			if (exit_status != 0)
			{
				/* You can handle non-zero exit status here */
				fprintf(stderr, "Command '%s' exited with status %d\n",
						args[0], exit_status);
			}
		}
		else if (WIFSIGNALED(status))
		{
			/* In case the child was terminated by a signal */
			fprintf(stderr, "Command '%s' terminated by signal %d\n",
					args[0], WTERMSIG(status));
		}
	}
}
