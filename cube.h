#ifndef CUBE_H
# define CUBE_H

# include <unistd.h>
# include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "gnl/gnl.h"
#include "libft/libft.h"
#include "./mlx/include/MLX42/MLX42.h"

/*
** init_map.c
*/
char    **create_map(char *);

/*
** check_map.c
*/
int     get_players_position(char **, int *);
int     flood_fill(char**, int, int, int*);
int is_still_there_zeros(char **, int *);

#endif
