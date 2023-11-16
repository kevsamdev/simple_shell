#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

int main(int argc, char *argv[]) {
    int status;

    if (argc != 2) {
        printf("Usage: %s status\n", argv[0]);
        return 1;
    }

    status = atoi(argv[1]);
    printf("Exiting with status %d\n", status);
    exit(status);
}
