#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "shell.h"

char **tokenizeCommand(const char *command)
{
	const char delimiter[] = " ";

	char **tokens = malloc(sizeof(char *));
	if (tokens == NULL)
	{
		perror("Error allocating memory");
		exit(EXIT_FAILURE);
	}

	char *token = strtok(strdup(command), delimiter);
	int count = 0;
	while (token != NULL)
	{
		tokens = realloc(tokens, (count + 2) * sizeof(char *));
		if (tokens == NULL)
		{
			perror("Error reallocating memory");
			exit(EXIT_FAILURE);
		}
		tokens[count] = strdup(token);
		count++;
		token = strtok(NULL, delimiter);
	}
	tokens[count] = NULL;

	return (-1);

}

int executeComma80nd(const char *const *tokens)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Error forking");
		return (-1);
	}

	if (pid == 0)
	{
		if (execvp(tokens[0], (char *const *)tokens) == -1)
		{
			perror("Error executing command");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;
		waitpid(pid, &status, 0);

		if (WIFEXITED(status))
		{
			return (WEXITSTATUS(status));
		}
		else
		{
			return (-1);
		}
	}
}

int main(void)
{
	const char *command = "ls -l";
	char **tokens = tokenizeCommand(command);
	int status = executeCommand((const char *const *)tokens);

	for (int i = 0; tokens[i] != NULL; i++)
	{
		free(tokens[i]);
	}
	free(tokens);

	return (status);
}
