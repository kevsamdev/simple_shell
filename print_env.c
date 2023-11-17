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
