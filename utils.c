#include "cube.h"

void ft_error(void)
{
    char *err_str;

    err_str = (char *)mlx_strerror(mlx_errno);
    write(2, "Error\n", 6);
	write(2, err_str, ft_strlen(err_str));
	exit(EXIT_FAILURE);
}

void    free_double(void **ptr)
{
    if (!ptr)
        return ;
    while (ptr && *ptr)
    {
        free(*ptr);
        ptr++;
    }
}

int strlen_double(void **ptr)
{
    int     i;
    void    **holder;

    holder = ptr;
    
    
    if (!holder)
        return 0;
    i = 0;
    while (holder && *holder)
    {
        holder++;
        i++;
    }
    return i;
}

void    print_map(t_var *var)
{
    int i;
    int j;

    i = -1;
    printf("###########\n");
    while (var->map[++i])
    {
        j = -1;
        while (var->map[i][++j])
        {
            printf("%c", var->map[i][j]);
        }
        printf("\n");
    }
    printf("###########\n");
}

char    **strdup_double(char **str)
{
    char **ret;
    int retlen;
    int i;

    retlen = strlen_double((void **)str);
    i = 0;
    ret = (char **)malloc(sizeof(char *) * (retlen + 1));
    while (i < retlen)
    {
        ret[i] = ft_strdup(str[i]);
        i++;
    }
    ret[i] = NULL;
    return (ret);
}

int ft_isspace(char c)
{
    return (c == 32 || (c >= 9 && c <= 13));
}

t_uint px_to_map_grid(t_uint x)
{
    return (x / 32);
}

double  calculate_distance(double a, double b, double a1, double b1)
{
    return (sqrt(((a - a1) * (a - a1)) + ((b - b1) * (b - b1))));
}

double  from_rad_to_deg(double val)
{
    return ((val * 180) / PI);
}

double  from_deg_to_rad(double val)
{
    return ((val * PI) / 180);
}

int check_if_wall(double x, double y, t_var *var)
{
    int x_positon;
    int y_position;

    x_positon = px_to_map_grid((t_uint)x);
    y_position = px_to_map_grid((t_uint)y);
    return (var->map[y_position][x_positon] == '1'
        || var->map[y_position][x_positon] == '\0'
        || ft_isspace(var->map[y_position][x_positon]));
}

void    draw_line2(t_line line, t_var *var)
{
    double distance;
    double x;
    double y;


    distance = calculate_distance(line.ax, line.ay, line.bx, line.by);
    x = line.ax;
    y = line.ay;
    if (x <= line.bx && y <= line.by)
    {
        while (x <= line.bx && y <= line.by)
        {
            if (check_if_wall(x, y, var))
                break;
            x += (fabs(line.bx - line.ax) / distance);
            y += (fabs(line.by - line.ay) / distance);
            mlx_put_pixel(var->mini_map, (t_uint)x, (t_uint)y, 0xFF0000FF);
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
            mlx_put_pixel(var->mini_map, (t_uint)x, (t_uint)y, 0xFF0000FF);
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
            mlx_put_pixel(var->mini_map, (t_uint)x, (t_uint)y, 0xFF0000FF);
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
            mlx_put_pixel(var->mini_map, (t_uint)x, (t_uint)y, 0xFF0000FF);
        }
    }
}
void    draw_line(t_line line, t_var *var)
{
    double distance;
    double x;
    double y;


    distance = calculate_distance(line.ax, line.ay, line.bx, line.by);
    x = line.ax;
    y = line.ay;
    if (x <= line.bx && y <= line.by)
    {
        while (x <= line.bx && y <= line.by)
        {
            if (check_if_wall(x, y, var))
                break;
            x += (fabs(line.bx - line.ax) / distance);
            y += (fabs(line.by - line.ay) / distance);
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
            mlx_put_pixel(var->mini_map, (t_uint)x, (t_uint)y, 0x00FF00FF);
        }
    }
}