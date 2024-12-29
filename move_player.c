#include "cube.h"

void    calcul_right_movement(t_var *var)
{
    double  new_position[2];
    int direction;
    new_position[0] = (var->player.position[0]) 
        + (SPEED * sin(from_deg_to_rad(var->player.angle)));
    new_position[1] = (var->player.position[1])
        + (SPEED * cos(from_deg_to_rad(var->player.angle)));
    if (var->map[(t_uint)new_position[1] / SQUARE_SIZE][(t_uint)new_position[0] / SQUARE_SIZE] != '1')
    {
        direction = 1;
        if ((0 < var->player.angle  && var->player.angle < 90) || (270 < var->player.angle && var->player.angle < 360))
            direction = -1;
        if ((new_position[0] /SQUARE_SIZE) * SQUARE_SIZE == new_position[0])
            new_position[0] +=direction * 0.01;
        if ((new_position[1] /SQUARE_SIZE) * SQUARE_SIZE == new_position[1])
            new_position[1] +=direction * 0.01;
        var->player.position[0] = new_position[0];
        var->player.position[1] = new_position[1];
    }
    else
        return ;
    new_position[0] = (var->player.vect[0]) 
        + (SPEED * sin(from_deg_to_rad(var->player.angle)));
    new_position[1] = (var->player.vect[1])
        + (SPEED * cos(from_deg_to_rad(var->player.angle)));
    var->player.vect[0] = new_position[0];
    var->player.vect[1] = new_position[1];
}

void    calcul_left_movement(t_var *var)
{
    double  new_position[2];
    int direction;
    new_position[0] = (var->player.position[0])
        - (SPEED * sin(from_deg_to_rad(var->player.angle)));
    new_position[1] = (var->player.position[1])
        - (SPEED * cos(from_deg_to_rad(var->player.angle)));
    if (new_position[1] <= 0 || new_position[0] <= 0)
        return ;
    if (var->map[(t_uint)new_position[1] / SQUARE_SIZE][(t_uint)new_position[0] / SQUARE_SIZE] != '1')
    {
        direction = 1;
        if ((0 < var->player.angle  && var->player.angle < 90) || (270 < var->player.angle && var->player.angle < 360))
            direction = -1;
        if ((new_position[0] /SQUARE_SIZE) * SQUARE_SIZE == new_position[0])
            new_position[0] +=direction * 0.01;
        if ((new_position[1] /SQUARE_SIZE) * SQUARE_SIZE == new_position[1])
            new_position[1] +=direction * 0.01;
        var->player.position[0] = new_position[0];
        var->player.position[1] = new_position[1];
    }
    else
        return ;
    new_position[0] = (var->player.vect[0])
        - (SPEED * sin(from_deg_to_rad(var->player.angle)));
    new_position[1] = (var->player.vect[1])
        - (SPEED * cos(from_deg_to_rad(var->player.angle)));
    if (new_position[1] <= 0 || new_position[0] <= 0)
        return ;
    var->player.vect[0] = new_position[0];
    var->player.vect[1] = new_position[1];
}

void    calcul_up_movement(t_var *var)
{
    double  new_position[2];
    int direction;
    new_position[0] = (var->player.position[0])
        + (SPEED * cos(from_deg_to_rad(var->player.angle)));
    new_position[1] = (var->player.position[1])
        - (SPEED * sin(from_deg_to_rad(var->player.angle)));
    if (new_position[1] <= 0)
        return ;
    if (var->map[(t_uint)new_position[1] / SQUARE_SIZE][(t_uint)new_position[0] / SQUARE_SIZE] != '1')
    {
        direction = 1;
        if (var->player.angle < 180)
            direction = -1;
        if ((new_position[0] /SQUARE_SIZE) * SQUARE_SIZE == new_position[0])
            new_position[0] +=direction * 0.01;
        if ((new_position[1] /SQUARE_SIZE) * SQUARE_SIZE == new_position[1])
            new_position[1] +=direction * 0.01;
        var->player.position[0] = new_position[0];
        var->player.position[1] = new_position[1];
    }
    else
        return ;
    new_position[0] = (var->player.vect[0])
        + (SPEED * cos(from_deg_to_rad(var->player.angle)));
    new_position[1] = (var->player.vect[1])
        - (SPEED * sin(from_deg_to_rad(var->player.angle)));
    if (new_position[1] <= 0)
        return ;
    var->player.vect[0] = new_position[0];
    var->player.vect[1] = new_position[1];
}

void    calcul_down_movement(t_var *var)
{
    double  new_position[2];
    int direction;
    new_position[0] = (var->player.position[0])
        - (SPEED * cos(from_deg_to_rad(var->player.angle)));
    new_position[1] = (var->player.position[1])
        + (SPEED * sin(from_deg_to_rad(var->player.angle)));
    if (new_position[0] <= 0)
        return ;
    if (var->map[(t_uint)new_position[1] / SQUARE_SIZE][(t_uint)new_position[0] / SQUARE_SIZE] != '1')
    {
        direction = 1;
        if (var->player.angle > 180)
            direction = -1;
        if ((new_position[0] /SQUARE_SIZE) * SQUARE_SIZE == new_position[0])
            new_position[0] +=direction * 0.01;
        if ((new_position[1] /SQUARE_SIZE) * SQUARE_SIZE == new_position[1])
            new_position[1] +=direction * 0.01;
        var->player.position[1] = new_position[1];
        var->player.position[0] = new_position[0];
    }
    else
        return ;
    new_position[0] = (var->player.vect[0])
        - (SPEED * cos(from_deg_to_rad(var->player.angle)));
    new_position[1] = (var->player.vect[1])
        + (SPEED * sin(from_deg_to_rad(var->player.angle)));
    if (new_position[0] <= 0)
        return ;
    var->player.vect[0] = new_position[0];
    var->player.vect[1] = new_position[1];
}

void    move_player_down(t_var *var)
{
    // t_line  vector;

    mlx_delete_image(var->mlx, var->mini_map);
    calcul_down_movement(var);
    // vector.ax = var->player.position[0];
    // vector.ay = var->player.position[1];
    // vector.bx = var->player.vect[0];
    // vector.by = var->player.vect[1];
    init_mini_map(var);
    // draw_line(vector, var, 0x00FF00FF);
    cast(var);
}

void    move_player_up(t_var *var)
{
    // t_line  vector;

    mlx_delete_image(var->mlx, var->mini_map);
    calcul_up_movement(var);
    // vector.ax = var->player.position[0];
    // vector.ay = var->player.position[1];
    // vector.bx = var->player.vect[0];
    // vector.by = var->player.vect[1];
    init_mini_map(var);
    // draw_line(vector, var, 0x00FF00FF);
    cast(var);
}

void    move_player_right(t_var *var)
{
    // t_line  vector;

    mlx_delete_image(var->mlx, var->mini_map);
    calcul_right_movement(var);
    // vector.ax = var->player.position[0];
    // vector.ay = var->player.position[1];
    // vector.bx = var->player.vect[0];
    // vector.by = var->player.vect[1];
    init_mini_map(var);
    // draw_line(vector, var, 0x00FF00FF);
    cast(var);
}

void    move_player_left(t_var *var)
{
    // t_line  vector;

    mlx_delete_image(var->mlx, var->mini_map);
    calcul_left_movement(var);
    // vector.ax = var->player.position[0];
    // vector.ay = var->player.position[1];
    // vector.bx = var->player.vect[0];
    // vector.by = var->player.vect[1];
    init_mini_map(var);
    // draw_line(vector, var, 0x00FF00FF);
    cast(var);
}
