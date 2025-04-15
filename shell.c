#include "simple_shell.h"

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
printf("$ ");
read = getline(&line, &len, stdin);
if (read == -1)
break;

if (line[read - 1] == '\n')
line[read - 1] = '\0';
args = parse_input(line);
if (!args || !args[0])
{
free_tokens(args);
continue;
}
pid = fork();
if (pid == 0)
{
if (execvp(args[0], args) == -1)
{
perror("hsh");
}
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
