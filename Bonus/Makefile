CC = cc
FLAGS = -Wall -Wextra -Werror 
CFILES = hooks/mouse_bonus.c init_map/mini_map_system_bonus.c hooks/rotation_bonus.c ./move_player/move_player_bonus.c\
			./move_player/move_player1_bonus.c ./move_player/move_player2_bonus.c\
			hooks/hooks_bonus.c init_map/init_mini_map_bonus.c utils/utils_bonus.c utils/utils1_bonus.c utils/utils2_bonus.c\
			parsing/check_map_bonus.c ./init_map/init_map_bonus.c main_bonus.c Rays/rays_2_bonus.c Rays/rays_3_bonus.c Rays/rays_4_bonus.c\
			Rays/rays_5_bonus.c Rays/rays_6_bonus.c Rays/rays_7_bonus.c gnl/gnl_bonus.c Rays/rays_bonus.c ./init_map/init_map1_bonus.c ./init_map/init_map2_bonus.c\
			parsing/game_setup_bonus.c textures_code/door_textures_bonus.c textures_code/wall_textures_bonus.c\
			textures_code/gun_textures_bonus.c move_player/move_player3_bonus.c \
			./libft2/ft_atoi_bonus.c\
			./libft2/ft_isdigit_bonus.c\
			./libft2/ft_split_bonus.c\
			./libft2/ft_strdup_bonus.c   libft2/ft_strlcat_bonus.c  libft2/ft_strlcpy_bonus.c\
			./libft2/ft_strjoin_bonus.c  ./libft2/ft_strlen_bonus.c ./libft2/ft_strncmp_bonus.c \
			./libft2/ft_strnstr_bonus.c ./libft2/ft_substr_bonus.c


OBJ = $(CFILES:.c=.o)
NAME = ../cub3D_bonus
MLX = ./MLX42/build/libmlx42.a
MLX_LINUX = ./MLX42/build/libmlx42.a
INCLUDES = MLX42/build/libmlx42.a libft2/libft.a  MLX42/build/libglfw3.a -Iinclude -lm -framework Cocoa -framework OpenGL -framework IOKit
GLFW = -Iinclude -lglfw -L"/Users/welyousf/goinfre/homebrew/Cellar/glfw/3.4/lib/"
GLFW = -Iinclude -lglfw -L"/Users/skamroun/goinfre/homebrew/Cellar/glfw/3.4/lib/"

all : ${NAME}

${NAME}: ${OBJ} 
	${CC} ${FLAGS}  ${OBJ} ${MLX} ${GLFW} -O3 -framework OpenGL -framework AppKit -o ${NAME}

%.o : %.c cube_bonus.h
	cc ${FLAGS} -Imlx -c $< -o $@

clean:
	rm -rf ${OBJ}

fclean: clean 
	rm -rf ${NAME}

git:
	git add .
	git commit -m "update"

linux: ${OBJ} 
	${CC} ${FLAGS} ${OBJ}  ${MLX_LINUX} -Iinclude -ldl -lglfw  -lm -o ${NAME}

re : fclean all

mlx:
	git clone https://github.com/codam-coding-college/MLX42.git && cd MLX42 && cmake -B build && cmake --build build -j4

	
	