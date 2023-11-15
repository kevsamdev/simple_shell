#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 * main - Main function of the program.
 *
 * Description: This function attempts to open a file for reading,
 * handles errors if the file opening fails, and then closes the file
 * before exiting.
 *
 * Return: 0 on success, or an error code if file opening fails.
 */
int main(void)
{
	FILE *file = fopen("nonexistent_file.txt", "r");

	if (file == NULL)
	{
		perror("Error");
		exit(1);
	}

	fclose(file);

	return (0);
}
