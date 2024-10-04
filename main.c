#include "cube.h"

void parse_arguments(char *arg)
{
    char *cube;

    cube = NULL;
    cube = ft_strnstr(arg, ".cub", ft_strlen(arg) + 1);
    if (!cube)
    {
        printf("wrong file format!");
        exit(4);
    }
    if (ft_strncmp(cube, ".cube", 5))
    {
        printf("wrong file format!");
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
    char **to_print;

    if (ac != 2)
    {
        printf("wrong number of arguments!");
        exit(3);
    }
    parse_arguments(av[1]);
    var->map = create_map(av[1], var);
    _map = strdup_double(var->map);
    to_print = _map;
    while (to_print && *to_print)
    {
        printf("%s\n", *to_print);
        to_print++;
    }
    get_players_position(var->map, position, var);
    var->player.position[0] = position[1] * 32;
    var->player.position[1] = position[0] * 32;
    while (is_still_there_zeros(_map, zero_position))
        flood_fill(_map, zero_position[1], zero_position[0]);
    is_map_all_ones(_map);
    free_double((void**)_map);
}

int main(int ac, char *av[])
{
    t_var var;

    parsing(ac, av, &var);
    _init_window(&var);
    init_mini_map(&var);
    draw_vector(&var);
    mlx_key_hook(var.mlx, &listen_to_key, (void*)&var);
    mlx_loop(var.mlx);
    return 0;
}
