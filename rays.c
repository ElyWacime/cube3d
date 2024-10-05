#include "cube.h"

void  cast_up(t_var *var)
{
    double *player = var->player.position;
    t_line line;
    double tmpbx;
    double tmpby;
    line.ax = player[0];
    line.ay = player[1];
    line.by = px_to_map_grid(player[1]) * 32;
    line.bx = tan(from_deg_to_rad(var->player.angle + 30)) * (player[1] - line.by) + player[0];
    tmpbx = line.ax;
    tmpby = line.by;
    while (1)
    {
        tmpby -= 32;
        tmpbx = tan(from_deg_to_rad(var->player.angle + 30)) * (player[1] - line.by) + player[0];
        if (tmpbx > 0 && tmpbx < var->mini_width
            && tmpby > 0 && tmpby < var->mini_height)
        {
            line.by = tmpby;
            line.bx = tmpbx;
        }
        else
            break;
    }
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
    line.bx =  tan(from_deg_to_rad(var->player.angle + 30)) * (player[1] - line.by) + player[0];
    tmpbx = line.ax;
    tmpby = line.by;
    while (1)
    {
        tmpby += 32;
        tmpbx = tan(from_deg_to_rad(var->player.angle + 30)) * (player[1] - line.by) + player[0];
        if (tmpbx > 0 && tmpbx < var->mini_width
            && tmpby > 0 && tmpby < var->mini_height)
        {
            line.by = tmpby;
            line.bx = tmpbx;
        }
        else 
            break;
    }
    draw_line(line, var, 0xFF0000FF);
}

void cast(t_var *var)
{
    t_uint angle = ((t_uint)(var->player.angle) + 30) % 360;
    if ((angle > 0 && angle < 90)
        || (angle > 270 && angle < 360))
        cast_up(var);
    else
        cast_down(var);
}