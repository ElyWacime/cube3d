CC = cc
FLAGS = -Wall -Wextra -Werror 
FLAGS = -fsanitize=address -g
FLAGS = -Wall -Wextra -Werror -fsanitize=address -g
CFILES = rotation.c move_player.c hooks.c init_mini_map.c utils.c check_map.c init_map.c main.c gnl/gnl.c rays.c
OBJ = $(CFILES:.c=.o)
NAME = cube
LIBFT = ./libft2/libft.a
MLX = ./mlx/build/libmlx42.a
MLX_LINUX = ./MLX43/build/libmlx42.a
GLFW = -Iinclude -lglfw -L"/Users/welyousf/goinfre/homebrew/Cellar/glfw/3.4/lib/"
# GLFW = -Iinclude -lglfw -L"/Users/welyousf/goinfre/homebrew/Cellar/glfw/3.4/lib/"

all : ${NAME}

${NAME}:${LIBFT} ${OBJ} 
	${CC} ${FLAGS} ${OBJ} ${LIBFT} ${MLX_LINUX} -Iinclude -ldl -lglfw -pthread -lm -o ${NAME}
# ${CC} ${FLAGS} ${LIBFT} ${OBJ} ${MLX} ${GLFW} -framework OpenGL -framework AppKit -o ${NAME}

${LIBFT}:
	make -C ./libft2

%.o : %.c cube.h
	cc ${FLAGS} -Imlx -c $< -o $@

clean:
	rm -rf ${OBJ}

cleanlib:
	make fclean -C ./libft2

fclean: clean cleanlib
	rm -rf ${NAME}

git:
	git add .
	git commit -m "update"

linux: ${LIBFT} ${OBJ} 
	${CC} ${FLAGS} ${OBJ} ${LIBFT} ${MLX_LINUX} -Iinclude -ldl -lglfw -pthread -lm -o ${NAME}

re : fclean all
