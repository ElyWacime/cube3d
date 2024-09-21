#ifndef CUBE_H
# define CUBE_H

# include <unistd.h>
# include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "gnl/gnl.h"
#include "libft/libft.h"

/*
** init_map.c
*/
char    **create_map(void);

/*
** check_map.c
*/
int     get_players_position(char **map, int *position);
int     flood_fill(char **map, int x, int y, int *k);
int is_still_there_zeros(char **_map, int *zero_position);

#endif