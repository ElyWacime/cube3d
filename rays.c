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
        printf("ENTER while\n");
        tmpby -= 32;
        tmpbx = tan(from_deg_to_rad(var->player.angle + 30)) * (player[1] - line.by) + player[0];
        if (tmpbx >= 0 && tmpbx <= var->mini_width
            && tmpby >= 0 && tmpby <= var->mini_height)
        {
            printf("ENTER IF\n");
            line.by = tmpby;
            line.bx = tmpbx;
        }
        else 
            break;
        printf("ax = %f\tay = %f\tbx = %f\tby = %f\n", line.ax, line.ay, line.bx, line.by);
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
        if (tmpbx >= 0 && tmpbx <= var->mini_width
            && tmpby >= 0 && tmpby <= var->mini_height)
        {
            printf("ENTER IF\n");
            line.by = tmpby;
            line.bx = tmpbx;
        }
        else 
        {
            printf("break from the while \n");
            break;
        }
    }
    printf("%f\t%f\t%f\t%f\n\n", line.ax, line.ay, line.bx, line.by);
    printf("mini width ::%u\tmini height:: %u\n\n\n\n\n\n*******************\n",
        var->mini_width, var->mini_height);
    draw_line(line, var, 0xFF0000FF);
}

void cast(t_var *var)
{
    t_uint angle = ((t_uint)(var->player.angle) + 30) % 360;
    if ((angle > 0 && angle < 90)
        || (angle > 270 && angle < 360))
    {
        cast_up(var);
        printf("enter up\n\n\n\n\n\n\n");
    }
    else
    {
        printf("ENTER down\n\n\n\n\n\n");
        cast_down(var);
    }
}