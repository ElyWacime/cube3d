/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_textures_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:51:14 by skamroun          #+#    #+#             */
/*   Updated: 2025/02/21 16:36:58 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_bonus.h"

uint32_t	get_gun_color_at_current_pixel(t_var *var, int x, int y)
{
	t_uint	r;
	t_uint	g;
	t_uint	b;
	t_uint	o;
	t_uint	color;

	if ((y * var->gunprefire->width + x) >= var->gunprefire->height
		* var->gunprefire->width * 4)
		return (0xFFFFFF00);
	r = (var->gunprefire->pixels[((y * var->gunprefire->width + x) + 0)]) << 24;
	g = (var->gunprefire->pixels[((y * var->gunprefire->width + x) + 1)]) << 16;
	b = (var->gunprefire->pixels[((y * var->gunprefire->width + x) + 2)]) << 8;
	o = (var->gunprefire->pixels[((y * var->gunprefire->width + x) + 3)]);
	color = r | g | b | o;
	if (color == 0x6070DFFF)
		return (0x00000000);
	return (color);
}

void	draw_gun(t_var *var)
{
	int	xstart;
	int	ystart;

	xstart = (WIDTH / 2) - (var->gunprefire->width);
	ystart = HEIGHT - var->gunprefire->height * 2;
	var->gunfireimg = mlx_texture_to_image(var->mlx, var->gunfire);
	var->gunprefireimg = mlx_texture_to_image(var->mlx, var->gunprefire);
	var->gunprefireimg->enabled = true;
	var->gunfireimg->enabled = false;
	mlx_resize_image(var->gunprefireimg, var->gunprefire->width * 2,
		var->gunprefire->height * 2);
	mlx_resize_image(var->gunfireimg, var->gunfire->width * 2,
		var->gunfire->height * 2);
	mlx_image_to_window(var->mlx, var->gunprefireimg, xstart, ystart);
	mlx_image_to_window(var->mlx, var->gunfireimg, xstart, ystart);
}
