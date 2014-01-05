#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/11 05:27:36 by greyrol           #+#    #+#              #
#    Updated: 2014/01/05 15:08:01 by greyrol          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_select

LIB_EXT = a

LIBFT_NAME = libft
LIBFT_TARGET = $(LIBFT_NAME).$(LIB_EXT)
LIBFT_DIR = ./$(LIBFT_NAME)
LIBFT_LIB = $(LIBFT_DIR)/$(LIBFT_TARGET)

INC_DIR = inc -I $(LIBFT_DIR)/inc
SRC_DIR = ./src
OBJ_DIR = ./obj

UNITS = ft_select.c ft_terminal.c ft_list.c ft_terminal_error.c ft_signal.c\
		ft_write.c ft_terminal_run.c ft_move.c ft_capabilities.c\
		ft_base_keys.c ft_keys.c

UNITS_O = $(UNITS:.c=.o)
SRCS = $(patsubst %,$(SRC_DIR)/%,$(UNITS))
OBJS = $(patsubst %,$(OBJ_DIR)/%,$(UNITS_O))
FLAGS = -Wall -Wextra -Werror -std=c89 -ansi -pedantic -Qunused-arguments
CFLAGS = $(FLAGS) -ggdb
LDFLAGS = $(LIBFT_LIB) -ltermcap
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

clean:
	@$(RM) $(OBJS)
	@make clean -C $(LIBFT_DIR)

fclean : clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: clean fclean all re
