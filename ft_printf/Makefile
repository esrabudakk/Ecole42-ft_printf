NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
SRCS = ft_printf.c ft_printf_utils.c
OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

norm:
	@norminette *.[ch] */*.[ch] | grep ': OK!' -v || printf '\nHepsi doğru!\n\n'

.PHONY: all clean fclean re norm