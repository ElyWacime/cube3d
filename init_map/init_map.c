/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:50:06 by skamroun          #+#    #+#             */
/*   Updated: 2025/02/15 17:50:07 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

char **create_map(char *file_cub, t_var *var)
{
	char        *line = NULL;
	int         fd;
    char        **map;
    char        *_map;

    _map = NULL;
    fd = open(file_cub, O_RDONLY);
    if (fd < 0)
    {
        write(2, "Error\nfile not found!", 21);
        exit(6);
    }
    get_texures(var, fd);
    get_colors(var, fd);
    line = gnl(fd);
    while (line)
    {
        _map = ft_strjoin(_map, line);
        free(line);
        line = gnl(fd);
    }
    map = ft_split(_map, '\n');
    free(_map);
    return (map);
}
void    _init_window_3d(t_var *var)
{
	
    if (var->img_3d)
        mlx_image_to_window(var->mlx, var->img_3d, 0, 0);
    else
        ft_error();
}

void    sub_init_window(t_var *var, int i, int j)
{
    i = -1;
    while (++i < WIDTH)
    {
        j = -1;
        while (++j < HEIGHT)
        {
            if (j > HEIGHT / 2)
            {
                mlx_put_pixel(var->img, i, j, var->color_F);
                continue ;
            }
            if (i < 100 && j < 100)
                continue;
            mlx_put_pixel(var->img, i, j, var->color_C);
        }
    }
    mlx_image_to_window(var->mlx, var->img, 0, 0);
}

void    _init_window(t_var *var)
{
    int i;
    int j;

    i = -1;
    j = -1;
	var->mlx = mlx_init(WIDTH, HEIGHT, "cube4d", true);
	if (var->mlx)
	{
        var->img = mlx_new_image(var->mlx, WIDTH, HEIGHT);
        var->img_3d = mlx_new_image(var->mlx, WIDTH, HEIGHT);
        if (var->img)
            sub_init_window(var, i, j);
        else
            ft_error();
    }
    else
        ft_error();
}
