/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:15:21 by hfiqar            #+#    #+#             */
/*   Updated: 2024/05/03 18:18:41 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void wall_map(char **map, void *mlx_ptr, void *img_ptr, void *win_ptr, int cols, int rows)
{
    int x;
    int y;
    int i=0;
    int j=0;
    int l;
    int w = 0;
        while(map[j])
        {
            l = 0;
            i = 0;
            while(map[j][i])
            {
                if (map[j][i] == '1')
                {
                    img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./wall.xpm", &y, &x);
                    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, l, w);
                }
                else if (map[j][i] == 'P')
                {
                    img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./character_0.xpm", &y, &x);
                    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, l, w);
                }
                else if (map[j][i] == '0')
                {
                    img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./floor_3.xpm", &y, &x);
                    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, l, w);
                }
                else if (map[j][i] == 'E')
                {
                    img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./cave.xpm", &y, &x);
                    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, l, w);
                }
                else if (map[j][i] == 'c')
                {
                    img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./rabbit_1.xpm", &y, &x);
                    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, l, w);
                }
                l += SIZE_l;
                i++;
            }
            w += SIZE_w;
            j++;
        }
    }