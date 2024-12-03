#include "cube.h"


float mod_360(float a)
{
    // while (a > 360)
    //     a-= 360;
    // return (a);
    return fmod(a,360);
}

float mod(float a, int b)
{   
    // while (a >= b)
    //     a-= b;
    // return (a);
    return fmod(a,b);
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
        // printf("A(%f %f) B(%f %f)\n",line.ax,line.by,line.bx,line.by);
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

t_point rotate_by(t_point center, t_point m, double angle)
{
    t_point z;

    z.x = ((m.x - center.x)*cos(angle)) - ((m.y - center.y)*sin(angle)) + center.x;
    z.y = ((m.y - center.y)*cos(angle)) + ((m.x - center.x)*sin(angle)) + center.y;
    return z;
}

t_point cast_vertical(t_var *var,t_ray *ray)
{
    t_point colison;
    double skip_x;
    double skip_y;
    double tn;

    colison.x = ray->start.x;
    colison.y = ray->start.y;
    tn = tan_0_90(ray->angle);
    if (ray->direction_y == -1)
    {
        colison.x = next_px_in_grid(ray->start.x,ray->direction_x);
        colison.y = ray->start.y - (fabs(colison.x-ray->start.x) * tn);
        skip_x = SQUARE_SIZE *  ray->direction_x;
        skip_y = - SQUARE_SIZE * tn;
    }
    else
    {
        colison.x = next_px_in_grid(ray->start.x,ray->direction_x);
        colison.y = ray->start.y + ((ray->direction_y * fabs(colison.x - ray->start.x)) / tn);
        skip_x = SQUARE_SIZE *  ray->direction_x;
        skip_y = SQUARE_SIZE / tn;
    }
    while ((0 <= colison.x && colison.x < WIDTH && 0 <= colison.y && colison.y < HEIGHT))
    {   
        if (check_if_wall_v(colison, ray->direction, var))
            return colison;
        colison.x += skip_x;
        colison.y += skip_y;
    }
    return colison;
}

t_point cast_horizantal(t_var *var,t_ray *ray)
{
    t_point horizon;
    t_point colison;
    double skip_x;
    double skip_y;
    double tn;

    colison.x = ray->start.x;
    colison.y = ray->start.y;
    tn = tan_0_90(ray->angle);
    if (ray->direction_y == -1)
    {
        horizon.y = ray->start.y;
        colison.y = next_px_in_grid(ray->start.y, ray->direction_y);
        colison.x = ray->start.x + (ray->direction_x * ((fabs(horizon.y - colison.y) / tn)));
        horizon.x = colison.x;
        skip_x = (SQUARE_SIZE / tn) * ray->direction_x;
        skip_y = SQUARE_SIZE * ray->direction_y;
    }
    else
    {
        horizon.y = next_px_in_grid(ray->start.y, ray->direction_y);
        colison.y = horizon.y;
        horizon.x = ray->start.x;
        colison.x = ray->start.x + (fabs(ray->start.y - horizon.y) * tn * ray->direction_x);
        skip_x = (SQUARE_SIZE * tn) * ray->direction_x;
        skip_y = SQUARE_SIZE * ray->direction_y;
    }
    while ((0 <= colison.x && colison.x < var->mini_width && 0 <= colison.y && colison.y < var->mini_height))
    {   
        if (check_if_wall_h(colison, ray->direction, var))
            return colison;
        colison.x += skip_x;
        colison.y += skip_y;
    }
    return colison;
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

double min(double a,double b)
{
    if (a < b)
        return a;
    return b;   
}

void cast_v_h(t_var *var, t_ray *ray,t_cords *cor)
{
    ray->is_vertical = 1;
    cor->is_collision_horizontal = 1;
    if (ray->direction_x == 0)
    {
        cor->is_collision_horizontal = 0;
        cor->colision_h = cast_horizantal(var,ray);
        cor->line.bx = cor->colision_h.x;
        cor->line.by = cor->colision_h.y;
        cor->h  = cor->distance_h;
        draw_line5(cor->line,var,0xFF0000FF);//WHITE HORIZON     0xFFFFFFFF
    }
    else if (ray->direction_y == 0)
    {
        cor->colision_v = cast_vertical(var,ray);
        cor->line.bx = cor->colision_v.x;
        cor->line.by = cor->colision_v.y;
        cor->h  = cor->distance_v;
        draw_line5(cor->line,var,0xFF0000FF);//WHITE VERTICAL    0xFFFFFFFF    
    }
    else
    {
        cor->colision_v = cast_vertical(var,ray);
        cor->colision_h = cast_horizantal(var,ray);
        cor->distance_v = distance_squared(ray->start, cor->colision_v);
        cor->distance_h = distance_squared(ray->start, cor->colision_h);
        cor->h  = cor->distance_v;
        if (cor->distance_v < cor->distance_h)
        {
            cor->is_collision_horizontal = 0;
            cor->line.bx = cor->colision_v.x;
            cor->line.by = cor->colision_v.y;
            draw_line5(cor->line,var,0xFF0000FF);//BLUE VERTICAL   0x0000FFFF
        }
        else if (cor->distance_h < cor->distance_v)
        {
            cor->h  = cor->distance_h;
            cor->line.bx = cor->colision_h.x;
            cor->line.by = cor->colision_h.y;
            ray->is_vertical = 0;
            ray->angle = fmod(ray->angle,360);
            draw_line5(cor->line,var,0x0000FFFF);//RED HORIZON
        }
        else
        {
            cor->line.bx = cor->colision_v.x;
            cor->line.by = cor->colision_v.y;
            draw_line5(cor->line,var,0x00FF00FF);//GRAY VERTICAL   0x808080FF
        }
    }
    cor->distance_to_wall =  cor->h;
}

void one_ray_wall(t_var *var, t_ray *ray)
{
    t_cords cor;
    int a;
    int idy;
    int idx;
    double distance_correction;
    double distance_to_projection;
    double wall_projection_height;
    // char *path = "/textures/rome1.webp";
    // int offset = 0;
        uint32_t color = 0xAD00FAFF;

    set_direciton(ray);
    cor.line.ax = ray->start.x;
    cor.line.ay = ray->start.y;
    cor.line.bx = ray->target.x;
    cor.line.by = ray->target.y;
    ray->direction.x = ray->direction_x;
    ray->direction.y = ray->direction_y;
    distance_to_projection = HEIGHT / (2 * tan(from_deg_to_rad(VIEW/2)));
    cast_v_h(var ,ray, &cor);
    cor.h = sqrt(cor.h);
    distance_correction = cor.h;
    distance_correction *= cos(from_deg_to_rad(ray->angle - var->player.angle));
    wall_projection_height = (distance_to_projection * CUBE_SIZE) / (distance_correction);
    a = ((HEIGHT - wall_projection_height) / 2);
    if (a <= 0)
        a = 0;
    if(var->img_3d)
    {
        idx = var->x_3d;
        idy = 0;
        while (a > 0 && idy < a)  //Draw Sky
        {
            if (0 <= idx && idx  < WIDTH &&  0 <= idy && idy < HEIGHT)
            {
                mlx_put_pixel(var->img_3d, idx, idy, 0xA0D8EFB4);
            }
            else 
                break;
            idy++;
        }
        idy = a;
        
        if (cor.is_collision_horizontal == 1)
        {
            color =0xAD00FA48;
        }
        while (idy < HEIGHT - a)
        {
            if (0 <= idx && idx  < WIDTH &&  0 <= idy && idy < HEIGHT)
            {
            //   mlx_texture_t *b =   mlx_load_png(path);
            //   b->pixels[offset];
                mlx_put_pixel(var->img_3d, idx, idy,color );
            }
            else 
                break;
            idy++;
        }

        var->x_3d++;
    }
}

void cast(t_var *var)
{
    t_ray ray;
    t_point r;
    t_point p;
    t_point v;
    float angle;
    float step;
    float i;
    
    i = 0;
    step = (1.0 * VIEW ) / WIDTH;
    angle = mod(var->player.angle,360);
    p.x = var->player.position[0];
    p.y = var->player.position[1];
    v.x = var->player.vect[0];
    v.y = var->player.vect[1];
    ray.start = p;
    ray.target = v;
    r = rotate_by(ray.start, v, -from_deg_to_rad(VIEW / 2));
    ray.angle = angle + (VIEW / 2);
    ray.angle = mod(ray.angle , 360);
    i = 0;
    var->x_3d = 0;
    var->y_3d = HEIGHT - 50;
    while (i < WIDTH)
    {
        var->player.angle = mod(var->player.angle,360);
        ray.target = r;
        ray.angle = ray.angle + 360 - (step);
        ray.angle = mod(ray.angle , 360);
        one_ray_wall(var,&ray);
        r = rotate_by(p, r, from_deg_to_rad(step));
        i+=1;
    }
    // printf("player(%f %f) **angle : %f\n",var->player.position[0],var->player.position[1],var->player.angle);
    // printf("start(%f %f) target(%f %f) angle : %f\n",ray.start.x,ray.start.y,ray.target.x,ray.target.y,ray.angle);
    ray.target.x = var->player.vect[0];
    ray.target.y = var->player.vect[1];
    // one_ray(var,&ray,0x00FF00FF);//PLAYER VIEW DIRECTION
    // range_2(var);
}

