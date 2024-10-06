#include "cube.h"

int    draw_line3(t_line line, t_var *var)
{
    double a;
    double b;
    double a_prime = (line.ay  - line.by);
    double a_seconde = (line.ax  - line.bx);
    double i  = -1;

    a = a_prime / a_seconde;
    b = line.ay - ((a_prime * line.ax) / a_seconde);
    printf("f(x) = %fx + %f\n",a,b);
    printf("A (%f , %f) B( %f  , %f) \n",line.ax , line.ay,line.bx , line.by);
    if (line.ax == line.bx)
    {
        if (line.ay < line.by)
            i = 1;
        // while (((i == 1 && line.ay < line.by) || (i == -1 && line.by < line.ay)) && ((0 <= line.ax && line.ax < var->mini_width && 0 <= line.ay && line.ay < var->mini_height)))
        while ((0 <= line.ax && line.ax < var->mini_width && 0 <= line.ay && line.ay < var->mini_height))
        {
            mlx_put_pixel(var->mini_map, (t_uint)line.ax, (t_uint)line.ay, 0xFF0000FF);
            line.ay+=i;
        }
        i = 0;
    }
    else
    {
        if (line.ax < line.bx)
            i = 1;
        // ((i == 1 && line.ax < line.bx) || (i == -1 && line.bx < line.ax)) && 
        while ((0 <= line.ax && line.ax < var->mini_width && 0 <= line.ay && line.ay < var->mini_height))
        {
            mlx_put_pixel(var->mini_map, (t_uint)line.ax, (t_uint)line.ay, 0xFF0000FF);
            line.ax+=i;
            line.ay = (line.ax * a) + b;
        }
    }
    return 0;
}

void    draw_line4(t_line line, t_var *var, t_uint color)
{
    double distance;
    double x;
    double y;


    distance = calculate_distance(line.ax, line.ay, line.bx, line.by);
    x = line.ax;
    y = line.ay;
    if (x <= line.bx && y <= line.by)
    {
        while ((0 <= x && x < var->mini_width && 0 <= y && y < var->mini_height))
        {
            // if (check_if_wall(x, y, var))
                // break;
            mlx_put_pixel(var->mini_map, (t_uint)x, (t_uint)y, color);
            x += (fabs(line.bx - line.ax) / distance);
            y += (fabs(line.by - line.ay) / distance);
        }
    }
    else if (x >= line.bx && y <= line.by)
    {
        while ((0 <= x && x < var->mini_width && 0 <= y && y < var->mini_height))
        {
            // if (check_if_wall(x, y, var))
                // break;
            mlx_put_pixel(var->mini_map, (t_uint)x, (t_uint)y, color);
            x -= (fabs(line.bx - line.ax) / distance);
            y += (fabs(line.by - line.ay) / distance);
        }
    }
    else if (x >= line.bx && y >= line.by)
    {
        while ((0 <= x && x < var->mini_width && 0 <= y && y < var->mini_height))
        {
            // if (check_if_wall(x, y, var))
                // break;
            mlx_put_pixel(var->mini_map, (t_uint)x, (t_uint)y, color);
            x -= (fabs(line.bx - line.ax) / distance);
            y -= (fabs(line.by - line.ay) / distance);
        }
    }
    else if (x <= line.bx && y >= line.by)
    {
        while ((0 <= x && x < var->mini_width && 0 <= y && y < var->mini_height))
        {
            // if (check_if_wall(x, y, var))
                // break;
            mlx_put_pixel(var->mini_map, (t_uint)x, (t_uint)y, color);
            x += (fabs(line.bx - line.ax) / distance);
            y -= (fabs(line.by - line.ay) / distance);
        }
    }

}
void    draw_line5(t_line line, t_var *var, t_uint color)
{
    double distance;
    double x;
    double y;


    distance = calculate_distance(line.ax, line.ay, line.bx, line.by);
    x = line.ax;
    y = line.ay;
    if (x <= line.bx && y <= line.by)
    {
        while (x <= line.bx && y <= line.by && (0 <= x && x < var->mini_width && 0 <= y && y < var->mini_height))
        {
            // if (check_if_wall(x, y, var))
                // break;
            mlx_put_pixel(var->mini_map, (t_uint)x, (t_uint)y, color);
            x += (fabs(line.bx - line.ax) / distance);
            y += (fabs(line.by - line.ay) / distance);
        }
    }
    else if (x >= line.bx && y <= line.by)
    {
        while (x >= line.bx && y <= line.by && (0 <= x && x < var->mini_width && 0 <= y && y < var->mini_height))
        {
            // if (check_if_wall(x, y, var))
                // break;
            mlx_put_pixel(var->mini_map, (t_uint)x, (t_uint)y, color);
            x -= (fabs(line.bx - line.ax) / distance);
            y += (fabs(line.by - line.ay) / distance);
        }
    }
    else if (x >= line.bx && y >= line.by)
    {
        while (x >= line.bx && y >= line.by && (0 <= x && x < var->mini_width && 0 <= y && y < var->mini_height))
        {
            // if (check_if_wall(x, y, var))
                // break;
            mlx_put_pixel(var->mini_map, (t_uint)x, (t_uint)y, color);
            x -= (fabs(line.bx - line.ax) / distance);
            y -= (fabs(line.by - line.ay) / distance);
        }
    }
    else if (x <= line.bx && y >= line.by)
    {
        while (x <= line.bx && y >= line.by && (0 <= x && x < var->mini_width && 0 <= y && y < var->mini_height))
        {
            // if (check_if_wall(x, y, var))
                // break;
            mlx_put_pixel(var->mini_map, (t_uint)x, (t_uint)y, color);
            x += (fabs(line.bx - line.ax) / distance);
            y -= (fabs(line.by - line.ay) / distance);
        }
    }

}

