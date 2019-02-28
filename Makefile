# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwillem- <jwillem-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/07 18:58:02 by jwillem-          #+#    #+#              #
#    Updated: 2019/02/28 01:08:06 by jwillem-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
PUSH_SWAP = push_swap

CC = gcc
FLAGS = -Wall -Wextra -Werror -g

SRCDIR = srcs/
OBJDIR = obj/

CH_FILES = checker	
CH_SRC = $(addprefix $(SRCDIR), $(addsuffix .c,$(CH_FILES)))
CH_OBJ = $(addprefix $(OBJDIR),$(addsuffix .o,$(CH_FILES)))

PS_FILES = push_swap	sorting		sort_three	pivots
PS_SRC = $(addprefix $(SRCDIR), $(addsuffix .c,$(PS_FILES)))
PS_OBJ = $(addprefix $(OBJDIR),$(addsuffix .o,$(PS_FILES)))

COMMON = validates	validates_split		operations	stack_print		
COMMON_SRC = $(addprefix $(SRCDIR), $(addsuffix .c,$(COMMON)))
COMMON_OBJ = $(addprefix $(OBJDIR),$(addsuffix .o,$(COMMON)))

LIBFT = ./libft/libftprintf.a
INCDIR = -I ./includes
LIBLINK = -L ./libft -lftprintf
LIBINC = -I ./libft/includes

all: $(LIBFT) $(CHECKER) $(PUSH_SWAP)

$(LIBFT):
	@make -C ./libft

$(OBJDIR):
	@echo "Creating Push_Swap object files directory..."
	@mkdir $(OBJDIR)
	@echo "Directory created!"

$(OBJDIR)%.o: $(SRCDIR)%.c | $(OBJDIR)
	@$(CC) $(FLAGS) $(INCDIR) $(LIBINC) -c $< -o $@

$(CHECKER): $(CH_OBJ) $(COMMON_OBJ)
	@echo "Compiling checker..."
	@$(CC) $(LIBLINK) -o $(CHECKER) $(CH_OBJ) $(COMMON_OBJ)
	@echo "Checker is compiled!"

$(PUSH_SWAP): $(PS_OBJ) $(COMMON_OBJ)
	@echo "Compiling push_swap..."
	@$(CC) $(LIBLINK) -o $(PUSH_SWAP) $(PS_OBJ) $(COMMON_OBJ)
	@echo "Push_swap is compiled!"

libclean:
	@make clean -C ./libft

clean: libclean
	@echo "Deleting Push_swap object files..."
	@rm -rf $(OBJDIR)
	@echo "Push_swap object files are deleted!"

fclean: clean
	@echo "Deleting push_swap and checker..."
	@rm -rf $(CHECKER) $(PUSH_SWAP)
	@echo "Executable files are deleted!"
	@make fclean -C ./libft
	@echo "Everything is cleaned!"

re: fclean
	@$(MAKE) all
