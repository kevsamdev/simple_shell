#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LENGTH 1024

void print_prompt() {
    printf("simple-shell> ");
}

char* read_command() {
    char *command = (char *) malloc(MAX_LENGTH * sizeof(char));
    fgets(command, MAX_LENGTH, stdin);
    return command;
}

void execute_command(char *command) {
    if (strcmp(command, "exit\n") == 0) {
        exit(0);
    } else {
        system(command);
    }
}

int main() {
    while (1) {
	char *command = read_command();
        print_prompt();
        execute_command(command);
        free(command);
    }
    return 0;
}
