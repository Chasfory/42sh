/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** minishell1
*/

#include "funct_minishell.h"

int funct_exit(program_t *minishell)
{
    if (minishell->command[1] != NULL) {
        my_putstr_error("exit: Expression Syntax.\n");
    }
    if (my_strlen(minishell->command[0]) != 4) {
        funct_error_cd(minishell->command[0], ": Command not found.\n");
        return 0;
    }
    for (int i = 0; minishell->command[i] != NULL; i++) {
        free(minishell->command[i]);
    }
    free(minishell->command);
    free(minishell->path);
    my_putstr("exit\n");
    exit(0);
}