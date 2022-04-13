/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** minishell1
*/

#include "funct_minishell.h"

char **recup_path(char **env, program_t *minishell)
{
    minishell->path_first = NULL;
    char **path_finish = NULL;

    for (int i = 0; env[i]; i++) {
        if (my_strcmp(env[i], "PATH=") == 0) {
            minishell->path_first = my_strdup(env[i] + 5);
            if (minishell->path_first == NULL) {
                return NULL;
            }
        }
    }
    path_finish = str_to_word_array(minishell->path_first, ':');
    return path_finish;
}

static void free_minishell(program_t *minishell)
{
    if (isatty(0))
        my_putstr("exit\n");
    if (minishell->command == NULL) {
        return;
    }
    for (int i = 0; minishell->command[i]; i++) {
        free(minishell->command[i]);
    }
    free(minishell->command);
    for (int i = 0; minishell->nbr_command[i]; i++) {
        free(minishell->nbr_command[i]);
    }
    free(minishell->nbr_command);
    return;
}

static void minishell_prog(program_t *minishell)
{
    char **and_separator = NULL;
    char **or_separator = NULL;
    int compt = 0;

    for (int i = 0; minishell->nbr_command[i] != NULL; i++) {
        and_separator = str_to_word_array_string(minishell->nbr_command[i],
                                                "&&");
        or_separator = str_to_word_array_string(minishell->nbr_command[i],
                                                "||");
        if (and_separator[1] != NULL) {
            funct_and_bis(and_separator, minishell);
        } else if (or_separator[1] != NULL) {
            funct_or_bis(or_separator, minishell);
        } else {
            minishell_prog_bis(minishell, i, compt);
            compt = 0;
        }
    }
}

int minishell(char **env)
{
    program_t minishell = init_srtuct(env);
    char *lineptr = NULL;
    size_t n = 0;

    if (isatty(0))
        my_putstr("$> ");
    while (getline(&lineptr, &n, stdin) != -1) {
        if (lineptr[0] != '\n') {
            minishell.nbr_command = str_to_word_array(lineptr, ';');
            push_back_history(&minishell, &minishell.history, lineptr);
            minishell_prog(&minishell);
            lineptr = NULL;
            n = 0;
        }
        if (isatty(0))
            my_putstr("$> ");
    }
    free(lineptr);
    free_minishell(&minishell);
    return 0;
}