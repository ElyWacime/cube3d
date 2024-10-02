#include "cube.h"

void    rotate_player_left(t_var *var)
{
    (void)var;
}

void    rotate_player_right(t_var *var)
{
    (void)var;
}

void    listen_to_key(struct mlx_key_data keydata, void *ptr)
{
    t_var *var;
    
    var = (t_var *)ptr;
	if (keydata.key == MLX_KEY_W
        && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
        // move_player_up(var);
	if (keydata.key == MLX_KEY_A
        && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		// move_player_left(var);
	if (keydata.key == MLX_KEY_D
        && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		// move_player_right(var);
	if (keydata.key == MLX_KEY_S
        && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		// move_player_down(var);
    if (keydata.key == MLX_KEY_LEFT
        && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
        rotate_player_left(var);
    if (keydata.key == MLX_KEY_RIGHT
        && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
        rotate_player_right(var);
}

// void    color_player_movement(double *tracker, t_var *var, int color)
// {
//     t_uint i;
//     t_uint j;

//     i = (t_uint)tracker[1];
//     while (i <= (t_uint)tracker[1] + 32 && i < var->mini_height)
//     {
//         j = (t_uint)tracker[0];
//         while (j <= (t_uint)tracker[0] + 32 && j < var->mini_width)
//         {
//             if (i >= ((t_uint)tracker[1]) && i < (t_uint)tracker[1] + 32 / 8
//                 && j >= (t_uint)tracker[0] && j < (t_uint)tracker[0] + 32 / 8)
//                 mlx_put_pixel(var->mini_map, j, i, color);
//             j++;
//         }
//         i++;
//     }
// }

// int check_if_player_hits_wall(t_var *var)
// {
//     int x_positon;
//     int y_position;

//     x_positon = px_to_map_grid((t_uint)var->player_position[0]);
//     y_position = px_to_map_grid((t_uint)var->player_position[1]);
//     return (var->map[y_position][x_positon] == '1');
// }

// void    move_player_up(t_var *var)
// {
//     color_player_movement(var->player_position, var, 0xFF00FFFF);
//     var->player_position[1] -= 4.0;
//     if (check_if_player_hits_wall(var))
//     {
//         var->player_position[1] += 4.0;
//         color_player_movement(var->player_position, var, 0x000000FF);
//         return ;
//     }
//     color_player_movement(var->player_position, var, 0x000000FF);
// }

// void    move_player_down(t_var *var)
// {
//     color_player_movement(var->player_position, var, 0xFF00FFFF);
//     var->player_position[1] += 4.0;
//     if (check_if_player_hits_wall(var))
//     {
//         var->player_position[1] -= 4.0;
//         color_player_movement(var->player_position, var, 0x000000FF);
//         return ;
//     }
//     color_player_movement(var->player_position, var, 0x000000FF);
// }

// void    move_player_left(t_var *var)
// {
//     color_player_movement(var->player_position, var, 0xFF00FFFF);
//     var->player_position[0] -= 4.0;
//     if (check_if_player_hits_wall(var))
//     {
//         var->player_position[0] += 4.0;
//         color_player_movement(var->player_position, var, 0x000000FF);
//         return ;
//     }
//     color_player_movement(var->player_position, var, 0x000000FF);
// }

// void    move_player_right(t_var *var)
// {
//     color_player_movement(var->player_position, var, 0xFF00FFFF);
//     var->player_position[0] += 4.0;
//     if (check_if_player_hits_wall(var))
//     {
//         var->player_position[0] -= 4.0;
//         color_player_movement(var->player_position, var, 0x000000FF);
//         return ;
//     }
//     color_player_movement(var->player_position, var, 0x000000FF);
// }

// void    draw_direction_line(double *point_position, t_var *var, t_uint color)
// {
//     double distance;
//     double x;
//     double y;

//     distance = calculate_distance(point_position[0], point_position[1],
//         var->player_position[0], var->player_position[1]);
//     x = var->player_position[1];
//     y = var->player_position[0];
//     while (x < var->player_position[1] + 50 && y < var->player_position[0] + 70)
//     {
//         printf("%u\t%u\n", (t_uint)x, (t_uint)y);
//         mlx_put_pixel(var->mini_map, (t_uint)y,(t_uint)x, color);
//         y += 70 / distance;
//         x += 50 / distance;
//     }
// }

// void    get_point_position_to_draw_diraction(t_var *var, t_uint color)
// {
//     double  point_position[2];
//     if (var->player_direction == 'N')
//     {
//         point_position[0] = var->player_position[0];
//         point_position[1] = var->player_position[1] + 50;
//     }
//     else if (var->player_direction == 'S')
//     {
//         point_position[0] = var->player_position[0];
//         point_position[1] = var->player_position[1] - 50;
//         if (point_position[1] < 0)
//             point_position[1] = 0;
//     }
//     else if (var->player_direction == 'E')
//     {
//         point_position[0] = var->player_position[0] + 50;
//         point_position[1] = var->player_position[1];

//     }
//     else if (var->player_direction == "W")
//     {
//         point_position[0] = var->player_position[0] - 50;
//         point_position[1] = var->player_position[1];
//         if (point_position[0] < 0)
//             point_position[0] = 0;
//     }
//     draw_direction_line(point_position, var, color);
// }

// void rotate_player_left(t_var *var)
// {
//     (void)var;
// }

// void    rotate_player_right(t_var *var)
// {
//     (void)var;

// }
