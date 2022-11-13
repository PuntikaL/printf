NAME = libftprintf.a

SOURCES			= mainfunc.c ft2.c ft_putnbr.c

OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) -r $@ $?

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
