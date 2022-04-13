/*
** EPITECH PROJECT, 2021
** command_edit.c
** File description:
** a function that replace var and aliases in the command by their values
*/

#include "funct_minishell.h"

static int special_char(char *str)
{
    for (int j = 0; str[j] != '\0'; j++)
        if (str[j] == '\\' || str[j] == '\'' || str[j] == '"' || str[j] == '`')
            return (1);
    return (0);
}

int command_edit(program_t *minishell, char *lineptr)
{
    change_command_alias(minishell);
    replace_called_variables(minishell);
    if (special_char(lineptr) == 1) {
        system(lineptr);
        return (1);
    }
    return (0);
}