#include "cube.h"

void  cast_up(t_var *var)
{
    double *player = var->player.position;
    t_line line;
    line.ax = player[0];
    line.ay = player[1];
    line.by = px_to_map_grid(player[1]) * 32;
    line.bx = tan(from_deg_to_rad(var->player.angle + 30)) * (player[1] - line.by) + player[0];
    while (line.bx >= 0 && line.bx <= var->mini_width
        && line.by >= 0 && line.by <= var->mini_height)
    {
        draw_line(line, var, 0xFF0000FF);
        line.by -= 32;
        line.bx = tan(from_deg_to_rad(var->player.angle + 30)) * (player[1] - line.by) + player[0];
    }
}

void  cast_down(t_var *var)
{
    double *player = var->player.position;
    t_line line;
    line.ax = player[0];
    line.ay = player[1];
    line.by = px_to_map_grid(player[1]) * 32 + 32;
    line.bx =  tan(from_deg_to_rad(var->player.angle + 30)) * (player[1] - line.by) + player[0];
    while (line.bx >= 0 && line.bx <= var->mini_width
        && line.by >= 0 && line.by <= var->mini_height)
    {
        draw_line(line, var, 0xFF0000FF);
        line.by += 32;
        line.bx = tan(from_deg_to_rad(var->player.angle + 30)) * (player[1] - line.by) + player[0];
    }
}

void cast(t_var *var)
{
    t_uint angle = ((t_uint)(var->player.angle) + 30) % 360;
    if ((angle > 0 && angle < 90)
        || (angle > 270 && angle < 360))
    {
        cast_up(var);
        printf("enter up\n");
    }
    else
        cast_down(var);
}