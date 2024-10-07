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
    printf("f(x) = %.2fx + %.2f\n",a,b);
    printf("A (%.2f , %.2f) B( %.2f  , %.2f) \n",line.ax , line.ay,line.bx , line.by);
    if (line.ax == line.bx)
    {
        if (line.ay < line.by)
            i = 1;
        // while (((i == 1 && line.ay < line.by) || (i == -1 && line.by < line.ay)) && ((0 <= line.ax && line.ax < var->mini_width && 0 <= line.ay && line.ay < var->mini_height)))
        while ((0 <= line.ax && line.ax < var->mini_width && 0 <= line.ay && line.ay < var->mini_height))
        {
            mlx_put_pixel(var->mini_map, (t_uint)line.ax, (t_uint)line.ay, 0xFF0000FF);
            line.ay+=i;
        }
        i = 0;
    }
    else
    {
        if (line.ax < line.bx)
            i = 1;
        // ((i == 1 && line.ax < line.bx) || (i == -1 && line.bx < line.ax)) && 
        while ((0 <= line.ax && line.ax < var->mini_width && 0 <= line.ay && line.ay < var->mini_height))
        {
            mlx_put_pixel(var->mini_map, (t_uint)line.ax, (t_uint)line.ay, 0xFF0000FF);
            line.ax+=i;
            line.ay = (line.ax * a) + b;
        }
    }
    return 0;
}

void    draw_line4(t_line line, t_var *var, t_uint color)
{
    double distance;
    double x;
    double y;


    distance = calculate_distance(line.ax, line.ay, line.bx, line.by);
    x = line.ax;
    y = line.ay;
    if (x <= line.bx && y <= line.by)
    {
        while ((0 <= x && x < var->mini_width && 0 <= y && y < var->mini_height))
        {
            // if (check_if_wall(x, y, var))
                // break;
            mlx_put_pixel(var->mini_map, (t_uint)x, (t_uint)y, color);
            x += (fabs(line.bx - line.ax) / distance);
            y += (fabs(line.by - line.ay) / distance);
        }
    }
    else if (x >= line.bx && y <= line.by)
    {
        while ((0 <= x && x < var->mini_width && 0 <= y && y < var->mini_height))
        {
            // if (check_if_wall(x, y, var))
                // break;
            mlx_put_pixel(var->mini_map, (t_uint)x, (t_uint)y, color);
            x -= (fabs(line.bx - line.ax) / distance);
            y += (fabs(line.by - line.ay) / distance);
        }
    }
    else if (x >= line.bx && y >= line.by)
    {
        while ((0 <= x && x < var->mini_width && 0 <= y && y < var->mini_height))
        {
            // if (check_if_wall(x, y, var))
                // break;
            mlx_put_pixel(var->mini_map, (t_uint)x, (t_uint)y, color);
            x -= (fabs(line.bx - line.ax) / distance);
            y -= (fabs(line.by - line.ay) / distance);
        }
    }
    else if (x <= line.bx && y >= line.by)
    {
        while ((0 <= x && x < var->mini_width && 0 <= y && y < var->mini_height))
        {
            // if (check_if_wall(x, y, var))
                // break;
            mlx_put_pixel(var->mini_map, (t_uint)x, (t_uint)y, color);
            x += (fabs(line.bx - line.ax) / distance);
            y -= (fabs(line.by - line.ay) / distance);
        }
    }

}
void    draw_line5(t_line line, t_var *var, t_uint color)
{
    double distance;
    double x;
    double y;


    distance = calculate_distance(line.ax, line.ay, line.bx, line.by);
    x = line.ax;
    y = line.ay;
    if (x <= line.bx && y <= line.by)
    {
        while (x <= line.bx && y <= line.by && (0 <= x && x < var->mini_width && 0 <= y && y < var->mini_height))
        {
            // if (check_if_wall(x, y, var))
                // break;
            mlx_put_pixel(var->mini_map, (t_uint)x, (t_uint)y, color);
            x += (fabs(line.bx - line.ax) / distance);
            y += (fabs(line.by - line.ay) / distance);
        }
    }
    else if (x >= line.bx && y <= line.by)
    {
        while (x >= line.bx && y <= line.by && (0 <= x && x < var->mini_width && 0 <= y && y < var->mini_height))
        {
            // if (check_if_wall(x, y, var))
                // break;
            mlx_put_pixel(var->mini_map, (t_uint)x, (t_uint)y, color);
            x -= (fabs(line.bx - line.ax) / distance);
            y += (fabs(line.by - line.ay) / distance);
        }
    }
    else if (x >= line.bx && y >= line.by)
    {
        while (x >= line.bx && y >= line.by && (0 <= x && x < var->mini_width && 0 <= y && y < var->mini_height))
        {
            // if (check_if_wall(x, y, var))
                // break;
            mlx_put_pixel(var->mini_map, (t_uint)x, (t_uint)y, color);
            x -= (fabs(line.bx - line.ax) / distance);
            y -= (fabs(line.by - line.ay) / distance);
        }
    }
    else if (x <= line.bx && y >= line.by)
    {
        while (x <= line.bx && y >= line.by && (0 <= x && x < var->mini_width && 0 <= y && y < var->mini_height))
        {
            // if (check_if_wall(x, y, var))
                // break;
            mlx_put_pixel(var->mini_map, (t_uint)x, (t_uint)y, color);
            x += (fabs(line.bx - line.ax) / distance);
            y -= (fabs(line.by - line.ay) / distance);
        }
    }

}

