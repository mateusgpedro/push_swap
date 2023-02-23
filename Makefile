# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 14:51:39 by maguimar          #+#    #+#              #
#    Updated: 2023/02/23 14:01:35 by maguimar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC = src/push_swap.c src/rules.c src/utils.c src/algo.c src/frees.c src/init.c src/ft_atol.c
OBJ = $(SRC:.c=.o)

all: $(OBJ)
	make -C ./libft
	cp ./libft/libft.a .
	$(CC) $(CFLAGS) $(OBJ) libft.a -o push_swap
