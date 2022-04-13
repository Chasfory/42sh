/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-2-minishell2-laetitia.bousch
** File description:
** init_struct
*/

#include "funct_minishell.h"

program_t init_srtuct(char **env)
{
    program_t minishell;

    minishell.copy_env = env;
    minishell.command = NULL;
    minishell.path = recup_path(env, &minishell);
    minishell.nbr_command = NULL;
    minishell.last_value = 0;
    minishell.return_value = 0;
    minishell.history = NULL;
    minishell.alias = NULL;
    minishell.var = NULL;
    push_back_var(&minishell.var, "?", "0");
    return minishell;
}