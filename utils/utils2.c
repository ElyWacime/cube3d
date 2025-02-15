/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:54:42 by skamroun          #+#    #+#             */
/*   Updated: 2025/02/15 19:54:44 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	ft_isspace(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

t_uint	px_to_map_grid(t_uint x)
{
	return (x / SQUARE_SIZE);
}

float	calculate_distance(float a, float b, float a1, float b1)
{
	return (sqrt(((a - a1) * (a - a1)) + ((b - b1) * (b - b1))));
}

float	from_rad_to_deg(float val)
{
	return ((val * 180) / PI);
}

float	from_deg_to_rad(float val)
{
	return ((val * PI) / 180);
}
