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

double distance_square(t_point a, t_point b)
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
    // printf("-------- cast_vertical ------- \n");
    // if (check_if_wall(colison.x, colison.y, var))
    // if (check_if_wall_v(ray.start, ray.direction, var))
    //     return colison;
    // printf("player.angle(%d)\n",var->player.angle);
    // printf("ray.angle(%.2f)\n",ray.angle);
    ray.angle = mod(ray.angle,360);
    theta = ray.angle;
    if (90 < theta && theta < 180)
        theta = 180 - theta;
    else  if (180 < theta && theta < 270)
        theta =  270 - theta;
    else if (270 < theta && theta < 360)
        theta = theta - 270;
    // printf("theta (%.2f)\n",theta);
    tn = tan(from_deg_to_rad(theta));
    if (ray.direction_y == -1)
    {
        colison.x = next_px_in_grid(ray.start.x,ray.direction_x);
        horizon.x = next_px_in_grid(ray.start.x,ray.direction_x);
        horizon.y = ray.start.y;
        colison.y = ray.start.y - (fabs(horizon.x-ray.start.x) * tn);
        skip_x = SQUARE_SIZE *  ray.direction_x;
        skip_y = - SQUARE_SIZE * tn;
    }
    else
    {
        horizon.x = ray.start.x;
        colison.x = next_px_in_grid(ray.start.x,ray.direction_x);
        horizon.y = ray.start.y + ((ray.direction_y * fabs(colison.x - ray.start.x)) / tn);
        colison.y = horizon.y;
        skip_x = SQUARE_SIZE *  ray.direction_x;
        skip_y = SQUARE_SIZE / tn;
    }
    // printf("Vertical Codinates\n");
    // printf("tan === (%.2f)\n",tn);
    // printf("P (%.2f %.2f)   \n", ray.start.x, ray.start.y);
    // printf("H (%.2f %.2f)   \n", horizon.x ,horizon.y);
    // printf("I (%.2f %.2f)   \n", colison.x ,colison.y);
    // printf("DirectionXY(%.2f ::::  %.2f)\n",ray.direction_x ,ray.direction_y);
    printf("\n\n\n");
    prev_colison = colison;
    while ((0 <= colison.x && colison.x < var->mini_width && 0 <= colison.y && colison.y < var->mini_height))
    {   
        prev_colison = colison;
        // if (check_if_wall(colison.x, colison.y, var))
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
    t_point prev_colison;
    double skip_x;
    double skip_y;
    double tn;
    double theta;

    colison.x = ray.start.x;
    colison.y = ray.start.y;
    // printf("-------- cast_horizantal ------- \n");
    // if (check_if_wall_h(ray.start, ray.direction, var))
    //     return colison;
    // printf("player.angle(%d)\n",var->player.angle);
    // printf("ray.angle(%.2f)\n",ray.angle);
    ray.angle = mod(ray.angle,360);
    theta = ray.angle;
    if (90 < theta && theta < 180)
        theta = 180 - theta;
    else  if (180 < theta && theta < 270)
        theta =  270 - theta;
    else if (270 < theta && theta < 360)
        theta = theta - 270;
    // printf("theta (%.2f)\n",theta);
    tn = tan(from_deg_to_rad(theta));
    if (ray.direction_y == -1)
    {
        horizon.y = ray.start.y;
        colison.y = next_px_in_grid(ray.start.y, ray.direction_y);
        
        colison.x = ray.start.x + (ray.direction_x * ((fabs(horizon.y - colison.y) / tn)));
        horizon.x = colison.x;


        skip_x = (SQUARE_SIZE / tn) * ray.direction_x;
        skip_y = SQUARE_SIZE * ray.direction_y;
        prev_colison = colison;
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
    // printf("tan === (%.2f)\n",tn);
    // printf("P (%.2f %.2f)   \n", ray.start.x, ray.start.y);
    // printf("H (%.2f %.2f)   \n", horizon.x ,horizon.y);
    // printf("I (%.2f %.2f)   \n", colison.x ,colison.y);
    // printf("DirectionXY(%.2f ::::  %.2f)\n",ray.direction_x ,ray.direction_y);
    prev_colison = colison;
    while ((0 <= colison.x && colison.x < var->mini_width && 0 <= colison.y && colison.y < var->mini_height))
    {   
        prev_colison = colison;
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
    draw_line5(line,var,0XA020F0A0);
    r = rotate_by(p,v,from_deg_to_rad(-view/2));//BLUE - LEFT
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

void one_ray_wall(t_var *var, t_ray ray ,unsigned int color)
{
    t_line line;
    t_point colision_h;
    t_point colision_v;

    ray.direction_x = 1;
    ray.direction_y = 1;
    // printf("-------  one_ray_wall---\n");
    if (0 < ray.angle  && ray.angle < 90)
    {
        ray.direction_y = -1;
        // printf("up right\n");
    }
    else if (90 < ray.angle && ray.angle < 180)
    {
        ray.direction_x = -1;
        ray.direction_y = -1;
        // printf("up left\n");
    }
    else if (180 < ray.angle  && ray.angle < 270)
    {
        ray.direction_x = -1;
        // printf("down left\n");
    }
    else if (270 < ray.angle && ray.angle != 0)
    {
        // printf(" down right\n");
    }
    else if (ray.angle < 0)
    {
         printf("------else----Negative Angle---\n");
        //  return;
    }
    else
    {
        ray.direction_x = 0;
        ray.direction_y = 0;
        if (ray.angle == 0)
        {
            ray.direction_x = 1;
            // printf(" right\n");
        }
        else if (ray.angle == 90)
        {
            // printf("up\n");
            ray.direction_y = -1;
        }
        else if (ray.angle == 180)
        {
            ray.direction_x = -1;
            // printf("left\n");
        }
        else if (ray.angle == 270)
        {
            ray.direction_y = 1;
            // printf("down\n");
        }
    }
    line.ax = ray.start.x;
    line.ay = ray.start.y;
    line.bx = ray.target.x;
    line.by = ray.target.y;
    ray.direction.x = ray.direction_x;
    ray.direction.y = ray.direction_y;
    if (ray.direction_x == 0)
    {
        // printf("<<<<<<<< x ==== 0\n");
        // cast_horizantal(var,*ray,line);
    }
    else if (ray.direction_y == 0)
    {
        // printf("<<<<<<<< y ==== 0\n");
        // cast_vertical(var,*ray,line);
    }
    else
    {
        colision_h = cast_horizantal(var,ray);
        colision_v = cast_vertical(var,ray);
        // // line.bx = colision_h.x;
        // // line.by = colision_h.y;
        // // draw_line5(line,var,0xFF0000FF);//RED HORIZON
        // line.bx = colision_v.x;
        // line.by = colision_v.y;
        // draw_line5(line,var,0x0000FFFF);//BLUE VERTICAL
        if (distance_square(ray.start, colision_h) > distance_square(ray.start, colision_v))
        {
            line.bx = colision_h.x;
            line.by = colision_h.y;
            draw_line5(line,var,0xFF0000FF);//RED HORIZON
            line.bx = colision_v.x;
            line.by = colision_v.y;
            draw_line5(line,var,0x0000FFFF);//BLUE VERTICAL
        }
        else if (distance_square(ray.start, colision_h) < distance_square(ray.start, colision_v))
        {
            line.bx = colision_v.x;
            line.by = colision_v.y;
            draw_line5(line,var,0x0000FFFF);//BLUE VERTICAL 
            line.bx = colision_h.x;
            line.by = colision_h.y;
            draw_line5(line,var,0xFF0000FF);//RED HORIZON
        }
        else
        {
            line.bx = colision_v.x;
            line.by = colision_v.y;
            // printf()
            printf("ray.target(%f  %f) \n",ray.target.x,ray.target.y);
            printf("ray.angle (%f)\n",ray.angle);
            printf("V(%f %f)\n",colision_v.x,colision_v.y);
            printf("H(%f %f)\n",colision_h.x,colision_h.y);
            draw_line5(line,var,0x808080FF);//BLUE VERTICAL  
        }
    
    }
    // draw_line5(line,var,color);
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
    // printf("------ cast --------\n");
    // printf("player angle === %d\n",angle);
    r = rotate_by(ray.start, v, -from_deg_to_rad(view / 2));
    ray.angle = angle + (view / 2);
    ray.angle = mod(ray.angle , 360);
    i = 1;
    while (i   < 50)//comment this will  to check progress
    // while (i * step  < view)//comment this will  to check progress
    {
        r = rotate_by(p, r, from_deg_to_rad(step));
        ray.target = r;
        ray.angle -= (i * step);
        ray.angle = mod((ray.angle) , 360);
        ray.angle+=360;
        ray.angle = mod((ray.angle) , 360);
        // one_ray(var,&ray,0XAA0000A0); // comment this
        one_ray_wall(var,ray,0XAA0000A0); // In  Progresss
        i+=1;
        // break;
    }
    ray.target.x = var->player.vect[0];
    ray.target.y = var->player.vect[1];
    one_ray(var,&ray,0x00FF00FF);//PLAYER VIEW DIRECTION
    range_2(var);
}
