# CC = cc
# CFLAGS = -Wall -Wextra -Werror
SRC = ft_isalnum.c ft_memcmp.c ft_putstr_fd.c ft_strlcpy.c ft_substr.c ft_isalpha.c ft_memcpy.c ft_split.c ft_strlen.c ft_tolower.c ft_isascii.c ft_memmove.c ft_strchr.c ft_strmapi.c ft_toupper.c ft_isdigit.c ft_memset.c ft_strdup.c ft_strncmp.c ft_atoi.c ft_isprint.c ft_putchar_fd.c ft_striteri.c ft_strnstr.c ft_bzero.c ft_itoa.c ft_putendl_fd.c ft_strjoin.c ft_strrchr.c ft_calloc.c ft_memchr.c ft_putnbr_fd.c ft_strlcat.c ft_strtrim.c
OBJ = $(SRC:.c=.o)
BONUS = ft_lstnew_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c
BONUSO = $(BONUS:.c=.o)
NAME = libft.a

all: $(NAME)

$(NAME): ${OBJ}
	ar rcs $(NAME) ${OBJ}

bonus: ${BONUSO}
	ar rcs $(NAME) ${BONUSO}

# %.o : %.c libft.h
# 	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf ${OBJ} ${BONUSO}

fclean:clean
	rm -rf $(NAME) .DS_Store a.out app main.c .vscode app.*

re: fclean all

.PHONY: all bonus clean fclean re

main:
# 	echo '#include "libft.h"\n#include<stdio.h>\nint main(){return(0);}' > main.c
	$(CC) $(CFLAGS) main.c libft.a -o ttt && ./ttt