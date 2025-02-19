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

#include "textures_code/textures.c" 

//alias cv="make && ./cube file.cub" && alias cr="make && ./cube creepy.cub"
//
#define SQUARE_SIZE 8
#define DOOR 7
#define WIDTH 1280 // 2560   //     1080
#define HEIGHT 640 // 1280  //      896
#define VIEW 63
#define CUBE_SIZE 8
#define PI 3.14159265358979323846
#define SPEED 1.5

typedef unsigned int t_uint;

typedef struct s_point
{
    float x;
    float y;
}   t_point;

typedef struct s_one_ray_wall
{
    int a;
    int correct_a;
    int idy;
    int idx;
    float distance_correction;
    float distance_to_projection;
    float wall_proj_h;
    int ofssetx;
    int ofssety;
    int pix;
    int idy_;
    float image_offset ;
}   t_ray_wall;


typedef struct s_ray
{
    t_point start;
    t_point target;
    t_point direction;
    int     textures_index;
    float angle;
    float direction_x;
    float direction_y;
    int wall_or_door;
    int wall_or_door_v;
    int wall_or_door_h;
}   t_ray;

typedef struct s_line
{
    float ax;
    float ay;
    float bx;
    float by;
}   t_line;

typedef struct s_player
{
    t_point     position;
    float       vect[2];
    char        direction;
    float       angle;
}   t_player;

typedef struct s_cords
{
    t_line line;
    t_point colision_h;
    t_point colision_v;
    float distance_h;
    float distance_v;
    float h;
    float distance_to_wall;
    int is_collision_horizontal;
}   t_cords;

typedef struct s_door_cords
{
    t_point *cords;
    t_uint  len;
}   t_dcor;

typedef struct s_var
{
    t_player    player;
    mlx_t       *mlx;
    mlx_image_t *img;
    mlx_image_t *img_3d;
    mlx_image_t *mini_map;
    mlx_image_t *mini_map_system; // image

    mlx_texture_t *north;
    mlx_texture_t *east;
    mlx_texture_t *west;
    mlx_texture_t *south;
    mlx_texture_t *door;
    mlx_texture_t *gunPreFire;
    mlx_texture_t *gunFire;
    mlx_image_t *gunFireImg;
    mlx_image_t *gunPreFireImg;

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
    
    t_dcor      door_cords;
    // t_cords     *cor;
    // t_ray       *ray;

    t_uint      r;
    t_uint      g;
    t_uint      b;
    t_uint      o;
}   t_var;

typedef struct s_init_mini_map
{
    t_point start;
    t_point end;
    t_uint  map_x;
    t_uint map_y;
    t_uint mini_width;
    t_uint mini_height;
    t_uint i;
    t_uint j;
}   t_imm;

/*
** game_setup.c
*/
void parse_arguments(char *arg);
void    is_map_all_ones(char **map);
void parsing(int ac, char *av[], t_var *var);
void check_for_images(t_var *var);
void    load_pictures(t_var *var);

/*
** move_player.c
*/
void    move_player_down(t_var *);
void    move_player_right(t_var *);
void    move_player_left(t_var *);
void    move_player_up(t_var *);
int check_if_wall_up_movement(t_var *var, t_point new_position);
int check_if_wall_down_movement(t_var *var, t_point new_position);
int check_if_wall_left_movement(t_var *var, t_point new_position);
int check_if_wall_right_movement(t_var *var, t_point new_position);
void    calcul_down_movement(t_var *);
void    calcul_up_movement(t_var *);
void    calcul_right_movement(t_var *);
void    calcul_left_movement(t_var *);

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
void    cursor_callBackFunc(double x, double y, void *ptr);

/*
** mouse.c
*/
void    change_mouse_position(void* param);
void    mlx_mouse_func(double xpos, double ypos, void* param);

/*
** init_map.c
*/
char        **create_map(char *, t_var *);
void        _init_window(t_var*);
uint32_t    transform_color_to_hexa(int *);

