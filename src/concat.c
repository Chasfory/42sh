/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** minishell1
*/

#include "funct_minishell.h"

char *concat(char const *a, char const *b, char const *c)
{
    int a_size = my_strlen(a);
    int b_size = my_strlen(b);
    int c_size = my_strlen(c);
    char *tmp = malloc(sizeof(char) * (a_size + b_size + c_size + 1));

    if (tmp == NULL) {
        return NULL;
    }
    my_strcpy(tmp, a);
    my_strcpy(tmp + a_size, b);
    my_strcpy(tmp + a_size + b_size, c);
    return tmp;
}