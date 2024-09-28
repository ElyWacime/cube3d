#include "cube.h"

void    color_wall(int *tracker, t_var *var)
{
    int i;
    int j;

    i = tracker[1];
    while (i <= tracker[1] + 32 && i < MINI_HEIGHT)
    {
        j = tracker[0];
        while (j <= tracker[0] + 32 && j < MINI_WIDTH)
        {
            mlx_put_pixel(var->mini_map, j, i, 0xFFFFFFFF);
            j++;
        }
        i++;
    }
}

void    color_floor(int *tracker, t_var *var)
{
    int i;
    int j;

    i = tracker[1];
    while (i <= tracker[1] + 32 && i < MINI_HEIGHT)
    {
        j = tracker[0];
        while (j <= tracker[0] + 32 && j < MINI_WIDTH)
        {
            mlx_put_pixel(var->mini_map, j, i, 0xFF00FFFF);
            j++;
        }
        i++;
    }
}

void    init_mini_map(t_var *var)
{
    var->mini_map = mlx_new_image(var->mlx, MINI_WIDTH, MINI_HEIGHT);
    int i;
    int j;
    int tracker[2];

    tracker[1] = 0;
    i = -1;
    while (var->map[++i])
    {
        tracker[0] = 0;
        j = -1;
        while (var->map[++j])
        {
            if (var->map[i][j] == '1')
            {
                color_wall(tracker, var);
            }
            else if (var->map[i][j] == '0')
                color_floor(tracker, var);
            tracker[0] += 32;
        }
        tracker[1] += 32;
    }
    if (mlx_image_to_window(var->mlx, var->mini_map, 0, 0))
        ft_error();
    print_map(var);
}
