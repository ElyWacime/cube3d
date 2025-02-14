#include "../cube.h"

float next_px_in_grid(float p, int d)
{
    int a;

    a = (int)(p / SQUARE_SIZE);
    if (p - (SQUARE_SIZE * a) == 0)
    {
        if (d == 1)
            return (a + 1) * SQUARE_SIZE;
        else 
            return (a - 1) * SQUARE_SIZE;
    }
    else
    {
        if (d == 1)
            return (a + 1) * SQUARE_SIZE;
        else 
            return SQUARE_SIZE * a; 
    }
}

int check_if_wall_h(t_point start, t_point direction, t_var *var)
{
    int row;
    int col;

    row = px_to_map_grid((t_uint)start.y) - (direction.y == -1);
    col = px_to_map_grid((t_uint)start.x);
    if (0 <= row && row < str_double_len(var->map) && 0 <= col && col < (float)ft_strlen(var->map[row]))
    {   
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
    return 1;
}

int check_if_wall_v(t_point start, t_point direction, t_var *var)
{
    int row;
    int col;

    row = px_to_map_grid((t_uint)start.y);
    col = px_to_map_grid((t_uint)start.x) - (direction.x == -1);
    if (0 <= row && row < str_double_len(var->map) && 0 <= col && col < (float)ft_strlen(var->map[row]))
    {   
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
    return 1;
}

t_point fill_cast_vertical(t_var *var,t_ray *ray,cast_v *cst_v)
{
    cst_v->colison.x = ray->start.x;
    cst_v->colison.y = ray->start.y;
    ray->wall_or_door_v = 0;
    cst_v->tn = tan_0_90(ray->angle);
    if (ray->direction_y == -1)
    {
        cst_v->colison.x = next_px_in_grid(ray->start.x,ray->direction_x);
        cst_v->colison.y = ray->start.y - (fabs(cst_v->colison.x-ray->start.x) * cst_v->tn);
        cst_v->skip_x = SQUARE_SIZE *  ray->direction_x;
        cst_v->skip_y = - SQUARE_SIZE * cst_v->tn;
    }
    else
    {
        cst_v->colison.x = next_px_in_grid(ray->start.x,ray->direction_x);
        cst_v->colison.y = ray->start.y + ((ray->direction_y * fabs(cst_v->colison.x - ray->start.x)) / cst_v->tn);
        cst_v->skip_x = SQUARE_SIZE *  ray->direction_x;
        cst_v->skip_y = SQUARE_SIZE / cst_v->tn;
    }
}

t_point cast_vertical(t_var *var,t_ray *ray)
{
    cast_v cst_v;

    fill_cast_vertical(var,ray,&cst_v);
    while (((0 <= cst_v.colison.x && 0 <= cst_v.colison.y) && ((cst_v.colison.x < WIDTH  && cst_v.colison.y < HEIGHT) || (cst_v.colison.x < var->mini_width  && cst_v.colison.y < var->mini_height))))
    {   
        if (check_if_wall_v(cst_v.colison, ray->direction, var))
        {
            ray->wall_or_door_v = check_if_wall_v(cst_v.colison, ray->direction, var);
            return cst_v.colison;
        }
        cst_v.colison.x += cst_v.skip_x;
        cst_v.colison.y += cst_v.skip_y;
    }
    return cst_v.colison;
}

t_point fill_cast_horizantal(t_var *var,t_ray *ray,cast_h *cst_h)
{
    ray->wall_or_door_h = 0;
    cst_h->colison.x = ray->start.x;
    cst_h->colison.y = ray->start.y;
    cst_h->tn = tan_0_90(ray->angle);
    if (ray->direction_y == -1)
    {
        cst_h->horizon.y = ray->start.y;
        cst_h->colison.y = next_px_in_grid(ray->start.y, ray->direction_y);
        cst_h->colison.x = ray->start.x + (ray->direction_x * ((fabs(cst_h->horizon.y - cst_h->colison.y) / cst_h->tn)));
        cst_h->horizon.x = cst_h->colison.x;
        cst_h->skip_x = (SQUARE_SIZE / cst_h->tn) * ray->direction_x;
        cst_h->skip_y = SQUARE_SIZE * ray->direction_y;
    }
    else
    {
        cst_h->horizon.y = next_px_in_grid(ray->start.y, ray->direction_y);
        cst_h->colison.y = cst_h->horizon.y;
        cst_h->horizon.x = ray->start.x;
        cst_h->colison.x = ray->start.x + (fabs(ray->start.y - cst_h->horizon.y) * cst_h->tn * ray->direction_x);
        cst_h->skip_x = (SQUARE_SIZE * cst_h->tn) * ray->direction_x;
        cst_h->skip_y = SQUARE_SIZE * ray->direction_y;
    }
}

t_point cast_horizantal(t_var *var,t_ray *ray)
{
    cast_h cst_h;

    fill_cast_horizantal(var, ray, &cst_h);
    while (((0 <= cst_h.colison.x && 0 <= cst_h.colison.y) && ((cst_h.colison.x < var->mini_width  && cst_h.colison.y < var->mini_height))))
    {   
        if (check_if_wall_h(cst_h.colison, ray->direction, var))
        {
            ray->wall_or_door_h = check_if_wall_h(cst_h.colison, ray->direction, var);
            return cst_h.colison;
        }
        cst_h.colison.x += cst_h.skip_x;
        cst_h.colison.y += cst_h.skip_y;
    }
    return cst_h.colison;
}

void fill_set_direciton(t_ray *ray)
{
    ray->direction_x = 1;
    ray->direction_y = 1;
    ray->angle = my_fmod(ray->angle, 360);
    ray->angle += 360;
    ray->angle = my_fmod(ray->angle,360);
}

void set_direciton(t_ray *ray)
{
    fill_set_direciton(ray);
    if (0 < ray->angle  && ray->angle < 90)
        ray->direction_y = -1;
    else if (90 < ray->angle && ray->angle < 180)
    {
        ray->direction_x = -1;
        ray->direction_y = -1;
    }
    else if (180 < ray->angle  && ray->angle < 270)
        ray->direction_x = -1;
    else if (ray->angle <= 270)
    {
        ray->direction_x = 0;
        ray->direction_y = 0;
        if (ray->angle == 0)
            ray->direction_x = 1;
        else if (ray->angle == 270)
            ray->direction_y = 1;
        else if (ray->angle == 90)
            ray->direction_y = -1;
        else if (ray->angle == 180)
            ray->direction_x = -1;
    }
}

void cast_v_h(t_var *var, t_ray *ray,t_cords *cor)
{
    cor->is_collision_horizontal = 1;
    ray->wall_or_door = 0;
    if (ray->direction_x == 0)
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
    else if (ray->direction_y == 0)
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
    else
    {
        cor->colision_h = cast_horizantal(var,ray);
        cor->colision_v = cast_vertical(var,ray);
        cor->distance_v = distance_squared(ray->start, cor->colision_v);
        cor->distance_h = distance_squared(ray->start, cor->colision_h);
        cor->h  = cor->distance_v;
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

void one_ray_wall(t_var *var, t_ray *ray)
{
    t_cords cor;
    t_ray_wall ra_wl;

    set_direciton(ray);
    cor.line.ax = ray->start.x;
    cor.line.ay = ray->start.y;
    cor.line.bx = ray->target.x;
    cor.line.by = ray->target.y;
    ray->direction.x = ray->direction_x;
    ray->direction.y = ray->direction_y;
    ra_wl.distance_to_projection = HEIGHT / (tan(from_deg_to_rad(VIEW/2)));
    cast_v_h(var ,ray, &cor);
    cor.h = sqrt(cor.h);
    ra_wl.distance_correction = cor.h;
    ra_wl.distance_correction *= cos(from_deg_to_rad(ray->angle - var->player.angle));
    ra_wl.wall_projection_height = (ra_wl.distance_to_projection * CUBE_SIZE) / (ra_wl.distance_correction);
    ra_wl.a = ((HEIGHT - ra_wl.wall_projection_height) / 2);
    ra_wl.correct_a = -ra_wl.a * (ra_wl.a <= 0);
    ra_wl.a *= (ra_wl.a > 0);
    if(var->img_3d)
    {
        ra_wl.idx = var->x_3d;
        ra_wl.idy = ra_wl.a;
        if (ray->wall_or_door != DOOR)
        {
            if (ray->textures_index == 0)
            {
                ra_wl.ofssetx = (((my_fmod(cor.colision_v.y,CUBE_SIZE)) * var->east->width)) / CUBE_SIZE;
                if (ra_wl.correct_a > 0)
                    ra_wl.image_offset = (ra_wl.correct_a * var->east->width) / (ra_wl.wall_projection_height);
            }
            else if (ray->textures_index == 1)
            {
                ra_wl.ofssetx = (((my_fmod(cor.colision_h.x,CUBE_SIZE)) * var->north->width)) / CUBE_SIZE;
                if (ra_wl.correct_a > 0)
                    ra_wl.image_offset = (ra_wl.correct_a  / (ra_wl.wall_projection_height))  * var->north->width ;
            }
            else if (ray->textures_index == 2)
            {
                ra_wl.ofssetx = (((CUBE_SIZE - my_fmod(cor.colision_v.y,CUBE_SIZE)) * var->west->width)) / CUBE_SIZE;
                if (ra_wl.correct_a > 0)
                    ra_wl.image_offset = (ra_wl.correct_a * var->west->height) / (ra_wl.wall_projection_height);
            }
            else if (ray->textures_index == 3)
            {
                ra_wl.ofssetx = (((CUBE_SIZE - my_fmod(cor.colision_h.x,CUBE_SIZE)) * var->south->width)) / CUBE_SIZE;
                if (ra_wl.correct_a > 0)
                    ra_wl.image_offset = (ra_wl.correct_a * var->south->height) / (ra_wl.wall_projection_height);
            }
        }
        else
        {
            if (ray->textures_index == 0)
            {
                ra_wl.ofssetx = (((my_fmod(cor.colision_v.y,CUBE_SIZE)) * var->door->width)) / CUBE_SIZE;
                if (ra_wl.correct_a > 0)
                    ra_wl.image_offset = (ra_wl.correct_a * var->door->width) / (ra_wl.wall_projection_height);
            }
            else if (ray->textures_index == 1)
            {
                ra_wl.ofssetx = (((my_fmod(cor.colision_h.x,CUBE_SIZE)) * var->door->width)) / CUBE_SIZE;
                if (ra_wl.correct_a > 0)
                    ra_wl.image_offset = (ra_wl.correct_a  / (ra_wl.wall_projection_height))  * var->door->width ;
            }
            else if (ray->textures_index == 2)
            {
                ra_wl.ofssetx = (((CUBE_SIZE - my_fmod(cor.colision_v.y,CUBE_SIZE)) * var->door->width)) / CUBE_SIZE;
                if (ra_wl.correct_a > 0)
                    ra_wl.image_offset = (ra_wl.correct_a * var->door->height) / (ra_wl.wall_projection_height);
            }
            else if (ray->textures_index == 3)
            {
                ra_wl.ofssetx = (((CUBE_SIZE - my_fmod(cor.colision_h.x,CUBE_SIZE)) * var->door->width)) / CUBE_SIZE;
                if (ra_wl.correct_a > 0)
                    ra_wl.image_offset = (ra_wl.correct_a * var->door->height) / (ra_wl.wall_projection_height);
            } 
        }
        
        while (ra_wl.idy < HEIGHT - ra_wl.a)
        {
            if (0 <= ra_wl.idx && ra_wl.idx  < WIDTH &&  0 <= ra_wl.idy && ra_wl.idy < HEIGHT)
            {
                if (ra_wl.idx < 100 && ra_wl.idy < 100)
                {
                    ++(ra_wl.idy);
                    continue;
                }
                if (ray->wall_or_door != DOOR)
                {   
                    if (ray->textures_index == 0)
                        mlx_put_pixel(var->img_3d, ra_wl.idx, ra_wl.idy,east_textures(var,&ra_wl,ra_wl.ofssetx));
                    else if (ray->textures_index == 1)
                        mlx_put_pixel(var->img_3d, ra_wl.idx, ra_wl.idy,north_textures(var,&ra_wl,ra_wl.ofssetx));
                    else if (ray->textures_index == 2)
                        mlx_put_pixel(var->img_3d, ra_wl.idx, ra_wl.idy,west_textures(var,&ra_wl,ra_wl.ofssetx));
                    else if (ray->textures_index == 3)
                        mlx_put_pixel(var->img_3d, ra_wl.idx, ra_wl.idy,south_textures(var,&ra_wl,ra_wl.ofssetx));
                }
                else
                        mlx_put_pixel(var->img_3d, ra_wl.idx, ra_wl.idy,door_textures_v(var,&ra_wl,ra_wl.ofssetx));
            }
            else 
                break;
            ++(ra_wl.idy); 
        }
        ++var->x_3d;
    }
}

void fill_cast(t_var *var,t_cast *cst)
{
    cst->step = (1.0 * VIEW ) / WIDTH;
    cst->angle = my_fmod(var->player.angle,360);
    cst->p.x = var->player.position.x;
    cst->p.y = var->player.position.y;
    cst->v.x = var->player.vect[0];
    cst->v.y = var->player.vect[1];
    cst->ray.start = cst->p;
    cst->ray.target = cst->v;
    cst->r = rotate_by(cst->ray.start, cst->v, - from_deg_to_rad(VIEW / 2));
    cst->ray.angle = cst->angle + (VIEW / 2);
    cst->ray.angle = my_fmod(cst->ray.angle , 360);
    cst->i = 0;
    var->x_3d = 0;
    var->y_3d = 0;
}

void cast(t_var *var)
{
    t_cast cst;
    
    fill_cast(var, &cst);
    while (cst.i < WIDTH)
    {
        var->player.angle = my_fmod(var->player.angle,360);
        cst.ray.target = cst.r;
        cst.ray.angle = cst.ray.angle + 360 - (cst.step);
        cst.ray.angle = my_fmod(cst.ray.angle , 360);
        one_ray_wall(var,&cst.ray);
        cst.r = rotate_by(cst.p, cst.r, from_deg_to_rad(cst.step));
        ++cst.i;
    }
    cst.ray.target.x = var->player.vect[0];
    cst.ray.target.y = var->player.vect[1];
}

float cast_one_ray_for_movement(t_var var, t_ray *ray)
{
    t_cords cor;

    cor.line.ax = ray->start.x;
    cor.line.ay = ray->start.y;
    cor.line.bx = ray->target.x;
    cor.line.by = ray->target.y;
    ray->direction.x = ray->direction_x;
    ray->direction.y = ray->direction_y;
    cast_v_h(&var ,ray, &cor);
    cor.h = sqrt(cor.h);
    return cor.h;
}
