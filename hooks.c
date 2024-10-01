#include "cube.h"

void    color_player_movement(t_uint *tracker, t_var *var, int color)
{
    t_uint i;
    t_uint j;

    i = tracker[1];
    while (i <= tracker[1] + 32 && i < var->mini_height)
    {
        j = tracker[0];
        while (j <= tracker[0] + 32 && j < var->mini_width)
        {
            if (i >= (tracker[1]) && i < tracker[1] + 32 / 8
                && j >= tracker[0] && j < tracker[0] + 32 / 8)
                mlx_put_pixel(var->mini_map, j, i, color);
            j++;
        }
        i++;
    }
}

int check_if_player_hits_wall(t_var *var)
{
    int x_positon;
    int y_position;

    x_positon = px_to_map_grid(var->player_position[0]);
    y_position = px_to_map_grid(var->player_position[1]);
    return (var->map[y_position][x_positon] == '1');
}

void    move_player_up(t_var *var)
{
    color_player_movement(var->player_position, var, 0xFF00FFFF);
    var->player_position[1] -= 4;
    if (check_if_player_hits_wall(var))
    {
        var->player_position[1] += 4;
        color_player_movement(var->player_position, var, 0x000000FF);
        return ;
    }
    color_player_movement(var->player_position, var, 0x000000FF);
}

void    move_player_down(t_var *var)
{
    color_player_movement(var->player_position, var, 0xFF00FFFF);
    var->player_position[1] += 4;
    if (check_if_player_hits_wall(var))
    {
        var->player_position[1] -= 4;
        color_player_movement(var->player_position, var, 0x000000FF);
        return ;
    }
    color_player_movement(var->player_position, var, 0x000000FF);
}

void    move_player_left(t_var *var)
{
    color_player_movement(var->player_position, var, 0xFF00FFFF);
    var->player_position[0] -= 4;
    if (check_if_player_hits_wall(var))
    {
        var->player_position[0] += 4;
        color_player_movement(var->player_position, var, 0x000000FF);
        return ;
    }
    color_player_movement(var->player_position, var, 0x000000FF);
}

void    move_player_right(t_var *var)
{
    color_player_movement(var->player_position, var, 0xFF00FFFF);
    var->player_position[0] += 4;
    if (check_if_player_hits_wall(var))
    {
        var->player_position[0] -= 4;
        color_player_movement(var->player_position, var, 0x000000FF);
        return ;
    }
    color_player_movement(var->player_position, var, 0x000000FF);
}

void    listen_to_key(struct mlx_key_data keydata, void *ptr)
{
    t_var *var;
    
    var = (t_var *)ptr;
	if (keydata.key == MLX_KEY_UP
        && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
            move_player_up(var);
	else if (keydata.key == MLX_KEY_LEFT
        && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		move_player_left(var);
	else if (keydata.key == MLX_KEY_RIGHT
        && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		move_player_right(var);
	else if (keydata.key == MLX_KEY_DOWN
        && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		move_player_down(var);
}