double mod(double a, int b)
{
    int x = (int)a;
    return (a - (1.0 * x)) + (double)(x % b);
}


// void cast_horizantal(t_var *var,t_ray direction,t_line line)
// {
//     double *p = var->player.position;
//     double ang = 30;
//     t_line line;
//     int i = 0;
//     double x = (fabs(p[1] - (px_to_map_grid(p[1])) * 32) * tan(from_deg_to_rad(ang))) + p[0];
//     double y = px_to_map_grid(p[1]) * 32;
//     double px = p[0];
//     double py = p[1];
//     // printf("x = %.2f %.2f\n", x, y);
//     // printf("px = %.2f %.2f\n", px, py);
//     // printf(">>>>>>>>>>>> CUrrent inter ::: %.2f %.2f\n\n\n", x,y);
//     double skip = 32 * tan(from_deg_to_rad(ang));
//     // double skip = 32 / tan(from_deg_to_rad(ang));
//     while (0 <= x && x < var->mini_width && 0 <= y && y < var->mini_height)
//     {
//         line.ax = px;
//         line.ay = py;
//         line.bx = x;
//         line.by = y;

//         draw_line4(line, var,0x00FFFFF0);
//         // if (draw_line3(line, var))
//         //     break;
//         px = x;
//         py = y;
//         // x = (32) * tan(from_deg_to_rad(ang)) + px;
//         x += skip;
//         y -= 32;
//         // printf(" Next ::; %.2f %.2f\n\n\n", x,y);
//     }
//     //  printf("-----------------\n\n\n");
// }

// void cast_vertical(t_var *var,t_ray direction,t_line line)
// {
//     double *p = var->player.position;
//     double ang = 30;
//     t_line line;
//     int i = 0;
//     double x = (px_to_map_grid(p[0]) + 1) * 32;
//     double y = (fabs(x - p[0]) * tan(from_deg_to_rad(ang))) + p[1];
//     double px = p[0];
//     double py = p[1];
//     // printf("x = %.2f %.2f\n", x, y);
//     // printf("px = %.2f %.2f\n", px, py);
//     // printf(">>>>>>>>>>>> CUrrent inter ::: %.2f %.2f\n\n\n", x,y);
//     // double skip = 32 * tan(from_deg_to_rad(ang));
//     double skip = 32 / tan(from_deg_to_rad(ang));
//     while (0 <= x && x < var->mini_width && 0 <= y && y < var->mini_height)
//     {
//         line.ax = px;
//         line.ay = py;
//         line.bx = x;
//         line.by = y;

//         draw_line4(line, var,0xFF00FFF0);
//         // if (draw_line3(line, var))
//         //     break;
//         px = x;
//         py = y;
//         x += 32;
//         y -= skip;
//         // printf(" Next ::; %.2f %.2f\n\n\n", x,y);
//     }
//     //  printf("-----------------\n\n\n");
// }

