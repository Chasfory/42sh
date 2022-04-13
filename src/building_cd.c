/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** minishell1
*/

#include "funct_minishell.h"
#include <errno.h>

void setenv_cd(program_t *minishell, char *env_name, char *content)
{
    int compt = 0;
    char **bis_env = NULL;

    for (int i = 0; minishell->copy_env[i]; i++) {
        if (my_strcmp(minishell->copy_env[i], env_name) == 0) {
            minishell->copy_env[i] = my_strcat(env_name, content);
            compt = 1;
        }
    }
    if (compt == 0) {
        compt = my_strlen_env(minishell->copy_env);
        bis_env = malloc(sizeof(char *) * (compt) + 1);
        if (bis_env == NULL)
            return;
        bis_env = minishell->copy_env;
        minishell->copy_env = bis_env;
        minishell->copy_env[compt] = my_strcat(env_name, content);
        minishell->copy_env[compt + 1] = NULL;
    }
}

int command_cd_bis(program_t *minishell, int tmp)
{
    if (my_strcmp(minishell->command[1], "~") == 0) {
        for (int i = 0; minishell->copy_env[i]; i++) {
            if (my_strcmp(minishell->copy_env[i], "HOME=") == 0)
                minishell->command[1] = my_strdup(minishell->copy_env[i] + 5);
        }
    }
    else if (my_strcmp(minishell->command[1], "-") == 0) {
        for (int i = 0; minishell->copy_env[i]; i++) {
            if (my_strcmp(minishell->copy_env[i], "OLDPWD=") == 0) {
                minishell->command[1] = my_strdup(minishell->copy_env[i] + 7);
                tmp = 0;
            }
        }
        if (tmp == 1) {
            my_putstr_error(": No such file or directory.\n");
            return -1;
        }
    }
    return 0;
}

int command_cd(program_t *minishell)
{
    int tmp = 1;

    if (minishell->command[1] == NULL) {
        for (int i = 0; minishell->copy_env[i]; i++) {
            if (my_strcmp(minishell->copy_env[i], "HOME=") == 0)
                minishell->command[1] = my_strdup(minishell->copy_env[i] + 5);
        }
    } else {
        if (command_cd_bis(minishell, tmp) == -1) {
            return -1;
        }
    }
    return 0;
}

int funct_cd(program_t *minishell)
{
    char *old_path = getcwd(NULL, 0);
    char *new_path = NULL;

    if (error_funct_cd(minishell) == -1) {
        return 0;
    }
    if (chdir(minishell->command[1]) == -1) {
        funct_error_on_cd(minishell);
        return 0;
    } else {
        new_path = getcwd(NULL, 0);
        setenv_cd(minishell, "PWD=", new_path);
        setenv_cd(minishell, "OLDPWD=", old_path);
    }
    return 0;
}