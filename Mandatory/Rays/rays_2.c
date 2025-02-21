/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:56:34 by skamroun          #+#    #+#             */
/*   Updated: 2025/02/15 14:56:36 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

float	distance_squared(t_point a, t_point b)
{
	return (((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y)));
}

float	str_double_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

float	my_fmod(float theta, int mod)
{
	int	i;

	i = theta;
	return (theta - ((i / mod) * mod));
}

float	tan_0_90(float theta)
{
	theta = my_fmod(theta, 360);
	theta += 360;
	theta = my_fmod(theta, 360);
	if (90 < theta && theta < 180)
		theta = 180 - theta;
	else if (180 < theta && theta < 270)
		theta = 270 - theta;
	else if (270 < theta && theta < 360)
		theta = theta - 270;
	return (tan(from_deg_to_rad(theta)));
}

t_point	rotate_by(t_point center, t_point m, float angle)
{
	t_point	z;

	z.x = ((m.x - center.x) * cos(angle)) - ((m.y - center.y) * sin(angle))
		+ center.x;
	z.y = ((m.y - center.y) * cos(angle)) + ((m.x - center.x) * sin(angle))
		+ center.y;
	return (z);
}
