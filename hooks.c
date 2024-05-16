/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:24:00 by hfiqar            #+#    #+#             */
/*   Updated: 2024/05/16 16:12:48 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	to_x_plus_1(t_game *vars)
{
	if (vars->map_copy_1[vars->player_y][vars->player_x + 1] == '1')
		return ;
	else if (vars->map_copy_1[vars->player_y][vars->player_x + 1] == '0'
	|| vars->map_copy_1[vars->player_y][vars->player_x + 1] == 'C')
	{
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
	else if (vars->map_copy_1[vars->player_y][vars->player_x + 1] == 'E')
		exit(0);
}

void	to_x_minus_1(t_game *vars)
{
	if (vars->map_copy_1[vars->player_y][vars->player_x - 1] == '1')
		return ;
	else if (vars->map_copy_1[vars->player_y][vars->player_x - 1] == '0'
	|| vars->map_copy_1[vars->player_y][vars->player_x - 1] == 'C')
	{
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
	else if (vars->map_copy_1[vars->player_y][vars->player_x - 1] == 'E')
		exit(0);
}

void	to_y_plus_1(t_game *vars)
{
	if (vars->map_copy_1[vars->player_y + 1][vars->player_x] == '1')
		return ;
	else if (vars->map_copy_1[vars->player_y + 1][vars->player_x] == '0'
	|| vars->map_copy_1[vars->player_y + 1][vars->player_x] == 'C')
	{
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
	else if (vars->map_copy_1[vars->player_y + 1][vars->player_x] == 'E')
		exit(0);
}

void	to_y_minus_1(t_game *vars)
{
	if (vars->map_copy_1[vars->player_y - 1][vars->player_x] == '1')
		return ;
	else if (vars->map_copy_1[vars->player_y - 1][vars->player_x] == '0'
	|| vars->map_copy_1[vars->player_y - 1][vars->player_x] == 'C')
	{
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
	else if (vars->map_copy_1[vars->player_y - 1][vars->player_x] == 'E')
		exit(0);
}
