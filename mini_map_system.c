#include "cube.h"

void init_mini_map_system(t_var *var)
{
    int i = 0, j = 0;
    // var->mini_map_system = mlx_new_image(var->mlx, 100, 100);
    while (i++ < 100)
    {
        j = 0;
        while (j++ < 100)
            mlx_put_pixel(var->img_3d, j, i, 0xFF0000FF);
    }
    // mlx_image_to_window(var->mlx, var->mini_map_system, 0, 0);
}

void draw_animated_sprite(t_var *var)
{
    int i = 0, j = 0;
    while (i++ < 100)
    {
        j = 0;
        while (j++ < 100)
            mlx_put_pixel(var->img_3d, j, i, 0xFF0000FF);
    }
}