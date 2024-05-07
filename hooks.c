/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:24:00 by hfiqar            #+#    #+#             */
/*   Updated: 2024/05/07 22:39:10 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void to_x_plus_1(t_game *vars)
{
    int player_x = 2;
    int player_y = 2;
    // we neeed to player's position
    if (vars->map_copy_1[player_y][player_x + 1] == '1')
        return;
    else if (vars->map_copy_1[player_y][player_x + 1] == '0'
    || vars->map_copy_1[player_y][player_x + 1] == 'c')
    {
        vars->img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr, "./character_0.xpm", &vars->x, &vars->y);
        mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img_ptr, SIZE_l * 3 , SIZE_w * 2);
        vars->img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr, "./floor_3.xpm", &vars->x, &vars->y);
        mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img_ptr, SIZE_l * 2 , SIZE_w * 2);
    }
    else if (vars->map_copy_1[player_y][player_x + 1] == 'E')
        exit(0);
}

void to_x_minus_1(t_game *vars)
{
    int player_x = 2;
    int player_y = 2;
    // we neeed to player's position
    if (vars->map_copy_1[player_y][player_x - 1] == '1')
        return;
    else if (vars->map_copy_1[player_y][player_x - 1] == '0'
    || vars->map_copy_1[player_y][player_x - 1] == 'c')
    {
        vars->img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr, "./character_0.xpm", &vars->x, &vars->y);
        mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img_ptr, SIZE_l  , SIZE_w * 2);
        vars->img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr, "./floor_3.xpm", &vars->x, &vars->y);
        mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img_ptr, SIZE_l * 2 , SIZE_w * 2);
    }
    else if (vars->map_copy_1[player_y][player_x -  1] == 'E')
        exit(0);
}

void to_y_plus_1(t_game *vars)
{
    int player_x = 2;
    int player_y = 2;
    // we neeed to player's position
    if (vars->map_copy_1[player_y + 1][player_x ] == '1')
        return;
    else if (vars->map_copy_1[player_y + 1][player_x] == '0'
    || vars->map_copy_1[player_y + 1][player_x] == 'c')
    {
        vars->img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr, "./character_0.xpm", &vars->x, &vars->y);
        mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img_ptr, SIZE_l * 2 , SIZE_w * 3);
        vars->img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr, "./floor_3.xpm", &vars->x, &vars->y);
        mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img_ptr, SIZE_l * 2 , SIZE_w * 2);
    }
    else if (vars->map_copy_1[player_y + 1][player_x] == 'E')
        exit(0);
}

void to_y_minus_1(t_game *vars)
{
    int player_x = 2;
    int player_y = 2;
    // we neeed to player's position
    if (vars->map_copy_1[player_y - 1][player_x ] == '1')
        return;
    else if (vars->map_copy_1[player_y - 1][player_x] == '0'
    || vars->map_copy_1[player_y - 1][player_x] == 'c')
    {
        vars->img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr, "./character_0.xpm", &vars->x, &vars->y);
        mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img_ptr, SIZE_l * 2 , SIZE_w );
        vars->img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr, "./floor_3.xpm", &vars->x, &vars->y);
        mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img_ptr, SIZE_l * 2 , SIZE_w * 2);
    }
    else if (vars->map_copy_1[player_y - 1][player_x] == 'E')
        exit(0);
}
