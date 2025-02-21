CC = cc 
# CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g  
CFLAGS = -Wall -Wextra -Werror 

### helper functions ###
LIB_CFILES =  ft_atoi_bonus.c  ft_isalnum_bonus.c  ft_isalpha_bonus.c  ft_isdigit_bonus.c  ft_isprint_bonus.c  ft_strchr_bonus.c  ft_strdup_bonus.c  ft_strjoin_bonus.c\
		 ft_strlcat_bonus.c  ft_strlcpy_bonus.c  ft_strlen_bonus.c  ft_strncmp_bonus.c  ft_strnstr_bonus.c  ft_strrchr_bonus.c  ft_strtrim_bonus.c  ft_substr_bonus.c\
		 ft_tolower_bonus.c  ft_toupper_bonus.c  ft_itoa_bonus.c  ft_split_bonus.c   ft_strmapi_bonus.c  ft_striteri_bonus.c  ft_putchar_fd_bonus.c  ft_bzero_bonus.c\
		 ft_memset_bonus.c  ft_memchr_bonus.c  ft_memcmp_bonus.c  ft_calloc_bonus.c  ft_putstr_fd_bonus.c  ft_putendl_fd_bonus.c  ft_putnbr_fd_bonus.c  ft_memcpy_bonus.c\
		 ft_memmove_bonus.c  ft_isascii_bonus.c \
		 ft_lstnew_bonus_bonus.c  ft_lstadd_front_bonus_bonus.c  ft_lstsize_bonus_bonus.c  ft_lstlast_bonus_bonus.c  ft_lstadd_back_bonus_bonus.c\
		 ft_lstdelone_bonus_bonus.c  ft_lstclear_bonus_bonus.c  ft_lstiter_bonus_bonus.c  ft_lstmap_bonus_bonus.c 
LIB_OBJ = $(LIB_CFILES:.c=.o)
LIB_NAME =  libft.a

all: ${LIB_NAME}

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

${LIB_NAME}: ${LIB_OBJ}
	ar rcs ${LIB_NAME} ${LIB_OBJ}

clean:
	rm ${LIB_OBJ}

fclean: clean
	rm ${LIB_NAME}

re: fclean all

.PHONY: git clean