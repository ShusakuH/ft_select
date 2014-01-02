#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/11 05:27:36 by greyrol           #+#    #+#              #
#    Updated: 2014/01/02 15:14:46 by greyrol          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_select

LIB_EXT = a

LIBOPT_NAME = libopt
LIBOPT_TARGET = $(LIBOPT_NAME).$(LIB_EXT)
LIBOPT_DIR = ./$(LIBOPT_NAME)
LIBOPT_LIB = $(LIBOPT_DIR)/$(LIBOPT_TARGET)

LIBFT_NAME = libft
LIBFT_TARGET = $(LIBFT_NAME).$(LIB_EXT)
LIBFT_DIR = ./$(LIBFT_NAME)
LIBFT_LIB = $(LIBFT_DIR)/$(LIBFT_TARGET)

INC_DIR = inc -I $(LIBOPT_DIR)/inc -I $(LIBFT_DIR)/inc
SRC_DIR = ./src
OBJ_DIR = ./obj

UNITS = ft_select.c ft_term.c ft_ask_terminal.c

UNITS_O = $(UNITS:.c=.o)
SRCS = $(patsubst %,$(SRC_DIR)/%,$(UNITS))
OBJS = $(patsubst %,$(OBJ_DIR)/%,$(UNITS_O))
FLAGS = -Wall -Wextra -Werror -std=c89 -ansi -pedantic -Qunused-arguments
CFLAGS = $(FLAGS) -ggdb
LDFLAGS = $(LIBOPT_LIB) $(LIBFT_LIB) -ltermcap
CC = clang $(CFLAGS)
LD = $(CC) -o $(NAME)
RM = /bin/rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB) $(LIBOPT_LIB) 
	@$(LD) $^  $(LDFLAGS)
	@printf 'Building binary : %s\n' "$(NAME)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) -c -I$(INC_DIR) -o $@ $<

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)
	@printf 'Building library : libft.a\n'

$(LIBOPT_LIB):
	@make -C $(LIBOPT_DIR)
	@printf 'Building library : libopt.a\n'

clean:
	@$(RM) $(OBJS)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(LIBOPT_DIR)

fclean : clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(LIBOPT_DIR)

re: fclean all

.PHONY: clean fclean all re
