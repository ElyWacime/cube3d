#include "cube.h"

int north_textures(t_var *var, int idx, int idy, t_cords *cor, int a)
{
    int x;
    int y;
    x = ((fmod(cor->colision_h.x, SQUARE_SIZE)) * var->north->width) / SQUARE_SIZE;
    y = (((idy - a) / (HEIGHT - 2*a)) * var->north->height);
    // y = (idy * var->north->height * var->north->width) / (HEIGHT - a);
    int pix = (x * y);
    int color = var->north->pixels[pix];
    int color1 = var->north->pixels[pix+1];
    int color2 = var->north->pixels[pix+2];
    int color3 = var->north->pixels[pix+3];
    uint32_t transformed_color = (color * 256 * 256 * 256) + (color1 * 256 * 256) + (color2 * 256) + color3;
    // printf("height: %zu\twidth: %zu\n", var->north->height, var->north->width);
    printf("pix =   %d: \t\t%d\t%d\t%d\t%d\t\t cor_colision_h_x = %f \t\t fmod(cor->colision_h.x, SQUARE_SIZE) : %f \t\t x = %d \t y = %d \t\t HEIGHT - 2*a = %d \t\t idy = %d a = %d\n",
            pix, color, color1, color2, color3, cor->colision_h.x, fmod(cor->colision_h.x, SQUARE_SIZE), x, y, HEIGHT - 2*a, idy, a);
    mlx_put_pixel(var->img_3d, idx, idy, transformed_color);
    // double offset;
    // double image_with;
    // double actual_pixel;
    // int pix;
    // offset = fmod(cor->colision_h.y, SQUARE_SIZE);
    // if (offset >= 0 && offset <= (int)var->north->width 
    //     && idy >= 0 && idy <= (int)var->north->height)
    // {
    //     pix = (idy * var->north->bytes_per_pixel) * var->north->width
    //         + (offset * var->north->bytes_per_pixel);
    //     int color = var->north->pixels[pix++];
    //     int color1 = var->north->pixels[pix++];
    //     int color2 = var->north->pixels[pix++];
    //     int color3 = var->north->pixels[pix];
    //     int transformed_color = color << 24 | color1 << 16 | color2 << 8 | color3;
    //     mlx_put_pixel(var->img_3d, idx, idy, transformed_color);
    // }

    // image_with = var->north->width;
    // actual_pixel = (((offset * image_with) / SQUARE_SIZE) + (idy * image_with));
    // size_t color = var->north->pixels[(int)actual_pixel];
    // size_t color1 = var->north->pixels[(int)actual_pixel+1];
    // size_t color2 = var->north->pixels[(int)actual_pixel+2];
    // size_t color3 = var->north->pixels[(int)actual_pixel+3];
    // int transformed_color = color << 24 | color1 << 16 | color2 << 8 | color3;
    // mlx_put_pixel(var->img_3d, idx, idy, transformed_color);

    return 0;
}

// int south_textures(t_var *var, int idx, int idy, t_cords *cor)
// {
//     return 0;   
// }

// int east_textures(t_var *var, int idx, int idy, t_cords *cor)
// {
//     return 0;   
// }

// int west_textures(t_var *var, int idx, int idy, t_cords *cor)
// {
//     return 0;   
// }
