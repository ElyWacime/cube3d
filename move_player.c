#include "cube.h"

int check_if_wall_up_movement(t_var *var, t_point new_position)
{
    if (var->player.angle >= 0 && var->player.angle < 90)
    {
        if (var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x + 1)] != '1'
            && var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x + 1)] != 'P')
            return 1;
    }
    else if (var->player.angle >= 90 && var->player.angle < 180)
    {
        if (var->map[px_to_map_grid(new_position.y - 1)][px_to_map_grid(new_position.x)] != '1'
            && var->map[px_to_map_grid(new_position.y - 1)][px_to_map_grid(new_position.x)] != 'P')
            return 1;
    }
    else if (var->player.angle >= 180 && var->player.angle < 270)
    {
        if (var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x - 1)] != '1'
            && var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x - 1)] != 'P')
            return 1;
    }
    else if (var->player.angle >= 270 && var->player.angle < 360)
    {
        if (var->map[px_to_map_grid(new_position.y + 1)][px_to_map_grid(new_position.x)] != '1'
            && var->map[px_to_map_grid(new_position.y + 1)][px_to_map_grid(new_position.x)] != 'P')
            return 1;
    }
    // else
    // {
    //     if (var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x)] != '1'
    //         && var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x)] != 'P')
    //         return 1;
    // }
    return 0;
}

int check_if_wall_down_movement(t_var *var, t_point new_position)
{
    if (var->player.angle >= 0 && var->player.angle < 90)
    {
        if (var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x - 1)] != '1'
            && var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x - 1)] != 'P')
            return 1;
    }
    else if (var->player.angle >= 90 && var->player.angle < 180)
    {
        if (var->map[px_to_map_grid(new_position.y + 1)][px_to_map_grid(new_position.x)] != '1'
            && var->map[px_to_map_grid(new_position.y + 1)][px_to_map_grid(new_position.x)] != 'P')
            return 1;
    }
    else if (var->player.angle >= 180 && var->player.angle < 270)
    {
        if (var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x + 1)] != '1'
            && var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x + 1)] != 'P')
            return 1;
    }
    else if (var->player.angle >= 270 && var->player.angle < 360)
    {
        if (var->map[px_to_map_grid(new_position.y - 1)][px_to_map_grid(new_position.x)] != '1'
            && var->map[px_to_map_grid(new_position.y - 1)][px_to_map_grid(new_position.x)] != 'P')
            return 1;
    }
    // else
    // {
    //     if (var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x)] != '1'
    //         && var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x)] != 'P')
    //         return 1;
    // }
    return 0;
}

int check_if_wall_left_movement(t_var *var, t_point new_position)
{
    if (var->player.angle >= 0 && var->player.angle < 90)
    {
        if (var->map[px_to_map_grid(new_position.y - 1)][px_to_map_grid(new_position.x)] != '1'
            && var->map[px_to_map_grid(new_position.y - 1)][px_to_map_grid(new_position.x)] != 'P')
            return 1;
    }
    else if (var->player.angle >= 90 && var->player.angle < 180)
    {
        if (var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x - 1)] != '1'
            && var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x - 1)] != 'P')
            return 1;
    }
    else if (var->player.angle >= 180 && var->player.angle < 270)
    {
        if (var->map[px_to_map_grid(new_position.y + 1)][px_to_map_grid(new_position.x)] != '1'
            && var->map[px_to_map_grid(new_position.y + 1)][px_to_map_grid(new_position.x)] != 'P')
            return 1;
    }
    else if (var->player.angle >= 270 && var->player.angle < 360)
    {
        if (var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x + 1)] != '1'
            && var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x + 1)] != 'P')
            return 1;
    }
    // else
    // {
    //     if (var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x)] != '1'
    //         && var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x)] != 'P')
    //         return 1;
    // }
    return 0;
}

int check_if_wall_right_movement(t_var *var, t_point new_position)
{
    if (var->player.angle >= 0 && var->player.angle < 90)
    {
        if (var->map[px_to_map_grid(new_position.y + 1)][px_to_map_grid(new_position.x)] != '1'
            && var->map[px_to_map_grid(new_position.y + 1)][px_to_map_grid(new_position.x)] != 'P')
            return 1;
    }
    else if (var->player.angle >= 90 && var->player.angle < 180)
    {
        if (var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x + 1)] != '1'
            && var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x + 1)] != 'P')
            return 1;
    }
    else if (var->player.angle >= 180 && var->player.angle < 270)
    {
        if (var->map[px_to_map_grid(new_position.y - 1)][px_to_map_grid(new_position.x)] != '1'
            && var->map[px_to_map_grid(new_position.y - 1)][px_to_map_grid(new_position.x)] != 'P')
            return 1;
    }
    else if (var->player.angle >= 270 && var->player.angle < 360)
    {
        if (var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x - 1)] != '1'
            && var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x - 1)] != 'P')
            return 1;
    }
    // else
    // {
    //     if (var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x)] != '1'
    //         && var->map[px_to_map_grid(new_position.y)][px_to_map_grid(new_position.x)] != 'P')
    //         return 1;
    // }
    return 0;
}

