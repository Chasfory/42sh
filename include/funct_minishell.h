/*
** EPITECH PROJECT, 2021
** command_gestion.h
** File description:
** minishell1
*/

#ifndef FUNCT_MINISHELL_H
#define FUNCT_MINISHELL_H

#include "struc_minishell.h"
#include "my.h"

//building_env.c
int funct_env_setenv(program_t *minishell);

//building_cd_lib.c
int my_strcmp_tree(char const *s1, char const *s2);
int my_strlen_env(char **clone_env);

//building_cd_error.c
int error_cd(program_t *minishell);
int error_funct_cd(program_t *minishell);
int funct_error_on_cd(program_t *minishell);

//building_cd.c
int command_cd_bis(program_t *minishell, int tmp);
int command_cd(program_t *minishell);
void setenv_cd(program_t *minishell, char *env_name, char *content);

//building_history.c
void push_back_history(program_t *minishell, history_t **history, char *linept);

//building_alias.c
alias_t *alias_exists(alias_t **head, char *alias);

//building_alias_display.c
void display_all_aliases(alias_t **head);
void display_one_alias(alias_t **head, char *alias);

//building_alias_change_command.c
void change_command_alias(program_t *minishell);

//concat.c
char *concat(char const *a, char const *b, char const *c);

//building_setenv.c
char *funct_setenv_bis(program_t *minishell);
int funct_setenv_tree(program_t *minishell, char *tmp_env);
int funct_alph_error_one(char const *command);
int funct_alph_error_two(char const *command);
int funct_error_setenv(program_t *minishell);

//building_unsetenv.c
int strcmp_env(char const *av1, char const *av2);
int funct_unsetenv_error(program_t *minishell);

//buidling_set.c
int my_strchr(char *str, char c);

//building.c
int heart_of_buildings(program_t *minishell, char *lineptr);
int is_valid_opt(char const *av, minishell_t const *arg,
int i, program_t *minishell);

//funct_error.c
int funct_error_env(char const *command);
int funct_error_cd(char const *command, char *const message);
int my_putstr_error(char const *str);
void funct_error_path_segment_fault(int pich);
void funct_error_path_maths(int pich);

//minishell.c
int minishell(char **env);
program_t init_srtuct(char **env);
char **recup_path(char **env, program_t *minishell);

//clean.c
char *clean_str(char *command);

//path.c
int access_path(char const *path);
void execve_path(program_t *minishell, char *const path_command);
int find_path_bis(program_t *minishell, int compt, char *path_command, int i);
int find_path(program_t *minishell);

//in variables directory
char *get_var_value(var_t *head, char *wanted);
void push_back_var(var_t **head, char *name, char *value);
void update_var(var_t *var, char *new_value);
void update_return(program_t *minishell, int new);
var_t *var_exist(var_t *head, char *wanted);
void replace_called_variables(program_t *minishell);
void destroy_var(var_t **head);

//command_edit.c
int command_edit(program_t *minishell, char *lineptr);

#endif /* !FUNCT_MINISHELL_H_ */