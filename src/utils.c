/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-2-minishell2-laetitia.bousch
** File description:
** utils
*/

#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>

#include "funct_minishell.h"

static int access_path_recup(char const *path)
{
    if (access(path, F_OK) != 0) {
        return 1;
    }
    if (access(path, X_OK) != 0) {
        my_putstr_error("permission denied\n");
        return 2;
    }
    return 0;
}

static int recup_path_bis(program_t *minishell, int compt, int i)
{
    if (access_path_recup(minishell->command[0]) == 0) {
        compt = 1;
    } else {
        minishell->path_command = concat(minishell->path[i], "/",
        minishell->command[0]);
    }
    if (access_path_recup(minishell->path_command) == 0) {
        compt = 1;
    }
    return compt;
}

void path(program_t *minishell)
{
    int compt = 0;

    for (int i = 0; minishell->path[i] && compt == 0; i++) {
        minishell->path_command = malloc(sizeof(char) *
        (my_strlen(minishell->path[i]) +
        my_strlen(minishell->command[0]) + 2));
        compt = recup_path_bis(minishell, compt, i);
    }
    if (compt != 1) {
        funct_error_cd(minishell->command[0], ": Command not found.\n");
    }
}

pipe_t init_struct_pipe(void)
{
    pipe_t struct_pipe;

    struct_pipe.command = NULL;
    struct_pipe.error = 0;
    struct_pipe.num = 0;
    return struct_pipe;
}