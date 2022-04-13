##
## EPITECH PROJECT, 2021
##
## File description:
##

SRC			=	src/main.c\
				src/funct_error.c\
				src/minishell.c\
				src/building_and_or.c\
				src/minishell_bis.c\
				src/str_to_word_array_string.c\
				src/clean.c\
				src/path.c\
				src/concat.c\
				src/building.c\
				src/building_cd.c\
				src/building_cd_error.c\
				src/building_cd_lib.c\
				src/building_env.c\
				src/building_exit.c\
				src/building_setenv.c\
				src/building_setenv_bis.c\
				src/building_unsetenv.c\
				src/building_pwd.c\
				src/building_echo.c\
				src/building_history.c\
				src/building_set.c\
				src/building_redirect_right.c\
				src/building_double_redirect.c\
				src/building_redirect_left.c\
				src/building_double_redirect_left.c\
				src/building_pipes.c\
				src/command_edit.c\
				src/building_alias.c\
				src/building_alias_display.c\
				src/building_alias_change_command.c\
				src/utils.c\
				src/init_struct.c\
				src/variables/push_back_var.c\
				src/variables/get_var_value.c\
				src/variables/update_var.c\
				src/variables/update_return.c\
				src/variables/var_exist.c\
				src/variables/destroy_var.c\
				src/variables/replace_called_variables.c\

OBJ			=	$(SRC:.c=.o)

NAME		=	42sh

CFLAGS		=	-Wall -Wextra

CPPFLAGS	=	-iquote ./include

LDFLAGS		=	-L ./lib -lmy

CC			=	gcc

all: $(NAME)
$(NAME): $(OBJ)
	$(MAKE) -C ./lib/my
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

debug: CFLAGS += -g3
debug: re

clean:
	$(RM) $(OBJ)
	$(MAKE) -C ./lib/my clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C ./lib/my fclean

re: fclean all

./PHONY: all clean fclean