// void cast_horizantal(t_var *var,t_ray direction,t_line line)
// {
//     double *p = var->player.position;
//     double ang = 30;
//     t_line line;
//     int i = 0;
//     double x = (fabs(p[1] - (px_to_map_grid(p[1])) * 32) * tan(from_deg_to_rad(ang))) + p[0];
//     double y = px_to_map_grid(p[1]) * 32;
//     double px = p[0];
//     double py = p[1];
//     // printf("x = %f %f\n", x, y);
//     // printf("px = %f %f\n", px, py);
//     // printf(">>>>>>>>>>>> CUrrent inter ::: %f %f\n\n\n", x,y);
//     double skip = 32 * tan(from_deg_to_rad(ang));
//     // double skip = 32 / tan(from_deg_to_rad(ang));
//     while (0 <= x && x < var->mini_width && 0 <= y && y < var->mini_height)
//     {
//         line.ax = px;
//         line.ay = py;
//         line.bx = x;
//         line.by = y;

//         draw_line4(line, var,0x00FFFFF0);
//         // if (draw_line3(line, var))
//         //     break;
//         px = x;
//         py = y;
//         // x = (32) * tan(from_deg_to_rad(ang)) + px;
//         x += skip;
//         y -= 32;
//         // printf(" Next ::; %f %f\n\n\n", x,y);
//     }
//     //  printf("-----------------\n\n\n");
// }

// void cast_vertical(t_var *var,t_ray direction,t_line line)
// {
//     double *p = var->player.position;
//     double ang = 30;
//     t_line line;
//     int i = 0;
//     double x = (px_to_map_grid(p[0]) + 1) * 32;
//     double y = (fabs(x - p[0]) * tan(from_deg_to_rad(ang))) + p[1];
//     double px = p[0];
//     double py = p[1];
//     // printf("x = %f %f\n", x, y);
//     // printf("px = %f %f\n", px, py);
//     // printf(">>>>>>>>>>>> CUrrent inter ::: %f %f\n\n\n", x,y);
//     // double skip = 32 * tan(from_deg_to_rad(ang));
//     double skip = 32 / tan(from_deg_to_rad(ang));
//     while (0 <= x && x < var->mini_width && 0 <= y && y < var->mini_height)
//     {
//         line.ax = px;
//         line.ay = py;
//         line.bx = x;
//         line.by = y;

