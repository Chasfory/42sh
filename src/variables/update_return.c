/*
** EPITECH PROJECT, 2021
** update_return.c
** File description:
** a function that update the return value
*/

#include "funct_minishell.h"

#include <stdlib.h>

static char *my_itoa(int nb)
{
    int len = 1;
    char *str;

    for (int a = nb; a > 9; len++)
        a = a / 10;
    str = malloc(sizeof(char) * (len + 1));
    str[len] = '\0';
    for (int i = len - 1; i >= 0; i--) {
        str[i] = 48 + (nb % 10);
        nb = nb / 10;
    }
    return (str);
}

void update_return(program_t *minishell, int new)
{
    update_var(minishell->var, my_itoa(new));
}