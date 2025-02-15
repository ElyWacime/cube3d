
// #include "cube.h"

// size_t door_textures_v(t_var *var, t_ray_wall *ra_wl, int ofsx)
// {
//     if (ra_wl->correct_a > 0)
//         ra_wl->ofssety =  (((var->door->height - (2 * ra_wl->image_offset)) * ra_wl->idy) / HEIGHT) + ra_wl->image_offset;
//     else
//         ra_wl->ofssety = (((ra_wl->idy - ra_wl->a) * var->door->height)) / (HEIGHT - (ra_wl->a << 1));
//     ra_wl->pix = ((ra_wl->ofssety * var->door->width) + ofsx) << 2;
//     if ((uint32_t)(ra_wl->pix) >= var->door->height * var->door->width * 4)
//         return 0xFFFFFFFF;
//     var->r = (var->door->pixels[ra_wl->pix + 0]) << 24;
//     var->g = (var->door->pixels[ra_wl->pix + 1]) << 16;
//     var->b =  (var->door->pixels[ra_wl->pix + 2]) << 8;
//     var->o = var->door->pixels[ra_wl->pix + 3];
//     return   var->r |
//             var->g |
//             var->b |
//             var->o;
// }

// size_t door_textures_h(t_var *var, t_ray_wall *ra_wl, int ofsx)
// {
//     if (ra_wl->correct_a > 0)
//         ra_wl->ofssety =  (((var->door->width - (2 * ra_wl->image_offset)) * ra_wl->idy) / HEIGHT) + ra_wl->image_offset;
//     else
//         ra_wl->ofssety = ((ra_wl->idy - ra_wl->a) * var->door->width) / (HEIGHT - (ra_wl->a << 1));
//     ra_wl->pix = ((ra_wl->ofssety * var->door->width) + ofsx) << 2;
//     if ((uint32_t)(ra_wl->pix) >=  var->door->height * var->door->width * 4)
//         return 0xFFFFFFFF;
//     var->r = (var->door->pixels[ra_wl->pix + 0]) << 24;
//     var->g = (var->door->pixels[ra_wl->pix + 1]) << 16;
//     var->b =  (var->door->pixels[ra_wl->pix + 2]) << 8;
//     var->o = var->door->pixels[ra_wl->pix + 3];
//         return   var->r |
//             var->g |
//             var->b |
//             var->o;
// }

// size_t east_textures(t_var *var, t_ray_wall *ra_wl, int ofsx)
// {
//     if (ra_wl->correct_a > 0)
//         ra_wl->ofssety =  (((var->east->height - (2 * ra_wl->image_offset)) * ra_wl->idy) / HEIGHT) + ra_wl->image_offset;
//     else
//         ra_wl->ofssety = (((ra_wl->idy - ra_wl->a) * var->east->height)) / (HEIGHT - (ra_wl->a << 1));
//     ra_wl->pix = ((ra_wl->ofssety * var->east->width) + ofsx) << 2;
//     if ((uint32_t)(ra_wl->pix) >= var->east->height * var->east->width * 4)
//         return 0xFFFFFF00;
//     var->r = (var->east->pixels[ra_wl->pix + 0]) << 24;
//     var->g = (var->east->pixels[ra_wl->pix + 1]) << 16;
//     var->b =  (var->east->pixels[ra_wl->pix + 2]) << 8;
//     var->o = var->east->pixels[ra_wl->pix + 3];
//     return   var->r |
//             var->g |
//             var->b |
//             var->o;
// }

// size_t north_textures(t_var *var, t_ray_wall *ra_wl, int ofsx)
// {
//     if (ra_wl->correct_a > 0)
//         ra_wl->ofssety =  (((var->north->width - (2 * ra_wl->image_offset)) * ra_wl->idy) / HEIGHT) + ra_wl->image_offset;
//     else
//         ra_wl->ofssety = ((ra_wl->idy - ra_wl->a) * var->north->width) / (HEIGHT - (ra_wl->a << 1));
//     ra_wl->pix = ((ra_wl->ofssety * var->north->width) + ofsx) << 2;
//     if ((uint32_t)(ra_wl->pix) >=  var->north->height * var->north->width * 4)
//         return 0xFFFFFF00;
//     var->r = (var->north->pixels[ra_wl->pix + 0]) << 24;
//     var->g = (var->north->pixels[ra_wl->pix + 1]) << 16;
//     var->b =  (var->north->pixels[ra_wl->pix + 2]) << 8;
//     var->o = var->north->pixels[ra_wl->pix + 3];
//         return   var->r |
//             var->g |
//             var->b |
//             var->o;
// }

