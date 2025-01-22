NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

SRC = $(wildcard srcs/*.c) $(wildcard gnl/*.c)
OBJ = $(SRC:.c=.o)

INCLUDE = -Iinclude

ifeq ($(shell uname), Linux)
    MINILIBX = minilibx-linux
    MINILIBX_LIBRARY = -L$(MINILIBX) -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
else
    MINILIBX = minilibx
    MINILIBX_LIBRARY = -L$(MINILIBX) -lmlx -framework OpenGL -framework AppKit
endif

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(MINILIBX)
	make -C ft_printf
	cp ft_printf/libftprintf.a .
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) $(MINILIBX_LIBRARY) libftprintf.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(MINILIBX)
	make clean -C ft_printf
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f libftprintf.a

re: fclean all

.PHONY: all clean fclean re
