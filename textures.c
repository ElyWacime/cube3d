
#include "cube.h"

size_t door_textures_v(t_var *var, t_ray_wall *ra_wl, int ofsx)
{
    if (ra_wl->correct_a > 0)
        ra_wl->ofssety =  (((var->door->height - (2 * ra_wl->image_offset)) * ra_wl->idy) / HEIGHT) + ra_wl->image_offset;
    else
        ra_wl->ofssety = (((ra_wl->idy - ra_wl->a) * var->door->height)) / (HEIGHT - (ra_wl->a << 1));
    ra_wl->pix = ((ra_wl->ofssety * var->door->width) + ofsx) << 2;
    if ((uint32_t)(ra_wl->pix) >= var->door->height * var->door->width * 4)
        return 0xFFFFFFFF;
    var->r = (var->door->pixels[ra_wl->pix + 0]) << 24;
    var->g = (var->door->pixels[ra_wl->pix + 1]) << 16;
    var->b =  (var->door->pixels[ra_wl->pix + 2]) << 8;
    var->o = var->door->pixels[ra_wl->pix + 3];
    return   var->r |
            var->g |
            var->b |
            var->o;
}

size_t door_textures_h(t_var *var, t_ray_wall *ra_wl, int ofsx)
{
    if (ra_wl->correct_a > 0)
        ra_wl->ofssety =  (((var->door->width - (2 * ra_wl->image_offset)) * ra_wl->idy) / HEIGHT) + ra_wl->image_offset;
    else
        ra_wl->ofssety = ((ra_wl->idy - ra_wl->a) * var->door->width) / (HEIGHT - (ra_wl->a << 1));
    ra_wl->pix = ((ra_wl->ofssety * var->door->width) + ofsx) << 2;
    if ((uint32_t)(ra_wl->pix) >=  var->door->height * var->door->width * 4)
        return 0xFFFFFFFF;
    var->r = (var->door->pixels[ra_wl->pix + 0]) << 24;
    var->g = (var->door->pixels[ra_wl->pix + 1]) << 16;
    var->b =  (var->door->pixels[ra_wl->pix + 2]) << 8;
    var->o = var->door->pixels[ra_wl->pix + 3];
        return   var->r |
            var->g |
            var->b |
            var->o;
}

size_t east_textures(t_var *var, t_ray_wall *ra_wl, int ofsx)
{
    // return 0x0AAA0AFF;
    if (ra_wl->correct_a > 0)
        ra_wl->ofssety =  (((var->east->height - (2 * ra_wl->image_offset)) * ra_wl->idy) / HEIGHT) + ra_wl->image_offset;
    else
        ra_wl->ofssety = (((ra_wl->idy - ra_wl->a) * var->east->height)) / (HEIGHT - (ra_wl->a << 1));
    ra_wl->pix = ((ra_wl->ofssety * var->east->width) + ofsx) << 2;
    // return  var->east->pixels[ra_wl->pix + 3] |  (var->east->pixels[ra_wl->pix + 2] << 8) | (var->east->pixels[ra_wl->pix + 1] << 16) |  (var->east->pixels[ra_wl->pix + 0] << 24);
    if ((uint32_t)(ra_wl->pix) >= var->east->height * var->east->width * 4)
        return 0xFFFFFF00;
    var->r = (var->east->pixels[ra_wl->pix + 0]) << 24;
    var->g = (var->east->pixels[ra_wl->pix + 1]) << 16;
    var->b =  (var->east->pixels[ra_wl->pix + 2]) << 8;
    var->o = var->east->pixels[ra_wl->pix + 3];
    return   var->r |
            var->g |
            var->b |
            var->o;
}

size_t north_textures(t_var *var, t_ray_wall *ra_wl, int ofsx)
{
    // return 0x0AAA0AFF;
    if (ra_wl->correct_a > 0)
        ra_wl->ofssety =  (((var->north->width - (2 * ra_wl->image_offset)) * ra_wl->idy) / HEIGHT) + ra_wl->image_offset;
    else
        ra_wl->ofssety = ((ra_wl->idy - ra_wl->a) * var->north->width) / (HEIGHT - (ra_wl->a << 1));
    ra_wl->pix = ((ra_wl->ofssety * var->north->width) + ofsx) << 2;
    // return  var->north->pixels[ra_wl->pix + 3] |  (var->north->pixels[ra_wl->pix + 2] << 8) | (var->north->pixels[ra_wl->pix + 1] << 16) |  (var->north->pixels[ra_wl->pix + 0] << 24);
    if ((uint32_t)(ra_wl->pix) >=  var->north->height * var->north->width * 4)
        return 0xFFFFFF00;
    var->r = (var->north->pixels[ra_wl->pix + 0]) << 24;
    var->g = (var->north->pixels[ra_wl->pix + 1]) << 16;
    var->b =  (var->north->pixels[ra_wl->pix + 2]) << 8;
    var->o = var->north->pixels[ra_wl->pix + 3];
        return   var->r |
            var->g |
            var->b |
            var->o;
}

