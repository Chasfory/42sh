/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** minishell1
*/

#include "funct_minishell.h"

int funct_setenv_tree(program_t *minishell, char *tmp_env)
{
    char **bis_env = NULL;
    int tmp = 0;

    for (int i = 0; minishell->copy_env[i]; i++) {
        if (strcmp_env(tmp_env, minishell->copy_env[i]) == 0) {
            minishell->copy_env[i] = tmp_env;
            return 0;
        }
    }
    tmp = my_strlen_env(minishell->copy_env);
    bis_env = malloc(sizeof(char *) * (tmp));
    if (bis_env == NULL) {
        return -1;
    }
    bis_env = minishell->copy_env;
    minishell->copy_env = bis_env;
    minishell->copy_env[tmp] = tmp_env;
    minishell->copy_env[tmp + 1] = NULL;
    return 0;
}

int funct_error_setenv_bis(program_t *minishell)
{
    if (funct_alph_error_one(minishell->command[1]) == -1) {
        funct_error_cd(minishell->command[0],
        ": Variable name must contain alphanumeric characters.\n");
        return -1;
    }
    if (minishell->command[2] != NULL) {
        if (funct_alph_error_two(minishell->command[2]) == -1) {
            funct_error_cd(minishell->command[0],
            ": Variable name must contain alphanumeric characters.\n");
            return -1;
        }
    }
    return 0;
}

int funct_error_setenv(program_t *minishell)
{
    int i;

    for (i = 0; minishell->command[i]; i++);
    if (i > 3) {
        my_putstr_error("setenv: Too many arguments.\n");
        return -1;
    }
    if (minishell->command[1] == NULL) {
        funct_env_setenv(minishell);
        return 0;
    }
    else if (funct_error_setenv_bis(minishell) == -1) {
        return -1;
    }
    return 0;
}

int funct_setenv(program_t *minishell)
{
    char *tmp_env = NULL;

    if (funct_error_setenv(minishell) == -1) {
        return -1;
    }
    if (minishell->command[1] != NULL) {
        tmp_env = funct_setenv_bis(minishell);
        if (tmp_env == NULL)
            return -1;
        if (funct_setenv_tree(minishell, tmp_env) == -1)
            return -1;
    }
    return 0;
}