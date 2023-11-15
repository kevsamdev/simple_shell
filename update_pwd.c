#include <stdio.h>
#include <unistd.h>
#include "shell.h"

void update_pwd(void)
{
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        setenv("PWD", cwd, 1);
    }
    else
    {
        perror("getcwd");
    }
}

int main(void)
{
    // Sample usage of update_pwd function
    update_pwd();

    return 0;
}
