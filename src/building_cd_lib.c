/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** minishell1
*/

#include "funct_minishell.h"
#include <errno.h>

int my_strcmp_tree(char const *s1, char const *s2)
{
    int i;

    for (i = 0; s1[i] == s2[i]; i++) {
        if (s2[i + 1] == '\0' && s1[i + 1] == '=') {
            return 0;
        }
    }
    return (s1[i] - s2[i]);
}

int my_strlen_env(char **clone_env)
{
    int len = 0;

    for (; clone_env[len]; len++);
    return (len);
}