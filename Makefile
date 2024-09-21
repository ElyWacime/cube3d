CC = cc
FLAGS = -Wall -Wextra -Werror -fsanitize=address -g
CFILES = check_map.c init_map.c main.c gnl/gnl.c
OBJ = $(CFILES:.c=.o)
NAME = cube
LIBFT = libft/libft.a


all : ${NAME}

${NAME}: ${OBJ} ${LIBFT}
	${CC} ${FLAGS} ${LIBFT} ${CFILES} -o ${NAME}

${LIBFT}: #fix relink
	make -C ./libft

%.o : %.c cube.h
	cc ${CFLAGS} -c $< -o $@

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

git:
	git add .
	git commit -m "update"

re : fclean all