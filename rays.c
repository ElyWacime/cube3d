#include "cube.h"

void cast(t_var *var)
{
    double *p = var->player.position;
    double Int[2];
    double ang = 30;
    t_line line;
    Int[0] = (fabs(p[1] - (px_to_map_grid(p[1])) * 32 ) * tan(from_deg_to_rad(ang))) + p[0];
    Int[1] = (px_to_map_grid(p[1])) * 32;
    printf("%f %f\n", p[0],p[1]);
    printf("%f %f\n\n\n", Int[0],Int[1]);
    int i = 0;
    double x = Int[0];
    double y = Int[1];
    double px = p[0];
    double py = p[1];
    printf(">>>>>>>>>>>>\033[31;1m CUrrent inter ::: %f %f\033[31;1m\n\n\n", x,y);
    while (0 <= x && x < var->mini_width && 0 <= y && y < var->mini_height)
    {
        line.ax = px;
        line.ay = py;
        line.bx = x;
        line.by = y;
       printf(">>>>>>>>>>>> check_if_wall inter ::: %d\n\n\n", check_if_wall(791.547005, 320.0, var));
        if (check_if_wall(x, y, var))
            break;
        draw_line2(line, var);

        px = x;
        py = y;
            // 24 10
        x = (32 * tan(from_deg_to_rad(ang))) + px;
        y -= 32;
        printf(" Next ::; %f %f\n\n\n", x,y);
    }
     printf("-----------------\n\n\n");
}