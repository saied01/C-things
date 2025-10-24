#include "shell.h"


int status = 0;





// if function is builtin call it 
// (basic functions to call, can add more)
t_builtin g_builtin[] =
{
//  {.builtin_name="echo", .foo=shell_echo},
    {.builtin_name="env", .foo=shell_env},
    {.builtin_name="exit", .foo=shell_exit},
    {.builtin_name="NULL"},
};
// for rest of builtins,
// could add every builtin and make pointer to already implemented function


// 3 - exec
// fork+execvp+wait

pid_t shell_launch(char **args)
{

    pid_t result;

    if (fork_wrapper() == 0)
        execvp_wrapper(args[0], args);
    else
        result = wait(&status);
    if (result == -1)
        perror("wait failed");
    if (WIFEXITED(status))
        status = WEXITSTATUS(status);
    
    return result;
        
}



void shell_exec(char **args)
{
    int i;
    const char *curr;

    i = 0;
    while ((curr = g_builtin[i].builtin_name))
    {
        if (strcmp(curr, args[0]) == 0)
        {
            status = g_builtin[i].foo(args);
            return;
        }
        ++i;
    }
    shell_launch(args);
}


// argv
// 2 - get tokens. 
// "ls -al" --> ['ls']
//          --> ['-al'] 
char **cell_split_line(char *line)
{
    char **tokens;
    unsigned int position;
    size_t bufsize;

    bufsize = BUFSIZ;
    tokens = malloc_wrapper(BUFSIZ * sizeof(char *));
    position = 0;

    // strtok() --> return a pointer to the next token, or NULL if
    // there are no more tokens.
    for (char *token = strtok(line, DEL); token; token=strtok(NULL, DEL))
    {
        tokens[position++] = token;
        if (position >= bufsize)
        {
            bufsize*=2;
            tokens = realloc_wrapper(tokens, bufsize);
        }


    }
    tokens[position] = NULL;
    return tokens;
}


char *shell_read_line() 
{

    char *buf;
    size_t bufsize;
    char cwd[BUFSIZ]; // BUFSIZ = 1024

    buf = NULL;

    getcwd_wrapper(cwd, sizeof(cwd));
    printf(C" %s "RST" $ ", cwd);

    if (getline(&buf, &bufsize, stdin) == -1) 
    {
        free(buf);
        buf = NULL;
        if (feof(stdin)) 
            printf(RED"[EOF]"RST);
        else 
            printf(RED"Getline failed."RST);
    }
    
    return buf;
}


int main(int argc, char **argv) 
{

    printbanner();
    char *line;
    char **args;

    // REPL
    // READ->EVAL->PRINT->LOOP
    // 1 - Get line
    while (line = shell_read_line()) 
    {

        // 2 - get tokens. 
        args = cell_split_line(line);

        // 3 - exec(vp)
        shell_exec(args);


        // 4 - FREE
        free(line);
        free(args);
    }
}