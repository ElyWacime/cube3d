/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:51:14 by skamroun          #+#    #+#             */
/*   Updated: 2025/02/15 19:58:44 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

uint32_t	get_gun_color_at_current_pixel(t_var *var, int x, int y)
{
	t_uint	r;
	t_uint	g;
	t_uint	b;
	t_uint	o;
	t_uint	color;

	if ((y * var->gunPreFire->width + x) >= var->gunPreFire->height
		* var->gunPreFire->width * 4)
		return (0xFFFFFF00);
	r = (var->gunPreFire->pixels[((y * var->gunPreFire->width + x) + 0)]) << 24;
	g = (var->gunPreFire->pixels[((y * var->gunPreFire->width + x) + 1)]) << 16;
	b = (var->gunPreFire->pixels[((y * var->gunPreFire->width + x) + 2)]) << 8;
	o = (var->gunPreFire->pixels[((y * var->gunPreFire->width + x) + 3)]);
	color = r | g | b | o;
	if (color == 0x6070DFFF)
		return (0x00000000);
	return (color);
}

void	draw_gun(t_var *var)
{
	int	xstart;
	int	ystart;

	xstart = (WIDTH / 2) - (var->gunPreFire->width);
	ystart = HEIGHT - var->gunPreFire->height * 2;
	var->gunFireImg = mlx_texture_to_image(var->mlx, var->gunFire);
	var->gunPreFireImg = mlx_texture_to_image(var->mlx, var->gunPreFire);
	var->gunPreFireImg->enabled = true;
	var->gunFireImg->enabled = false;
	mlx_resize_image(var->gunPreFireImg, var->gunPreFire->width * 2,
		var->gunPreFire->height * 2);
	mlx_resize_image(var->gunFireImg, var->gunFire->width * 2,
		var->gunFire->height * 2);
	mlx_image_to_window(var->mlx, var->gunPreFireImg, xstart, ystart);
	mlx_image_to_window(var->mlx, var->gunFireImg, xstart, ystart);
}
