/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:22:32 by hfiqar            #+#    #+#             */
/*   Updated: 2024/05/17 21:02:12 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freed(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	fill_map(t_game *adr_var)
{
	char	*str;
	t_game	vars;

	vars = *adr_var;
	while (vars.n_l > vars.inc)
	{
		str = get_next_line(vars.fd);
		if (!str)
		{
			free(str);
			break ;
		}
		vars.allocate_map[vars.inc] = malloc(ft_strlen(str) + 1);
		if (!vars.allocate_map)
			return (free(str), ft_exit(), (void) NULL);
		fill_line(vars, str, vars.inc);
		vars.inc++;
	}
}

void	ft_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_compt_c(t_game *var)
{
	int	i;
	int	j;

	j = 0;
	var->c = 0;
	while (var->map_copy_1[j])
	{
		i = 0;
		while (var->map_copy_1[j][i])
		{
			if (var->map_copy_1[j][i] == 'C')
				var->c++;
			i++;
		}
		j++;
	}
}
