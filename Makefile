NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = push_swap.c \
      parse.c \
      errors.c \
      stack_init.c \
      sort_small.c \
      sort_radix.c \
      utils.c \
      operations/swap.c \
      operations/push.c \
      operations/rotate.c \
      operations/reverse_rotate.c

OBJ = $(SRC:.c=.o)

# =========================
# Rules
# =========================

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
