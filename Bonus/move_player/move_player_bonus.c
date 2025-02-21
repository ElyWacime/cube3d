/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:50:49 by skamroun          #+#    #+#             */
/*   Updated: 2025/02/21 16:36:58 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_bonus.h"

void	move_player_down(t_var *var)
{
	calcul_down_movement(var);
	init_img3d(var);
	cast(var);
	init_mini_map_system(var);
	mlx_image_to_window(var->mlx, var->gunprefireimg, (WIDTH / 2)
		- var->gunfire->width, HEIGHT - var->gunfire->height * 2);
	mlx_image_to_window(var->mlx, var->gunfireimg, (WIDTH / 2)
		- var->gunprefire->width, HEIGHT - var->gunprefire->height * 2);
}

void	move_player_up(t_var *var)
{
	calcul_up_movement(var);
	init_img3d(var);
	cast(var);
	init_mini_map_system(var);
	mlx_image_to_window(var->mlx, var->gunprefireimg, (WIDTH / 2)
		- var->gunfire->width, HEIGHT - var->gunfire->height * 2);
	mlx_image_to_window(var->mlx, var->gunfireimg, (WIDTH / 2)
		- var->gunprefire->width, HEIGHT - var->gunprefire->height * 2);
}

void	move_player_right(t_var *var)
{
	calcul_right_movement(var);
	init_img3d(var);
	cast(var);
	init_mini_map_system(var);
	mlx_image_to_window(var->mlx, var->gunprefireimg, (WIDTH / 2)
		- var->gunfire->width, HEIGHT - var->gunfire->height * 2);
	mlx_image_to_window(var->mlx, var->gunfireimg, (WIDTH / 2)
		- var->gunprefire->width, HEIGHT - var->gunprefire->height * 2);
}

void	move_player_left(t_var *var)
{
	calcul_left_movement(var);
	init_img3d(var);
	cast(var);
	init_mini_map_system(var);
	mlx_image_to_window(var->mlx, var->gunprefireimg, (WIDTH / 2)
		- var->gunfire->width, HEIGHT - var->gunfire->height * 2);
	mlx_image_to_window(var->mlx, var->gunfireimg, (WIDTH / 2)
		- var->gunprefire->width, HEIGHT - var->gunprefire->height * 2);
}
