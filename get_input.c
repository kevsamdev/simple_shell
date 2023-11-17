#include "shell.h"

/* Define the node structure for aliases */
typedef struct Node
{
    char *name;
    char *value;
    struct Node *next;
} Node;

/* Define the info structure */
typedef struct Info

{

    char *arg;    /* Argument */
    char **argv;  /* Argument vector */
    Node *alias;  /* Alias list */
} Info;


/* Function Declarations */
void replace_alias(Info *info);
void replace_vars(Info *info);
void execute_command(Info *info);

/* Function Definitions */

int main(void)
{
    char input[256];  /* Assuming a maximum input size of 256 characters */

    /* Example info structure initialization */
    Info info;
    info.arg = NULL;
    info.argv = NULL;
    info.alias = NULL;

    printf("Enter a command: ");
    fgets(input, sizeof(input), stdin);

    /* Assuming you have a function to parse the input into arguments */
    /* parse_input(input, &info); */

    /* Replace aliases and variables before executing the command */
    replace_alias(&info);
    replace_vars(&info);

    /* Execute the command */
    execute_command(&info);

    return (0);
}