//         draw_line4(line, var,0xFF00FFF0);
//         // if (draw_line3(line, var))
//         //     break;
//         px = x;
//         py = y;
//         x += 32;
//         y -= skip;
//         // printf(" Next ::; %f %f\n\n\n", x,y);
//     }
//     //  printf("-----------------\n\n\n");
// }

t_point cast_horizantal(t_var *var,t_ray ray,t_line line)
{
    t_point horizon;
    t_point colison;
    double distance;
    double skip;
    double tn;

    horizon.x = ((line.ax / 32) + (ray.direction_x > 0)) * 32;
    horizon.y = line.ay;
    colison.x = horizon.x;
    distance =  fabs(horizon.x - line.ax);
    tn = tan(ray.angle);
    colison.y = (distance * tn) + line.ay;
    skip = 32 * tn * ray.direction_y;

    while ((0 <= line.ax && line.ax < var->mini_width && 0 <= line.ay && line.ay < var->mini_height))
    {
        colison.x = line.ax;
        colison.y = line.ay;
        if (check_if_wall(line.ax, line.ay, var))
            return colison;
        line.ax += 32 * ray.direction_x;
        line.ay += skip;
    }
    return colison;
}

t_point cast_vertical(t_var *var,t_ray ray,t_line line)
{
    t_point horizon;
    t_point colison;
    double distance;
    double skip;
    double tn;

    horizon.x = ((line.ax / 32) + (ray.direction_x > 0)) * 32;
    horizon.y = line.ay;
    colison.x = horizon.x;
    distance =  fabs(horizon.x - line.ax);
    tn = tan(ray.angle);
    colison.y = (distance * tn) + line.ay;
    skip = (32 / tn) * ray.direction_x;

    while ((0 <= line.ax && line.ax < var->mini_width && 0 <= line.ay && line.ay < var->mini_height))
    {
        colison.x = line.ax;
        colison.y = line.ay;
        if (check_if_wall(line.ax, line.ay, var))
            return colison;
        line.ax += skip;
        line.ay += 32 * ray.direction_y;
    }
    return colison;
}

void  cast_up_(t_var *var)
{
    double *player = var->player.position;
    t_line line;
    double tmpbx;
    double tmpby;

    line.ax = player[0];
    line.ay = player[1];

    line.by = px_to_map_grid(player[1]) * 32;
    line.bx = (1 / tan(from_deg_to_rad(var->player.angle))) * (fabs(player[1] - line.by)) + player[0];
    
    tmpbx = line.ax;
    tmpby = line.by;

    while (1)
    {
        tmpby -= 32;
        tmpbx = (1 / tan(from_deg_to_rad(var->player.angle))) * (fabs(player[1] - tmpby)) + player[0];
        
        if (tmpbx > 0 && tmpbx < var->mini_width * 1.0
            && tmpby > 0 && tmpby < var->mini_height * 1.0)
        {
            line.by = tmpby;
            line.bx = tmpbx;
        }
        else
        {
            printf("break up\nmini width: %u\tmini height: %u\ntmpbx: %f\ttmpby: %f\n\n\n", var->mini_width, var->mini_height, tmpbx, tmpby);
            break;
        }
    }
    printf("ax = %f\tay = %f\nbx = %f\tby = %f\n\n\n", line.ax, line.ay, line.bx, line.by);
    draw_line(line, var, 0xFF0000FF);
}

