#include "cube.h"

void init_mini_map_system(t_var *var)
{
    t_point start;
    t_point end;
    t_uint  map_x = 0;
    t_uint map_y = 0;
    t_uint mini_width = calculate_mini_map_width(var);
    t_uint mini_height = strlen_double((void **)var->map);

    if (var->player.position.x - 50 > 0)
        start.x = var->player.position.x - 50;
    else
        start.x = 0;
    if (var->player.position.y - 50 > 0)
        start.y = var->player.position.y - 50;
    else
        start.y = 0;
    if (var->player.position.x + 50 > mini_width)
        end.x = var->player.position.x + 50;
    else
        end.x = mini_width;
    if (var->player.position.y + 50 > mini_height)
        end.y = var->player.position.y + 50;
    else
        end.y = mini_height;
    t_uint i = (t_uint)start.x, j = (t_uint)start.y;
    while (j < end.y && map_y < 100 && j < var->mini_height)
    {
        i = start.x;
        map_x = 0;
        while (i < end.x && map_x < 100)
        {
            if (i > ft_strlen(var->map[px_to_map_grid(j)]) * SQUARE_SIZE)
                break;
            if (var->map[px_to_map_grid(j)][px_to_map_grid(i)] != '1' &&
                var->map[px_to_map_grid(j)][px_to_map_grid(i)] != 'P')
                mlx_put_pixel(var->img_3d, map_x, map_y, 0x000000FF);
            else if (var->map[px_to_map_grid(j)][px_to_map_grid(i)] == 'P')
                mlx_put_pixel(var->img_3d, map_x, map_y, 0xFF0000FF);
            else
                mlx_put_pixel(var->img_3d, map_x, map_y, 0xFFFFFFFF);
            map_x++;
            i++;
        }
        map_y++;
        j++;
    }
}
