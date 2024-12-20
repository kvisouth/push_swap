SRC		=	src/main.c \
			src/parse.c \
			src/parse_args.c \
			src/parse_join.c \
			src/parse_numbers.c \
			src/init.c \
			src/sort_instructions_reverse.c \
			src/sort_instructions_swap.c \
			src/sort_instructions_push.c \
			src/sort.c \
			src/sort_instructions_rotate.c \
			src/sort_2.c \
			src/sort_3.c \
			src/sort_4.c \
			src/sort_5.c \
			src/sort_500.c \
			src/sort_500_calc.c \
			src/sort_500_utils.c \

NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf
AR		= ar rcs

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

OBJ		= $(SRC:.c=.o)

%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(LIBFT) $(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBFT_DIR) -lft

$(LIBFT):
			$(MAKE) -C $(LIBFT_DIR)

all:		$(NAME)

clean:
			$(RM) $(OBJ)
			$(MAKE) -C $(LIBFT_DIR) clean

fclean:		clean
			$(RM) $(NAME)
			$(MAKE) -C $(LIBFT_DIR) fclean

re:			fclean all

.PHONY:		all clean fclean re
