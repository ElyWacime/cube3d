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
    if (line.ax <= line.bx)
        i = 1;
    while ((i == 1 && line.ax < line.bx) || (i == -1 && line.bx < line.ax))
    {
        if (0 <= line.ax && line.ax < var->mini_width && 0 <= line.ay && line.ay < var->mini_height)
            mlx_put_pixel(var->mini_map, (t_uint)line.ax, (t_uint)line.ay, 0xFF0000FF);
        else
            break;
        line.ax+=i;
        line.ay = (line.ax * a) + b;
    }
    return 0;
}

void  cast_up(t_var *var)
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

void  cast_down(t_var *var)
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

void cast(t_var *var)
{
    t_uint angle = (var->player.angle) % 360;
    if (angle > 0 && angle < 180)
        cast_up(var);
    else if (angle > 180 && angle != 0)
        cast_down(var);
}