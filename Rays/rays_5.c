#include "../cube.h"

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
	ra_wl->distance_to_projection = HEIGHT / (tan(from_deg_to_rad(VIEW / 2)));
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

void	fill_one_ray_wall_1(t_var *var, t_ray *ray, t_cords *cor,
		t_ray_wall *ra_wl)
{
	if (ray->textures_index == 0 || ray->textures_index == 2)
	{
		ra_wl->ofssetx = ((((CUBE_SIZE * ray->textures_index)
						- my_fmod(cor->colision_v.y, CUBE_SIZE))
					* var->west->width)) / CUBE_SIZE;
		if (ra_wl->correct_a > 0)
			ra_wl->image_offset = (ra_wl->correct_a * var->west->height)
				/ (ra_wl->wall_proj_h);
	}
	else if (ray->textures_index == 1)
	{
		ra_wl->ofssetx = (((my_fmod(cor->colision_h.x, CUBE_SIZE))
					* var->north->width)) / CUBE_SIZE;
		if (ra_wl->correct_a > 0)
			ra_wl->image_offset = (ra_wl->correct_a
					/ (ra_wl->wall_proj_h)) * var->north->width;
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

void	fill_one_ray_wall_2(t_var *var, t_ray *ray, t_cords *cor,
		t_ray_wall *ra_wl)
{
	if (ray->textures_index == 0 || ray->textures_index == 2)
	{
		ra_wl->ofssetx = ((((CUBE_SIZE * ray->textures_index)
						- my_fmod(cor->colision_v.y, CUBE_SIZE))
					* var->door->width)) / CUBE_SIZE;
		if (ra_wl->correct_a > 0)
			ra_wl->image_offset = (ra_wl->correct_a * var->door->height)
				/ (ra_wl->wall_proj_h);
	}
	else if (ray->textures_index == 1)
	{
		ra_wl->ofssetx = (((my_fmod(cor->colision_h.x, CUBE_SIZE))
					* var->door->width)) / CUBE_SIZE;
		if (ra_wl->correct_a > 0)
			ra_wl->image_offset = (ra_wl->correct_a
					/ (ra_wl->wall_proj_h)) * var->door->width;
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

void	while_check(t_var *var, t_ray *ray, t_ray_wall *ra_wl)
{
	if (ra_wl->idx < 100 && ra_wl->idy < 100)
		++(ra_wl->idy);
	else
	{
		if (ray->wall_or_door != DOOR)
		{
			if (ray->textures_index == 0)
				mlx_put_pixel(var->img_3d, ra_wl->idx, ra_wl->idy,
					east_textures(var, ra_wl, ra_wl->ofssetx));
			else if (ray->textures_index == 1)
				mlx_put_pixel(var->img_3d, ra_wl->idx, ra_wl->idy,
					north_textures(var, ra_wl, ra_wl->ofssetx));
			else if (ray->textures_index == 2)
				mlx_put_pixel(var->img_3d, ra_wl->idx, ra_wl->idy,
					west_textures(var, ra_wl, ra_wl->ofssetx));
			else if (ray->textures_index == 3)
				mlx_put_pixel(var->img_3d, ra_wl->idx, ra_wl->idy,
					south_textures(var, ra_wl, ra_wl->ofssetx));
		}
		else
			mlx_put_pixel(var->img_3d, ra_wl->idx, ra_wl->idy,
				door_textures_v(var, ra_wl, ra_wl->ofssetx));
	}
}

void	one_ray_wall(t_var *var, t_ray *ray)
{
	t_cords		cor;
	t_ray_wall	ra_wl;

	fill_one_ray_wall_0(var, ray, &cor, &ra_wl);
	if (var->img_3d)
	{
		ra_wl.idx = var->x_3d;
		ra_wl.idy = ra_wl.a;
		if (ray->wall_or_door != DOOR)
			fill_one_ray_wall_1(var, ray, &cor, &ra_wl);
		else
			fill_one_ray_wall_2(var, ray, &cor, &ra_wl);
		while (ra_wl.idy < HEIGHT - ra_wl.a)
		{
			if (0 <= ra_wl.idx && ra_wl.idx < WIDTH && 0 <= ra_wl.idy
				&& ra_wl.idy < HEIGHT)
				while_check(var, ray, &ra_wl);
			else
				break ;
			++(ra_wl.idy);
		}
		++var->x_3d;
	}
}
