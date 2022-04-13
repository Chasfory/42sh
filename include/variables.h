/*
** EPITECH PROJECT, 2021
** variable.h
** File description:
** a header for the variables linked list
*/

#ifndef VARIABLES_H_
#define VARIABLES_H_

typedef struct var_s
{
    char *name;
    char *value;
    struct var_s *next;
} var_t;

#endif /* !VARIABLES_H_ */