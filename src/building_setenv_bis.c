/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** minishell1
*/

#include "funct_minishell.h"

char *funct_setenv_bis(program_t *minishell)
{
    char *tmp_env = NULL;

    if (my_strlen(minishell->command[0]) != 6) {
        funct_error_cd(minishell->command[0], ": Command not found.\n");
        return 0;
    }
    if (minishell->command[2] == NULL) {
        tmp_env = concat(minishell->command[1], "=", "");
    } else {
        tmp_env = concat(minishell->command[1], "=", minishell->command[2]);
    }
    return tmp_env;
}

int funct_alph_error_one(char const *command)
{
    for (int i = 0; command[i]; i++) {
        if ((command[i] < 'a' || command[i] > 'z') && (command[i] < 'A'
        || command[i] > 'Z') && command[i] != '=') {
            return -1;
        }
    }
    return 0;
}

int funct_alph_error_two(char const *command)
{
    for (int i = 0; command[i]; i++) {
        if ((command[i] < 'a' || command[i] > 'z') && (command[i] < 'A'
        || command[i] > 'Z')) {
            return -1;
        }
    }
    return 0;
}