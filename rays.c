#include "cube.h"

void  cast(t_var *var)
{
    printf("enter \n");
    double *player = var->player.position;
    t_line line;
    line.ax = player[0];
    line.ay = player[1];
    line.by = px_to_map_grid(player[1]) * 32;
    line.bx = tan(from_deg_to_rad(var->player.angle + 32)) * (player[1] - line.by) + player[0];
    while (line.bx >= 0 && line.bx <= var->mini_width
        && line.by >= 0 && line.by <= var->mini_height)
    {
        draw_line(line, var, 0xFF0000FF);
        line.by -= 32;
        line.bx = tan(from_deg_to_rad(var->player.angle + 32)) * (player[1] - line.by) + player[0];
    }
}

void cast_vertical(t_var *var)
{
    double *p = var->player.position;
    double ang = 30;
    t_line line;
    int i = 0;
    double x = (px_to_map_grid(p[0]) + 1) * 32;
    double y = (fabs(x - p[0]) * tan(from_deg_to_rad(ang))) + p[1];
    double px = p[0];
    double py = p[1];
    // printf("x = %f %f\n", x, y);
    // printf("px = %f %f\n", px, py);
    // printf(">>>>>>>>>>>> CUrrent inter ::: %f %f\n\n\n", x,y);
    double skip = 32 * tan(from_deg_to_rad(ang));
    while (0 <= x && x < var->mini_width && 0 <= y && y < var->mini_height)
    {
        line.ax = px;
        line.ay = py;
        line.bx = x;
        line.by = y;

        if (draw_line3(line, var))
            break;
        px = x;
        py = y;
        x += 32;
        y -= skip;
        // printf(" Next ::; %f %f\n\n\n", x,y);
    }
    //  printf("-----------------\n\n\n");
}
