# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xdarksyderx <xdarksyderx@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 13:10:04 by vnaslund          #+#    #+#              #
#    Updated: 2023/12/11 15:12:32 by xdarksyderx      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SOURCES = src/main.c src/parser/get_command_args.c src/parser/parse_commands.c \
		  src/parser/split_commands.c src/debug/print_cmd_list.c src/helpers/mem.c \
		  src/execution/exec_cmd.c src/execution/start_minishell.c \
		  src/execution/builtin_handler.c src/builtins/cd.c \
		  src/builtins/exit.c src/builtins/pwd.c  src/builtins/echo.c

OBJ_DIR = obj/
OBJECTS = $(SOURCES:%.c=$(OBJ_DIR)%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I/libft

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
