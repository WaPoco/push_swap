NAME=push_swap
CC=cc
CFLAGS=-Wall -Wextra -Werror
LFLAGS=-L./ft_printf -lftprintf -L./Libft -lft
HEADER=./Include/push_swap.h
SRCS=./src/check_args.c ./src/cost.c ./src/find_cheapest.c ./src/free_stacks.c ./src/move_stacks.c ./src/push_swap.c ./src/sort.c ./src/stack_operations1.c ./src/stack_operations2.c ./src/stack_operations3.c
OBJS=$(SRCS:.c=.o)

all: Libft ft_printf $(NAME)

Libft:
	make -C ./Libft

ft_printf:
	make -C ./ft_printf

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LFLAGS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	make -C ./Libft fclean
	make -C ./ft_printf fclean

re: fclean all

.PHONY: clean fclean all re Libft ft_printf