double max(double a, double b)
{
    if (a > b)
        return a;
    return b;
}

double min(double a, double b)
{
    if (a < b)
        return a;
    return b;
}

t_point cast_horizantal0(t_var *var,t_ray ray,t_line line)
{
    t_point horizon;
    t_point colison;
    double distance;
    double skip;
    double tn;

    horizon.x = ((line.ax / 32) + (ray.direction_x > 0)) * 32;
    horizon.y = line.ay;
    colison.x = horizon.x;
    distance =  fabs(horizon.x - line.ax);
    tn = tan(from_deg_to_rad(ray.angle));
    colison.y = (distance * tn) + line.ay;
    skip = 32 * tn * ray.direction_y;
    while ((0 <= colison.x && colison.x < var->mini_width && 0 <= colison.y && colison.y < var->mini_height))
    {
        if (check_if_wall(colison.x, colison.y, var))
            return colison;
        colison.x += 32 * ray.direction_x;
        colison.y += skip;
    }
    colison.x = min(colison.x,var->mini_width);
    colison.y = min(colison.y,var->mini_height);
    return colison;
}

double grid_to_px(double i,int x)
{
    if (x == -1)
        return (32 * i);
    return (32 * i) + 32;
}

double next_px_in_grid(double p, int d)
{
    int a;

    a = (int)(p / 32);
    if (p - (32.0 * a) == 0)
    {
        if (d == 1)
            return (a + 1) * 32;
        else 
            return (a - 1) * 32;
    }
    else
    {
        if (d == 1)
            return (a + 1) * 32;
        else 
            return 32 * a; 
    }
}

t_point cast_horizantal1(t_var *var,t_ray ray)
{
    t_point horizon;
    t_point colison;
    t_point prev_colison;
    double skip_x;
    double skip_y;
    double tn;
    double theta;

    printf("-------- cast_horizantal ------- \n");
    printf("player.angle(%d)\n",var->player.angle);
    printf("ray.angle(%.2f)\n",ray.angle);
    ray.angle = mod(ray.angle,360);
    
    // grid_to_px() ---- change px hx ix back grom grid
    theta = ray.angle;
    if (90 < ray.angle && ray.angle < 180)
        theta = 180 - ray.angle;
    else  if (180 < ray.angle && ray.angle < 270)
        theta = 270 - ray.angle  ;
    else  if (270 < ray.angle && ray.angle < 360)
        theta = ray.angle - 270;
    tn = tan(from_deg_to_rad(theta));
    horizon.y = ray.start.y;
    colison.y = next_px_in_grid(ray.start.y, ray.direction_y);
    // colison.x = ray.start.x + (ray.direction_x * (fabs(horizon.y - colison.y) / tn));
    colison.x = ray.start.x + ((fabs(horizon.y - colison.y) / tn));
    // if (180 < ray.angle)
    //     colison.x = -colison.x;
    horizon.x = colison.x;
    skip_x = (32.0 / tn) * ray.direction_x;
    skip_y = 32.0 * ray.direction_y;
    prev_colison = colison;
    printf("tan === (%.2f)\n",tn);
    printf("P (%.2f %.2f)   \n", ray.start.x, ray.start.y);
    printf("H (%.2f %.2f)   \n", horizon.x ,horizon.y);
    printf("I (%.2f %.2f)   \n", colison.x ,colison.y);
    printf("DirectionXY(%.2f ::::  %.2f)\n",ray.direction_x ,ray.direction_y);
    // while ((0 <= colison.x && colison.x < var->mini_width && 0 <= colison.y && colison.y < var->mini_height))
    // {   
    //     prev_colison = colison;
    //     if (check_if_wall(colison.x, colison.y, var))
    //         return colison;
    //     colison.x += skip_x;
    //     colison.y += skip_y;
    // }
    // colison.x = min(colison.x,var->mini_width);
    // colison.y = min(colison.y,var->mini_height);
    return colison;
}

