/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_5_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:56:51 by skamroun          #+#    #+#             */
/*   Updated: 2025/02/21 16:36:58 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_bonus.h"

void	fill_one_ray_wall_0(t_var *var, t_ray *ray, t_cords *cor,
		t_ray_wall *ra_wl)
{
	set_direciton(ray);
	cor->line.ax = ray->start.x;
	cor->line.ay = ray->start.y;
	cor->line.bx = ray->target.x;
	cor->line.by = ray->target.y;
	ray->direction.x = ray->direction_x;
	ray->direction.y = ray->direction_y;
	ra_wl->distance_to_projection = (WIDTH 
			/ (2 * tan(from_deg_to_rad(VIEW / 2))));
	cast_v_h(var, ray, cor);
	cor->h = sqrt(cor->h);
	ra_wl->distance_correction = cor->h;
	ra_wl->distance_correction *= cos(from_deg_to_rad(ray->angle
				- var->player.angle));
	ra_wl->wall_proj_h = (ra_wl->distance_to_projection * CUBE_SIZE)
		/ (ra_wl->distance_correction);
	ra_wl->a = ((HEIGHT - ra_wl->wall_proj_h) / 2);
	ra_wl->correct_a = -ra_wl->a * (ra_wl->a <= 0);
	ra_wl->a *= (ra_wl->a > 0);
}

void	fill_one_ray_wall_1_0(t_var *var, t_ray *ray, t_cords *cor,
		t_ray_wall *ra_wl)
{
	if (ray->textures_index == 0)
	{
		ra_wl->ofssetx = (((my_fmod(cor->colision_v.y, CUBE_SIZE))
					* var->east->width)) / CUBE_SIZE;
		if (ra_wl->correct_a > 0)
			ra_wl->image_offset = (ra_wl->correct_a * var->east->width)
				/ (ra_wl->wall_proj_h);
	}
	else if (ray->textures_index == 2)
	{
		ra_wl->ofssetx = (((CUBE_SIZE - my_fmod(cor->colision_v.y, CUBE_SIZE))
					* var->west->width)) / CUBE_SIZE;
		if (ra_wl->correct_a > 0)
			ra_wl->image_offset = (ra_wl->correct_a * var->west->height)
				/ (ra_wl->wall_proj_h);
	}
}

void	fill_one_ray_wall_1_1(t_var *var, t_ray *ray, t_cords *cor,
		t_ray_wall *ra_wl)
{
	if (ray->textures_index == 1)
	{
		ra_wl->ofssetx = (((my_fmod(cor->colision_h.x, CUBE_SIZE))
					* var->north->width)) / CUBE_SIZE;
		if (ra_wl->correct_a > 0)
			ra_wl->image_offset = (ra_wl->correct_a * var->north->height)
				/ (ra_wl->wall_proj_h);
	}
	else if (ray->textures_index == 3)
	{
		ra_wl->ofssetx = (((CUBE_SIZE - my_fmod(cor->colision_h.x, CUBE_SIZE))
					* var->south->width)) / CUBE_SIZE;
		if (ra_wl->correct_a > 0)
			ra_wl->image_offset = (ra_wl->correct_a * var->south->height)
				/ (ra_wl->wall_proj_h);
	}
}

void	fill_one_ray_wall_1(t_var *var, t_ray *ray, t_cords *cor,
		t_ray_wall *ra_wl)
{
	if (ray->textures_index == 0 || (ray->textures_index == 2))
		fill_one_ray_wall_1_0(var, ray, cor, ra_wl);
	else if (ray->textures_index == 1 || (ray->textures_index == 3))
		fill_one_ray_wall_1_1(var, ray, cor, ra_wl);
}
