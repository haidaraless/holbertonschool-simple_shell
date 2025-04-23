#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "simple_shell.h"

/**
* get_command_path - searches for the full path of a command
* @command: the command to search for
*
* Return: the full path of the command or NULL if not found
*/
char *get_command_path(char *command)
{
char *env_path = NULL;
char *path_copy, *dir;
char full_path[1024];
int i = 0;

/* search for PATH in the environment variables */
while (environ[i])
{
if (strncmp(environ[i], "PATH=", 5) == 0)
{
env_path = environ[i] + 5;
break;
}
i++;
}

if (!env_path)
return (NULL);

/* copy the PATH and split by colon to search directories */
path_copy = strdup(env_path);
dir = strtok(path_copy, ":");

while (dir)
{
snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);
if (access(full_path, X_OK) == 0)  /* check if the command is executable */
{
free(path_copy);
return (strdup(full_path));  /* return the full path if executable */
}
dir = strtok(NULL, ":");
}

free(path_copy);
return (NULL);  /* return NULL if command is not found */
}

/**
* check_path_env - checks if the PATH variable is in the environment
*
* Return: 1 if PATH is found, 0 otherwise
*/
int check_path_env(void)
{
int i = 0;

while (environ[i])
{
if (strncmp(environ[i], "PATH=", 5) == 0)
return (1);
i++;
}
return (0);  /* return 0 if PATH is not found */
}