int check_if_wall_h(t_point start, double direction_y, t_var *var)
{
    int x_positon;
    int y_position;
    // int y = ((start.x / 32) - (direction_y == -1)) * 32;
    // int x = (start.x / 32) * 32;

    x_positon = px_to_map_grid((t_uint)start.x);
    y_position = px_to_map_grid((t_uint)start.y) - (direction_y == -1);
    if (0 <= start.x && start.x < var->mini_width && 0 <= start.y && start.y < var->mini_height)
        return (var->map[y_position][x_positon] == '1'
            || var->map[y_position][x_positon] == '\0'
            || ft_isspace(var->map[y_position][x_positon]));
    return 1;

    // if (0 <= x && x < var->mini_width && 0 <= y && y < var->mini_height)
    //     return (var->map[y][x] == '1');
    // return 1;
}
int check_if_wall_v(t_point start, double direction_x, t_var *var)
{
    int x_positon;
    int y_position;
    // int y = ((start.x / 32) - (direction_y == -1)) * 32;
    // int x = (start.x / 32) * 32;
    x_positon = px_to_map_grid((t_uint)start.x) - (direction_x == -1);
    y_position = px_to_map_grid((t_uint)start.y);
    if (0 <= start.x && start.x < var->mini_width && 0 <= start.y && start.y < var->mini_height)
        return (var->map[y_position][x_positon] == '1'
            || var->map[y_position][x_positon] == '\0'
            || ft_isspace(var->map[y_position][x_positon]));
    return 1;

    // if (0 <= x && x < var->mini_width && 0 <= y && y < var->mini_height)
    //     return (var->map[y][x] == '1');
    // return 1;
}
t_point cast_horizantal(t_var *var,t_ray ray)
{
    t_point horizon;
    t_point colison;
    t_point prev_colison;
    double skip_x;
    double skip_y;
    double tn;
    double theta;

    colison.x = ray.start.x;
    colison.y = ray.start.y;
    printf("-------- cast_horizantal ------- \n");
    if (check_if_wall_h(ray.start, ray.direction_y, var))
    // if (check_if_wall(colison.x, colison.y, var))
        return colison;
    printf("player.angle(%d)\n",var->player.angle);
    printf("ray.angle(%.2f)\n",ray.angle);
    ray.angle = mod(ray.angle,360);
    theta = ray.angle;
    if (90 < theta && theta < 180)
        theta = 180 - theta;
    else  if (180 < theta && theta < 270)
        theta =  270 - theta;
    else if (270 < theta && theta < 360)
        theta = theta - 270;
    printf("theta (%.2f)\n",theta);
    tn = tan(from_deg_to_rad(theta));

    // {
    //     horizon.x = next_px_in_grid(ray.start.x, ray.direction_y);
    //     colison.x = next_px_in_grid(ray.start.x, ray.direction_y);
        
    //     colison.y = ray.start.y + (ray.direction_y * ((fabs(horizon.x - colison.x) * tn)));
    //     horizon.y = ray.start.y;


    //     skip_x = (32.0 / tn) * ray.direction_x;
    //     skip_y = 32.0 * ray.direction_y;
    //     prev_colison = colison;
    // }
    if (ray.direction_y == -1)
    {
        horizon.y = ray.start.y;
        colison.y = next_px_in_grid(ray.start.y, ray.direction_y);
        
        colison.x = ray.start.x + (ray.direction_x * ((fabs(horizon.y - colison.y) / tn)));
        horizon.x = colison.x;


        skip_x = (32.0 / tn) * ray.direction_x;
        skip_y = 32.0 * ray.direction_y;
        prev_colison = colison;
    }
    else
    {
        horizon.y = next_px_in_grid(ray.start.y, ray.direction_y);
        colison.y = horizon.y;

        horizon.x = ray.start.x;
        colison.x = ray.start.x + (fabs(ray.start.y - horizon.y) * tn * ray.direction_x);

        skip_x = (32.0 * tn) * ray.direction_x;
        skip_y = 32.0 * ray.direction_y;
    }
    printf("tan === (%.2f)\n",tn);
    printf("P (%.2f %.2f)   \n", ray.start.x, ray.start.y);
    printf("H (%.2f %.2f)   \n", horizon.x ,horizon.y);
    printf("I (%.2f %.2f)   \n", colison.x ,colison.y);
    printf("DirectionXY(%.2f ::::  %.2f)\n",ray.direction_x ,ray.direction_y);
    prev_colison = colison;
    while ((0 <= colison.x && colison.x < var->mini_width && 0 <= colison.y && colison.y < var->mini_height))
    {   
        prev_colison = colison;
        if (check_if_wall_h(colison, ray.direction_y, var))
        // if (check_if_wall(colison.x, colison.y, var))
            return colison;
        colison.x += skip_x;
        colison.y += skip_y;
    }
    // colison.x = min(colison.x,var->mini_width);
    // colison.y = min(colison.y,var->mini_height);
    return prev_colison;
}


