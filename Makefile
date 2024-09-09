CC = cc
FLAGS = -Wall -Wextra -Werror
CFILES = init_map.c main.c gnl/gnl.c
OBJ = $(CFILES:.c=.o)
NAME = cube
LIBFT = libft/libft.a


all : ${NAME}

${NAME}: ${OBJ}
	${CC} ${FLAGS} ${LIBFT} ${CFILES} -o ${NAME}

%.o : %.c cube.h
	cc ${CFLAGS} -c $< -o $@

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}