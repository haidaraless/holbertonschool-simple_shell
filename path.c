#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int check_command_in_path(char *command) {
char *path = getenv("PATH");
char *path_copy = strdup(path);
char *token = strtok(path_copy, ":");
char full_path[1024];

while (token != NULL) {
snprintf(full_path, sizeof(full_path), "%s/%s", token, command);
if (access(full_path, X_OK) == 0) {
free(path_copy);
return 1;
}
token = strtok(NULL, ":");
}

free(path_copy);
return 0;
