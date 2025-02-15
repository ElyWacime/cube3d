/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:51:11 by skamroun          #+#    #+#             */
/*   Updated: 2025/02/15 19:51:01 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

size_t	door_textures_v(t_var *var, t_ray_wall *ra_wl, int ofsx)
{
	if (ra_wl->correct_a > 0)
		ra_wl->ofssety = (((var->door->height - (2 * ra_wl->image_offset))
					* ra_wl->idy) / HEIGHT) + ra_wl->image_offset;
	else
		ra_wl->ofssety = (((ra_wl->idy - ra_wl->a) * var->door->height))
			/ (HEIGHT - (ra_wl->a << 1));
	ra_wl->pix = ((ra_wl->ofssety * var->door->width) + ofsx) << 2;
	if ((uint32_t)(ra_wl->pix) >= var->door->height * var->door->width * 4)
		return (0xFFFFFFFF);
	var->r = (var->door->pixels[ra_wl->pix + 0]) << 24;
	var->g = (var->door->pixels[ra_wl->pix + 1]) << 16;
	var->b = (var->door->pixels[ra_wl->pix + 2]) << 8;
	var->o = var->door->pixels[ra_wl->pix + 3];
	return (var->r | var->g | var->b | var->o);
}

size_t	door_textures_h(t_var *var, t_ray_wall *ra_wl, int ofsx)
{
	if (ra_wl->correct_a > 0)
		ra_wl->ofssety = (((var->door->width - (2 * ra_wl->image_offset))
					* ra_wl->idy) / HEIGHT) + ra_wl->image_offset;
	else
		ra_wl->ofssety = ((ra_wl->idy - ra_wl->a) * var->door->width) / (HEIGHT
				- (ra_wl->a << 1));
	ra_wl->pix = ((ra_wl->ofssety * var->door->width) + ofsx) << 2;
	if ((uint32_t)(ra_wl->pix) >= var->door->height * var->door->width * 4)
		return (0xFFFFFFFF);
	var->r = (var->door->pixels[ra_wl->pix + 0]) << 24;
	var->g = (var->door->pixels[ra_wl->pix + 1]) << 16;
	var->b = (var->door->pixels[ra_wl->pix + 2]) << 8;
	var->o = var->door->pixels[ra_wl->pix + 3];
	return (var->r | var->g | var->b | var->o);
}