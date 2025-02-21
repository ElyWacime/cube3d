/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:49:38 by skamroun          #+#    #+#             */
/*   Updated: 2025/02/21 16:36:58 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_bonus.h"

void	sub_listen_to_key(struct mlx_key_data keydata, t_var *var)
{
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_player_up(var);
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_player_left(var);
	else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_player_right(var);
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_player_down(var);
	else if (keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS)
		close_door(var);
	else if (keydata.key == MLX_KEY_O && keydata.action == MLX_PRESS)
		open_door(var);
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		quit_program(var);
}

void	listen_to_key(struct mlx_key_data keydata, void *ptr)
{
	t_var	*var;

	var = (t_var *)ptr;
	if (keydata.key == MLX_KEY_SPACE && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
	{
		var->gunfireimg->enabled = true;
		var->gunprefireimg->enabled = false;
	}
	else if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_RELEASE)
	{
		var->gunfireimg->enabled = false;
		var->gunprefireimg->enabled = true;
	}
	else if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		rotate_player_left(var);
	else if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		rotate_player_right(var);
	else
		sub_listen_to_key(keydata, var);
}

void	shoot(struct mlx_key_data keydata, void *ptr)
{
	t_var	*var;

	var = (t_var *)ptr;
	if (keydata.key == MLX_KEY_SPACE && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
		var->gunfireimg->enabled = true;
	if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_RELEASE)
		var->gunfireimg->enabled = false;
}
