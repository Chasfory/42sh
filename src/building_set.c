/*
** EPITECH PROJECT, 2021
** building_set.c
** File description:
** a function that reproduce the comportement of the set function in tcsh
*/

#include "funct_minishell.h"
#include "my.h"

#include <stdlib.h>

int my_strchr(char *str, char c)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == c)
            return (i);
    }
    return (-1);
}

void set_var(program_t *minishell, char *param)
{
    var_t *exist;
    int idx = my_strchr(param, '=');
    char *name = malloc(sizeof(char) * (idx + 1));

    name = strncpy(name, param, idx);
    name[idx + 1] = '\0';
    exist = var_exist(minishell->var, name);
    if (exist)
        update_var(exist, &param[idx+1]);
    else
        push_back_var(&minishell->var, name, &param[idx+1]);
    free(name);
}

int funct_set(program_t *minishell)
{
    for (int i = 0; minishell->command[i]; i++) {
        if (my_strchr(minishell->command[i], '=') != -1)
            set_var(minishell, minishell->command[i]);
    }
    return (0);
}