/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** minishell1
*/

#include "funct_minishell.h"
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int access_path(char const *path)
{
    if (access(path, F_OK) != 0) {
        return 1;
    }
    if (access(path, X_OK) != 0) {
        my_putstr_error("permission denied\n");
        return 2;
    }
    return 0;
}

void execve_path(program_t *minishell, char *const path_command)
{
    int pich = fork();

    for (int tmp = 0; minishell->command[tmp]; tmp++) {
        if (pich != 0) {
            waitpid(pich, &tmp, 0);
            update_return(minishell, WEXITSTATUS(pich));
            if (WIFSIGNALED(tmp)) {
                if (WTERMSIG(tmp) == SIGSEGV) {
                    funct_error_path_segment_fault(tmp);
                }
                else if (WTERMSIG(tmp) == SIGFPE) {
                    funct_error_path_maths(tmp);
                }
            }
        } else {
            execve(path_command, minishell->command, minishell->copy_env);
            exit(EXIT_FAILURE);
        }
    }
}

int find_path_bis(program_t *minishell, int compt, char *path_command, int i)
{
    if (access_path(minishell->command[0]) == 0) {
        execve_path(minishell, minishell->command[0]);
        compt = 1;
    } else {
        path_command = concat(minishell->path[i], "/",
        minishell->command[0]);
    }
    if (access_path(path_command) == 0) {
        execve_path(minishell, path_command);
        compt = 1;
    }
    return compt;
}

int find_path(program_t *minishell)
{
    int compt = 0;
    char *path_command = NULL;

    for (int i = 0; minishell->path[i] && compt == 0; i++) {
        path_command = malloc(sizeof(char) * (my_strlen(minishell->path[i]) +
        my_strlen(minishell->command[0]) + 2));
        compt = find_path_bis(minishell, compt, path_command, i);
        free(path_command);
    }
    if (compt != 1) {
        funct_error_cd(minishell->command[0], ": Command not found.\n");
    }
    return compt;
}