t_point cast_vertical(t_var *var,t_ray ray)
{
    t_point horizon;
    t_point colison;
    t_point prev_colison;
    double skip_x;
    double skip_y;
    double tn;
    double theta;

    colison.x = ray.start.x;
    colison.y = ray.start.y;
    printf("-------- cast_vertical ------- \n");
    // if (check_if_wall(colison.x, colison.y, var))
    if (check_if_wall_v(ray.start, ray.direction_x, var))
        return colison;
    printf("player.angle(%d)\n",var->player.angle);
    printf("ray.angle(%.2f)\n",ray.angle);
    ray.angle = mod(ray.angle,360);
    theta = ray.angle;
    if (90 < theta && theta < 180)
        theta = 180 - theta;
    else  if (180 < theta && theta < 270)
        theta =  270 - theta;
    else if (270 < theta && theta < 360)
        theta = theta - 270;
    printf("theta (%.2f)\n",theta);
    tn = tan(from_deg_to_rad(theta));
    
    if (ray.direction_y == 1)
    {
        horizon.x = ray.start.x;
        colison.x = next_px_in_grid(ray.start.x, ray.direction_x);

        colison.y = ray.start.y + (((fabs(horizon.x - ray.start.x ) / tn)) * ray.direction_y);
        horizon.y = ray.start.y;

        skip_x = 32.0 * ray.direction_x;
        skip_y = (32.0 / tn) * ray.direction_y;
    }
    else
    {
        horizon.x = next_px_in_grid(ray.start.x, ray.direction_x);
        colison.x = colison.x;

        horizon.y = ray.start.y;
        colison.y = ray.start.y + ((fabs(ray.start.x - horizon.x) * tn) * ray.direction_y);
 
        skip_x = 32.0  * ray.direction_x;
        skip_y = (32.0 * tn) * ray.direction_y;
    }
    printf("Vertical Codinates\n");
    printf("tan === (%.2f)\n",tn);
    printf("P (%.2f %.2f)   \n", ray.start.x, ray.start.y);
    printf("H (%.2f %.2f)   \n", horizon.x ,horizon.y);
    printf("I (%.2f %.2f)   \n", colison.x ,colison.y);
    printf("DirectionXY(%.2f ::::  %.2f)\n",ray.direction_x ,ray.direction_y);
    prev_colison = colison;
    while ((0 <= colison.x && colison.x < var->mini_width && 0 <= colison.y && colison.y < var->mini_height))
    {   
        prev_colison = colison;
        // if (check_if_wall(colison.x, colison.y, var))
        if (check_if_wall_v(colison, ray.direction_x, var))
            return colison;
        colison.x += skip_x;
        colison.y += skip_y;
    }
    colison.x = min(colison.x,var->mini_width);
    colison.y = min(colison.y,var->mini_height);
    return prev_colison;
}

