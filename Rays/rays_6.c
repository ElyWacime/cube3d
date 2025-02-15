/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:56:58 by skamroun          #+#    #+#             */
/*   Updated: 2025/02/15 18:31:41 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	check_if_wall_h(t_point start, t_point direction, t_var *var)
{
	int	row;
	int	col;

	row = px_to_map_grid((t_uint)start.y) - (direction.y == -1);
	col = px_to_map_grid((t_uint)start.x);
	if (!(0 <= row && row < str_double_len(var->map) && 0 <= col
			&& col < (float)ft_strlen(var->map[row])))
		return (1);
	if (col * SQUARE_SIZE == start.x)
	{
		if (var->map[row][col] == 'P' || var->map[row][col - 1] == 'P')
			return (DOOR);
		return (var->map[row][col] == '1' || var->map[row][col] == '\0'
			|| ft_isspace(var->map[row][col]) || var->map[row][col - 1] == '1'
			|| var->map[row][col - 1] == '\0' || ft_isspace(var->map[row][col
				- 1]));
	}
	if (var->map[row][col] == 'P')
		return (DOOR);
	return (var->map[row][col] == '1' || var->map[row][col] == '\0'
		|| ft_isspace(var->map[row][col]));
}

int	check_if_wall_v(t_point start, t_point direction, t_var *var)
{
	int	row;
	int	col;

	row = px_to_map_grid((t_uint)start.y);
	col = px_to_map_grid((t_uint)start.x) - (direction.x == -1);
	if (!(0 <= row && row < str_double_len(var->map) && 0 <= col
			&& col < (float)ft_strlen(var->map[row])))
		return (1);
	if (row * SQUARE_SIZE == start.y)
	{
		if (var->map[row][col] == 'P' || var->map[row - 1][col] == 'P')
			return (DOOR);
		return (var->map[row][col] == '1' || var->map[row][col] == '\0'
			|| ft_isspace(var->map[row][col]) || var->map[row - 1][col] == '1'
			|| var->map[row - 1][col] == '\0' || ft_isspace(var->map[row
				- 1][col]));
	}
	if (var->map[row][col] == 'P')
		return (DOOR);
	return (var->map[row][col] == '1' || var->map[row][col] == '\0'
		|| ft_isspace(var->map[row][col]));
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
