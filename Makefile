NAME = libftprintf.a
INCLUDE = ft_printf.h

SRCS = ft_printf.c ft_printhex.c ft_printptr.c ft_printeasy.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o : %.c
	cc -g $(CFLAGS) -c -o $@ $< 

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re rebonus