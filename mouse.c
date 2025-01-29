#include "cube.h"

void change_mouse_position(void* param) {
    t_var *var = (t_var*)param;
    int32_t prev_x = WIDTH / 2;
    int32_t mouse_x, mouse_y;
    const float rotation_speed = 0.001;
    const float speed = 2;

    if (!var || !var->mlx) return;

    mlx_set_cursor_mode(var->mlx, MLX_MOUSE_HIDDEN);

    mlx_get_mouse_pos(var->mlx, &mouse_x, &mouse_y);
    float delta_x = mouse_x - prev_x;

    // var->player.angle += delta_x * rotation_speed;
    if (delta_x > 0) rotate_player_right(var);
    else if (delta_x < 0) rotate_player_left(var);
    // printf("mousex = %d\n", mouse_x);
    // printf("mousey = %d\n", mouse_y);
    // printf("player angle = %f\n", var->player.angle);
    // var->player.angle = fmod(var->player.angle, 2 * PI);
    // if (var->player.angle < 0) var->player.angle += 2 * PI;

    // var->xdx = cos(var->player.angle) * speed;
    // var->ydy = sin(var->player.angle) * speed;

    mlx_set_mouse_pos(var->mlx, WIDTH/2, HEIGHT/2);
}

void mlx_mouse_func(mouse_key_t button, action_t action, modifier_key_t mods, void* param) {
    (void)button;
    // (void)action;
    (void)mods;
    printf("action = %d\n", action);
    change_mouse_position(param);
}