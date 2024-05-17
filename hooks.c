/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:24:00 by hfiqar            #+#    #+#             */
/*   Updated: 2024/05/17 21:13:41 by hfiqar           ###   ########.fr       */
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
		assist_x_plus(vars);
	}
	else if (vars->map_copy_1[vars->player_y][vars->player_x + 1] == 'E')
	{
		if (vars->c <= 0)
			exit(EXIT_FAILURE);
		else
			return ;
	}
}

void	to_x_minus_1(t_game *vars)
{
	if (vars->map_copy_1[vars->player_y][vars->player_x - 1] == '1')
		return ;
	else if (vars->map_copy_1[vars->player_y][vars->player_x - 1] == '0'
	|| vars->map_copy_1[vars->player_y][vars->player_x - 1] == 'C')
	{
		assist_x_minus(vars);
	}
	else if (vars->map_copy_1[vars->player_y][vars->player_x - 1] == 'E')
	{
		if (vars->c <= 0)
			exit(EXIT_FAILURE);
		else
			return ;
	}
}

void	to_y_plus_1(t_game *vars)
{
	if (vars->map_copy_1[vars->player_y + 1][vars->player_x] == '1')
		return ;
	else if (vars->map_copy_1[vars->player_y + 1][vars->player_x] == '0'
	|| vars->map_copy_1[vars->player_y + 1][vars->player_x] == 'C')
	{
		assist_y_plus(vars);
	}
	else if (vars->map_copy_1[vars->player_y + 1][vars->player_x] == 'E')
	{
		if (vars->c <= 0)
			exit(EXIT_FAILURE);
		else
			return ;
	}
}

void	to_y_minus_1(t_game *vars)
{
	if (vars->map_copy_1[vars->player_y - 1][vars->player_x] == '1')
		return ;
	else if (vars->map_copy_1[vars->player_y - 1][vars->player_x] == '0'
	|| vars->map_copy_1[vars->player_y - 1][vars->player_x] == 'C')
	{
		assist_y_minus(vars);
	}
	else if (vars->map_copy_1[vars->player_y - 1][vars->player_x] == 'E')
	{
		if (vars->c <= 0)
			exit(EXIT_FAILURE);
		else
			return ;
	}
}
