# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwillem- <jwillem-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/15 17:32:16 by wballaba          #+#    #+#              #
#    Updated: 2019/02/13 15:45:00 by jwillem-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

SRCS = srcs/checker.c srcs/operations.c srcs/stack_print.c
OBJ = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

LIBFT = ./libft/libftprintf.a
INC = -I ./includes
LIBLINK = -L ./libft -lftprintf
LIBINC = -I ./libft/includes

all: $(NAME) 

%.o:%.c
	@$(CC) $(CFLAGS) $(LIBINC) $(INC) -o $@ -c $<

libft: $(LIBFT)

$(LIBFT):
	@echo "Compiling libft..."
	@make -C ./libft
	@echo "OK!"

$(NAME): libft $(OBJ)
	@echo "Compiling checker..."
	@$(CC) $(LIBLINK) -o $(NAME) $(OBJ)
	@echo "OK!"

rmlib:
	@echo "Deleting libft object files and libft.a..."
	@make fclean -C ./libft
	@echo "OK!"

clean: rmlib
	@echo "Deleting fillit object files..."
	@rm -rf $(OBJ)
	@echo "OK!"

fclean: clean
	@echo "Deleting fillit..."
	@rm -rf $(NAME)
	@echo "OK!"

re: fclean all
