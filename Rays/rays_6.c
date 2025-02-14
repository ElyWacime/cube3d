#include "../cube.h"

int check_if_wall_h(t_point start, t_point direction, t_var *var)
{
    int row;
    int col;

    row = px_to_map_grid((t_uint)start.y) - (direction.y == -1);
    col = px_to_map_grid((t_uint)start.x);
    if (!(0 <= row && row < str_double_len(var->map) && 0 <= col && col < (float)ft_strlen(var->map[row])))
        return 1;
    if (col * SQUARE_SIZE == start.x)
    {
        if (var->map[row][col] == 'P' || var->map[row][col - 1] == 'P')
            return DOOR;
        return (var->map[row][col] == '1'
            || var->map[row][col] == '\0'
            || ft_isspace(var->map[row][col])
            || var->map[row][col - 1] == '1'
            || var->map[row][col - 1] == '\0'
            || ft_isspace(var->map[row][col - 1])
            );
    }
    if (var->map[row][col] == 'P')
        return DOOR;
    return (var->map[row][col] == '1'
        || var->map[row][col] == '\0'
        || ft_isspace(var->map[row][col])
        );
}

int check_if_wall_v(t_point start, t_point direction, t_var *var)
{
    int row;
    int col;

    row = px_to_map_grid((t_uint)start.y);
    col = px_to_map_grid((t_uint)start.x) - (direction.x == -1);
    if (!(0 <= row && row < str_double_len(var->map) && 0 <= col && col < (float)ft_strlen(var->map[row])))
        return 1;
    if (row * SQUARE_SIZE == start.y)
    {
        if (var->map[row][col] == 'P' || var->map[row - 1][col] == 'P')
            return DOOR;
        return (var->map[row][col] == '1'
            || var->map[row][col] == '\0'
            || ft_isspace(var->map[row][col])
            || var->map[row - 1][col] == '1'
            || var->map[row - 1][col] == '\0'
            || ft_isspace(var->map[row - 1][col])
            ); 
    }
    if (var->map[row][col] == 'P')
        return DOOR;
    return (var->map[row][col] == '1'
        || var->map[row][col] == '\0'
        || ft_isspace(var->map[row][col])
        );
}
