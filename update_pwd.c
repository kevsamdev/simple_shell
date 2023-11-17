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
    update_pwd();

    return 0;
}