void  cast_down_(t_var *var)
{
    double *player = var->player.position;
    t_line line;
    double tmpbx;
    double tmpby;
    line.ax = player[0];
    line.ay = player[1];
    line.by = px_to_map_grid(player[1]) * 32 + 32;
    line.bx = (-1 / tan(from_deg_to_rad(var->player.angle))) * (fabs(player[1] - line.by)) + player[0];
    tmpbx = line.ax;
    tmpby = line.by;
    while (1)
    {
        tmpby += 32;
        tmpbx = (-1 / tan(from_deg_to_rad(var->player.angle))) * (fabs(player[1] - tmpby)) + player[0];
        if (tmpbx > 0 && tmpbx < var->mini_width * 1.0
            && tmpby > 0 && tmpby < var->mini_height * 1.0)
        {
            line.by = tmpby;
            line.bx = tmpbx;
        }
        else
        {
            printf("break down\nmini width: %u\tmini height: %u\ntmpbx: %f\ttmpby: %f\nline.bx: %f\tline.by: %f\n\n\n\n", var->mini_width, var->mini_height, tmpbx, tmpby, line.bx, line.by);
            break;
        }
    }
    draw_line(line, var, 0xFF0000FF);
}

double mod(double a, int b)
{
    int x = (int)a;
    return (a - (double)x) + (double)(x % b);
}

//rotate a point m f rom center by an angle in radian
t_point rotate_by(t_point center, t_point m, double angle)
{
    t_point z;

    z.x = ((m.x - center.x)*cos(angle)) - ((m.y - center.y)*sin(angle)) + center.x;
    z.y = ((m.y - center.y)*cos(angle)) + ((m.x - center.x)*sin(angle)) + center.y;
    return z;
}

// maxim left and right rays
// void range(t_var *var)
// {
//     double vx = var->player.vect[0];
//     double vy = var->player.vect[1];
//     double px = var->player.position[0];
//     double py = var->player.position[1];
//     double thetha = var->player.angle % 360;
//     double rot = 30.0;
//     double cs = cos(from_deg_to_rad(rot));
//     double sn = sin(from_deg_to_rad(rot));
//     double vax = ((vx - px)*cs) - ((vy - py)*sn) + px;
//     double vay = ((vy - py)*cs) + ((vx - px)*sn) + py;
//     sn = -sn;
//     double vbx = ((vx - px)*cs) - ((vy - py)*sn) + px;
//     double vby = ((vy - py)*cs) + ((vx - px)*sn) + py;
//     // printf("P(%f     %f)\nV(%f    %f) \nVa(%f   %f) \nVb(%f   %f)\n",px,py,vx,vy,vax,vay,vbx,vby);
//     t_line line;
//     line.ax = px;
//     line.ay = py;
//     line.bx = vax;
//     line.by = vay;
//     // draw_line3(line,var);//RED +
//     draw_line4(line,var,0xFF0000FF);
//     line.bx = vbx;
//     line.by = vby;
//      draw_line4(line,var,0x0000FFFF);
//     // draw_line4(line,var);//BLUE - 
//     // printf("RED  +%f  \n" , rot);
//     // printf("BLUE  -%f \n",  rot);
// }

// maxim left and right rays
void range_2(t_var *var)
{
    t_point v;
    t_point p;
    t_point r;
    t_line line;
    double view;
    
    view = 60;
    v.x = var->player.vect[0];
    v.y = var->player.vect[1];
    p.x = var->player.position[0];
    p.y = var->player.position[1];
    r = rotate_by(p,v,from_deg_to_rad(view/2));//RED + RIGHT
    line.ax = p.x;
    line.ay = p.y;
    line.bx = r.x;
    line.by = r.y;
    draw_line4(line,var,0XA020F0A0);
    r = rotate_by(p,v,from_deg_to_rad(-view/2));//BLUE - LEFT
    line.bx = r.x;
    line.by = r.y;
    draw_line4(line,var,0XA020F0A0);
}


void one_ray(t_var *var, t_ray *ray ,unsigned int color)
{
    t_line line;

    line.ax = ray->start.x;
    line.ay = ray->start.y;
    line.bx = ray->target.x;
    line.by = ray->target.y;
    draw_line4(line,var,color);
}

