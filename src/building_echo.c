/*
** EPITECH PROJECT, 2021
** building_echo..c
** File description:
** a function that build the echo function
*/

#include "funct_minishell.h"
#include "my.h"

int funct_echo(program_t *minishell)
{
    for (int i = 1; minishell->command[i]; i++) {
        if (i > 1)
            my_putstr(" ");
        my_putstr(minishell->command[i]);
    }
    my_putstr("\n");
    return 0;
}