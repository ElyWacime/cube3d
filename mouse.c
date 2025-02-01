#include "cube.h"

void mlx_mouse_func(double xpos, double ypos, void* param) {
    t_var *var = (t_var*)param;
    int32_t prev_x = WIDTH / 2;
    int32_t prev_y = HEIGHT / 2;
    int32_t mouse_x, mouse_y;
    const float rotation_speed = 0.001;

    mlx_set_cursor_mode(((t_var *)param)->mlx, MLX_MOUSE_HIDDEN);
    if (!var || !var->mlx)
        return;
    mlx_get_mouse_pos(var->mlx, &mouse_x, &mouse_y);
    float delta_x = mouse_x - prev_x;
    if (delta_x > 0)
        rotate_player_right(var);
    else if (delta_x < 0)
        rotate_player_left(var);
    mlx_set_mouse_pos(var->mlx, prev_x, prev_y);
    // prev_x = mouse_x;
    // prev_y = mouse_y;
    // printf("mouse position x = %d\tmouse position y = %d\n", mouse_x, mouse_y);
}