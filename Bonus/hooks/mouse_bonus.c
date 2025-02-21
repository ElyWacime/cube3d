/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:49:50 by skamroun          #+#    #+#             */
/*   Updated: 2025/02/21 16:36:58 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_bonus.h"

void	mlx_mouse_func(double xpos, double ypos, void *param)
{

	t_mouse ms;
	t_var * var;
	
	var = (t_var *)param;
	ms.prev_x = WIDTH / 2;
	ms.prev_y = HEIGHT / 2;
	(void)xpos;
	(void)ypos;
	mlx_set_cursor_mode(((t_var *)param)->mlx, MLX_MOUSE_HIDDEN);
	if (!var || !var->mlx)
		return ;
	mlx_get_mouse_pos(var->mlx, &ms.mouse_x, &ms.mouse_y);
	ms.delta_x = ms.mouse_x - ms.prev_x;
	if (ms.delta_x > 0)
		rotate_player_right(var);
	else if (ms.delta_x < 0)
		rotate_player_left(var);
	mlx_set_mouse_pos(var->mlx, ms.prev_x, ms.prev_y);
}
