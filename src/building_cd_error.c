/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** minishell1
*/

#include "funct_minishell.h"
#include <errno.h>

int error_cd(program_t *minishell)
{
    int compt_command;

    for (compt_command = 0; minishell->command[compt_command];
    compt_command++);
    if (compt_command > 3) {
        my_putstr_error("Too many arguments.\n");
        return -1;
    }
    if (compt_command == 3) {
        if ((my_strcmp(minishell->command[1], "..") == -1) ||
        minishell->command[1][0] != '~' || minishell->command[1][0] != '-') {
            my_putstr_error("cd: Too many arguments.\n");
            return -1;
        }
    }
    return 0;
}

int error_funct_cd(program_t *minishell)
{
    if (error_cd(minishell) == -1) {
        return -1;
    }
    if (my_strlen(minishell->command[0]) != 2) {
        funct_error_cd(minishell->command[0],
        ": Command not found.\n");
        return -1;
    }
    if (command_cd(minishell) == -1) {
        return -1;
    }
    return 0;
}

int funct_error_on_cd(program_t *minishell)
{
    if (errno == ENOENT) {
        funct_error_cd(minishell->command[1],
        ": No such file or directory.\n");
    } else if (errno == EACCES) {
        funct_error_cd(minishell->command[1],
        ": Permission denied.\n");
    } else {
        funct_error_cd(minishell->command[1],
        ": Not a directory.\n");
    }
    return 0;
}