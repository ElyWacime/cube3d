#include "cube.h"

void    color_player(t_var *var, int color)
{
    t_uint i;
    t_uint j;

    i = var->player_position[1];
    while (i < var->player_position[1] + 32 && i < var->mini_height)
    {
        j = var->player_position[0];
        while (j < var->player_position[0] + 32 && j < var->mini_width)
        {
            if (i >= (var->player_position[1]) && i < var->player_position[1] + 32 / 16
                && j >= var->player_position[0] && j < var->player_position[0] + 32 / 16)
                mlx_put_pixel(var->mini_map, j, i, color);
            j++;
        }
        i++;
    }
    var->player.position[0] = var->player_position[0];
    var->player.position[1] = var->player_position[1];
    var->player.direction = var->player_direction;
}

void    listen_to_key(struct mlx_key_data keydata, void *ptr)
{
    t_var *var;
    

    var = (t_var *)ptr;
    if (keydata.key == MLX_KEY_LEFT
        && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
        rotate_player_left(var);
    else if (keydata.key == MLX_KEY_RIGHT
        && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
        rotate_player_right(var);
	if (keydata.key == MLX_KEY_W
        && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
        move_player_up(var);
	else if (keydata.key == MLX_KEY_A
        && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		move_player_left(var);
	else if (keydata.key == MLX_KEY_D
        && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		move_player_right(var);
	else if (keydata.key == MLX_KEY_S
        && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		move_player_down(var);
}