t_point cast_vertical_0(t_var *var,t_ray ray,t_line line)
{
    t_point horizon;
    t_point colison;
    double distance;
    double skip;
    double tn;

    horizon.x = ((line.ax / 32) + (ray.direction_x > 0)) * 32;
    horizon.y = line.ay;
    colison.x = horizon.x;
    distance =  fabs(horizon.x - line.ax);
    tn = tan(from_deg_to_rad(ray.angle));
    colison.y = (distance * tn) + line.ay;
    skip = (32 / tn) * ray.direction_x;
    while ((0 <= colison.x && colison.x < var->mini_width && 0 <= colison.y && colison.y < var->mini_height))
    {
        if (check_if_wall(colison.x, colison.y, var))
            return colison;
        colison.x += skip;
        colison.y += 32 * ray.direction_y;
    }
    colison.x = min(colison.x,var->mini_width);
    colison.y = min(colison.y,var->mini_height);
    return colison;
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
            printf("break up\nmini width: %u\tmini height: %u\ntmpbx: %.2f\ttmpby: %.2f\n\n\n", var->mini_width, var->mini_height, tmpbx, tmpby);
            break;
        }
    }
    printf("ax = %.2f\tay = %.2f\nbx = %.2f\tby = %.2f\n\n\n", line.ax, line.ay, line.bx, line.by);
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
            printf("break down\nmini width: %u\tmini height: %u\ntmpbx: %.2f\ttmpby: %.2f\nline.bx: %.2f\tline.by: %.2f\n\n\n\n", var->mini_width, var->mini_height, tmpbx, tmpby, line.bx, line.by);
            break;
        }
    }
    draw_line(line, var, 0xFF0000FF);
}


//rotate a point m f rom center by an angle in radian
t_point rotate_by(t_point center, t_point m, double angle)
{
    t_point z;

    z.x = ((m.x - center.x)*cos(angle)) - ((m.y - center.y)*sin(angle)) + center.x;
    z.y = ((m.y - center.y)*cos(angle)) + ((m.x - center.x)*sin(angle)) + center.y;
    return z;
}

// maxim left and right rays
// void range(t_var *var)
// {
//     double vx = var->player.vect[0];
//     double vy = var->player.vect[1];
//     double px = var->player.position[0];
//     double py = var->player.position[1];
//     double thetha = var->player.angle % 360;
//     double rot = 30.0;
//     double cs = cos(from_deg_to_rad(rot));
//     double sn = sin(from_deg_to_rad(rot));
//     double vax = ((vx - px)*cs) - ((vy - py)*sn) + px;
//     double vay = ((vy - py)*cs) + ((vx - px)*sn) + py;
//     sn = -sn;
//     double vbx = ((vx - px)*cs) - ((vy - py)*sn) + px;
//     double vby = ((vy - py)*cs) + ((vx - px)*sn) + py;
//     // printf("P(%.2f     %.2f)\nV(%.2f    %.2f) \nVa(%.2f   %.2f) \nVb(%.2f   %.2f)\n",px,py,vx,vy,vax,vay,vbx,vby);
//     t_line line;
//     line.ax = px;
//     line.ay = py;
//     line.bx = vax;
//     line.by = vay;
//     // draw_line3(line,var);//RED +
//     draw_line4(line,var,0xFF0000FF);
//     line.bx = vbx;
//     line.by = vby;
//      draw_line4(line,var,0x0000FFFF);
//     // draw_line4(line,var);//BLUE - 
//     // printf("RED  +%.2f  \n" , rot);
//     // printf("BLUE  -%.2f \n",  rot);
// }

// maxim left and right rays
void range_2(t_var *var)
{
    t_point v;
    t_point p;
    t_point r;
    t_line line;
    double view;
    
    view = 60;
    v.x = var->player.vect[0];
    v.y = var->player.vect[1];
    p.x = var->player.position[0];
    p.y = var->player.position[1];
    r = rotate_by(p,v,from_deg_to_rad(view/2));//RED + RIGHT
    line.ax = p.x;
    line.ay = p.y;
    line.bx = r.x;
    line.by = r.y;
    draw_line4(line,var,0XA020F0A0);
    r = rotate_by(p,v,from_deg_to_rad(-view/2));//BLUE - LEFT
    line.bx = r.x;
    line.by = r.y;
    draw_line4(line,var,0XA020F0A0);
}


void one_ray(t_var *var, t_ray *ray ,unsigned int color)
{
    t_line line;

    line.ax = ray->start.x;
    line.ay = ray->start.y;
    line.bx = ray->target.x;
    line.by = ray->target.y;
    draw_line4(line,var,color);
}

