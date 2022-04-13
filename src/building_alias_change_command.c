/*
** EPITECH PROJECT, 2021
** building_alias_change_command.c
** File description:
** changes commands depending on existing aliases
*/

#include "funct_minishell.h"

void change_command_alias(program_t *minishell)
{
    alias_t *alias;

    for (int i = 0; minishell->command[i]; i++) {
        alias = alias_exists(&minishell->alias, minishell->command[i]);
        if (alias != NULL) {
            free(minishell->command[i]);
            minishell->command[i] = strdup(alias->replace);
        }
    }
}
