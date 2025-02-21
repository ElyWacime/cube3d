/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:56:45 by skamroun          #+#    #+#             */
/*   Updated: 2025/02/19 18:52:25 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	fill_cast_vertical(t_ray *ray, t_cast_v *cst_v)
{
	cst_v->colison.x = ray->start.x;
	cst_v->colison.y = ray->start.y;
	ray->wall_or_door_v = 0;
	cst_v->tn = tan_0_90(ray->angle);
	if (ray->direction_y == -1)
	{
		cst_v->colison.x = next_px_in_grid(ray->start.x, ray->direction_x);
		cst_v->colison.y = ray->start.y - (fabs(cst_v->colison.x - ray->start.x)
				* cst_v->tn);
		cst_v->skip_x = SQUARE_SIZE * ray->direction_x;
		cst_v->skip_y = -SQUARE_SIZE * cst_v->tn;
	}
	else
	{
		cst_v->colison.x = next_px_in_grid(ray->start.x, ray->direction_x);
		cst_v->colison.y = ray->start.y + ((ray->direction_y
					* fabs(cst_v->colison.x - ray->start.x)) / cst_v->tn);
		cst_v->skip_x = SQUARE_SIZE * ray->direction_x;
		cst_v->skip_y = SQUARE_SIZE / cst_v->tn;
	}
}

t_point	cast_vertical(t_var *var, t_ray *ray)
{
	t_cast_v	cst_v;

	fill_cast_vertical(ray, &cst_v);
	while (((0 <= cst_v.colison.x && 0 <= cst_v.colison.y)
			&& ((cst_v.colison.x < WIDTH && cst_v.colison.y < HEIGHT)
				|| (cst_v.colison.x < var->mini_width
					&& cst_v.colison.y < var->mini_height))))
	{
		if (check_if_wall_v(cst_v.colison, ray->direction, var))
		{
			ray->wall_or_door_v = check_if_wall_v(cst_v.colison, ray->direction,
					var);
			return (cst_v.colison);
		}
		cst_v.colison.x += cst_v.skip_x;
		cst_v.colison.y += cst_v.skip_y;
	}
	return (cst_v.colison);
}

void	fill_cast_horizantal(t_ray *ray, t_cast_h *cst_h)
{
	ray->wall_or_door_h = 0;
	cst_h->colison.x = ray->start.x;
	cst_h->colison.y = ray->start.y;
	cst_h->tn = tan_0_90(ray->angle);
	if (ray->direction_y == -1)
	{
		cst_h->horizon.y = ray->start.y;
		cst_h->colison.y = next_px_in_grid(ray->start.y, ray->direction_y);
		cst_h->colison.x = ray->start.x + (ray->direction_x
				* ((fabs(cst_h->horizon.y - cst_h->colison.y) / cst_h->tn)));
		cst_h->horizon.x = cst_h->colison.x;
		cst_h->skip_x = (SQUARE_SIZE / cst_h->tn) * ray->direction_x;
		cst_h->skip_y = SQUARE_SIZE * ray->direction_y;
	}
	else
	{
		cst_h->horizon.y = next_px_in_grid(ray->start.y, ray->direction_y);
		cst_h->colison.y = cst_h->horizon.y;
		cst_h->horizon.x = ray->start.x;
		cst_h->colison.x = ray->start.x + (fabs(ray->start.y - cst_h->horizon.y)
				* cst_h->tn * ray->direction_x);
		cst_h->skip_x = (SQUARE_SIZE * cst_h->tn) * ray->direction_x;
		cst_h->skip_y = SQUARE_SIZE * ray->direction_y;
	}
}

t_point	cast_horizantal(t_var *var, t_ray *ray)
{
	t_cast_h	cst_h;

	fill_cast_horizantal(ray, &cst_h);
	while (((0 <= cst_h.colison.x && 0 <= cst_h.colison.y)
			&& ((cst_h.colison.x < var->mini_width
					&& cst_h.colison.y < var->mini_height))))
	{
		if (check_if_wall_h(cst_h.colison, ray->direction, var))
		{
			ray->wall_or_door_h = check_if_wall_h(cst_h.colison, ray->direction,
					var);
			return (cst_h.colison);
		}
		cst_h.colison.x += cst_h.skip_x;
		cst_h.colison.y += cst_h.skip_y;
	}
	return (cst_h.colison);
}

float	next_px_in_grid(float p, int d)
{
	int	a;

	a = (int)(p / SQUARE_SIZE);
	if (p - (SQUARE_SIZE * a) == 0)
	{
		if (d == 1)
			return ((a + 1) * SQUARE_SIZE);
		else
			return ((a - 1) * SQUARE_SIZE);
	}
	else
	{
		if (d == 1)
			return ((a + 1) * SQUARE_SIZE);
		else
			return (SQUARE_SIZE * a);
	}
}
