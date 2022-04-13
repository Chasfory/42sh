/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-2-minishell2-laetitia.bousch
** File description:
** building_redirect_left
*/

#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>

#include "funct_minishell.h"

void funct_child_left(program_t *minishell, int fd, int tmp)
{
    int value = 0;

    if (dup2(fd, 0) == -1) {
        funct_error_cd(strerror(errno), "\n");
        return;
    }
    clean_str(minishell->command[0]);
    minishell->command[tmp] = NULL;
    for (size_t i = 0; i < ARRAY_SIZE(COMMAND_GESTION); i++) {
        if (value != 1) {
            value = is_valid_opt(minishell->command[0],
            &COMMAND_GESTION[i], i, minishell);
        }
    }
    if (value != 1) {
        find_path(minishell);
    }
    exit(0);
}

static int funct_simple_redirect_left(program_t *minishell, int i)
{
    int fd = 0;
    int error = 0;
    pid_t child = 0;

    fd = open(minishell->command[i + 1], O_RDONLY, 0664);
    child = fork();
    if (child == 0) {
        funct_child_left(minishell, fd, i);
    } else {
        wait(&error);
        funct_error_redirect(error);
    }
    return 0;
}

int funct_redirect_left(program_t *minishell)
{
    int i = 1;

    for (; minishell->command[i] != NULL && minishell->command[i][0] != '<';
        i++);
    if (minishell->command[i] == NULL || minishell->command[i + 1] == NULL) {
        return my_putstr_error("Missing name for redirect.\n");
    }
    if (minishell->command[i][1] == '<') {
        funct_double_redirect_left(minishell, i);
    } else {
        funct_simple_redirect_left(minishell, i);
    }
    return 0;
}