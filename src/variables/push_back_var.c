/*
** EPITECH PROJECT, 2021
** push_back_var.c
** File description:
** a function that push back a new variable in the linked list
*/

#include "variables.h"
#include "my.h"

#include <stdlib.h>

void push_back_var(var_t **head, char *name, char *value)
{
    var_t *temp = (*head);
    var_t *new = malloc(sizeof(var_t));
    (*new) = (var_t) {my_strdup(name), my_strdup(value), NULL};

    if (temp == NULL) {
        (*head) = new;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new;
}