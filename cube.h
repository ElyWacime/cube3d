#ifndef CUBE_H
# define CUBE_H

# include <unistd.h>
# include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "gnl/gnl.h"
#include "libft/libft.h"
#include "./mlx/include/MLX42/MLX42.h"

#define WIDTH 1000
#define HEIGHT 1000

// typedef struct s_mlx
// {
// 	void*		window;
// 	void*		context;
// 	int32_t		width;
// 	int32_t		height;
// 	double		delta_time;
// }	t_mlx;

typedef struct s_var
{
    char    **map;
    int     largest_line_in_map;
    int     map_len;
}   t_var;

/*
** init_map.c
*/
char    **create_map(char *);
void    _init_map(t_var*);

/*
** utils.c
*/
void ft_error(void);
void    free_double(void **ptr);

/*
** check_map.c
*/
int     get_players_position(char **, int *);
int     flood_fill(char**, int, int, int*);
int is_still_there_zeros(char **, int *);

#endif
