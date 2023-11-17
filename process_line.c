#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "shell.h"

#define READ_SIZE 1024

static ssize_t read_char(int fd, char *buffer, size_t *pos)
{
	if (*pos == 0)
	{
		ssize_t bytesRead = read(fd, buffer, READ_SIZE);
		if (bytesRead <= 0)
		{
			return (bytesRead);
		}
	}
	return (buffer[(*pos)++]);
}


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
