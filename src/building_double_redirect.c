/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-2-minishell2-laetitia.bousch
** File description:
** building_double_redirect
*/

#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>

#include "funct_minishell.h"

int funct_double_redirect_right(program_t *minishell, int i)
{
    int fd = 0;
    int error = 0;
    pid_t child = 0;

    fd = open(minishell->command[i + 1], O_APPEND | O_CREAT | O_WRONLY, 0664);
    child = fork();
    if (child == 0) {
        funct_child(minishell, fd, i);
    } else {
        wait(&error);
        funct_error_redirect(error);
    }
    return 0;
}