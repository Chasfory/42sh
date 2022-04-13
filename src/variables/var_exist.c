/*
** EPITECH PROJECT, 2021
** var_exist.c
** File description:
** a function that check if a var exist, if yes return a pointer to it
*/

#include "variables.h"
#include "my.h"

#include <stddef.h>

var_t *var_exist(var_t *head, char *wanted)
{
    for (var_t *temp = head; temp; temp = temp->next) {
        if (my_strcmp(temp->name, wanted) == 0)
            return (temp);
    }
    return (NULL);
}