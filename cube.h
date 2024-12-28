#ifndef CUBE_H
# define CUBE_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include "gnl/gnl.h"
#include "./libft2/libft.h"
#include <math.h>
#include <stdint.h>
#include "./MLX43/include/MLX42/MLX42.h"

//alias cv="make && ./cube file.cube" && alias cr="make && ./cube creepy.cube"
//
#define SQUARE_SIZE 8
#define WIDTH 1280 // 2560   //     1080
#define HEIGHT 640 // 1280  //      896
#define VIEW 63
#define CUBE_SIZE 8
#define PI 3.14159265358979323846
#define SPEED 2

typedef unsigned int t_uint;

typedef struct s_point
{
    double x;
    double y;
}   t_point;

typedef struct s_one_ray_wall
{
    int a;
    int correct_a;
    int idy;
    int idx;
    double distance_correction;
    double distance_to_projection;
    double wall_projection_height;
    int ofssetx;
    int ofssety;
    int pix;
    int idy_;
    double image_offset ;
}   t_ray_wall;


typedef struct s_ray
{
    t_point start;
    t_point target;
    t_point direction;
    int     textures_index;
    float angle;
    double direction_x;
    double direction_y;
}   t_ray;

typedef struct s_line
{
    double ax;
    double ay;
    double bx;
    double by;
}   t_line;

typedef struct s_player
{
    double  position[2];
    double  vect[2];
    char    direction;
    float  angle;
}   t_player;

typedef struct s_cords
{
    t_line line;
    t_point colision_h;
    t_point colision_v;
    double distance_h;
    double distance_v;
    double h;
    double distance_to_wall;
    int is_collision_horizontal;
}   t_cords;

typedef struct s_var
{
    t_player    player;
    mlx_t       *mlx;
    mlx_t       *mlx_3d;
    mlx_image_t *img;
    mlx_image_t *img_3d;
    mlx_image_t *mini_map;
    mlx_texture_t *north;
    mlx_texture_t *east;
    mlx_texture_t *west;
    mlx_texture_t *south;
    char        **map;
    char        **textures;
    char        **colors;
    int         largest_line_in_map;
    int         map_len;
    int         x_3d;
    int         y_3d;

    t_uint      mini_width;
    t_uint      mini_height;
    uint32_t    color_C;
    uint32_t    color_F;
}   t_var;

/*
** move_player.c
*/
void    move_player_down(t_var *);
void    move_player_right(t_var *);
void    move_player_left(t_var *);
void    move_player_up(t_var *);

/*
** rotation.c
*/
void    calcul_right_rotation(t_var *);
void    calcul_left_rotation(t_var *);
void    rotate_player_right(t_var *);
void    rotate_player_left(t_var *);

/*
** hooks.c
*/
void    listen_to_key(struct mlx_key_data, void *);
void    get_point_position_to_draw_diraction(t_var *, t_uint);
void    color_player(t_var *var, int color);

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
void    create_mini_map_image(t_var *var);
void    draw_vector(t_var *var);

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
double  from_rad_to_deg(double);
double  from_deg_to_rad(double);
int     check_if_wall(double , double , t_var *);
void    draw_line(t_line , t_var *, t_uint);
void    quit_program(t_var *);
/*
** check_map.c
*/
int     get_players_position(char **, int *, t_var *);
void    flood_fill(char**, int, int);
int     is_still_there_zeros(char **, int *);

/*
** rays.c
*/
void cast(t_var *);
void    _init_window_3d(t_var *var);
t_point rotate_by(t_point center, t_point m, double angle);

/*
** textures.c
*/
size_t north_textures(t_var *var, t_ray_wall *ra_wl, t_cords *cor);
size_t south_textures(t_var *var, t_ray_wall *ra_wl, t_cords *cor);
size_t east_textures(t_var *var, t_ray_wall *ra_wl, t_cords *cor);
size_t west_textures(t_var *var, t_ray_wall *ra_wl, t_cords *cor);
double my_fmod(double theta,int mod);
#endif
