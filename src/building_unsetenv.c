/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** minishell1
*/

#include "funct_minishell.h"

int strcmp_env(char const *av1, char const *av2)
{
    int i = 0;

    for (; av1[i] == av2[i]; i++) {
        if (av2[i] == '=')
            return 0;
    }
    return (av1[i] - av2[i]);
}

int funct_unsetenv_error(program_t *minishell)
{
    if (minishell->command[1] == NULL) {
        my_putstr_error("unsetenv: Too few arguments.\n");
        return -1;
    }
    if (my_strlen(minishell->command[0]) != 8) {
        funct_error_cd(minishell->command[0], ": Command not found.\n");
        return -1;
    }

    return 0;
}

int funct_unsetenv(program_t *minishell)
{
    char **tmp = malloc(sizeof(char *) *
    (my_strlen_env(minishell->copy_env) + 1));
    int i = 0;

    if (funct_unsetenv_error(minishell) == -1) {
        return 0;
    }
    if (tmp == NULL)
        return -1;
    for (int j = 0; minishell->copy_env[j] != NULL; j++) {
        if (my_strcmp_tree(minishell->copy_env[j],
        minishell->command[1]) != 0) {
            tmp[i] = minishell->copy_env[j];
            i++;
        }
    }
    tmp[i] = NULL;
    minishell->copy_env = tmp;
    return 0;
}