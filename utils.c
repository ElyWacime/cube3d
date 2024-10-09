#include "cube.h"

void    quit_program(t_var *var)
{
    mlx_delete_image(var->mlx, var->mini_map);
    mlx_close_window(var->mlx);
    exit(0);
}

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
    return (c == SQUARE_SIZE || (c >= 9 && c <= 13));
}

t_uint px_to_map_grid(t_uint x)
{
    return (x / SQUARE_SIZE);
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
    if (0 <= x && x < var->mini_width && 0 <= y && y < var->mini_height)
        return (var->map[y_position][x_positon] == '1'
            || var->map[y_position][x_positon] == '\0'
            || ft_isspace(var->map[y_position][x_positon]));
    return 1;
}

double line_fun(double x,double a,double b)
{
    return (a * x) + b;
}

void    draw_line(t_line line, t_var *var, t_uint color)
{
    double distance;
    double x;
    double y;


    distance = calculate_distance(line.ax, line.ay, line.bx, line.by);
    x = line.ax;
    y = line.ay;
    if (x <= line.bx && y <= line.by)
    {
        while ((0 <= x && x < var->mini_width && 0 <= y && y < var->mini_height))
        // while (x <= line.bx && y <= line.by)
        {
            // if (check_if_wall(x, y, var))
                // break;
            mlx_put_pixel(var->mini_map, (t_uint)x, (t_uint)y, color);
            x += (fabs(line.bx - line.ax) / distance);
            y += (fabs(line.by - line.ay) / distance);
        }
    }
    else if (x >= line.bx && y <= line.by)
    {
         while ((0 <= x && x < var->mini_width && 0 <= y && y < var->mini_height))
        // while (x >= line.bx && y <= line.by)
        {
            // if (check_if_wall(x, y, var))
                // break;
            mlx_put_pixel(var->mini_map, (t_uint)x, (t_uint)y, color);
            x -= (fabs(line.bx - line.ax) / distance);
            y += (fabs(line.by - line.ay) / distance);
        }
    }
    else if (x >= line.bx && y >= line.by)
    {
         while ((0 <= x && x < var->mini_width && 0 <= y && y < var->mini_height))
        // while (x >= line.bx && y >= line.by)
        {
            // if (check_if_wall(x, y, var))
                // break;
            mlx_put_pixel(var->mini_map, (t_uint)x, (t_uint)y, color);
            x -= (fabs(line.bx - line.ax) / distance);
            y -= (fabs(line.by - line.ay) / distance);
        }
    }
    else if (x <= line.bx && y >= line.by)
    {
         while ((0 <= x && x < var->mini_width && 0 <= y && y < var->mini_height))
        // while (x <= line.bx && y >= line.by)
        {
            // if (check_if_wall(x, y, var))
                // break;
            mlx_put_pixel(var->mini_map, (t_uint)x, (t_uint)y, color);
            x += (fabs(line.bx - line.ax) / distance);
            y -= (fabs(line.by - line.ay) / distance);
        }
    }

}

void    color_player(t_var *var, int color)
{
    t_uint i;
    t_uint j;

    i = var->player.position[1];
    while (i < var->player.position[1] + SQUARE_SIZE && i < var->mini_height)
    {
        j = var->player.position[0];
        while (j < var->player.position[0] + SQUARE_SIZE && j < var->mini_width)
        {
            if (i >= (var->player.position[1]) && i < var->player.position[1] + SQUARE_SIZE / 16
                && j >= var->player.position[0] && j < var->player.position[0] + SQUARE_SIZE / 16)
                mlx_put_pixel(var->mini_map, j, i, color);
            j++;
        }
        i++;
    }
    var->player.direction = var->player.direction;
}
