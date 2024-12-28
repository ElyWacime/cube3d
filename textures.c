#include "cube.h"

size_t north_textures(t_var *var, t_ray_wall *ra_wl, t_cords *cor)
{
    int r;
    int g;
    int b;
    int o;
    int delta_y;
    ra_wl->ofssetx = (((my_fmod(cor->colision_h.x,CUBE_SIZE)) * var->north->width)) / CUBE_SIZE;
    ra_wl->image_offset = (ra_wl->correct_a  / (ra_wl->wall_projection_height))  * var->north->height ;
    if (ra_wl->correct_a > 0)
    {
        ra_wl->ofssety =  (((var->north->height - (2 * ra_wl->image_offset)) * ra_wl->idy) / HEIGHT) + ra_wl->image_offset;
        printf("---------ofssety0 = %d\n",ra_wl->ofssety);
        delta_y = (((var->north->height - (2 * ra_wl->image_offset)) * (ra_wl->idy + 1)) / HEIGHT) + ra_wl->image_offset;
        printf("ofssety1 = %d\n",(int)delta_y);
        delta_y = (((var->north->height - (2 * ra_wl->image_offset)) * (ra_wl->idy + 2)) / HEIGHT) + ra_wl->image_offset;
        printf("ofssety2 = %d\n",(int)delta_y);
        delta_y = (((var->north->height - (2 * ra_wl->image_offset)) * (ra_wl->idy + 3)) / HEIGHT) + ra_wl->image_offset;
        printf("ofssety3 = %d\n",(int)delta_y);
    }
    else
    {
        ra_wl->ofssety = ((ra_wl->idy - ra_wl->a) * var->north->height) / (HEIGHT - (2*ra_wl->a));
        printf("****ofssety0 = %d\n",ra_wl->ofssety);
        delta_y = (((ra_wl->idy + 1)- ra_wl->a) * var->north->height) / (HEIGHT - (2*ra_wl->a));
        printf("ofssety1 = %d\n",(int)delta_y);
        delta_y = (((ra_wl->idy + 2) - ra_wl->a) * var->north->height) / (HEIGHT - (2*ra_wl->a));
        printf("ofssety2 = %d\n",(int)delta_y);
        delta_y = (((ra_wl->idy + 3) - ra_wl->a) * var->north->height) / (HEIGHT - (2*ra_wl->a));
        printf("ofssety3 = %d\n",(int)delta_y);
    }

    if (ra_wl->ofssety > 0)
        delta_y = (var->north->height - (2 * ra_wl->image_offset)) / HEIGHT;
    else
        delta_y = (var->north->height) / (HEIGHT - 2*ra_wl->a);
    

    while (ra_wl->idy < HEIGHT - ra_wl->a)
    {
        ra_wl->pix = ((ra_wl->ofssety * var->north->width) + ra_wl->ofssetx) * 4;
        r = var->north->pixels[ra_wl->pix + 0];
        g = var->north->pixels[ra_wl->pix + 1];
        b = var->north->pixels[ra_wl->pix + 2];
        o = var->north->pixels[ra_wl->pix + 3];
        ra_wl->ofssety += (delta_y % 4 == 0);
        delta_y++;
        if (0 <= ra_wl->idx && ra_wl->idx  < WIDTH &&  0 <= ra_wl->idy && ra_wl->idy < HEIGHT)
            mlx_put_pixel(var->img_3d, ra_wl->idx,ra_wl->idy , r << 24 | g << 16 | b << 8 | o);
            // mlx_put_pixel(var->img_3d, ra_wl->idx, ra_wl->idy,var->north->pixels[ra_wl->pix + 3] + 256 * ((var->north->pixels[ra_wl->pix + 2]) + (256 * (var->north->pixels[ra_wl->pix + 1] +  (256 * var->north->pixels[ra_wl->pix + 0])))));
        else 
            break;
        (ra_wl->idy)++;
    }
    return   var->north->pixels[ra_wl->pix + 3] + 256 * ((var->north->pixels[ra_wl->pix + 2]) + (256 * (var->north->pixels[ra_wl->pix + 1] +  (256 * var->north->pixels[ra_wl->pix + 0]))));
}

