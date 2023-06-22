NAME = push_swap.a

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIBFT = ./libft/libft.a

SRCS = 	src/algo.c \
		src/frees.c \
		src/init.c \
		src/push_swap.c \
		src/rules.c \
		src/utils.c \
		src/utils2.c \
		src/utils3.c \
		src/algo2.c \
		src/algo3.c \
		src/algo5.c \
		src/algo_100.c \
		src/algo_diff.c \
		src/algo_diff2.c \

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o push_swap

clean:
	@$(MAKE) clean -C ./libft
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(RM) $(NAME) push_swap

re: fclean all
