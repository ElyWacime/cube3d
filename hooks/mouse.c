/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:49:50 by skamroun          #+#    #+#             */
/*   Updated: 2025/02/15 17:49:51 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	mlx_mouse_func(double xpos, double ypos, void *param)
{
	t_var	*var;
	int32_t	prev_x;
	int32_t	prev_y;
	float	delta_x;

	var = (t_var *)param;
	prev_x = WIDTH / 2;
	prev_y = HEIGHT / 2;
	mlx_set_cursor_mode(((t_var *)param)->mlx, MLX_MOUSE_HIDDEN);
	if (!var || !var->mlx)
		return ;
	mlx_get_mouse_pos(var->mlx, (int32_t*)&xpos, (int32_t*)&ypos);
	delta_x = xpos - prev_x;
	if (delta_x > 0)
		rotate_player_right(var);
	else if (delta_x < 0)
		rotate_player_left(var);
	mlx_set_mouse_pos(var->mlx, prev_x, prev_y);
}
