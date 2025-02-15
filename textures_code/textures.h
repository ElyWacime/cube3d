#ifndef TEXTURES_H
#define TEXTURES_H

#include "../cube.h"

size_t door_textures_v(t_var *var, t_ray_wall *ra_wl, int ofsx);
size_t door_textures_h(t_var *var, t_ray_wall *ra_wl, int ofsx);
size_t east_textures(t_var *var, t_ray_wall *ra_wl, int ofsx);
size_t north_textures(t_var *var, t_ray_wall *ra_wl, int ofsx);
size_t west_textures(t_var *var, t_ray_wall *ra_wl, int ofsx);
size_t south_textures(t_var *var, t_ray_wall *ra_wl, int ofsx);
uint32_t get_gun_color_at_current_pixel(t_var *var, int x, int y);
void draw_gun(t_var *var);

#endif