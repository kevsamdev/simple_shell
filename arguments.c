#include <stdio.h>
#include "shell.h"

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *
 * Return: 0 success, or an error code if insufficient arguments are provided.
 */
int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return (1);
	}

	char *filename = argv[1];

	/* Your code to handle the filename or perform other operations */

	printf("Filename: %s\n", filename);

	return (0);
}

