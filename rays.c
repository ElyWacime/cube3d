#include "cube.h"

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
            mlx_put_pixel(var->mini_map, (t_uint)x, (t_uint)y, color);
            x += (fabs(line.bx - line.ax) / distance);
            y += (fabs(line.by - line.ay) / distance);
        }
    }
    else if (x >= line.bx && y <= line.by)
    {
        while (x >= line.bx && y <= line.by && (0 <= x && x < var->mini_width && 0 <= y && y < var->mini_height))
        {
            mlx_put_pixel(var->mini_map, (t_uint)x, (t_uint)y, color);
            x -= (fabs(line.bx - line.ax) / distance);
            y += (fabs(line.by - line.ay) / distance);
        }
    }
    else if (x >= line.bx && y >= line.by)
    {
        while (x >= line.bx && y >= line.by && (0 <= x && x < var->mini_width && 0 <= y && y < var->mini_height))
        {
            mlx_put_pixel(var->mini_map, (t_uint)x, (t_uint)y, color);
            x -= (fabs(line.bx - line.ax) / distance);
            y -= (fabs(line.by - line.ay) / distance);
        }
    }
    else if (x <= line.bx && y >= line.by)
    {
        while (x <= line.bx && y >= line.by && (0 <= x && x < var->mini_width && 0 <= y && y < var->mini_height))
        {
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

double distance_squared(t_point a, t_point b)
{
    return (((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y)));
}

double str_double_len(char **str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return i;
}

double next_px_in_grid(double p, int d)
{
    int a;

    a = (int)(p / SQUARE_SIZE);
    if (p - (SQUARE_SIZE * a) == 0)
    {
        if (d == 1)
            return (a + 1) * SQUARE_SIZE;
        else 
            return (a - 1) * SQUARE_SIZE;
    }
    else
    {
        if (d == 1)
            return (a + 1) * SQUARE_SIZE;
        else 
            return SQUARE_SIZE * a; 
    }
}

int check_if_wall_h(t_point start, t_point direction, t_var *var)
{
    int row;
    int col;

    row = px_to_map_grid((t_uint)start.y) - (direction.y == -1);
    col = px_to_map_grid((t_uint)start.x);
    if (0 <= row && row < str_double_len(var->map) && 0 <= col && col < (double)ft_strlen(var->map[row]))
    {   
        if (col * SQUARE_SIZE == start.x)
        {
           return (var->map[row][col] == '1'
            || var->map[row][col] == '\0'
            || ft_isspace(var->map[row][col])
            || var->map[row][col - 1] == '1'
            || var->map[row][col - 1] == '\0'
            || ft_isspace(var->map[row][col - 1])
            ); 
        }
        return (var->map[row][col] == '1'
            || var->map[row][col] == '\0'
            || ft_isspace(var->map[row][col])
            );
    }
    return 1;
}

int check_if_wall_v(t_point start, t_point direction, t_var *var)
{
    int row;
    int col;

    row = px_to_map_grid((t_uint)start.y);
    col = px_to_map_grid((t_uint)start.x) - (direction.x == -1);
    if (0 <= row && row < str_double_len(var->map) && 0 <= col && col < (double)ft_strlen(var->map[row]))
    {   
        if (row * SQUARE_SIZE == start.y)
        {
           return (var->map[row][col] == '1'
            || var->map[row][col] == '\0'
            || ft_isspace(var->map[row][col])
            || var->map[row - 1][col] == '1'
            || var->map[row - 1][col] == '\0'
            || ft_isspace(var->map[row - 1][col])
            ); 
        }
        return (var->map[row][col] == '1'
            || var->map[row][col] == '\0'
            || ft_isspace(var->map[row][col])
            );
    }
    return 1;
}

double tan_0_90(double theta)
{
    theta = mod(theta,360);
    theta += 360;
    theta = mod(theta,360);
    if (90 < theta && theta < 180)
        theta = 180 - theta;
    else  if (180 < theta && theta < 270)
        theta =  270 - theta;
    else if (270 < theta && theta < 360)
        theta = theta - 270;
    return tan(from_deg_to_rad(theta));
}

t_point cast_vertical(t_var *var,t_ray ray)
{
    t_point horizon;
    t_point colison;
    double skip_x;
    double skip_y;
    double tn;

    colison.x = ray.start.x;
    colison.y = ray.start.y;
    tn = tan_0_90(ray.angle);
    if (ray.direction_y == -1)
    {
        colison.x = next_px_in_grid(ray.start.x,ray.direction_x);
        colison.y = ray.start.y - (fabs(colison.x-ray.start.x) * tn);
        horizon.x = next_px_in_grid(ray.start.x,ray.direction_x);
        horizon.y = ray.start.y;
        skip_x = SQUARE_SIZE *  ray.direction_x;
        skip_y = - SQUARE_SIZE * tn;
    }
    else
    {
        colison.x = next_px_in_grid(ray.start.x,ray.direction_x);
        colison.y = ray.start.y + ((ray.direction_y * fabs(colison.x - ray.start.x)) / tn);
        
        horizon.x = ray.start.x;
        horizon.y = colison.y;
        skip_x = SQUARE_SIZE *  ray.direction_x;
        skip_y = SQUARE_SIZE / tn;
    }
    while ((0 <= colison.x && colison.x < var->mini_width && 0 <= colison.y && colison.y < var->mini_height))
    {   
        if (check_if_wall_v(colison, ray.direction, var))
            return colison;
        colison.x += skip_x;
        colison.y += skip_y;
    }
    return colison;
}

t_point cast_horizantal(t_var *var,t_ray ray)
{
    t_point horizon;
    t_point colison;
    t_point direction;
    double skip_x;
    double skip_y;
    double tn;

    colison.x = ray.start.x;
    colison.y = ray.start.y;
    tn = tan_0_90(ray.angle);
    if (ray.direction_y == -1)
    {
        horizon.y = ray.start.y;
        colison.y = next_px_in_grid(ray.start.y, ray.direction_y);
        colison.x = ray.start.x + (ray.direction_x * ((fabs(horizon.y - colison.y) / tn)));
        horizon.x = colison.x;
        skip_x = (SQUARE_SIZE / tn) * ray.direction_x;
        skip_y = SQUARE_SIZE * ray.direction_y;
    }
    else
    {
        horizon.y = next_px_in_grid(ray.start.y, ray.direction_y);
        colison.y = horizon.y;
        horizon.x = ray.start.x;
        colison.x = ray.start.x + (fabs(ray.start.y - horizon.y) * tn * ray.direction_x);
        skip_x = (SQUARE_SIZE * tn) * ray.direction_x;
        skip_y = SQUARE_SIZE * ray.direction_y;
    }
    while ((0 <= colison.x && colison.x < var->mini_width && 0 <= colison.y && colison.y < var->mini_height))
    {   
        if (check_if_wall_h(colison, ray.direction, var))
            return colison;
        colison.x += skip_x;
        colison.y += skip_y;
    }
    return colison;
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
void range_2(t_var *var)
{
    t_point v;
    t_point p;
    t_point r;
    t_line line;

    v.x = var->player.vect[0];
    v.y = var->player.vect[1];
    p.x = var->player.position[0];
    p.y = var->player.position[1];
    r = rotate_by(p,v,from_deg_to_rad(VIEW/2));//RED + RIGHT
    line.ax = p.x;
    line.ay = p.y;
    line.bx = r.x;
    line.by = r.y;
    draw_line5(line,var,0XA020F0A0);
    r = rotate_by(p,v,from_deg_to_rad(-VIEW/2));//BLUE - LEFT
    line.bx = r.x;
    line.by = r.y;
    draw_line5(line,var,0XA020F0A0);
}

void one_ray(t_var *var, t_ray *ray ,unsigned int color)
{
    t_line line;

    line.ax = ray->start.x;
    line.ay = ray->start.y;
    line.bx = ray->target.x;
    line.by = ray->target.y;
    draw_line5(line,var,color);
}

void set_direciton(t_ray *ray)
{
    ray->direction_x = 1;
    ray->direction_y = 1;
    ray->angle = mod(ray->angle, 360);
    ray->angle += 360;
    ray->angle = mod(ray->angle,360);
    if (0 < ray->angle  && ray->angle < 90)
        ray->direction_y = -1;
    else if (90 < ray->angle && ray->angle < 180)
    {
        ray->direction_x = -1;
        ray->direction_y = -1;
    }
    else if (180 < ray->angle  && ray->angle < 270)
        ray->direction_x = -1;
    else if (ray->angle <= 270)
    {
        ray->direction_x = 0;
        ray->direction_y = 0;
        if (ray->angle == 0)
            ray->direction_x = 1;
        else if (ray->angle == 270)
            ray->direction_y = 1;
        else if (ray->angle == 90)
            ray->direction_y = -1;
        else if (ray->angle == 180)
            ray->direction_x = -1;
    }
}

void one_ray_wall(t_var *var, t_ray ray ,unsigned int color)
{
    t_line line;
    t_point colision_h;
    t_point colision_v;

    set_direciton(&ray);
    line.ax = ray.start.x;
    line.ay = ray.start.y;
    line.bx = ray.target.x;
    line.by = ray.target.y;
    ray.direction.x = ray.direction_x;
    ray.direction.y = ray.direction_y;
    if (ray.direction_x == 0)
    {
        colision_h = cast_horizantal(var,ray);
        line.bx = colision_h.x;
        line.by = colision_h.y;
        draw_line5(line,var,0xFF0000FF);//WHITE HORIZON     0xFFFFFFFF
    }
    else if (ray.direction_y == 0)
    {
        colision_v = cast_vertical(var,ray);
        line.bx = colision_v.x;
        line.by = colision_v.y;
        draw_line5(line,var,0xFF0000FF);//WHITE VERTICAL    0xFFFFFFFF    
    }
    else
    {
        colision_h = cast_horizantal(var,ray);
        colision_v = cast_vertical(var,ray);
        if (distance_squared(ray.start, colision_v) < distance_squared(ray.start, colision_h))
        {
            line.bx = colision_v.x;
            line.by = colision_v.y;
            draw_line5(line,var,0xFF0000FF);//BLUE VERTICAL   0x0000FFFF
        }
        else if (distance_squared(ray.start, colision_h) < distance_squared(ray.start, colision_v))
        {
            line.bx = colision_h.x;
            line.by = colision_h.y;
            draw_line5(line,var,0xFF0000FF);//RED HORIZON
        }
        else
        {
            line.bx = colision_v.x;
            line.by = colision_v.y;
            draw_line5(line,var,0xFF0000FF);//GRAY VERTICAL   0x808080FF
        }
    }
}

void cast(t_var *var)
{
    t_ray ray;
    t_point r;
    t_point p;
    t_point v;
    int angle;
    double step;
    double i;
    
    i = 0;
    step = VIEW / ((double)WIDTH);
    angle = (var->player.angle) % 360;
    p.x = var->player.position[0];
    p.y = var->player.position[1];
    v.x = var->player.vect[0];
    v.y = var->player.vect[1];
    ray.start = p;
    ray.target = v;
    r = rotate_by(ray.start, v, -from_deg_to_rad(VIEW / 2));
    ray.angle = angle + (VIEW / 2);
    ray.angle = mod(ray.angle , 360);
    i = 1;
    while (i * step  < VIEW)
    {
        r = rotate_by(p, r, from_deg_to_rad(step));
        ray.target = r;
        ray.angle -= (step);
        one_ray_wall(var,ray,0XAA0000A0);
        i+=1;
    }
    ray.target.x = var->player.vect[0];
    ray.target.y = var->player.vect[1];
    one_ray(var,&ray,0x00FF00FF);//PLAYER VIEW DIRECTION
    range_2(var);
}
