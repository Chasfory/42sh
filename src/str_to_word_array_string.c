/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-2-42sh-laetitia.bousch
** File description:
** str_to_word_array_string
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "funct_minishell.h"

static int nb_ligne(char *str, char *sep)
{
    int i = my_strlen(sep);
    int compt = 0;
    int j = 0;

    for (; my_strcmp(&str[j], sep) == 0; j += i);
    for (; str[j] != '\0';) {
        if (my_strcmp(&str[j], sep) == 0) {
            compt++;
            j += i;
        } else {
            j++;
        }
    }
    compt++;
    return compt;
}

static int my_strlen_to_word_array(char *str, char *sep)
{
    int i = 0;

    for (; my_strcmp(&str[i], sep) != 0 && str[i] != '\0'; i++);
    return i;
}

static str_to_word_t init_struct(char *str, char *sep)
{
    str_to_word_t array;

    array.compt_line = nb_ligne(str, sep);
    array.l = 0;
    array.i = 0;
    array.stock = 0;
    array.k = my_strlen(sep);
    array.tmp = malloc(sizeof(char *) * (array.compt_line + 1));
    return array;
}

char **str_to_word_array_string(char *str, char *sep)
{
    str_to_word_t array = init_struct(str, sep);

    for (int j = 0; j < array.compt_line; j++, array.i++) {
        array.stock = my_strlen_to_word_array(&str[array.i], sep);
        array.tmp[j] = malloc(sizeof(char) * (array.stock + 1));
        for (array.l = 0; array.l < array.stock;) {
            if (my_strcmp(&str[array.i], sep) != 0) {
                array.tmp[j][array.l] = str[array.i];
                array.l++;
                array.i++;
            } else {
                array.l += array.k;
                array.i += array.k;
            }
        }
        array.tmp[j][array.stock] = '\0';
        array.i++;
    }
    array.tmp[array.compt_line] = NULL;
    return array.tmp;
}