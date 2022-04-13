/*
** EPITECH PROJECT, 2021
** replace_called_variables.c
** File description:
** a function that replace called variables by their value 
*/

#include "funct_minishell.h"

#include <stdlib.h>

static void replace_env_var(program_t *minishell, int nb)
{
    for (int i = 0; minishell->copy_env[i]; i++) {
        if (my_strcmp_tree(minishell->copy_env[i],
            &minishell->command[nb][1]) == 0) {
                free(minishell->command[nb]);
                minishell->command[nb] = my_strdup(&minishell->copy_env[i][
                my_strchr(minishell->copy_env[i], '=') + 1]);
        }
    }
}

static void replace_var(program_t *minishell, int nb)
{
    var_t *exist;

    exist = var_exist(minishell->var, &minishell->command[nb][1]);
    if (exist) {
        free(minishell->command[nb]);
        minishell->command[nb] = my_strdup(exist->value);
    } else {
        replace_env_var(minishell, nb);
    }
}

void replace_called_variables(program_t *minishell)
{
    for (int i = 0; minishell->command[i]; i++) {
        if (minishell->command[i][0] == '$')
            replace_var(minishell, i);
    }
}