#include <stdio.h>
#include <stdlib.h>

/**
 * exit_shell - Exits the shell program.
 */
void exit_shell(void)
{
	printf("Exiting the shell...\n");
	exit(EXIT_SUCCESS);
}

/**
 * main - Example usage of the shell program.
 *
 * Return: Always 0.
 */
int main(void)
{
	char input[100];

	while (1)
	{
		printf("Shell> ");
		fgets(input, sizeof(input), stdin);
			size_t len = strlen(input);
		if (len > 0 && input[len - 1] == '\n')
		{
			input[len - 1] = '\0';
		}

		if (strcmp(input, "exit") == 0)
		{
			exit_shell();
		}

		printf("Command: %s\n", input);
	}

	return (0);
}

