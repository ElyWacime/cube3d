/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:50:58 by skamroun          #+#    #+#             */
/*   Updated: 2025/02/15 20:11:40 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	init_player_angle(t_var *var)
{
	if (var->player.direction == 'N')
		var->player.angle = 90;
	else if (var->player.direction == 'S')
		var->player.angle = 270;
	else if (var->player.direction == 'W')
		var->player.angle = 180;
	else if (var->player.direction == 'E')
		var->player.angle = 0;
}

int	get_players_position(char **map, int *position, t_var *var)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'W'
				|| map[i][j] == 'S')
			{
				var->player.direction = map[i][j];
				init_player_angle(var);
				position[0] = i;
				position[1] = j;
				return (0);
			}
			j++;
		}
		i++;
	}
	write(2, "Error\nMap does't have player!", 29);
	exit(1);
}

int	is_still_there_zeros(char **_map, int *zero_position)
{
	int	i;
	int	j;

	i = 0;
	while (_map[i])
	{
		j = 0;
		while (_map[i][j])
		{
			if (_map[i][j] == '0' || _map[i][j] == 'P')
			{
				zero_position[0] = i;
				zero_position[1] = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	flood_fill(char **map, int x, int y)
{
	static int	flag;

	if (x < 0 || y < 0 || y >= strlen_double((void **)map)
		|| x >= (int)ft_strlen(map[y]) || map[y][x] == ' ' || flag > 1)
	{
		write(2, "Error\nmap is invalid!", 21);
		exit(21);
	}
	if (map[y][x] == '1')
		return ;
	if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'W'
		|| map[y][x] == 'S' || map[y][x] == 'E' || map[y][x] == 'P')
	{
		if (!(map[y][x] == '0' || map[y][x] == 'P'))
			flag += 1;
		map[y][x] = '1';
	}
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
}
