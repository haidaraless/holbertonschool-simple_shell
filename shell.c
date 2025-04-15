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
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2); /* Display prompt */

		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			/* Handle Ctrl+D (EOF) */
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		/* Remove newline character from input */
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		args = parse_input(line); /* Tokenize the input */
		if (!args)
			continue;

		if (!handle_builtin(args))
			execute_command(args); /* Execute external commands using execve */

		free(args);  /* Clean up memory */
	}
	free(line);  /* Clean up input buffer */
	return (0);
}
