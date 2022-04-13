/*
** EPITECH PROJECT, 2021
** building_alias_list.c
** File description:
** aliases
*/

#include "funct_minishell.h"
#include "my.h"

void display_all_aliases(alias_t **head){
    alias_t *current = *head;

    do {
        dprintf(1, "%s\t%s\t\n", current->alias, current->replace);
        current = current->next;
    } while (current != *head);
}

void display_one_alias(alias_t **head, char *alias){
    alias_t *is_an_alias = alias_exists(head, alias);

    if (is_an_alias != NULL)
        dprintf(1, "%s\n", is_an_alias->replace);
}