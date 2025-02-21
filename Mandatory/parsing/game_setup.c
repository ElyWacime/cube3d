/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:51:00 by skamroun          #+#    #+#             */
/*   Updated: 2025/02/21 18:48:18 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	parse_arguments(char *arg)
{
	char	*cube;

	cube = NULL;
	cube = ft_strnstr(arg, ".cub", ft_strlen(arg) + 1);
	if (!cube)
	{
		write(2, "wrong file format!", 18);
		exit(4);
	}
	if (ft_strncmp(cube, ".cub", 5))
	{
		write(2, "wrong file format!", 18);
		exit(5);
	}
}

void	is_map_all_ones(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] && map[i][j] != '1' && !ft_isspace(map[i][j]))
			{
				write(2, "Error\nInvalid map!", 17);
				exit(31);
			}
			j++;
		}
		i++;
	}
}

void	parsing(int ac, char *av[], t_var *var)
{
	char	**_map;
	int		position[2];
	int		zero_position[2];

	if (ac != 2)
	{
		write(1, "wrong number of arguments!", 26);
		exit(3);
	}
	parse_arguments(av[1]);
	free_double((void **)var->map);
	var->map = create_map(av[1], var);
	_map = strdup_double(var->map);
	get_players_position(var->map, position, var);
	var->player.position.x = (position[1] * SQUARE_SIZE) + (SQUARE_SIZE / 2);
	var->player.position.y = (position[0] * SQUARE_SIZE) + (SQUARE_SIZE / 2);
	while (is_still_there_zeros(_map, zero_position))
		flood_fill(_map, zero_position[1], zero_position[0]);
	is_map_all_ones(_map);
	free_double((void **)_map);
	free(_map);
}

void	load_pictures(t_var *var)
{
	var->north = mlx_load_png(var->textures[0] + 3);
	var->south = mlx_load_png(var->textures[1] + 3);
	var->west = mlx_load_png(var->textures[2] + 3);
	var->east = mlx_load_png(var->textures[3] + 3);
}
