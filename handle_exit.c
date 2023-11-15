#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	/* Check if the correct number of command-line arguments is provided*/
	if (argc != 2)
	{
		printf("Usage: %s status\n", argv[0]);
		return (1);
	}

	/* Convert the command-line argument to an integer*/
	int status = atoi(argv[1]);

	/* Print the exit status*/
	printf("Exiting with status %d\n", status);

	/* Exit the program with the specified status*/
	exit(status);
}

