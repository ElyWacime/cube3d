/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:31:36 by skamroun          #+#    #+#             */
/*   Updated: 2025/02/15 19:42:36 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	fill_one_ray_wall_2_0(t_var *var, t_ray *ray, t_cords *cor,
		t_ray_wall *ra_wl)
{
	if (ray->textures_index == 0)
	{
		ra_wl->ofssetx = (((my_fmod(cor->colision_v.y, CUBE_SIZE))
					* var->door->width)) / CUBE_SIZE;
		if (ra_wl->correct_a > 0)
			ra_wl->image_offset = (ra_wl->correct_a
					* var->door->width) / (ra_wl->wall_proj_h);
	}
	else if (ray->textures_index == 1)
	{
		ra_wl->ofssetx = (((my_fmod(cor->colision_h.x, CUBE_SIZE))
					* var->door->width)) / CUBE_SIZE;
		if (ra_wl->correct_a > 0)
			ra_wl->image_offset = (ra_wl->correct_a
					* var->door->width) / (ra_wl->wall_proj_h);
	}
}

void	fill_one_ray_wall_2_1(t_var *var, t_ray *ray, t_cords *cor,
		t_ray_wall *ra_wl)
{
	if (ray->textures_index == 2)
	{
		ra_wl->ofssetx = (((CUBE_SIZE - my_fmod(cor->colision_v.y, CUBE_SIZE))
					* var->door->width)) / CUBE_SIZE;
		if (ra_wl->correct_a > 0)
			ra_wl->image_offset = (ra_wl->correct_a
					* var->door->height) / (ra_wl->wall_proj_h);
	}
	else if (ray->textures_index == 3)
	{
		ra_wl->ofssetx = (((CUBE_SIZE - my_fmod(cor->colision_h.x, CUBE_SIZE))
					* var->door->width)) / CUBE_SIZE;
		if (ra_wl->correct_a > 0)
			ra_wl->image_offset = (ra_wl->correct_a * var->door->height)
				/ (ra_wl->wall_proj_h);
	}
}

void	fill_one_ray_wall_2(t_var *var, t_ray *ray, t_cords *cor,
		t_ray_wall *ra_wl)
{
	if (ray->textures_index == 0 || (ray->textures_index == 1))
		fill_one_ray_wall_2_0(var, ray, cor, ra_wl);
	else if (ray->textures_index == 2 || (ray->textures_index == 3))
		fill_one_ray_wall_2_1(var, ray, cor, ra_wl);
}
