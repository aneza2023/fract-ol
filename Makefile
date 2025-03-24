NAME = fractol
SOURCES = fractol.c\
			julia.c\
			ft_atof.c\
			mandelbrot.c\
			strcmp.c\
			hooks.c\
			math.c\
			ending_prg.c
MLX42LIB = MLX42/build/libmlx42.a

OBJS = $(SOURCES:.c=.o)
CC = cc
CFLAGS =  -Wall -Werror -Wextra -g
MLXFLAGS = -Iinclude -ldl -lglfw -pthread -lm

all:$(NAME)

$(NAME):$(OBJS)
	cc -o $(NAME) $(OBJS) $(MLX42LIB) $(MLXFLAGS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

