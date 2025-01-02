#include "cube.h"

void    check_textures(char *NO, char *SO, char *WE, char *EA)
{
    if (ft_strncmp(NO, "NO ", 3)
        || ft_strncmp(SO, "SO ", 3)
        || ft_strncmp(WE, "WE ", 3)
        || ft_strncmp(EA, "EA ", 3))
    {
        write(2, "Error 1\nInvalid path!", 21);
        exit(72);
    }
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
        write(2, "Error 2\nInvalid path!\n", 20);
        close(fd1);
        close(fd2);
        close(fd3);
        close(fd4);
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
        write(2, "Error 3\nInvalid path!", 20);
        exit(71);
    }
    check_textures(var->textures[0], var->textures[1],
                    var->textures[2], var->textures[3]);
    NO = var->textures[0] + 3;
    SO = var->textures[1] + 3;
    WE = var->textures[2] + 3;
    EA = var->textures[3] + 3;
    // printf("%s\t%s\t%s\t%s\t\n", NO, SO, WE, EA);
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
        // printf("ENTER\n");
        line = gnl(fd);
        if (!line)
        {
            write(2, "Error\nInvalid map!", 18);
            exit(5);
        }
        tmp = ft_strjoin(tmp, line);
        // printf("inside loop: %s\tline: %s\n", tmp, line);
        free(line);
    }
    var->textures = ft_split(tmp, '\n');
    // printf(">>>>>>>>%s\n\n\n\n\n\n", tmp);
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

void    extract_F(t_var *var)
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

void    extract_C(t_var *var)
{
    char **color;
    int _colors[3];

    // printf(">>>> %c\n", var->colors[1][0]);
    // printf(">>>> %d\t%d\n", var->colors[1][0] == 'C' && ft_isspace(var->colors[1][1]));
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
    extract_C(var);
    extract_F(var);
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
    free(_map);
    return (map);
}
void    _init_window_3d(t_var *var)
{
	
    if (var->img_3d)
        mlx_image_to_window(var->mlx, var->img_3d, 0, 0);
    else
        ft_error();
}

void    _init_window(t_var *var)
{
    int i;
    int j;

	var->mlx = mlx_init(WIDTH, HEIGHT, "cube4d", true);
	if (var->mlx)
	{
        var->img = mlx_new_image(var->mlx, WIDTH, HEIGHT);
        var->img_3d = mlx_new_image(var->mlx, WIDTH, HEIGHT);
        if (var->img)
        {
            i = -1;
            while (++i < WIDTH)
            {
                j = -1;
                while (++j < HEIGHT)
                {
                    if (j > HEIGHT / 2)
                    {
                        mlx_put_pixel(var->img, i, j, var->color_F);
                        continue ;
                    }
                    if (i < 100 && j < 100)
                        continue;
                    mlx_put_pixel(var->img, i, j, var->color_C);
                }
            }
            mlx_image_to_window(var->mlx, var->img, 0, 0);
        }
        else
            ft_error();
    }
    else
        ft_error();
}


