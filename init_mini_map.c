#include "cube.h"

void    color_wall(t_uint *tracker, t_var *var)
{
    t_uint i;
    t_uint j;

    i = tracker[1];
    while (i < tracker[1] + SQUARE_SIZE && i < var->mini_height)
    {
        j = tracker[0];
        while (j < tracker[0] + SQUARE_SIZE && j < var->mini_width)
        {
            mlx_put_pixel(var->mini_map, j, i, 0xFFFFFFFF);
            j++;
        }
        i++;
    }
}

void    color_floor(t_uint *tracker, t_var *var)
{
    t_uint i;
    t_uint j;

    i = tracker[1];
    while (i < tracker[1] + SQUARE_SIZE && i < var->mini_height)
    {
        j = tracker[0];
        while (j < tracker[0] + SQUARE_SIZE && j < var->mini_width)
        {
            mlx_put_pixel(var->mini_map, j, i, 0x000000FF);
            j++;
        }
        i++;
    }
}

unsigned int   calculate_mini_map_width(t_var *var)
{
    unsigned int width;
    unsigned int i;
    unsigned int j;

    width = 0;
    i = -1;
    while (var->map[++i])
    {
        j = -1;
        while (var->map[i][++j])
            ;
        if (j > width)
            width = j;
    }
    return width;
}

void    init_img3d(t_var *var)
{
    var->mini_width = calculate_mini_map_width(var) * SQUARE_SIZE;
    var->mini_height = (t_uint)(strlen_double((void **)var->map)) * SQUARE_SIZE;
    if (var->img_3d)
        mlx_delete_image(var->mlx, var->img_3d);
    if (var->gunFireImg)
        mlx_delete_image(var->mlx, var->gunFireImg);
    if (var->gunPreFireImg)
        mlx_delete_image(var->mlx, var->gunPreFireImg);
    var->img_3d = mlx_new_image(var->mlx, WIDTH, HEIGHT);
    mlx_image_to_window(var->mlx, var->img_3d, 0, 0);
}
