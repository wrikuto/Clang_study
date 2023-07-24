NAME = push_swap.a
SRCS = \
		chk_args.c \
		list_utils.c \
		main.c \
		push.c \
		reverse_rotate.c \
		rotate.c \
		swap.c \
		insert_sort.c \
		sort_three_elements.c

OBJS	= $(SRCS:.c=.o)
CC		= cc
CFLAGS 	= -Wall -Wextra -Werror

##################################################################

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

$(OBJS): %.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

