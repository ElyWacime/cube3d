CC = cc
# FLAGS = -fsanitize=address -g
# FLAGS = -fsanitize=address -g
# FLAGS = -Wall -Wextra -g
FLAGS = -Wall -Wextra -Werror 
CFILES = hooks/mouse.c mini_map_system.c hooks/rotation.c ./move_player/move_player.c\
			./move_player/move_player1.c ./move_player/move_player2.c\
			hooks/hooks.c init_mini_map.c utils/utils.c utils/utils1.c utils/utils2.c\
			parsing/check_map.c ./init_map/init_map.c main.c Rays/rays_2.c Rays/rays_3.c Rays/rays_4.c\
			Rays/rays_5.c Rays/rays_6.c Rays/rays_7.c gnl/gnl.c Rays/rays.c ./init_map/init_map1.c ./init_map/init_map2.c\
			parsing/game_setup.c textures_code/door_textures.c textures_code/wall_textures.c\
			textures_code/gun_textures.c move_player/move_player3.c\

OBJ = $(CFILES:.c=.o)
NAME = cube
LIBFT = ./libft2/libft.a
MLX = ./MLX42/build/libmlx42.a
MLX_LINUX = ./MLX42/build/libmlx42.a
INCLUDES = MLX42/build/libmlx42.a libft2/libft.a  MLX42/build/libglfw3.a -Iinclude -lm -framework Cocoa -framework OpenGL -framework IOKit
GLFW = -Iinclude -lglfw -L"/Users/welyousf/goinfre/homebrew/Cellar/glfw/3.4/lib/"
GLFW = -Iinclude -lglfw -L"/Users/skamroun/goinfre/homebrew/Cellar/glfw/3.4/lib/"

all : ${NAME}
${NAME}:${LIBFT} ${OBJ} 
	${CC} ${FLAGS} ${LIBFT} ${OBJ} ${MLX} ${GLFW} -O3 -framework OpenGL -framework AppKit -o ${NAME}
# ${CC} ${FLAGS} ${OBJ} ${LIBFT} ${MLX_LINUX} -O3 -Iinclude -ldl -lglfw  -lm -o ${NAME}
# ${CC} ${FLAGS} ${OBJ} ${MLX} ${INCLUDES} -o ${NAME}

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
	${CC} ${FLAGS} ${OBJ} ${LIBFT} ${MLX_LINUX} -Iinclude -ldl -lglfw  -lm -o ${NAME}

re : fclean all

mlx:
	git clone https://github.com/codam-coding-college/MLX42.git
	cd MLX42
	cmake -B build
	cmake --build build -j4