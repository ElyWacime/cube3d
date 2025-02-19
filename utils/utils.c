/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:54:36 by skamroun          #+#    #+#             */
/*   Updated: 2025/02/19 18:53:19 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	get_all_door_cords_0(t_var *var, int8_t	*i, int8_t *j)
{
	*i = -1;
	while (++(*i) < (int)var->mini_height / 8)
	{
		*j = -1;
		while (var->map[*i][++(*j)])
		{
			if (var->map[*i][*j] == 'P')
				var->door_cords.len++;
		}
	}
}

void	get_all_door_cords(t_var *var)
{
	int8_t	i;
	int8_t	j;
	int8_t	trucker;

	get_all_door_cords_0(var, &i, &j);
	if (var->door_cords.len == 0)
		return ;
	var->door_cords.cords = malloc(sizeof(t_point) * var->door_cords.len);
	i = -1;
	trucker = 0;
	while (++i < (int)var->mini_height / 8)
	{
		j = -1;
		while (var->map[i][++j])
		{
			if (var->map[i][j] == 'P')
			{
				var->door_cords.cords[trucker].x = j;
				var->door_cords.cords[trucker].y = i;
				trucker++;
			}
		}
	}
}

void	close_door(t_var *var)
{
	t_uint	i;

	i = 0;
	while (i < var->door_cords.len)
	{
		if (var->door_cords.cords[i].x == px_to_map_grid(var->player.position.x)
			&& var->door_cords.cords[i].y
			== px_to_map_grid(var->player.position.y))
			return ;
		i++;
	}
	i = 0;
	while (i < var->door_cords.len)
	{
		var->map[(int)var->door_cords.cords[i].y]
		[(int)var->door_cords.cords[i].x] = 'P';
		i++;
	}
	init_img3d(var);
	cast(var);
	init_mini_map_system(var);
	mlx_image_to_window(var->mlx, var->gunprefireimg, (WIDTH / 2)
		- var->gunfire->width, HEIGHT - var->gunfire->height * 2);
	mlx_image_to_window(var->mlx, var->gunfireimg, (WIDTH / 2)
		- var->gunprefire->width, HEIGHT - var->gunprefire->height * 2);
}

void	open_door(t_var *var)
{
	t_uint	i;

	i = 0;
	while (i < var->door_cords.len)
	{
		var->map[(int)var->door_cords.cords[i].y]
		[(int)var->door_cords.cords[i].x] = '0';
		i++;
	}
	init_img3d(var);
	cast(var);
	init_mini_map_system(var);
	mlx_image_to_window(var->mlx, var->gunprefireimg, (WIDTH / 2)
		- var->gunfire->width, HEIGHT - var->gunfire->height * 2);
	mlx_image_to_window(var->mlx, var->gunfireimg, (WIDTH / 2)
		- var->gunprefire->width, HEIGHT - var->gunprefire->height * 2);
}
