# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/03 16:13:08 by rlandolt          #+#    #+#              #
#    Updated: 2023/08/24 13:04:55 by rlandolt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

SRC_PATH = ./srcs
ACTIONS = $(SRC_PATH)/actions
INPUT = $(SRC_PATH)/input
SORT = $(SRC_PATH)/sort
STRUCT = $(SRC_PATH)/struct

SRC = push_swap.c \
	$(INPUT)/process.c \
	$(INPUT)/split.c \
	$(INPUT)/strings.c \
	$(INPUT)/error.c \
	$(STRUCT)/struct.c \
	$(STRUCT)/sutils.c \
	$(STRUCT)/smanager.c \
	$(STRUCT)/index.c \
	$(ACTIONS)/push.c \
	$(ACTIONS)/swap.c \
	$(ACTIONS)/rotate.c \
	$(SORT)/small_sort.c \
#	$(SORT)/big_sort.c \

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	ar -rcs $@ $(OBJ)
	cc -g -o push_swap push_swap.a -fsanitize=address

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, bonus, clean, fclean, re
