/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-2-minishell2-laetitia.bousch
** File description:
** building_pipes
*/

#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>

#include "funct_minishell.h"

static void funct_child_pipes_bis(program_t *minishell, int *pfd,
                                char *command)
{
    char **tmp_command = NULL;

    command = clean_str(command);
    tmp_command = str_to_word_array(command, ' ');
    minishell->command = tmp_command;
    path(minishell);
    dup2(pfd[0], 0);
    close(pfd[1]);
    close(pfd[0]);
    execve(minishell->path_command, tmp_command, minishell->copy_env);
    exit(1);
}

static void funct_child_pipes(program_t *minishell, int *pfd, char *command)
{
    char **tmp_command = NULL;

    command = clean_str(command);
    tmp_command = str_to_word_array(command, ' ');
    minishell->command = tmp_command;
    path(minishell);
    dup2(pfd[1], 1);
    close(pfd[0]);
    close(pfd[1]);
    execve(minishell->path_command, tmp_command, minishell->copy_env);
    exit(1);
}

static void funct_pipe_tree(pipe_t *struct_pipe, program_t *minishell)
{
    minishell->path_command = NULL;
        waitpid(struct_pipe->child, NULL, 0);
        struct_pipe->child = fork();
    if (struct_pipe->child == 0) {
        funct_child_pipes_bis(minishell, struct_pipe->pfd,
        struct_pipe->command[struct_pipe->num + 1]);
    } else {
        close(struct_pipe->pfd[1]);
        close(struct_pipe->pfd[0]);
        waitpid(struct_pipe->child, NULL, 0);
    }
}

static void funct_pipes_bis(pipe_t *struct_pipe, program_t *minishell)
{
    struct_pipe->child = fork();
    if (struct_pipe->child == -1) {
        wait(&struct_pipe->error);
        funct_error_redirect(struct_pipe->error);
    } else {
        if (struct_pipe->child == 0) {
            funct_child_pipes(minishell, struct_pipe->pfd,
                        struct_pipe->command[struct_pipe->num]);
        } else {
            funct_pipe_tree(struct_pipe, minishell);
        }
    }
}

int funct_pipes(program_t *minishell, char *lineptr)
{
    pipe_t struct_pipe = init_struct_pipe();

    struct_pipe.command = str_to_word_array(lineptr, '|');
    if (pipe(struct_pipe.pfd) == -1) {
        return funct_error_cd("Invalid null command.", "\n");
    } else {
        funct_pipes_bis(&struct_pipe, minishell);
    }
    return 0;
}