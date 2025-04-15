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
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		/* Remove newline character */
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		args = parse_input(line); /* Tokenize the input */

		/* Check for empty input or parsing failure */
		if (!args || !args[0])
		{
			free_tokens(args);
			continue;
		}

		/* Check and handle built-in commands */
		if (!handle_builtin(args))
			execute_command(args); /* Execute external command */

		free_tokens(args); /* Free tokenized input */
	}

	free(line); /* Free raw input */
	return (0);
}
