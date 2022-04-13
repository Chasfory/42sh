/*
** EPITECH PROJECT, 2021
** destroy_var.c
** File description:
** a function that destroy the var linked list
*/

#include "variables.h"

#include <stdlib.h>

void destroy_var(var_t **head)
{
    var_t *temp = (*head);
    var_t *temp_next;

    if (temp)
        temp_next = (*head)->next;

    while (temp) {
        free(temp->name);
        free(temp->value);
        free(temp);
        temp = temp_next;
        if (temp)
            temp_next = temp->next;
    }
}