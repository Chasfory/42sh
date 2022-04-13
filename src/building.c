/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** minishell1
*/

#include "funct_minishell.h"

static int my_strict_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (; s1[i] == s2[i]; i++) {
        if (s1[i + 1] == '\0' && s2[i + 1] == '\0')
            return (0);
    }
    return (s1[i] - s2[i]);
}

int is_valid_opt(char const *av, minishell_t const *arg,
                int i, program_t *minishell)
{
    if (my_strict_strcmp(av, arg->comd) == 0) {
        update_return(minishell, COMMAND_GESTION[i].handler(minishell));
        return 1;
    }
    return 0;
}

static int funct_redirect(program_t *minishell)
{
    for (int i = 0; minishell->command[i] != NULL; i++) {
        if (minishell->command[i][0] == '>') {
            funct_redirect_right(minishell);
            return 1;
        }
        if (minishell->command[i][0] == '<') {
            funct_redirect_left(minishell);
            return 1;
        }
    }
    return 0;
}

int heart_of_buildings(program_t *minishell, char *lineptr)
{
    int tmp = my_strlen(lineptr);
    int value = 0;

    if (lineptr[tmp - 1] == '\n')
        lineptr[tmp - 1] = '\0';
    lineptr = clean_str(lineptr);
    minishell->command = str_to_word_array(lineptr, ' ');
    if (command_edit(minishell, lineptr) == 1)
        return (1);
    if (value == 0)
        value = funct_redirect(minishell);
    for (size_t i = 0; i < ARRAY_SIZE(COMMAND_GESTION); i++) {
        if (value != 1) {
            value = is_valid_opt(minishell->command[0],
            &COMMAND_GESTION[i], i, minishell);
        }
    }
    return value;
}