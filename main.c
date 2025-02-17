/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:51:39 by skamroun          #+#    #+#             */
/*   Updated: 2025/02/15 17:51:40 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init_vars(t_var *var)
{
	var->img = NULL;
	var->mlx = NULL;
	var->img = NULL;
	var->img_3d = NULL;
	var->mini_map = NULL;
	var->map = NULL;
	var->textures = NULL;
	var->colors = NULL;
	var->door_cords.len = 0;
	var->door_cords.cords = NULL;
	var->gunFireImg = NULL;
	var->gunPreFireImg = NULL;
}

int	main(int ac, char *av[])
{
	t_var	var;

	init_vars(&var);
	parsing(ac, av, &var);
	_init_window(&var);
	var.mini_map = mlx_new_image(var.mlx, WIDTH, HEIGHT);
	init_img3d(&var);
	load_pictures(&var);
	get_all_door_cords(&var);
	cast(&var);
	init_mini_map_system(&var);
	draw_gun(&var);
	mlx_key_hook(var.mlx, &listen_to_key, (void *)&var);
	mlx_cursor_hook(var.mlx, mlx_mouse_func, (void *)&var);
	mlx_loop(var.mlx);
	return (0);
}
