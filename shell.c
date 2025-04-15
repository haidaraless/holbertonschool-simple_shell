#include "simple_shell.h"
#include "builtins.h"

/**
* main - A minimal UNIX command line interpreter.
*
* Description:
*   - Displays a prompt and waits for user input.
*   - Accepts a single command (no arguments).
*   - Uses execve() to execute the command (must be a full path).
*   - Handles EOF (Ctrl+D) and prints error if command fails.
*
* Return: Always 0.
*/
int main(void)
{
	char *line = NULL;
	char **args = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		printf("$ "); /* Display prompt */

		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			/* Handle Ctrl+D (EOF) */
			free(line);
			write(STDOUT_FILENO, "\n", 1);
			exit(0);
		}
		/* Remove newline character from input */
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		if (strlen(line) == 0)
			continue;

		args = parse_input(line); /* Tokenize the input */
		if (args == NULL)
			continue;

		/* Handle built-in commands like "exit" */
		if (handle_builtin(args))
		{
			free(args);
			continue;
		}
		/* Execute external commands using execve */
		execute_command(args);
		free(args);  /* Clean up memory */
	}
	free(line);  /* Clean up input buffer */
	return (0);
}
