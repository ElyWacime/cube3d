#include "cube.h"

void    get_texures(t_var *var, int fd)
{
    char *line;
    char *tmp;
    int i;

    i = -1;
    tmp = NULL;
    while (++i < 4)
    {
        line = gnl(fd);
        if (!line)
        {
            write(2, "Error\nInvalid map!", 18);
            exit(5);
        }
        tmp = ft_strjoin(tmp, line);
        free(line);
    }
    var->textures = ft_split(tmp, '\n');
    free(tmp);
}

void    extraxt_C(t_var *var)
{
    int i;
    char **color;

    i = -1;
    while (var->wall_floor_colors[++i])
    {
        if (var->wall_floor_colors[i][0] == 'C')
            color = var->wall_floor_colors[i] + 2;
    }
    
}

void    extract_F(t_var *var)
{
    (void)var;
    return ;
}

void    transform_colors_to_hexa(t_var *var)
{
    extraxt_C(var);
    extract_F(var);
}

void    get_colors(t_var *var, int fd)
{
    char *line;
    char *tmp;
    int i;

    i = -1;
    tmp = NULL;
    while (++i < 4)
    {
        line = gnl(fd);
        if (!line)
        {
            write(2, "Error\nInvalid map!", 18);
            exit(5);
        }
        tmp = ft_strjoin(tmp, line);
        free(line);
    }
    var->wall_floor_colors = ft_split(tmp, '\n');
    free(tmp);
    transform_colors_to_hexa(var);
}

char **create_map(char *file_cub, t_var *var)
{
	char        *line = NULL;
	int         fd;
    char        **map;
    char        *_map;

    _map = NULL;
    fd = open(file_cub, O_RDONLY);
    if (fd < 0)
    {
        write(2, "Error\nfile not found!", 21);
        exit(6);
    }
    get_texures(var, fd);
    get_colors(var, fd);
    line = gnl(fd);
    while (line)
    {
        _map = ft_strjoin(_map, line);
        free(line);
        line = gnl(fd);
    }
    map = ft_split(_map, '\n');
    return (map);
}

void    _init_map(t_var *var)
{
    (void)var;
	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "cube4d", true);
	if (!mlx)
		ft_error();
	mlx_image_t* img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
	mlx_put_pixel(img, 0, 0, 0xFF0000FF);
    mlx_loop(mlx);
}
