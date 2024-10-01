#ifndef CUBE_H
# define CUBE_H

# include <unistd.h>
# include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "gnl/gnl.h"
#include "libft/libft.h"
#include "./mlx/include/MLX42/MLX42.h"
#include <math.h>
#include <stdint.h>


#define WIDTH 2500
#define HEIGHT 1200

typedef unsigned int t_uint;

typedef struct s_var
{
    mlx_t       *mlx;
    mlx_image_t *img;
    mlx_image_t *mini_map;
    char        **map;
    char        **textures;
    char        **colors;
    int         largest_line_in_map;
    int         map_len;
    t_uint      mini_width;
    t_uint      mini_height;
    double      player_position[2];
    uint32_t    color_C;
    uint32_t    color_F;
}   t_var;

/*
** hooks.c
*/
void    listen_to_key(struct mlx_key_data, void *);

/*
** init_map.c
*/
char        **create_map(char *, t_var *);
void        _init_window(t_var*);
uint32_t    transform_color_to_hexa(int *);

/*
** init_mini_map.c
*/
void    init_mini_map(t_var *);
void    color_player(t_uint *, t_var *, int);

/*
** utils.c
*/
int     ft_isspace(char);
void    ft_error(void);
void    free_double(void**);
char    **strdup_double(char**);
int     strlen_double(void**);
void    print_map(t_var *var);
t_uint  px_to_map_grid(t_uint x);
double  calculate_distance(double, double, double, double);

/*
** check_map.c
*/
int     get_players_position(char **, int *);
void    flood_fill(char**, int, int);
int     is_still_there_zeros(char **, int *);

#endif
