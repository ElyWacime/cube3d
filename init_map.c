#include "cube.h"

void    check_textures(char *NO, char *SO, char *WE, char *EA)
{
    if (ft_strncmp(NO, "NO ", 3)
        || ft_strncmp(SO, "SO ", 3)
        || ft_strncmp(WE, "WE ", 3)
        || ft_strncmp(EA, "EA ", 3))
    {
        write(2, "Error\nInvalid path!", 18);
        exit(72);
    }
    free(NO);
    free(SO);
    free(WE);
    free(EA);
}

void   check_path(char *NO, char *SO, char *WE, char *EA)
{
    int fd1;
    int fd2;
    int fd3;
    int fd4;

    fd1 = open(NO, O_RDONLY);
    fd2 = open(SO, O_RDONLY);
    fd3 = open(WE, O_RDONLY);
    fd4 = open(EA, O_RDONLY);
    if (fd1 < 0 || fd2 < 0 || fd3 < 0 || fd4 < 0)
    {
        write(2, "Error\nInvalid path!", 18);
        exit(73);
    }
    close(fd1);
    close(fd2);
    close(fd3);
    close(fd4);
}

void    parse_textures(t_var *var)
{
    char *NO;
    char *SO;
    char *WE;
    char *EA;

    if (strlen_double((void**)var->textures) < 4)
    {
        write(2, "Error\nInvalid path!", 18);
        exit(71);
    }
    check_textures(var->textures[0], var->textures[1],
                    var->textures[2], var->textures[3]);
    NO = var->textures[0] + 3;
    SO = var->textures[1] + 3;
    WE = var->textures[2] + 3;
    EA = var->textures[3] + 3;
    check_path(NO, SO, WE, EA);
}

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
    parse_textures(var);
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

uint32_t  transform_color_to_hexa(int *color)
{
    uint32_t    _color;
   
   _color = (color[0] << 24) | (color[1] << 16) | (color[2] << 8) | 0xFF;
    return _color;
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
    var->color_C = transform_color_to_hexa(_colors);
}

void    extract_F(t_var *var)
{
    char **color;
    int _colors[3];

    if (var->colors[1][0] == 'C' && ft_isspace(var->colors[1][1]))
        color = ft_split(var->colors[1] + 2, ',');
    else
    {
        write(2, "Error\nInvalid color!", 19);
        exit(92);
    }
    check_if_valid_color(color);
    _colors[0] = ft_atoi(color[0]);
    _colors[1] = ft_atoi(color[1]);
    _colors[2] = ft_atoi(color[2]);
    free_double((void**)color);
    var->color_F = transform_color_to_hexa(_colors);
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
    printf("%u\t%u\n", var->color_C, var->color_F);
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

void    _init_window(t_var *var)
{
    (void)var;
    int i;
    int j;

	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "cube4d", true);
    var->mlx = mlx;
	if (!mlx)
		ft_error();
	mlx_image_t* img = mlx_new_image(mlx, WIDTH, HEIGHT);
    if (!img)
		ft_error();
	i = -1;
    while (++i < WIDTH)
    {
        j = -1;
        while (++j < HEIGHT)
        {
            if (j > HEIGHT / 2)
            {
                mlx_put_pixel(img, i, j, var->color_F);
                continue ;
            }
            mlx_put_pixel(img, i, j, var->color_C);
        }
    }
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
    mlx_loop(mlx);
}
