/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:50:49 by skamroun          #+#    #+#             */
/*   Updated: 2025/02/15 17:50:50 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void    move_player_down(t_var *var)
{
    calcul_down_movement(var);
    init_img3d(var);
    cast(var);
    init_mini_map_system(var);
    mlx_image_to_window(var->mlx, var->gunPreFireImg, (WIDTH / 2) - var->gunFire->width, HEIGHT - var->gunFire->height * 2);
    mlx_image_to_window(var->mlx, var->gunFireImg, (WIDTH / 2) - var->gunPreFire->width, HEIGHT - var->gunPreFire->height * 2);
}

void    move_player_up(t_var *var)
{
    calcul_up_movement(var);
    init_img3d(var);
    cast(var);
    init_mini_map_system(var);
    mlx_image_to_window(var->mlx, var->gunPreFireImg, (WIDTH / 2) - var->gunFire->width, HEIGHT - var->gunFire->height * 2);
    mlx_image_to_window(var->mlx, var->gunFireImg, (WIDTH / 2) - var->gunPreFire->width, HEIGHT - var->gunPreFire->height * 2);
}

void    move_player_right(t_var *var)
{
    calcul_right_movement(var);
    init_img3d(var);
    cast(var);
    init_mini_map_system(var);
    mlx_image_to_window(var->mlx, var->gunPreFireImg, (WIDTH / 2) - var->gunFire->width, HEIGHT - var->gunFire->height * 2);
    mlx_image_to_window(var->mlx, var->gunFireImg, (WIDTH / 2) - var->gunPreFire->width, HEIGHT - var->gunPreFire->height * 2);
}

void    move_player_left(t_var *var)
{
    calcul_left_movement(var);
    init_img3d(var);
    cast(var);
    init_mini_map_system(var);
    mlx_image_to_window(var->mlx, var->gunPreFireImg, (WIDTH / 2) - var->gunFire->width, HEIGHT - var->gunFire->height * 2);
    mlx_image_to_window(var->mlx, var->gunFireImg, (WIDTH / 2) - var->gunPreFire->width, HEIGHT - var->gunPreFire->height * 2);

}
