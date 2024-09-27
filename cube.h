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
    char    **textures;
    char    **colors;
    int     largest_line_in_map;
    int     map_len;
    size_t  color_C;
    size_t  color_F;
}   t_var;

/*
** init_map.c
*/
char    **create_map(char *, t_var *);
void    _init_map(t_var*);

/*
** utils.c
*/
int ft_isspace(char);
void ft_error(void);
void    free_double(void**);
char    **strdup_double(char**);
int strlen_double(void**);

/*
** check_map.c
*/
int     get_players_position(char **, int *);
void     flood_fill(char**, int, int);
int is_still_there_zeros(char **, int *);

#endif
