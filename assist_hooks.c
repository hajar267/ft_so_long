/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assist_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:06:03 by hfiqar            #+#    #+#             */
/*   Updated: 2024/05/17 21:26:57 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	assist_x_plus(t_game *vars)
{
	if (vars->map_copy_1[vars->player_y][vars->player_x + 1] == 'C')
	{
		vars->map_copy_1[vars->player_y][vars->player_x + 1] = '0';
		vars->c--;
	}
	vars->img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr, \
	"./textures/character_0.xpm", &vars->x, &vars->y);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img_ptr, \
	SIZE_L * (vars->player_x + 1), (SIZE_W * vars->player_y));
	mlx_destroy_image(vars->mlx_ptr, vars->img_ptr);
	vars->img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr, \
	"./textures/floor_3.xpm", &vars->x, &vars->y);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, \
	vars->img_ptr, SIZE_L * vars->player_x, SIZE_W * vars->player_y);
	mlx_destroy_image(vars->mlx_ptr, vars->img_ptr);
	vars->player_x++;
	vars->player_moves++;
	ft_putstr_fd("move : ", 1);
	ft_putnbr_fd(vars->player_moves, 1);
	ft_putstr_fd("\r", 1);
}

void	assist_x_minus(t_game *vars)
{
	if (vars->map_copy_1[vars->player_y][vars->player_x - 1] == 'C')
	{
		vars->map_copy_1[vars->player_y][vars->player_x - 1] = '0';
		vars->c--;
	}
	vars->img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr, \
	"./textures/character_0.xpm", &vars->x, &vars->y);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, \
	vars->img_ptr, SIZE_L * (vars->player_x - 1), SIZE_W * vars->player_y);
	mlx_destroy_image(vars->mlx_ptr, vars->img_ptr);
	vars->img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr, \
	"./textures/floor_3.xpm", &vars->x, &vars->y);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, \
	vars->img_ptr, SIZE_L * vars->player_x, SIZE_W * vars->player_y);
	mlx_destroy_image(vars->mlx_ptr, vars->img_ptr);
	vars->player_x--;
	vars->player_moves++;
	ft_putstr_fd("move : ", 1);
	ft_putnbr_fd(vars->player_moves, 1);
	ft_putstr_fd("\r", 1);
}

void	assist_y_plus(t_game *vars)
{
	if (vars->map_copy_1[vars->player_y + 1][vars->player_x] == 'C')
	{
		vars->map_copy_1[vars->player_y + 1][vars->player_x] = '0';
		vars->c--;
	}
	vars->img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr, \
	"./textures/character_0.xpm", &vars->x, &vars->y);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, \
	vars->img_ptr, SIZE_L * vars->player_x, SIZE_W * (vars->player_y + 1));
	mlx_destroy_image(vars->mlx_ptr, vars->img_ptr);
	vars->img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr, \
	"./textures/floor_3.xpm", &vars->x, &vars->y);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, \
	vars->img_ptr, SIZE_L * vars->player_x, SIZE_W * vars->player_y);
	mlx_destroy_image(vars->mlx_ptr, vars->img_ptr);
	vars->player_y++;
	vars->player_moves++;
	ft_putstr_fd("move : ", 1);
	ft_putnbr_fd(vars->player_moves, 1);
	ft_putstr_fd("\r", 1);
}

void	assist_y_minus(t_game *vars)
{
	if (vars->map_copy_1[vars->player_y - 1][vars->player_x] == 'C')
	{
		vars->map_copy_1[vars->player_y - 1][vars->player_x] = '0';
		vars->c--;
	}
	vars->img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr, \
	"./textures/character_0.xpm", &vars->x, &vars->y);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, \
	vars->img_ptr, SIZE_L * vars->player_x, SIZE_W * (vars->player_y - 1));
	mlx_destroy_image(vars->mlx_ptr, vars->img_ptr);
	vars->img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr, \
	"./textures/floor_3.xpm", &vars->x, &vars->y);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, \
	vars->img_ptr, SIZE_L * vars->player_x, SIZE_W * vars->player_y);
	mlx_destroy_image(vars->mlx_ptr, vars->img_ptr);
	vars->player_y--;
	vars->player_moves++;
	ft_putstr_fd("move : ", 1);
	ft_putnbr_fd(vars->player_moves, 1);
	ft_putstr_fd("\r", 1);
}
