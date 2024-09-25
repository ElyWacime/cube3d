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

int main(int ac, char *av[])
{
    char **_map;
    int position[2];
    int zero_position[2];
    t_var var;

    if (ac != 2)
    {
        printf("wrong number of arguments!");
        exit(3);
    }
    parse_arguments(av[1]);
    var.map = create_map(av[1], &var);
    // _map = strdup_double_str(var.map);
    _map = create_map(av[1], &var);
    while (_map && *_map)
    {
        printf("%s\n", *_map);
        _map++;
    }
    get_players_position(var.map, position);
    printf("%c\t%d\t%d\n",var.map[position[0]][position[1]],
        position[1], position[0]);
    flood_fill(_map, position[1], position[0]);
    (void)zero_position;
    // while (is_still_there_zeros(_map, zero_position))
    //     valid = flood_fill(_map, zero_position[1], zero_position[0]);
    free_double((void**)_map);
    _init_map(&var);
    return 0;
}
