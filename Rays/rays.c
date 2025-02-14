#include "../cube.h"

void fill_cast_vh_2_0(t_var *var, t_ray *ray,t_cords *cor)
{
    cor->colision_h = cast_horizantal(var,ray);
    cor->colision_v = cast_vertical(var,ray);
    cor->distance_v = distance_squared(ray->start, cor->colision_v);
    cor->distance_h = distance_squared(ray->start, cor->colision_h);
    cor->h = cor->distance_v;
}

void fill_cast_vh_2(t_var *var, t_ray *ray,t_cords *cor)
{
    fill_cast_vh_2_0(var, ray,cor);
    if (cor->distance_v < cor->distance_h)
    {
        if (ray->wall_or_door_v == DOOR)
            ray->wall_or_door = DOOR;
        cor->is_collision_horizontal = 0;
        cor->line.bx = cor->colision_v.x;
        cor->line.by = cor->colision_v.y;
    }
    else if (cor->distance_h < cor->distance_v)
    {
        if (ray->wall_or_door_h == DOOR)
            ray->wall_or_door = DOOR;   
        cor->h  = cor->distance_h;
        ray->angle = my_fmod(ray->angle,360);
        cor->line.by = cor->colision_h.y;
        cor->line.bx = cor->colision_h.x;
    }
    else
    {
        cor->line.bx = cor->colision_v.x;
        cor->line.by = cor->colision_v.y;
    }
}

void fill_cast_vh_1(t_var *var, t_ray *ray,t_cords *cor)
{
        cor->colision_v = cast_horizantal(var,ray);
        if (ray->wall_or_door_h == DOOR)
            ray->wall_or_door = DOOR;
        if (ray->angle == 90)
            ray->textures_index = 1;
        else
            ray->textures_index = 3;
        cor->h  = cor->distance_v;
        cor->line.bx = cor->colision_v.x;
        cor->line.by = cor->colision_v.y;
}

void fill_cast_vh_0(t_var *var, t_ray *ray,t_cords *cor)
{
        cor->is_collision_horizontal = 0;
        cor->colision_h = cast_vertical(var,ray);
        if (ray->wall_or_door_v == DOOR)
            ray->wall_or_door = DOOR;
        if (ray->angle == 0)
            ray->textures_index = 0;
        else
            ray->textures_index = 2;
        cor->h  = cor->distance_h;
        cor->line.by = cor->colision_h.y;
        cor->line.bx = cor->colision_h.x;
}

void cast_v_h(t_var *var, t_ray *ray,t_cords *cor)
{
    cor->is_collision_horizontal = 1;
    ray->wall_or_door = 0;
    if (ray->direction_x == 0)
        fill_cast_vh_0(var, ray, cor);
    else if (ray->direction_y == 0)
        fill_cast_vh_1(var, ray, cor);
    else
        fill_cast_vh_2(var, ray, cor);
    cor->distance_to_wall =  cor->h;
    if (cor->is_collision_horizontal == 0)
    {
        if ((270 < ray->angle && ray->angle < 360) ||
            (0 < ray->angle && ray->angle < 90))
            ray->textures_index = 0;
        else
            ray->textures_index = 2;
    }
    else
    {
        if (0 < ray->angle && ray->angle < 180)
            ray->textures_index = 1;
        else
            ray->textures_index = 3;
    }
}
