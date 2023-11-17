#include "shell.h"

int main(int argc, char *argv[])
{
	int status = atoi(argv[1]);
	if (argc != 2)
	{
		printf("Usage: %s status\n", argv[0]);
		return (1);
	}

	printf("Exiting with status %d\n", status);

	exit(status);
}

