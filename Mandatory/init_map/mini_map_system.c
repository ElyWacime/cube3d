/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_system.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:51:42 by skamroun          #+#    #+#             */
/*   Updated: 2025/02/21 18:43:09 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	sub_init_mini_map_system_0(t_var *var, t_imm *imm)
{
	if (var->player.position.x - 2 < imm->i
		&& imm->i < var->player.position.x + 2 && var->player.position.y
		- 2 < imm->j && imm->j < var->player.position.y + 2)
		mlx_put_pixel(var->img_3d, imm->map_x, imm->map_y, 0x00FF00FF);
	else if (var->map[px_to_map_grid(imm->j)]
		[px_to_map_grid(imm->i)] != '1'
		&& var->map[px_to_map_grid(imm->j)]
		[px_to_map_grid(imm->i)] != 'P')
		mlx_put_pixel(var->img_3d, imm->map_x, imm->map_y, 0x000000FF);
	else if (var->map[px_to_map_grid(imm->j)]
		[px_to_map_grid(imm->i)] == 'P')
		mlx_put_pixel(var->img_3d, imm->map_x, imm->map_y, 0xFF0000FF);
	else
		mlx_put_pixel(var->img_3d, imm->map_x, imm->map_y, 0xFFFFFFFF);
}

void	sub_init_mini_map_system(t_var *var, t_imm *imm)
{
	while (imm->j < imm->end.y && imm->map_y < 100 && imm->j < var->mini_height)
	{
		imm->i = imm->start.x;
		imm->map_x = 0;
		while (imm->i < imm->end.x && imm->map_x < 100)
		{
			if (imm->i > ft_strlen(var->map[px_to_map_grid(imm->j)])
				* SQUARE_SIZE)
				break ;
			sub_init_mini_map_system_0(var, imm);
			imm->map_x++;
			imm->i++;
		}
		imm->map_y++;
		imm->j++;
	}
}

void	init_mini_map_system(t_var *var)
{
	t_imm	imm;

	imm.map_x = 0;
	imm.map_y = 0;
	imm.mini_width = calculate_mini_map_width(var);
	imm.mini_height = strlen_double((void **)var->map);
	if (var->player.position.x - 50 > 0)
		imm.start.x = var->player.position.x - 50;
	else
		imm.start.x = 0;
	if (var->player.position.y - 50 > 0)
		imm.start.y = var->player.position.y - 50;
	else
		imm.start.y = 0;
	if (var->player.position.x + 50 > imm.mini_width)
		imm.end.x = var->player.position.x + 50;
	else
		imm.end.x = imm.mini_width;
	if (var->player.position.y + 50 > imm.mini_height)
		imm.end.y = var->player.position.y + 50;
	else
		imm.end.y = imm.mini_height;
	imm.i = (t_uint)imm.start.x;
	imm.j = (t_uint)imm.start.y;
	sub_init_mini_map_system(var, &imm);
}
