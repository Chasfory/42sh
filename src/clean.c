/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** minishell1
*/

#include "funct_minishell.h"

char *clean_str(char *command)
{
    int j = 0;
    int i;
    char *new_command = malloc(sizeof(char) * (my_strlen(command) + 1));

    for (i = 0; command[i] == ' ' || command[i] == '\t'; i++);
    for (; command[i] != '\0'; i++) {
        if (command[i] == ' ' || command[i] == '\t') {
            for(;command[i] == ' ' || command[i] == '\t'; i++);
            if (command[i] != '\0')
                new_command[j] = ' ';
            i--;
        } else {
            new_command[j] = command[i];
        }
        j++;
    }
    new_command[j] = '\0';
    return new_command;
}