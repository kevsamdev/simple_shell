#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s status\n", argv[0]);
        return 1;
    }

    int status = atoi(argv[1]);
    printf("Exiting with status %d\n", status);
    exit(status);
}
