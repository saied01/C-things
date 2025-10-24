#include "shell.h"

int shell_exit(char **args) 
{
    (void)args;

    exit(EXIT_SUCCESS);
}

int shell_env(char **args)
{
    // extern -> variable is defined somewhere (not here)
    // environ is defined on C runtime
    extern char **environ;

    (void)args;
    if (!environ)
        return 1;
    for (int i = 0; environ[i]; i++)
        printf("%s\n", environ[i]);

    return 0;
}