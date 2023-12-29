# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xdarksyderx <xdarksyderx@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 13:10:04 by vnaslund          #+#    #+#              #
#    Updated: 2023/12/27 14:39:37 by xdarksyderx      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SOURCES = src/main.c src/parser/parser.c src/parser/parser_helpers.c \
          src/expander/expander.c src/expander/expander_utils.c \
          src/debug/print_cmd_list.c src/helpers/mem.c src/helpers/signals.c \
          src/execution/execute.c src/execution/start_minishell.c src/execution/pipes.c \
          src/execution/exec_utils.c src/execution/builtin_handler.c src/builtins/env_utils.c \
          src/builtins/cd.c src/builtins/env.c src/builtins/exit.c src/builtins/pwd.c src/builtins/echo.c \

OBJ_DIR = obj/
OBJECTS = $(SOURCES:%.c=$(OBJ_DIR)%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I/libft -g

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) -lreadline $(LIBFT)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
