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
                perror("Error forking process");
                return (-1);
        }

        int status;

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
