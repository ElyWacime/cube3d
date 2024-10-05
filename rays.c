#include "cube.h"

int    draw_line2(t_line line, t_var *var)
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
    // if (check_if_wall(line.ax, line.ay, var))
    //     return 1;
    while ((i == 1 && line.ax < line.bx) || (i == -1 && line.bx < line.ax))
    {
        if (0 <= line.ax && line.ax < var->mini_width && 0 <= line.ay && line.ay < var->mini_height)
            mlx_put_pixel(var->mini_map, (t_uint)line.ax, (t_uint)line.ay, 0x00FF00FF);
        else
            break;
        line.ax+=i;
        line.ay = (line.ax * a) + b;
    }
    // if (check_if_wall(line.bx, line.by, var))
    //         return 1;
    // if (check_if_wall(line.ax, line.ay, var))
    //         return 1;
    return 0;
}

// void cast(t_var *var)
// {
//     double *p = var->player.position;
//     double ang = 30;
//     t_line line;
//     int i = 0;
//     double x = (fabs(p[1] - (px_to_map_grid(p[1])) * 32) * tan(from_deg_to_rad(ang))) + p[0];
//     double y = px_to_map_grid(p[1]) * 32;
//     double px = p[0];
//     double py = p[1];
//     double skip = 32 / (tan(from_deg_to_rad(ang)));
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
//         x += skip;
//         y -= 32;
//     }
// }

void  cast(t_var *var)
{
    printf("enter \n");
    double *player = var->player.position;
    t_line line;
    line.ax = player[0];
    line.ay = player[1];
    line.by = px_to_map_grid(player[1]) * 32;
    line.bx = tan(from_deg_to_rad(var->player.angle + 32)) * (player[1] - line.by) + player[0];
    printf("player :::: x = %f\ty = %f\n", player[0], player[1]);
    printf("x = %f\ty = %f\n", line.bx, line.by);
    printf("width and height : %u\t%u\n\n\n\n\n", var->mini_width, var->mini_height);
    while (line.bx >= 0 && line.bx <= var->mini_width
        && line.by >= 0 && line.by <= var->mini_height)
    {
        printf("inside while \n");
        draw_line(line, var, 0xFF0000FF);
        line.by -= 32;
        line.bx = tan(from_deg_to_rad(var->player.angle + 32)) * (player[1] - line.by) + player[0];
        printf("apdated :::: %f\t%f\napdated :::: %f\t%f\n\n", line.bx, line.by, line.ax, line.ay);
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

void cast2(t_var *var)
{
    int flag = 0;
    double *p = var->player.position;
    double ang = 30;
    t_line line;
    int i = 0;
    double x = (fabs(p[1] - (px_to_map_grid(p[1])) * 32 ) * tan(from_deg_to_rad(ang))) + p[0];
    double y = px_to_map_grid(p[1]) * 32;
    double px = p[0];
    double py = p[1];
    while (0 <= x && x < var->mini_width && 0 <= y && y < var->mini_height)
    {
        line.ax = px;
        line.ay = py;
        line.bx = x;
        line.by = y;
        draw_line2(line, var);
        px = x;
        py = y + 32;

        x = ((fabs(y - p[1])) * tan(from_deg_to_rad(ang))) + p[0];
        if (flag)
            y -= 32;
        flag = 1;
    }
}