void one_ray_wall(t_var *var, t_ray ray ,unsigned int color)
{
    t_line line;
    t_point colision;

    ray.direction_x = 1;
    ray.direction_y = 1;
    ray.angle = mod(ray.angle, 360);
    ray.angle+=360;
    ray.angle = mod(ray.angle, 360);
    printf("-------  one_ray_wall---\n");
    if (0 < ray.angle  && ray.angle < 90)
    {
        ray.direction_y = -1;
        printf("up right\n");
    }
    else if (90 < ray.angle && ray.angle < 180)
    {
        ray.direction_x = -1;
        ray.direction_y = -1;
        printf("up left\n");
    }
    else if (180 < ray.angle  && ray.angle < 270)
    {
        ray.direction_x = -1;
        printf("down left\n");
    }
    else if (270 < ray.angle && ray.angle != 0)
    {
        printf(" down right\n");
    }
    else if (ray.angle < 0)
    {
         printf("------else----Negative Angle---\n");
         return;
    }
    else
    {
        ray.direction_x = 0;
        ray.direction_y = 0;
        if (ray.angle == 0)
        {
            ray.direction_x = 1;
            printf(" right\n");
        }
        else if (ray.angle == 90)
        {
            printf("up\n");
            ray.direction_y = -1;
        }
        else if (ray.angle == 180)
        {
            ray.direction_x = -1;
            printf("left\n");
        }
        else if (ray.angle == 270)
        {
            ray.direction_y = 1;
            printf("down\n");
        }
    }
    line.ax = ray.start.x;
    line.ay = ray.start.y;
    line.bx = ray.target.x;
    line.by = ray.target.y;
    if (ray.direction_x == 0)
    {
        printf("<<<<<<<< x ==== 0\n");
        // cast_horizantal(var,*ray,line);
    }
    else if (ray.direction_y == 0)
    {
        printf("<<<<<<<< y ==== 0\n");
        // cast_vertical(var,*ray,line);
    }
    else
    {
        colision = cast_horizantal(var,ray);
        line.bx = colision.x;
        line.by = colision.y;
        printf("start ****** %.2f %.2f\n\n",line.ax ,line.ay);
        printf("Hcolision ****** %.2f %.2f\n\n",colision.x ,colision.y);
        draw_line5(line,var,0xFF0000FF);//RED HORIZON
        line.bx = ray.target.x;
        line.by = ray.target.y;
        colision = cast_vertical(var,ray);
        line.bx = colision.x;
        line.by = colision.y;
        printf("Vcolision ****** %.2f %.2f\n\n",colision.x ,colision.y);
        draw_line5(line,var,0x0000FFFF);//BLUE VERTICAL
    }
    // draw_line4(line,var,color);
}


void cast(t_var *var)
{
    t_ray ray;
    t_point r;
    t_point p;
    t_point v;
    int angle;
    double view;
    double step;
    double i;
    
    i = 0;
    view = 60;
    step = view / ((double)WIDTH);
    angle = (var->player.angle) % 360;

    p.x = var->player.position[0];
    p.y = var->player.position[1];
    v.x = var->player.vect[0];
    v.y = var->player.vect[1];

    ray.start = p;
    ray.target = v;
    printf("------ cast --------\n");
    printf("player angle === %d\n",angle);
    r = rotate_by(ray.start, v, -from_deg_to_rad(view / 2));
    ray.angle = angle + (view / 2);
    ray.angle = mod(ray.angle , 360);
    
    // printf("ray angle === %.2f\n",ray.angle);
    // printf("%.2f == step\n",step);
    i = 1;
    // while (i * step  < view)//comment this will  to check progress
    {
        r = rotate_by(p, r, from_deg_to_rad(step));
        ray.target = r;
        ray.angle -= (i * step);
        // one_ray(var,&ray,0XAA0000A0); // comment this
        one_ray_wall(var,ray,0XAA0000A0); // In  Progresss
        i++;
    }
    ray.target.x = var->player.vect[0];
    ray.target.y = var->player.vect[1];
    one_ray(var,&ray,0x00FF00FF);//PLAYER VIEW DIRECTION
    // range_2(var);
    
}
