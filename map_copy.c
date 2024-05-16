/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:38:52 by hfiqar            #+#    #+#             */
/*   Updated: 2024/05/16 15:35:16 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_game_copy(t_game var)
{
	char	**map_copy;
	int		i;
	int		j;

	j = 0;
	map_copy = malloc(sizeof(char *) * (var.rows + 1));
	if (!map_copy)
		return (NULL);
	while (var.map[j])
	{
		map_copy[j] = malloc(var.cols + 1);
		if (!map_copy)
			return (NULL);
		i = 0;
		while (var.map[j][i])
		{
			map_copy[j][i] = var.map[j][i];
			i++;
		}
		map_copy[j][i] = '\0';
		j++;
	}
	map_copy[j] = NULL;
	return (map_copy);
}

int	*get_exit_position(char **map_copy)
{
	int	*t_copy;
	int	i;
	int	j;

	j = 0;
	t_copy = malloc(sizeof(int) * 2);
	if (!t_copy)
		return (0);
	while (map_copy[j])
	{
		i = 0;
		while (map_copy[j][i])
		{
			if (map_copy[j][i] == 'E')
			{
				t_copy[0] = j;
				t_copy[1] = i;
			}
			i++;
		}
		j++;
	}
	return (t_copy);
}

void	flood_fill_copy(t_game vars, int y, int x)
{
	if (y < 0 || y >= vars.rows || x < 0 || x >= vars.cols)
		return ;
	if (vars.map_copy[y][x] == '1' || vars.map_copy[y][x] == 'F')
		return ;
	vars.map_copy[y][x] = 'F';
	flood_fill_copy(vars, y - 1, x);
	flood_fill_copy(vars, y + 1, x);
	flood_fill_copy(vars, y, x + 1);
	flood_fill_copy(vars, y, x - 1);
}

void	check_for_e_copy(t_game vars)
{
	int	j;
	int	i;

	j = 0;
	while (vars.map_copy[j])
	{
		i = 0;
		while (vars.map_copy[j][i])
		{
			if (vars.map_copy[j][i] == 'c' || vars.map_copy[j][i] == 'P')
			{
				write(1, "Error\n", 6);
				exit(0);
			}
			i++;
		}
		j++;
	}
}
