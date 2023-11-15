#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printPrompt(void);
char *readCommand(void);
char **tokenizeCommand(const char *command);
int executeCommand(const char * const *tokens);

#endif
