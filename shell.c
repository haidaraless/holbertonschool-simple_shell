#include "simple_shell.h"
#include "builtins.h"


/**
* main - Entry point for the simple shell
* Description:
*   - Displays a prompt and waits for user input.
*   - Parses input into command and arguments.
*   - Handles built-in commands like "exit" and "env".
*   - Executes external commands using fork + exec.
*   - Repeats until user exits with "exit" or Ctrl+D.
*
* Return: 0 on success, exits with failure on error
*/
int main(void)
{
	char *line = NULL;
	char **args = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		printf("$ ");  /* Display prompt */

		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			free(line);  /* Exit on Ctrl+D */
			exit(EXIT_SUCCESS);
		}

		args = parse_input(line);  /* Tokenize input */
		if (args == NULL || args[0] == NULL)
		{
			free(args);
			continue;
		}

		if (handle_builtin(args))  /* Handle built-in commands */
		{
			free(args);
			continue;
		}

		execute_command(args);  /* Run external commands */

		free(args);  /* Clean up memory */
	}

	free(line);
	return (0);
}
