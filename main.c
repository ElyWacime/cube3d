#include "cube.h"

int main(void)
{
    char **map;
    char **_map;
    int position[2];
    int zero_position[2];
    int k = 0;
    int valid;

    map = create_map();
    _map = create_map();
    if (get_players_position(map, position))
    {
        perror("Map does't have player!");
        exit(1);
    }
    printf("%c\t%d\t%d\n",map[position[0]][position[1]], position[1], position[0]);
    valid = flood_fill(_map, position[1], position[0], &k);
    while (is_still_there_zeros(_map, zero_position))
    {
        printf("fuck\n");
        valid = flood_fill(_map, zero_position[1], zero_position[0], &k);
    }
    printf("%d\n", valid);
    return 0;
}