void    calcul_right_movement(t_var *var)
{
    t_point new_position;
    int cnt = -1;

    while (cnt++ <= 1)
    {
        new_position.x = (var->player.position.x + cnt)
            + (SPEED * sin(from_deg_to_rad(var->player.angle)));
        new_position.y = (var->player.position.y + cnt)
            + (SPEED * cos(from_deg_to_rad(var->player.angle)));
        if (!check_if_wall_right_movement(var, new_position))
            return ;
    }
    new_position.x = (var->player.position.x)
        + (SPEED * sin(from_deg_to_rad(var->player.angle)));
    new_position.y = (var->player.position.y)
        + (SPEED * cos(from_deg_to_rad(var->player.angle)));
    var->player.position.x = new_position.x;
    var->player.position.y = new_position.y;
}

void    calcul_left_movement(t_var *var)
{
    t_point new_position;
    int cnt = -1;

    while (cnt++ <= 1)
    {
        new_position.x = (var->player.position.x + cnt)
            - (SPEED * sin(from_deg_to_rad(var->player.angle)));
        new_position.y = (var->player.position.y + cnt)
            - (SPEED * cos(from_deg_to_rad(var->player.angle)));
        if (!check_if_wall_left_movement(var, new_position))
            return ;
    }
    new_position.x = (var->player.position.x)
        - (SPEED * sin(from_deg_to_rad(var->player.angle)));
    new_position.y = (var->player.position.y)
        - (SPEED * cos(from_deg_to_rad(var->player.angle)));
    if (new_position.y <= 0 || new_position.x <= 0)
        return ;
    var->player.position.x = new_position.x;
    var->player.position.y = new_position.y;
}

void    calcul_up_movement(t_var *var)
{
    t_point new_position;
    int cnt = -1;
    
    while (cnt++ <= 1)
    {
        new_position.x = (var->player.position.x + cnt)
            + (SPEED * cos(from_deg_to_rad(var->player.angle)));
        new_position.y = (var->player.position.y + cnt)
            - (SPEED * sin(from_deg_to_rad(var->player.angle)));
        if (new_position.y <= 0)
            return ;
        if (!check_if_wall_up_movement(var, new_position))
            return ;
    }
    new_position.x = (var->player.position.x)
        + (SPEED * cos(from_deg_to_rad(var->player.angle)));
    new_position.y = (var->player.position.y)
        - (SPEED * sin(from_deg_to_rad(var->player.angle)));
    if (new_position.y <= 0)
        return ;
    var->player.position.x = new_position.x;
    var->player.position.y = new_position.y;
}

void    calcul_down_movement(t_var *var)
{
    t_point new_position;
    int cnt = -1;

    while (cnt++ <= 1)
    {
        new_position.x = (var->player.position.x + cnt)
            - (SPEED * cos(from_deg_to_rad(var->player.angle)));
        new_position.y = (var->player.position.y + cnt)
            + (SPEED * sin(from_deg_to_rad(var->player.angle)));
        if (new_position.x <= 0)
            return ;
        if (!check_if_wall_down_movement(var, new_position))
            return ;
    }
    new_position.x = (var->player.position.x)
        - (SPEED * cos(from_deg_to_rad(var->player.angle)));
    new_position.y = (var->player.position.y)
        + (SPEED * sin(from_deg_to_rad(var->player.angle)));
    if (new_position.x <= 0)
        return ;
    var->player.position.x = new_position.x;
    var->player.position.y = new_position.y;
}

void    move_player_down(t_var *var)
{
    calcul_down_movement(var);
    init_img3d(var);
    cast(var);
    init_mini_map_system(var);
    // draw_gun(var);
    //mlx_image_to_window(var->mlx, var->gunPreFireImg, (WIDTH / 2) - var->gunFire->width, HEIGHT - var->gunFire->height * 2);
    //mlx_image_to_window(var->mlx, var->gunFireImg, (WIDTH / 2) - var->gunPreFire->width, HEIGHT - var->gunPreFire->height * 2);
}

void    move_player_up(t_var *var)
{
    calcul_up_movement(var);
    init_img3d(var);
    cast(var);
    init_mini_map_system(var);
    // draw_gun(var);
    //mlx_image_to_window(var->mlx, var->gunPreFireImg, (WIDTH / 2) - var->gunFire->width, HEIGHT - var->gunFire->height * 2);
    //mlx_image_to_window(var->mlx, var->gunFireImg, (WIDTH / 2) - var->gunPreFire->width, HEIGHT - var->gunPreFire->height * 2);
}

void    move_player_right(t_var *var)
{
    calcul_right_movement(var);
    init_img3d(var);
    cast(var);
    init_mini_map_system(var);
    // draw_gun(var);
    //mlx_image_to_window(var->mlx, var->gunPreFireImg, (WIDTH / 2) - var->gunFire->width, HEIGHT - var->gunFire->height * 2);
    //mlx_image_to_window(var->mlx, var->gunFireImg, (WIDTH / 2) - var->gunPreFire->width, HEIGHT - var->gunPreFire->height * 2);
}

void    move_player_left(t_var *var)
{
    calcul_left_movement(var);
    init_img3d(var);
    cast(var);
    init_mini_map_system(var);
    // draw_gun(var);
    //mlx_image_to_window(var->mlx, var->gunPreFireImg, (WIDTH / 2) - var->gunFire->width, HEIGHT - var->gunFire->height * 2);
    //mlx_image_to_window(var->mlx, var->gunFireImg, (WIDTH / 2) - var->gunPreFire->width, HEIGHT - var->gunPreFire->height * 2);

}
