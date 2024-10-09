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

void    draw_vector(t_var *var)
{
    t_line vector;

    if (var->player.direction == 'N')
    {
        var->player.vect[0] = var->player.position[0];
        var->player.vect[1] = var->player.position[1] - 50;
    }
    else if (var->player.direction == 'S')
    {
        var->player.vect[0] = var->player.position[0];
        var->player.vect[1] = var->player.position[1] + 50;
    }
    else if (var->player.direction == 'W')
    {
        var->player.vect[0] = var->player.position[0] - 50;
        var->player.vect[1] = var->player.position[1];
    }
    else if (var->player.direction == 'E')
    {
        var->player.vect[0] = var->player.position[0] + 50;
        var->player.vect[1] = var->player.position[1];
    }
    vector.ax = var->player.position[0];
    vector.ay = var->player.position[1];
    vector.bx = var->player.vect[0];
    vector.by = var->player.vect[1];
    // draw_line(vector, var, 0x00FF00FF);
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
    var->mini_width = calculate_mini_map_width(var) * SQUARE_SIZE;
    var->mini_height = (t_uint)(strlen_double((void **)var->map)) * SQUARE_SIZE;
    var->mini_map = mlx_new_image(var->mlx, var->mini_width, var->mini_height);
    if (!var->mini_map)
        ft_error();
}

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
                color_floor(tracker, var);
            tracker[0] += SQUARE_SIZE;
        }
        tracker[1] += SQUARE_SIZE;
    }
    color_player(var, 0xFF0000FF);
    if (mlx_image_to_window(var->mlx, var->mini_map, 0, 0))
        ft_error();
}