/*
** init_mini_map.c
*/
void    init_img3d(t_var *);
unsigned int   calculate_mini_map_width(t_var *var);
void    check_textures(char *NO, char *SO, char *WE, char *EA);
void   check_path(char *NO, char *SO, char *WE, char *EA);
void    parse_textures(t_var *var);
void    get_texures(t_var *var, int fd);
void    check_len(char **color);
void    check_if_valid_color(char **color);
uint32_t  transform_color_to_hexa(int *color);
void    extract_F(t_var *var);
void    extract_C(t_var *var);
void    get_colors(t_var *var, int fd);

/*
** utils.c
*/
int     ft_isspace(char);
void    ft_error(void);
void    free_double(void**);
char    **strdup_double(char**);
int     strlen_double(void**);
t_uint  px_to_map_grid(t_uint x);
float  calculate_distance(float, float, float, float);
float  from_rad_to_deg(float);
float  from_deg_to_rad(float);
void    draw_line(t_line , t_var *, t_uint);
void    quit_program(t_var *);
void    get_all_door_cords(t_var *var);
void    close_or_open_door(t_var *var);
void open_door(t_var *var);
void close_door(t_var *var);
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
t_point rotate_by(t_point center, t_point m, float angle);
float cast_one_ray_for_movement(t_var var, t_ray *ray);
void set_direciton(t_ray *ray);

/*
** textures.c
*/
size_t north_textures(t_var *var, t_ray_wall *ra_wl, int ofsx);
size_t south_textures(t_var *var, t_ray_wall *ra_wl, int ofsx);
size_t east_textures(t_var *var, t_ray_wall *ra_wl, int ofsx);
size_t west_textures(t_var *var, t_ray_wall *ra_wl, int ofsx);
size_t door_textures_v(t_var *var, t_ray_wall *ra_wl, int ofsx);
size_t door_textures_h(t_var *var, t_ray_wall *ra_wl, int ofsx);
float my_fmod(float theta,int mod);
void draw_gun(t_var *var);

/*
** mini_map_system.c
*/
void init_mini_map_system(t_var *var);
void draw_animated_sprite(t_var *var);


typedef struct s_cast_vertical
{
    t_point colison;
    float skip_x;
    float skip_y;
    float tn;

}cast_v;
typedef struct s_cast_horizantal
{
    t_point horizon;
    t_point colison;
    float skip_x;
    float skip_y;
    float tn;
    
}cast_h;
typedef struct s_cast
{
    t_ray ray;
    t_point r;
    t_point p;
    t_point v;
    float angle;
    float step;
    int i;
    
}t_cast;
// rays_2.c
float distance_squared(t_point a, t_point b);
float str_double_len(char **str);
float my_fmod(float theta,int mod);
float tan_0_90(float theta);
t_point rotate_by(t_point center, t_point m, float angle);

// rays_3.c
void fill_cast(t_var *var,t_cast *cst);
void cast(t_var *var);
float cast_one_ray_for_movement(t_var var, t_ray *ray);
void fill_set_direciton(t_ray *ray);
void set_direciton(t_ray *ray);

// rays_4.c
void fill_cast_vertical(t_ray *ray,cast_v *cst_v);
t_point cast_vertical(t_var *var,t_ray *ray);
void fill_cast_horizantal(t_ray *ray,cast_h *cst_h);
t_point cast_horizantal(t_var *var,t_ray *ray);
float next_px_in_grid(float p, int d);

// rays.c
int check_if_wall_h(t_point start, t_point direction, t_var *var);
int check_if_wall_v(t_point start, t_point direction, t_var *var);
void cast_v_h(t_var *var, t_ray *ray,t_cords *cor);
void one_ray_wall(t_var *var, t_ray *ray);

// rayc_5.c
void fill_one_ray_wall_0(t_var *var, t_ray *ray,t_cords *cor,t_ray_wall *ra_wl);
void fill_one_ray_wall_1(t_var *var, t_ray *ray,t_cords *cor,t_ray_wall *ra_wl);
void fill_one_ray_wall_2(t_var *var, t_ray *ray,t_cords *cor,t_ray_wall *ra_wl);
void while_check(t_var *var, t_ray *ray,t_ray_wall *ra_wl);
void one_ray_wall(t_var *var, t_ray *ray);

// rays_6.c
int check_if_wall_h(t_point start, t_point direction, t_var *var);
int check_if_wall_v(t_point start, t_point direction, t_var *var);
#endif
