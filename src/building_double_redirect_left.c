/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-2-minishell2-laetitia.bousch
** File description:
** building_double_redirect_left
*/

#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>

#include "funct_minishell.h"

int funct_recup_fd(int fd, program_t *minishell, int i)
{
    char *lineptr = NULL;
    size_t n = 0;

    fd = open("tmp", O_CREAT | O_TRUNC | O_WRONLY, 0664);
    if (isatty(0))
        my_putstr(" > ");
    while (getline(&lineptr, &n, stdin) != -1) {
        if (my_strcmp(lineptr, minishell->command[i + 1]) == 0) {
            break;
        } else {
            write(fd, lineptr, my_strlen(lineptr));
            if (isatty(0))
                my_putstr(" > ");
            free(lineptr);
            lineptr = NULL;
            n = 0;
        }
    }
    close(fd);
    return fd;
}

int funct_double_redirect_left(program_t *minishell, int i)
{
    int fd = 0;
    int error = 0;
    pid_t child = 0;

    fd = funct_recup_fd(fd, minishell, i);
    fd = open("tmp", O_RDONLY, 0664);
    child = fork();
    if (child == 0) {
        funct_child_left(minishell, fd, i);
    } else {
        wait(&error);
        funct_error_redirect(error);
    }
    close(fd);
    return 0;
}