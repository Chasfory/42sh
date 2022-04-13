/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** minishell1
*/

#include "funct_minishell.h"

int funct_env_setenv(program_t *minishell)
{
    for (int i = 0; minishell->copy_env[i]; i++) {
        my_putstr(minishell->copy_env[i]);
        my_putchar('\n');
    }
    return 0;
}

int funct_env(program_t *minishell)
{
    if (minishell->command[1] != NULL) {
        my_putstr_error("env: Too many arguments\n");
        return 0;
    }
    if (my_strlen(minishell->command[0]) != 3) {
        funct_error_cd(minishell->command[0], ": Command not found.\n");
        return 0;
    }
    for (int i = 0; minishell->copy_env[i]; i++) {
        my_putstr(minishell->copy_env[i]);
        my_putchar('\n');
    }
    return 0;
}