#include "shell.h"

// WRAPPERS

// MAN getcwd => On success, these functions return a pointer to a string
// containing the pathname  of  the  current  working  directory.
void getcwd_wrapper(char *buf, size_t size) 
{
    if (NULL == getcwd(buf, size)) 
        perror("getcwd FAILED");
}


void *malloc_wrapper(size_t size) 
{
    void *ptr;

    if (size == 0)
        return NULL;
    ptr = malloc(size);
    if (!ptr)
    {
        perror(RED"malloc failed"RST);
        exit(EXIT_FAILURE);
    }
    return ptr;
}


void *realloc_wrapper(void *ptr, size_t size)
{
    void *new_ptr;

    new_ptr = realloc(ptr, size);
    if (!new_ptr && size == 0)
    {
        perror(RED"realloc failed"RST);
        exit(EXIT_FAILURE);
    }
    return new_ptr;
}


pid_t fork_wrapper()
{
    pid_t pid = fork();

    if (pid == -1)
    {
        perror(RED"fork failed"RST);
        exit(EXIT_FAILURE);
    }

    return pid;
}


void execvp_wrapper(const char *file, char *argv[])
{
    if (!file || !argv)
    {
        fprintf(stderr, RED"invalid arguments\n"RST);
        exit(EXIT_FAILURE);
    }
    if (execvp(file, argv) == -1)
    {
        perror(RED"exec failed"RST);
        exit(EXIT_FAILURE);
    }
}



void printbanner() 
{
    printf(
        "███████╗██╗  ██╗███████╗██╗     ██╗    ██╗   ██╗ ██╗\n"
        "██╔════╝██║  ██║██╔════╝██║     ██║    ██║   ██║███║\n"
        "███████╗███████║█████╗  ██║     ██║    ██║   ██║╚██║\n"
        "╚════██║██╔══██║██╔══╝  ██║     ██║    ╚██╗ ██╔╝ ██║\n"
        "███████║██║  ██║███████╗███████╗███████╗╚████╔╝  ██║\n"
        "╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝ ╚═══╝   ╚═╝\n"
    );
}