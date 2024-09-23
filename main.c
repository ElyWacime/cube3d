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
    char **map;
    char **_map;
    int position[2];
    int zero_position[2];
    int k = 0;
    int valid;

    if (ac != 2)
    {
        printf("wrong number of arguments!");
        exit(3);
    }
    parse_arguments(av[1]);
    map = create_map(av[1]);
    _map = create_map(av[1]);
    if (get_players_position(map, position))
    {
        perror("Map does't have player!");
        exit(1);
    }
    printf("%c\t%d\t%d\n",map[position[0]][position[1]], position[1], position[0]);
    valid = flood_fill(_map, position[1], position[0], &k);
    while (is_still_there_zeros(_map, zero_position))
        valid = flood_fill(_map, zero_position[1], zero_position[0], &k);
    printf("%d\n", valid);
    init_map();
    return 0;
}
