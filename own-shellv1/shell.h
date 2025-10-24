#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

// ANSI COLORS
#define Y   "\033[33m"  // Yellow
#define G   "\033[32m"  // Green
#define RED "\033[31m"  // Red
#define C   "\033[36m"  // Cyan
#define RST "\033[0m"   // Reset

// DELIMIT FOR SPACE
#define DEL " \t\n\v\f\r"


typedef struct s_builtin
{
    const char *builtin_name;
    int (*foo)(char **);
} t_builtin;

// WRAPPERS + FUNCTIONS
void getcwd_wrapper(char *, size_t);
void printbanner();
void *malloc_wrapper(size_t);
void *realloc_wrapper(void *, size_t);
int shell_exit(char **);
int shell_env(char **);
void execvp_wrapper(const char *, char **args);
pid_t fork_wrapper();

#endif