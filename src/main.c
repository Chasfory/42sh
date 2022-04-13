/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** minishell1
*/

#include "funct_minishell.h"

int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;
    if (env[0] == NULL || ac != 1) {
        return 84;
    }
    minishell(env);
    return 0;
}
