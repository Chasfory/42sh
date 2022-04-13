/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-2-42sh-laetitia.bousch
** File description:
** building_and_or
*/

#include "funct_minishell.h"

int funct_or(program_t *minishell)
{
    if (my_getnbr(minishell->var->value) == -1) {
        return 0;
    }
    return 2;
}

int funct_and(program_t *minishell)
{
    if (my_getnbr(minishell->var->value) == -1) {
        return 2;
    }
    return 0;
}