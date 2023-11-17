#include "shell.h"

int main(int argc, char *argv[])
{
	const char *command = argv[1];
    const char *variable = argv[2];

	if (argc < 3)
	{
		fprintf(stderr, "Usage: %s \n", argv[0]);
		return (1);
	}

	if (strcmp(command, "setenv") == 0)
	{
		const char *value = argv[3];

		if (argc != 4)
		{
			fprintf(stderr, "Usage: %s setenv VARIABLE VALUE\n", argv[0]);
			return (1);
		}

		if (setenv(variable, value, 1) != 0)
		{
			perror("setenv");
			return (1);
		}
	}
	else if (strcmp(command, "unsetenv") == 0)
	{
		if (argc != 3)
		{
			fprintf(stderr, "Usage: %s unsetenv VARIABLE\n", argv[0]);
			return (1);
		}

		if (unsetenv(variable) != 0)
		{
			perror("unsetenv");
			return (1);
		}
	}
	else
	{
		fprintf(stderr, "Unknown command: %s\n", command);
		return (1);
	}

	return (0);
}
