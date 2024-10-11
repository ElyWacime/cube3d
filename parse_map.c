#include "cube.h"

int get_player_position(char **map, int *start)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'N' || map[i][j] == 'S'
                || map[i][j] == 'E' || map[i][j] == 'W')
            {
                start[0] = i;
                start[1] = j;
                return 1;
            }
            j++;
        }
        i++;
    }
    return 0;
}

int check_if_surrounded_by_walls(char **map, int *player_pos)
{
    (void)map;
    (void)player_pos;
    return 1;
}

int parse_map(char **map)
{
    int player_pos[2];
    if (!get_player_position(map, player_pos))
        return 1;
    if (check_if_surrounded_by_walls(map, player_pos))
        return 1;
    return 0;
}
