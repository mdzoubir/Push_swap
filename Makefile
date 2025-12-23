NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = push_swap.c \
      sorting/sort_chunk.c \
      sorting/sort_utils.c \
      sorting/sort_small.c \
      parse.c \
      utils/errors.c \
      utils/stack_utils.c \
      utils/is_sorted.c \
      operations/swap.c \
      operations/push.c \
      operations/rotate.c \
      operations/reverse_rotate.c \
      libft/ft_split.c \
      libft/ft_strlen.c \
      libft/ft_substr.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
