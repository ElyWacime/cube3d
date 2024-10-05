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
    printf("%f\n", var->player.angle + 30);
    if ((var->player.angle + 30 > 0 && var->player.angle + 30 < 90)
        || (var->player.angle + 30 > 270 && var->player.angle + 30 < 360))
    {
        cast_up(var);
        printf("enter up\n");
    }
    else
        cast_down(var);
}