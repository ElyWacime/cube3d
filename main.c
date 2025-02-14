#include "cube.h"

void parse_arguments(char *arg)
{
    char *cube;

    cube = NULL;
    cube = ft_strnstr(arg, ".cub", ft_strlen(arg) + 1);
    if (!cube)
    {
        write(2, "wrong file format!", 18);
        exit(4);
    }
    if (ft_strncmp(cube, ".cub", 5))
    {
        write(2, "wrong file format!", 18);
        exit(5);
    }
}

void    is_map_all_ones(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] && map[i][j] != '1' && !ft_isspace(map[i][j]))
            {
                write(2, "Error\nInvalid map!", 17);
                exit(31);
            }
            j++;
        }
        i++;
    }
}

void parsing(int ac, char *av[], t_var *var)
{
    char **_map;
    int position[2];
    int zero_position[2];

    if (ac != 2)
    {
        write(1, "wrong number of arguments!", 26);
        exit(3);
    }
    parse_arguments(av[1]);
    free_double((void **)var->map);
    var->map = create_map(av[1], var);
    _map = strdup_double(var->map);
    get_players_position(var->map, position, var);
    var->player.position.x = (position[1] * SQUARE_SIZE) + (SQUARE_SIZE /2);
    var->player.position.y = (position[0] * SQUARE_SIZE) + (SQUARE_SIZE /2);
    while (is_still_there_zeros(_map, zero_position))
        flood_fill(_map, zero_position[1], zero_position[0]);
    is_map_all_ones(_map);
    free_double((void**)_map);
    free(_map);
}

void check_for_images(t_var *var)
{
    int fd;

    fd = open("./textures/door.png", O_RDONLY);
    if (fd < 1)
        quit_program(var);
    fd = open("./textures/gunImageFire.png", O_RDONLY);
    if (fd < 1)
        quit_program(var);
    fd = open("./textures/gunImagePreFire.png", O_RDONLY);
    if (fd < 1)
        quit_program(var);
}

void print_map(t_var var)
{
    int len;
    len = strlen_double((void**)var.map);
    for (int i = 0;i<len;i++)
    {
        for (int j=0;var.map[i][j];j++)
            printf("%c", var.map[i][j]);
        printf("\n");
    }
}

void    init_vars(t_var *var)
{
    var->img = NULL;
    var->mlx = NULL;
    var->img = NULL;
    var->img_3d = NULL;
    var->mini_map = NULL;
    var->map = NULL;
    var->textures = NULL;
    var->colors = NULL;
    var->door_cords.len = 0;
    var->door_cords.cords = NULL;
    var->gunFireImg = NULL;
    var->gunPreFireImg = NULL;
}

void    load_pictures(t_var *var)
{
    var->north =   mlx_load_png(var->textures[0] + 3);
    var->south =   mlx_load_png(var->textures[1] + 3);
    var->west =   mlx_load_png(var->textures[2] + 3);
    var->east =   mlx_load_png(var->textures[3] + 3);
    check_for_images(var);
    var->door = mlx_load_png("./textures/door.png");
    var->gunFire = mlx_load_png("./textures/gunImageFire.png");
    var->gunPreFire = mlx_load_png("./textures/gunImagePreFire.png");
}

int main(int ac, char *av[])
{
    t_var var;

    init_vars(&var);
    parsing(ac, av, &var);
    _init_window(&var);
    var.mini_map = mlx_new_image(var.mlx, WIDTH, HEIGHT);
    init_img3d(&var);
    load_pictures(&var);
    print_map(var);
    get_all_door_cords(&var);
    cast(&var);
    init_mini_map_system(&var);
    draw_gun(&var);
    mlx_key_hook(var.mlx, &listen_to_key, (void*)&var);
    mlx_cursor_hook(var.mlx, mlx_mouse_func, (void*)&var);
    mlx_loop(var.mlx);
    return 0;
}