// void one_ray_wall(t_var *var, t_ray ray ,unsigned int color)
// {
//     t_line line;
//     ray.direction_x = 1;
//     ray.direction_y = 1;
//     ray.angle += 360;
//     ray.angle = mod(ray.angle, 360);
//     printf("ray angle == %f\n",ray.angle);
//     printf("player angle == %u\n",var->player.angle);
//     if (0 < ray.angle  && ray.angle < 90)
//     {
//         ray.direction_y = -1;
//         printf("up right\n");
//     }
//     else if (90 < ray.angle && ray.angle < 180)
//     {
//         ray.direction_x = -1;
//         ray.direction_y = -1;
//         printf("up left\n");
//     }
//     else if (180 < ray.angle  && ray.angle < 270)
//     {
//         ray.direction_x = -1;
//         printf("down left\n");
//     }
//     else if (270 < ray.angle && ray.angle != 0)
//     {
//         printf(" down right\n");
//     }
//     else if (ray.angle == 0)
//     {
//         ray.direction_y = 0;
//         printf(" right\n");
//     }
//     else if (ray.angle == 90)
//     {
//         printf("up\n");
//         ray.direction_x = 0;
//         ray.direction_y = -1;
//     }
//     else if (ray.angle == 180)
//     {
//         ray.direction_x = -1;
//         ray.direction_y = 0;
//         printf("left\n");
//     }
//     else if (ray.angle == 270)
//     {
//         ray.direction_x = 0;
//         printf("down\n");
//     }
//     else
//         printf("------else-------\n");
//     printf(">>>>>>>>>>>>>>>>>>>>--------\n\n");
//     line.ax = ray.start.x;
//     line.ay = ray.start.y;
//     line.bx = ray.target.x;
//     line.by = ray.target.y;
//     t_point colision;

//     if (ray.direction_x == 0)
//     {
//         printf("<<<<<<<< x ==== 0\n");
//         // cast_horizantal(var,*ray,line);
//     }
//     else if (ray.direction_y == 0)
//     {
//         printf("<<<<<<<< y ==== 0\n");
//         // cast_vertical(var,*ray,line);
//     }
//     else
//     {
//         printf("    1****** %f %f %f %f\n",line.ax ,line.ay,line.bx ,line.by);
//         colision = cast_horizantal(var,ray,line);
//         line.bx = colision.x;
//         line.by = colision.y;
//         printf("    2****** %f %f %f %f\n",line.ax ,line.ay,line.bx ,line.by);
//         draw_line5(line,var,0xFF0000FF);
//         colision = cast_vertical(var,ray,line);
//         line.bx = colision.x;
//         line.by = colision.y;
//         printf("    3****** %f %f %f %f\n",line.ax ,line.ay,line.bx ,line.by);
//         draw_line5(line,var,0x0000FFFF);
//     }
//     // draw_line4(line,var,color);
// }


// void cast(t_var *var)
// {
//     t_ray ray;
//     t_point r;
//     t_point p;
//     t_point v;
//     int angle;
//     double view;
//     double step;
//     double i;
    
//     i = 0;
//     view = 60;
//     step = view / ((double)WIDTH);
//     angle = (var->player.angle) % 360;

//     p.x = var->player.position[0];
//     p.y = var->player.position[1];
//     v.x = var->player.vect[0];
//     v.y = var->player.vect[1];

//     ray.start = p;
//     ray.target = v;
//     r = rotate_by(ray.start, ray.target, from_deg_to_rad(view / 2));
//     ray.target = r;
//     ray.angle = angle + (view / 2);
//     v = r;

//     while (i * step  < view)
//     {
//         // one_ray_wall(var,ray,0XAA0000A0); // In  Progresss
//         one_ray(var,&ray,0XAA0000A0);
//         ray.angle -= (i * step);
//         r = rotate_by(ray.start, v, -from_deg_to_rad((i * step)));
//         ray.target = r;
//         i++;
//     }
//     ray.target.x = var->player.vect[0];
//     ray.target.y = var->player.vect[1];
//     one_ray(var,&ray,0x00FF00FF);//PLAYER VIEW DIRECTION
//     range_2(var);
// }

