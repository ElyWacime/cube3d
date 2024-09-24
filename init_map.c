#include "cube.h"

void    get_texures_colors(t_var *var, int fd)
{
    char *line;
    char *tmp;
    int i;

    i = 0;
    while (i < 4)
    {
        line = gnl(fd);
        if (!line)
        {
            write(2, "Invalid map!", 12);
            exit(5);
        }
        tmp = ft_strjoin(tmp, line);
        free(line);
    }
    var->textures = ft_split(tmp, '\n');
    free(tmp);
    tmp = NULL;
    while (i < 8)
    {
        line = gnl(fd);
        if (!line)
        {
            write(2, "Invalid map!", 12);
            exit(6);
        }
        tmp = ft_strjoin(tmp, line);
        free(line);
    }
    var->wall_floor_colors = ft_split(tmp, '\n');
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
        printf("file not found!");
        exit(6);
    }
    get_texures_colors(var, fd);
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

void    create_floor(t_var *var, mlx_t *mlx)
{
    (void)var;
    (void)mlx;
    return;
}

void    create_wall(t_var *var, mlx_t *mlx)
{
    (void)var;
    (void)mlx;
    return ;
}

void    create_2d_map(t_var *var, mlx_t *mlx)
{
    int i;
    int j;

    i = 0;
    while (var->map[i])
    {
        j = 0;
        while (var->map[i][j])
        {
            if (var->map[i][j] == '1')
                create_floor(var, mlx);
            else if (var->map[i][j] == '0')
                create_wall(var, mlx);
            j++;
        }
        i++;
    }
}

void    _init_map(t_var *var)
{

	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "cube4d", true);
	if (!mlx)
		ft_error();
	create_2d_map(var, mlx);
	mlx_image_t* img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
	mlx_put_pixel(img, 0, 0, 0xFF0000FF);
    mlx_loop(mlx);
}
