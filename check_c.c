/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:49:58 by hfiqar            #+#    #+#             */
/*   Updated: 2024/05/11 14:53:22 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*get_player_position(char **map)
{
	int	*t;
	int	i;
	int	j;

	j = 0;
	t = malloc(sizeof(int) * 2);
	if (!t)
		return (0);
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'P')
			{
				t[0] = j;
				t[1] = i;
			}
			i++;
		}
		j++;
	}
	return (t);
}

void	flood_fill(t_game vars, int y, int x)
{
	if (y < 0 || y >= vars.rows || x < 0 || x >= vars.cols)
		return ;
	if (vars.map[y][x] == '1' || vars.map[y][x] == 'F')
		return ;
	if (vars.map[y][x] == 'E')
	{
		vars.map[y][x] = '1';
		return ;
	}
	vars.map[y][x] = 'F';
	flood_fill(vars, y + 1, x);
	flood_fill(vars, y - 1, x);
	flood_fill(vars, y, x + 1);
	flood_fill(vars, y, x - 1);
}

void	check_for_c(t_game vars)
{
	int	j;
	int	i;

	j = 0;
	while (vars.map[j])
	{
		i = 0;
		while (vars.map[j][i])
		{
			if (vars.map[j][i] == 'c')
			{
				perror("Error");
				exit(0);
			}
			i++;
		}
		j++;
	}
}
