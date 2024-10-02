CC = cc
FLAGS = -Wall -Wextra -Werror -fsanitize=address -g
CFILES = hooks.c init_mini_map.c utils.c check_map.c init_map.c main.c gnl/gnl.c
OBJ = $(CFILES:.c=.o)
NAME = cube
LIBFT = libft/libft.a
MLX = ./mlx/build/libmlx42.a
GLFW = -Iinclude -lglfw -L"/Users/welyousf/goinfre/homebrew/Cellar/glfw/3.4/lib/"

all : ${NAME}

${NAME}: ${OBJ} ${LIBFT}
	${CC} ${FLAGS} ${LIBFT} ${CFILES} ${MLX} ${GLFW} \
	-framework OpenGL -framework AppKit -o ${NAME}

${LIBFT}: #fix relink
	make -C ./libft

%.o : %.c cube.h
	cc ${CFLAGS} -Imlx -c $< -o $@

clean:
	rm -rf ${OBJ}

cleanlib:
	make fclean -C ./libft

fclean: clean cleanlib
	rm -rf ${NAME}

git:
	git add .
	git commit -m "update"

re : fclean all