/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:15:21 by hfiqar            #+#    #+#             */
/*   Updated: 2024/05/06 13:57:24 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void state_map_wall(t_game var, int i, int j, int l, int w)
{
    if (var.map_copy_1[j][i] == '1')
    {
        var.img_ptr = mlx_xpm_file_to_image(var.mlx_ptr, "./wall.xpm", &var.x, &var.y);
        mlx_put_image_to_window(var.mlx_ptr, var.win_ptr, var.img_ptr, l, w);
    }
    else if (var.map_copy_1[j][i] == 'P')
    {
        var.img_ptr = mlx_xpm_file_to_image(var.mlx_ptr, "./character_0.xpm", &var.x, &var.y);
        mlx_put_image_to_window(var.mlx_ptr, var.win_ptr, var.img_ptr, l, w);
    }
    else if (var.map_copy_1[j][i] == '0')
    {
        var.img_ptr = mlx_xpm_file_to_image(var.mlx_ptr, "./floor_3.xpm", &var.x, &var.y);
        mlx_put_image_to_window(var.mlx_ptr, var.win_ptr, var.img_ptr, l, w);
    }
    else if (var.map_copy_1[j][i] == 'E')
    {
        var.img_ptr = mlx_xpm_file_to_image(var.mlx_ptr, "./cave.xpm", &var.x, &var.y);
        mlx_put_image_to_window(var.mlx_ptr, var.win_ptr, var.img_ptr, l, w);
    }
}

void wall_map(t_game var)
{
    int i;
    int j=0;
    int l;
    int w = 0;
        while(var.map_copy_1[j])
        {
            l = 0;
            i = 0;
            while(var.map_copy_1[j][i])
            {
                if (var.map_copy_1[j][i] == '1' || var.map_copy_1[j][i] == 'P' || var.map_copy_1[j][i] == '0' || var.map_copy_1[j][i] == 'E')
                    state_map_wall(var, i, j, l, w);
                else if (var.map_copy_1[j][i] == 'c')
                {
                    var.img_ptr = mlx_xpm_file_to_image(var.mlx_ptr, "./rabbit_1.xpm", &var.x, &var.y);
                    mlx_put_image_to_window(var.mlx_ptr, var.win_ptr, var.img_ptr, l, w);
                }
                l += SIZE_l;
                i++;
            }
            w += SIZE_w;
            j++;
        }
    }
    