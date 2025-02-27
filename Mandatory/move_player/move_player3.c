/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:50:55 by skamroun          #+#    #+#             */
/*   Updated: 2025/02/19 21:33:59 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	check_if_wall_up_movement_1(t_var *var, t_point new_position)
{
	if (var->player.angle >= 180 && var->player.angle < 270)
	{
		if (var->map[px_to_map_grid(new_position.y)]
			[px_to_map_grid(new_position.x - 1)] != '1')
			return (1);
	}
	else if (var->player.angle >= 270 && var->player.angle < 360)
	{
		if (var->map[px_to_map_grid(new_position.y
					+ 1)][px_to_map_grid(new_position.x)] != '1')
			return (1);
	}
	return (0);
}

int	check_if_wall_up_movement(t_var *var, t_point new_position)
{
	// if (var->map[px_to_map_grid(new_position.x)][px_to_map_grid(new_position.y)] == ' ')
	// 	return (0);
	if (var->player.angle >= 0 && var->player.angle < 90)
	{
		if (var->map[px_to_map_grid(new_position.y)]
			[px_to_map_grid(new_position.x + 1)] != '1')
			return (1);
	}
	else if (var->player.angle >= 90 && var->player.angle < 180)
	{
		if (var->map[px_to_map_grid(new_position.y
					- 1)][px_to_map_grid(new_position.x)] != '1')
			return (1);
	}
	if (check_if_wall_up_movement_1(var, new_position))
		return (1);
	return (0);
}

int	check_if_wall_down_movement_1(t_var *var, t_point new_position)
{

	if (var->player.angle >= 180 && var->player.angle < 270)
	{
		if (var->map[px_to_map_grid(new_position.y)]
			[px_to_map_grid(new_position.x + 1)] != '1')
			return (1);
	}
	else if (var->player.angle >= 270 && var->player.angle < 360)
	{
		if (var->map[px_to_map_grid(new_position.y
					- 1)][px_to_map_grid(new_position.x)] != '1')
			return (1);
	}
	return (0);
}

int	check_if_wall_down_movement(t_var *var, t_point new_position)
{
	// if (var->map[px_to_map_grid(new_position.x)][px_to_map_grid(new_position.y)] == ' ')
	// 	return (0);
	if (var->player.angle >= 0 && var->player.angle < 90)
	{
		if (var->map[px_to_map_grid(new_position.y)]
			[px_to_map_grid(new_position.x - 1)] != '1')
			return (1);
	}
	else if (var->player.angle >= 90 && var->player.angle < 180)
	{
		if (var->map[px_to_map_grid(new_position.y
					+ 1)][px_to_map_grid(new_position.x)] != '1')
			return (1);
	}
	if (check_if_wall_down_movement_1(var, new_position))
		return (1);
	return (0);
}
