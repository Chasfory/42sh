/*
** EPITECH PROJECT, 2021
** update_var.c
** File description:
** a function that update a variable's value
*/

#include "variables.h"
#include "my.h"

#include <stdlib.h>

void update_var(var_t *var, char *new_value)
{
    free(var->value);
    var->value = my_strdup(new_value);
}