void    calculate_next_colision_up(t_var *var, t_ray *ray, double angle, t_offset *offset)
{
    offset->y = 32;
    ray->target.y = (((int)(ray->start.y)/32)*32) - 0.001;
    offset->x = tan(from_deg_to_rad(angle)) * (ray->start.y - ray->target.y);
    if (ray->angle < 90)
        ray->target.x = offset->x + ray->start.x;
    else
        ray->target.x = - offset->x + ray->start.x;
}

void    cast_up(t_var *var, t_ray *ray)
{
    double angle;
    t_offset offset;
    t_line line;

    if (ray->angle < 90)
        angle = 90 - ray->angle;
    else
        angle = -90 + ray->angle;
    calculate_next_colision_up(var, ray, angle, &offset);
    if (check_if_wall(ray->target.x, ray->target.y, var))
    {
        line.ax = var->player.position[0];
        line.ay = var->player.position[1];
        line.bx = ray->target.x;
        line.by = ray->target.y;
        draw_line(line, var, 0xFF0000FF);
        return ;
    }
    int i = 0;
    while (ray->target.x < var->mini_width && ray->target.x > 0
        && ray->target.y < var->mini_height && ray->target.y > 0
        && i < 100)
    {
        i++;
        ray->start.x = ray->target.x;
        ray->start.y = ray->target.y;
        calculate_next_colision_up(var, ray, angle, &offset);
        if (check_if_wall(ray->target.x, ray->target.y, var))
        {
            line.ax = var->player.position[0];
            line.ay = var->player.position[1];
            line.bx = ray->target.x;
            line.by = ray->target.y;
            draw_line(line, var, 0xFF0000FF);
            return ;
        }
    }
}

void    calculate_next_colision_down(t_var *var, t_ray *ray, double angle, t_offset *offset)
{
    offset->y = - 32;
    ray->target.y = (((int)(ray->start.y)/32)*32) + 32;
    offset->x = tan(from_deg_to_rad(angle)) * (ray->start.y - ray->target.y);
    if (ray->angle < 270)
        ray->target.x = offset->x + ray->start.x;
    else
        ray->target.x = - offset->x + ray->start.x;
}

void    cast_down(t_var *var, t_ray *ray)
{
    double angle;
    t_offset offset;
    t_line line;

    if (ray->angle < 270)
        angle = 270 - ray->angle;
    else
        angle = -270 + ray->angle;
    calculate_next_colision_down(var, ray, angle, &offset);
    if (check_if_wall(ray->target.x, ray->target.y, var))
    {
        line.ax = ray->start.x;
        line.ay = ray->start.y;
        line.bx = ray->target.x;
        line.by = ray->target.y;
        draw_line(line, var, 0xFF0000FF);
        return ;
    }
    int i = 0;
    while (ray->target.x < var->mini_width && ray->target.x > 0
        && ray->target.y < var->mini_height && ray->target.y > 0
        && i < 100)
    {
        i++;
        ray->start.x = ray->target.x;
        ray->start.y = ray->target.y;
        calculate_next_colision_down(var, ray, angle, &offset);
        if (check_if_wall(ray->target.x, ray->target.y, var))
        {
            line.ax = var->player.position[0];
            line.ay = var->player.position[1];
            line.bx = ray->target.x;
            line.by = ray->target.y;
            draw_line(line, var, 0xFF0000FF);
            return ;
        }
    }
}


void    cast(t_var *var)
{
    t_ray ray;

    ray.angle = var->player.angle * 1.0;
    ray.start.x = var->player.position[0];
    ray.start.y = var->player.position[1];
    if (ray.angle > 0 && ray.angle < 180)
        cast_up(var, &ray);
    else if (ray.angle > 180 && ray.angle < 360)
        cast_down(var, &ray);
}
