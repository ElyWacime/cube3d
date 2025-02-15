/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:51:23 by skamroun          #+#    #+#             */
/*   Updated: 2025/02/15 19:58:56 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

size_t	east_textures(t_var *var, t_ray_wall *ra_wl, int ofsx)
{
	if (ra_wl->correct_a > 0)
		ra_wl->ofssety = (((var->east->height - (2 * ra_wl->image_offset))
					* ra_wl->idy) / HEIGHT) + ra_wl->image_offset;
	else
		ra_wl->ofssety = (((ra_wl->idy - ra_wl->a) * var->east->height))
			/ (HEIGHT - (ra_wl->a << 1));
	ra_wl->pix = ((ra_wl->ofssety * var->east->width) + ofsx) << 2;
	if ((uint32_t)(ra_wl->pix) >= var->east->height * var->east->width * 4)
		return (0xFFFFFF00);
	var->r = (var->east->pixels[ra_wl->pix + 0]) << 24;
	var->g = (var->east->pixels[ra_wl->pix + 1]) << 16;
	var->b = (var->east->pixels[ra_wl->pix + 2]) << 8;
	var->o = var->east->pixels[ra_wl->pix + 3];
	return (var->r | var->g | var->b | var->o);
}

size_t	north_textures(t_var *var, t_ray_wall *ra_wl, int ofsx)
{
	if (ra_wl->correct_a > 0)
		ra_wl->ofssety = (((var->north->height - (2 * ra_wl->image_offset))
					* ra_wl->idy) / HEIGHT) + ra_wl->image_offset;
	else
		ra_wl->ofssety = ((ra_wl->idy - ra_wl->a) * var->north->height)
			/ (HEIGHT - (ra_wl->a << 1));
	ra_wl->pix = ((ra_wl->ofssety * var->north->width) + ofsx) << 2;
	if ((uint32_t)(ra_wl->pix) >= var->north->height * var->north->width * 4)
		return (0xFFFFFF00);
	var->r = (var->north->pixels[ra_wl->pix + 0]) << 24;
	var->g = (var->north->pixels[ra_wl->pix + 1]) << 16;
	var->b = (var->north->pixels[ra_wl->pix + 2]) << 8;
	var->o = var->north->pixels[ra_wl->pix + 3];
	return (var->r | var->g | var->b | var->o);
}

size_t	west_textures(t_var *var, t_ray_wall *ra_wl, int ofsx)
{
	if (ra_wl->correct_a > 0)
		ra_wl->ofssety = (((var->west->height - (2 * ra_wl->image_offset))
					* ra_wl->idy) / HEIGHT) + ra_wl->image_offset;
	else
		ra_wl->ofssety = (((ra_wl->idy - ra_wl->a) * var->west->height))
			/ (HEIGHT - (ra_wl->a << 1));
	ra_wl->pix = ((ra_wl->ofssety * var->west->width) + ofsx) << 2;
	if ((uint32_t)(ra_wl->pix) >= var->west->height * var->west->width * 4)
		return (0xFFFFFF00);
	var->r = (var->west->pixels[ra_wl->pix + 0]) << 24;
	var->g = (var->west->pixels[ra_wl->pix + 1]) << 16;
	var->b = (var->west->pixels[ra_wl->pix + 2]) << 8;
	var->o = var->west->pixels[ra_wl->pix + 3];
	return (var->r | var->g | var->b | var->o);
}

size_t	south_textures(t_var *var, t_ray_wall *ra_wl, int ofsx)
{
	if (ra_wl->correct_a > 0)
		ra_wl->ofssety = (((var->south->height - (2 * ra_wl->image_offset))
					* ra_wl->idy) / HEIGHT) + ra_wl->image_offset;
	else
		ra_wl->ofssety = (((ra_wl->idy - ra_wl->a) * var->south->height))
			/ (HEIGHT - (ra_wl->a << 1));
	ra_wl->pix = ((ra_wl->ofssety * var->south->width) + ofsx) << 2;
	if ((uint32_t)(ra_wl->pix) >= var->south->height * var->south->width * 4)
		return (0xFFFFFF00);
	var->r = (var->south->pixels[ra_wl->pix + 0]) << 24;
	var->g = (var->south->pixels[ra_wl->pix + 1]) << 16;
	var->b = (var->south->pixels[ra_wl->pix + 2]) << 8;
	var->o = var->south->pixels[ra_wl->pix + 3];
	return (var->r | var->g | var->b | var->o);
}
