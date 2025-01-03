#include "cube.h"

void    calcul_right_rotation(t_var *var)
{
    double x;
    double y;

    x = var->player.vect[0] - var->player.position.x;
    y = var->player.vect[1] - var->player.position.y;
    var->player.vect[0] = (x * cos(from_deg_to_rad(9)) - y * sin(from_deg_to_rad(9)))
        + var->player.position.x;
    var->player.vect[1] = (x * sin(from_deg_to_rad(9)) + y * cos(from_deg_to_rad(9)))
        + var->player.position.y;
}

void    calcul_left_rotation(t_var *var)
{
    double x;
    double y;

    x = var->player.vect[0] - var->player.position.x;
    y = var->player.vect[1] - var->player.position.y;
    var->player.vect[0] = (x * cos(from_deg_to_rad(360 - 9))
        - y * sin(from_deg_to_rad(360 - 9)))
        + var->player.position.x;
    var->player.vect[1] = (x * sin(from_deg_to_rad(360 - 9))
        + y * cos(from_deg_to_rad(360 - 9)))
        + var->player.position.y;
}

void    rotate_player_right(t_var *var)
{
    calcul_right_rotation(var);
    var->player.angle = my_fmod((var->player.angle + (360 - 9)),360);
    init_img3d(var);
    cast(var);
    init_mini_map_system(var);
}

void    rotate_player_left(t_var *var)
{
    calcul_left_rotation(var);
    var->player.angle = my_fmod(var->player.angle + 9, 360);
    init_img3d(var);
    cast(var);
    init_mini_map_system(var);
}