#include "cube.h"

char **create_map(char *file_cub)
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

void    put_wall_img_to_map(char **map, mlx_t *mlx)
{
    (void)map;
    (void)mlx;
    return;
}

void    put_floor_img_to_map(char **map, mlx_t *mlx)
{
    (void)map;
    (void)mlx;
    return ;
}

void    add_floor_2d(char **map, mlx_t *mlx)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == '1')
                put_wall_img_to_map(map, mlx);
            else if (map[i][j] == '0')
                put_floor_img_to_map(map, mlx);
        }
    }
}

void    _init_map(t_var *var)
{

	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
	if (!mlx)
		ft_error();
	add_floor_2d(var->map, mlx);
	mlx_image_t* img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
	mlx_put_pixel(img, 0, 0, 0xFF0000FF);
    mlx_loop(mlx);
}
