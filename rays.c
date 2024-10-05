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
void cast(t_var *var)
{
    t_uint angle = (var->player.angle) % 360;
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