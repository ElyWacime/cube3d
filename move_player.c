#include "cube.h"

int check_if_wall_up_movement(t_var *var, t_point new_position)
{
    if (var->player.angle == 0)
    {
        if (var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x + 0.1)] != '1')
            return 1;
    }
    else if (var->player.angle == 90)
    {
        if (var->map[px_to_map_grid(new_position.y - 0.1)][px_to_map_grid(new_position.x)] != '1')
            return 1;
    }
    else if (var->player.angle == 180)
    {
        if (var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x - 0.1)] != '1')
            return 1;
    }
    else if (var->player.angle == 270)
    {
        if (var->map[px_to_map_grid(new_position.y + 0.1)][px_to_map_grid(new_position.x)] != '1')
            return 1;
    }
    else
    {
        if (var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x)] != '1')
            return 1;
    }
    return 0;
}

int check_if_wall_down_movement(t_var *var, t_point new_position)
{
    if (var->player.angle == 0)
    {
        if (var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x - 0.1)] != '1')
            return 1;
    }
    else if (var->player.angle == 90)
    {
        if (var->map[px_to_map_grid(new_position.y + 0.1)][px_to_map_grid(new_position.x)] != '1')
            return 1;
    }
    else if (var->player.angle == 180)
    {
        if (var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x + 0.1)] != '1')
            return 1;
    }
    else if (var->player.angle == 270)
    {
        if (var->map[px_to_map_grid(new_position.y - 0.1)][px_to_map_grid(new_position.x)] != '1')
            return 1;
    }
    else
    {
        if (var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x)] != '1')
            return 1;
    }
    return 0;
}

int check_if_wall_left_movement(t_var *var, t_point new_position)
{
    if (var->player.angle == 0)
    {
        if (var->map[px_to_map_grid(new_position.y - 0.1)][px_to_map_grid(new_position.x)] != '1')
            return 1;
    }
    else if (var->player.angle == 90)
    {
        if (var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x - 0.1)] != '1')
            return 1;
    }
    else if (var->player.angle == 180)
    {
        if (var->map[px_to_map_grid(new_position.y + 0.1)][px_to_map_grid(new_position.x)] != '1')
            return 1;
    }
    else if (var->player.angle == 270)
    {
        if (var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x + 0.1)] != '1')
            return 1;
    }
    else
    {
        if (var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x)] != '1')
            return 1;
    }
    return 0;
}

int check_if_wall_right_movement(t_var *var, t_point new_position)
{
    if (var->player.angle == 0)
    {
        if (var->map[px_to_map_grid(new_position.y + 0.1)][px_to_map_grid(new_position.x)] != '1')
            return 1;
    }
    else if (var->player.angle == 90)
    {
        if (var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x + 0.1)] != '1')
            return 1;
    }
    else if (var->player.angle == 180)
    {
        if (var->map[px_to_map_grid(new_position.y - 0.1)][px_to_map_grid(new_position.x)] != '1')
            return 1;
    }
    else if (var->player.angle == 270)
    {
        if (var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x - 0.1)] != '1')
            return 1;
    }
    else
    {
        if (var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x)] != '1')
            return 1;
    }
    return 0;
}

void    calcul_right_movement(t_var *var)
{
    t_point new_position;

    new_position.x = (var->player.position[0])
        + (SPEED * sin(from_deg_to_rad(var->player.angle)));
    new_position.y = (var->player.position[1])
        + (SPEED * cos(from_deg_to_rad(var->player.angle)));
    if (check_if_wall_right_movement(var, new_position))
    {
        var->player.position[0] = new_position.x;
        var->player.position[1] = new_position.y;
    }
}

void    calcul_left_movement(t_var *var)
{
    t_point new_position;

    new_position.x = (var->player.position[0])
        - (SPEED * sin(from_deg_to_rad(var->player.angle)));
    new_position.y = (var->player.position[1])
        - (SPEED * cos(from_deg_to_rad(var->player.angle)));
    if (new_position.y <= 0 || new_position.x <= 0)
        return ;
    if (check_if_wall_left_movement(var, new_position))
    {
        var->player.position[0] = new_position.x;
        var->player.position[1] = new_position.y;
    }
}

void    calcul_up_movement(t_var *var)
{
    t_point new_position;
    new_position.x = (var->player.position[0])
        + (SPEED * cos(from_deg_to_rad(var->player.angle)));
    new_position.y = (var->player.position[1])
        - (SPEED * sin(from_deg_to_rad(var->player.angle)));
    if (new_position.y <= 0)
        return ;
    if (check_if_wall_up_movement(var, new_position))
    {
        var->player.position[0] = new_position.x;
        var->player.position[1] = new_position.y;
    }
}

void    calcul_down_movement(t_var *var)
{
    t_point new_position;

    new_position.x = (var->player.position[0])
        - (SPEED * cos(from_deg_to_rad(var->player.angle)));
    new_position.y = (var->player.position[1])
        + (SPEED * sin(from_deg_to_rad(var->player.angle)));
    if (new_position.x <= 0)
        return ;
    if (check_if_wall_down_movement(var, new_position))
    {
        var->player.position[0] = new_position.x;
        var->player.position[1] = new_position.y;
    }
}

void    move_player_down(t_var *var)
{
    calcul_down_movement(var);
    init_mini_map(var);
    cast(var);
    init_mini_map_system(var);
}

void    move_player_up(t_var *var)
{
    calcul_up_movement(var);
    init_mini_map(var);
    cast(var);
    init_mini_map_system(var);
}

void    move_player_right(t_var *var)
{
    calcul_right_movement(var);
    init_mini_map(var);
    cast(var);
    init_mini_map_system(var);
}

void    move_player_left(t_var *var)
{
    calcul_left_movement(var);
    init_mini_map(var);
    cast(var);
    init_mini_map_system(var);
}
