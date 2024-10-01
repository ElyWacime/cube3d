#include "cube.h"

void    color_wall(t_uint *tracker, t_var *var)
{
    t_uint i;
    t_uint j;

    i = tracker[1];
    while (i <= tracker[1] + 32 && i < var->mini_height)
    {
        j = tracker[0];
        while (j <= tracker[0] + 32 && j < var->mini_width)
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
    while (i <= tracker[1] + 32 && i < var->mini_height)
    {
        j = tracker[0];
        while (j <= tracker[0] + 32 && j < var->mini_width)
        {
            mlx_put_pixel(var->mini_map, j, i, 0xFF00FFFF);
            j++;
        }
        i++;
    }
}

void    color_player(t_uint *tracker, t_var *var, int color)
{
    t_uint i;
    t_uint j;

    i = tracker[1];
    var->player_position[0] = (double)tracker[0];
    var->player_position[1] = (double)tracker[1];
    while (i <= tracker[1] + 32 && i < var->mini_height)
    {
        j = tracker[0];
        while (j <= tracker[0] + 32 && j < var->mini_width)
        {
            if (i >= (tracker[1]) && i < tracker[1] + 32 / 8
                && j >= tracker[0] && j < tracker[0] + 32 / 8)
                mlx_put_pixel(var->mini_map, j, i, color);
            else
                mlx_put_pixel(var->mini_map, j, i, 0xFF00FFFF);
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

void    create_mini_map_image(t_var *var)
{
    var->mini_width = calculate_mini_map_width(var) * 32;
    var->mini_height = (t_uint)(strlen_double((void **)var->map)) * 32;
    var->mini_map = mlx_new_image(var->mlx, var->mini_width, var->mini_height);
    if (!var->mini_map)
        ft_error();
}

// void    draw_line(double distance, t_var *var)
// {
//     double x;
//     double y;

//     x = var->player_position[1];
//     y = var->player_position[0];
//     while (x < var->player_position[1] + 50 && y < var->player_position[0] + 50)
//     {
//         printf("%u\t%u\n", (t_uint)x, (t_uint)y);
//         mlx_put_pixel(var->mini_map, (t_uint)y,(t_uint)x, 0x00FF00FF);
//         y += 50 / distance;
//         x += 50 / distance;
//     }
// }

// void    rotate_player_left(t_var *var)
// {
//     double  position[2];
//     double  distance;

//     position[0] = var->player_position[0] + 50;
//     position[1] = var->player_position[1] + 50;
//     distance = calculate_distance(position[0], position[1],
//         var->player_position[0], var->player_position[1]);
//     draw_line(distance, var);
// }

void    init_mini_map(t_var *var)
{
    create_mini_map_image(var);
    int i;
    int j;
    t_uint tracker[2];

    tracker[1] = 0;
    i = -1;
    while (var->map[++i])
    {
        tracker[0] = 0;
        j = -1;
        while (var->map[i][++j])
        {
            if (var->map[i][j] == '1')
                color_wall(tracker, var);
            else if (var->map[i][j] == '0')
                color_floor(tracker, var);
            else if (var->map[i][j] == 'N')
                color_player(tracker, var, 0x000000FF);
            tracker[0] += 32;
        }
        tracker[1] += 32;
    }
    if (mlx_image_to_window(var->mlx, var->mini_map, 0, 0))
        ft_error();
    // rotate_player_left(var);
}
