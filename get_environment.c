#include "shell.h"

/**
 * get_environment_variable - Get the value of an environment variable.
 * @variable: This names environment variable.
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
