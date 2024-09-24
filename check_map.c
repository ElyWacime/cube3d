#include "cube.h"

int    get_players_position(char **map, int *position)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'N')
            {
                position[0] = i;
                position[1] = j;
                return 0;
            }
            j++;
        }
        i++;
    }
    perror("Map does't have player!");
    exit(1);
}

int is_still_there_zeros(char **_map, int *zero_position)
{
    int i;
    int j;

    i = 0;
    while (_map[i])
    {
        j = 0;
        while (_map[i][j])
        {
            if (_map[i][j] == '0')
            {
                zero_position[0] = i;
                zero_position[1] = j;
                return 1;
            }
            j++;
        }
        i++;
    }
    return 0;
}

int flood_fill(char **map, int x, int  y, int *k)
{
    if (*k == 1)
    {
        printf("map is invalid!");
        exit(2);
    }
    if ((x < 0 || y < 0 || !map[y])
        || x > (int)ft_strlen(map[y])
        || map[y][x] == ' ')
        return (1);
    if (map[y][x] == '1')
        return 0;
    if (map[y][x] == '0' || map[y][x] == 'N')
        map[y][x] = '1';
    *k = flood_fill(map, x, y + 1, k);
    *k = flood_fill(map, x, y - 1, k);
    *k = flood_fill(map, x + 1, y, k);
    *k = flood_fill(map, x - 1, y, k);
    return *k;
}
