#include "simple_shell.h"
#include "builtins.h"


/**
 * main - Basic shell loop that handles command lines with arguments
 * Return: Always 0
 */

int main(void)
{
char *line = NULL;
size_t len = 0;
ssize_t read;
char **args;
pid_t pid;
int status;
while (1)
{
if (isatty(STDIN_FILENO))
printf("$ ");
read = getline(&line, &len, stdin);
if (read == -1)
break;
if (line[read - 1] == '\n')
line[read - 1] = '\0';
args = parse_line(line);
if (!args || !args[0])
{
free_tokens(args);
continue;
}
if (handle_builtin(args, line))
{
continue;
}
if (!check_command_in_path(args[0]))
{
fprintf(stderr, "%s: command not found\n", args[0]);
free_tokens(args);
continue;
}
pid = fork();
if (pid == 0)
{
execvp(args[0], args);
perror("hsh");
exit(EXIT_FAILURE);
}
else if (pid < 0)
perror("fork");
else
waitpid(pid, &status, 0);
free_tokens(args);
}
free(line);
return (0);
}
