#include "cube.h"

void    quit_program(t_var *var)
{
    free_double((void **)var->map);
    free(var->map);
    mlx_terminate(var->mlx);
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

void get_all_door_cords(t_var *var)
{
    int8_t i;
    int8_t j;
    int8_t trucker;

    i = -1;
    while (++i < (int)var->mini_height / 8)
    {
        j = -1;
        while (var->map[i][++j])
        {
            if (var->map[i][j] == 'P')
                var->door_cords.len++;
        }
    }
    if (var->door_cords.len == 0)
        return ;
    var->door_cords.cords = malloc(sizeof(t_point) * var->door_cords.len);
    i = -1;
    trucker = 0;
    while (++i < (int)var->mini_height / 8)
    {
        j = -1;
        while (var->map[i][++j])
        {
            if (var->map[i][j] == 'P')
            {
                var->door_cords.cords[trucker].x = j;
                var->door_cords.cords[trucker].y = i;
                trucker++;
            }
        }
    }
}

void close_door(t_var *var)
{
    t_uint  i;

    i = 0;
    while (i < var->door_cords.len)
    {
        if (var->door_cords.cords[i].x == px_to_map_grid(var->player.position.x)
            && var->door_cords.cords[i].y == px_to_map_grid(var->player.position.y))
            return ;
        i++;
    }
    i = 0;
    while (i < var->door_cords.len)
    {
        var->map[(int)var->door_cords.cords[i].y][(int)var->door_cords.cords[i].x] = 'P';
        i++;
    }
    init_img3d(var);
    cast(var);
    init_mini_map_system(var);
    mlx_image_to_window(var->mlx, var->gunPreFireImg, (WIDTH / 2) - var->gunFire->width, HEIGHT - var->gunFire->height * 2);
    mlx_image_to_window(var->mlx, var->gunFireImg, (WIDTH / 2) - var->gunPreFire->width, HEIGHT - var->gunPreFire->height * 2);
}

void open_door(t_var *var)
{
    t_uint  i;

    i = 0;
    while (i < var->door_cords.len)
    {
        var->map[(int)var->door_cords.cords[i].y][(int)var->door_cords.cords[i].x] = '0';
        i++;
    }
    init_img3d(var);
    cast(var);
    init_mini_map_system(var);
    mlx_image_to_window(var->mlx, var->gunPreFireImg, (WIDTH / 2) - var->gunFire->width, HEIGHT - var->gunFire->height * 2);
    mlx_image_to_window(var->mlx, var->gunFireImg, (WIDTH / 2) - var->gunPreFire->width, HEIGHT - var->gunPreFire->height * 2);
}

