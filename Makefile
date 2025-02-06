NAME = fractol
SOURCES = fractol.c\

OBJS = $(SOURCES:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra

all:$(NAME)

$(NAME):$(OBJS)
	cc -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

