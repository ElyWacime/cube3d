#include "cube.h"

int check_if_wall_left_movement(t_var *var, double *new_position)
{
    if (0 < var->player.angle && var->player.angle < 90)
    {
        if (var->map[(t_uint)((new_position[1] - 0.1) / SQUARE_SIZE)][(t_uint)((new_position[0] - 0.1) / SQUARE_SIZE)] == '0')
            return 1;
    }
    else if (90 < var->player.angle && var->player.angle < 180)
    {
        if (var->map[(t_uint)((new_position[1] - 0.1) / SQUARE_SIZE)][(t_uint)((new_position[0] + 0.1) / SQUARE_SIZE)] == '0')
            return 1;
    }
    else if (180 < var->player.angle && var->player.angle < 270)
    {
        if (var->map[(t_uint)((new_position[1] + 0.1) / SQUARE_SIZE)][(t_uint)((new_position[0] + 0.1) / SQUARE_SIZE)] == '0')
            return 1;
    }
    else if (270 < var->player.angle && var->player.angle < 360)
    {
        if (var->map[(t_uint)((new_position[1] + 0.1) / SQUARE_SIZE)][(t_uint)((new_position[0] - 0.1) / SQUARE_SIZE)] == '0')
            return 1;
    }
    return 0;
}

int check_if_wall_up_movement(t_var *var, double *new_position)
{
    static int i;
    printf("%f\n", var->player.angle);
    if (var->player.angle == 0)
    {
        if (var->map[px_to_map_grid(new_position[1] + 1)][px_to_map_grid(new_position[0])] != '1')
            return 1;
    }
    else if (var->player.angle == 90)
    {
        if (var->map[px_to_map_grid(new_position[1])][px_to_map_grid(new_position[0] - 1)] != '1')
        {
            i += 1;
            printf("static int = %d\tpalyer x = %d, player y = %d\n", i, px_to_map_grid(new_position[0] - 1), px_to_map_grid(new_position[1]));
            return 1;
        }
    }
    else if (var->player.angle == 180)
    {
        if (var->map[px_to_map_grid(new_position[1] - 1)][px_to_map_grid(new_position[0])] != '1')
            return 1;
    }
    else if (var->player.angle == 270)
    {
        if (var->map[px_to_map_grid(new_position[1])][px_to_map_grid(new_position[0] + 1)] != '1')
            return 1;
    }
    else
    {
        if (var->map[px_to_map_grid(new_position[1])][px_to_map_grid(new_position[0])] != '1')
            return 1;
    }
    return 0;
}

void    calcul_right_movement(t_var *var)
{
    double  new_position[2];

    new_position[0] = (var->player.position[0]) 
        + (SPEED * sin(from_deg_to_rad(var->player.angle)));
    new_position[1] = (var->player.position[1])
        + (SPEED * cos(from_deg_to_rad(var->player.angle)));
    if (var->map[px_to_map_grid(new_position[1])][px_to_map_grid(new_position[0])] != '1')
    {
        var->player.position[0] = new_position[0];
        var->player.position[1] = new_position[1];
    }
    else
        return ;
}

void    calcul_left_movement(t_var *var)
{
    double  new_position[2];

    new_position[0] = (var->player.position[0])
        - (SPEED * sin(from_deg_to_rad(var->player.angle)));
    new_position[1] = (var->player.position[1])
        - (SPEED * cos(from_deg_to_rad(var->player.angle)));
    if (new_position[1] <= 0 || new_position[0] <= 0)
        return ;
    if (var->map[px_to_map_grid(new_position[1])][px_to_map_grid(new_position[0])] != '1')
    {
        var->player.position[0] = new_position[0];
        var->player.position[1] = new_position[1];
    }
}

void    calcul_up_movement(t_var *var)
{
    double  new_position[2];
    new_position[0] = (var->player.position[0])
        + (SPEED * cos(from_deg_to_rad(var->player.angle)));
    new_position[1] = (var->player.position[1])
        - (SPEED * sin(from_deg_to_rad(var->player.angle)));
    if (new_position[1] <= 0)
        return ;
    if (check_if_wall_up_movement(var, new_position))
    {
        var->player.position[0] = new_position[0];
        var->player.position[1] = new_position[1];
    }
}

void    calcul_down_movement(t_var *var)
{
    double  new_position[2];

    new_position[0] = (var->player.position[0])
        - (SPEED * cos(from_deg_to_rad(var->player.angle)));
    new_position[1] = (var->player.position[1])
        + (SPEED * sin(from_deg_to_rad(var->player.angle)));
    if (new_position[0] <= 0)
        return ;
    if (var->map[px_to_map_grid(new_position[1])][px_to_map_grid(new_position[0])] != '1')
    {
        var->player.position[0] = new_position[0];
        var->player.position[1] = new_position[1];
        // printf("%f\t%f\n", var->player.position[0], var->player.position[1]);
    }
}

void    move_player_down(t_var *var)
{
    calcul_down_movement(var);
    init_mini_map(var);
    cast(var);
}

void    move_player_up(t_var *var)
{
    calcul_up_movement(var);
    init_mini_map(var);
    cast(var);
}

void    move_player_right(t_var *var)
{
    calcul_right_movement(var);
    init_mini_map(var);
    cast(var);
}

void    move_player_left(t_var *var)
{
    calcul_left_movement(var);
    init_mini_map(var);
    cast(var);
}
