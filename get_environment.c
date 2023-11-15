#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 * get_environment_variable - Get the value of an environment variable.
 * @variable: The name of the environment variable.
 *
 * Return: The value of the environment variable, or NULL if not found.
 */
char *get_environment_variable(const char *variable)
{
	char *value = getenv(variable);

	return (value ? value : NULL);
}

/**
 * main - Example usage of the get_environment_variable function.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *home_dir = get_environment_variable("HOME");
	char *user_name = get_environment_variable("USER");

	if (home_dir != NULL)
	{
		printf("Home directory: %s\n", home_dir);
	}
	else
	{
		fprintf(stderr, "HOME environment variable not set.\n");
		return (EXIT_FAILURE);
	}

	if (user_name != NULL)
	{
		printf("User name: %s\n", user_name);
	}
	else
	{
		fprintf(stderr, "USER environment variable not set.\n");
		return (EXIT_FAILURE);
	}

	return (0);
}

