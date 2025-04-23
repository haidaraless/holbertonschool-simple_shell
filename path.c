#include "simple_shell.h"

/**
 * find_command - finds the full path of a command
 * @command: the command to search for
 *
 * Return: the full path to the command, or NULL if not found
 */

char *find_command(char *command)
{
char *path_env = NULL;
char *path_copy, *dir;
char full_path[1024];
int i = 0;

/* Search for PATH in the environment variables */
while (environ[i])
{
if (strncmp(environ[i], "PATH=", 5) == 0)
{
path_env = environ[i] + 5;
break;
}
i++;
}

if (!path_env)
return (NULL);

/* Copy the PATH and split by colon to search directories */
path_copy = strdup(path_env);
dir = strtok(path_copy, ":");

while (dir)
{
snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);
if (access(full_path, X_OK) == 0)
{
free(path_copy);
return (strdup(full_path));
}
dir = strtok(NULL, ":");
}

free(path_copy);
return (NULL);
}


/**
 * execute_command - executes a command by forking a child process
 * @args: the arguments to execute
 *
 * Return: void
 */
void execute_command(char **args)
{
char *command_path;
pid_t pid;
int status;

command_path = find_command(args[0]);

/* If the command doesn't exist, do not call fork */
if (command_path == NULL)
{
fprintf(stderr, "Command not found: %s\n", args[0]);
return;
}

pid = fork();
if (pid == -1)
{
perror("Fork failed");
return;
}
else if (pid == 0)
{
execve(command_path, args, environ);
perror("Execve failed");
exit(1);
}
else
{
wait(&status);
}
}

/**
 * handle_exit - exits the shell
 *
 * Return: void
 */
void handle_exit(void)
{
exit(0);
}

int main(void)
{
char *line = NULL;
size_t len = 0;
ssize_t nread;
char **args;

while (1)
{
printf("$ ");
nread = getline(&line, &len, stdin);

if (nread == -1)
{
perror("getline failed");
break;
}

line[strcspn(line, "\n")] = 0;

if (strcmp(line, "exit") == 0)
{
handle_exit();
}

args = parse_input(line);
execute_command(args);
free_tokens(args);
}

free(line);
return (0);
}
