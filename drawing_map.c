/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:15:21 by hfiqar            #+#    #+#             */
/*   Updated: 2024/05/17 21:02:34 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	state_map_wall_1(t_game *var, int l, int w)
{
	if (var->map_copy_1[var->j][var->i] == '1')
	{
		var->img_ptr = mlx_xpm_file_to_image(var->mlx_ptr, \
		"./textures/wall.xpm", &var->x, &var->y);
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, \
		var->img_ptr, l, w);
	}
	else if (var->map_copy_1[var->j][var->i] == 'P')
	{
		var->img_ptr = mlx_xpm_file_to_image(var->mlx_ptr, \
		"./textures/character_0.xpm", &var->x, &var->y);
		var->img_ptr = mlx_xpm_file_to_image(var->mlx_ptr, \
		"./textures/character_0.xpm", &var->x, &var->y);
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, \
		var->img_ptr, l, w);
	}
	else if (var->map_copy_1[var->j][var->i] == 'E')
	{
		var->img_ptr = mlx_xpm_file_to_image(var->mlx_ptr, \
		"./textures/cave.xpm", &var->x, &var->y);
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, \
		var->img_ptr, l, w);
	}
}

void	state_map_wall(t_game *var, int l, int w)
{
	if (var->map_copy_1[var->j][var->i] == '0')
	{
		var->img_ptr = mlx_xpm_file_to_image(var->mlx_ptr, \
		"./textures/floor_3.xpm", &var->x, &var->y);
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, \
		var->img_ptr, l, w);
	}
	else if (var->map_copy_1[var->j][var->i] == 'C')
	{
		var->img_ptr = mlx_xpm_file_to_image(var->mlx_ptr, \
		"./textures/rabbit_1.xpm", &var->x, &var->y);
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, \
		var->img_ptr, l, w);
	}
	else if (var->map_copy_1[var->j][var->i] == '1' \
	|| var->map_copy_1[var->j][var->i] == 'P' \
	|| var->map_copy_1[var->j][var->i] == 'E')
		state_map_wall_1(var, l, w);
}

void	wall_map(t_game var)
{
	int	l;
	int	w;

	var.j = 0;
	w = 0;
	while (var.map_copy_1[var.j])
	{
		l = 0;
		var.i = 0;
		while (var.map_copy_1[var.j][var.i])
		{
			if (var.map_copy_1[var.j][var.i] == '1' \
			|| var.map_copy_1[var.j][var.i] == 'P' \
			|| var.map_copy_1[var.j][var.i] == '0' \
			|| var.map_copy_1[var.j][var.i] == 'E' || \
			var.map_copy_1[var.j][var.i] == 'C')
				state_map_wall(&var, l, w);
			l += SIZE_L;
			var.i++;
		}
		w += SIZE_W;
		var.j++;
	}
}

int	destroynotify(int keycode, t_game *var)
{
	(void)keycode;
	(void)var;
	exit(EXIT_FAILURE);
}
