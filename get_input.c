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
