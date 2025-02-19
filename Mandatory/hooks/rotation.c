/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:50:01 by skamroun          #+#    #+#             */
/*   Updated: 2025/02/19 20:28:49 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	calcul_right_rotation(t_var *var)
{
	double	x;
	double	y;

	x = var->player.vect[0] - var->player.position.x;
	y = var->player.vect[1] - var->player.position.y;
	var->player.vect[0] = (x * cos(from_deg_to_rad(6)) - y
			* sin(from_deg_to_rad(6))) + var->player.position.x;
	var->player.vect[1] = (x * sin(from_deg_to_rad(6)) + y
			* cos(from_deg_to_rad(6))) + var->player.position.y;
}

void	calcul_left_rotation(t_var *var)
{
	double	x;
	double	y;

	x = var->player.vect[0] - var->player.position.x;
	y = var->player.vect[1] - var->player.position.y;
	var->player.vect[0] = (x * cos(from_deg_to_rad(360 - 6)) - y
			* sin(from_deg_to_rad(360 - 6))) + var->player.position.x;
	var->player.vect[1] = (x * sin(from_deg_to_rad(360 - 6)) + y
			* cos(from_deg_to_rad(360 - 6))) + var->player.position.y;
}

void	rotate_player_right(t_var *var)
{
	calcul_right_rotation(var);
	var->player.angle = my_fmod((var->player.angle + (360 - 6)), 360);
	init_img3d(var);
	cast(var);
}

void	rotate_player_left(t_var *var)
{
	calcul_left_rotation(var);
	var->player.angle = my_fmod(var->player.angle + 6, 360);
	init_img3d(var);
	cast(var);
}
