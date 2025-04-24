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
/*void free_tokens(char **tokens);*/


int has_path_env(void);
char **parse_line(char *line);
int execute_cmd(char **args);
extern char **environ;
char *find_command(char *command);
extern int last_status;

#endif /* SIMPLE_SHELL_H */
