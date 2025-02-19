/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:50:52 by skamroun          #+#    #+#             */
/*   Updated: 2025/02/15 17:50:53 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	calcul_right_movement(t_var *var)
{
	t_point	new_position;
	int		cnt;

	cnt = -1;
	while (cnt++ <= 1)
	{
		new_position.x = (var->player.position.x + cnt) + (SPEED
				* sin(from_deg_to_rad(var->player.angle)));
		new_position.y = (var->player.position.y + cnt) + (SPEED
				* cos(from_deg_to_rad(var->player.angle)));
		if (!check_if_wall_right_movement(var, new_position))
			return ;
	}
	new_position.x = (var->player.position.x) + (SPEED
			* sin(from_deg_to_rad(var->player.angle)));
	new_position.y = (var->player.position.y) + (SPEED
			* cos(from_deg_to_rad(var->player.angle)));
	var->player.position.x = new_position.x;
	var->player.position.y = new_position.y;
}

void	calcul_left_movement(t_var *var)
{
	t_point	new_position;
	int		cnt;

	cnt = -1;
	while (cnt++ <= 1)
	{
		new_position.x = (var->player.position.x + cnt) - (SPEED
				* sin(from_deg_to_rad(var->player.angle)));
		new_position.y = (var->player.position.y + cnt) - (SPEED
				* cos(from_deg_to_rad(var->player.angle)));
		if (!check_if_wall_left_movement(var, new_position))
			return ;
	}
	new_position.x = (var->player.position.x) - (SPEED
			* sin(from_deg_to_rad(var->player.angle)));
	new_position.y = (var->player.position.y) - (SPEED
			* cos(from_deg_to_rad(var->player.angle)));
	if (new_position.y <= 0 || new_position.x <= 0)
		return ;
	var->player.position.x = new_position.x;
	var->player.position.y = new_position.y;
}

void	calcul_up_movement(t_var *var)
{
	t_point	new_position;
	int		cnt;

	cnt = -1;
	while (cnt++ <= 1)
	{
		new_position.x = (var->player.position.x + cnt) + (SPEED
				* cos(from_deg_to_rad(var->player.angle)));
		new_position.y = (var->player.position.y + cnt) - (SPEED
				* sin(from_deg_to_rad(var->player.angle)));
		if (new_position.y <= 0)
			return ;
		if (!check_if_wall_up_movement(var, new_position))
			return ;
	}
	new_position.x = (var->player.position.x) + (SPEED
			* cos(from_deg_to_rad(var->player.angle)));
	new_position.y = (var->player.position.y) - (SPEED
			* sin(from_deg_to_rad(var->player.angle)));
	if (new_position.y <= 0)
		return ;
	var->player.position.x = new_position.x;
	var->player.position.y = new_position.y;
}

void	calcul_down_movement(t_var *var)
{
	t_point	new_position;
	int		cnt;

	cnt = -1;
	while (cnt++ <= 1)
	{
		new_position.x = (var->player.position.x + cnt) - (SPEED
				* cos(from_deg_to_rad(var->player.angle)));
		new_position.y = (var->player.position.y + cnt) + (SPEED
				* sin(from_deg_to_rad(var->player.angle)));
		if (new_position.x <= 0)
			return ;
		if (!check_if_wall_down_movement(var, new_position))
			return ;
	}
	new_position.x = (var->player.position.x) - (SPEED
			* cos(from_deg_to_rad(var->player.angle)));
	new_position.y = (var->player.position.y) + (SPEED
			* sin(from_deg_to_rad(var->player.angle)));
	if (new_position.x <= 0)
		return ;
	var->player.position.x = new_position.x;
	var->player.position.y = new_position.y;
}
