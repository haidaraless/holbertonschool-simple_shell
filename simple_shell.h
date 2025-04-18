#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

/**
 * File: simple_shell.h
 * Desc: a header file containing the standard library includes,
 * and function prototypes of the project.
 */

/* Standard Library Includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* function prototypes */
char **parse_input(char *line);
void execute_command(char **args);
void free_tokens(char **tokens);
extern char **environ;
int check_command_in_path(char *command);
#endif /* SIMPLE_SHELL_H */
