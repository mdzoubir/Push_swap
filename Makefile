NAME        = push_swap
BONUS_NAME  = checker

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

HEADER_M    = includes/push_swap.h
HEADER_B    = includes/checker_bonus.h

COMMON_SRC  = utils/helpers.c \
              utils/stack_utils.c \
              operations/swap.c \
              operations/push.c \
              operations/rotate.c \
              operations/reverse_rotate.c \
              libft/ft_split.c \
              libft/ft_strlen.c \
              libft/ft_substr.c \
              parse.c

SRC         = push_swap.c \
              sorting/sort_chunk.c \
              sorting/sort_utils.c \
              sorting/sort_small.c

BONUS_SRC   = bonus/checker_bonus.c \
              bonus/helper_bonus.c \
              bonus/gnl/get_next_line_bonus.c \
              bonus/gnl/get_next_line_utils_bonus.c

OBJ_COMMON  = $(COMMON_SRC:.c=.o)

OBJ_M       = $(SRC:.c=.o)

OBJ_B       = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_M) $(OBJ_COMMON)
	$(CC) $(CFLAGS) $(OBJ_M) $(OBJ_COMMON) -o $(NAME)

$(BONUS_NAME): $(OBJ_B) $(OBJ_COMMON)
	$(CC) $(CFLAGS) $(OBJ_B) $(OBJ_COMMON) -o $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_COMMON) $(OBJ_M): $(HEADER_M)

$(OBJ_B): $(HEADER_B) $(HEADER_M)

clean:
	rm -f $(OBJ_M) $(OBJ_B) $(OBJ_COMMON)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

bonus: $(BONUS_NAME)

.PHONY: all clean fclean re bonus