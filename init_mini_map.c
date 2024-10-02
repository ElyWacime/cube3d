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
            mlx_put_pixel(var->mini_map, j, i, 0x000000FF);
            j++;
        }
        i++;
    }
}

int check_if_wall(double x, double y, t_var *var)
{
    int x_positon;
    int y_position;

    x_positon = px_to_map_grid((t_uint)x);
    y_position = px_to_map_grid((t_uint)y);
    return (var->map[y_position][x_positon] == '1');
}

void    draw_line(t_line line, t_var *var)
{
    double distance;
    double x;
    double y;

    printf("ENTER\n");
    distance = calculate_distance(line.ax, line.ay, line.bx, line.by);
    x = line.ax;
    y = line.ay;
    printf("x == %u\ty == %u\n", (t_uint)x, (t_uint)y);
    printf("x == %u\ty == %u\n", (t_uint)var->player.position[0], (t_uint)var->player.position[1]);
    if (x <= line.bx && y <= line.by)
    {
        while (x <= line.bx && y <= line.by)
        {
            if (check_if_wall(x, y, var))
                break;
            x += (fabs(line.bx - line.ax) / distance);
            y += (fabs(line.by - line.ay) / distance);
            printf("x == %u\ty == %u\n", (t_uint)x, (t_uint)y);
            mlx_put_pixel(var->mini_map, (t_uint)x, (t_uint)y, 0x00FF00FF);
        }
    }
    else if (x >= line.bx && y <= line.by)
    {
        while (x >= line.bx && y <= line.by)
        {
            if (check_if_wall(x, y, var))
                break;
            x -= (fabs(line.bx - line.ax) / distance);
            y += (fabs(line.by - line.ay) / distance);
            printf("x == %u\ty == %u\n", (t_uint)x, (t_uint)y);
            mlx_put_pixel(var->mini_map, (t_uint)x, (t_uint)y, 0x00FF00FF);
        }
    }
    else if (x >= line.bx && y >= line.by)
    {
        while (x >= line.bx && y >= line.by)
        {
            if (check_if_wall(x, y, var))
                break;
            x -= (fabs(line.bx - line.ax) / distance);
            y -= (fabs(line.by - line.ay) / distance);
            printf("x == %u\ty == %u\n", (t_uint)x, (t_uint)y);
            mlx_put_pixel(var->mini_map, (t_uint)x, (t_uint)y, 0x00FF00FF);
        }
    }
    else if (x <= line.bx && y >= line.by)
    {
        while (x <= line.bx && y >= line.by)
        {
            if (check_if_wall(x, y, var))
                break;
            x += (fabs(line.bx - line.ax) / distance);
            y -= (fabs(line.by - line.ay) / distance);
            printf("x == %u\ty == %u\n", (t_uint)x, (t_uint)y);
            mlx_put_pixel(var->mini_map, (t_uint)x, (t_uint)y, 0x00FF00FF);
        }
    }
}

void    draw_vector(t_var *var)
{
    t_line vector;

    if (var->player.direction == 'S')
    {
        var->player.vect[0] = var->player.position[0];
        var->player.vect[1] = var->player.position[1] + 50;
    }
    else if (var->player.direction == 'E')
    {
        var->player.vect[0] = var->player.position[0] + 50;
        var->player.vect[1] = var->player.position[1];
    }
    else if (var->player.direction == 'W')
    {
        var->player.vect[0] = var->player.position[0];
        var->player.vect[1] = var->player.position[1] - 50;
        if (var->player.vect[1] < 0)
            var->player.vect[1] = 0;
    }
    else if (var->player.direction == 'S')
    {
        var->player.vect[0] = var->player.position[0] - 50;
        var->player.vect[1] = var->player.position[1];
        if (var->player.vect[0] < 0)
            var->player.vect[0] = 0;
    }
    vector.ax = var->player.position[0];
    vector.ay = var->player.position[1];
    vector.bx = var->player.vect[0];
    vector.by = var->player.vect[1];
    draw_line(vector, var);
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
            if (i >= (tracker[1]) && i < tracker[1] + 32 / 16
                && j >= tracker[0] && j < tracker[0] + 32 / 16)
                mlx_put_pixel(var->mini_map, j, i, color);
            else
                mlx_put_pixel(var->mini_map, j, i, 0x000000FF);
            j++;
        }
        i++;
    }
    var->player.position[0] = var->player_position[0];
    var->player.position[1] = var->player_position[1];
    var->player.direction = var->player_direction;
    draw_vector(var);
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
                color_player(tracker, var, 0xFF00FFFF);
            tracker[0] += 32;
        }
        tracker[1] += 32;
    }
    if (mlx_image_to_window(var->mlx, var->mini_map, 0, 0))
        ft_error();
}
