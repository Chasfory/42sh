/*
** EPITECH PROJECT, 2021
** get_var_value.c
** File description:
** a function that get a var value
*/

#include "variables.h"
#include "my.h"

#include <stddef.h>

char *get_var_value(var_t *head, char *wanted)
{
    for (var_t *temp = head; temp; temp = temp->next) {
        if (my_strcmp(temp->name, wanted) == 0)
            return (temp->value);
    }
    return (NULL);
}