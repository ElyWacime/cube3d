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

void    check_if_valid_color(char **color)
{
    int i;
    int j;

    i = -1;
    if (strlen_double((void**)color) != 3)
    {
        write(2, "Error\nInvalid color!", 19);
        exit(90);
    }
    while (color[++i])
    {
        if (ft_strlen(color[i]) > 3)
        {
            write(2, "Error\nInvalid color!", 19);
            exit(90);
        }
        j = -1;
        while (color[i][++j])
        {
            if (!ft_isdigit(color[i][j]))
            {
                write(2, "Error\nInvalid color!", 19);
                exit(90);
            }
        }
    }
}

size_t  transform_color_to_hexa(int *color)
{
    
}

void    extraxt_C(t_var *var)
{
    char **color;
    int _colors[3];

    if (var->colors[0][0] == 'F' && ft_isspace(var->colors[0][1]))
        color = ft_split(var->colors[0] + 2, ',');
    else
    {
        write(2, "Error\nInvalid color!", 19);
        exit(91);
    }
    check_if_valid_color(color);
    _colors[0] = ft_atoi(color[0]);
    _colors[1] = ft_atoi(color[1]);
    _colors[2] = ft_atoi(color[2]);
    free_double((void**)color);
    var->color_C = transform_color_to_heaxa(_colors);
}

void    extract_F(t_var *var)
{
    (void)var;
    return ;
}

void    parse_colors(t_var *var)
{
    extraxt_C(var);
    extract_F(var);
}

void    get_colors(t_var *var, int fd)
{
    char *line;
    char *tmp;
    int  i;

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
    var->colors = ft_split(tmp, '\n');
    free(tmp);
    parse_colors(var);
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
