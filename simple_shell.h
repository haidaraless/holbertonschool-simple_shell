#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

/**
 * simple_shell.h - a header file containing the function prototypes of the project
 */

/* function prototypes */
char **parse_input(char *line);
void execute_command(char **args);

#endif
