/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:50:14 by skamroun          #+#    #+#             */
/*   Updated: 2025/02/21 16:36:58 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_bonus.h"

void	check_if_valid_color(char **color)
{
	int	i;
	int	j;

	i = -1;
	check_len(color);
	while (color[++i])
	{
		if (ft_strlen(color[i]) > 3)
		{
			write(2, "Error\nInvalid color!", 19);
			exit(90);
		}
		j = -1;
		while (color[i][++j])
		{
			if (!ft_isdigit(color[i][j]))
			{
				write(2, "Error\nInvalid color!", 19);
				exit(90);
			}
		}
	}
}

uint32_t	transform_color_to_hexa(int *color)
{
	uint32_t	_color;

	_color = (color[0] << 24) | (color[1] << 16) | (color[2] << 8) | 0xFF;
	return (_color);
}

void	extract_f(t_var *var)
{
	char	**color;
	int		_colors[3];

	if (var->colors[0][0] == 'F' && ft_isspace(var->colors[0][1]))
		color = ft_split(var->colors[0] + 2, ',');
	else
	{
		write(2, "Error\nInvalid color!", 19);
		exit(91);
	}
	check_if_valid_color(color);
	_colors[0] = ft_atoi(color[0]);
	_colors[1] = ft_atoi(color[1]);
	_colors[2] = ft_atoi(color[2]);
	free_double((void **)color);
	free(color);
	var->colorf = transform_color_to_hexa(_colors);
}

void	extract_c(t_var *var)
{
	char	**color;
	int		_colors[3];

	if (var->colors[1][0] == 'C' && ft_isspace(var->colors[1][1]))
		color = ft_split(var->colors[1] + 2, ',');
	else
	{
		write(2, "Error\nInvalid color!", 19);
		exit(92);
	}
	check_if_valid_color(color);
	_colors[0] = ft_atoi(color[0]);
	_colors[1] = ft_atoi(color[1]);
	_colors[2] = ft_atoi(color[2]);
	free_double((void **)color);
	free(color);
	var->color_c = transform_color_to_hexa(_colors);
}

void	get_colors(t_var *var, int fd)
{
	char	*line;
	char	*tmp;
	int		i;

	i = -1;
	tmp = NULL;
	while (++i < 4)
	{
		line = gnl(fd);
		if (!line)
		{
			write(2, "Error\nInvalid map!", 18);
			exit(5);
		}
		tmp = ft_strjoin(tmp, line);
		free(line);
	}
	var->colors = ft_split(tmp, '\n');
	free(tmp);
	extract_c(var);
	extract_f(var);
}
