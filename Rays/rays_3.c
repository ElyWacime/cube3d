#include "../cube.h"

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
