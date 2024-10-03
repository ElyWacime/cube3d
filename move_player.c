#include "cube.h"

void    calcul_right_movement(t_var *var)
{
    double  new_position[2];

    new_position[0] = (var->player_position[0]) 
        + (2.0 * cos(from_deg_to_rad(var->player.angle)));
    new_position[1] = (var->player_position[1])
        + (2.0 * sin(from_deg_to_rad(var->player.angle)));
    var->player_position[0] = new_position[0];
    var->player_position[1] = new_position[1];
    new_position[0] = (var->player.vect[0]) 
        + (2.0 * cos(from_deg_to_rad(var->player.angle)));
    new_position[1] = (var->player.vect[1])
        + (2.0 * sin(from_deg_to_rad(var->player.angle)));
    var->player.vect[0] = new_position[0];
    var->player.vect[1] = new_position[1];
}

void    move_player_right(t_var *var)
{
    t_line  vector;

    mlx_delete_image(var->mlx, var->mini_map);
    calcul_right_movement(var);
    vector.ax = var->player.position[0];
    vector.ay = var->player.position[1];
    vector.bx = var->player.vect[0];
    vector.by = var->player.vect[1];
    init_mini_map(var);
    draw_line(vector, var);
}

void    move_player_up(t_var *var)
{
    (void)var;
}

void    move_player_left(t_var *var)
{
    (void)var;
}

void    move_player_down(t_var *var)
{
    (void)var;
}