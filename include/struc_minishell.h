/*
** EPITECH PROJECT, 2021
** command_gestion.h
** File description:
** minishell1
*/

#ifndef STRUCT_MINISHELL_H
#define STRUCT_MINISHELL_H

#include "variables.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wait.h>
#include <time.h>

#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

typedef struct alias_s
{
    char *alias;
    char *replace;
    struct alias_s *prev;
    struct alias_s *next;
} alias_t;

typedef struct history_s
{
    int index;
    time_t time;
    char *prompt;
    struct history_s *prev;
    struct history_s *next;
} history_t;

typedef struct program_s {
    char **copy_env;
    char **nbr_command;
    char **separator;
    char **command;
    char **path;
    char *path_first;
    char *path_command;
    int last_value;
    int return_value;
    var_t *var;
    history_t *history;
    alias_t *alias;
} program_t;

typedef struct pipe_s {
    pid_t child;
    char **command;
    int num;
    int error;
    int pfd_tmp[2];
    int pfd[2];
} pipe_t;

typedef struct minishell_s {
    const char *comd;
    int (*handler)(program_t *minishell);
} minishell_t;

char **str_to_word_array_string(char *str, char *sep);

typedef struct str_to_word_s {
    int compt_line;
    int l;
    int i;
    int stock;
    int k;
    char **tmp;
} str_to_word_t;

int is_valid_opt(char const *av, minishell_t const *arg,
int i, program_t *minishell);
void funct_child(program_t *minishell, int fd, int i);
void funct_error_redirect(int pich);

int funct_env(program_t *minishell);
int funct_cd(program_t *minishell);
int funct_exit(program_t *minishell);
int funct_setenv(program_t *minishell);
int funct_unsetenv(program_t *minishell);
int funct_pwd(program_t *minishell);
int funct_echo(program_t *minishell);
int funct_history(program_t *minishell);
int funct_set(program_t *minishell);

void funct_child_left(program_t *minishell, int fd, int tmp);
void funct_redirect_right(program_t *minishell);
int funct_double_redirect_right(program_t *minishell, int i);
int funct_double_redirect_left(program_t *minishell, int i);
int funct_redirect_left(program_t *minishell);
int funct_history(program_t *minishell);
int funct_alias(program_t *minishell);

int funct_pipes(program_t *minishell, char *lineptr);

pipe_t init_struct_pipe(void);
void path(program_t *minishell);
int funct_pipes(program_t *minishell, char *lineptr);

program_t init_srtuct(char **env);

char **str_to_word_array_string(char *str, char *sep);

int funct_and(program_t *minishell);
int funct_or(program_t *minishell);
void funct_or_bis(char **or_separator, program_t *minishell);
void funct_and_bis(char **and_separator, program_t *minishell);
int funct_pipes_redirect(program_t *minishell, char *lineptr);
void minishell_prog_bis(program_t *minishell, int i, int compt);

static const minishell_t COMMAND_GESTION[] = {
    {"env", funct_env},
    {"cd", funct_cd},
    {"setenv", funct_setenv},
    {"unsetenv", funct_unsetenv},
    {"exit", funct_exit},
    {"pwd", funct_pwd},
    {"echo", funct_echo},
    {"history", funct_history},
    {"set", funct_set},
    {"alias", funct_alias},
};

#endif /* !STRUCT_MINISHELL_H_ */