/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:15:21 by hfiqar            #+#    #+#             */
/*   Updated: 2024/05/10 14:26:12 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void state_map_wall_1(t_game var, int i, int j, int l, int w)
{
    if (var.map_copy_1[j][i] == '1')
    {
        var.img_ptr = mlx_xpm_file_to_image(var.mlx_ptr, \
        "./textures/wall.xpm", &var.x, &var.y);
        mlx_put_image_to_window(var.mlx_ptr, var.win_ptr, \
        var.img_ptr, l, w);
    }
    else if (var.map_copy_1[j][i] == 'P')
    {
        var.img_ptr = mlx_xpm_file_to_image(var.mlx_ptr, \
        "./textures/character_0.xpm", &var.x, &var.y);
        //
        var.img_ptr = mlx_xpm_file_to_image(var.mlx_ptr, \
        "./textures/character_0.xpm", &var.x, &var.y);
        //
        mlx_put_image_to_window(var.mlx_ptr, var.win_ptr, \
        var.img_ptr, l, w);
    }
     else if (var.map_copy_1[j][i] == 'E')
    {
        var.img_ptr = mlx_xpm_file_to_image(var.mlx_ptr, \
        "./textures/cave.xpm", &var.x, &var.y);
        mlx_put_image_to_window(var.mlx_ptr, var.win_ptr, \
        var.img_ptr, l, w);
    }
}

void state_map_wall(t_game var, int i, int j, int l, int w)
{
    if (var.map_copy_1[j][i] == '0')
    {
        var.img_ptr = mlx_xpm_file_to_image(var.mlx_ptr, \
        "./textures/floor_3.xpm", &var.x, &var.y);
        mlx_put_image_to_window(var.mlx_ptr, var.win_ptr, \
        var.img_ptr, l, w);
    }
    else if (var.map_copy_1[j][i] == 'c')
    {
        var.img_ptr = mlx_xpm_file_to_image(var.mlx_ptr, \
        "./textures/rabbit_1.xpm", &var.x, &var.y);
        mlx_put_image_to_window(var.mlx_ptr, var.win_ptr, \
        var.img_ptr, l, w);
    }
    else if (var.map_copy_1[j][i] == '1' || var.map_copy_1[j][i] == 'P' \
            || var.map_copy_1[j][i] == 'E')
            state_map_wall_1(var, i, j, l, w);
}

void wall_map(t_game var)
{
    int i;
    int j;
    int l;
    int w;

    j = 0;
    w = 0;
    while(var.map_copy_1[j])
    {
        l = 0;
        i = 0;
        while(var.map_copy_1[j][i])
        {
            if (var.map_copy_1[j][i] == '1' || var.map_copy_1[j][i] == 'P' \
            || var.map_copy_1[j][i] == '0'|| var.map_copy_1[j][i] == 'E' || \
            var.map_copy_1[j][i] == 'c')
                state_map_wall(var, i, j, l, w);
            l += SIZE_l;
            i++;
        }
        w += SIZE_w;
        j++;
    }
}
    
int kill_redcross(int keycode, t_game * var)
{
    (void)keycode;
    exit(0);
}
