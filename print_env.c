#include "shell.h"

/**
 * env_shell - Prints the current environment.
 * @envp: The strings array with environment variables.
 */
void env_shell(char *envp[])
{
	int i = 0;

	while (envp[i] != NULL)
	{
		printf("%s\n", envp[i]);
		i++;
	}
}

/**
 * main - Example usage of the shell program with env built-in.
 * @argc: Number of command-line arguments.
 * @argv: This is command-line argument strings array.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[], char *envp[])
{
	char input[100];
	(void)argc;
	(void)argv;

	while (1)
	{
		size_t len = strlen(input);
		printf("Shell> ");
		fgets(input, sizeof(input), stdin);
		if (len > 0 && input[len - 1] == '\n')
		{
			input[len - 1] = '\0';
		}

		if (strcmp(input, "env") == 0)
		{
			env_shell(envp);
		}

		printf("Command: %s\n", input);
	}
	return (0);
}

