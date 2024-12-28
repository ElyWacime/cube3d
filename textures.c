#include "cube.h"

size_t north_textures(t_var *var, t_ray_wall *ra_wl, t_cords *cor)
{
    (void)cor;
    // ra_wl->ofssetx = (((fmod(cor->colision_h.x,CUBE_SIZE)) * var->north->width)) / CUBE_SIZE;
    if (ra_wl->correct_a > 0)
    {
        ra_wl->image_offset = (ra_wl->correct_a * var->north->height) / (ra_wl->wall_projection_height);
        ra_wl->ofssety =  (((var->north->height - (2 * ra_wl->image_offset)) * ra_wl->idy) / HEIGHT) + ra_wl->image_offset;
    }
    else
        ra_wl->ofssety = (((ra_wl->idy - ra_wl->a) * var->north->height)) / (HEIGHT - (2*ra_wl->a));
    ra_wl->pix = ((ra_wl->ofssety * var->north->width) + ra_wl->ofssetx) * 4;
    return   var->north->pixels[ra_wl->pix + 3]
        + (256* var->north->pixels[ra_wl->pix + 2])
        + (256*256* var->north->pixels[ra_wl->pix + 1])
        +  (256*256*256* var->north->pixels[ra_wl->pix + 0]);
}

size_t south_textures(t_var *var, t_ray_wall *ra_wl, t_cords *cor)
{
    (void)cor;
    // ra_wl->ofssetx = (((fmod(cor->colision_h.x,CUBE_SIZE)) * var->south->width)) / CUBE_SIZE;
    if (ra_wl->correct_a > 0)
    {
        ra_wl->image_offset = (ra_wl->correct_a * var->south->height) / (ra_wl->wall_projection_height);
        ra_wl->ofssety =  (((var->south->height - (2 * ra_wl->image_offset)) * ra_wl->idy) / HEIGHT) + ra_wl->image_offset;
    }
    else
        ra_wl->ofssety = (((ra_wl->idy - ra_wl->a) * var->south->height)) / (HEIGHT - (2*ra_wl->a));
    ra_wl->pix = ((ra_wl->ofssety * var->south->width) + ra_wl->ofssetx) * 4;
    return  var->south->pixels[ra_wl->pix + 3]
        + (256* var->south->pixels[ra_wl->pix + 2])
        + (256*256* var->south->pixels[ra_wl->pix + 1])
        +  (256*256*256* var->south->pixels[ra_wl->pix + 0]);
}

size_t east_textures(t_var *var, t_ray_wall *ra_wl, t_cords *cor)
{
    (void)cor;
    // ra_wl->ofssetx = (((fmod(cor->colision_v.y,CUBE_SIZE)) * var->east->height)) / CUBE_SIZE;
    if (ra_wl->correct_a > 0)
    {
        ra_wl->image_offset = (ra_wl->correct_a * var->east->width) / (ra_wl->wall_projection_height);
        ra_wl->ofssety =  (((var->east->width - (2 * ra_wl->image_offset)) * ra_wl->idy) / HEIGHT) + ra_wl->image_offset;
    }
    else
        ra_wl->ofssety = (((ra_wl->idy - ra_wl->a) * var->east->width)) / (HEIGHT - (2*ra_wl->a));
    ra_wl->pix = ((ra_wl->ofssety * var->east->height) + ra_wl->ofssetx) * 4;
    return   var->east->pixels[ra_wl->pix + 3]
    + (256* var->east->pixels[ra_wl->pix + 2])
    + (256*256* var->east->pixels[ra_wl->pix + 1])
    +  (256*256*256* var->east->pixels[ra_wl->pix + 0]);
}

size_t west_textures(t_var *var, t_ray_wall *ra_wl, t_cords *cor)
{
    (void)cor;
    // ra_wl->ofssetx = (((fmod(cor->colision_v.y,CUBE_SIZE)) * var->west->width)) / CUBE_SIZE;
    if (ra_wl->correct_a > 0)
    {
        ra_wl->image_offset = (ra_wl->correct_a * var->west->height) / (ra_wl->wall_projection_height);
        ra_wl->ofssety =  (((var->west->height - (2 * ra_wl->image_offset)) * ra_wl->idy) / HEIGHT) + ra_wl->image_offset;
    }
    else
        ra_wl->ofssety = (((ra_wl->idy - ra_wl->a) * var->west->height)) / (HEIGHT - (2*ra_wl->a));
    ra_wl->pix = ((ra_wl->ofssety * var->west->width) + ra_wl->ofssetx) * 4;
    return  var->west->pixels[ra_wl->pix + 3] + (256* var->west->pixels[ra_wl->pix + 2]) + (256*256* var->west->pixels[ra_wl->pix + 1]) +  (256*256*256* var->west->pixels[ra_wl->pix + 0]);
}
