/*
** EPITECH PROJECT, 2021
** building_alias.c
** File description:
** building alias
*/

#include <stdbool.h>

#include "funct_minishell.h"
#include "my.h"

alias_t *alias_exists(alias_t **head, char *alias)
{
    alias_t *current = *head;

    if (*head == NULL)
        return NULL;
    do {
        if (strcmp(current->alias, alias) == 0) {
            return current;
        }
        current = current->next;
    } while (current != *head);
    return NULL;
}

static char *get_replacement(program_t *minishell)
{
    char *replacement = strdup(minishell->command[2]);

    for (int i = 3; minishell->command[i]; ++i) {
        replacement = realloc(replacement,
        strlen(replacement) + 2 + strlen(minishell->command[i]));
        strcat(replacement, " ");
        strcat(replacement, minishell->command[i]);
    }
    return replacement;
}

static void create_node_null_alias(program_t *mini, alias_t **h, alias_t *n)
{
    *h = n;
    n->next = *h;
    n->prev = *h;
    n->alias = strdup(mini->command[1]);
    n->replace = get_replacement(mini);
}

void push_back_alias(program_t *minishell, alias_t **head)
{
    alias_t *new_node;

    new_node = malloc(sizeof(alias_t));
    if (*head == NULL) {
        create_node_null_alias(minishell, head, new_node);
    } else {
        new_node->next = *head;
        new_node->prev = (*head)->prev;
        (*head)->prev->next = new_node;
        (*head)->prev = new_node;
        new_node->alias = strdup(minishell->command[1]);
        new_node->replace = get_replacement(minishell);
    }
}

int funct_alias(program_t *minishell)
{
    int nb_args = 0;
    alias_t *alias_node;

    for (; minishell->command[nb_args]; ++nb_args);
    if (minishell->alias) {
        if (nb_args == 1)
            display_all_aliases(&minishell->alias);
        if (nb_args == 2)
            display_one_alias(&minishell->alias, minishell->command[1]);
    }
    if (nb_args >= 3) {
        alias_node = alias_exists(&minishell->alias, minishell->command[1]);
        if (alias_node == NULL)
            push_back_alias(minishell, &minishell->alias);
        else {
            free(alias_node->replace);
            alias_node->replace = get_replacement(minishell);
        }
    }
    return 0;
}