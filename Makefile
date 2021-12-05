NAME := libftprintf.a

CFILES := ft_printf.c ft_printf_utils.c

HEADER := ft_printf.h

CFLAGS := -Wall -Wextra -Werror

OBJS = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o : %.c $(HEADER)
	gcc $(CFLAGS) -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
