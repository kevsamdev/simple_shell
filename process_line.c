#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "shell.h"

#define READ_SIZE 1024


void process_line(const char *line)
{
    size_t i;
	
	(void)line;

    for (i = 0; line[i] != '\0'; ++i)
    {
        putchar(line[i]);
    }

    putchar('\n');
}
