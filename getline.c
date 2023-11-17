#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
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

char *custom_getline(int fd)
{
	char *line = NULL;
	size_t line_size = 0;
	size_t pos = 0;

	while (1)
	{
		char ch;
		ssize_t result = read_char(fd, &ch, &pos);

		if (result < 0)
		{
			free(line);
			perror("Error reading from file");
			return (NULL);
		}

		if (result == 0 || ch == '\n')
		{
			if (line_size > 0 || ch == '\n')
			{
				line = realloc(line, line_size + 2);
				if (line == NULL)
				{
					perror("Error reallocating memory");
					exit(EXIT_FAILURE);
				}
				line[line_size++] = ch;
			}

			line[line_size] = '\0';
			return (line);
		}
		else
		{
			line = realloc(line, line_size + 1);
			if (line == NULL)
			{
				perror("Error reallocating memory");
				exit(EXIT_FAILURE);
		}
		line[line_size++] = ch;
		}
	}
}

