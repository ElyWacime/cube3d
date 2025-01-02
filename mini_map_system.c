#include "cube.h"

#define MAP_WIDTH 27
#define MAP_HEIGHT 13
#define MINI_MAP_SIZE 100
#define TILE_SIZE (MINI_MAP_SIZE / MAP_WIDTH)
#define VIEW_RADIUS 50

void init_mini_map_system(t_var *var)
{
    t_point start;
    t_point end;
    t_uint  map_x = 0;
    t_uint map_y = 0;
    t_uint mini_width = calculate_mini_map_width(var);
    t_uint mini_height = strlen_double((void **)var->map);

    if (var->player.position[0] - 50 > 0)
        start.x = var->player.position[0] - 50;
    else
        start.x = 0;
    if (var->player.position[1] - 50 > 0)
        start.y = var->player.position[1] - 50;
    else
        start.y = 0;
    if (var->player.position[0] + 50 > mini_width)
        end.x = var->player.position[0] + 50;
    else
        end.x = mini_width;
    if (var->player.position[1] + 50 > mini_height)
        end.y = var->player.position[1] + 50;
    else
        end.y = mini_height;
    t_uint i = (t_uint)start.x, j = (t_uint)start.y;
    printf("start.x = %f\tstart.y = %f\tend.x = %f\tend.y = %f\n", start.x, start.y, end.x, end.y);
    printf("palyer[0] = %f\tplayer[1] = %f\n", var->player.position[0], var->player.position[1]);
    printf("%u\t%u\n", px_to_map_grid(end.x), px_to_map_grid(end.y));
    while (j++ < end.y && map_y < 100)
    {
        i = start.x;
        while (i++ < end.x && map_x < 100)
        {
            printf("#####################################\n");
            printf("start.x = %f\tstart.y = %f\tend.x = %f\tend.y = %f\n", start.x, start.y, end.x, end.y);
            printf("palyer[0] = %f\tplayer[1] = %f\n", var->player.position[0], var->player.position[1]);
            printf("i = %u\tj = %u\t\ti.to.px = %u\tj.to.px = %u\n", i, j, px_to_map_grid(i), px_to_map_grid(j));
            printf("%u\t%u\n", px_to_map_grid(end.x), px_to_map_grid(end.y));
            if (var->map[px_to_map_grid(j)][px_to_map_grid(i)] != '1')
                mlx_put_pixel(var->img_3d, map_x, map_y, 0x000000FF);
            else
                mlx_put_pixel(var->img_3d, map_x, map_y, 0xFFFFFFFF);
            map_x++;
        }
        map_y++;
    }
}

// void draw_mini_map(t_var *var, int player_x, int player_y)
// {
//     int start_x = player_x - VIEW_RADIUS / TILE_SIZE;
//     int start_y = player_y - VIEW_RADIUS / TILE_SIZE;
//     int end_x = player_x + VIEW_RADIUS / TILE_SIZE;
//     int end_y = player_y + VIEW_RADIUS / TILE_SIZE;

//     for (int i = start_y; i <= end_y; i++)
//     {
//         for (int j = start_x; j <= end_x; j++)
//         {
//             if (i >= 0 && i < MAP_HEIGHT && j >= 0 && j < MAP_WIDTH)
//             {
//                 int color = (var->map[i][j] == '1') ? 0xFFFFFFFF : 0x000000FF;
//                 if (var->map[i][j] == 'N')
//                 {
//                     player_x = j;
//                     player_y = i;
//                 }
//                 int x = (j - start_x) * TILE_SIZE;
//                 int y = (i - start_y) * TILE_SIZE;
//                 for (int ty = 0; ty < TILE_SIZE; ty++)
//                 {
//                     for (int tx = 0; tx < TILE_SIZE; tx++)
//                     {
//                         mlx_put_pixel(var->img_3d, x + tx, y + ty, color);
//                     }
//                 }
//             }
//         }
//     }
//     // Draw player position
//     int player_map_x = (player_x - start_x) * TILE_SIZE + TILE_SIZE / 2;
//     int player_map_y = (player_y - start_y) * TILE_SIZE + TILE_SIZE / 2;
//     for (int ty = -2; ty <= 2; ty++)
//     {
//         for (int tx = -2; tx <= 2; tx++)
//         {
//             mlx_put_pixel(var->img_3d, player_map_x + tx, player_map_y + ty, 0xFF0000FF);
//         }
//     }
// }



// void init_mini_map_system(t_var *var)
// {
//     // Initialize the mini-map with the player's initial position
//     int player_x = 0, player_y = 0;
//     // Find the initial player position
//     for (int i = 0; i < MAP_HEIGHT; i++)
//     {
//         for (int j = 0; j < MAP_WIDTH; j++)
//         {
//             if (var->map[i][j] == 'N')
//             {
//                 player_x = j;
//                 player_y = i;
//                 break;
//             }
//         }
//     }
//     draw_mini_map(var, var->player.position[0], var->player.position[1]);
// }