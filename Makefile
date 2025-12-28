NAME = push_swap
BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

INCLUDES = includes/push_swap.h \
			includes/checker.h

COMMON_SRC = \
	utils/helpers.c \
	utils/stack_utils.c \
	utils/is_sorted.c \
	operations/swap.c \
	operations/push.c \
	operations/rotate.c \
	operations/reverse_rotate.c \
	libft/ft_split.c \
	libft/ft_strlen.c \
	libft/ft_substr.c \
	parse.c

COMMON_OBJ = $(COMMON_SRC:.c=.o)

SRC = push_swap.c \
      sorting/sort_chunk.c \
      sorting/sort_utils.c \
      sorting/sort_small.c

OBJ = $(SRC:.c=.o) $(COMMON_OBJ)

BONUS_SRC = bonus/checker.c \
            gnl/get_next_line.c \
            gnl/get_next_line_utils.c

BONUS_OBJ = $(BONUS_SRC:.c=.o)  $(COMMON_OBJ)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(BONUS): $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BONUS)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ) $(COMMON_OBJ)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

bonus: $(BONUS)

.PHONY: all clean fclean re bonus
