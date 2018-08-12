NAME = fdf
SRC = src/main.c \
	  get_next_line/get_next_line.c \
	  src/drawline.c \
	  src/render.c

LIB	= get_next_line/libft/libft.a

OBJ = $(SRC:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror 

.SILENT:
all: $(NAME)

$(NAME): $(OBJ)
	@make -C get_next_line/libft/ re
	@$(CC) -g -o $(NAME) $(OBJ) $(FLAGS) -I. $(LIB) -I minilibx_macos -lmlx -framework OpenGL -framework AppKit

 %.o: %.c
	@$(CC) -c -o $@ $(FLAGS) $^

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re:	fclean all
