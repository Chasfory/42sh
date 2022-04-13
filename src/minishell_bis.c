/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-2-42sh-laetitia.bousch
** File description:
** minishell_bis
*/

#include "funct_minishell.h"

void minishell_prog_bis(program_t *minishell, int i, int compt)
{
    compt = funct_pipes_redirect(minishell, minishell->nbr_command[i]);
    if (compt != 1)
        compt = heart_of_buildings(minishell, minishell->nbr_command[i]);
    if (compt != 1)
        compt = find_path(minishell);
}

int funct_pipes_redirect(program_t *minishell, char *lineptr)
{
    int tmp = my_strlen(lineptr);

    if (lineptr[tmp - 1] == '\n') {
        lineptr[tmp - 1] = '\0';
    }
    lineptr = clean_str(lineptr);
    minishell->command = str_to_word_array(lineptr, ' ');
    for (int i = 0; minishell->command[i] != NULL; i++) {
        if (minishell->command[i][0] == '|' &&
            minishell->command[i][1] == '\0') {
            funct_pipes(minishell, lineptr);
            return 1;
        }
    }
    return 0;
}

void funct_and_bis(char **and_separator, program_t *minishell)
{
    int compt = 0;

    for (int j = 0; and_separator[j] != NULL; j++) {
        compt = funct_pipes_redirect(minishell, and_separator[j]);
        if (compt != 1)
            compt = heart_of_buildings(minishell, and_separator[j]);
        if (compt != 1)
            compt = find_path(minishell);
        if (funct_and(minishell) == 2) {
            return;
        }
        compt = 0;
    }
}

void funct_or_bis(char **or_separator, program_t *minishell)
{
    int compt = 0;

    for (int j = 0; or_separator[j] != NULL; j++) {
        compt = funct_pipes_redirect(minishell, or_separator[j]);
        if (compt != 1)
            compt = heart_of_buildings(minishell, or_separator[j]);
        if (compt != 1)
            compt = find_path(minishell);
        if (funct_or(minishell) == 2) {
            return;
        }
        compt = 0;
    }
}