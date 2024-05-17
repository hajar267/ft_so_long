/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:52:03 by hfiqar            #+#    #+#             */
/*   Updated: 2024/05/17 20:18:09 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_start_game(t_game vars, char *name)
{
	char	*str;

	vars.fd = open(name, O_RDONLY);
	if (vars.fd == -1)
		ft_exit();
	str = get_next_line(vars.fd);
	if (str[0] != '1')
	{
		free(str);
		close(vars.fd);
		ft_exit();
	}
	free(str);
	close(vars.fd);
}

void	check_map_wall(t_game var, char *name)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(var.map[0]);
	var.n_l = get_numline_map(var, name) - 1;
	while (var.map[0][i] && var.map[var.n_l][i])
	{
		if (var.map[0][i] != '1' || var.map[var.n_l][i] != '1')
			ft_exit();
		i++;
	}
	i = 0;
	while (var.n_l > 0)
	{
		if (var.map[var.n_l][0] != '1' || var.map[var.n_l][len - 1] != '1')
			ft_exit();
		var.n_l--;
	}
}

void	check_map_shape(t_game var, char *name)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(var.map[0]);
	j = get_numline_map(var, name);
	if (j == i)
		ft_exit();
	while (j > 0)
	{
		if (i != ft_strlen(var.map[j - 1]))
			ft_exit();
		j--;
	}
}

void	check_line(t_game *var, int x)
{
	int	y;
	int	len;

	y = 1;
	len = var->cols - 1;
	while (len - 1 > 0)
	{
		if (var->map[x][y] == 'E')
			var->compt_e++;
		else if (var->map[x][y] == 'C')
			var->compt_c++;
		else if (var->map[x][y] == 'P')
			var->compt_p++;
		else if (var->map[x][y] != '0' && var->map[x][y] != '1')
			ft_exit();
		y++;
		len--;
	}
}

void	check_map_content(t_game *var)
{
	int	x;

	x = 1;
	while (var->rows - 1 > 0)
	{
		check_line(var, x);
		x++;
		var->rows--;
	}
	if (var->compt_e != 1 || var->compt_p != 1 || var->compt_c < 1)
		ft_exit();
}
