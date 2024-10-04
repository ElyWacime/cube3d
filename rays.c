#include "cube.h"

void cast(t_var *var)
{
    double *p = var->player.position;
    double ang = 30;
    t_line line;
    int i = 0;
    double x = (fabs(p[1] - (px_to_map_grid(p[1])) * 32) * tan(from_deg_to_rad(ang))) + p[0];
    double y = px_to_map_grid(p[1]) * 32;
    double px = p[0];
    double py = p[1];
    // printf("x = %f %f\n", x, y);
    // printf("px = %f %f\n", px, py);
    // printf(">>>>>>>>>>>> CUrrent inter ::: %f %f\n\n\n", x,y);
    while (0 <= x && x < var->mini_width && 0 <= y && y < var->mini_height)
    {
        line.ax = px;
        line.ay = py;
        line.bx = x;
        line.by = y;

        if (draw_line2(line, var))
            break;
        px = x;
        py = y;
        x = (32) * tan(from_deg_to_rad(ang)) + px;
        y -= 32;
        // printf(" Next ::; %f %f\n\n\n", x,y);
    }
    //  printf("-----------------\n\n\n");
}


void cast2(t_var *var)
{
    double *p = var->player.position;
    double ang = 30;
    t_line line;
    int i = 0;
    double x = (fabs(p[1] - (px_to_map_grid(p[1])) * 32 ) * tan(from_deg_to_rad(ang))) + p[0];
    double y = px_to_map_grid(p[1]) * 32;
    double px = p[0];
    double py = p[1];
    printf("%f %f\n", p[0],p[1]);
    printf("%f %f\n", px,py);
    printf(">>>>>>>>>>>> CUrrent inter ::: %f %f\n\n\n", x,y);
    while (0 <= x && x < var->mini_width && 0 <= y && y < var->mini_height)
    {
        line.ax = px;
        line.ay = py;
        line.bx = x;
        line.by = y;
        printf(">>>>>>>>>>>> CUrrent inter ::: %d\n\n\n", check_if_wall(x, y, var));
        // if (check_if_wall(x, y, var))
            // break;
        draw_line2(line, var);
        px = x;
        py = y;

        x = ((fabs(y - p[1])) * tan(from_deg_to_rad(ang))) + p[0];
        y -= 32;
        printf(" Next ::; %f %f\n\n\n", x,y);
    }
     printf("-----------------\n\n\n");
}