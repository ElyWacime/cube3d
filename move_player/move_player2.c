#include "../cube.h"

int check_if_wall_up_movement(t_var *var, t_point new_position)
{
    if (var->player.angle >= 0 && var->player.angle < 90)
    {
        if (var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x + 1)] != '1'
            && var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x + 1)] != 'P')
            return 1;
    }
    else if (var->player.angle >= 90 && var->player.angle < 180)
    {
        if (var->map[px_to_map_grid(new_position.y - 1)][px_to_map_grid(new_position.x)] != '1'
            && var->map[px_to_map_grid(new_position.y - 1)][px_to_map_grid(new_position.x)] != 'P')
            return 1;
    }
    else if (var->player.angle >= 180 && var->player.angle < 270)
    {
        if (var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x - 1)] != '1'
            && var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x - 1)] != 'P')
            return 1;
    }
    else if (var->player.angle >= 270 && var->player.angle < 360)
    {
        if (var->map[px_to_map_grid(new_position.y + 1)][px_to_map_grid(new_position.x)] != '1'
            && var->map[px_to_map_grid(new_position.y + 1)][px_to_map_grid(new_position.x)] != 'P')
            return 1;
    }
    return 0;
}

int check_if_wall_down_movement(t_var *var, t_point new_position)
{
    if (var->player.angle >= 0 && var->player.angle < 90)
    {
        if (var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x - 1)] != '1'
            && var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x - 1)] != 'P')
            return 1;
    }
    else if (var->player.angle >= 90 && var->player.angle < 180)
    {
        if (var->map[px_to_map_grid(new_position.y + 1)][px_to_map_grid(new_position.x)] != '1'
            && var->map[px_to_map_grid(new_position.y + 1)][px_to_map_grid(new_position.x)] != 'P')
            return 1;
    }
    else if (var->player.angle >= 180 && var->player.angle < 270)
    {
        if (var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x + 1)] != '1'
            && var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x + 1)] != 'P')
            return 1;
    }
    else if (var->player.angle >= 270 && var->player.angle < 360)
    {
        if (var->map[px_to_map_grid(new_position.y - 1)][px_to_map_grid(new_position.x)] != '1'
            && var->map[px_to_map_grid(new_position.y - 1)][px_to_map_grid(new_position.x)] != 'P')
            return 1;
    }
    return 0;
}

int check_if_wall_left_movement(t_var *var, t_point new_position)
{
    if (var->player.angle >= 0 && var->player.angle < 90)
    {
        if (var->map[px_to_map_grid(new_position.y - 1)][px_to_map_grid(new_position.x)] != '1'
            && var->map[px_to_map_grid(new_position.y - 1)][px_to_map_grid(new_position.x)] != 'P')
            return 1;
    }
    else if (var->player.angle >= 90 && var->player.angle < 180)
    {
        if (var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x - 1)] != '1'
            && var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x - 1)] != 'P')
            return 1;
    }
    else if (var->player.angle >= 180 && var->player.angle < 270)
    {
        if (var->map[px_to_map_grid(new_position.y + 1)][px_to_map_grid(new_position.x)] != '1'
            && var->map[px_to_map_grid(new_position.y + 1)][px_to_map_grid(new_position.x)] != 'P')
            return 1;
    }
    else if (var->player.angle >= 270 && var->player.angle < 360)
    {
        if (var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x + 1)] != '1'
            && var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x + 1)] != 'P')
            return 1;
    }
    return 0;
}

int check_if_wall_right_movement(t_var *var, t_point new_position)
{
    if (var->player.angle >= 0 && var->player.angle < 90)
    {
        if (var->map[px_to_map_grid(new_position.y + 1)][px_to_map_grid(new_position.x)] != '1'
            && var->map[px_to_map_grid(new_position.y + 1)][px_to_map_grid(new_position.x)] != 'P')
            return 1;
    }
    else if (var->player.angle >= 90 && var->player.angle < 180)
    {
        if (var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x + 1)] != '1'
            && var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x + 1)] != 'P')
            return 1;
    }
    else if (var->player.angle >= 180 && var->player.angle < 270)
    {
        if (var->map[px_to_map_grid(new_position.y - 1)][px_to_map_grid(new_position.x)] != '1'
            && var->map[px_to_map_grid(new_position.y - 1)][px_to_map_grid(new_position.x)] != 'P')
            return 1;
    }
    else if (var->player.angle >= 270 && var->player.angle < 360)
    {
        if (var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x - 1)] != '1'
            && var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x - 1)] != 'P')
            return 1;
    }
    return 0;
}