size_t west_textures(t_var *var, t_ray_wall *ra_wl, int ofsx)
{
    // return 0x0AAA0AFF;
    if (ra_wl->correct_a > 0)
        ra_wl->ofssety =  (((var->west->height - (2 * ra_wl->image_offset)) * ra_wl->idy) / HEIGHT) + ra_wl->image_offset;
    else
        ra_wl->ofssety = (((ra_wl->idy - ra_wl->a) * var->west->height)) / (HEIGHT - (ra_wl->a << 1));
    ra_wl->pix = ((ra_wl->ofssety * var->west->width) + ofsx) << 2;
    if ((uint32_t)(ra_wl->pix) >=  var->west->height * var->west->width * 4)
        return 0xFFFFFF00;
    var->r = (var->west->pixels[ra_wl->pix + 0]) << 24;
    var->g = (var->west->pixels[ra_wl->pix + 1]) << 16;
    var->b =  (var->west->pixels[ra_wl->pix + 2]) << 8;
    var->o = var->west->pixels[ra_wl->pix + 3];
        return   var->r |
            var->g |
            var->b |
            var->o;
    // return  var->west->pixels[ra_wl->pix + 3] |  (var->west->pixels[ra_wl->pix + 2] << 8) | (var->west->pixels[ra_wl->pix + 1] << 16) |  (var->west->pixels[ra_wl->pix + 0] << 24);
}

size_t south_textures(t_var *var, t_ray_wall *ra_wl, int ofsx)
{
    // return 0x0AAA0AFF;
    if (ra_wl->correct_a > 0)
        ra_wl->ofssety =  (((var->south->height - (2 * ra_wl->image_offset)) * ra_wl->idy) / HEIGHT) + ra_wl->image_offset;
    else
        ra_wl->ofssety = (((ra_wl->idy - ra_wl->a) * var->south->height)) / (HEIGHT - (ra_wl->a << 1));
    ra_wl->pix = ((ra_wl->ofssety * var->south->width) + ofsx)  << 2;
    if ((uint32_t)(ra_wl->pix) >=  var->south->height * var->south->width * 4)
        return 0xFFFFFF00;
    var->r = (var->south->pixels[ra_wl->pix + 0]) << 24;
    var->g = (var->south->pixels[ra_wl->pix + 1]) << 16;
    var->b =  (var->south->pixels[ra_wl->pix + 2]) << 8;
    var->o = var->south->pixels[ra_wl->pix + 3];
        return   var->r |
            var->g |
            var->b |
            var->o;
    // return  var->south->pixels[ra_wl->pix + 3] |  (var->south->pixels[ra_wl->pix + 2] << 8) | (var->south->pixels[ra_wl->pix + 1] << 16) |  (var->south->pixels[ra_wl->pix + 0] << 24);
}

uint32_t get_gun_color_at_current_pixel(t_var *var, int x, int y)
{
    t_uint r;
    t_uint g;
    t_uint b;
    t_uint o;
    t_uint color;

    if ((y * var->gun->width + x) >= var->gun->height * var->gun->width * 4)
        return 0xFFFFFF00;
    r = (var->gun->pixels[((y * var->gun->width + x) + 0)]) << 24;
    g = (var->gun->pixels[((y * var->gun->width + x) + 1)]) << 16;
    b =  (var->gun->pixels[((y * var->gun->width + x) + 2)]) << 8;
    o = (var->gun->pixels[((y * var->gun->width + x) + 3)]);
    color =   r |
            g |
            b |
            o;
    if (color == 0x6070DFFF)
        return 0x00000000;
    return color;
}

void draw_gun(t_var *var)
{
    int xstart;
    int xend;
    int ystart;
    int yend;
    uint32_t color;

    int x_img = 0;
    int y_img = 0;
    int xtrucker = 0;
    int ytrucker = 0;

    xstart = (WIDTH / 2) - (var->gun->width / 2);
    xend = (WIDTH / 2) + (var->gun->width / 2);
    ystart = (HEIGHT - (HEIGHT / 4)) - var->gun->height;
    yend = (HEIGHT - HEIGHT / 4) + var->gun->height;

    // printf("xstart = %d\tystart = %d\t\txend = %d\tyend = %d\t\tx = %d\ty = %d\t\twidth = %u\theight = %u\n",
    //         xstart, ystart, xend, yend, xend-xstart, yend-ystart, var->gun->width, var->gun->height);

    while (ystart < yend)
    {
        if (++ytrucker > var->gun->height)
            break;
        xstart = (WIDTH / 2) - (var->gun->width / 2);
        while (xstart < xend)
        {
            color = get_gun_color_at_current_pixel(var, x_img, y_img);
            // printf("%X\n", color);
            // break;
            mlx_put_pixel(var->img_3d, xstart, ystart, color);
            xstart++;
            x_img+=4;
        }
        ystart++;
        y_img+=4;
    }
}