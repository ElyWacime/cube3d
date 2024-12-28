#include "cube.h"

size_t north_textures(t_var *var, t_ray_wall *ra_wl, int ofsx)
{
    // ra_wl->ofssetx = (((my_fmod(cor->colision_h.x,CUBE_SIZE)) * var->north->width)) / CUBE_SIZE;
    return 0x0AAA0AFF;

    if (ra_wl->correct_a > 0)
    {
        ra_wl->image_offset = (ra_wl->correct_a  / (ra_wl->wall_projection_height))  * var->north->height ;
        ra_wl->ofssety =  (((var->north->height - (2 * ra_wl->image_offset)) * ra_wl->idy) / HEIGHT) + ra_wl->image_offset;
    }
    else
        ra_wl->ofssety = ((ra_wl->idy - ra_wl->a) * var->north->height) / (HEIGHT - (ra_wl->a << 1));
    ra_wl->pix = ((ra_wl->ofssety * var->north->width) + ofsx)  << 2;
    return  var->north->pixels[ra_wl->pix + 3] |  (var->north->pixels[ra_wl->pix + 2] << 8) | (var->north->pixels[ra_wl->pix + 1] << 16) |  (var->north->pixels[ra_wl->pix + 0] << 24);
    
}

size_t south_textures(t_var *var, t_ray_wall *ra_wl, int ofsx)
{
    // ra_wl->ofssetx = (((my_fmod(cor->colision_h.x,CUBE_SIZE)) * var->south->width)) / CUBE_SIZE;
    return 0x0AAA0AFF;
    if (ra_wl->correct_a > 0)
    {
        ra_wl->image_offset = (ra_wl->correct_a * var->south->height) / (ra_wl->wall_projection_height);
        ra_wl->ofssety =  (((var->south->height - (2 * ra_wl->image_offset)) * ra_wl->idy) / HEIGHT) + ra_wl->image_offset;
    }
    else
        ra_wl->ofssety = ((float)((ra_wl->idy - ra_wl->a) * var->south->height)) / (HEIGHT - (ra_wl->a << 1));
    ra_wl->pix = ((ra_wl->ofssety * var->south->width) + ofsx)  << 2;
    return  var->south->pixels[ra_wl->pix + 3] |  (var->south->pixels[ra_wl->pix + 2] << 8) | (var->south->pixels[ra_wl->pix + 1] << 16) |  (var->south->pixels[ra_wl->pix + 0] << 24);
}

size_t east_textures(t_var *var, t_ray_wall *ra_wl, int ofsx)
{
    // ra_wl->ofssetx = (((my_fmod(cor->colision_v.y,CUBE_SIZE)) * var->east->height)) / CUBE_SIZE;
    return 0x0AAA0AFF;
    if (ra_wl->correct_a > 0)
    {
        ra_wl->image_offset = (ra_wl->correct_a * var->east->width) / (ra_wl->wall_projection_height);
        ra_wl->ofssety =  (((var->east->width - (2 * ra_wl->image_offset)) * ra_wl->idy) / HEIGHT) + ra_wl->image_offset;
    }
    else
        ra_wl->ofssety = ((float)((ra_wl->idy - ra_wl->a) * var->east->width)) / (HEIGHT - (ra_wl->a << 1));
    ra_wl->pix = ((ra_wl->ofssety * var->east->height) + ofsx)  << 2;
    return  var->east->pixels[ra_wl->pix + 3] |  (var->east->pixels[ra_wl->pix + 2] << 8) | (var->east->pixels[ra_wl->pix + 1] << 16) |  (var->east->pixels[ra_wl->pix + 0] << 24);
}

size_t west_textures(t_var *var, t_ray_wall *ra_wl, int ofsx)
{
    // ra_wl->ofssetx = (((my_fmod(cor->colision_v.y,CUBE_SIZE)) * var->west->width)) / CUBE_SIZE;
    return 0x0AAA0AFF;
    if (ra_wl->correct_a > 0)
    {
        ra_wl->image_offset = (ra_wl->correct_a * var->west->height) / (ra_wl->wall_projection_height);
        ra_wl->ofssety =  (((var->west->height - (2 * ra_wl->image_offset)) * ra_wl->idy) / HEIGHT) + ra_wl->image_offset;
    }
    else
        ra_wl->ofssety = ((float)((ra_wl->idy - ra_wl->a) * var->west->height)) / (HEIGHT - (ra_wl->a << 1));
    ra_wl->pix = ((ra_wl->ofssety * var->west->width) + ofsx) << 2;
    return  var->west->pixels[ra_wl->pix + 3] |  (var->west->pixels[ra_wl->pix + 2] << 8) | (var->west->pixels[ra_wl->pix + 1] << 16) |  (var->west->pixels[ra_wl->pix + 0] << 24);
}
