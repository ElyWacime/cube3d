#include "cube.h"

// void cast_horizantal(t_var *var)
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

//         if (draw_line2(line, var))
//             break;
//         px = x;
//         py = y;
//         // x = (32) * tan(from_deg_to_rad(ang)) + px;
//         x += skip;
//         y -= 32;
//         // printf(" Next ::; %f %f\n\n\n", x,y);
//     }
//     //  printf("-----------------\n\n\n");
// }

// void cast_vertical(t_var *var)
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

//         if (draw_line3(line, var))
//             break;
//         px = x;
//         py = y;
//         x += 32;
//         y -= skip;
//         // printf(" Next ::; %f %f\n\n\n", x,y);
//     }
//     //  printf("-----------------\n\n\n");
// }

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

void cast_left(t_var *var)
{

}
void cast_down(t_var *var)
{
    
}
void cast_right(t_var *var)
{
    
}
void cast_up(t_var *var)
{
    
}
void cast_up_left(t_var *var)
{

}
void cast_down_left(t_var *var)
{
    
}
void cast_down_right(t_var *var)
{
    
}

void cast_up_right(t_var *var)
{

}

double mod(double a, int b)
{
    int x = (int)a;
    return (a - (double)x) + (double)(x % b);
}

//rx = (vx - px)cos(thetha) - (vy - py)*sin(thetha)+ px
//ry = (vy - py)cos(thetha) + (vx - px)*sin(thetha)+ py

//rx = ((vx - px)*cs) - ((vy - py)*sn) + px
//ry = ((vy - py)*cs) + ((vx - px)*sn) + py
void range(t_var *var)
{
    double vx = var->player.vect[0];
    double vy = var->player.vect[1];
    double px = var->player.position[0];
    double py = var->player.position[1];
    double thetha = var->player.angle % 360;
    double rot = 30.0;


    double cs = cos(from_deg_to_rad(rot));
    double sn = sin(from_deg_to_rad(rot));

    double vax = ((vx - px)*cs) - ((vy - py)*sn) + px;
    double vay = ((vy - py)*cs) + ((vx - px)*sn) + py;
    
    sn = -sn;
    double vbx = ((vx - px)*cs) - ((vy - py)*sn) + px;
    double vby = ((vy - py)*cs) + ((vx - px)*sn) + py;
    // printf("P(%f     %f)\nV(%f    %f) \nVa(%f   %f) \nVb(%f   %f)\n",px,py,vx,vy,vax,vay,vbx,vby);
    t_line line;
    line.ax = px;
    line.ay = py;
    line.bx = vax;
    line.by = vay;
    // draw_line3(line,var);//RED +
    draw_line4(line,var,0xFF0000FF);
    line.bx = vbx;
    line.by = vby;
     draw_line4(line,var,0x0000FFFF);
    // draw_line4(line,var);//BLUE - 
    // printf("RED  +%f  \n" , rot);
    // printf("BLUE  -%f \n",  rot);
}

void cast(t_var *var)
{
    int angle = (var->player.angle) % 360;
    range(var);
    if (0 < angle  && angle < 90)
    {
        printf("up right\n");
        cast_up_right(var);
    }
    else if (90 < angle && angle < 180)
    {
        printf("up left\n");
        cast_down_right(var); 
    }
    else if (180 < angle  && angle < 270)
    {
        printf("down left\n");
        cast_down_left(var);
    }
    else if (270 < angle && angle != 0)
    {
        printf(" down right\n");
        cast_up_left(var); 
    }
    else if (angle == 0)
    {
        printf(" right\n");
        cast_up(var); 
    }
    else if (angle == 90)
    {
        printf("up\n");
        cast_right(var); 
    }
    else if (angle == 180)
    {
        printf("left\n");
        cast_left(var); 
    }
    else if (angle == 270)
    {
        printf("down\n");
        cast_down(var); 
    }
}