// size_t west_textures(t_var *var, t_ray_wall *ra_wl, int ofsx)
// {
//     if (ra_wl->correct_a > 0)
//         ra_wl->ofssety =  (((var->west->height - (2 * ra_wl->image_offset)) * ra_wl->idy) / HEIGHT) + ra_wl->image_offset;
//     else
//         ra_wl->ofssety = (((ra_wl->idy - ra_wl->a) * var->west->height)) / (HEIGHT - (ra_wl->a << 1));
//     ra_wl->pix = ((ra_wl->ofssety * var->west->width) + ofsx) << 2;
//     if ((uint32_t)(ra_wl->pix) >=  var->west->height * var->west->width * 4)
//         return 0xFFFFFF00;
//     var->r = (var->west->pixels[ra_wl->pix + 0]) << 24;
//     var->g = (var->west->pixels[ra_wl->pix + 1]) << 16;
//     var->b =  (var->west->pixels[ra_wl->pix + 2]) << 8;
//     var->o = var->west->pixels[ra_wl->pix + 3];
//         return   var->r |
//             var->g |
//             var->b |
//             var->o;
// }

// size_t south_textures(t_var *var, t_ray_wall *ra_wl, int ofsx)
// {
//     if (ra_wl->correct_a > 0)
//         ra_wl->ofssety =  (((var->south->height - (2 * ra_wl->image_offset)) * ra_wl->idy) / HEIGHT) + ra_wl->image_offset;
//     else
//         ra_wl->ofssety = (((ra_wl->idy - ra_wl->a) * var->south->height)) / (HEIGHT - (ra_wl->a << 1));
//     ra_wl->pix = ((ra_wl->ofssety * var->south->width) + ofsx)  << 2;
//     if ((uint32_t)(ra_wl->pix) >=  var->south->height * var->south->width * 4)
//         return 0xFFFFFF00;
//     var->r = (var->south->pixels[ra_wl->pix + 0]) << 24;
//     var->g = (var->south->pixels[ra_wl->pix + 1]) << 16;
//     var->b =  (var->south->pixels[ra_wl->pix + 2]) << 8;
//     var->o = var->south->pixels[ra_wl->pix + 3];
//         return   var->r |
//             var->g |
//             var->b |
//             var->o;
// }

// uint32_t get_gun_color_at_current_pixel(t_var *var, int x, int y)
// {
//     t_uint r;
//     t_uint g;
//     t_uint b;
//     t_uint o;
//     t_uint color;

//     if ((y * var->gunPreFire->width + x) >= var->gunPreFire->height * var->gunPreFire->width * 4)
//         return 0xFFFFFF00;
//     r = (var->gunPreFire->pixels[((y * var->gunPreFire->width + x) + 0)]) << 24;
//     g = (var->gunPreFire->pixels[((y * var->gunPreFire->width + x) + 1)]) << 16;
//     b =  (var->gunPreFire->pixels[((y * var->gunPreFire->width + x) + 2)]) << 8;
//     o = (var->gunPreFire->pixels[((y * var->gunPreFire->width + x) + 3)]);
//     color =   r |
//             g |
//             b |
//             o;
//     if (color == 0x6070DFFF)
//         return 0x00000000;
//     return color;
// }

// void draw_gun(t_var *var)
// {
//     int xstart;
//     int ystart;

//     xstart = (WIDTH / 2) - (var->gunPreFire->width);
//     ystart = HEIGHT - var->gunPreFire->height * 2;

//     var->gunFireImg =  mlx_texture_to_image(var->mlx, var->gunFire);
//     var->gunPreFireImg =  mlx_texture_to_image(var->mlx, var->gunPreFire);

//     var->gunPreFireImg->enabled = true;
//     var->gunFireImg->enabled = false;

//     mlx_resize_image(var->gunPreFireImg, var->gunPreFire->width*2, var->gunPreFire->height*2);
//     mlx_resize_image(var->gunFireImg, var->gunFire->width*2, var->gunFire->height*2);

//     mlx_image_to_window(var->mlx, var->gunPreFireImg, xstart, ystart);
//     mlx_image_to_window(var->mlx, var->gunFireImg, xstart, ystart);
// }
