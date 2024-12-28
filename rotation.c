#include "cube.h"

void    calcul_right_rotation(t_var *var)
{
    double x;
    double y;

    x = var->player.vect[0] - var->player.position[0];
    y = var->player.vect[1] - var->player.position[1];
    var->player.vect[0] = (x * cos(from_deg_to_rad(9)) - y * sin(from_deg_to_rad(9)))
        + var->player.position[0];
    var->player.vect[1] = (x * sin(from_deg_to_rad(9)) + y * cos(from_deg_to_rad(9)))
        + var->player.position[1];
}

void    calcul_left_rotation(t_var *var)
{
    double x;
    double y;

    x = var->player.vect[0] - var->player.position[0];
    y = var->player.vect[1] - var->player.position[1];
    var->player.vect[0] = (x * cos(from_deg_to_rad(360 - 9))
        - y * sin(from_deg_to_rad(360 - 9)))
        + var->player.position[0];
    var->player.vect[1] = (x * sin(from_deg_to_rad(360 - 9))
        + y * cos(from_deg_to_rad(360 - 9)))
        + var->player.position[1];
}

void    rotate_player_right(t_var *var)
{
    t_line  vector;

    mlx_delete_image(var->mlx, var->mini_map);
    calcul_right_rotation(var);
    var->player.angle = my_fmod((var->player.angle + (360 - 9)),360);
    vector.ax = var->player.position[0];
    vector.ay = var->player.position[1];
    vector.bx = var->player.vect[0];
    vector.by = var->player.vect[1];
    init_mini_map(var);
    draw_line(vector, var, 0x00FF00FF);
    cast(var);
}

void    rotate_player_left(t_var *var)
{
    t_line  vector;
    
    mlx_delete_image(var->mlx, var->mini_map);
    calcul_left_rotation(var);
    var->player.angle = my_fmod(var->player.angle + 9, 360);
    vector.ax = var->player.position[0];
    vector.ay = var->player.position[1];
    vector.bx = var->player.vect[0];
    vector.by = var->player.vect[1];
    init_mini_map(var);
    draw_line(vector, var, 0x00FF00FF);
    cast(var);
}