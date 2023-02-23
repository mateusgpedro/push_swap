# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 14:51:39 by maguimar          #+#    #+#              #
#    Updated: 2023/02/09 17:02:56 by maguimar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIBFT = ./libft/libft.a

SRC = src/push_swap.c src/rules.c src/utils.c
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(LIBFT):
		make bonus -C ./libft

$(NAME): $(OBJ) $(LIBFT)
		@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o push_swap

clean:
		@$(MAKE) clean -C ./libft
		@$(RM) $(OBJ)

fclean: clean
		@$(RM) push_swap
		@$(RM) (LIBFT)

re: fclean all