size_t south_textures(t_var *var, t_ray_wall *ra_wl, t_cords *cor)
{
    return 0x0AAA0AFF;
    ra_wl->ofssetx = (((my_fmod(cor->colision_h.x,CUBE_SIZE)) * var->south->width)) / CUBE_SIZE;
    if (ra_wl->correct_a > 0)
    {
        ra_wl->image_offset = (ra_wl->correct_a * var->south->height) / (ra_wl->wall_projection_height);
        ra_wl->ofssety =  (((var->south->height - (2 * ra_wl->image_offset)) * ra_wl->idy) / HEIGHT) + ra_wl->image_offset;
    }
    else
        ra_wl->ofssety = ((double)((ra_wl->idy - ra_wl->a) * var->south->height)) / (HEIGHT - (2*ra_wl->a));
    ra_wl->pix = ((ra_wl->ofssety * var->south->width) + ra_wl->ofssetx) * 4;
    return  var->south->pixels[ra_wl->pix + 3] + (256* var->south->pixels[ra_wl->pix + 2]) + (256*256* var->south->pixels[ra_wl->pix + 1]) +  (256*256*256* var->south->pixels[ra_wl->pix + 0]);
}

size_t east_textures(t_var *var, t_ray_wall *ra_wl, t_cords *cor)
{
    return 0x0AAA0AFF;
    ra_wl->ofssetx = (((my_fmod(cor->colision_v.y,CUBE_SIZE)) * var->east->height)) / CUBE_SIZE;
    if (ra_wl->correct_a > 0)
    {
        ra_wl->image_offset = (ra_wl->correct_a * var->east->width) / (ra_wl->wall_projection_height);
        ra_wl->ofssety =  (((var->east->width - (2 * ra_wl->image_offset)) * ra_wl->idy) / HEIGHT) + ra_wl->image_offset;
    }
    else
        ra_wl->ofssety = ((double)((ra_wl->idy - ra_wl->a) * var->east->width)) / (HEIGHT - (2*ra_wl->a));
    ra_wl->pix = ((ra_wl->ofssety * var->east->height) + ra_wl->ofssetx) * 4;
    return   var->east->pixels[ra_wl->pix + 3] + (256* var->east->pixels[ra_wl->pix + 2]) + (256*256* var->east->pixels[ra_wl->pix + 1]) +  (256*256*256* var->east->pixels[ra_wl->pix + 0]);
}

size_t west_textures(t_var *var, t_ray_wall *ra_wl, t_cords *cor)
{
    return 0x0AAA0AFF;

    ra_wl->ofssetx = (((my_fmod(cor->colision_v.y,CUBE_SIZE)) * var->west->width)) / CUBE_SIZE;
    if (ra_wl->correct_a > 0)
    {
        ra_wl->image_offset = (ra_wl->correct_a * var->west->height) / (ra_wl->wall_projection_height);
        ra_wl->ofssety =  (((var->west->height - (2 * ra_wl->image_offset)) * ra_wl->idy) / HEIGHT) + ra_wl->image_offset;
    }
    else
        ra_wl->ofssety = ((double)((ra_wl->idy - ra_wl->a) * var->west->height)) / (HEIGHT - (2*ra_wl->a));
    ra_wl->pix = ((ra_wl->ofssety * var->west->width) + ra_wl->ofssetx) * 4;
    return  var->west->pixels[ra_wl->pix + 3] + (256* var->west->pixels[ra_wl->pix + 2]) + (256*256* var->west->pixels[ra_wl->pix + 1]) +  (256*256*256* var->west->pixels[ra_wl->pix + 0]);
}
