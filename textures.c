#include "cube.h"

int north_textures(t_var *var, int idx, int idy, t_cords *cor)
{
    double offset;
    double image_with;
    double actual_pixel;
    offset = fmod(cor->colision_h.x, SQUARE_SIZE);
    image_with = var->north->width;
    actual_pixel = ((offset * image_with) / SQUARE_SIZE) + (idy * image_with);
    
    

    return 0;
}

int south_textures(t_var *var, int idx, int idy, t_cords *cor)
{
    return 0;   
}

int east_textures(t_var *var, int idx, int idy, t_cords *cor)
{
    return 0;   
}

int west_textures(t_var *var, int idx, int idy, t_cords *cor)
{
    return 0;   
}
