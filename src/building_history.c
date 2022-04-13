/*
** EPITECH PROJECT, 2021
** building_history.c
** File description:
** building history function
*/

#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

#include "funct_minishell.h"
#include "my.h"

static void display_n_history(history_t **head, int n)
{
    history_t *current = *head;
    char s[10];
    int i = 0;

    do {
        current = current->prev;
        ++i;
    } while (current->index > current->prev->index && i < n);
    do {
        strftime(s, sizeof(s), "%H:%M", localtime(&current->time));
        dprintf(1, "    %d  %s  %s", current->index, s, current->prompt);
        current = current->next;
    } while (current != *head);
}

static void display_history(history_t **head)
{
    history_t *current = *head;
    char s[10];

    do {
        strftime(s, sizeof(s), "%H:%M", localtime(&current->time));
        dprintf(1, "    %d  %s  %s", current->index, s, current->prompt);
        current = current->next;
    } while (current != *head);
}

static void create_node_null_history(history_t **h, history_t *n, char *prompt)
{
    *h = n;
    n->next = *h;
    n->prev = *h;
    n->index = 1;
    n->time = time(0);
    n->prompt = strdup(prompt);
}

void push_back_history(program_t *minishell, history_t **head, char *prompt)
{
    history_t *new_node;

    new_node = malloc(sizeof(history_t));
    if (*head == NULL) {
        create_node_null_history(head, new_node, prompt);
    } else {
        new_node->next = *head;
        new_node->prev = (*head)->prev;
        (*head)->prev->next = new_node;
        (*head)->prev = new_node;
        new_node->index = (new_node->prev->index) + 1;
        new_node->time = time(0);
        new_node->prompt = strdup(prompt);
    }
}

int funct_history(program_t *minishell)
{
    int nb_args = 0;

    for (; minishell->command[nb_args]; ++nb_args);
    if (nb_args > 1) {
        for (int i = 0; minishell->command[1][i] != '\0'; ++i) {
            if (isdigit(minishell->command[1][i]) == false) {
                dprintf(1, "history: Badly formed number\n");
                return 84;
            }
        }
        display_n_history(&minishell->history, my_getnbr(minishell->command[1]));
    } else if (minishell->history != NULL)
        display_history(&minishell->history);
    return 0;
}