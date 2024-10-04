#include "cube.h"

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
