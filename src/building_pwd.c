/*
** EPITECH PROJECT, 2021
** command_gestion.h
** File description:
** minishell1
*/

#include "funct_minishell.h"

int funct_pwd(program_t *minishell)
{
    (void)minishell;
    if (my_strlen(minishell->command[0]) != 3) {
        funct_error_cd(minishell->command[0], ": Command not found.\n");
        return 0;
    }
    my_putstr(getcwd(NULL, 0));
    my_putchar('\n');
    return 0;
}