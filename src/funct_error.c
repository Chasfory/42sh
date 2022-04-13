/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** minishell1
*/

#include "funct_minishell.h"

int my_putstr_error(char const *str)
{
    write(2, str, my_strlen(str));
    return 0;
}

int funct_error_cd(char const *command, char *const message)
{
    my_putstr_error(command);
    my_putstr_error(message);
    return 0;
}

int funct_error_env(char const *command)
{
    my_putstr_error("env: '");
    my_putstr_error(command);
    my_putstr_error("': No such file or directory\n");
    return 0;
}

void funct_error_path_segment_fault(int pich)
{
    if (WCOREDUMP(pich)) {
        my_putstr_error("Segmentation fault (core dump)\n");
    } else {
        my_putstr_error("Segmentation fault\n");
    }
}

void funct_error_path_maths(int pich)
{
    if (WCOREDUMP(pich)) {
        my_putstr_error("Floating exception (core dump)\n");
    } else {
        my_putstr_error("Floating exception\n");
    }
}