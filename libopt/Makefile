#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: greyrol <greyrol@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 14:02:18 by greyrol           #+#    #+#              #
#    Updated: 2013/12/29 13:27:06 by greyrol          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libopt
EXT = a
TARGET = $(NAME).$(EXT)

LIBFT_NAME = libft
LIBFT_EXT = a
LIBFT_TARGET = $(LIBFT_NAME).$(LIBFT_EXT)
LIBFT_DIR = ../$(LIBFT_NAME)
LIBFT_INC = $(LIBFT_DIR)/inc
LIBFT_LIB = $(LIBFT_DIR)/$(LIBFT_TARGET)

INC = ./ -I./inc -I$(LIBFT_INC)
SRC_DIR = ./src
OBJ_BASE = ./obj
OBJ_DIR = $(OBJ_BASE)

UNITS = $(shell ls $(SRC_DIR) | grep .c)
UNITS_O = $(UNITS:.c=.o)

SRCS = $(patsubst %,$(SRC_DIR)/%,$(UNITS))
OBJS = $(patsubst %,$(OBJ_DIR)/%,$(UNITS_O))

FLAGS = -Wall -Wextra -Werror -pedantic -std=c89
CFLAGS = $(FLAGS) -ggdb

AR = ar rcs
CC = clang $(CFLAGS) -I$(INC)
RM = /bin/rm -f

all: $(TARGET)


$(TARGET): $(OBJS) $(LIBFT_LIB)
	@$(AR) $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) -c -o $@ $<

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

clean:
	@$(RM) $(OBJS)
	@make clean -C $(LIBFT_DIR)

fclean : clean
	@$(RM) $(TARGET)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: clean fclean all re
