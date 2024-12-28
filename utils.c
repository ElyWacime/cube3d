#include "cube.h"

void    quit_program(t_var *var)
{
    free_double((void **)var->map);
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
    return (c == 32 || (c >= 9 && c <= 13));
}

t_uint px_to_map_grid(t_uint x)
{
    return (x / SQUARE_SIZE);
}

float  calculate_distance(float a, float b, float a1, float b1)
{
    return (sqrt(((a - a1) * (a - a1)) + ((b - b1) * (b - b1))));
}

float  from_rad_to_deg(float val)
{
    return ((val * 180) / PI);
}

float  from_deg_to_rad(float val)
{
    return ((val * PI) / 180);
}
void    draw_line(t_line line, t_var *var, t_uint color)
{
    float distance;
    float x;
    float y;

    distance = calculate_distance(line.ax, line.ay, line.bx, line.by);
    x = line.ax;
    y = line.ay;
    if (x <= line.bx && y <= line.by)
    {
        while ((0 <= x && y < var->mini_height && x < var->mini_width  && x < x + distance && 0 <= y && y < + distance))
        {
            mlx_put_pixel(var->mini_map, (t_uint)x, (t_uint)y, color);
            x += (fabs(line.bx - line.ax) / distance);
            y += (fabs(line.by - line.ay) / distance);
        }
    }
    else if (x >= line.bx && y <= line.by)
    {
         while ((0 <= x && y < var->mini_height && x < var->mini_width  && x < x + distance && 0 <= y && y < + distance))
        {
            mlx_put_pixel(var->mini_map, (t_uint)x, (t_uint)y, color);
            x -= (fabs(line.bx - line.ax) / distance);
            y += (fabs(line.by - line.ay) / distance);
        }
    }
    else if (x >= line.bx && y >= line.by)
    {
         while ((0 <= x && y < var->mini_height && x < var->mini_width  && x < x + distance && 0 <= y && y < + distance))
        {
            mlx_put_pixel(var->mini_map, (t_uint)x, (t_uint)y, color);
            x -= (fabs(line.bx - line.ax) / distance);
            y -= (fabs(line.by - line.ay) / distance);
        }
    }
    else if (x <= line.bx && y >= line.by)
    {
         while ((0 <= x && y < var->mini_height && x < var->mini_width  && x < x + distance && 0 <= y && y < + distance))
        {
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
